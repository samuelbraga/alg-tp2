#include "./graph.hpp"

Graph::Graph(int vertexLength, int edgeLength)
{
  this->vertexLength = vertexLength;
  this->edgeLength = edgeLength;

	this->edges = new Edge[this->edgeLength];
}

int Graph::getVertexLength() { return this->vertexLength; }

int Graph::getEdgeLength() { return this->edgeLength; }

Edge *Graph::getEdges() { return this->edges; }

void Graph::setStretch(int index, int source, int destination, int weigh)
{
  edges[index].setSource(source);
  edges[index].setDestination(destination);
  edges[index].setWeight(weigh);
}
