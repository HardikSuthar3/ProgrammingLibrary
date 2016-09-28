#include "Graph_Structure.h"

bool isCycle() {
    UFinit(V);
    for (int i = 0; i < edges.size(); i++) {
        if (Find(edges[i].first) == Find(edges[i].second)) return true;
        Union(edges[i].first, edges[i].second);
    }
    return false;
}