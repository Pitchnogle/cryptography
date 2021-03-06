/*
Abstract class definition for a generic cipher

@author Justin Hadella (pitchnogle@gmail.com)
*/
#ifndef CIPHER_H
#define CIPHER_H

#include <ostream>

enum cipher_action
{
  encode,
  decode
};

class cipher
{
public:
  // All ciphers must implement encode & decode functions
  virtual void encode(std::ostream &os, int c) = 0;
  virtual void decode(std::ostream &os, int c) = 0;

  // Converts ASCII into letter num ('A' => 0, 'B' => 1, 'Z' => 25, etc)
  static int a2n(int c) { return toupper(c) - 'A'; }

  // Converts letter num into ASCII (0 => 'A', 1 => 'B', 25 => 'Z', etc)
  static int n2a(int c) { return c + 'A'; }
};

#endif
