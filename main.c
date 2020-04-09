#include <stdio.h>
#include "atm.h"

int main(void)
{
  ushort amounts[] = {1, 10, 39, 589, 2590, 31999};
  ITERATE(0, 6)
  {
    unsigned notes = get_money(amounts[index]);
    printf("Amount: %hu\n", amounts[index]);
    display_notes(notes);
    NEW_LINE;
  }

  return 0;
}
