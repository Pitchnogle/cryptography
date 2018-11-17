/*
This is a simple class which encodes/decodes an input stream to/from Morse code

Modes:
- ditdah
- binary

# ditdah

International Morse code is used except in cases where ASCII doesn't have an
equivalent substitute. For brevity, this version displays indovidual letters
as just dits (.) and dahs (-) without gaps, one space between letters in a
word, and a  " / " between words.

Example:
MORSE CODE
-- --- .-. ... . / -.-. --- -.. .

# binary

International Morse code is used except in cases where ASCII doesn't have an
equivalent substitute. A "dit" is encoded as a "1" and a "dah" is encoded as 
"111". While within a symbol a single "0" is used to separate the "dit" from
the "dah", etc. Spaces between symbols are represented as "000" and "0000000"
between words.

Example:
MORSE CO
1110111000111011101110001011101000101010001000000011101011101000111011101110
===.===...===.===.===...=.===.=...=.=.=...=.......===.=.===.=...===.===.===.
   ^               ^    ^       ^             ^
   |              dah  dit      |             |
symbol space                letter space    word space

@author Justin Hadella (pitchnogle@gmail.com)
*/
#ifndef _MORSE_CODE_H_
#define _MORSE_CODE_H_

#include <ostream>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Definitions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
The morse mode defines the type of encoding/decoding
*/
enum MorseMode {
  /*
  This mode encodes morse into the symbols ['.', '-', ' ', '/']

  For example:
  MORSE CODE
  -- --- .-. ... . / -.-. --- -.. .
  */
  ditdah,

  /*
  This mode encodes morse into binary (1's and 0's)

  For example:
  MORSE
  11101110001110111011100010111010001010100010
  */
  binary
};

/*
Class for encoding/decoding character stream into/from Morse code
*/
class MorseCode
{
public:
  /*
  Function to set the morse mode
  */
  void set_mode(MorseMode mode);

  /*
  Function to encode input into Morse code
  */
  void encode(std::ostream &os, int c);

  /*
  Function to decode input from Morse code
  */
  void decode(std::ostream &os, int c);

private:
  MorseMode m_mode{ditdah};

  int m_decode_idx{0};
  int m_decode_one_count{0};
  int m_decode_zero_count{0};

  /*
  Function takes in character and outputs a morse encoded symbol

  For example:
  'S' -> ...
  'O' -> ---
  */
  void encode_morse_symbol(std::ostream &os, int c);

  /*
  Function takes in sequence of morse symbols to produce an ASCII character

  In order to produce an ASCII this may be called multiple times depending
  on the morse encoding. For example, the sequence "... " would define the
  character 'S'. The space at the end marks the end of the sequence.
  */
  void decode_morse_symbol(std::ostream &os, int c);

  /*
  Function takes in character and outputs a morse encoded bit sequence

  Example:
  'S' -> 101010
  'O' -> 111011101110
  ' ' -> 0000000
  */
  void encode_morse_bit(std::ostream &os, int c);

  /*
  Function takes in sequence of morse bits to produce an ASCII character

  In the morse binary encoding, a 'dit' is the sequence "10" and a 'dah' is the
  sequence "1110". Gaps between letters are the sequence "000" and gaps between 
  words are the sequence "0000000". 

  Basically, this function is acting a ones and zeros counter to produce the
  normal [' ', '.', '-', '/'] symbols the non-binary morse decoder uses. When
  certain counts are encountered, that constructed symbol is then decoded.
  */
  void decode_morse_bit(std::ostream &os, int c);
};

#endif // _MORSE_CODE_H_
