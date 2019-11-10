# Open3D: www.open3d.org
# The MIT License (MIT)
# See license file or visit www.open3d.org for details

# examples/Python/Basic/solution.py

import copy
import numpy as np
import open3d as o3d

if __name__ == "__main__":

    print("Reading test mesh ...")
    mesh = o3d.io.read_triangle_mesh("test_mesh.ply")

    print("Extracting same color components ...")
    result = mesh.identically_colored_connected_components()

    print(result)

    with open("results.txt", 'w') as fp:
        for items in result:
            for val in items:
                fp.write('%d ' % val)
            fp.write('\n')

