#include <vector>

#include "sum.hpp"

#include <benchmark/benchmark.h>

static void BM_EMPTY_SUM(benchmark::State& state) {
   std::vector<int> x{};
   int s;
   for (auto _ : state)
      benchmark::DoNotOptimize(s = stats::sum(x.begin(), x.end()));
}

// Register the function as a benchmark
BENCHMARK(BM_EMPTY_SUM)->MinTime(5);

// Define another benchmark
static void BM_SMALL_SUM(benchmark::State& state) {
   std::vector<int> x{1, 2, 3};
   int s;
   for (auto _ : state)
      benchmark::DoNotOptimize(s = stats::sum(x.begin(), x.end()));
}

BENCHMARK(BM_SMALL_SUM)->MinTime(5);

static void BM_LARGE_SUM(benchmark::State& state) {
   std::vector<double> x{
      #include "test_data/1000000_doubles.txt"
   };
   double s;
   for (auto _ : state)
      benchmark::DoNotOptimize(s = stats::sum(x.begin(), x.end()));  
}

BENCHMARK(BM_LARGE_SUM)->MinTime(5);


static void BM_LARGE_SORTED_SUM(benchmark::State& state) {
   std::vector<double> x{
      #include "test_data/1000000_doubles.txt"
   };
   double s;
   for (auto _ : state)
      benchmark::DoNotOptimize(s = stats::sorted_sum(x.begin(), x.end()));    
}
BENCHMARK(BM_LARGE_SORTED_SUM)->MinTime(5);


static void BM_LARGE_KAHAN_SUM(benchmark::State& state) {
   std::vector<double> x{
      #include "test_data/1000000_doubles.txt"
   };
   double s;
   for (auto _ : state)
      benchmark::DoNotOptimize(s = stats::kahan_sum(x.begin(), x.end()));    
}

BENCHMARK(BM_LARGE_KAHAN_SUM)->MinTime(5);




BENCHMARK_MAIN();
