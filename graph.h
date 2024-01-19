//Yunsung Choi
//graph.h
//graph ADT

#include<iostream>
#include <fstream>
#include <queue>
using namespace std;
#ifndef GRAPH_H
#define GRAPH_H

class Graph{
    private:
    // number of vertices
    int numVertices;

    //2D
    int **adjMatrix;

    public:
    //constructor
    Graph();

    //destructor
    ~Graph();

    //creates the graph using the file passed into the function
    void load(char *filename);

    //Displays the graph's adjacency matrix to the screen.
    void display();

    //Displays the result of a DFS starting at the provided vertex.
    //Pick the vertex with the lower number first.
    //RECURSION!
    void displayDFS(int vertex);

    //Displays the result of a BFS starting at the provided vertex.
    //Pick the vertex with the lower number first.
    void displayBFS(int vertex);

    private:
    //helper method for displayDFS function.
    //The actual recursion takes place here.
    void DFS(int vertex, bool* visited);



};
#endif