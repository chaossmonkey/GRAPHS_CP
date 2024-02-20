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


 bool isPrefix(int i,int j,string str1,string str2)
 {
    if(i==str1.size()-1 && str1[i]==str2[j])
    {
        return true;
    }
    if(str1[i]==str2[j])
    {
        return isPrefix(i+1,j+1,str1,str2);
    }
    return false;
 }

 bool isSuffix(int i,int j,string str1,string str2)
 {
    if(i==0 && str1[i]==str2[j])
    {
        return true;
    }


    if(str1[i]==str2[j])
    {
        return isSuffix(i-1,j-1,str1,str2);
    }
return false;
 }

int main()
{
    bool b1=isPrefix(0,0,"pa","papa");
    bool b2=isSuffix(2,3,"apa","papa");
    cout<<b1<<endl;
    cout<<b2<<endl;

      
}
