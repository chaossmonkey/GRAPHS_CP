// C++ program for the above approach 
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

// Define size of grid 
#define N 3 
#define M 4 

// To store direction of all the four 
// adjacent cells 
const int directionInX[4] = { -1, 0, 1, 0 }; 
const int directionInY[4] = { 0, 1, 0, -1 }; 

// Boolean function for checking 
// if a cell is valid or not 
bool isValid(int x, int y) 
{ 
	if (x < N && x >= 0 
		&& y < M && y >= 0) 
		return 1; 

	return 0; 
} 

// Boolean function which will check 
// whether the given array consist 
// of a cycle or not 
bool isCycle(int x, int y, char arr[N][M], 
			bool visited[N][M], 
			int parentX, int parentY) 
{ 
	// Mark the current vertex true 
	visited[x][y] = true; 

	// Loop for generate all possibilities 
	// of adjacent cells and checking them 
	for (int k = 0; k < 4; k++) { 

		int newX = x + directionInX[k]; 
		int newY = y + directionInY[k]; 

		if (isValid(newX, newY) == 1 
			&& arr[newX][newY] == arr[x][y] 
			&& !(parentX == newX 
				and parentY == newY)) { 

			// Check if there exist 
			// cycle then return true 
			if (visited[newX][newY] == 1) { 

				// Return 1 because the 
				// cycle exists 
				return true; 
			} 

			// Check if not found, 
			// keep checking recursively 
			else { 
				bool check 
					= isCycle(newX, newY, arr, 
							visited, x, y); 

				// Now, if check comes out 
				// to be true then return 1 
				// indicating there exist cycle 
				if (check == 1) 
					return true; 
			} 
		} 
	} 

	// If there was no cycle, 
	// taking x and y as source 
	// then return false 
	return false; 
} 

// Function to detect Cycle in a grid 
void detectCycle(char arr[N][M]) 
{ 

	// To store the visited cell 
	bool visited[N][M]; 

	// Initially marking all 
	// the cells as unvisited 
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			visited[i][j] = false; 

	// Boolean variable for 
	// storing the result 
	bool cycle = 0; 

	// As there is no fix position 
	// of Cycle we will have to 
	// check for every arr[i][j] 
	for (int i = 0; i < N; i++) { 

		// If cycle is present and 
		// we have already detected 
		// it, then break this loop 
		if (cycle == true) 
			break; 

		for (int j = 0; j < M; j++) { 

			// Taking (-1, -1) as 
			// source node's parent 
			if (visited[i][j] == 0) { 
				cycle = isCycle(i, j, arr, 
								visited, -1, -1); 
			} 

			// If we have encountered a 
			// cycle then break this loop 
			if (cycle == true) 
				break; 
		} 
	} 

	// Cycle was encountered 
	if (cycle == true) { 
		cout << "Yes"; 
	} 

	// Cycle was not encountered 
	else { 
		cout << "No"; 
	} 
} 

// Driver code 
int main() 
{ 
	// Given grid arr[][] 
	char arr[N][M] = { { 'A', 'A', 'A', 'A' }, 
					{ 'A', 'B', 'C', 'A' }, 
					{ 'A', 'D', 'D', 'A' } }; 

	// Function Call 
	detectCycle(arr); 
	return 0; 
}
