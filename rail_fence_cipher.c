/*
The Rail Fence Cipher

This is a simple cipher which essentially scrambles the order of the input. This
implementation support a 2-line and 3-line fence. The best way to show how the
cipher works is by example. The code is kinda ugly...

Given the message:
MEET METO NIGH TQXZ

A 2-line rail fence would then look like:
M E M T N G T X
 E T E O I H Q Z
 
So the output would be:
MEMT NGTX ETEO IHQZ

A 3-line rail fence would then look like:
M   M   N   T
 E T E O I H Q Z
  E   T   G   X
  
So the output would be:
MMNT ETEO IQHZ ETGX

...

In this cipher, since the data is rearranged, it is first read into a buffer of
a fixed size. Really no way to use normal streaming here..

...

Written by: Justin Hadella (2016)
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define SIZE (1024 * 1024) /* Data is 1 MB length max! */

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

void usage();
void encode(int *data, int data_len, int rail_len);
void decode(int *data, int data_len, int rail_len);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Rail-Fence Cipher
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void usage()
{
  fprintf(stderr, "usage: $ railfence [options]\n\n");
  fprintf(stderr, "options:\n");
  fprintf(stderr, "-e 2 -- Encode text using railfence 2\n");
  fprintf(stderr, "-e 3 -- Encode text using railfence 3\n");
  fprintf(stderr, "-d 2 -- Decode text using railfence 2\n");
  fprintf(stderr, "-d 3 -- Decode text using railfence 3\n");
}

int rail[3][SIZE];
int rail_cnts[3];

void encode(int *data, int data_len, int rail_len)
{
  int rail_cnt = 0;
  int i, j, k;
  bool up = true;
  
  // Clear the globals
  memset(rail, 0, sizeof (rail));
  memset(rail_cnts, 0, sizeof (rail_cnts));
  
  // Encode the data
  for (i = 0; i < data_len; i++) {
    if (isalpha(data[i])) {
      j = rail_cnts[rail_cnt];
      
      rail[rail_cnt][j] = data[i];
      
      rail_cnts[rail_cnt]++;
      
      if (rail_len == 2) {
        rail_cnt++;
        rail_cnt %= rail_len;
      }
      else {
        switch (rail_cnt) {
          case 0: 
            rail_cnt = 1; 
            up = true; 
            break;
          case 1: 
            rail_cnt = up ? 2 : 0; 
            break;
          case 2:
            rail_cnt = 1;
            up = false;
            break;
        }
      }
    }
  }

  // Output the data
  for (i = 0, j = 0, k = 0; i < data_len; i++) {
    if (isalpha(data[i])) {
      fprintf(stdout, "%c", rail[j][k]);
      
      k++;
      if (k == rail_cnts[j]) {
        k = 0;
        
        j++;
        j %= rail_len;
      }
    }
    else {
      fprintf(stdout, "%c", data[i]);
    }
  }
}


void decode(int *data, int data_len, int rail_len)
{
  int rail_cnt = 0;
  int i, j, k;
  int alpha_num = 0;

  // Clear the global matrix
  memset(rail, 0, sizeof (rail));
  
  for (i = 0; i < data_len; i++) {
    if (isalpha(data[i])) {
      alpha_num++;
    }
  }
  
  for (i = 0, j = 0, k = 0; i < data_len; i++) {
    if (isalpha(data[i])) {
      rail[0][j] = data[i];
      
      if (rail_len == 2) {
        j += rail_len;
        if (j > alpha_num - 1) {
          k++;
          j = k;
        }
      }
      else {
        switch (k) {
          case 0:
            j += 4;
            if (j > alpha_num - 1) {
              k++;
              j = k;
            }
            break;
            
          case 1:
            j += 2;
            if (j > alpha_num - 1) {
              k++;
              j = k;
            }
            break;
            
          case 2:
            j += 4;
            break;
        }
      }
    }
  }
  
  for (i = 0, j = 0; i < data_len; i++) {
    if (isalpha(data[i])) {
      fprintf(stdout, "%c", rail[0][j++]);
    }
    else {
      fprintf(stdout, "%c", data[i]);
    }
  }
}


// =============================================================================
// Main program
// =============================================================================

int main (int argc, char **argv)
{
  int c;
  
  bool is_encode = true;
  int rail_len = 2;
  
  int raw_input[SIZE];
  int raw_length = 0;
  
  while ((c = getopt(argc, argv, "d:e:")) != -1) {
    switch (c) {
      case 'd':
        is_encode = false;
        /* deliberate fall-through */
        
      case 'e':
        {
          int tmp = atoi(optarg);
          if ((tmp == 2) || (tmp == 3)) {
            rail_len = tmp;
          }
          else {
            fprintf(stderr, "Value must be 2 or 3!\n");
            return 1;
          }
        }
        break;
      
      default:
        usage();
        exit(1);
    }
  }
  
  // Read in the data!
  while ((c = getc(stdin)) != EOF) {
    raw_input[raw_length++] = c;
  }

  // Do the cipher
  if (is_encode) {
    encode(raw_input, raw_length, rail_len);
  }
  else {
    decode(raw_input, raw_length, rail_len);
  }
}

