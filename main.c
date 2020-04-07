#include <stdio.h>
#include "atm.h"

void display_notes(unsigned);

void display_notes(unsigned notes)
{
  unsigned short denoms[8] = {2000, 500, 100, 50, 20, 10, 5, 1};
  unsigned short index;
  unsigned note;

  for(index = 0; index < 8; index++)
  { 
    note = notes << index * 4;
    note = note >> 28;
    printf("%2u notes of Rs %4hu\n", note, denoms[index]);
  }

}

int main(void)
{
  unsigned short int amounts[] = {1, 10, 39, 589, 2590, 31999};
  for (int i = 0; i < 6; i++)
  {
    unsigned int notes = get_money(amounts[i]);
    printf("Amount: %hu\n", amounts[i]);
    display_notes(notes);
    printf("\n");
  }

  return 0;
}
