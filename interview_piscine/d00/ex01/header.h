#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

struct s_art {
	char *name;
	int price;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/

void  sortArts(struct s_art **arts);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

struct s_art **getArts(void);


/*--------------------------------
  &  your own other function
  --------------------------------*/

int					compare(struct s_art *a1, struct s_art *a2);
int					partition(struct s_art **arts, int low, int high);
void				quickSort(struct s_art **arts, int low, int high);
int					arrlen(struct s_art **arts);
void				swap(struct s_art **arts, int i, int j);

#endif
