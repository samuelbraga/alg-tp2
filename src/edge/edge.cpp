#include "./edge.hpp"

Edge::Edge() {}

Edge::Edge(int source, int destination, int weight)
{
  this->source = source;
  this->destination = destination;
  this->weight = weight;
}

int Edge::getSource() { return this->source; }

void Edge::setSource(int value) { this->source = value; }

int Edge::getDestination() { return this->destination; }

void Edge::setDestination(int value) { this->destination = value; }

int Edge::getWeight() { return this->weight; }

void Edge::setWeight(int value) { this->weight = value; }