/*
This is a simple class which encodes/decodes an input stream using Vigenère cipher

@author Justin Hadella (pitchnogle@gmail.com)
*/
#ifndef VIGENERE_CIPHER_H
#define VIGENERE_CIPHER_H

#include <ostream>
#include <string>

#include "cipher.h"

enum vigenere_mode
{
  alphabet,
  xor_ascii
};

class vigenere_cipher : public cipher
{
public:
  /*
  Function to set the Vigenère cipher key
  */
  void set_key(std::string key);

  /*
  Function to set the Vigenère cipher mode
  */
  void set_mode(vigenere_mode mode);

  /*
  Function to encode a character
  */
  void encode(std::ostream &os, int c);

  /*
  Function to decode a character
  */
  void decode(std::ostream &os, int c);

private:
  // The "key" in a Vigenère cipher shifts an amount based the current letter
  std::string m_key;

  // The index into key string
  size_t m_idx{0};

  // The mode determined the encoding/decoding method used
  int m_mode{alphabet};

  /*
  Function applies the Vigenère cipher using alphabet mode

  The input c is a value from 0-25 representing the letters A-Z

  Encoding:
  value = (c + k) % 26

  Decoding:
  value = (c - k) % 26
  */
  int shift_alpha(int c, cipher_action action);

  /*
  Function applies the Vigenère cipher shift using xor_ascii mode

  The input c is an ASCII value

  Encoding/Decoding:
  value = c ^ k
  */
  int shift_xor(int c);
};

#endif
