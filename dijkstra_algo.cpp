#include <bits/stdc++.h>
using namespace std;

#define V 9

int minDistance(const vector<int>& dist, const vector<bool>& sptSet) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(const vector<int>& dist) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

void dijkstra(const vector<vector<int>>& graph, int src) {
    vector<int> dist(V, INT_MAX);
    vector<bool> sptSet(V, false);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist);
}

int main() {
    vector<vector<int>> graph = {{0, 5, 0, 0, 0, 0, 0, 9, 0},
                                  {5, 0, 7, 0, 0, 0, 0, 12, 0},
                                  {0, 7, 0, 6, 0, 5, 0, 0, 3},
                                  {0, 0, 6, 0, 8, 15, 0, 0, 0},
                                  {0, 0, 0, 8, 0, 11, 0, 0, 0},
                                  {0, 0, 5, 15, 11, 0, 3, 0, 0},
                                  {0, 0, 0, 0, 0, 3, 0, 2, 8},
                                  {9, 12, 0, 0, 0, 0, 2, 0, 10},
                                  {0, 0, 3, 0, 0, 0, 8, 10, 0}};

    clock_t t = clock();
    dijkstra(graph, 0);
    t = clock() - t;
    float time_taken = (float)t / CLOCKS_PER_SEC;
    cout << endl << "Time taken by algorithm is: " << time_taken << endl;
    return 0;
}
