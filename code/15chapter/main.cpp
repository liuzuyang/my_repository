#include <iostream>
#include "quote.h"


int main()
{
  using namespace n_quo;
  {
    quote qu{"0001", 1};
    bulk_quote bu{"0002", 2, 2, 2};
    bulk_quote bu2{bu};
  }
  return 0;
}
