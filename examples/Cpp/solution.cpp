// ----------------------------------------------------------------------------
// ASSIGNMENT RESULT
// ----------------------------------------------------------------------------

#include <set>
#include "Open3D/Open3D.h"

using namespace open3d;

int main() {
    // Read triangle mesh "test_mesh.ply"
    geometry::TriangleMesh mesh;

    io::ReadTriangleMesh("test_mesh.ply", mesh);

    FILE *fp = fopen("results.txt", "w");

    std::list<std::list<unsigned int>> components = mesh.IdenticallyColoredConnectedComponents();
    for (auto component : components)
    {
        for (auto vertex : component)
        {
            fprintf(fp, "%d ", vertex);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    return 0;
}

