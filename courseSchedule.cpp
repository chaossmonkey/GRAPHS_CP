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
   
   void addEdge(int v1,int v2)
   {
    adj[v1].push_back(v2);
    //adj[v2].push_back(v1); ///comment this if  its unidrectional graphs
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

  bool  dfs(int src,vector<bool>& visited,vector<bool>& stack)
  {
      visited[src]=true;
      stack[src]=true;

      for(auto& it:adj[src])
      {
        if(visited[it]==false)
        {
          bool CycleOrNot= dfs(it,visited,stack);
          if(CycleOrNot)
          {
            return true;
          }
        }
        else
        {
          if(stack[it]==true)
          {
            return true;
          }
        }
      }
  
      stack[src]=false;
      return false;
  }
  
  bool CycleOrNot()
  {
       vector<bool> visited(V,false);
       vector<bool> stack(V,false);

       for(int i=0;i<V;i++)
       {
        if(visited[i]==false)
        {
          if(dfs(i,visited,stack))
          {
            return true;
          }
        }
       }
       return false;
  }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        Graph g(numCourses);

         for (int i = 0; i < prerequisites.size(); i++) {
             vector<int> pair=prerequisites[i];
             int v1=pair[0];
             int v2=pair[1];
             g.addEdge(v2,v1);
         }

         return g.CycleOrNot();
       
    }

        
    };

  
