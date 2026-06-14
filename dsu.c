#include "dsu.h"

void initialize_dsu_pool(DisjointSetElement* set_pool, int count) {
    for (int i = 0; i < count; i++) {
        set_pool[i].parent_node = i;
        set_pool[i].coordinate_rank = 0;
    }
}

int find_representative_root(DisjointSetElement* set_pool, int target_node) {
    // Recursive Path Compression optimization step
    if (set_pool[target_node].parent_node != target_node) {
        set_pool[target_node].parent_node = find_representative_root(set_pool, set_pool[target_node].parent_node);
    }
    return set_pool[target_node].parent_node;
}

int perform_union_merge(DisjointSetElement* set_pool, int node_u, int node_v) {
    int root_u = find_representative_root(set_pool, node_u);
    int root_v = find_representative_root(set_pool, node_v);

    if (root_u != root_v) {
        // Union by Rank optimization step
        if (set_pool[root_u].coordinate_rank < set_pool[root_v].coordinate_rank) {
            set_pool[root_u].parent_node = root_v;
        } else if (set_pool[root_u].coordinate_rank > set_pool[root_v].coordinate_rank) {
            set_pool[root_v].parent_node = root_u;
        } else {
            set_pool[root_v].parent_node = root_u;
            set_pool[root_u].coordinate_rank++;
        }
        return 1; // Merge successful
    }
    return 0; // Already grouped in the same network block
}
