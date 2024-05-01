ll hsh[MAX], pwi[MAX];

ll bigmod(ll a, ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b/=2;
    }
    return ans;
}


void calc_hash(string s) {
  int n=s.size();
  hsh[1]=s[0]-'a'+1;
  ll b=1ll;
  pwi[1]=b;
  for(int i=2;i<=n;i++){
    b = (b*31)%MOD;
    pwi[i]=bigmod(b, MOD-2);
    hsh[i] = (hsh[i-1] + b*(s[i-1]-'a'+1))%MOD;
  }
  
  // string s = "ddabababb";
    // calc_hash(s);
    // ll val1 = (hsh[5] - hsh[2] + MOD)%MOD, val2 = (hsh[7] - hsh[4] + MOD)%MOD;
    // val1 = (val1 * pwi[1])%MOD;
    // val2 = (val2 * pwi[3])%MOD;
    // cout<<val1<<" "<<val2<<endl;
  
}
