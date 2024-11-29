#include<bits/stdc++.h>
using namespace std;

class Graph{

    public:
    int nodes; // number of nodes in the graph
    vector<vector<pair<int,int>>> adj;

    Graph(int V){
        nodes = V;
        adj.resize(V); // resize the adjacency list to V vertices
    }

    void addEdge(int u, int v, int weight){
        adj[u].push_back({weight, v}); // add an edge from u to v with weight
        adj[v].push_back({weight, u}); // add an edge from v to u with weight
    }


    vector<int> Dijkstra(int src){

        vector<int> distance(nodes, INT_MAX);

        distance[src] = 0; // distance of source node to itself is 0

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

        pq.push({0,src }); // push the source node into the priority_queue

        while(pq.size()){

            int currentDistance = pq.top().first;
            int currentVertex = pq.top().second;
            pq.pop();

            if( currentDistance > distance[currentVertex]) continue; // if the weight of the current node is greater than the distance of the current node, then skip it

            for(pair<int,int>& neighbour: adj[currentVertex]){
                
                int edgeWeight = neighbour.first;
                int adjacentVertex = neighbour.second;

                int newDistance = currentDistance + edgeWeight;

                if(newDistance < distance[adjacentVertex]){

                    distance[adjacentVertex] = newDistance;
                    pq.push({newDistance,adjacentVertex});
                }
            }
        }

        return distance; // returning the distance vector
    }

};


int main(){

    int V = 8;

    Graph *g = new Graph(V); // create a graph with 7 vertices

    g->addEdge(0,1,2);
    g->addEdge(0,2,6);
    g->addEdge(1,3,5);
    g->addEdge(2,3,8);
    g->addEdge(3,4,10);
    g->addEdge(3,5,15);
    g->addEdge(4,6,2);
    g->addEdge(5,6,6);

    vector<int> distances = g->Dijkstra(0); // find the shortest path from vertex 0

    for(int i = 0; i < V; i++){
        cout << "Distance from vertex " << i << " to vertex 0 is " << (distances[i] == INT_MAX? -1:distances[i]) << endl; // print the distances
    }

    return 0;
}