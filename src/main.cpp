#include <bits/stdc++.h>
#include "./graph/graph.hpp"
#include "./subset/subset.hpp"
using namespace std;

int find(Subset subsets[], int i)
{
	if (subsets[i].getParent() != i)
		subsets[i].setParent(find(subsets, subsets[i].getParent()));

	return subsets[i].getParent();
}

void Union(Subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if (subsets[xroot].getRank() < subsets[yroot].getRank())
		subsets[xroot].setParent(yroot);
	else if (subsets[xroot].getRank() > subsets[yroot].getRank())
		subsets[yroot].setParent(xroot);

	else
	{
		subsets[yroot].setParent(xroot);
		int rank = subsets[xroot].getRank() + 1;
		subsets[xroot].setRank(rank);
	}
}

int myComp(const void* a, const void* b)
{
	Edge* a1 = (Edge*)a;
	Edge* b1 = (Edge*)b;
	return a1->getCost() > b1->getCost();
}

void printResult(int length, Edge *result)
{
	int minimumCost = 0;
	for (int j = 0; j < length; j++) 
		minimumCost = minimumCost + result[j].getCost();

	cout << minimumCost << endl;

	for (int j = 0; j < length; j++) 
	{
		cout  << result[j].getSource() 
					<< " "
					<< result[j].getDestination()
					<< " "
					<< result[j].getCost()
					<< endl;
	}
}


void KruskalMST(Graph* graph)
{
	int vertexLength = graph->getVertexLength();
	Edge result[vertexLength];
	int edges = 0;
	int i = 0;

	qsort(graph->getEdges(), graph->getEdgeLength(), sizeof(graph->getEdges()[0]),
          myComp);

	Subset* subsets = new Subset[(vertexLength * sizeof(Subset))];

	for (int j = 0; j < vertexLength; j++) 
	{
		subsets[j].setParent(j);
		subsets[j].setRank(0);
	}

	while (edges < vertexLength - 1 && i < graph->getEdgeLength()) 
	{
		Edge next_edge = graph->getEdges()[i++];

		int x = find(subsets, next_edge.getSource());
		int y = find(subsets, next_edge.getDestination());

		if (x != y)
		{
			result[edges++] = next_edge;
			Union(subsets, x, y);
		}
	}

	printResult(edges, result);
}

int main()
{
	int N;
	int T;

	scanf("%d %d", &N, &T);
	Graph* graph = new Graph(N, T);

	for(int i = 0; i < T; i++)
  {
		int p_i;
		int p_j;
		int c_t;

		scanf("%d %d %d", &p_i, &p_j, &c_t);

		graph->setStretch(i, p_i, p_j, c_t);
  }

	KruskalMST(graph);

	return 0;
}
