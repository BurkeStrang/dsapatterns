#include "unionfind/shared.hpp"

#include "testing/testing.hpp"

int main()
{
    t::run("union find");
    UnionFind uf(5);
    t::check("connected(0, 1) before any union", uf.connected(0, 1), false);

    uf.unite(0, 1);
    uf.unite(3, 4);
    uf.unite(1, 1);
    t::check("connected(0, 1) after unite(0, 1)", uf.connected(0, 1), true);
    t::check("connected(1, 3)", uf.connected(1, 3), false);

    uf.unite(1, 4);
    t::check("connected(0, 3) after joining both sets", uf.connected(0, 3),
             true);
    t::check("connected(2, 0)", uf.connected(2, 0), false);
    return t::done();
}
