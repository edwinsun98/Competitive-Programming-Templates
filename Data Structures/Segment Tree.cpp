template<typename T> struct seg{
    struct node{
        int l, r;
        T sum;
    };
    vector<node> seg;
    int n;
    void init(int sz){
        n = sz;
        int accurate = (1<<((int)log2(n)+2))-1;
        seg.assign(accurate, (node){0, 0, 0});
    }
    // TODO: operation change
    void pushup(int rt){
        seg[rt].sum = max(seg[2*rt].sum , seg[2*rt+1].sum);
    }
    void build(int l, int r, int rt){
        seg[rt].l = l; seg[rt].r = r;
        if(l == r) {
//            cin>>seg[rt].sum;
            return;
        }
        int mid = (l + r)/2;
        build(l, mid, 2*rt); build(mid+1, r, 2*rt+1); pushup(rt);
    }
    void update(int id, T val, int rt){
        if(seg[rt].l == seg[rt].r){
            seg[rt].sum = val;
            return;
        }
        int mid = (seg[rt].l + seg[rt].r)/2;
        if(id <= mid) update(id, val, 2*rt);
        else update(id, val, 2*rt+1);
        pushup(rt);
    }
    T query(int l, int r, int rt){
        if(seg[rt].l == l && seg[rt].r == r) return seg[rt].sum;
        int mid = (seg[rt].l + seg[rt].r)/2;
        if(r <= mid) return query(l, r, 2*rt);
        if(l > mid) return query(l, r, 2*rt+1);
        // TODO: operation change
        return max(query(l, mid, 2*rt) , query(mid+1, r, 2*rt+1));
    }
};
