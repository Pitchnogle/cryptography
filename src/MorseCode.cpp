/**
@file MorseCode.cpp

See header

@author Justin Hadella (pitchnogle@gmail.com)
*/
#include "MorseCode.h"

#include <iostream>

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Morse Lookup Tables
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

const int morse_encode_table[] =
{
  0x0,    /* NUL */   0x0,    /* SOH */  	0x0,    /* STX */   0x0,    /* ETX */
  0x0,    /* EOT */ 	0x0,    /* ENQ */ 	0x0,    /* ACK */ 	0x0,    /* BEL */
  0x0,    /* BS  */ 	0x0,    /* TAB */ 	0x0,    /* LF  */ 	0x0,    /* VT  */
  0x0,    /* FF  */ 	0x0,    /* CR  */ 	0x0,    /* SO  */ 	0x0,    /* SI  */
  0x0,    /* DLE */ 	0x0,    /* DC1 */ 	0x0,    /* DC2 */ 	0x0,    /* DC3 */
  0x0,    /* DC4 */ 	0x0,    /* NAK */ 	0x0,    /* SYN */ 	0x0,    /* ETB */
  0x0,    /* CAN */ 	0x0,    /* EM  */ 	0x0,    /* SUB */ 	0x0,    /* ESC */
  0x0,    /* FS  */ 	0x0,    /* GS  */ 	0x0,    /* RS  */ 	0x0,    /* US  */
  0x3,    /* ' ' */ 	0xa66,  /* '!' */ 	0x659,  /* '"' */ 	0x0,    /* '#' */
  0x595,  /* '$' */ 	0x0,    /* '%' */ 	0x159,  /* '&' */ 	0x6a9,  /* ''' */
  0x1a6,  /* '(' */ 	0x9a6,  /* ')' */ 	0x0,    /* '*' */ 	0x199,  /* '+' */
  0xa5a,  /* ',' */ 	0x956,  /* '-' */ 	0x999,  /* '.' */ 	0x196,  /* '/' */
  0x2aa,  /* '0' */ 	0x2a9,  /* '1' */ 	0x2a5,  /* '2' */ 	0x295,  /* '3' */
  0x255,  /* '4' */ 	0x155,  /* '5' */ 	0x156,  /* '6' */ 	0x15a,  /* '7' */
  0x16a,  /* '8' */ 	0x1aa,  /* '9' */ 	0x56a,  /* ':' */ 	0x666,  /* ';' */
  0x0,    /* '<' */ 	0x256,  /* '=' */ 	0x0,    /* '>' */ 	0x5a5,  /* '?' */
  0x669,  /* '@' */ 	0x9,    /* 'A' */ 	0x56,   /* 'B' */ 	0x66,   /* 'C' */
  0x16,   /* 'D' */ 	0x1,    /* 'E' */ 	0x65,   /* 'F' */ 	0x1a,   /* 'G' */
  0x55,   /* 'H' */ 	0x5,    /* 'I' */ 	0xa9,   /* 'J' */ 	0x26,   /* 'K' */
  0x59,   /* 'L' */ 	0xa,    /* 'M' */ 	0x6,    /* 'N' */ 	0x2a,   /* 'O' */
  0x69,   /* 'P' */ 	0x9a,   /* 'Q' */ 	0x19,   /* 'R' */ 	0x15,   /* 'S' */
  0x2,    /* 'T' */ 	0x25,   /* 'U' */ 	0x95,   /* 'V' */ 	0x29,   /* 'W' */
  0x96,   /* 'X' */ 	0xa6,   /* 'Y' */ 	0x5a,   /* 'Z' */ 	0x1a6,  /* '[' */
  0x0,    /* '\' */ 	0x9a6,  /* ']' */ 	0x0,    /* '^' */ 	0x9a5,  /* '_' */
  0x0,    /* '`' */ 	0x9,    /* 'a' */ 	0x56,   /* 'b' */ 	0x66,   /* 'c' */
  0x16,   /* 'd' */ 	0x1,    /* 'e' */ 	0x65,   /* 'f' */ 	0x1a,   /* 'g' */
  0x55,   /* 'h' */ 	0x5,    /* 'decode_idx' */ 	0xa9,   /* 'j' */ 	0x26,   /* 'k' */
  0x59,   /* 'l' */ 	0xa,    /* 'm' */ 	0x6,    /* 'n' */ 	0x2a,   /* 'o' */
  0x69,   /* 'p' */ 	0x9a,   /* 'q' */ 	0x19,   /* 'r' */ 	0x15,   /* 's' */
  0x2,    /* 't' */ 	0x25,   /* 'u' */ 	0x95,   /* 'v' */ 	0x29,   /* 'w' */
  0x96,   /* 'x' */ 	0xa6,   /* 'y' */ 	0x5a,   /* 'z' */ 	0x0,    /* '{' */
  0x0,    /* '|' */ 	0x0,    /* '}' */ 	0x0,    /* '~' */ 	0x0,    /* '' */
};

