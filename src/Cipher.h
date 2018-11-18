/*
Abstract class definition for a generic cipher

@author Justin Hadella (pitchnogle@gmail.com)
*/
#ifndef CIPHER_H
#define CIPHER_H

#include <ostream>

enum CipherMode
{
  alphabet,  // Ciphers use pure alphabet A-Z (modulo 26)
  ascii_xor  // Ciphers use ASCII character space (XOR)
};

enum CipherAction
{
  encode,
  decode
};

class Cipher
{
public:
  // All ciphers must implement encode & decode functions
  virtual void encode(std::ostream &os, int c) = 0;
  virtual void decode(std::ostream &os, int c) = 0;

  // All ciphers must implement set mode function
  virtual void set_mode(CipherMode mode) = 0;

  // Converts ASCII into letter num (A = 0, B = 1, etc)
  static int a2n(int c) { return toupper(c) - 'A'; }

  // Converts letter num into ASCII (0 = A, 1 = B, etc)
  static int n2a(int c) { return toupper(c) + 'A'; }

protected:
  CipherMode m_mode{alphabet};
};

#endif
