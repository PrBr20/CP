ll fact[MAX];
ll inv[MAX];

ll bigmod(ll a, ll b, ll m)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%m;
        b/=2;
        a=(a*a)%m;
    }
    return ans;
}


void Calfac()
{
    fact[0]=1;
    for(int i=1;i<MAX;i++) fact[i]=(fact[i-1]*i)%M;
    for(int i=0;i<MAX;i++)
    {
        inv[i]=bigmod(fact[i],M-2,M);
    }
    return;
}
 
ll Cal_ncr(int n,int r)
{
    if(n<r) return 0;
    return (fact[n]*inv[r]%M*inv[n-r]%M)%M;
}