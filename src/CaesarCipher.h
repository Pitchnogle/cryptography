/*
This is a simple class which encodes/decodes an input stream using Caesar cipher

@author Justin Hadella (pitchnogle@gmail.com)
*/
#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include <ostream>

#include "Cipher.h"

class CaesarCipher : public Cipher
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
  Function applies the Ceasar cipher shift

  The input c is a value from 0-25 representing the letters A-Z

  Encoding:
  value = (c + k) % 26

  Decoding:
  value = (c - k) % 26
  */
  int shift(int c, CipherAction action);
};

#endif
