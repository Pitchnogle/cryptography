/*
This is a simple class which encodes/decodes an input stream using Caesar cipher

@author Justin Hadella (pitchnogle@gmail.com)
*/
#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include <ostream>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Definitions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class CaesarCipher
{
public:
  /*
  Function sets the Caesar cipher shift value (modulus 26)
  */
  void set_shift(int shift);

  /*
  Function gets the Caesar cipher shift value
  */
  int get_shift();
  
  /*
  Function to encode a character
  */
  void encode(std::ostream &os, int c);

  /*
  Function to decode a character
  */
  void decode(std::ostream &os, int c);

private:
  int m_key{0};

  /*
  Function applies the Ceasar cipher

  Encoding:
  value = (x + k) % 26

  Decoding:
  value = (x - k) % 26

  Decode uses opposite sign for the key!
  */
  int shift_cipher(int c, int k);
};

#endif
