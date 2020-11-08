#ifndef delvel_DISJOINTSET
#define delvel_DISJOINTSET

#include <vector>
#include <numeric>

using namespace std;

/**
    Disjoint set.

    Implemented with path halving & merge by rank, assuring the time complexity of Inverse Ackermann function.
    Only receives data of unsigned int, and does not allow to take 0 elements.
*/
class DisjointSet
{
private:
    size_t _num;
    vector<unsigned> _rank;
    mutable vector<unsigned> _parent;

public:
    DisjointSet(size_t n) : _num(n), _rank(n, 0), _parent(n)
    {
        if (n == 0)
            throw "0 length disjoint set.";
        iota(_parent.begin(), _parent.end(), 0);
    }

    unsigned parentOf(unsigned index) const noexcept
    {
        // Path halving
        while (_parent[_parent[index]] != _parent[index])
            index = (_parent[index] = _parent[_parent[index]]);
        return _parent[index];
    }

    bool merge(unsigned A, unsigned B) noexcept
    {
        int AInd = parentOf(A);
        int BInd = parentOf(B);

        if (AInd == BInd)
            return false;

        // Merge by rank
        if (_rank[BInd] > _rank[AInd])
            swap(AInd, BInd);

        _parent[BInd] = AInd;

        if (_rank[AInd] == _rank[BInd])
            _rank[AInd]++;

        _num--;

        return true;
    }

    size_t countDisjoints() const noexcept
    {
        return _num;
    }
};

#endif
