#include "Graph_Structure.h"

// Minimum Spanning Tree

int minElement(vector<int> dist) {
   int mindist = INT_MAX;
   int minInd = 0;
   for (int i = 0; i < V; i++) // start i = 1 if vertice starts from 1
   {
      if (dist[i] < mindist && !used[i]) {
         mindist = dist[i];
         minInd = i;
      }
   }
   return minInd;
}

void primMst(int r) {
   vector<int> dist(V);
   fill(dist.begin(), dist.end(), INT_MAX);
   dist[r] = 0;
   function<bool(int &, int &)> compare([&](int &u, int &v) -> bool { return (dist[u] > dist[v]); });
   priority_queue<int, vector<int>, decltype(compare)> ind(compare);
   ind.push(r);
   long total_distance = 0;
   int count = 0;
   while (count < V - 1) { // V if starting index of vertice is 0
      int u = minElement(dist);
      used[u] = true;
      total_distance += dist[u];
      for (int i = 0; i < G[u].size(); ++i) {
         int eno = G[u][i];
         pair<int, int> p = edges[eno];
         int adj = p.first ^p.second ^u;
         float w = W[eno].second;
         if (dist[adj] > w) {
            dist[adj] = w;
         }
      }
      count++;
   }
   cout << total_distance;
}

void krushkalsMst() {
   function<bool(pair < int, float > &, pair < int, float > &)>
         compare([](pair<int, float> &x, pair<int, float> &y) -> bool { return (x.second < y.second); });
   UFinit(V);
   sort(W.begin(), W.end(), compare);
   int i = 0, edgecount = 0;  // Number of Edges in solution

   vector <pair<int, int>> outputVertices;
   vector<float> mstEdges;

   // N vertice tree has N-1 edges
   while (edgecount < V - 2) { // V if vertice starts from 0
      int eid = W[i].first;
      if (Find(edges[eid].first) != Find(edges[eid].second)) {
         Union(edges[eid].first, edges[eid].second);
         outputVertices.push_back(edges[eid]);
         mstEdges.push_back(W[i].second);
         edgecount++;
      }
      i++;
   }
   int total_weight = 0;
   for (int i = 0; i < outputVertices.size(); i++) {
      total_weight += mstEdges[i];
   }
   cout << total_weight;
}
