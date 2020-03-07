#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_art {
	char *name;
	int price;
};

struct s_maxHeap {
	struct s_art **arr;
	int size;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
void heapSort(struct s_art **masterpiece, int n);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_art **getArts(void);

/*--------------------------------
  &  your own other function
  --------------------------------*/

void swap(struct s_art **art1, struct s_art **art2);
void maxHeapify(struct s_maxHeap *heap, int i);
struct s_maxHeap *createHeap(struct s_art **masterpiece, int size);

#endif
