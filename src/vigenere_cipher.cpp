/*
Implementation of Vigenère cipher class

@author Justin Hadella (pitchnogle@gmail.com)
*/
#include "vigenere_cipher.h"

#include <iostream>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Public Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void vigenere_cipher::set_key(std::string key)
{
  m_key = key;
  m_idx = 0;
}

void vigenere_cipher::set_mode(vigenere_mode mode)
{
  m_mode = mode;
}

void vigenere_cipher::encode(std::ostream &os, int c)
{
  if (m_mode == alphabet && !isalpha(c)) return;

  if (m_mode == alphabet)
    os << (char)shift_alpha(c, cipher_action::encode);
  else
    os << (char)shift_xor(c);
}

void vigenere_cipher::decode(std::ostream &os, int c)
{
  if (m_mode == alphabet && !isalpha(c)) return;

  if (m_mode == alphabet)
    os << (char)shift_alpha(c, cipher_action::decode);
  else
    os << (char)shift_xor(c);
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Private Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

int vigenere_cipher::shift_alpha(int c, cipher_action action)
{
  int tmp = a2n(c);
  if (action == cipher_action::encode)
    tmp += a2n(m_key[m_idx]);
  else
    tmp -= a2n(m_key[m_idx]);

  int ret = tmp % 26;
  if (ret < 0) ret += 26;

  m_idx++;
  m_idx %= m_key.length();

  return n2a(ret); // convert back to ascii
}

int vigenere_cipher::shift_xor(int c)
{
  size_t len = m_key.length();

  int k = m_key[m_idx++ % len];

  return c ^ k;
}
