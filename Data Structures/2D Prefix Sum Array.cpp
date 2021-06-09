template<typename T> struct psa2{
    vector<vector<T>> a;
    int r, c;
    void init(int x, int y){
        r = x, c = y;
        a.assign(x+2, vector<T>(y+2, 0));
    }
    void update(int r1, int c1, int r2, int c2, T v){
        a[r1][c1] += v; a[r1][c2+1] -= v;
        a[r2+1][c1] -= v; a[r2+1][c2+1] += v;
    }
    void build(){ // call build once or twice
        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++)
                a[i][j] += a[i][j-1];
        for(int j = 1; j <= c; j++)
            for(int i = 1; i <= r; i++)
                a[i][j] += a[i-1][j];
    }
    T query(int r1, int c1, int r2, int c2){
        return a[r2][c2]-a[r1-1][c2]-a[r2][c1-1]+a[r1-1][c1-1];
    }
};
