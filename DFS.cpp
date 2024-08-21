#include <iostream>
#include <vector>
using namespace std;

//add edge to the adjacency list
//vector<vector<int>> is a vector of vectors of integers.
void addEdge(vector<vector<int>> &adj, int s, int t){
    adj[s].push_back(t);//add edge from vertex s to t
    adj[t].push_back(s);//add edge from vertex t to s (it is undirected graph)
}

//DFS traversal
void DFS(vector<vector<int>> &adj, vector<bool> &visited, int s){
    //mark current vertex as visited
    visited[s] = true;
    cout<<s<<" ";

    //visit all others, do the recursion
    for (int i : adj[s])
    {
        if (visited[i] == false)
        {
            DFS(adj, visited, i);
        }
    }
}

int main(){
    int vertices = 5;
    vector<vector<int>> adj(vertices);//create an adjacency list

    //define the edges for the graph
    vector<vector<int>> edges = {{1,2},{1,0},{2,0},{2,3},{2,4}};

    for (auto &e : edges)//auto: auto detect the data type. &e: pass the reference to e. edges: it indicates the range
    {
        addEdge(adj, e[0], e[1]);   
    }

    int startingPoint = 1;
    cout<<"DFS from here: "<<startingPoint<<endl;

    //start to do DFS
    vector<bool> visited(adj.size(), false);
    DFS(adj, visited, startingPoint);
}