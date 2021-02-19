#include "./spot.hpp"

Spot::Spot() {}

Spot::Spot(int index, int turistIndex)
{
  this->index = index;
  this->turistIndex = turistIndex;
}

int Spot::getIndex() { return this->index; }

void Spot::setIndex(int value) { this->index = value; }

int Spot::getTuristIndex() { return this->turistIndex; }

void Spot::setTuristIndex(int value) { this->turistIndex = value; }