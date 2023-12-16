#include <algorithm>

namespace stats {

template<typename T=double, typename U>
T uniform_probability_function(const U& a, const U& b, const U& k)
{
   if(k < a || k > b) return 0;
   T x, y;
   x = a;
   y = b;
   if(x > y) std::swap(x, y);

   return T(1)/(y - x + T(1));
}

}