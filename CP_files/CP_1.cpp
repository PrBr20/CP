#include <bits/stdc++.h>
 
using namespace std;
 
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define Precision cout<<fixed<<setprecision(6);
#define gcd(a,b) __gcd(a,b)
#define ll long long
#define int ll
#define MAX 300005
#define getones __builtin_popcountll
 
const int N=4e5+5;

int a[N], b[N];

void solve() {
  string s;
  cin>>s;
  int n=s.size();
  
  int sz=0, prev=-1, c1=0, mns=2e6, mnf=2e6;
  for(int i=0;i<n;i++) {
    if(s[i]=='1') {
      // cout<<prev<<" "<<c1<<endl;
      if(prev==0 && mnf>=0) {
        cout<<"NO\n";
        return;
      }
      prev=1;
      c1=0;
      mns=0;
      mnf=2e6;
    }
    else if(s[i]=='0') {
      // cout<<prev<<" "<<mnf<<endl;
      if(sz<2 || (prev==1 && c1==0)) {
        cout<<"NO\n";
        return;
      }
      prev=0;
      c1=0;
      mns=0;
      mnf=2e6;
    }
    else if(s[i]=='+') {sz++; c1++; mns++; mnf=min(mnf, mns);}
    else {sz--; c1--; c1=max(0ll, c1); mns--; mnf=min(mnf, mns);}
  }
  cout<<"YES\n";
}
 
int32_t main() {
    FASTIO
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
      solve();
    }
}