#include<bits/stdc++.h>
using namespace std;

void remove_edge(vector<vector<int>>& neighbours, int u, int v) {
    auto it1 = find(neighbours[u].begin(), neighbours[u].end(), v);
    if (it1 != neighbours[u].end()) {
        neighbours[u].erase(it1);
    }

    auto it2 = find(neighbours[v].begin(), neighbours[v].end(), u);
    if (it2 != neighbours[v].end()) {
        neighbours[v].erase(it2);
    }
}

void bfs_to_broadcast(queue<int>& q, vector<vector<int>>& neighbours, vector<int>& visited, string& msg) {
    if (q.empty()) return;
    int temp = q.front();
    q.pop();
    for (int i = 0; i < neighbours[temp].size(); i++) {
        int curr = neighbours[temp][i];
        if (visited[curr] == 0) {
            q.push(curr);
            visited[curr] = 1;
            cout << "Message reached node " << curr << endl;
        }
    }
    bfs_to_broadcast(q, neighbours, visited, msg);
}

void dfs_to_broadcast(int node, vector<vector<int>>& neighbours, vector<int>& visited, string& msg) {
    visited[node] = 1;
    cout << "Message reached node " << node << endl;
    for (int i = 0; i < neighbours[node].size(); i++) {
        int curr = neighbours[node][i];
        if (visited[curr] == 0) {
            dfs_to_broadcast(curr, neighbours, visited, msg);
        }
    }
}

void report_status(int n, const vector<int>& visited) {
    int count = 0;
    for (int i = 0; i < n; i++) if (visited[i] == 1) count++;
    
    cout << "\n--- Broadcast Report ---" << endl;
    cout << "Nodes reached: " << count << " / " << n << endl;
    if (count < n) {
        cout << "Network status: DISTURBED (Some nodes did not receive the message)" << endl;
        cout << "Missing nodes: ";
        for (int i = 0; i < n; i++) if (visited[i] == 0) cout << i << " ";
        cout << endl;
    } else {
        cout << "Network status: HEALTHY (All nodes reached)" << endl;
    }
    cout << "------------------------\n" << endl;
}

int main() {
    int n, edges;
    cout << "Enter the number of nodes: "; cin >> n;
    vector<vector<int>> neighbours(n);

    cout << "Enter the number of edges: "; cin >> edges;
    for (int i = 0; i < edges; i++) {
        int v1, v2;
        cout << "Edge " << i + 1 << " (u v): "; cin >> v1 >> v2;
        neighbours[v1].push_back(v2);
        neighbours[v2].push_back(v1);
    }

    string msg;
    cout << "Enter message: ";
    cin.ignore(); 
    getline(cin, msg);
    
    int algorithm, start_node;
    cout << "Algorithm (1 for BFS, 2 for DFS): "; 
    cin >> algorithm;
    cout << "Starting node: "; 
    cin >> start_node;

    cout << "\n>> Initial Broadcast Starting..." << endl;
    vector<int> visited(n, 0);
    if (algorithm == 1) {
        queue<int> q; 
        q.push(start_node); 
        visited[start_node] = 1;
        cout << "Message reached node " << start_node << endl;
        bfs_to_broadcast(q, neighbours, visited, msg);
    } else {
        dfs_to_broadcast(start_node, neighbours, visited, msg);
    }
    report_status(n, visited);

    int del_count;
    cout << "How many edges to delete? "; 
    cin >> del_count;

    for (int i = 0; i < del_count; i++) {
        int u, v;
        cout << "Enter edge to delete (u v): "; cin >> u >> v;
        remove_edge(neighbours, u, v);
    }

    cout << "\n>> Second Broadcast After Edge Deletion..." << endl;
    fill(visited.begin(), visited.end(), 0); 

    if (algorithm == 1) {
        queue<int> q; 
        q.push(start_node); 
        visited[start_node] = 1;
        cout << "Message reached node " << start_node << endl;
        bfs_to_broadcast(q, neighbours, visited, msg);
    } else {
        dfs_to_broadcast(start_node, neighbours, visited, msg);
    }
    report_status(n, visited);

    return 0;
}