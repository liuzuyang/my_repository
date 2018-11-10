#include <iostream>

class Base
{
  public:
    //引入虚函数
    virtual int fcn(){
      std::cout << "调用base: fcn()" << std::endl;
      return 0;
    }
};

class D1 : public Base
{
  public:
    //隐藏虚基类中的同名虚函数
    int fcn() override{
      std::cout << "调用D1: fcn(int)" << std::endl;
      return 0;
    }
    virtual void f2(){
      std::cout << "调用d1: f2()" << std::endl;
    }
};

class D2 : public D1
{
  public:
    //隐藏虚基类中的同名函数
    int fcn(int){
      std::cout << "调用d2: fcn(int)" << std::endl;
      return 0;
    }
    //覆盖了base的fcn()函数
    int fcn(){
      std::cout << "调用d2: fcn()" << std::endl;
      return 0;
    }
    //覆盖了D1的f2()函数
    void f2(){
      std::cout << "调用d2: f2()" << std::endl;
    }
};

int main()
{
  Base bobj;
  D1 d1obj;
  D2 d2obj;

  Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
  //虚调用调用Base::fcn();
  bp1->fcn();
  //虚调用调用Base::fcn();
  bp2->fcn();
  //虚调用调用D2::fcn();
  bp3->fcn();
  D1 *d1p = &d1obj, *d2p = &d2obj;
  //错误:静态无权限访问f2()
 // bp2->f2();
  //正确:虚调用调用D1中f2()
  d1p->f2();
  //正确:虚调用调用D2中f2()
  d2p->f2();
}

