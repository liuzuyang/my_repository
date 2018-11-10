#include <iostream>
#include <thread>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <boost/progress.hpp>

template <typename _InputIterator, typename T>
struct accumulate_block
{
public:
  void operator()(_InputIterator beg, _InputIterator end,  T &val)
  {
    boost::progress_timer{std::cout};
    val = std::accumulate(beg, end, val);
  }
};

//并发计算
template <typename _InputIterator, typename T>
T paraller_accumulate(_InputIterator beg, _InputIterator end, const T &val)
{
  //计算区间长度
  const std::size_t length{static_cast<std::size_t>(std::distance(beg, end))};
  if (!length)
    {   //若计算区间长度为0
      return val;
    }
  const std::size_t min_per_thread{100};        //每个线程计算的区间最小区间长度
  const std::size_t max_thread{(length + min_per_thread) / min_per_thread};        //确定最大线程数
  const std::size_t handware_thread{std::thread::hardware_concurrency()};       //返回硬件支持的最大线程数，用于防止超额认购
  std::cout << "硬件支持的最大啊线程数: " << handware_thread << std::endl;
  /*
   * 注: 下列表达式在硬件和算法需要的线程数中选取较小的数目，因为若实际线程数超过硬件支持的最大线程数会导致超额认购，
   * 这样性能会下降，而若实际线程数大于算法需要的线程数则会产生不必要的浪费
   */
  const std::size_t num_thread{std::min(handware_thread != 0 ? handware_thread : 2, max_thread)};       //实际线程数
  const std::size_t block_size{length / num_thread};   //保存算法分块数量
  std::vector<T> results(static_cast<T>(num_thread));         //保存每个线程产生的中间结果
  std::vector<std::thread> threads{num_thread - 1};     //注意容器中保存的线程比时间线程少，因为主线程中存在一个线程

  _InputIterator block_strat{beg};
  for (std::size_t i{0}; i < num_thread - 1; ++i)
    {   //循环创建线程
      _InputIterator block_end{block_strat};
      std::advance(block_end, block_size);      //将block_end迭代器累进到尾后
      //注意:下列表达创建了一个线程并加入线程池中
      threads[i] = std::thread{accumulate_block<_InputIterator, T>(), block_strat, block_end, std::ref(results[i])};
      block_strat = block_end;  //新区间起始点
    }
  accumulate_block<_InputIterator, T>()(block_strat, end, std::ref(results[num_thread - 1]));     //在主线程中处理最后的计算
  std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
  int i{1};
  for (const auto &val : results)
    {
      std::cout << "区段" << i << ": " << val << std::endl;
      ++i;
    }
  return std::accumulate(results.begin(), results.end(), val);       //累加结果容器并返回计算和
}

int main()
{
  std::vector<int> mi{};

  std::fill_n(std::insert_iterator<std::vector<int>>(mi, mi.begin()), 1000000, 10);
  for (const auto &val : mi)
    {
      std::cout << val << " | ";
    }
  std::cout << std::endl;
  std::cout << paraller_accumulate(mi.begin(), mi.end(), 9) << std::endl;
  return 0;
}
