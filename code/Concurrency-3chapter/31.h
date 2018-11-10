#ifndef _A31_H
#define _A31_H

#include <list>
#include <thread>
#include <algorithm>

class add_some_to_list
{
public:
  void add_to_list(int new_value);
  bool find_data_in_list(int some_value);

private:
  std::mutex some_mutex;        //一个互斥锁
  std::list<int> my_list;

};

void add_some_to_list::add_to_list(int new_value)
{
  std::lock_guard<std::mutex> guard{some_mutex};
  my_list.push_back(new_value);
}

bool add_some_to_list::find_data_in_list(int some_value)
{
  std::lock_guard<std::mutex> guard{some_mutex};
  return std::find(my_list.begin(), my_list.end(), some_value) != my_list.end();
}
#endif // 31_H
