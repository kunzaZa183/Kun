#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// using Int = long long;

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T>
ostream &operator<<(ostream &os, const vector<T> &as)
{
  const int sz = as.size();
  os << "[";
  for (int i = 0; i < sz; ++i)
  {
    if (i >= 256)
    {
      os << ", ...";
      break;
    }
    if (i > 0)
    {
      os << ", ";
    }
    os << as[i];
  }
  return os << "]";
}
template <class T>
void pv(T a, T b)
{
  for (T i = a; i != b; ++i)
    cerr << *i << " ";
  cerr << endl;
}
template <class T>
bool chmin(T &t, const T &f)
{
  if (t > f)
  {
    t = f;
    return true;
  }
  return false;
}
template <class T>
bool chmax(T &t, const T &f)
{
  if (t < f)
  {
    t = f;
    return true;
  }
  return false;
}

#ifndef LIBRA_OTHER_INT128_H_
#define LIBRA_OTHER_INT128_H_

#include <stdio.h>
#include <iostream>

constexpr unsigned __int128 toUInt128(const char *s)
{
  unsigned __int128 x = 0;
  for (; *s; ++s)
    x = x * 10 + (*s - '0');
  return x;
}
constexpr __int128 toInt128(const char *s)
{
  if (*s == '-')
    return -toInt128(s + 1);
  __int128 x = 0;
  for (; *s; ++s)
    x = x * 10 + (*s - '0');
  return x;
}
unsigned __int128 inUInt128()
{
  static char buf[41];
  scanf("%s", buf);
  return toUInt128(buf);
}
__int128 inInt128()
{
  static char buf[41];
  scanf("%s", buf);
  return toInt128(buf);
}

void out(unsigned __int128 x)
{
  static char buf[41];
  int len = 0;
  do
  {
    buf[len++] = '0' + static_cast<int>(x % 10);
  } while (x /= 10);
  for (int i = len; --i >= 0;)
    putchar(buf[i]);
}
void out(__int128 x)
{
  if (x < 0)
  {
    putchar('-');
    out(-static_cast<unsigned __int128>(x));
  }
  else
  {
    out(static_cast<unsigned __int128>(x));
  }
}
std::ostream &operator<<(std::ostream &os, unsigned __int128 x)
{
  static char buf[41];
  int len = 0;
  do
  {
    buf[len++] = '0' + static_cast<int>(x % 10);
  } while (x /= 10);
  for (int i = len; --i >= 0;)
    os << buf[i];
  return os;
}
std::ostream &operator<<(std::ostream &os, __int128 x)
{
  if (x < 0)
  {
    os << '-' << -static_cast<unsigned __int128>(x);
  }
  else
  {
    os << static_cast<unsigned __int128>(x);
  }
  return os;
}

#endif // LIBRA_OTHER_INT128_H_

using Int = __int128;

// floor(a / b)
Int divFloor(Int a, Int b)
{
  return a / b - (((a ^ b) < 0 && a % b != 0) ? 1 : 0);
}

// ceil(a / b)
Int divCeil(Int a, Int b)
{
  return a / b + (((a ^ b) > 0 && a % b != 0) ? 1 : 0);
}

// a x + b y = (+/-) gcd(a, b)
//   (a, 0): g = a, x = 1, y = 0
//   (0, b), (b, b), (-b, b) (b != 0): g = b, x = 0, y = 1
//   otherwise: 2 |x| <= |b|, 2 |y| <= |a|
// S: signed integer
template <class S>
S gojo(S a, S b, S &x, S &y)
{
  if (b != 0)
  {
    const S g = gojo(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
  }
  else
  {
    x = 1;
    y = 0;
    return a;
  }
}

int main()
{
  long long N_, A_, B_, C_, X_;
  freopen("input.txt", "r", stdin);
  freopen("correctoutput.txt", "w", stdout);
  for (; ~scanf("%lld%lld%lld%lld%lld", &N_, &A_, &B_, &C_, &X_);)
  {
    const Int N = N_;
    const Int A = A_;
    const Int B = B_;
    const Int C = C_;
    const Int X = X_;

    Int p, q;
    const Int g = gojo(B, C, p, q);

    Int ans = 0;
    for (Int i = 1; i <= N; ++i)
    {
      const Int x = X - A * i;
      if (x % g == 0)
      {
        const Int p0 = (x / g) * p;
        const Int q0 = (x / g) * q;
        /*
          1 <= p0 - (C/g) t <= N
          1 <= q0 + (B/g) t <= N
        */
        const Int lb = max(divCeil(-(N - p0), C / g), divCeil(1 - q0, B / g));
        const Int ub = min(divFloor(-(1 - p0), C / g), divFloor(N - q0, B / g));
        if (lb <= ub)
        {
          ans += (ub - lb + 1);
        }
      }
    }
    out(ans);
    puts("");
  }
  return 0;
}
