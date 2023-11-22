#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int v, vector<vector<int>>& edges, int src) {
    vector<int> dist(v, 1e9);
    dist[src] = 0;
    for (int i = 0; i < v - 1; i++) {
        for (auto it : edges) {
            int u = it[0], v = it[1], wt = it[2];
            if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    for (auto it : edges) {
        int u = it[0], v = it[1], wt = it[2];
        if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
            return {-1};
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
    int v = 6;
    vector<vector<int>> edges(7, vector<int>(3));
    edges[0] = {3, 2, 6};
    edges[1] = {5, 3, 1};
    edges[2] = {0, 1, 5};
    edges[3] = {1, 5, -3};
    edges[4] = {1, 2, -2};
    edges[5] = {3, 4, -2};
    edges[6] = {2, 4, 3};
    vector<int> dist = bellman_ford(v, edges, 0);

    printAdjacencyMatrix(v, edges);
    cout<<endl;
    
    cout << "Vertex" << "\t" << "Distance from Source" << endl;
    for (int i = 0; i < v; i++) {
        if (dist[i] == 1e9) {
            cout << "  " << i << "\t\t" << "Path does not exist!" << endl;
            continue;
        }
        cout << "  " << i << "\t\t" << dist[i] << endl;
    }
    cout << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> bellman_ford(int v, vector<vector<int>>& edges, int src) {
//     vector<int> dist(v, 1e9);
//     dist[src] = 0;
//     for (int i = 0; i < v - 1; i++) {
//         for (auto it : edges) {
//             int u = it[0], v = it[1], wt = it[2];
//             if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
//                 dist[v] = dist[u] + wt;
//             }
//         }
//     }
//     for (auto it : edges) {
//         int u = it[0], v = it[1], wt = it[2];
//         if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
//             return {-1};
//         }
//     }
//     return dist;
// }

// void print_graph_matrix(int v, vector<vector<int>>& edges) {
//     int adj_matrix[v][v];
//     for (int i = 0; i < v; i++) {
//         for (int j = 0; j < v; j++) {
//             adj_matrix[i][j] = 1e9;
//         }
//     }
//     for (auto it : edges) {
//         int u = it[0], v = it[1], wt = it[2];
//         adj_matrix[u][v] = wt;
//     }

//     for (int i = 0; i < v; i++) {
//         for (int j = 0; j < v; j++) {
//             if (adj_matrix[i][j] == 1e9) {
//                 cout << 0 << " ";
//             } else {
//                 cout << adj_matrix[i][j] << " ";
//             }
//         }
//         cout << endl;
//     }
// }

// int main() {
// 	int v = 6;
// 	vector<vector<int>> edges(7, vector<int>(3));
// 	edges[0] = {3, 2, 6};
// 	edges[1] = {5, 3, 1};
// 	edges[2] = {0, 1, 5};
// 	edges[3] = {1, 5, -3};
// 	edges[4] = {1, 2, -2};
// 	edges[5] = {3, 4, -2};
// 	edges[6] = {2, 4, 3};
// 	vector<int> dist = bellman_ford(v, edges, 0);
// 	cout<<"Vertex"<<"\t"<<"Distance from Source"<<endl;
//     for (int i = 0; i < v; i++) {
//         if(dist[i]==1e9){
//             cout<<"  "<<i<<"\t\t"<<"Path does not exist!"<<endl;
//             continue;
//         }
//         cout<<"  "<<i<<"\t\t"<<dist[i]<<endl;
//     }
//     cout << endl;

//     print_graph_matrix(v, edges);

// 	return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// vector<int> bellman_ford(int v, vector<vector<int>>& edges, int src) {
//     vector<int> dist(v, 1e9);
//     dist[src] = 0;
//     for (int i = 0; i < v - 1; i++) {
//         for (auto it : edges) {
//             int u = it[0], v = it[1], wt = it[2];
//             if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
//                 dist[v] = dist[u] + wt;
//             }
//         }
//     }
//     for (auto it : edges) {
//         int u = it[0], v = it[1], wt = it[2];
//         if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
//             return {-1};
//         }
//     }
//     return dist;
// }

// int main() {
// 	int v = 6;
// 	vector<vector<int>> edges(7, vector<int>(3));
// 	edges[0] = {3, 2, 6};
// 	edges[1] = {5, 3, 1};
// 	edges[2] = {0, 1, 5};
// 	edges[3] = {1, 5, -3};
// 	edges[4] = {1, 2, -2};
// 	edges[5] = {3, 4, -2};
// 	edges[6] = {2, 4, 3};
// 	vector<int> dist = bellman_ford(v, edges, 0);
// 	cout<<"Vertex"<<"\t"<<"Distance from Source"<<endl;
//     for (int i = 0; i < v; i++) {
//         if(dist[i]==1e9){
//             cout<<"  "<<i<<"\t\t"<<"Path does not exist!"<<endl;
//             continue;
//         }
//         cout<<"  "<<i<<"\t\t"<<dist[i]<<endl;
//     }
// 	cout << endl;
// 	return 0;
// }