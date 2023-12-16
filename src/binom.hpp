#include <cmath>

namespace stats {

// This assumees  that n, k are integer types

template<typename T>
T BinomialCoefficient(const T& n, const T& k)
{
   // we note that (n, k) = (n-1, k-1) * (n/k)
   // note also that k divides (n-1, k-1) * n since (n, k) is an integer. 

   if(k > n) {
      return 0;
   }
   if(k < 0) {
      return 0;
   }
   // we can start with (n-k, 0) = 1
   // but we know the next value will be 
   // (n-k+1)/1 = (n-k+1)
   T result = n-k+1;
   for(T i=1; i < k; i++) {
      // result = (n-k+i, i)
      // we compute (n-k+i+1, i+1)
      result = ( result * (n-k+i+1)) / (i+1);
   }
   return result;

}

template<typename T, typename U>
U BinomialProbabilityFunction(T n, T k, U p)
{
   return U(BinomialCoefficient(n, k)) * std::pow(p, k) * std::pow((1-p), (n-k));
}

}