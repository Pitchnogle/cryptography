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
Function takes in sequence of morse bits to produce an ASCII character

In the morse binary encoding, a 'dit' is the sequence "10" and a 'dah' is the
sequence "1110". Gaps between letters are the sequence "000" and gaps between 
words are the sequence "0000000". 

Basically, this function is acting a ones and zeros counter to produce the
normal [' ', '.', '-', '/'] symbols the non-binary morse decoder uses. When
certain counts are encountered, that constructed symbol is then decoded...
*/
void decode_morse_bit(std::ostream &os, int c);

/*
Function takes in sequence of morse symbols to produce an ASCII character

In order to produce an ASCII this may be called multiple times depending
on the morse encoding. For example, the sequence "... " would define the
's'. The space at the end marks the end of the sequence.
*/
void decode_morse_symbol(std::ostream &os, int c);

// =============================================================================
// Main Program
// =============================================================================

int main()
{
  char c;
  while (std::cin.get(c)) {
    decode_morse_bit(std::cout, c);
  }
  std::cout << std::endl;
  
  return 0;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Private Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Morse tree order in terms of levels
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

void decode_morse_bit(std::ostream &os, int c)
{
  static int one_count = 0;
  static int zer_count = 0;
  
  if (c == '1') {
    one_count++;
    zer_count = 0;
  }

  if (c == '0') {
    zer_count++;
  
    if (one_count == 1)
      decode_morse_symbol(os, '.');
    else if (one_count == 3)
      decode_morse_symbol(os, '-');

    one_count = 0;
  }

  if (zer_count == 3)
    decode_morse_symbol(os, ' ');

  if (zer_count == 7)
    decode_morse_symbol(os, '/');
}

void decode_morse_symbol(std::ostream &os, int c)
{
  bool reset = false;

  int max_i = sizeof (morse_tree) / sizeof (morse_tree[0]);

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
