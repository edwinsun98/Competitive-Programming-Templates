/*---------Binary Indexed Tree---------*/
struct bit{
    ll bit[1000005];
    void update(int x, ll v){
        for(int i = x; i <= 1000000; i+=i&-i)bit[i]+=v;
    }
    ll query(int x){
        ll sum = 0;
        for(int i = x; i > 0; i-=i&-i)sum += bit[i];
        return sum;
    }
};
/*---------Binary Indexed Tree End---------*/v
