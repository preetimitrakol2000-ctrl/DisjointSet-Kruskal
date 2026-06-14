#include <stdio.h>
#include "dsu.h"

extern int process_mesh_connectivity(DisjointSetElement* pool, int u, int v);

int main() {
    printf("🕸️  Activating DisjointSet-Kruskal Sensor Partition Subsystem...\n\n");

    int node_count = 4;
    DisjointSetElement cluster_pool[4];
    initialize_dsu_pool(cluster_pool, node_count);

    // Simulate sorting communication link costs between edge sensors
    printf("📥 Connecting Channel: Sensor [0] <---> Sensor [1]\n");
    process_mesh_connectivity(cluster_pool, 0, 1);

    printf("📥 Connecting Channel: Sensor [2] <---> Sensor [3]\n");
    process_mesh_connectivity(cluster_pool, 2, 3);

    printf("\n🔮 Verifying Graph Cluster Components:\n");
    if (find_representative_root(cluster_pool, 0) == find_representative_root(cluster_pool, 1)) {
        printf("   ✅ Sensor 0 and Sensor 1 belong to the same local subnet component.\n");
    }
    if (find_representative_root(cluster_pool, 0) != find_representative_root(cluster_pool, 2)) {
        printf("   🚨 Sensor 0 and Sensor 2 are completely isolated across mesh groups.\n");
    }

    return 0;
}
