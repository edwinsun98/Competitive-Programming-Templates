const int N = 35;
vector<vector<int>> adj(N, vector<int>(N));
vector<vector<int>> adj2(N, vector<int>(N));
vector<int> par(N);
vector<int> dis(N);
int n, m;
bool bfs(int s, int t){
    fill(all(par), -1);
    fill(all(dis), 0);
    queue<int> q;
    dis[s] = 1e9; q.push(s);
    while(!q.empty()){
        int c = q.front(); q.pop();
        for(int i = 1; i <= n; i++){
            if(!dis[i] && adj2[c][i]){
                dis[i] = min(dis[c], adj2[c][i]);
                par[i] = c; q.push(i);
            }
        }
    }
    return dis[t];
}
int flow(int s, int t){
    for(int i = 1; i <= n; i++)for(int j = 1; j <= n; j++)adj2[i][j] = adj[i][j];
    int ans = 0;
    while(bfs(s, t)){
        ans += dis[t];
        for(int i = t; i != s; i = par[i]){
            adj2[par[i]][i] -= dis[t];
            adj2[i][par[i]] += dis[t];
        }
    }
    return ans;
}
