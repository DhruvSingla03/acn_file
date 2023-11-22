#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int v, vector<vector<int>> adj[], int src) {
    set<pair<int, int>> st;
    vector<int> dist(v, 1e9);
    st.insert({0, src});
    dist[src] = 0;
    while (!st.empty()) {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);
        for (auto it : adj[node]){
            int adjNode = it[0];
            int edgW = it[1];
            if (dis + edgW < dist[adjNode]){
                if (dist[adjNode] != 1e9){
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = dis + edgW;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

void printAdjacencyMatrix(int v, vector<vector<int>>& edges) {
    vector<vector<int>> adjMatrix(v, vector<int>(v, 0));
    for (auto it : edges) {
        int u = it[0], v = it[1], wt = it[2];
        adjMatrix[u][v] = wt;
    }
    cout << "Adjacency matrix of the graph:" << endl <<endl;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << setw(3) << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int v = 6, src = 0;
    vector<vector<int>> edges(7, vector<int>(3));
	edges[0] = {3, 2, 6};
	edges[1] = {5, 3, 1};
	edges[2] = {0, 1, 5};
	edges[3] = {1, 5, 3};
	edges[4] = {1, 2, 2};
	edges[5] = {3, 4, 2};
	edges[6] = {2, 4, 3};

    vector<vector<int>> adj[v];
    for(auto it: edges) {
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }

    vector<int> dist = dijkstra(v, adj, src);

    printAdjacencyMatrix(v, edges);
    cout<<endl;

    cout<<"Vertex"<<"\t"<<"Distance from Source"<<endl;
    for (int i = 0; i < v; i++) {
        if(dist[i]==1e9){
            cout<<"  "<<i<<"\t\t"<<"Path does not exist!"<<endl;
            continue;
        }
        cout<<"  "<<i<<"\t\t"<<dist[i]<<endl;
    }
    cout << endl;
    return 0;
}