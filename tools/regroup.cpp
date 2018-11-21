/*
This program is a simple text filter which takes an input stream and produces an
output where non-alphabetic characters are omitted and alphabetic characters are
output as uppercase in groups of 4 or 5 characters separated by spaces.

For example, the input:
The quick brown fox jumped over the lazy dog

would produce the output:
THEQU ICKBR OWNFO XJUMPE DOVER THELA ZYDOG

If there are not enough alphabetic characters remaining to make a fixed group,
then some extra null characters are added to end.

...

This program would typically be used in conjunction with some form of cipher.
Many books covering how ciphers work will include puzzles with this type of
letter grouping in the enciphered data.

...

@author Justin Hadella (pitchnogle@gmail.com)
*/
#include <iostream>
#include <cctype>
#include <cstdlib>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Local Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void usage()
{
  std::cout << "usage: % regroup [len]" << std::endl
            << "where:" << std::endl
            << "[len] is 4 for groups of four characters" << std::endl
            << "[len] is 5 for groups of five characters (default)" << std::endl;
}

// =============================================================================
// Main Program
// =============================================================================

int main(int argc, char **argv)
{
  // The extra "null" characters possibly added to end of stream to make the
  // output a multiple of group_len character groups
  const char *null_chars = "QXZJ";

  // Default group length if five characters
  int group_len = 5;

  int group_cnt = 0;
  int alpha_cnt = 0;

  if (argc == 2) {
    int arg = atoi(argv[1]);
    if (arg == 4 || arg == 5) {
      group_len = arg;
    }
    else {
      std::cout << "[len] should be 4 or 5" << std::endl;
      return 0;
    }
  }
  
  if (argc > 2) {
    usage();
    return 1;
  }
  
  char c;
  while (std::cin.get(c)) {
    if (isalpha(c)) {
      std::cout << static_cast<char>(toupper(c));
      alpha_cnt++;

      // Add a space between groups
      group_cnt++;
      if (group_cnt == group_len) {
        std::cout << " ";
        group_cnt = 0;
      }
    }
  }
	
  // Add null characters (if needed) to make last group of characters the group
  // length
  c = 0;
  while ((alpha_cnt % group_len) > 0) {
    std::cout << null_chars[c++];
    alpha_cnt++;
  }
  
  return 0;
}
