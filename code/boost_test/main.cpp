#include <iostream>
#include <boost/timer.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

int main()
{
  using namespace boost::gregorian;
  boost::timer t;
  data d1{form_string("2018-11-5")};
  std::cout << "已经流逝的时间: " << t.elapsed() << std::endl;
  std::cout << "可计量最大时间: " << t.elapsed_max() / 3600 << "小时" << std::endl;
  std::cout << "可计量最小时间: " << t.elapsed_min() << "秒" << std::endl;
  std::cout << "Hello World!" << std::endl;
  std::cout << "消耗时间: " << t.elapsed() << std::endl;
  return 0;
}
