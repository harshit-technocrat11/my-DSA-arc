#include <bits/stdc++.h>
using namespace std;

// by babbar
class Solution
{
public:
    // namespace
    using AdjList = unordered_map<int, set<int>>;

    // function to create the adjList (below)
    AdjList createList(int V, const vector<vector<int>> &edges)
    {
        AdjList adjList;

        // Initialize all nodes in the map to ensure all
        // vertices (even isolated ones) are present.

        for (int i = 0; i < V; i++)
        {
            adjList[i] = set<int>();
        }

        // Populate the list for an undirected graph

        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            // push the vertices into AdjList
            adjList[u].insert(v);
            adjList[v].insert(u);
        }
        return adjList;
    }

    void print_Adj_List(const AdjList &adjList) {
        for ( auto it : adjList){
            cout << it.first << "--> ";
            for ( auto j : it.second ){
                cout << j << ", ";
            }cout << endl;
        }
    }

    void bfs(int startNode, const AdjList &adjList, unordered_map<int, bool> &visited)
    {
        queue<int> q;

        // 1. Initial actions for the start node
        q.push(startNode);
        visited[startNode] = true;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            // 2. Traverse neighbors (for auto in adjList[frontNode])
            // Use .at() for safe access in const context
            for (auto neighbor : adjList.at(frontNode))
            {
                // 3. Check if the neighbor is unvisited
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    int findNumberOfComponent(int V, vector<vector<int>> &edges)
    {
        if (V <= 0)
        {
            return 0;
        }

        AdjList adjList = createList(V, edges);
        print_Adj_List(adjList);

        // 2. Data Structure to track visited nodes
        // Using an unordered_map is flexible, but a vector<bool> is often preferred
        // when node indices are sequential (0 to V-1). We'll stick to the map for consistency.
        unordered_map<int, bool> visited;

        // intializing the map with all vertices V as false
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }

        int componentCount = 0;

        // main logic - looping through all the vertices ( from - to V-1 )
        for (int i = 0; i < V; i++)
        {
            // Check if the current vertex belongs to a component not yet traversed
            if (!visited[i])
            {
                // Found a new, unexplored component
                componentCount++;
                // traverse- and mark all the nodes in this component as visited
                bfs(i, adjList, visited);
            }
        }

        // total disconnected graphs
        return componentCount;
    }
};


int main() {

    Solution s;

    int vertices = 4;
    vector<vector<int>> edges;

    edges = {{3,1}, {0,3},{0,1}};

    cout << "numnber of components are : "<< s.findNumberOfComponent(vertices, edges);
    return 0;
}