// Morse tree ordered in terms of levels
const char morse_decode_table[] =
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

const int decode_max_i = sizeof (morse_decode_table) / sizeof (morse_decode_table[0]);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Public Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

MorseCode::MorseCode()
{
  mode = ditdah;

  decode_idx = 0;
  decode_one_count = 0;
  decode_zero_count = 0;
}

void MorseCode::set_mode(morse_mode damode)
{
  mode = damode;
}

void MorseCode::encode(std::ostream &os, int c)
{
  if (ditdah == mode)
    encode_morse_symbol(os, c);
  else
    encode_morse_bit(os, c);
}

void MorseCode::decode(std::ostream &os, int c)
{
  if (ditdah == mode)
    decode_morse_symbol(os, c);
  else
    decode_morse_bit(os, c);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Private Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void MorseCode::encode_morse_symbol(std::ostream &os, int c)
{
  const int ascii_mask = 0x7f;

  c &= ascii_mask;
  c  = morse_encode_table[c];

  bool print_gap = c != 0;

  while (c > 0) {
    switch (c & 0x3) {
    case 0: break;
    case 1: os << '.'; break;
    case 2: os << '-'; break;
    case 3: os << "/ "; print_gap = false; break; // word indicator
    }
    c = c >> 2;
  };
	
  if (print_gap) os << " "; // 1 space between letters
}

void MorseCode::decode_morse_symbol(std::ostream &os, int c)
{
  bool reset = false;

  switch (c) {
  case '.': decode_idx = 2 * decode_idx + 1; break; // dit
  case '-': decode_idx = 2 * decode_idx + 2; break; // dah

  case ' ':
    if (decode_idx != 0 && decode_idx < decode_max_i)
      std::cout << (char)morse_decode_table[decode_idx];
    reset = true;
    break;

  case '/':
    std::cout << " ";
    reset = true;
    break;
  }

  if (reset) decode_idx = 0;
}

void MorseCode::encode_morse_bit(std::ostream &os, int c)
{
  const int ascii_mask = 0x7f;

  c &= ascii_mask;
  c  = morse_encode_table[c];

  bool print_gap = c != 0;

  while (c > 0) {
    switch (c & 0x3) {
    case 0: break;
    case 1: os << "10"; break;
    case 2: os << "1110"; break;
    case 3: os << "0000"; print_gap = false; break; // 4 additional spaces between words
    }
    c = c >> 2;
  };
	
  if (print_gap) os << "00"; // 3 space between letters (one part of letter itself)
}

void MorseCode::decode_morse_bit(std::ostream &os, int c)
{
  if (c == '1') {
    decode_one_count++;
    decode_zero_count = 0;
  }

  if (c == '0') {
    decode_zero_count++;
  
    if (decode_one_count == 1)
      decode_morse_symbol(os, '.');
    else if (decode_one_count == 3)
      decode_morse_symbol(os, '-');

    decode_one_count = 0;
  }

  if (decode_zero_count == 3)
    decode_morse_symbol(os, ' ');

  if (decode_zero_count == 7)
    decode_morse_symbol(os, '/');
}
