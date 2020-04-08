#include <stdio.h>
#include "atm.h"

unsigned get_money(unsigned short amount)
{
  denom denoms = DENOMS;
  unsigned short money = amount, index;
  unsigned notes = 0x0;

  if(money > LIMIT)
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

void display_notes(unsigned notes)
{
  denom denoms = DENOMS;
  unsigned short index;
  unsigned note;

  for(index = 0; index < 8; index++)
  { 
    note = notes << index * 4;
    note = note >> 28;
    
    if(note)
    {
      printf("%-2u %-5s of Rs %-4hu\n", note, LABEL(note), denoms[index]);
    }
  }

}