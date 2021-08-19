struct line{
    ll m, b;
};
struct chull{
    double cross(line a, line b){
        return (double)(b.b-a.b)/(a.m-b.m);
    }
    deque<line>cht;
    ll arr[100010], dp[100010];
    void add(line l){
        while((int)cht.size() >= 2 &&
              cross(cht.back(), l) <= cross(cht.back(),cht[(int)cht.size()-2]))
            cht.pop_back();
        cht.pb(l);
    }
    ll query(ll x){
        int l = 0, r = (int)cht.size()-2, m;
        int idx = (int)cht.size()-1;
        while(l <= r){
            m = (l+r)/2;
            if(cross(cht[m], cht[m+1]) >= x){
                idx = m; r = m-1;
            }else l = m+1;
        }
        return cht[idx].m*x+cht[idx].b;
    }
};
