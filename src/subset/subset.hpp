#include <iostream>
#ifndef __TP2_ALG___
#define __TP2_ALG__

class Subset {
  private:
    int parent;
    int rank;

  public:
    Subset();
    int getParent();
    void setParent(int value);
    int getRank();
    void setRank(int value);
};

#endif