/*
Implementation of Caesar cipher class

@author Justin Hadella (pitchnogle@gmail.com)
*/
#include "caesar_cipher.h"

#include <iostream>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Public Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void caesar_cipher::set_shift(int n)
{
  m_key = n > 0 ? n % 26 : (26 + n) % 26;
}

int caesar_cipher::get_shift()
{
  return m_key;
}

void caesar_cipher::encode(std::ostream &os, int c)
{
  if (!isalpha(c)) return;

  os << (char)shift(c, cipher_action::encode);
}

void caesar_cipher::decode(std::ostream &os, int c)
{
  if (!isalpha(c)) return;

  os << (char)shift(c, cipher_action::decode);
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Private Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

int caesar_cipher::shift(int c, cipher_action action)
{
  int key = action == cipher_action::encode ? m_key : 26 - m_key;

  return n2a((a2n(c) + key) % 26);
}
