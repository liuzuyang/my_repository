#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <deque>

std::istream &readStream(std::istream &, std::ostream &);

template <typename InputIterator, typename T>
bool find_elem(InputIterator beg, InputIterator end, const T &val)
{
  for (;beg != end; ++beg)
    {
      if (*beg == val)
        {
          return true;
        }
    }
  return false;
}

int main()
{
  using std::cout;
  using std::endl;
  using std::cin;

  std::vector<int> vi{1, 2 , 4, 4, 23, 10 ,23, 39, 10};
  std::deque<int> de1{};
  std::deque<int> de2{};
  for (const auto &val : vi)
    {
      if (val % 2 == 0)
        {
          de1.push_back(val);
        }
      else
        {
          de2.push_back(val);
        }
    }
  cout << "偶数: ";
  for (const auto &val : de1)
    {
      cout << val << " | ";
    }
  cout << endl;
  cout << "奇数: ";
  for (const auto &val : de2)
    {
      cout << val << " | ";
    }
  cout << endl;
}

std::istream &readStream(std::istream &is, std::ostream &os)
{
  for (int str{}; !is.eof() && !is.bad() && !is.fail();)
    {   //若未达到文件尾部且strm未被破坏则读入数据
      is >> str;
      os << str;
    }
  if (is.bad())
    {
      std::cerr << "流被破坏" << std::endl;
      exit(-1);
    }
  else
    {
      is.clear();
    }
  return is;
}
