#if !defined(_SURFACE_)

template <typename T> SimpleVector<T> next2k(const SimpleMatrix<T>& Ascaled, const SimpleMatrix<T>& B, const SimpleVector<T>& in, const int& n = 1) {
  auto A(Ascaled);
  for(int i = 1; i < n; i ++) A *= A;
  auto res(A * (B * in));
  for(int i = 0; i < res.size(); i ++) res[i] = tan(res[i]);
  return std::move(res);
}

#define _SURFACE_
#endif

