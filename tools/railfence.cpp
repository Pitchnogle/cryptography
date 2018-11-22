/*
This is a Rail-fence cipher encoder/decoder

@author Justin Hadella (pitchnogle@gmail.com)
*/
#include <iostream>
#include <vector>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Function Prototypes
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

static void usage(std::string name);

static void encode(std::vector<std::vector<int>>& msg, int key);
static void decode(std::vector<int>& msg, int key);

// =============================================================================
// Main Program
// =============================================================================

int main(int argc, char **argv)
{
  bool decode_message = false;

  int num_rails = 3;

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
    else if ((arg == "-r") || (arg == "--rails")) {
      if (i + 1 < argc) {
        num_rails = atoi(argv[i + 1]);
        i++;
      }
      else {
        usage(argv[0]);
        std::cerr << "--rails requires an integer argument > 0" << std::endl;
        return 1;
      }
      if (num_rails < 0) {
        usage(argv[0]);
        std::cerr << "--rails requires an integer argument > 0" << std::endl;
        return 1;
      }
    }
    else {
      usage(argv[0]);
      std::cerr << "Invalid argument \"" << argv[i] << "\"" << std::endl;
      return 1;
    }
  }

  if (decode_message) {
    std::vector<int> msg;
    char c;
    while (std::cin.get(c)) {
      if (isalpha(c)) {
        msg.push_back(c);
      }
    }

    decode(msg, num_rails);
  }
  else {
    std::vector<std::vector<int>> rows(num_rails);
    encode(rows, num_rails);
    
    for (std::vector<int> row : rows) {
      for (int c : row) {
        std::cout << (char)c;
      }
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
            << "\t-r,--rails INT_RAILS\tSet the number of rails (3 is default)\n"
            << "\t-d,--decode\t\tDecode input stream\n"
            << std::endl;
}

static void encode(std::vector<std::vector<int>>& msg, int key)
{
  size_t row = 0;
  int dir = 1;

  char c;
  while (std::cin.get(c)) {
    if (isalpha(c)) {
      msg[row % key].push_back(toupper(c));

      // The row index bounces between 0 and key - 1
      row += dir;
      if (row == 0) 
        dir = 1;
      if (row == (size_t)(key - 1))
        dir = -1;
    }
  };
}

static void decode(std::vector<int>& msg, int key)
{
  std::vector<int> decoded(msg.size());

  int k = 0;
  int row;
  for (row = 0; row < key - 1; row++) {
    int skip = 2 * (key - row - 1);
    int j = 0;
    for (size_t i = row/*, j = 0*/; i < msg.size(); ) {
      decoded[i] = msg[k++];
      if ((row == 0) || (j % 2 == 0)) {
        i += skip;
      }
      else {
        i += 2 * (key - 1) - skip;
      }
      j++;
    }
  }
  for (size_t i = row; i < msg.size(); i += 2 * (key - 1)) {
    decoded[i] = msg[k++];
  }

  // Display the decoded data
  for (size_t i = 0; i < decoded.size(); i++) {
    std::cout << (char)decoded[i];
  }

  // Another (more modern way to do it)
  /*
  for (auto i = decoded.begin(); i != decoded.end(); ++i) {
    std::cout << (char)*i;
  }
  */
}
