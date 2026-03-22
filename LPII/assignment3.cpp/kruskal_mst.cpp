#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v, cost;
    bool operator<( const Edge& other){
        return cost < other.cost;
    }
};

struct DSU{
    vector<int> parent;
    DSU(int n){
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int find(int i){
        if(parent[i]==i) return i;

        return parent[i] = find(parent[i]);
    }

    void  unite(int i, int j){
        int root_i = find(i);
        int root_j = find(j);

        if(root_i != root_j){
            parent[root_i] = root_j;
        }
    }
};

void kruskalMST(int v, vector<Edge>& edges){
    sort(edges.begin(), edges.end());

    DSU dsu(v);

    int mst_weight = 0;
    int edge_counts = 0;

    cout<<endl<<"---Building the minimum cost network---"<<endl;
    for(auto & edge : edges){
        if(dsu.find(edge.u) != dsu.find(edge.v)){
            dsu.unite(edge.u, edge.v);
            mst_weight += edge.cost;
            edge_counts++;
            cout<<"Village "<<edge.u<<" connnected to Village "<<edge.v<<" | Cost: "<<edge.cost<<endl;
        }
        if(edge_counts == v-1) break;
    }
    cout<<"Total Minimum Budget :"<<mst_weight<<endl;
}

int main(){
    int v, e;

    cout<<"Enter the number of villages and possible routes: ";
    cin>>v>>e;

    vector<Edge> edges(e);
    for(int i=0; i<e; i++){
        cout<<"Route "<<i+1<<" (Village1 Village2 Cost): ";
        cin>>edges[i].u>>edges[i].v>>edges[i].cost;
    }

    kruskalMST(v, edges);
    return 0;
}