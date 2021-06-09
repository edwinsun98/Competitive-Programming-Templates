template<typename T> struct seg2{
    struct node{
        int l, r;
        T sum, lz;
    };
    vector<node> seg;
    int n;
    void init(int sz){
        n = sz;
        int accurate = (1<<((int)log2(n)+2))-1;
        seg.assign(accurate, (node){0, 0, 0, 0});
    }
    // TODO: operation change
    void pushup(int rt){
        seg[rt].sum = seg[2*rt].sum + seg[2*rt+1].sum;
    }
    // TODO: operation change
    void pushdown(int rt){
        int lson = 2*rt, rson = 2*rt+1;
        seg[lson].lz += seg[rt].lz; seg[rson].lz += seg[rt].lz;
        seg[lson].sum += seg[rt].lz*(seg[lson].r - seg[lson].l + 1);
        seg[rson].sum += seg[rt].lz*(seg[rson].r - seg[rson].l + 1);
        seg[rt].lz = 0;
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
    void update(int l, int r, T val, int rt){
        if(seg[rt].l==l && seg[rt].r==r){
            seg[rt].lz += val; seg[rt].sum += val*(r - l + 1);
            return;
        }
        if(seg[rt].lz) pushdown(rt);
        int mid = (seg[rt].l + seg[rt].r)/2;
        if(r <= mid) update(l, r, val, 2*rt);
        else if(l > mid) update(l, r, val, 2*rt+1);
        else {
            update(l, mid, val, 2*rt);
            update(mid+1, r, val, 2*rt+1);
        }
        pushup(rt);
    }
    T query(int l, int r, int rt){
        if(seg[rt].l == l && seg[rt].r == r) return seg[rt].sum;
        if(seg[rt].lz) pushdown(rt);
        int mid = (seg[rt].l + seg[rt].r)/2;
        if(r <= mid) return query(l, r, 2*rt);
        if(l > mid) return query(l, r, 2*rt+1);
        // TODO: operation change
        return query(l, mid, 2*rt) + query(mid+1, r, 2*rt+1);
    }
};
