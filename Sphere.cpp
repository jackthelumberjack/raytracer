#include "Sphere.hpp"

using namespace rt;

Intersection Sphere::getIntersection(const Line& line,
                                     double minDist,
                                     double maxDist) {
  Intersection in;

  double A = line.dx()*line.dx();
  double B = line.dx()*(line.x0()-_center)*2;
  double C = (line.x0()-_center)*(line.x0()-_center)-(_radius*_radius);

  double dt = B*B-4*A*C;
  double t = 0;

  if (dt == 0) {
    t = (-B)/(2*A);
  } else if (dt > 0) {
    t = (-B-sqrt(dt))/(2*A);
    double t1 = (-B-sqrt(dt))/(2*A);
    if (t1 < t) {
      t = t1;
    }
  }

  if (t >= minDist && t <= maxDist) {
    in = Intersection(true, *this, line, t);
  }

  return in;
}

