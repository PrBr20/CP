#include <bits/stdc++.h>

using namespace std;

// #define MOD 998244353
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

#define MAX 300005


int main() {
    int t;
    cin>>t;
    while(t--){
      ll n,m;
      cin>>n>>m;
      
      ll ans=0;
      for(int i=1;i<=m;i++) {
        for(int j=1;j*i<=n;j++) {
          ll b=i, a=i*j;
          // cout<<gcd()
          if((a+b)%(b*b)==0) ans++;
        }
      }
      
      cout<<ans<<endl;
    }

}
