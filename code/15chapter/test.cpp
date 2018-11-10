#include <iostream>
#include <algorithm>

//void swap(int, int){std::cout << "调用全局swap" << std::endl;}
namespace n_a
{
  struct aa
  {
    virtual void swap(int, int, int) {std::cout << "调用基类作用域中swap" << std::endl;}
  };

  struct bb : aa
  {
    void bf() {
      //using std::swap;  //使标准库中函数曝光
      aa::swap(a, b, b);
    }
    void swap(int, int) {std::cout << "调用bb成员函数swap" << std::endl;}
    int a{1}, b{2};
  };
  void swap(int, int) {std::cout << "调用所在名字空间中swap" << std::endl;}
}

int main()
{
  using namespace std;
  n_a::bb B;
  B.bf();
  cout << "B.a: " << B.a << "B.b" << B.b << endl;
}
