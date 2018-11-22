/*
Implementation of Atbash cipher class

@author Justin Hadella (pitchnogle@gmail.com)
*/
#include "atbash_cipher.h"

#include <iostream>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Public Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void atbash_cipher::encode(std::ostream &os, int c)
{
  if (!isalpha(c)) return;

  os << (char)n2a(25 - a2n(c));
}

void atbash_cipher::decode(std::ostream &os, int c)
{
  // Decode is exactly same as encode
  encode(os, c);
}
