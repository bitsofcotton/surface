#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include <assert.h>

#include "lieonn.hh"
typedef myfloat num_t;
#include "surface.hh"

int main(int argc, const char* argv[]) {
  std::vector<num_t> v;
  std::string s;
  while(std::getline(std::cin, s, '\n')) {
    std::stringstream ins(s);
    v.emplace_back(num_t(0));
    ins >> v[v.size() - 1];
  }
  assert(v.size() == 4 * 4 + 4 * 4 + 1);
  SimpleMatrix<num_t> invA(4, 4);
  SimpleMatrix<num_t> invR(4, 4);
  for(int i = 0; i < invA.rows(); i ++)
    for(int j = 0; j < invA.cols(); j ++)
      invA(i, j) = v[i * invA.cols() + j];
  for(int i = 0; i < invR.rows(); i ++)
    for(int j = 0; j < invR.cols(); j ++)
      invR(i, j) = v[i * invR.cols() + j + invA.rows() * invA.cols()];
  Surface<num_t> sim;
  std::cout << sim.stepk(invA, invR, int(v[v.size() - 1])) << std::endl;
  return 0;
}

