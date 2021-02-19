#include "./subset.hpp"

Subset::Subset() { }

int Subset::getParent() { return this->parent; }

void Subset::setParent(int value) { this->parent = value; }

int Subset::getRank() { return this->rank; }

void Subset::setRank(int value) { this->rank = value; }