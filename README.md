# DisjointSet-Kruskal

A pure C99 network layout engine designed to minimize structural wiring and transmission costs in distributed IoT environments. This repository implements a **Disjoint Set Union (DSU)** from scratch to construct a Minimum Spanning Tree (MST) using Kruskal's Algorithm, optimizing communication routes across nodes.

## 📊 Algorithmic Architecture
* **Data Structure:** Disjoint Set Union (DSU) flat tracking array.
* **Optimizations:** Recursive Path Compression and Union by Rank.
* **Time Complexity:** $O(E \log E)$ for initial edge sorting, followed by near-constant $O(E \cdot \alpha(V))$ processing bounds via Ackermann inverse processing.

## 📦 Compilation & Execution
```bash
gcc main.c dsu.c kruskal.c -o dsu_kruskal -lm
./dsu_kruskal
