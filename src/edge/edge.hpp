#include <iostream>
#ifndef __TP2_ALG___
#define __TP2_ALG__

using namespace std;

class Edge
{
  private:
    int source;
    int destination;
    int cost;

  public:
    Edge();
    Edge(int source, int destination, int cost);
    int getSource();
    void setSource(int value);
    int getDestination();
    void setDestination(int value);
    int getCost();
    void setCost(int value);
};

#endif