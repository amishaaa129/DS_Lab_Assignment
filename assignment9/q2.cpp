#include <iostream>
#include <vector>
using namespace std;

void DFSfunc(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : adj[node])
        if (!visited[neighbor])
            DFSfunc(neighbor, adj, visited);
}
void DFS(vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFSfunc(i, adj, visited);
        }
    }
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    cout << "DFS starting from node 0: ";
    DFS(adj, n);
}
