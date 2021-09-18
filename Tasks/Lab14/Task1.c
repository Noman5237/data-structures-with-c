/**
 * @file: L14T1.c
 * @author: Anonyman637
 * @date: 9/17/2021; 4:13 AM
 */

#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define MAX 100
#define INF 99999

int n;

void printPath(int node, int origin[n], int start) {
	if (node == start) {
		printf("%d", node);
		return;
	}
	printPath(origin[node], origin, start);
	printf(" -> %d", node);
}

int printResult(int distance[n], int origin[n], int start) {
	//For each of the vertex print the value of distance matrix
	printf("[");
	for (int i = 0; i < n; i++) {
		printf("(%d: %d), ", i, distance[i]);
	}
	printf("]");
	printf("\n");
	
	//For each of the vertex backtrack the origin vertices to get the path
	for (int i = 0; i < n; i++) {
		printf("%d: ", i);
		printPath(i, origin, start);
		printf("\n");
	}
	
	return 0;
}

void initializeGraph(int adj[n][n]) {
	int i, j, edge;
	//This function will vary based on input type.
	//In this code, I gave a 75% chance to have an edge between two vertices and added a random value if the edge exists.
	//-1 is used to represent no edge between two vertices
	srand(time(0));
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			edge = (rand() % 20);
			if (edge > 5) {
				adj[i][j] = edge;
			} else {
				adj[i][j] = -1;
			}
			printf("%d\t", adj[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void initializeCost(int cost[n][n], int adj[n][n]) {
	// Initialize the cost matrix
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// Rest of the values will remain same.
			cost[i][j] = adj[i][j];
			
			// Replace all the negative values by infinity
			if (adj[i][j] == -1) {
				cost[i][j] = INF;
			}
			
			// Make all the diagonal values 0
			if (i == j) {
				cost[i][j] = 0;
			}
		}
	}
}

void initializeOthers(int distance[], int origin[], int processed[], int cost[n][n], int start) {
	// initialize 3 arrays
	
	// assign the distance array by taking the value from the "start" vertex row of the cost matrix
	for (int i = 0; i < n; i++) {
		distance[i] = cost[start][i];
	}
	
	// assign all of the original values as "start" vertex
	for (int i = 0; i < n; i++) {
		origin[i] = start;
	}
	
	// assign all of the processed values as 0
	for (int i = 0; i < n; i++) {
		processed[i] = 0;
	}
}

void dijkstra(int distance[], int origin[], int processed[], int cost[n][n], int start) {
	int i, j, mind, newnode, newcost;
	
	// Set the distance for start node as 0
	distance[start] = 0;
	
	// Add start node to the processed list by setting the processed[start] as 1
	processed[start] = 1;
	
	for (i = 0; i < n - 1; i++) {
		// Find the minimum distance (mind) among the vertices which are not processed yet.
		mind = INF;
		for (j = 0; j < n; j++) {
			if (!processed[j] && distance[j] < mind) {
				mind = distance[j];
				// Also find the vertex (newnode) containing that value.
				newnode = j;
			}
		}
		
		// Add the newnode into the processed list, by setting processed[newnode] as 1
		processed[newnode] = 1;
		
		// Update the distance of all the vertices which are not processed yet.
		for (j = 0; j < n; j++) {
			if (!processed[j]) {
				newcost = cost[newnode][j] + mind;
				if (newcost < distance[j]) {
					distance[j] = newcost;
					origin[j] = newnode;
				}
			}
		}
	}
}

int main() {
	int adj[MAX][MAX], cost[MAX][MAX];
	int distance[MAX], origin[MAX], processed[MAX], start;
	
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	printf("Enter the starting vertex: ");
	scanf("%d", &start);
	
	initializeGraph(adj);
	initializeCost(cost, adj);
	initializeOthers(distance, origin, processed, cost, start);
	dijkstra(distance, origin, processed, cost, start);
	printResult(distance, origin, start);
	return 0;
}
