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

void printvec(vector<int>& v) {
  for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
  cout<<endl;
}
 
#define MAX 200005

int a[MAX], dp[MAX][2];

int main() {  
    int t;
    cin>>t;
    while(t--){
      int n, w, f;
      cin>>n>>w>>f;
      
      for(int i=1;i<=n;i++) cin>>a[i];
      
      for(int i=0;i<=n;i++) {
        for(int j=0;j<2;j++) dp[i][j] = INT_MAX;
      }  
    
      dp[0][0]=0;
      dp[1][0]=0;
      
      for(int i=1; i<=n;i++){
        for(int j=0;j<2;j++){
          int remw = min(dp[i-1][0], dp[i-1][1])*w;
          
        }  
      }
      
      
    }
 
}