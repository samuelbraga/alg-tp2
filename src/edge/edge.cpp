#include "./edge.hpp"

Edge::Edge() {}

Edge::Edge(Spot source, Spot destination, int cost)
{
  this->source = source;
  this->destination = destination;
  this->cost = cost;
}

Spot Edge::getSource() { return this->source; }

void Edge::setSource(Spot value) { this->source = value; }

Spot Edge::getDestination() { return this->destination; }

void Edge::setDestination(Spot value) { this->destination = value; }

int Edge::getCost() { return this->cost; }

void Edge::setCost(int value) { this->cost = value; }

int Edge::getSumIndexDestination() { return this->source.getTuristIndex() + this->destination.getTuristIndex(); }
