const ll mod = 1e9+7;
vector<ll> fact;
ll add(ll a, ll b){
    return (a+b)%mod;
}
ll sub(ll a, ll b){
    return ((a-b)%mod+mod)%mod;
}
ll mult(ll a, ll b){
    return ((a%mod)*(b%mod))%mod;
}
ll power(ll x, ll y){
    ll res = 1;
    x = x;
    while(y){
        if(y&1)res = mult(res, x);
        y >>= (ll)1;
        x = mult(x, x);
    }
    return res;
}
void init(int n){
    fact.assign(n+1, 0);
    fact[0] = 1;
    for(ll i = 1; i <= n; i++){
        fact[i] = mult(fact[i-1], i);
    }
}
// (1/n)%mod
ll modinv(ll a){
    return power(a, mod-2);
}
ll nCr(ll n, ll r){
    if(n < r)return 0;
    return (fact[n]*modinv(fact[r])%mod)*modinv(fact[n-r])%mod;
}

