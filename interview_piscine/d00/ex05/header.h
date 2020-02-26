#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

struct s_item {
  char          	*key;
  int				value;
  struct s_item 	*next;
};

struct s_dict {
  struct s_item **items;
  int           capacity; //the capacity of the array 'items'
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/

// DICTIONNARY

//return hash result
size_t hash(char *input);

//initialize the dictionnary, given as parameter the capacity of the array.
struct s_dict *dictInit(int capacity);

//add one item in the dictionnary, if FAIL return 0, otherwise 1
int	dictInsert(struct s_dict *dict, char *key, int value);

//find one element in the dictionnary, if not found, return -1
int	dictSearch(struct s_dict *dict, char *key);

// OTHER

char *compress(char *book, struct s_dict *dict);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

char *readBookFile(void);
void readWordsFile(char ***pWords, int *pLenWords);

/*--------------------------------
  &  your own other function
  --------------------------------*/

int howManyWord(char *bible, char *word);
char **processWords(struct s_dict *dict, char *book, int *header_len, int *compress_len);
void add_header(char *cbook, char **word_list, int list_len);

#endif
