/**
@file morse_decode.cpp

This is a simple filter which decodes a morse encoded input stream into ASCII

International Morse code is used except in cases where ASCII doesn't have an
equivalent substitute. 

Example:
-- --- .-. ... . / -.-. --- -.. .
MORSE CODE

@author Justin Hadella (pitchnogle@gmail.com)
*/
#include <iostream>
#include <ostream>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Function Prototypes
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
Function takes in sequence of morse symbols to produce an ASCII character

In order to produce an ASCII this may be called multiple times depending
on the morse encoding. For example, the sequence "... " would define the
character 'S'. The space at the end marks the end of the sequence.
*/
void decode_morse_symbol(std::ostream &os, int c);

// =============================================================================
// Main Program
// =============================================================================

int main()
{
  char c;
  while (std::cin.get(c)) {
    if (c == '\n')
      std::cout << std::endl;
    
    decode_morse_symbol(std::cout, c);
  }
  std::cout << std::endl;
  
  return 0;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Private Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Morse tree ordered in terms of levels
const char morse_tree[] =
{
  0x0, 'E', 'T', 'I', 'A', 'N', 'M', 'S', 'U', 'R', 'W', 'D', 'K', 'G', 'O', 'H',
  'V', 'F', 0x0, 'L', 0x0, 'P', 'J', 'B', 'X', 'C', 'Y', 'Z', 'Q', 0x0, 0x0, '5',
  '4', 0x0, '3', 0x0, 0x0, 0x0, '2', '&', 0x0, '+', 0x0, 0x0, 0x0, 0x0, '1', '6',
  '=', '/', 0x0, 0x0, 0x0, '(', 0x0, '7', 0x0, 0x0, 0x0, '8', 0x0, '9', '0', 0x0,
  0x0, 0x0, 0x0, '$', 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, '?', '_', 0x0, 0x0, 0x0,
  0x0, '"', 0x0, 0x0, '.', 0x0, 0x0, 0x0, 0x0, '@', 0x0, 0x0, 0x0, '\'', 0x0, 0x0,
  '-', 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, ';', '!', 0x0, ')', 0x0, 0x0, 0x0,
  0x0, 0x0, ',', 0x0, 0x0, 0x0, 0x0, ':', 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
};

const int max_i = sizeof (morse_tree) / sizeof (morse_tree[0]);

void decode_morse_symbol(std::ostream &os, int c)
{
  bool reset = false;

  // Index into morse tree
  static int i = 0;

  switch (c) {
  case '.':
    i = 2 * i + 1;
    break;

  case '-':
    i = 2 * i + 2;
    break;

  case ' ':
    if (i != 0 && i < max_i)
      std::cout << (char)morse_tree[i];
    reset = true;
    break;

  case '/':
    std::cout << " ";
    reset = true;
    break;
  }

  if (reset) {
    i = 0;
  }
}
