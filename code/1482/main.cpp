#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>


int main()
{
  using std::cout;
  using std::cin;
  using std::endl;
  using namespace std::placeholders;

  std::vector<int> vi{1000, 1011, 1021, 1024, 1044, 1055};
  std::vector<std::string> vstr{"pooh", "pooh", "pooh", "pooh", "pangge", "dudongming"};
  cout <<
          std::count_if(vi.begin(), vi.end(), std::bind(std::greater_equal<int>(), _1, 1024))
       << endl;
  cout << *(std::find_if(vstr.begin(), vstr.end(),
                         std::bind(std::not_equal_to<std::string>(), _1, "pooh")))
       << endl;
  auto func = std::bind(std::multiplies<int>(), _1, 2);
  cout << "func: " << func(2) << endl;
  std::transform(vi.begin(), vi.end(), vi.begin(), func);
  for (const auto &val : vi)
    {
      cout << val << " ";
    }
  auto func_div = [](const std::vector<int>& vi, int i)
  {
      return 0 == std::count_if(vi.begin(), vi.end(), std::bind(std::modulus<int>(), _1, i));
    };

  cout << "2" << (func_div(vi, 2) ? "能被所有数整除" :  "不能被所有数整除") << endl;
  cout << endl;
  return 0;
}
