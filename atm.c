#include <stdio.h>
#include "atm.h"

unsigned get_money(ushort amount)
{
  denom denoms = DENOMS;
  ushort money = amount, index;
  unsigned notes = 0x0;

  OUT_OF_LIMIT(money)
  {
    return 0;
  }

  ITERATE(0, 8)
  { 
    notes = notes << 4;
    notes = notes | (money / denoms[index]);
    money %= denoms[index];
  }

  return notes;
}

void display_notes(unsigned notes)
{
  denom denoms = DENOMS;
  ushort index;
  unsigned note;

  ITERATE(0, 8)
  { 
    note = notes << index * 4;
    note = note >> 28;
    
    if(note)
    {
      printf("%-2u %-5s of Rs %-4hu\n", note, LABEL(note), denoms[index]);
    }
  }

}