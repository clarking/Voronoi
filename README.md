# VoronoiGen

---------------------------------------------------

##  Mark Dally's Voronoi C++ library fork adapted for linux.

### For the Windows version refer to the original version at: https://github.com/mdally/Voronoi 

##Compile using cmake


### Usage:
compute the diagram for a set of sites and a bounding box
```cpp
VoronoiGenerator::compute(std::vector<Point2>& sites, BoundingBox bbox);
```

perform Lloyd's relaxation on the diagram last computed
```cpp
VoronoiGenerator::relax();
```

### Notes:
 * This branch uses cmake for build

 * CLion was used instead of Visual Studio

 * This implementation generates a diagram within a bounding box. The box must be provided, and all voronoi cells will be closed, unlike a general implementation for an open plane.
 
 * It is your responsibility to ensure that there are no duplicate sites or sites that fall outside or on the borders of the bounding box.
	
 * Performing Lloyd's relaxation returns a new diagram but does not delete the original. You must delete the old one in order to avoid memory leaks.

 * The 'opengl_example' program requires OpenGL and [GLFW](http://www.glfw.org). 
 
