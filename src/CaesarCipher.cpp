/*
Implementation of Caesar cipher class

@author Justin Hadella (pitchnogle@gmail.com)
*/
#include "CaesarCipher.h"

#include <iostream>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Public Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void CaesarCipher::set_shift(int n)
{
  m_key = n > 0 ? n % 26 : (26 + n) % 26;
}

int CaesarCipher::get_shift()
{
  return m_key;
}

void CaesarCipher::encode(std::ostream &os, int c)
{
  if (!isalpha(c)) return;

  std::cout << (char)shift_cipher(c, m_key);
}

void CaesarCipher::decode(std::ostream &os, int c)
{
  if (!isalpha(c)) return;

  std::cout << (char)shift_cipher(c, -m_key);
}

int CaesarCipher::shift_cipher(int c, int k)
{
  int letter_num = toupper(c) - 'A';

  int cipher = (letter_num + k) % 26;
  if (cipher < 0)
    cipher += 26;
  
  return cipher + 'A';
}
