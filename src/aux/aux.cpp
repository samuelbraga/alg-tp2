#include "./aux.hpp"

vector<int> getTuristIndexes()
{
  string line;
  vector<int> indexes;

  getline(cin, line);
  istringstream iss(line);

  for (string s; iss >> s;)
  {
    int value = atoi(s.c_str());
		indexes.push_back(value);
  }

  return indexes;
}

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

int comparison(const void* a, const void* b)
{
	Edge* a1 = (Edge*)a;
	Edge* b1 = (Edge*)b;

  int sumTuristIndexA = a1->getSumIndexDestination();
  int sumTuristIndexB = b1->getSumIndexDestination();

  bool condition = a1->getCost() > b1->getCost() ||
                  (a1->getCost() >= b1->getCost() &&
                  sumTuristIndexA < sumTuristIndexB);
  
	return condition;
}

struct compareEdge {
  bool operator()(Edge *lhs, Edge *rhs)
  {
    return lhs->getSource().getIndex() < rhs->getSource().getIndex();
  }
};

void printResult(int length, Edge *result)
{
  map<int, Edge> results;

	int minimumCost = 0;
  int sumTuristIndex = 0;
	for (int j = 0; j < length; j++)
  {
		minimumCost = minimumCost + result[j].getCost();
    sumTuristIndex = sumTuristIndex + result[j].getSumIndexDestination();
    results.insert(pair<int, Edge>(result[j].getSource().getIndex(), result[j]));
  }

	cout << minimumCost << " " << sumTuristIndex << endl;

	for (int j = 0; j < length; j++) 
	{
		cout  << result[j].getSource().getIndex()
					<< " "
					<< result[j].getDestination().getIndex()
					<< " "
					<< result[j].getCost()
					<< endl;
	}
}