#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 200000;

vector<int> C(MAXN);
vector<vector<int>> tree(MAXN);
vector<bool> visited(MAXN);
set<int> sums;

void dfs(int node, int parent, int current_sum) {
    current_sum += C[node];
    sums.insert(current_sum);
    visited[node] = true;
    
    for (int neighbor : tree[node]) {
        if (neighbor != parent && !visited[neighbor]) {
            dfs(neighbor, node, current_sum);
        }
    }
    
    visited[node] = false;
}

int main() {
    int N, K;
    cin >> N >> K;
    
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }
    
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    for (int i = 0; i < N; ++i) {
        dfs(i, -1, 0);
    }
    
    if (sums.size() < K) {
        cout << "-1" << endl;
    } else {
        auto it = sums.begin();
        advance(it, K - 1);
        cout << *it << endl;
    }
    
    return 0;
}
