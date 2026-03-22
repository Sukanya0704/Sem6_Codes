#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void djikstra(int start, int v, vector<vector<pii>>& adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(v, INT_MAX);

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto& edge : adj[u]){
            int neighbor = edge.first;
            int weight = edge.second;

            if(dist[u] + weight < dist[neighbor]){
                dist[neighbor] = dist[u] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    cout << "\n--- Network Routing Results ---\n";
    for(int i=0; i<v; i++){
        cout << "Latency to Router " << i << ": ";
        if(dist[i] == INT_MAX) cout << "Unreachable" << endl;
        else cout << dist[i] << "ms" << endl;
    }
}

int main(){
    int routers, connections;
    cout<<"Enter the number of routers and connetions: ";
    if (!(cin >> routers >> connections)) return 0;

    vector<vector<pii>> adj(routers);

    cout<<"Enter the router1 and router2 of connection and the cost: "<<endl;
    for (int i = 0; i < connections; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int start_node;
    cout<<endl;
    cout<<"Enter the start node: ";
    cin >> start_node;

    djikstra(start_node, routers, adj);
           
    return 0;
}