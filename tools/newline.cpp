/*
This is a tool which automatically adds newlines to stream every # columns

@author Justin Hadella (pitchnogle@gmail.com)
*/
#include <iostream>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Function Prototypes
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

static void usage(std::string name);

// =============================================================================
// Main Program
// =============================================================================

int main(int argc, char **argv)
{
  // Insert newline after this column
  int num_cols = 80;

  // Parse command-line arguments
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if ((arg == "-h") || (arg == "--help")) {
      usage(argv[0]);
      return 0;
    }
    else if ((arg == "-n") || (arg == "--num_cols")) {
      if (i + 1 < argc) {
        num_cols = atoi(argv[i + 1]);
      }
    }
  }

  int col_count = 0;

  char c;
  while (std::cin.get(c)) {
    std::cout << c;

    col_count++;
    if (col_count == num_cols) {
      std::cout << std::endl;
      col_count = 0;
    }
  }
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
            << "\t-n,--num_cols\t\tInsert newline automatically every num columns\n"
            << std::endl;
}
