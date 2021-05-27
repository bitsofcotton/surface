#if !defined(_SURFACE_)

template <typename T> SimpleVector<T> stepk(const SimpleMatrix<T>& invarF, const SimpleMatrix<T>& implInvarF, const SimpleMatrix<T>& invarR, const SimpleMatrix<T>& implInvarR, const int& k, const SimpleVector<T>& inv) {
  std::vector<SimpleMatrix<T> > AinvarF;
  AinvarF.emplace_back(invarF);
  for(int i = 1; i < k; i ++)
    AinvarF.emplace_back(AinvarF[AinvarF.size() - 1] * AinvarF[AinvarF.size() - 1]);
  SimpleVector<T> last(invarF.cols());
  SimpleVector<T> regionv(invarR.cols());
  regionv.setVector(0, inv).setVector(inv.size(), implInvarR * inv);
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

