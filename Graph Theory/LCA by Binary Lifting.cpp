const int N = 1e5+3;
vector<int> adj[N];
struct lca{
    vector<int> h; // level of ith node
    vector<vector<int>> dp; // dp[i][j] = binary parent 2^j of ith node
    // dp[i][j] = parent that is distance 2^j on top of ith node
    void dfs(int cur, int par){
        h[cur] = h[par]+1;
        dp[cur][0] = par;
        for(int i = 1; i < 20; i++){
            dp[cur][i] = dp[dp[cur][i-1]][i-1];
        }
        for(auto& i : adj[cur+1]){
            int to = i-1;
            if(to^par)dfs(to, cur);
        }
    }
    void init(int n){
        h.assign(n+1, 0);
        dp.assign(n+1, vector<int>(20));
        dfs(1, 0);
    }
    int anc(int a, int b){
        if(h[a] < h[b])swap(a, b);
        int dif = h[a]-h[b];
        for(int i = 0; i < 20; i++){
            if(dif&(1<<i))a = dp[a][i];
        }
        if(a == b)return a+1;
        for(int i = 19; i >= 0; i--){
            if(dp[a][i] != dp[b][i]){
                a = dp[a][i]; b = dp[b][i];
            }
        }
        return dp[a][0];
    }
};
