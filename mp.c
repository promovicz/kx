//// Math primes
#include <stddef.h>
#include <limits.h>
#include <primesieve.h>
#include <k.h>
static K Par(K s, K e) {
  if(TK(s) != 'i' || TK(e) != 'i') return KE("Par_args");
  size_t rz;
  int *rv = primesieve_generate_primes(iK(s),iK(e),&rz,INT_PRIMES);
  if(rv == NULL) return KE("Par_error");
  K r = KI(rv,rz);
  primesieve_free(rv);
  return r;
}
static K Pnr(K s, K n) {
  if(TK(s) != 'i' || TK(n) != 'i') return KE("Pnr_args");
  size_t rz = iK(n);
  int *rv = primesieve_generate_n_primes(rz,iK(s),INT_PRIMES);
  if(rv == NULL) return KE("Pnr_error");
  K r = KI(rv,rz);
  primesieve_free(rv);
  return r;
}
static K pnr(K s, K n) {
  if(TK(s) != 'i' || TK(n) != 'i') return KE("pnr_args");
  uint64_t rn = primesieve_nth_prime(iK(n),iK(s));
  if(rn > INT_MAX) return KE("pnr_overflow");
  return Ki(rn);
}
static K pcr(K s, K e) {
  if(TK(s) != 'i' || TK(e) != 'i') return KE("pcr_args");
  uint64_t rn = primesieve_count_primes(iK(s),iK(e));
  if(rn > INT_MAX) return KE("pcr_overflow");
  return Ki(rn);
}
static K pc2r(K s, K e) {
  if(TK(s) != 'i' || TK(e) != 'i') return KE("pc2r_args");
  uint64_t rn = primesieve_count_twins(iK(s),iK(e));
  if(rn > INT_MAX) return KE("pc2r_overflow");
  return Ki(rn);
}
static K pc3r(K s, K e) {
  if(TK(s) != 'i' || TK(e) != 'i') return KE("pc3r_args");
  uint64_t rn = primesieve_count_triplets(iK(s),iK(e));
  if(rn > INT_MAX) return KE("pc3r_overflow");
  return Ki(rn);
}
static K pc4r(K s, K e) {
  if(TK(s) != 'i' || TK(e) != 'i') return KE("pc4r_args");
  uint64_t rn = primesieve_count_quadruplets(iK(s),iK(e));
  if(rn > INT_MAX) return KE("pc4r_overflow");
  return Ki(rn);
}
static K pc5r(K s, K e) {
  if(TK(s) != 'i' || TK(e) != 'i') return KE("pc5r_args");
  uint64_t rn = primesieve_count_quintuplets(iK(s),iK(e));
  if(rn > INT_MAX) return KE("pc5r_overflow");
  return Ki(rn);
}
static K pc6r(K s, K e) {
  if(TK(s) != 'i' || TK(e) != 'i') return KE("pc6r_args");
  uint64_t rn = primesieve_count_sextuplets(iK(s),iK(e));
  if(rn > INT_MAX) return KE("pc6r_overflow");
  return Ki(rn);
}
void kxinit_mp(void) {
  // ranged
  KR("mp.Par",Par,2);
  KR("mp.Pnr",Pnr,2);
  KR("mp.pnr",pnr,2);
  KR("mp.pcr",pcr,2);
  KR("mp.pc2r",pc2r,2);
  KR("mp.pc3r",pc3r,2);
  KR("mp.pc4r",pc4r,2);
  KR("mp.pc5r",pc5r,2);
  KR("mp.pc6r",pc6r,2);
  // convenience
  Kx("mp.Pa:mp.Par[0]");
  Kx("mp.Pn:mp.Pnr[0]");
  Kx("mp.pn:mp.pnr[0]");
  Kx("mp.pc:mp.pcr[0]");
  Kx("mp.pc2:mp.pc2r[0]");
  Kx("mp.pc3:mp.pc3r[0]");
  Kx("mp.pc4:mp.pc4r[0]");
  Kx("mp.pc5:mp.pc5r[0]");
  Kx("mp.pc6:mp.pc6r[0]");
}
