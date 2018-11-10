#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

int main()
{
  std::vector<int> vi{10, 293, 2348, 234, 123, 10, 10, 50};
  std::sort(vi.begin(), vi.end());
  auto unique_end = std::unique(vi.begin(), vi.end());
  for (const auto &val : vi)
    {
      std::cout << val << " | ";
    }
  std::cout << std::endl;
  vi.erase(unique_end, vi.end());
  for (const auto &val : vi)
    {
      std::cout << val << " | ";
    }
  std::cout << std::endl;
  return 0;
}
