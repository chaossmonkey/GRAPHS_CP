#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>      // For priority queues and breadth-first search
#include <stack>      // For stacks and depth-first search
#include <set>        // For sets (sorted containers with unique elements)
#include <map>        // For maps (key-value pairs)
#include <unordered_set>   // For unordered sets (hash-based)
#include <unordered_map>   // For unordered maps (hash-based)
#include <string>     // For string manipulation
#include <cmath>      // For mathematical functions (e.g., sqrt, pow)
#include <iomanip>    // For output formatting (e.g., setw, setprecision)
#include <bitset>     // For bit manipulation
#include <functional> // For function objects and lambdas
#include <numeric>    // For accumulate and other numeric operations
#include <deque>         // Double-ended queue
#include <list>          // Doubly linked list
#include <forward_list>  // Singly linked list

using namespace std;


//the crux is - we say we have cycle only when the nebour of the present node is visited but is
//this nbr is also not the parent of the present node

class Graph
{
    int V;
    vector<vector<int>> adj;

    public:
     Graph(int v)
   {
    this->V = v;
    adj.resize(V);
   }
   
   void addEdge(int v1,int v2)
   {
    adj[v1].push_back(v2);
    adj[v2].push_back(v1); ///comment this if  its unidrectional graphs
   }


  void printAdjacencyList()
  {

    for(int i=0;i<V;i++)
    {
        cout << "Adjacency list of vertex " << i << ":\n";
            for (const auto& neighbor : adj[i]) {
                cout << "-> " << neighbor << endl;
            }
    }
  }


  bool dfs(int src,bool* visited,int parent)
  {
      
      visited[src]=true;

      for(auto& it:adj[src])
      {
        
        if(visited[it]==false)
        {
            bool CyclicOrNot=dfs(it,visited,src);
            if(CyclicOrNot==true)
            {
                return true;
            }

        }
        else
        {
            if(parent!=it)
            {
                return true;
            }
        }
        
      }
      return false;
  }
  bool containsCycleOrNot()
  {

    bool*visited =new bool[V]{0};
    return dfs(0,visited,-1);

  }

  
};

int main()
{


    Graph g(5);
    g.addEdge(0,1);
     g.addEdge(1,2);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(3,4);



    
    cout<<g.containsCycleOrNot()<<endl;


return 0;
}