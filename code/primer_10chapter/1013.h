#ifndef _a1013_H
#define _a1013_H

#include <vector>
template <typename _InputIterator, typename _pred>
_InputIterator partition(_InputIterator beg, _InputIterator end, _pred op)
{
  _InputIterator flase_p = beg;
  for (; beg != end; ++beg)
    {
      if (!op(*beg) && flase_p != beg && op(*flase_p))
        {       //若谓词条件为假
          flase_p = beg;
        }
      else if (op(*beg) && flase_p != beg && !op(*flase_p))
        {
          using std::swap;
          swap(*beg, *flase_p);
          flase_p = beg;
        }
    }
  return flase_p;
}
#endif // 1013_H
