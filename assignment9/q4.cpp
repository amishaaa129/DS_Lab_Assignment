#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;   

void Dijkstra(int start, vector<vector<pii>>& adj, int n) {
    vector<int> dist(n, 1000000000); 
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push(pii(0, start));

    while (!pq.empty()) {
        pii top = pq.top();
        pq.pop();

        int d = top.first;
        int node = top.second;

        if (d > dist[node])
            continue;

        for (size_t i = 0; i < adj[node].size(); i++) {
            int next = adj[node][i].first;
            int w    = adj[node][i].second;

            if (dist[node] + w < dist[next]) {
                dist[next] = dist[node] + w;
                pq.push(pii(dist[next], next));
            }
        }
    }

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i <<" : "<< dist[i] << endl;
    }
}

int main() {
    int n = 5;
    vector<vector<pii>> adj(n);

    adj[0].push_back(pii(1, 2));
    adj[0].push_back(pii(2, 4));
    adj[1].push_back(pii(2, 1));
    adj[1].push_back(pii(3, 7));
    adj[2].push_back(pii(4, 3));
    adj[3].push_back(pii(4, 1));

    Dijkstra(0, adj, n);

    return 0;
}
