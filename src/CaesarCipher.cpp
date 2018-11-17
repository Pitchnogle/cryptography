/*
Implementation of Caesar cipher class

@author Justin Hadella (pitchnogle@gmail.com)
*/
#include "CaesarCipher.h"

#include <iostream>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Public Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void CaesarCipher::set_n(int n)
{
  if (n < 0)
    m_encode_shift = (26 + n) % 26;
  else
    m_encode_shift = n % 26;
  
  m_decode_shift = 26 - m_encode_shift;
}

int CaesarCipher::get_n()
{
  return m_encode_shift;
}

void CaesarCipher::encode(std::ostream &os, int c)
{
  if (!isalpha(c)) return;

  std::cout << (char)(letter_shift(c, m_encode_shift) + 'A');
}

void CaesarCipher::decode(std::ostream &os, int c)
{
  if (!isalpha(c)) return;

  std::cout << (char)(letter_shift(c, m_decode_shift) + 'A');
}

int CaesarCipher::letter_shift(int c, int n)
{
  int letter_num = toupper(c) - 'A';

  return (letter_num + n) % 26;
}