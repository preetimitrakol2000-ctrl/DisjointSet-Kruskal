#ifndef DSU_H
#define DSU_H

typedef struct {
    int parent_node;
    int coordinate_rank;
} DisjointSetElement;

void initialize_dsu_pool(DisjointSetElement* set_pool, int count);
int find_representative_root(DisjointSetElement* set_pool, int target_node);
int perform_union_merge(DisjointSetElement* set_pool, int node_u, int node_v);

#endif
