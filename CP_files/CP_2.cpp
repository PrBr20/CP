#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 998244353
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define Precision cout<<fixed<<setprecision(2);
#define gcd(a,b) __gcd(a,b)
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;


void printarr(int a[], int n) {
  for(int i=0;i<n;i++) cout<<a[i]<<" ";
}

#define MAX 200005

int a[MAX], dp[MAX][2];

int main() {
  set<int> s;
  s.insert({2,3,4,3,5});
  cout<<s.size()<<endl;
  s.erase(6);
  cout<<s.size()<<endl;
}