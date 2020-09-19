// Type your code here, or load an example.
#include <iostream>
#include <functional>
#include <chrono>

class ConstExprDemo {
 public:
  const char* GetConstCharStr() {
      return const_char_str_;
  }

  constexpr const char* GetConstExprStr() {
      return const_expr_str_;
  }

  std::string GetConstStr() {
      return const_std_str_;
  }

 private:
  static const std::string const_std_str_;
  static const char const_char_str_[];
  static constexpr char const_expr_str_[] = "expstr";
};

const std::string ConstExprDemo::const_std_str_ = "stdstr";
const char ConstExprDemo::const_char_str_[] = "chastr";
constexpr char ConstExprDemo::const_expr_str_[];

void measure_run_time(std::function<void()> callable) {
  auto start_time{std::chrono::steady_clock::now()};
  callable();
  auto end_time{std::chrono::steady_clock::now()};
  std::chrono::duration<double> run_time = end_time - start_time;
  std::cout << run_time.count() << '\n';
}


int main() {
  ConstExprDemo const_expr_demo;
  measure_run_time([&const_expr_demo]() { std::cout << const_expr_demo.GetConstExprStr() << '\n';});
  measure_run_time([&const_expr_demo]() { std::cout << const_expr_demo.GetConstCharStr() << '\n';});
  measure_run_time([&const_expr_demo]() { std::cout << const_expr_demo.GetConstStr() << '\n';});
  return 0;
}
