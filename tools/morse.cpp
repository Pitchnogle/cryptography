/*
This is a tool which uses the MorseCode class to encode/decode messages

@author Justin Hadella (pitchnogle@gmail.com)
*/
#include <iostream>

#include "morse_code.h"

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
  bool set_binary_mode = false;

  // Parse command-line arguments
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if ((arg == "-h") || (arg == "--help")) {
      usage(argv[0]);
      return 0;
    }
    else if ((arg == "-b") || (arg == "--binary")) {
      set_binary_mode = true;
    }
    else if ((arg == "-d") || (arg == "--decode")) {
      decode_message = true;
    }
    else {
      usage(argv[0]);
      std::cerr << "Invalid argument \"" << argv[i] << "\"" << std::endl;
      return 1;
    }
  }

  morse_code morse;

  if (set_binary_mode)
    morse.set_mode(binary);
  
  char c;
  while (std::cin.get(c)) {
    // Don't process newline
    if (c == '\n') {
      std::cout << std::endl;
      continue;
    }

    if (decode_message)
      morse.decode(std::cout, c);
    else
      morse.encode(std::cout, c);
  }

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
            << "\t-b,--binary\t\tSet mode to binary\n"
            << "\t-d,--decode\t\tDecode input stream\n"
            << std::endl;
}
