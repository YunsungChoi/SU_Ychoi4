//Yunsung Choi
//graph.cpp
//implementation of graph ADT

#include "graph.h"

//public
Graph::Graph(){
    numVertices = 0;
    adjMatrix = nullptr;
}

Graph::~Graph(){
    if(adjMatrix != nullptr){
        for (int i=0; i < numVertices; i++){
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
}

void Graph::load(char* filename){
    ifstream inputFile;
    inputFile.open(filename);
    if(!inputFile.is_open()){
        cout << "Cannot Open the File:  " << filename << endl;
        return;
    }

    inputFile >> numVertices; // first integer indicates how many vertices presents in the graph
    adjMatrix = new int* [numVertices]; //dynamic memory allocation
    for(int i =0; i < numVertices; i ++){
        adjMatrix[i] = new int[numVertices];
        for (int j=0; j < numVertices; j++){
            adjMatrix[i][j] = 0; // initialize with 0
        }
    }

    int vertex1, vertex2;
    while(inputFile >> vertex1 >> vertex2){
        if (vertex1 >= 0 && vertex1 < numVertices && vertex2 >=0 && vertex2 < numVertices){
            adjMatrix[vertex1][vertex2] = 1;
            adjMatrix[vertex2][vertex1] = 1; // adding edge
        }
    }
    inputFile.close();
}

void Graph::display(){
    for (int i = 0; i < numVertices; i++){
        for (int j = 0; j < numVertices; j++){
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::displayDFS(int vertex){
    bool* visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++){
        visited[i] = false; //initialize to flase.
    }
    DFS(vertex, visited);
    delete[] visited;
}

void Graph::displayBFS(int vertex){
    queue<int> bfsQueue;

    bool* visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++){
        visited[i] = false; //initialize to flase.
    }

    visited[vertex] = true;
    bfsQueue.push(vertex);

    while(!bfsQueue.empty()){
        int currentVertex = bfsQueue.front();
        bfsQueue.pop();
        cout << currentVertex << "  ";
        
        for(int i = 0; i < numVertices; i++){
            if(adjMatrix[currentVertex][i] == 1 && !visited[i]){
                visited[i] = true;
                bfsQueue.push(i);
            }
        }
    }
    delete[] visited;
}

//private
void Graph::DFS(int vertex, bool* visited){
    visited[vertex] = true;
    cout << vertex << "  ";

    for (int i = 0; i < numVertices; i++){
        if (adjMatrix[vertex][i] ==1 && !visited[i])
        DFS(i, visited);
    }
}
