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
 
const int N=1e5+9, M=998244353;

int a[N], tripls[N];
vector<int> divi[N];
 
void solve() {
  int n;
  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];
  sort(a,a+n);
  
  for(int i=0;i<n;i++) {
    for(int j=1;j*j<=a[i];j++) {
      if(a[i]%j==0) {
        divi[j].pb(i);
        if(j != a[i]/j) divi[a[i]/j].pb(i); 
      }
    }
  }
  
  for(int i=N-1;i>=1;i--) {
    for(int j=0;j<divi[i].size();j++) {
      int l=j, r=n-1-divi[i][j];
      tripls[i]+=l*r;
    }
    for(int j=2*i;j<N;j+=i) tripls[i]-=tripls[j];
  }
  
  int ans=0;
  for(int i=1;i<N;i++) ans+=tripls[i]*i;
  cout<<ans<<endl;

  for(int i=0;i<N;i++) {
    tripls[i]=0;
    divi[i].clear();
  }
  
}
  
 
 
int32_t main() {
    FASTIO
    int t=1;
    cin>>t;
    while(t--){
      solve();
    }
}