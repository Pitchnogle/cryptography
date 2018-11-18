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
  if (m_mode == alphabet) {
    m_key = n > 0 ? n % 26 : (26 + n) % 26;
  }
  else if (m_mode == ascii_xor) {
    m_key = n;
  }
}

int CaesarCipher::get_shift()
{
  return m_key;
}

void CaesarCipher::encode(std::ostream &os, int c)
{
  if (m_mode == alphabet && !isalpha(c)) return;

  std::cout << (char)shift(c, CipherAction::encode);
}

void CaesarCipher::decode(std::ostream &os, int c)
{
  if (m_mode == alphabet && !isalpha(c)) return;

  std::cout << (char)shift(c, CipherAction::decode);
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Private Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

int CaesarCipher::shift(int c, CipherAction action)
{
  if (m_mode == alphabet) {
    int key = action == CipherAction::encode ? m_key : 26 - m_key;

    return n2a((a2n(c) + key) % 26);
  }
  else if (m_mode == ascii_xor) {
    return c ^ m_key;
  }
}
