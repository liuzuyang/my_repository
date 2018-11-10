#include <iostream>
#include "31.h"
#include <thread>

int main()
{
  add_some_to_list my_a;
  std::thread t1{&add_some_to_list::add_to_list, &my_a, 10}; //启动一个线程向list中添加数据
  if (my_a.find_data_in_list(10))
    {
      std::cout << "数据10已经添加进链表" << std::endl;
    }
  t1.join();
  return 0;
}
