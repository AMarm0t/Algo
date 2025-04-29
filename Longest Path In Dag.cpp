const int N = 1e5 + 10;
int dp[N], vis[N];
bool check[N];
int cyc = 0;

void dfs(int i, vector<vector<int>>&graph) {
	if (vis[i])
		return;
	vis[i] = 1;
	check[i] = 1;

	for (auto u : graph[i]) {
		//cout << u << endl;
		if (!vis[u])
			dfs(u, graph);
		else if (check[u])
			cyc = 1;
		dp[i] = max(dp[i], dp[u] + 1);
	}
	check[i] = 0;
}
