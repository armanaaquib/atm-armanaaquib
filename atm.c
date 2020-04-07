#include "atm.h"

unsigned get_money(unsigned short amount)
{
  unsigned short denoms[8] = {2000, 500, 100, 50, 20, 10, 5, 1};
  unsigned short money = amount, index;
  unsigned notes = 0x0;

  if(money > 31999)
  {
    return 0;
  }

  for(index = 0; index < 8; index++)
  { 
    notes = notes << 4;
    notes = notes | (money / denoms[index]);
    money %= denoms[index];
  }

  return notes;
}
