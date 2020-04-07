#include "atm.h"
#include <math.h>

unsigned get_money(unsigned short amount)
{
  unsigned short denoms[8] = {2000, 500, 100, 50, 20, 10, 5, 1};
  unsigned short money = amount, pos, index;
  unsigned notes = 0;

  if(money > 31999)
  {
    return 0;
  }

  for(index = 0, pos = 7; index < 8; index++, pos--)
  { 
    notes = notes + (money / denoms[index]) * pow(16, pos);
    money %= denoms[index];
  }

  return notes;
}
