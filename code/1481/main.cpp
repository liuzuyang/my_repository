#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>

class cheack_size
{
public:
  void operator()(decltype (std::string().size()) n)
  {
    if (n > 0 && n <= 10)
      {
        ++(word_size[n - 1]);
      }
  }
  std::array<int, 10> word_size{};
};
//di si ci

class cheack_size1
{

  void operator()(decltype (std::string().size()) n)
  {
    if (n > 0 && n <= 9)
      {
        ++(word_size[n - 1]);
      }
    else
      {
        ++(word_size[9]);
      }
  }
  std::array<int, 10> word_size{};
};

int main(int argc, char **argv)
{
  using std::cout;
  using std::endl;
  using std::cin;
  cheack_size cs;
  const int minSize{1};
  //const int maxSize{10};
  //cheack_size1 cs2;

//lll
  //di er ci
 std::string filename{};
 cout << "请输入文件名: ";
 cin >> filename;
 std::ifstream infile{filename};
 if (!infile.is_open())
   {
     cout << "文件打开失败!" << endl;
     exit(-1);
   }
 std::string word;
 for (;infile >> word;)
   {
     cs(word.length());
   }
 int i{minSize};
 int tt;
 //di san ci
 for (const auto &val : cs.word_size)
   {
     cout << "长度为" << i << "的单词有: " << val << "个" << endl;
     ++i;
   }

  return 0;
}
