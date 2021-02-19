#include "./edge.hpp"

Edge::Edge() {}

Edge::Edge(int source, int destination, int cost)
{
  this->source = source;
  this->destination = destination;
  this->cost = cost;
}

int Edge::getSource() { return this->source; }

void Edge::setSource(int value) { this->source = value; }

int Edge::getDestination() { return this->destination; }

void Edge::setDestination(int value) { this->destination = value; }

int Edge::getCost() { return this->cost; }

void Edge::setCost(int value) { this->cost = value; }