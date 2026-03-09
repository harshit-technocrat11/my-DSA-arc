#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m ;
    cin >> n>>m;
    // n- vertices
    // m- edges
    int adj[n+1][n+1];

    for ( int i=0; i< m ; i++){
        int u, v;
        cout << "enter vertices:";
        cin >> u >> v;
        // enter no. of edges b/w 
        adj[u][v]= 1;
        adj[v][u] = 1;
    }

    return 0;
}