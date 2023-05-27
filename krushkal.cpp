#include<bits/stdc++.h>
using namespace std;
struct Edge {
    int u, v, w;
};
const int MAX = 1e5 + 5;
int parent[MAX], size[MAX];
vector<Edge> edges;

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
void kruskal(int n) {
    int cost = 0;
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b) {
        return a.w < b.w;
    });
    for (int i = 0; i < n; i++)
        make_set(i);

    cout<<"Edges of MST:\n";    
    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.w;
            cout<<e.u<<"-"<<e.v<<"--->"<<e.w<<"\n";
            union_sets(e.u, e.v);
        }
    }
    cout << "\nMinimum Cost Spanning Tree: " << cost << endl;
}
int main() {
    int n, m;
    cout<<"Enter the no. of vertices and edges:";
    cin >> n >> m;
    cout<<"start vertex ,end and weights of edges:\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    kruskal(n);
    return 0;
}
/*
Enter the no. of vertices and edges:5 8
start vertex ,end and weights of edges:
1 3 6
1 4 3
2 1 3
3 4 2
4 2 1
4 3 1
5 2 4
5 4 2
Edges of MST:
4-2--->1
4-3--->1
5-4--->2
1-4--->3

Minimum Cost Spanning Tree: 7

*/
