struct sparse{
    int n, MAXN = 50001, K = 20;
    int lg[50001]; ll st[50001][20];
    void init(int arr[]){
        for(int i = 0; i < n; i++){st[i][0] = arr[i];}
        lg[1] = 0; for (int i = 2; i <= 50001; i++)lg[i] = lg[i/2] + 1;
        for (int j = 1; j <= 18; j++)for (int i = 0; i + (1 << j) <= n+1; i++)
            st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
        return; //0 indexed
    }
    ll query(int l, int r){
        int t = lg[r - l + 1];
        return (ll)max(st[l][t], st[r - (1 << t) + 1][t]);
    }
};
