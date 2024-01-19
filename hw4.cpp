//Yunsung Choi
//hw4.cpp
//test driver program for graph.cpp

#include "graph.h"


int main(){

    string inputFileName;
    cout << "Enter the input file name: ";
    cin >> inputFileName;

    Graph graph;
    graph.load(const_cast<char*>(inputFileName.c_str()));

    cout << "Adjacency Matrix:" << endl;
    graph.display();

    cout << "DFS starting at vertex 0: ";
    graph.displayDFS(0);
    cout << endl;

    cout << "BFS starting at vertex 0: ";
    graph.displayBFS(0);
    cout << endl;

    return 0;
}
