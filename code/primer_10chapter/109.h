#ifndef _a109_H
#define _a109_H

#include <algorithm>
#include <vector>
#include <string>

class compVstr
{
public:
  bool operator()(const std::string &vs1, std::string &vs2)
  {
    return vs1.size() < vs2.size();
  }
};

template <typename T>
void elimDups(std::vector<T> &v)
{
  std::sort(v.begin(), v.end(), compVstr{});
  auto new_end = std::unique(v.begin(), v.end());
  v.erase(new_end, v.end());
}

#endif // 109_H
