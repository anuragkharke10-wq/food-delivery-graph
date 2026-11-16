// Food Delivery Route and Location Management System
// Case Study 19 - Data Structures & Algorithms
//
// Models a city's delivery network as an undirected graph:
//   - locations (restaurants, residential areas, customers) = vertices
//   - roads connecting them                                 = edges
// Represented with an adjacency list; explored with BFS and DFS.

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

class DeliveryGraph {
    int n;                      // number of locations
    vector<string> name;        // index -> location name
    map<string,int> id;         // location name -> index
    vector<vector<int>> adj;    // adjacency list

public:
    DeliveryGraph(vector<string> locations) {
        name = locations;
        n = name.size();
        adj.resize(n);
        for (int i = 0; i < n; i++) id[name[i]] = i;
    }

    // Add an undirected road between two locations
    void addEdge(string a, string b) {
        adj[id[a]].push_back(id[b]);
        adj[id[b]].push_back(id[a]);   // both directions
    }

    void printAdjList() {
        cout << endl << "Adjacency List (connected locations):" << endl;
        for (int i = 0; i < n; i++) {
            cout << name[i] << " -> ";
            for (int v : adj[i]) cout << name[v] << "  ";
            cout << endl;
        }
    }

    // BFS uses a QUEUE: visit locations level by level
    void BFS(string start) {
        vector<bool> visited(n, false);
        queue<int> q;
        int src = id[start];

        visited[src] = true;
        q.push(src);

        cout << endl << "BFS from " << start << ": ";
        while (!q.empty()) {
            int node = q.front(); q.pop();
            cout << name[node] << "  ";
            for (int nb : adj[node])
                if (!visited[nb]) {
                    visited[nb] = true;
                    q.push(nb);
                }
        }
        cout << endl;
    }

    // DFS goes DEEP first, then backtracks (recursion = stack)
    void dfsUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << name[node] << "  ";
        for (int nb : adj[node])
            if (!visited[nb]) dfsUtil(nb, visited);
    }

    void DFS(string start) {
        vector<bool> visited(n, false);
        cout << "DFS from " << start << ": ";
        dfsUtil(id[start], visited);
        cout << endl;
    }
};

int main() {
    vector<string> locations = {
        "PizzaHut", "Dominos", "PalmBeach",
        "Sector15", "CustomerA", "CustomerB"
    };

    DeliveryGraph city(locations);

    city.addEdge("PizzaHut",  "PalmBeach");
    city.addEdge("PizzaHut",  "Dominos");
    city.addEdge("Dominos",   "Sector15");
    city.addEdge("PalmBeach", "CustomerA");
    city.addEdge("Sector15",  "CustomerA");
    city.addEdge("Sector15",  "CustomerB");
    city.addEdge("CustomerA", "CustomerB");

    city.printAdjList();

    string start;
    cout << endl << "Enter starting location: ";
    cin >> start;

    city.BFS(start);
    city.DFS(start);

    return 0;
}
