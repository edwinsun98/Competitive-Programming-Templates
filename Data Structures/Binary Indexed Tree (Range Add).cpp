template<typename T> struct bit{
    int n;
    vector<T> bit;
    void init(int sz){
        n = sz;
        bit.assign(n+1, 0);
    }
    void update(int x, T v){
        for(int i = x; i <= n; i+=i&-i){
            bit[i] += v;
        }
    }
    void rupdate(int l, int r, T v) {
        update(l, v);
        update(r + 1, -v);
    }
    T query(int x){
        T sum = 0;
        for(int i = x; i > 0; i-=i&-i){
            sum += bit[i];
        }
        return sum;
    }
};
