//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,sse4a,avx,avx2,popcnt,tune=native")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <climits>
using namespace std;

#ifdef LOCAL
  #define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
  #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
  return (ull)rng() % B;
}

#define mp make_pair
#define all(x) (x).begin(),(x).end()

clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

ll floor_div(ll x, ll y) {
  assert(y != 0);
  if (y < 0) {
    y = -y;
    x = -x;
  }
  if (x >= 0) return x / y;
  return (x + 1) / y - 1;
}
ll ceil_div(ll x, ll y) {
  assert(y != 0);
  if (y < 0) {
    y = -y;
    x = -x;
  }
  if (x <= 0) return x / y;
  return (x - 1) / y + 1;
}


template<typename T> struct Fenwick {
  vector<T> a;
  int n;

  Fenwick() : a(), n(0) {}
  Fenwick(int _n) {
    n = _n;
    a = vector<T>(n, T());
  }

  void clear() {
    a = vector<T>(n, T());
  }

  void add(int p, T x) {
    for(; p < n; p |= p + 1)
      a[p] += x;
  }
  T get(int r) {
    if (r < 0) return T();
    r = min(r, n - 1);
    T res = T();
    for(; r >= 0; r = (r & (r + 1)) - 1)
      res += a[r];
    return res;
  }
  T getSum(int l, int r) {
    return get(r - 1) - get(l - 1);
  }
};

const int N = 500500;
vector<int> g[N];
int n, m;
int t[N][2];
int a[N][2];
int T;

void dfs(int v) {
  t[v][0] = T++;
  for (int u : g[v])
    dfs(u);
  t[v][1] = T;
}

void solve() {
  scanf("%d", &m);
  for (int i = 0; i <= m; i++)
    g[i].clear();
  n = 1;
  for (int i = 0; i < m; i++) {
    int x, v;
    scanf("%d%d", &x, &v);
    v--;
    if (x == 1) {
      a[i][0] = -1;
      a[i][1] = n;
      g[v].push_back(n++);
    } else {
      a[i][0] = v;
      scanf("%d", &a[i][1]);
    }
  }
  T = 0;
  dfs(0);
  // for(int i=0;i<10;i++) cout<<t[i][0]<<" ";
  //   cout<<endl;
  // for(int i=0;i<10;i++) cout<<t[i][1]<<" ";
  //   cout<<endl;
  Fenwick<ll> fenv(T);
  for (int i = 0; i < m; i++) {
    if (a[i][0] == -1) {
      int v = a[i][1];
      int p = t[v][0];
      ll x = fenv.get(p);
      fenv.add(t[v][0], -x);
      fenv.add(t[v][1], x);
    } else {
      int v = a[i][0];
      fenv.add(t[v][0], a[i][1]);
      fenv.add(t[v][1], -a[i][1]);
    }
  }
  for (int v = 0; v < n; v++)
    printf("%lld ", fenv.get(t[v][0]));
  printf("\n");
}

int main() {
  startTime = clock();
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    eprintf("--- Case #%d start ---\n", i);
    //printf("Case #%d: ", i);

    solve();

    //printf("%lld\n", (ll)solve());

    /*
    if (solve()) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
    */

    eprintf("--- Case #%d end ---\n", i);
    eprintf("time = %.5lf\n", getCurrentTime());
    eprintf("++++++++++++++++++++\n");
  }


  return 0;
}
