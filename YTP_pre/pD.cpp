#include <bits/stdc++.h>
using namespace std;
#define AI(x) begin(x),end(x)
#define ll long long
#define endl '\n'
#ifdef DEBUG
#define debug(args...) LKJ("[ "+string(#args)+" ]", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int maxn = 1e5+5;
vector<pair<int, int>> adj[maxn];
vector<int> arr(maxn, 0);
vector<int>ans;
int visitCount = 0;

void dfs(int i, bool &status, vector<bool>& visited) {
    visitCount++;
    visited[i] = 1;
    if (arr[i]) {
        status = !status;
    }
    
    for (auto j : adj[i]) {
        if (!visited[j.first]) {
            if (status) {
                ans.push_back(j.second);
            }
            dfs(j.first, status, visited);
        }
    }
}

signed main() {_
    int n,m;
    cin >> n >> m;
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        count += arr[i];
    }
    vector<int> indeg(n+5, 0);
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back({y, i});
        adj[y].push_back({x, i});
        indeg[x]++;
        indeg[y]++;
    }
    if (count % 2) {
        cout << "No" << endl;
        return 0;
    }
    vector<bool>visited(n+5, 0);
    while (visitCount < n) {
        int start = 1;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i] && indeg[i]==1){
                start = i;
                break;
            }
        }
        bool status = 0;
        dfs(start, status, visited);
    }
    
    cout << "Yes" << endl;
    cout << ans.size() << endl;
    for (auto &i : ans) cout << i << " \n"[&i==&ans.back()];
    
    
    
    
    
    return 0;
}
