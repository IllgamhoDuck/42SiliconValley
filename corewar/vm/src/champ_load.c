#include "vm.h"

/*
** ----------------------------------------------------------------------------
** Function used to merge the 'tmp_champ' and 'champions' structure together
** in 't_cw'. For each champion, this function initialises a process later used
** to manipulate virtual memory. It stores the address in memory where the
** process has been loaded, and close all opened files for the champions.
**
** {t_cw *} cw - Main structure for corewar.
** ----------------------------------------------------------------------------
*/

void		champ_assign(t_cw *cw)
{
	int 		i;
	int			tmp_i;
	uint16_t	pc;

	i = -1;
	tmp_i = 0;
	while (++i < cw->n_players)
	{
		if (CHAMP(i).manual_assign == 0)
			CHAMP(i) = cw->tmp_champ[tmp_i++];
		pc = (MEM_SIZE / cw->n_players) * i;
		ft_memset(&cw->owner[(MEM_SIZE / cw->n_players) * i], i, CHAMP(i).prog_size);
		read(CHAMP(i).fd, &cw->memory[pc], CHAMP(i).prog_size);
		process_init(cw, &CHAMP(i), pc);
		close(CHAMP(i).fd);
	}
	cw->winner = &CHAMP(i - 1);
}

/*
** ----------------------------------------------------------------------------
** Function that stores all the informations in either the `tmp_champ` or the
** `champions` t_champ structure. Those t_champ structures will be later
** merged together as one, thus handling the potential '-n' flags.
**
** {t_cw *} cw - Main structure for corewar.
** {t_hdr *} hdr - Structure where all the informations on the file are stored.
** {int} fd - File descriptor of the currently loading champion file.
** {int} champ_num - Given program number for the potential champion 'filename'.
** ----------------------------------------------------------------------------
*/

static void			champ_init(t_cw *cw, t_hdr *hdr, int fd, int champ_num)
{
	t_champ		*new_champ;

	if (cw->champions[champ_num].manual_assign == 1)
		new_champ = &(cw->champions[champ_num]);
	else
		new_champ = &(cw->tmp_champ[champ_num]);
	new_champ->name = ft_strdup(hdr->prog_name);
	new_champ->comment = ft_strdup(hdr->comment);
	new_champ->prog_number = champ_num + 1;
	new_champ->prog_size = hdr->prog_size;
	new_champ->fd = fd;
}

/*
** ----------------------------------------------------------------------------
** Function that will read different parts of the file and store them into
** the 't_hdr' structure.
**
** {t_hdr *} hdr - Structure where all the informations on the file
**				   will be stored.
**
** {int} fd - File descriptor containing all the informations on the current
**			  champion being loaded.
** ----------------------------------------------------------------------------
*/

static void			champ_read_header(t_hdr *hdr, int fd)
{
	off_t	file_size;

	if (!(file_size = lseek(fd, 0, SEEK_END)))
		send_error("Couldn't get size of file.\n");
	if ((size_t)file_size < sizeof(t_hdr))
		send_error("Invalid header size.\n");
	if (lseek(fd, 0, SEEK_SET) == -1)
		send_error("Couldnt set offset to 0.\n");
	if (read(fd, hdr, sizeof(t_hdr)) != sizeof(t_hdr))
		send_error("Error while reading the file.\n");
	h_rev_bytes(&hdr->magic, sizeof(hdr->magic));
	if (hdr->magic != COREWAR_EXEC_MAGIC)
		send_error("Magic is not correct.\n");
	h_rev_bytes(&hdr->prog_size, sizeof(hdr->prog_size));
	if (hdr->prog_size > CHAMP_MAX_SIZE)
		send_error("Size of champion is too big.\n");
}

/*
** ----------------------------------------------------------------------------
** Function that analyses the filename for any potential syntax errors, 
** then tries to open it and store the result in the passed 'fd',
** to be used later. An error will be send if there's any error with the file.
**
** {char *} filename - Potential champion file name passed on command line.
** {int *} fd - Pointer to an empty file descriptor.
** ----------------------------------------------------------------------------
*/

static int			champ_check_file(char *filename, int *fd)
{
	int		len;
	char	*ext;

	len = (int)ft_strlen(filename);
	if (len < 4)
		send_error("Incorrect file name for champion.\n");
	ext = ft_strsub(filename, len - 4, 4);
	if (ft_strcmp(ext, ".cor"))
		send_error("Invalid extension.\n");
	if (!(*fd = open(filename, O_RDONLY)))
		send_error("File couldn't be opened.\n");
	free(ext);
	return (0);
}

/*
** ----------------------------------------------------------------------------
** Function that call subfunctions to read a champion's file and store all the
** useful informations that might be contained in it.
**
** {t_cw *} cw - Main structure for corewar.
** {char *} filename - Potential champion file name passed on command line.
** {int} champ_num - Given program number for the potential champion 'filename'.
** ----------------------------------------------------------------------------
*/

void				champ_load(t_cw *cw, char *filename, int champ_num)
{
	int			fd;
	t_hdr		hdr;

	hdr = cw->header;
	champ_check_file(filename, &fd);
	champ_read_header(&hdr, fd);
	champ_init(cw, &hdr, fd, champ_num);
}