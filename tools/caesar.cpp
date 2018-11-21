/*
This is a Ceasar cipher encoder/decoder

@author Justin Hadella (pitchnogle@gmail.com)
*/
#include <iostream>

#include "caesar_cipher.h"
#include "cipher.h"

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

  // Default shift
  int caesar_shift = 7;

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
    else if ((arg == "-s") || (arg == "--shift")) {
      if (i + 1 < argc) {
        caesar_shift = atoi(argv[i + 1]);
        i++;
      }
      else {
        usage(argv[0]);
        std::cerr << "--shift requires an integer argument" << std::endl;
        return 1;
      }
    }
    else {
      usage(argv[0]);
      std::cerr << "Invalid argument \"" << argv[i] << "\"" << std::endl;
      return 1;
    }
  }

  caesar_cipher caesar;
  caesar.set_shift(caesar_shift);

  char c;
  while (std::cin.get(c)) {
    if (c == ' ' || c == '\n')
      std::cout << c;
    
    if (decode_message)
      caesar.decode(std::cout, c);
    else
      caesar.encode(std::cout, c);
  };
  std::cout << std::endl;

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
            << "\t-s,--shift INT_SHIFT\tSet Caesar cipher shift\n"
            << "\t-d,--decode\t\tDecode input stream\n"
            << std::endl;
}
