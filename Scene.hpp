#include "Geometry.hpp"
#include "Sphere.hpp"

using namespace rt;

int geometryCount = 8;

Color ambient(0.1,0.1,0.1);
Color diffuse(0.4,0.4,0.3);
Color specular(0.5,0.5,0.5);

Geometry* scene[] = {
  new Sphere(-50, -25, 175, 30, Color(1,0,0), ambient, diffuse, specular, 100, 0.5, 0.5, 0),
  new Sphere(-10,   0, 100, 10, Color(1,1,0), ambient, diffuse, specular, 100, 0.5, 0.5, 0),
  new Sphere(  0,   0, 200, 40, Color(0,1,0), ambient, diffuse, specular, 100, 0.5, 0.5, 0),
  new Sphere(  0, -50, 200, 10, Color(1,1,1), ambient, diffuse, specular, 100, 0.5, 0.5, 0),
  new Sphere( 10,   0,  20,  5, Color(0,1,1), ambient, diffuse, specular, 100, 0.5, 0.5, 0),
  new Sphere(-70,   0, 100, 10, Color(1,0,1), ambient, diffuse, specular, 100, 0.5, 0.5, 0),
  new Sphere( 50,  25,  75, 50, Color(0,0,1), ambient, diffuse, specular, 100, 0.5, 0.5, 0),
  new Sphere(-100,  50,  100, 5, Color(1,1,1), Color(1,1,1), Color(1,1,1), Color(1,1,1), 0.5, 0.5, 0.5, 1),
  new Sphere(-50,  50,  100, 5, Color(1,1,1), Color(1,1,1), Color(1,1,1), Color(1,1,1), 0.5, 0.5, 0.5, 1)
};
