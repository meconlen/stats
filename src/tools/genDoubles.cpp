#include <iomanip>
#include <iostream>
#include <random>
#include <string>

int main(int argc, char *argv[])
{

   if(argc < 2) { 
      return -1;
   }
   std::string count_string{argv[1]};
   auto count = std::stoll(count_string);
   std::random_device rd{};
   std::mt19937 gen{rd()};
   std::normal_distribution<double> d{0.0, 1e2};
   for(auto i = 0; i < count; i++) {
      std::cout << std::setprecision (16) << d(gen) << (i == count-1 ? "" : ",") << std::endl;
   }
   return 0;
}