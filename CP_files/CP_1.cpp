#include <bits/stdc++.h>
 
using namespace std;
 
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define Precision cout<<fixed<<setprecision(2);
#define gcd(a,b) __gcd(a,b)
#define ll long long
#define int ll
#define MAX 300005
#define getones __builtin_popcountll
 
const int N=2e5+5, M=998244353;
 
int a[N];

void solve() {
  int n;
  cin>>n;
  
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=1;i<n;i+=2) cout<<a[i]<<" ";
  for(int i=0;i<n;i+=2) cout<<a[i]<<" ";
  cout<<endl;
  
}
  
 
 
int32_t main() {
    FASTIO
    int t=1;
    cin>>t;
    while(t--){
      solve();
    }
}