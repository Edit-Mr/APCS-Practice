class UnionFind:
    def __init__(self, size):
        self.parent = list(range(size))
        self.rank = [1] * size

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])
        return self.parent[u]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u != root_v:
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1

def kruskal(n, edges, exclude_edge=None, include_edge=None):
    uf = UnionFind(n)
    mst_weight = 0
    mst_edges = []
    
    if include_edge:
        u, v, w = include_edge
        uf.union(u, v)
        mst_weight += w
        mst_edges.append(include_edge)
    
    for u, v, w in sorted(edges, key=lambda x: x[2]):
        if (u, v, w) == exclude_edge:
            continue
        if uf.find(u) != uf.find(v):
            uf.union(u, v)
            mst_weight += w
            mst_edges.append((u, v, w))
    
    if len(mst_edges) == n - 1:
        return mst_weight
    else:
        return float('inf')

def minimum_toll_fees(n, m, roads):
    mst_edges = []
    mst_weight = kruskal(n, roads)
    
    results = []
    for i in range(m):
        u, v, w = roads[i]
        min_weight = kruskal(n, roads, exclude_edge=(u, v, w), include_edge=(u, v, w))
        results.append(min_weight)
    
    return results


M, N = map(int, input().split())
roads = []
index = 2
for _ in range(M):
    data = input().split()
    Ui = int(data[index]) - 1
    Vi = int(data[index + 1]) - 1
    Wi = int(data[index + 2])
    roads.append((Ui, Vi, Wi))
    index += 3

result = minimum_toll_fees(N, M, roads)
for res in result:
    print(res)
