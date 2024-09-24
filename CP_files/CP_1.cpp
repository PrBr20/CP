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

bool check(int m, int n) {
  int k=0;
  for(int i=0;i<n;i++) {
    if(a[i]>m) k+=a[i]-m;
    if(a[i]<m) {
      k-=min(m-a[i], k);
    }
  }
  // cout<<"k "<<k<<endl;
  if(k==0) return true;
  return false;
}

bool check2(int m, int n) {
  int k=0;
  for(int i=n-1;i>=0;i--) {
    if(a[i]>m) k-=min(a[i]-m, k);
    if(a[i]<m) {
      k+=m-a[i];
    }
  }
  // cout<<"k "<<k<<endl;
  if(k==0) return true;
  return false;
}
 
 
void solve() {
  int n;
  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];
    
  int l=1, r=1e12, mx=r;
  while(l<=r) {
    int m=(l+r)/2;
    // cout<<m<<endl;
    if(check(m, n)) {
      mx=m;
      r=m-1;
    }
    else l=m+1;
  }
  
  // cout<<mx<<endl;
  
  int k=0;
  for(int i=0;i<n;i++) {
    if(a[i]>mx) {
      k+=a[i]-mx;
      a[i]=mx;
    }
    else if(a[i]<mx) {
      int x=min(mx-a[i], k);
      k-=x;
      a[i]+=x;
    }
    // cout<<i<<" "<<k<<endl;
  }
  
  l=1, r=1e12;
  int mn=-1;
  while(l<=r) {
    int m=(l+r)/2;
    // cout<<m<<endl;
    if(check2(m, n)) {
      mn=m;
      l=m+1;
    }
    else r=m-1;
  }
  
  // cout<<mn<<endl;
  
  // for(int i=0;i<n;i++) cout<<a[i]<<" ";
  // cout<<endl;
  
  cout<<mx-mn<<endl;
  
}
  
 
 
int32_t main() {
    FASTIO
    int t=1;
    cin>>t;
    while(t--){
      solve();
    }
}