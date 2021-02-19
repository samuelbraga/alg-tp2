#include <iostream>
#include "./../spot/spot.hpp"
#ifndef __TP2_ALG___
#define __TP2_ALG__

using namespace std;

class Edge
{
  private:
    Spot source;
    Spot destination;
    int cost;

  public:
    Edge();
    Edge(Spot source, Spot destination, int cost);
    Spot getSource();
    void setSource(Spot value);
    Spot getDestination();
    void setDestination(Spot value);
    int getCost();
    void setCost(int value);
    int getSumIndexDestination();
};

bool operator<(const Edge &a, const Edge &b);

#endif