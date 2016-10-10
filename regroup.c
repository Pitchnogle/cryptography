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

There is also an option to replace spaces with a letter to be able to preserve
the word length spacing.

This program would typically be used in conjunction with some form of cipher.

Written by: Justin Hadella (2016)
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

int main (int argc, char **argv)
{
  int c;
  
  // The extra "null" characters possibly added to end of stream to make the
  // output a multiple of group_len character groups
  const char *null_chars = "QXZJ";
  
  int group_len = 5;
  
  bool replace_spaces = false;
  int space_char = ' ';

  int group_cnt = 0;
  int alpha_cnt = 0;
  
  while ((c = getopt(argc, argv, "g:n:")) != -1) {
    switch (c) {
      case 'g':
        {
          int tmp = atoi(optarg);
          if (tmp >= 4 && tmp <= 5) {
            group_len = tmp;
          }
          else {
            fprintf(stderr, "Value must be 4 or 5!\n");
            return 1;
          }
        }
        break;
        
      case 'n':
        {
          char tmp;
          if (sscanf(optarg, "%c", &tmp) == 1) {
            if (isalpha(tmp)) {
            space_char = toupper(tmp);
            replace_spaces = true;
            }
          }
          else {
            fprintf(stderr, "Value must be alphabetic!\n");
            return 1;
          }
        }
        break;
        
      case '?':
        if (optopt == 'n')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
        
      default:
        abort();
    }
  }
  
  while ((c = getc(stdin)) != EOF) {
    // Replace space with user character (if required)
    if (replace_spaces && c == ' ') {
      c = space_char;
    }
    
    if (isalpha(c)) {
      alpha_cnt++;
      
      putchar(toupper(c));
      
      // Add a space between groups
      group_cnt++;
      if (group_cnt == group_len) {
        putchar(' ');
        
        group_cnt = 0;
      }
    }
  }

  // Add null characters (if needed) to make last group of characters the group
  // length
  c = 0;
  while ((alpha_cnt % group_len) > 0) {
    putchar(null_chars[c++]);
    alpha_cnt++;
  }
  putchar('\n');
    
  return 0;
}

