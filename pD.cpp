#include <iostream>
#include <utility>
#include <vector>
using namespace std;
const int MAXN = 1e5 + 5;
bool c[MAXN], color[MAXN];
vector<int> ans;
vector<pair<int, int> > graph[MAXN];
bool dfs(int u = 1, int pe = -1) {
	color[u] = 1;	
	bool light = c[u];
	for(auto [v, e] : graph[u]) {
		if(!color[v]) light ^= dfs(v, e);	
	}
	if(light) ans.push_back(pe);
	return light;
}
void solve() {
	int N, M;
	cin >> N >> M;
	for(int i = 1; i <= N; ++i) {
		cin >> c[i];
	}
	for(int i = 1; i <= M; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(make_pair(v, i));
		graph[v].push_back(make_pair(u, i));
	}
	for(int i = 1; i < N; ++i) {
		if(!color[i]) {
			if(dfs(i)) {
				cout << "No\n";
				return;
			}
		}
	}
	cout << "Yes\n" << (int)ans.size() << '\n';
	for(int i = 0; i < (int)ans.size(); ++i) {
		cout << ans[i] << " \n"[i == (int)ans.size() - 1];
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
