/**
@file detab.c
@brief 
This is program which replaces any occurrences of tab characters with a number
of spaces

@author Justin Hadella (pitchnogle@gmail.com)
*/
#include <iostream>

// =============================================================================
// Main Program
// =============================================================================

int main(int argc, char **argv)
{
  // Tabs are replaced by 2 spaces
  int tab_spaces = 2;

  // Or user can specify how many spaces to use
  if (argc == 2) {
    tab_spaces = atoi(argv[1]);
  }

  // Replace tabs in stream with spaces
  char c;
  while (std::cin.get(c)) {
    if (c == '\t') {
      for (int i = 0; i < tab_spaces; i++) std::cout << " ";
    }
    else 
      std::cout << c;
  }

  return 0;
}
