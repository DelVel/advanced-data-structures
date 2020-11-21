#ifndef delvel_GRAPH
#define delvel_GRAPH

#include <vector>
#include <set>

using namespace std;

class Graph
{
public:
	virtual bool hasEdge(unsigned from, unsigned to) const = 0;

	virtual size_t getNodes() const = 0;

	virtual size_t getEdges() const = 0;

	virtual ~Graph() {}
};

class ModifiableGraph : public Graph
{
public:
	virtual bool addEdge(unsigned from, unsigned to) = 0;

	virtual bool removeEdge(unsigned from, unsigned to) = 0;
};

class AdjacencyListDirectedGraph : public ModifiableGraph
{
private:
	vector<set<unsigned>> _adjList;
	const size_t _nodes;

public:
	AdjacencyListDirectedGraph(size_t size) :_adjList(size, set<unsigned>()), _nodes(size) {}

	bool hasEdge(unsigned from, unsigned to) const override
	{
		return _adjList.at(from).count(to);
	}

	bool addEdge(unsigned from, unsigned to) override
	{
		return _adjList.at(from).insert(to).second;
	}

	bool removeEdge(unsigned from, unsigned to) override
	{
		return _adjList.at(from).erase(to);
	}

	size_t getNodes() const override
	{
		return _nodes;
	}

	size_t getEdges() const override
	{
		size_t res = 0;
		for (auto s : _adjList)
			res += s.size();
		return res;
	}
};

class AdjacencyListUndirectedGraph : public ModifiableGraph
{
private:
	vector<set<unsigned>> _adjList;
	const size_t _nodes;

public:
	AdjacencyListUndirectedGraph(size_t size) :_adjList(size, set<unsigned>()), _nodes(size) {}

	bool hasEdge(unsigned from, unsigned to) const override
	{
		if (from > to)
			swap(from, to);
		return _adjList.at(from).count(to);
	}

	bool addEdge(unsigned from, unsigned to) override
	{
		if (from > to)
			swap(from, to);
		return _adjList.at(from).insert(to).second;
	}

	bool removeEdge(unsigned from, unsigned to) override
	{
		if (from > to)
			swap(from, to);
		return _adjList.at(from).erase(to);
	}

	size_t getNodes() const override
	{
		return _nodes;
	}

	size_t getEdges() const override
	{
		size_t res = 0;
		for (auto s : _adjList)
			res += s.size();
		return res;
	}
};

#endif