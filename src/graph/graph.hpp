#include <iostream>
#include "./../edge/edge.hpp"
#ifndef __TP2_ALG___
#define __TP2_ALG__

using namespace std;

class Graph {
  private:
    int vertexLength;
    int edgeLength;
    Edge *edges;
    

  public:
    Graph(int vertexLength, int edgeLength);
    int getVertexLength();
    int getEdgeLength();
    Edge *getEdges();
    void setStretch(int index, Spot source, Spot destination, int weigh);
};

#endif