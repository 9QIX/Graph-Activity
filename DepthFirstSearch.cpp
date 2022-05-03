//Kirk Hendrix L. Bulaong (CPE-201)
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    //variable declaration
    int cost[10] [10], i, j, k, n, stk[10], top, v, visit[10], visited[10];
    int m;

    cout << "Enter the number of vertices in the Graph: ";
    cin >> n;
    cout << "Enter the number of edges in the Graph: ";
    cin >> m;
    cout << "Enter the edges with source and target vertex:\n";

    for(k = 1; k <= m; k++){
        cin >> i >> j;
        cost[i][j] = 1;
    }

    cout << "Enter the initial vertex to start the DFS traversal with: ";
    cin >> v;
    cout << "\nThe Depth First Search Traversal for Given Graph: ";
    cout << v << "  ";
    //start with the vertex v, marking it visited to avoid visiting again
    visited[v] = 1;
    k = 1;

    //the DFS Traversal Logic
    while(k < n)
    {
        for(j = n; j >= 1; j--)
            if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
            {
                visit[j] = 1;
                //put all the vertices that are connected to the visited vertex into a stack
                stk[top] = j;
                top++;
            }
        //output all the connected vertices one at a time
        v = stk[--top];
        cout << v << "  ";
        k++;
        //as v is visited, so it is not a valid candidate to visit in future
        visit[v] = 0;
        //to mark it visited
        visited[v] = 1;
    }

    return 0;
}