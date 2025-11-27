#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int find(int x, vector<int>& parent) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x], parent);
}

void unionSet(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = find(a, parent);
    b = find(b, parent);
    if (rank[a] < rank[b]) parent[a] = b;
    else if (rank[a] > rank[b]) parent[b] = a;
    else parent[b] = a, rank[a]++;
}

int main() {
    int n = 4;  
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    cout << "Kruskal's MST:\n";
    for (auto e : edges) {
        if (find(e.u, parent) != find(e.v, parent)) {
            cout << e.u << " - " << e.v << " (Weight: " << e.w << ")\n";
            unionSet(e.u, e.v, parent, rank);
        }
    }
}
