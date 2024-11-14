#include<bits/stdc++.h>
using namespace std;

template <typename T>

class graph{

    public:

    map< T, set<T> > adj;

    void addGraph(T u, T v, bool direction){

        // 1 for directed graph
        // 0 for undirected graph

        adj[u].insert(v);

        if(direction == 0){
            adj[v].insert(u);
        }
    }

    void printGraph(){

        for(auto i : adj){

            cout<<i.first<<"--> ";

            for(auto j : i.second){
                
                cout<<j<<", ";
            }cout<<endl;
        }
    }
};

int main(){

    graph<char> g;

    int edges;
    cout<<"Enter no. of edges -> ";
    cin>> edges;

    for(int i = 0; i < edges; i++){

        char u, v;
        cin>> u>> v;

        g.addGraph(u,v,0);
    }
    g.printGraph();
}