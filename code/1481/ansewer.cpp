#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

//函数对象当参数长度与指定长度一致时返回true
class StrLenIs
{
public:
  using Szie = decltype (std::string{}.length());
  StrLenIs(Szie n) : m_sz{n}{}
  bool operator()(const std::string &str) const
  {
    return m_sz == str.length();
  }

private:
  Szie m_sz{0};
};

void ReadFile(std::vector<std::string> &vi, std::ifstream &in)
{
  std::string tmp_str{};
  std::cout << "请输入文件名: ";
  std::cin >> tmp_str;
  in.open(tmp_str);
  if (!in.is_open())
    {
      std::cout << "打开文件失败!" << std::endl;
      exit(-1);
    }
  for (; in >> tmp_str;)
    {
      vi.push_back(std::move(tmp_str));
    }
}

int main()
{
  using std::cout;
  using std::endl;
  using std::cin;

  std::ifstream infile;
  std::vector<std::string> vStr;
  const int minSize = 1;
  const int maxSize = 10;
  ReadFile(vStr, infile);
  for (StrLenIs::Szie i{minSize}; i <= maxSize; ++i)
    {
      cout << "长度为" << i << "的单词有: " <<
              std::count_if(vStr.begin(), vStr.end(), StrLenIs{i}) << "个" << endl;
    }
}
