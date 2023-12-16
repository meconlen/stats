#include <cstdint>
#include <iostream>
#include <vector>

#include <gtest/gtest.h>

#include "sum.hpp"
#include "binom.hpp"

TEST(sum, 0)
{
   std::vector<int> x{};
   int s = stats::sum(std::begin(x), std::end(x));
   EXPECT_EQ(s, 0);
}

TEST(sum, 1)
{
   std::vector<int> x{1, 2, 3};
   int s = stats::sum(std::begin(x), std::end(x));
   EXPECT_EQ(s, 6);
}

TEST(sum, 2)
{
   std::vector<double> x{1e-9, 1e9, 1e-9, -1e9};
   double s = stats::sum(std::begin(x), std::end(x));
   // this isn't actually the right result but it's the expected result for the algorithm
   EXPECT_EQ(s, 0);
}

TEST(sum, 3)
{
   std::vector<float> x(100000, 1e0);
   std::vector<float> y{1e8};
   y.insert(std::end(y), std::begin(x), std::end(x));
   float s = stats::sum(std::begin(y), std::end(y));
   // not the right answer but the expected answer
   EXPECT_EQ(s, 1e8);  
}

TEST(sum, kahan_example)
{
   std::vector<float> x{1000000.0, 3.14159265, 2.7182818284};
   float s = stats::sum(std::begin(x), std::end(x));
   // this isn't correct but is expected
   EXPECT_EQ(s, 1000005.8125);
}

TEST(sorted_sum, 0)
{
   std::vector<int> x{};
   int s = stats::sorted_sum(std::begin(x), std::end(x));
   EXPECT_EQ(s, 0);
}

TEST(sorted_sum, 1)
{
   std::vector<int> x{1, 2, 3};
   int s = stats::sorted_sum(std::begin(x), std::end(x));
   EXPECT_EQ(s, 6);
}

TEST(sorted_sum, 2)
{
   std::vector<double> x{1e-9, 1e9, 1e-9, -1e9};
   double s = stats::sorted_sum(std::begin(x), std::end(x));
   // this isn't actually the right result but it's the expected result for the algorithm
   EXPECT_EQ(s, 0);
}

TEST(sorted_sum, 3)
{
   std::vector<float> x(100000, 1e0);
   std::vector<float> y{1e8, -1e8};
   y.insert(std::end(y), std::begin(x), std::end(x));
   float s = stats::sorted_sum(std::begin(y), std::end(y));
   // not the right answer but the expected answer
   EXPECT_EQ(s, 1e5);  
}


TEST(sorted_sum, kahan_example)
{
   std::vector<float> x{1000000.0, 3.14159265, 2.7182818284};
   float s = stats::sorted_sum(std::begin(x), std::end(x));
   // this isn't correct but is expected
   EXPECT_EQ(s, 1000005.875);
}

TEST(kahan_sum, 1)
{
   std::vector<int> x{1, 2, 3};
   int s = stats::kahan_sum(std::begin(x), std::end(x));
   EXPECT_EQ(s, 6);
}

TEST(kahan_sum, 2)
{
   std::vector<double> x{1e-9, 1e9, 1e-9, -1e9};
   double s = stats::kahan_sum(std::begin(x), std::end(x));
   // this isn't actually the right result but it's the expected result for the algorithm
   EXPECT_EQ(s, 0);
}

TEST(kahan_sum, 3)
{
   std::vector<float> x(100000, 1e0);
   std::vector<float> y{1e8};
   y.insert(std::end(y), std::begin(x), std::end(x));
   float s = stats::kahan_sum(std::begin(y), std::end(y));
   // not the right answer but the expected answer
   EXPECT_EQ(s, 1.001e8);  
}

TEST(kahan_sum, kahan_example)
{
   std::vector<float> x{1000000.0, 3.14159265, 2.7182818284};
   float s = stats::kahan_sum(std::begin(x), std::end(x));
   // this isn't correct but is expected
   EXPECT_EQ(s, 1000005.875);
}

TEST(kahan_sum, kbn_example)
{
   std::vector<double> x{1.0, 1e100, 1.0, -1e100};
   double s = stats::kahan_sum(std::begin(x), std::end(x));
   // Expected but incorrect 
   EXPECT_EQ(s, 0.0);
}

