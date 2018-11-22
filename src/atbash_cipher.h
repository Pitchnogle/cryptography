/*
This is a simple class which encodes/decodes an input stream using Atbash cipher

@author Justin Hadella (pitchnogle@gmail.com)
*/
#ifndef ATBASH_CIPHER_H
#define ATBASH_CIPHER_H

#include <ostream>

#include "cipher.h"

class atbash_cipher : public cipher
{
public:
  /*
  Function to encode a character
  */
  void encode(std::ostream &os, int c);

  /*
  Function to decode a character
  */
  void decode(std::ostream &os, int c);
};

#endif
