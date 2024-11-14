#include <bits/stdc++.h>
using namespace std;

class DisjointSet{

private:
    vector<int> parent, rank, size;
public:
    DisjointSet(int n){

        parent.resize(n + 1, 1);
        rank.resize(n + 1, 1);
        size.resize(n + 1, 1);
        for (int i = 1; i < n + 1; i++){
            parent[i] = i;
        }
    }

    int findParent(int u)
    {

        if (parent[u] == u)
            return u;

        return parent[u] = findParent(parent[u]);
    }

    void unionByRank(int u, int v){

        int ultimateParentU = findParent(u);
        int ultimateParentV = findParent(v);

        if(ultimateParentU == ultimateParentV) return;

        if(rank[ultimateParentU] > rank[ultimateParentV]){
            parent[ultimateParentV] = ultimateParentU;
        }

        else if(rank[ultimateParentU] < rank[ultimateParentV]){
            parent[ultimateParentU] = ultimateParentV;
        }

        else{
            parent[ultimateParentU] = ultimateParentV;
            rank[ultimateParentV]++;
        }
    }
    void unionBySize(int u, int v){

        int ultimateParentU = findParent(u);
        int ultimateParentV = findParent(v);

        if(ultimateParentU == ultimateParentV) return;

        if(size[ultimateParentU] > size[ultimateParentV]){
            parent[ultimateParentV] = ultimateParentU;
            size[ultimateParentU]++;
        }

        else{
            parent[ultimateParentU] = ultimateParentV;
            size[ultimateParentV]++;
        }
    }
};

int main()
{
    DisjointSet d(7);

    d.unionBySize(1,2);
    d.unionBySize(2,3);
    d.unionBySize(4,5);
    d.unionBySize(6,7);
    d.unionBySize(5,6);

    if(d.findParent(3) == d.findParent(7)) cout<<"Same section"<<endl;
    else cout<<"Different Section"<<endl;

    d.unionBySize(3,6);
    if(d.findParent(3) == d.findParent(7)) cout<<"Same section"<<endl;
    else cout<<"Different Section"<<endl;

    return 0;
}