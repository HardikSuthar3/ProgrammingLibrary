#include "Graph_Structure.h"

bool isMColor(int m, int v) {
    static vector<int> col(V);
    if (v > V) return true;
    for (int c = 1; c <= m; ++c) {
        bool flg = true;
        for (int i = 0; i < G[v].size(); i++) {
            int eno = G[v][i];
            int adj = edges[eno].first ^edges[eno].second ^v;
            if (col[adj] == c) {
                flg = false;
                break;
            }
        }
        if (!flg)
            continue;
        else {
            col[v] = c;
            if (isMColor(m, v + 1) == true) return true;
            col[v] = -1;
        }
    }
    return false;
}