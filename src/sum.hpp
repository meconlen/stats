
#include <cmath>
#include <cstdlib>

namespace stats {


template<typename It>
typename std::iterator_traits<It>::value_type sum(const It& begin, const It& end) 
{
   typename std::iterator_traits<It>::value_type s{0};
   for(auto iter = begin; iter < end; iter++) {
      s += *iter;
   }
   return s;
}

// This will fail if we don't sort
// This will also fail if we don't sort by magnitude

template<typename It>
typename std::iterator_traits<It>::value_type sorted_sum(const It& begin, const It& end)
{
   using T = typename std::iterator_traits<It>::value_type;
   T s{0};
   std::vector<typename std::iterator_traits<It>::value_type> x(begin, end);
   // std::sort(x.begin(), x.end());
   std::sort(x.begin(), x.end(), [](const T& a, const T& b){ return std::abs(a) < std::abs(b); });
   return sum(x.begin(), x.end());
   return s;
}

template<typename It>
typename std::iterator_traits<It>::value_type kahan_sum(const It& begin, const It& end)
{
   using T = typename std::iterator_traits<It>::value_type;
   T s{0};
   T c{0};
   for(auto iter = begin; iter != end; iter++) {
      T y = *iter - c;
      T t = s + y;
      c = (t - s) - y;
      s = t;
   }
   return s;
}

template<typename It>
typename std::iterator_traits<It>::value_type kbn_sum(const It& begin, const It& end) 
{
   using T = typename std::iterator_traits<It>::value_type;
   T s{0};
   T c{0};
   for(auto iter = begin; iter != end; iter++) {
      T t = s + *iter;
      if(std::abs(s) >= std::abs(*iter)) {
         c += (s - t) + *iter;
      } else {
         c += (*iter - t) + s;
      }
      s = t;
   }
   return s + c;
}

template<typename It>
typename std::iterator_traits<It>::value_type kbk_sum(const It& begin, const It& end)
{
   using T = typename std::iterator_traits<It>::value_type;
   T s{0};
   T cs{0};
   T ccs{0};
   T c{0};
   T cc{0};

   for(auto iter = begin; iter != end; iter++) {
      T t = s + *iter;
      if(std::abs(s) >= std::abs(*iter)) {
         c = (s - t) + *iter;
      } else {
         c = (*iter - t) + s;
      }
      s = t;
      t = cs + c;
      if(std::abs(cs) >= std::abs(c)) {
         cc = (cs - t) + c;
      } else {
         cc = (c - t) + cs;
      }
      cs = t;
      ccs = ccs+cc;
   }
   return s + cs + ccs;
}

}