#if !defined(_SURFACE_)

template <typename T> SimpleVector<T> preparePt(const SimpleMatrix<T>& implInvarF, const SimpleMatrix<T>& invarR, const SimpleMatrix<T>& implInvarR, const SimpleVector<T>& in) {
  SimpleVector<T> last(invarR.rows() + implInvarF.rows());
  SimpleVector<T> regionv(invarR.cols());
  regionv.setVector(0, in).setVector(in.size(), implInvarR * in);
  auto work(regionv);
  for(int i = 0; i < work.size(); i ++)
    work[i] = tan(work[i]);
  last.setVector(0, work = invarR * work);
  for(int i = 0; i < work.size(); i ++)
    work[i] = atan(work[i]);
  work = implInvarF * work;
  for(int i = 0; i < work.size(); i ++)
    work[i] = tan(work[i]);
  return last.setVector(invarR.rows(), work);
}

#define _SURFACE_
#endif

