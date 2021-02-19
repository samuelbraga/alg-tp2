#include "./spot.hpp"

Spot::Spot(int indice, int indiceTuristico)
{
  this->indice = indice;
  this->indiceTuristico = indiceTuristico;
}

int Spot::getIndice() { return this->indice; }

void Spot::setIndice(int value) { this->indice = value; }

int Spot::getIndiceTuristico() { return this->indiceTuristico; }

void Spot::setIndiceTuristico(int value) { this->indiceTuristico = value; }