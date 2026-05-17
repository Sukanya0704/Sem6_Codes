#include<bits/stdc++.h>
using namespace std;

void remove_edge(vector<vector<int>>& neighbours, int u, int v){
    auto it1 = find(neighbours[u].begin(), neighbours[u].end(), v);
    if(it1 != neighbours[u].end()){
        neighbours[u].erase(it1);
    }
    
    auto it2 = find(neighbours[v].begin(), neighbours[v].end(), u);
    if(it1 != neighbours[u].end()){
        neighbours[u].erase(it2);
    }
}


void bfs(queue<int>& q, vector<vector<int>>& neighbours, vector<int>& visited, string msg){
    if(q.empty()) return;
    int node = q.front();
    q.pop();
    
    for(auto neighbour :neighbours[node]){
        if(visited[neighbour] == 0){
            visited[neighbour] = 1;
            q.push(neighbour);
            cout << "Message reached to node " << neighbour << "!";
        }
    }
    bfs(q, neighbours, visited, msg);
}

void dfs(int node, vector<vector<int>>& neighbours, vector<int>& visited, string msg){
    visited[node] = 1;
    cout << "Message reached to node " << node << "!";
    for(auto neighbour :neighbours[node]){
        if(visited[neighbour] == 0){
            dfs(neighbour, neighbours, visited, msg);
        }
    }
}

int main(){
    cout << "Stimulation of message transfer: " << endl;
    
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    
    vector<vector<int>> neighbours(n);
    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;
    
    for(int i=0; i<edges; i++){
        int u, v;
        cout << "Edge " << i + 1 << "(u v): ";
        cin >> u >> v;
        neighbours[u].push_back(v);
        neighbours[v].push_back(u);
    }
    
    string msg;
    cout << "Enter the msg to broadcast: ";
    cin.ignore();
    getline(cin, msg);
    
    int algorithm;
    cout << "Enter the algorithm to broadcast the message (1 for BFS ) and (2 for DFS): ";
    cin >> algorithm;
    int start_node;
    cout << "Enter the starting node to start the broadcast: ";
    cin >> start_node;
    
    vector<int> visited(n, 0);
    if(algorithm == 1){
        queue<int> q;
        q.push(start_node);
        visited[start_node] = 1;
        cout << "Message reached to node " << start_node << "!";
        bfs(q, neighbours, visited, msg);
    }else{
        dfs(start_node, neighbours, visited, msg);
    }

    cout << "Enter the number of edges to remove: ";
    int remove_edges;;
    cin >> remove_edges;
    for(int i=0; i<remove_edges; i++){
        int u, v;
        cout << "Edge " << i + 1 << "(u v): ";
        cin >> u >> v;
        remove_edge(neighbours, u, v);
    }

    cout << "Rebroadcasting the message after edge removal: " << endl;
    fill(visited.begin(), visited.end(), 0);   

    if(algorithm == 1){
        queue<int> q;
        q.push(start_node);
        visited[start_node] = 1;
        cout << "Message reached to node " << start_node << "!";
        bfs(q, neighbours, visited, msg);
    }else{
        dfs(start_node, neighbours, visited, msg);
    }

    return 0;
}