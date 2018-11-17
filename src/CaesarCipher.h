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
  void set_n(int n);

  /*
  Function gets the Caesar cipher shift value
  */
  int get_n();
  
  /*
  Function to encode a character
  */
  void encode(std::ostream &os, int c);

  /*
  Function to decode a character
  */
  void decode(std::ostream &os, int c);

private:
  int m_encode_shift{0};
  int m_decode_shift{0};

  /*
  Function applies the Ceasar cipher letter shift

  Encoding:
  value = (x + n) % 26

  Decoding:
  value = (x - n) % 26 
  */
  int letter_shift(int c, int n);
};

#endif
