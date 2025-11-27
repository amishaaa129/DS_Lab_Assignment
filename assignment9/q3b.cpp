#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii; 

void Prim(int start, vector<vector<pii>>& adj, int n) {
    vector<bool> visited(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push(pii(0, start));

    cout << "Prim's MST:\n";

    while (!pq.empty()) {

        pii top = pq.top();
        pq.pop();

        int weight = top.first;
        int node   = top.second;

        if (visited[node])
            continue;

        visited[node] = true;
        cout << "Visited: " << node << " with cost " << weight << endl;

        for (size_t i = 0; i < adj[node].size(); i++) {
            int next = adj[node][i].first;
            int w    = adj[node][i].second;
            if (!visited[next]) {
                pq.push(pii(w, next));
            }
        }
    }
}

int main() {
    int n = 5;
    vector<vector<pii>> adj(n);
    adj[0] = { pii(1, 2), pii(3, 6) };
    adj[1] = { pii(0, 2), pii(2, 3), pii(3, 8), pii(4, 5) };
    adj[2] = { pii(1, 3), pii(4, 7) };
    adj[3] = { pii(0, 6), pii(1, 8) };
    adj[4] = { pii(1, 5), pii(2, 7) };

    Prim(0, adj, n);
}
