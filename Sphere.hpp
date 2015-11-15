#include "Vector.hpp"
#include "Line.hpp"
#include "Intersection.hpp"
#include "Geometry.hpp"
#include "Color.hpp"

#ifndef RT_SPHERE_INCLUDED
#define RT_SPHERE_INCLUDED

namespace rt {

  class Sphere : public Geometry {
  private:
    Vector _center;
    double _radius;

  public:
    Sphere(const Vector& center, double radius, const Color& color, const Color& ambient, const Color& diffuse,
           const Color& specular, double shininess, double opacity, double reflectivity, double lightIntensity)
    : Geometry(color, ambient, diffuse, specular, shininess, opacity, reflectivity, lightIntensity) {
      _center = Vector(center);
      _radius = radius;
    }

    Sphere(double x, double y, double z, double radius,
           const Color& color, const Color& ambient, const Color& diffuse, const Color& specular,
           double shininess, double opacity, double reflectivity, double lightIntensity)
    : Geometry (color, ambient, diffuse, specular, shininess, opacity, reflectivity, lightIntensity) {
      _center = Vector(x, y, z);
      _radius = radius;
    }

    virtual Intersection getIntersection(const Line& line, 
                                         double minDist,
                                         double maxDist);

    inline double& radius() {
      return _radius;
    }

    inline Vector& center() {
      return _center;
    }
  };
}

#endif
