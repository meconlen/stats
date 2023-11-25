
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
   typename std::iterator_traits<It>::value_type s{0};
   std::vector<typename std::iterator_traits<It>::value_type> x(begin, end);
   // std::sort(x.begin(), x.end());
   std::sort(x.begin(), x.end(), [](const T& a, const T& b){ return abs(a) < abs(b); });
   return sum(x.begin(), x.end());
   return s;
}

template<typename It>
typename std::iterator_traits<It>::value_type kahan_sum(const It& begin, const It& end)
{
   typename std::iterator_traits<It>::value_type s{0};
   typename std::iterator_traits<It>::value_type c{0};
   for(auto iter = begin; iter < end; iter++) {
      typename std::iterator_traits<It>::value_type y = *iter - c;
      typename std::iterator_traits<It>::value_type t = s + y;
      c = (t - s) - y;
      s = t;
   }
   return s;
}

}