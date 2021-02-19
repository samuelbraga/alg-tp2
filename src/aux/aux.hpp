#include <iostream> 
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include "./../subset/subset.hpp"
#include "./../graph/graph.hpp"
#ifndef __TP2_ALG___
#define __TP2_ALG__

using namespace std;

vector<int> getTuristIndexes();

int find(Subset subsets[], int i);

void Union(Subset subsets[], int x, int y);

int comparison(const void* a, const void* b);

void printResult(int length, Edge *result);

#endif