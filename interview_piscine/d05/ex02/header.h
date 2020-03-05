/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_prices
{
	double *items;
	int length;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
double bestPriceV2(int pizzaSize, double *prices, double *cache);
double optimizedBestPrice(int pizzaSize, double *prices);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

// PARSING

struct s_prices *readList();

/*--------------------------------
  &  your own other function
  --------------------------------*/

