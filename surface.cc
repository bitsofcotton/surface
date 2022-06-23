#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include <assert.h>

#include "lieonn.hh"
typedef myfloat num_t;
#include "surface.hh"

int main(int argc, const char* argv[]) {
  std::string s;
  assert(3 < argc);
  const auto m(std::atoi(argv[1]));
  const auto n(std::atoi(argv[2]));
  const auto r(std::atoi(argv[3]));
  SimpleMatrix<num_t> Ascaled(m, m);
  SimpleMatrix<num_t> B(m, n);
  SimpleVector<num_t> x(n);
  int i = 0;
  int j = 0;
  while(std::getline(std::cin, s, '\n')) {
    std::stringstream ins(s);
    ins >> Ascaled(i, j ++);
    if(Ascaled.cols() <= j) { i ++; j ^= j; }
    if(Ascaled.rows() <= i) break;
  }
  i = j = 0;
  while(std::getline(std::cin, s, '\n')) {
    std::stringstream ins(s);
    ins >> B(i, j ++);
    if(B.cols() <= j) { i ++; j ^= j; }
    if(B.rows() <= i) break;
  }
  i ^= i;
  while(std::getline(std::cin, s, '\n')) {
    std::stringstream ins(s);
    ins >> x[i ++];
    if(x.size() <= i) break;
  }
  std::cout << next2k<num_t>(Ascaled, B, x, r) << std::endl;
  return 0;
}

