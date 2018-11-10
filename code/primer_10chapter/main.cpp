#include <iostream>
#include <vector>
#include <algorithm>
#include "1013.h"

int main()
{
  std::vector<std::string> vs{"liuzuyanglength", "liuzuyanglength", "dudongming", "liuz", "songchao", "dudongming", "123", "1234"};
  auto new_end = std::partition(vs.begin(), vs.end(), [](const std::string &str){ return str.size() >= 5;});
  vs.erase(new_end, vs.end());
  for (const auto &val : vs)
    {
      std::cout << val << " | ";
    }
  std::cout << std::endl;

  return 0;
}
