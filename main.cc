#include <cstdlib>
#include <iostream>
#include <omp.h>
#include <sstream>
#include <atomic>
#include <csignal>
#include <thread>
#include <future>

/*
 * 1 * n = n + 1
 * m * 1 = (m-1) * 2
 * m * n = (m - 1) * (m * (n - 1))
 */

using std::cout, std::endl;

static std::atomic_uint count{0};

auto op_star(const int m, const int n) -> int {

  count++;

  // cout << count << " op_star m = " << m << " n = " << n << "\n";

  if (m == 1) {
    return n + 1;
  }
  if (n == 1) {
    return std::async(op_star, m-1, n).get();
  }
    
  return std::async(op_star, m - 1, op_star(m, n - 1)).get();
  
}

void handler(int s) {
  cout << "Iteration count is " << count << endl;
}

int main(int ac, char ** __restrict__ av) {

  if (ac < 3) return EXIT_FAILURE;

  int a = atoi(av[1]);
  int b = atoi(av[2]);

  cout << "A,B: " << a << " " << b << endl;

  std::signal(SIGUSR1, handler);

  int result = 0;

  result = op_star(a, b);

  cout << result << endl;
  return 0;
}
