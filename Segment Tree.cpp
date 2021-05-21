struct seg{
    int n;
    ll fun(ll x, ll y){return x+y;}
    ll seg[4000010], arr[1000010];
    ll build(int cur, int l, int r){
        if(l == r){
            seg[cur] = arr[l];
        }
        else{
            int mid = (l+r)/2;
            build(cur*2, l, mid); build(cur*2+1, mid+1, r);
            seg[cur] = fun(seg[cur*2], seg[cur*2+1]);
        }
    }
    ll update_(int cur, int l, int r, int idx, ll val){
        if(l == r){
            seg[cur] += val; arr[idx] += val;
        }
        else{
            int mid = (l+r)/2;
            if(idx >= l && idx <= mid)update_(cur*2, l, mid, idx, val);
            else update_(cur*2+1, mid+1, r, idx, val);
            seg[cur] = fun(seg[cur*2], seg[cur*2+1]);
        }
    }
    ll update(int idx, ll val){
        return update_(1, 1, n, idx, val);
    }
    ll query_(int cur, int l, int r, int ql, int qr){
        if(qr < l || r < ql){
            return (ll)0;
        }
        if(ql <= l && r <= qr){
            return seg[cur];
        }
        int mid = (l + r) / 2;
        ll p1 = query_(2*cur,l, mid, ql, qr), p2 = query_(2*cur+1, mid+1,r, ql, qr);
        return fun(p1 ,p2);
    }
    ll query(int l, int r){
        return query_(1, 1, n, l, r);
    }
};
/*---------Segment Tree End---------*/