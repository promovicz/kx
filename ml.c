//// Math library
#include <math.h>
#include <kx.h>

#define WMc(_n,_c)				\
  static K kx_##_n(K x) {			\
    char xt = TK(x);				\
    if(xt == 'f') {				\
      return Kf(_n(fK(x)));			\
    } else if(xt == 'i') {			\
      return Kf(_n(iK(x)));			\
    } else if (xt == 'F') {			\
      size_t xn = NK(x);			\
      int i;					\
      double *rv = alloca(xn*sizeof(double));	\
      const double *xv = (double*)dK(x);	\
      for(i=0;i<xn;i++) {			\
        rv[i] = _c(xv[i]);			\
      }						\
      return KF(rv,xn);				\
    } else if (xt == 'I') {			\
      size_t xn = NK(x);			\
      int i;					\
      double *rv = alloca(xn*sizeof(double));	\
      int *xv = alloca(xn*sizeof(int));		\
      IK(xv,x);					\
      for(i=0;i<xn;i++) {			\
        rv[i] = _c(xv[i]);			\
      }						\
      return KF(rv,xn);				\
    } else {					\
      return KE("kx_inval");			\
    }						\
  }
#define WM(_n) WMc(_n,_n)

WM(floor);WM(ceil);WM(round);WM(trunc);
WM(sqrt);WM(cbrt);//WD(pow);WD(hypot);
WM(exp);WM(expm1);WM(exp2);//WM(exp10);
WM(log);WM(log1p);WM(log2);//WM(log10);
WM(cos);WM(acos);WM(cosh);WM(acosh);
WM(sin);WM(asin);WM(sinh);WM(asinh);
WM(tan);WM(atan);WM(tanh);WM(atanh);

#define RM(_n) KR("ml."#_n,kx_##_n,1)
#define RD(_n) KR("ml."#_n,kx_##_n,2)

void kxinit_ml(void) {
  RM(floor);RM(ceil);RM(round);RM(trunc);
  RM(sqrt);RM(cbrt);//RD(pow);
  RM(exp);RM(expm1);RM(exp2);//RM(exp10);
  RM(log);RM(log1p);RM(log2);//RM(log10);
  RM(cos);RM(acos);RM(cosh);RM(acosh);
  RM(sin);RM(asin);RM(sinh);RM(asinh);
  RM(tan);RM(atan);RM(tanh);RM(atanh);
}
