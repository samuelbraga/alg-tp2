#include <iostream>
#ifndef __TP2_ALG___
#define __TP2_ALG__

using namespace std;

class Spot {
  private:
    int index;
    int turistIndex;
    
  public:
    Spot();
    Spot(int index, int turistIndex);
    int getIndex();
    void setIndex(int value);
    int getTuristIndex();
    void setTuristIndex(int value);
    int getEdgeLength();
};

#endif