#include "./aux/aux.hpp"

using namespace std;

void KruskalMST(Graph* graph)
{
	int vertexLength = graph->getVertexLength();
	Edge result[vertexLength];
	int edges = 0;
	int i = 0;

	qsort(graph->getEdges(),
				graph->getEdgeLength(),
				sizeof(graph->getEdges()[0]),
        comparison);

	Subset* subsets = new Subset[(vertexLength * sizeof(Subset))];

	for (int j = 0; j < vertexLength; j++) 
	{
		subsets[j].setParent(j);
		subsets[j].setRank(0);
	}

	while (edges < vertexLength - 1 && i < graph->getEdgeLength()) 
	{
		Edge next_edge = graph->getEdges()[i++];

		int x = find(subsets, next_edge.getSource().getIndex());
		int y = find(subsets, next_edge.getDestination().getIndex());

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

	Spot *spots = new Spot[N];

  // Ocorre um bug que na primeira entrada do getline()
  // ela não realiza o input das entradas. Dessa forma, adicionei essa
  // primeira entrada para evitar inconsistencia na lógica
	vector<int> turistIndexes = getTuristIndexes();
	turistIndexes = getTuristIndexes();

	vector<int>::iterator it;
	int i = 0;
  for(it = turistIndexes.begin(); it != turistIndexes.end(); ++it)
	{
		Spot spot = Spot(i, *it);

		spots[i] = spot;
		i++;
	}

	Graph* graph = new Graph(N, T);

	for(int i = 0; i < T; i++)
  {
		int p_i;
		int p_j;
		int c_t;

		scanf("%d %d %d", &p_i, &p_j, &c_t);

		graph->setStretch(i, spots[p_i], spots[p_j], c_t);
  }

	KruskalMST(graph);

	return 0;
}
