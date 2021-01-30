#include <benchmark/benchmark.h>

#include <operation.h>

namespace op = operations;

void sum_int32_t(benchmark::State& state) {
  std::int32_t a = 5;
  std::int32_t b = 5;

  for (auto _ : state) {
    benchmark::DoNotOptimize(op::sum(a,b));
  }
}
void sub_int32_t(benchmark::State& state) {
  std::int32_t a = 5;
  std::int32_t b = 5;

  for (auto _ : state) {
    benchmark::DoNotOptimize(op::sub(a,b));
  }
}
void mul_int32_t(benchmark::State& state) {
  std::int32_t a = 5;
  std::int32_t b = 5;

  for (auto _ : state) {
    benchmark::DoNotOptimize(op::mul(a,b));
  }
}
void div_int32_t(benchmark::State& state) {
  std::int32_t a = 5;
  std::int32_t b = 5;

  for (auto _ : state) {
    benchmark::DoNotOptimize(op::div(a,b));
  }
}


BENCHMARK(sum_int32_t);
BENCHMARK(sub_int32_t);
BENCHMARK(mul_int32_t);
BENCHMARK(div_int32_t);

BENCHMARK_MAIN();