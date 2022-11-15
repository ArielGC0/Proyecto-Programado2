//The necessary libraries are called
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store a graph object
struct graph{
    // An array of pointers to Node to represent an adjacency list
    struct nodeG* head;
};
 
// Data structure to store adjacency list nodes of the graph
struct nodeG{
    int dest, weight;
    struct nodeG* next;
};
 
// Data structure to store a graph edge
struct edge{
    int src, dest, weight;
};
