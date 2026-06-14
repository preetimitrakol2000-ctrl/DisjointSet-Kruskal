// Structural routing abstraction linking cluster constraints
#include "dsu.h"
int process_mesh_connectivity(DisjointSetElement* pool, int u, int v) {
    return perform_union_merge(pool, u, v);
}
