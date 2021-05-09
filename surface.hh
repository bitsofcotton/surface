#if !defined(_SURFACE_)

template <typename T> class Surface {
public:
  typedef SimpleVector<T> Vec;
  typedef SimpleMatrix<T> Mat;
  inline Surface();
  inline ~Surface();
  // Mat prepInvariant(/* equation */);
  // Mat prepRegionInvariant(/* region */);
  Mat stepk(const Mat& invariants, const Mat& regions, const int& k) const;
};

template <typename T> inline Surface<T>::Surface() {
  ;
}

template <typename T> inline Surface<T>::~Surface() {
  ;
}

template <typename T> typename Surface<T>::Mat Surface<T>::stepk(const Mat& invariants, const Mat& regions, const int& k) const {
  assert(invariants.rows() == 4 && invariants.cols() == 4 &&
         regions.rows() == 4 && regions.cols() == 4 &&
         0 < k);
  std::vector<Mat> Akk;
  Akk.emplace_back(invariants);
  Mat Ak(invariants.rows(), invariants.cols());
  for(int i = 0; i < Ak.rows(); i ++)
    for(int j = 0; j < Ak.cols(); j ++)
      Ak(i, j) = T(i == j ? 1 : 0);
  for(int kk = k, i = 0; kk && 0 <= i; kk >>= 1, i ++) {
    if(kk & 1) Ak *= Akk[i];
    Akk.emplace_back(Akk[Akk.size() - 1] * Akk[Akk.size() - 1]);
  }
  return Ak * regions;
}

#define _SURFACE_
#endif

