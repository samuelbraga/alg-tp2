#include <iostream>
#ifndef __TP2_ALG___
#define __TP2_ALG__

using namespace std;

class Edge
{
  private:
    int source;
    int destination;
    int weight;

  public:
    Edge();
    Edge(int source, int destination, int weight);
    int getSource();
    void setSource(int value);
    int getDestination();
    void setDestination(int value);
    int getWeight();
    void setWeight(int value);
};

#endif