TEST(kbn_sum, 1)
{
   std::vector<int> x{1, 2, 3};
   int s = stats::kbn_sum(std::begin(x), std::end(x));
   EXPECT_EQ(s, 6);
}

// This test is an improvement of kbn over kahan
TEST(kbn_sum, 2)
{
   std::vector<double> x{1e-9, 1e9, 1e-9, -1e9};
   double s = stats::kbn_sum(std::begin(x), std::end(x));
   EXPECT_EQ(s, 2e-9);
}

TEST(kbn_sum, 3)
{
   std::vector<float> x(100000, 1e0);
   std::vector<float> y{1e8};
   y.insert(std::end(y), std::begin(x), std::end(x));
   float s = stats::kbn_sum(std::begin(y), std::end(y));
   // not the right answer but the expected answer
   EXPECT_EQ(s, 1.001e8);  
}

TEST(kbn_sum, kahan_example)
{
   std::vector<float> x{1000000.0, 3.14159265, 2.7182818284};
   float s = stats::kbn_sum(std::begin(x), std::end(x));
   // this isn't correct but is expected
   EXPECT_EQ(s, 1000005.875);
}

// This test is an improvement of kbn over kahan

TEST(kbn_sum, kbn_example)
{
   std::vector<double> x{1.0, 1e100, 1.0, -1e100};
   double s = stats::kbn_sum(std::begin(x), std::end(x));
   EXPECT_EQ(s, 2.0);
}



TEST(kbk_sum, 1)
{
   std::vector<int> x{1, 2, 3};
   int s = stats::kbk_sum(std::begin(x), std::end(x));
   EXPECT_EQ(s, 6);
}

// This test is an improvement of kbn over kahan
TEST(kbk_sum, 2)
{
   std::vector<double> x{1e-9, 1e9, 1e-9, -1e9};
   double s = stats::kbk_sum(std::begin(x), std::end(x));
   EXPECT_EQ(s, 2e-9);
}

TEST(kbk_sum, 3)
{
   std::vector<float> x(100000, 1e0);
   std::vector<float> y{1e8};
   y.insert(std::end(y), std::begin(x), std::end(x));
   float s = stats::kbk_sum(std::begin(y), std::end(y));
   // not the right answer but the expected answer
   EXPECT_EQ(s, 1.001e8);  
}

TEST(kbk_sum, kahan_example)
{
   std::vector<float> x{1000000.0, 3.14159265, 2.7182818284};
   float s = stats::kbk_sum(std::begin(x), std::end(x));
   // this isn't correct but is expected
   EXPECT_EQ(s, 1000005.875);
}

// This test is an improvement of kbn over kahan

TEST(kbk_sum, kbn_example)
{
   std::vector<double> x{1.0, 1e100, 1.0, -1e100};
   double s = stats::kbk_sum(std::begin(x), std::end(x));
   EXPECT_EQ(s, 2.0);
}

TEST(BinomialCoefficient, 1)
{
   uint64_t r = stats::BinomialCoefficient(uint64_t(3), uint64_t(2));
   EXPECT_EQ(r,3);
}

TEST(BinomialCoefficient, 2)
{
   uint64_t r = stats::BinomialCoefficient(uint64_t(30), uint64_t(20));
   EXPECT_EQ(r,30045015);
}

TEST(BinomialCoefficient, 3)
{
   int64_t r = stats::BinomialCoefficient(int64_t(30), int64_t(0));
   EXPECT_EQ(r,1);
}

TEST(BinomialCoefficient, 4)
{
   int64_t r = stats::BinomialCoefficient(int64_t(30), int64_t(-1));
   EXPECT_EQ(r,0);
}

TEST(BinomialCoefficient, 5)
{
   int64_t r = stats::BinomialCoefficient(int64_t(30), int64_t(40));
   EXPECT_EQ(r,0);
}


TEST(BinomialProbabilityFunction, 1)
{
   double r = stats::BinomialProbabilityFunction(uint64_t(30), uint64_t(20), double(0.1));
   EXPECT_NEAR(r, 1.0476048962981117e-13, 1e-19);
}

int main(int argc, char** argv)
{
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();	
	return 0;
}