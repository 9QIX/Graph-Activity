//Kirk Hendrix L. Bulaong (CPE-201)
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<bool> v;
vector<vector<int>> g;

void bfsTraversal(int b){
    //declare a queue to store all the nodes connected to b
    queue<int> q;
    //insert b to queue
    q.push(b);
    //mark b as visited
    v[b] = true;
    cout << "\nThe Breadth First Traversal for Given Graph (with 0 as starting node):  ";
    while (!q.empty()){
        int a = q.front();
        q.pop(); //delete the first element form queue
        for (int & j : g[a]){
            if (!v[j]){
                v[j] = true;
                q.push(j);
            }
        }
        cout << a << "  ";
    }
}

void makeEdge(int a, int b){
    g[a].push_back(b); //an edge from a to b (directed graph)
}

int main(){
    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    v.assign(n, false);
    g.assign(n, vector<int>());

    int a, b, i;
    cout << "Enter the edges with source and target vertex:\n";

    for (i = 0; i < e; i++){
        cin >> a >> b;
        makeEdge(a, b);
    }

    for (i = 0; i < n; i++){
        //if the node i is unvisited
        if (!v[i]){
            bfsTraversal(i);
        }
    }

    return 0;
}