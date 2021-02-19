#include <iostream>
#ifndef __TP2_ALG___
#define __TP2_ALG__

using namespace std;

class Spot {
  private:
    int indice;
    int indiceTuristico;
    
  public:
    Spot(int indice, int indiceTuristico);
    int getIndice();
    void setIndice(int value);
    int getIndiceTuristico();
    void setIndiceTuristico(int value);
    int getEdgeLength();
};

#endif