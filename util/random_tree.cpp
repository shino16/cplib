#pragma once

VVI makeGraph(int prufer[], int m) {
  int n = m + 2;
  VI vertex_set(n);
  vector<PII> edges;

  rep(i, m) vertex_set[prufer[i] - 1]++;

  rep(i, m) {
    rep(j, n) if (vertex_set[j] == 0) {
      vertex_set[j] = -1;
      edges.emplace_back(j, prufer[i] - 1);
      vertex_set[prufer[i] - 1]--;
      break;
    }
  }

  VI rest;
  rep(i, n) if (vertex_set[i] == 0) rest.push_back(i);
  edges.emplace_back(rest[0], rest[1]);

  VVI graph(n);
  for (auto p : edges) graph[p._1].push_back(p._2), graph[p._2].push_back(p._1);

  return graph;
}

int ran(int l, int r) {
  int res = l + (rand() % (r - l + 1));
  return res;
}

VVI generateRandomTree(int n) {
  int length = n - 2;
  int arr[length];

  for (int i = 0; i < length; i++) {
    arr[i] = ran(0, pow(2, i)) + 1;
  }
  return makeGraph(arr, length);
}
