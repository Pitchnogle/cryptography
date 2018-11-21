/*
This is a Vigenère cipher encoder/decoder

@author Justin Hadella (pitchnogle@gmail.com)
*/
#include <iostream>
#include <string>

#include "vigenere_cipher.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Function Prototypes
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

static void usage(std::string name);

// =============================================================================
// Main Program
// =============================================================================

int main(int argc, char **argv)
{
  bool decode_message = false;
  bool use_xor_mode = false;

  std::string key;

  // Parse command-line arguments
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if ((arg == "-h") || (arg == "--help")) {
      usage(argv[0]);
      return 0;
    }
    else if ((arg == "-d") || (arg == "--decode")) {
      decode_message = true;
    }
    else if ((arg == "-k") || (arg == "--key")) {
      if (i + 1 < argc) {
        key = argv[i + 1];
        i++;
      }
      else {
        usage(argv[0]);
        std::cerr << "-key requires an argument" << std::endl;
        return 1;
      }
    }
    else if ((arg == "-x") || (arg == "--xor")) {
      use_xor_mode = true;
    }
    else {
      usage(argv[0]);
      std::cerr << "Invalid argument \"" << argv[i] << "\"" << std::endl;
      return 1;
    }
  }

  vigenere_cipher cipher;

  cipher.set_key(key);
  
  if (use_xor_mode)
    cipher.set_mode(xor_ascii);

  char c;
  while (std::cin.get(c)) {
    if (!use_xor_mode && (c == ' ' || c == '\n'))
      std::cout << c;
    
    if (decode_message)
      cipher.decode(std::cout, c);
    else
      cipher.encode(std::cout, c);
  };

  return 0;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Private Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

static void usage(std::string name)
{
  std::cerr << "Usage: " << name << " <option(s)>\n"
            << "Options:\n"
            << "\t-h,--help\t\tShow this help message\n"
            << "\t-d,--decode\t\tDecode input stream\n"
            << "\t-k,--key KEY_STRING\tThe Vigenère key\n"
            << "\t-x,--xor\t\tUse XOR mode\n"
            << std::endl;
}
