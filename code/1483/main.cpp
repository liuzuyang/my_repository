#include <iostream>
#include <functional>
#include <string>
#include <map>
#include <initializer_list>
#include <utility>

template <typename T>
class add
{
public:
  T operator()(T t1, T t2){return t1 + t2;}
};

template <typename T>
T sub(T t1, T t2)
{
  return t1 - t2;
}

template <typename T>
using map_f = std::map<std::string, std::function<T (T, T)>>;

template <typename T>
class counter
{
public:
  using func = std::function<T (T, T)>;
  counter() = default;
  counter(const std::initializer_list<std::pair<std::string, func>> &il);
  T operator()(const std::string &op, T t1, T t2){return mf[op](t1, t2);}
private:
  map_f<T> mf; //存储用于计算的函数对象
};

template <typename T>
counter<T>::counter(const std::initializer_list<std::pair<std::string, func>> &il)
{
  for (const auto &val : il)
    {
      mf[val.first] = val.second;
    }
}

template <typename T>
counter<T> make_counter()
{
  auto mul = [](T t1, T t2){return t1 * t2;};
  return counter<int>{{"+", add<T>()}, {"-", sub<T>}, {"*", mul},
                   {"/", std::divides<T>()},
                   {"%", [](T t1, T t2){return t1 % t2;}}};
}
int main()
{
  using std::cin;
  using std::cout;
  using std::endl;
  int t1, t2;
  std::string op;
  auto cou = make_counter<int>();
  for (;cin >> t1 && cin >> op && cin >> t2;)
    {
      cout << "result: " << cou(op, t1, t2) << endl;
    }

  return 0;
}
