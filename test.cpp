#include <iostream>

int main()
{
  for (int i = 0, key = 3; i < 26; i++) {
    std::cout << i << "\t" << (i + key) % 26 << std::endl;
  }

  for (int i = 0, key = 3; i < 26; i++) {
    std::cout << i << "\t" << (i - key) % 26 << std::endl;
  }

  return 0;
}