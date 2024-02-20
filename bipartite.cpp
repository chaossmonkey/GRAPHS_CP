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
 void assignAdj(const vector<vector<int>>& adj) {
        if (adj.size() != V) {
            throw std::invalid_argument("Adjacency list size does not match number of vertices.");
        }
        this->adj = adj;
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

  bool bipartiteOrNot()
  {
    bool* visited=new bool[V]{0};
    bool* clr =new bool[V]{0};

    return dfs(-1,0,visited,clr,true);

  }
  bool dfs(int parent,int src,bool* visited,bool* clr,bool pclr)
  {
      visited[src]=true;
      clr[src]=pclr;

      for(auto& nbr:adj[src])
      {
         if(visited[nbr]==false)
         {
            bool torf=dfs(src,nbr,visited,clr,!pclr);
            if(torf==false)
            {
                return false;
            }
         }
         else
         {
            if(parent!=nbr && pclr==clr[nbr])
            {
                return false;
            }
         }
      }
      return true;
    
  }
};

int main()
{


    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(0,2);
  



    
    cout<<g.bipartiteOrNot()<<endl;


return 0;
}