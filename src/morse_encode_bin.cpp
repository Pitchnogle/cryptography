/*
This is a simple filter which outputs an input stream into morse code

International Morse code is used except in cases where ASCII doesn't have an
equivalent substitute. A "dit" is encoded as a "1" and a "dah" is encoded as 
"111". While within a symbol a single "0" is used to separate the "dit" from
the "dah", etc. Spaces between symbols are represented as "000" and "0000000"
between words.

Example:
         1         2         3         4         5         6         7         8
12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012
 
M------   O----------   R------   S----   E       C----------   O----------   D------   E

11101110001110111011100010111010001010100010000000111010111010001110111011100011101010001000
===.===...===.===.===...=.===.=...=.=.=...=.......===.=.===.=...===.===.===...===.=.=...=...
   ^               ^    ^       ^             ^
   |              dah  dit      |             |
symbol space                letter space    word space

@author Justin Hadella (pitchnogle@gmail.com)
*/
#include <iostream>
#include <ostream>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Function Prototypes
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
Function takes in character and output morse encoded bit sequence

Example:
's' -> 101010
'o' -> 111011101110
' ' -> 0000000
*/
void encode_morse_bit(std::ostream &os, int c);

// =============================================================================
// Main Program
// =============================================================================

int main()
{
	char c;
  while (std::cin.get(c)) {
  	encode_morse_bit(std::cout, c);
  }
  std::cout << std::endl;
  return 0;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Private Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

const int morse_code[] =
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
	0x55,   /* 'h' */ 	0x5,    /* 'i' */ 	0xa9,   /* 'j' */ 	0x26,   /* 'k' */
	0x59,   /* 'l' */ 	0xa,    /* 'm' */ 	0x6,    /* 'n' */ 	0x2a,   /* 'o' */
	0x69,   /* 'p' */ 	0x9a,   /* 'q' */ 	0x19,   /* 'r' */ 	0x15,   /* 's' */
	0x2,    /* 't' */ 	0x25,   /* 'u' */ 	0x95,   /* 'v' */ 	0x29,   /* 'w' */
	0x96,   /* 'x' */ 	0xa6,   /* 'y' */ 	0x5a,   /* 'z' */ 	0x0,    /* '{' */
	0x0,    /* '|' */ 	0x0,    /* '}' */ 	0x0,    /* '~' */ 	0x0,    /* '' */
};

void encode_morse_bit(std::ostream &os, int c)
{
	const int ascii_mask = 0x7f;

	c &= ascii_mask;
	c = morse_code[c];
	
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
