/*
This is a tool which scrambles an input string

@author Justin Hadella (pitchnogle@gmail.com)
*/
#include <iostream>
#include <random>
#include <vector>

// =============================================================================
// Main Program
// =============================================================================

int main(int argc, char **argv)
{  
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " [string]\n"
              << std::endl;
    return 1;
  }

  // The string to scramble is the the user argument
  std::string msg = argv[1];

  // Setup uniform random number distribution
  std::random_device random_device;
  std::mt19937 engine{random_device()};
  std::uniform_int_distribution<int> dist(0, msg.length() - 1);
  
  // Randomly swap a pair of characters 
  for (size_t i = 0; i < 100 * msg.length(); i++) {
    std::swap(msg[dist(engine)], msg[dist(engine)]);
  }

  std::cout << msg;

  return 0;
}
