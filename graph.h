#ifndef delvel_GRAPH
#define delvel_GRAPH

#include <vector>
#include <set>
#include <stdexcept>

using namespace std;

class Graph
{
private:
	vector<set<unsigned>> _adjList;

public:
	Graph(size_t size) :_adjList(size, set<unsigned>()) {}

	bool hasEdge(const unsigned from, const unsigned to) const
	{
		if (_adjList.size() <= from)
			return false;
		return _adjList.at(from).count(to);
	}
};

#endif