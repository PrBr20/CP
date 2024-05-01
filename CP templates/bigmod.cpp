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
