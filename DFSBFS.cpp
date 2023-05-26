#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Graph {
    public:
        //declaring all the essential variables
        map <int, vector<int>> adjList;
        map <int, bool> visited,visited1;
        queue <int> q;

        //function to add edge
        void addEdge(int src, int dest) 
        {
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }

        //function for BFS
        void BFS() 
        {
            if(q.empty()) 
            {
                return;
            }
            
            int node = q.front();
            q.pop();
            
            cout << node << " -> ";
            
            for(int i : adjList[node]) 
            {
                if(!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
            BFS();
        }  

        //function for DFS
        void DFS(int node) 
        {
            visited1[node] = true;
            
            cout << node << " -> ";
            for(int i : adjList[node]) 
            {
                if(!visited1[i]) 
                {
                    DFS(i);
                }
            }
        }

        
        
};
int main() {
    Graph g;           //creating an object of class
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    
    cout << "DFS : "<<endl;
    g.DFS(0);
    cout << endl;
    
    cout << "BFS : " << endl;
    g.q.push(0);
    g.visited[0] = true;
    g.BFS();
    
    return 0;
}