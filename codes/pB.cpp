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


signed main() {_
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    int ans = 0;
    vector<string> arr;
    for (int i = 0; i + n <= m; ++i) {
        string k = "";
        for (int j = 0; j < n; ++j) {
            k.push_back(b[i+j]);
        }
        int temp = 0;
        for (int j = 0; j < n; ++j) {
            temp += (k[j] != a[j]);
            if (temp >= 2) break;
        }
        if (temp <= 1) {
            arr.push_back(k);
            
        }
        
    }
    
    if (arr.empty()) {
        cout << "Not found" << endl;
    }else {
        sort(AI(arr));
        for(auto i : arr) cout << i << endl;
    }
    return 0;
}
