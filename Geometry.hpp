#include "Color.hpp"
#include "Vector.hpp"
#include "Line.hpp"
#include "Intersection.hpp"
#include "Material.hpp"

#ifndef RT_GEOMETRY_INCLUDED
#define RT_GEOMETRY_INCLUDED

namespace rt {

  class Geometry {
  private:
    Color _color;
    Color _ambient;
    Color _diffuse;
    Color _specular;
    double _shininess;
    double _opacity;
    double _reflectivity;
    double _lightIntensity;

  public:
    Geometry(const Color& color, const Color& ambient, const Color& diffuse, const Color& specular,
             double shininess, double opacity, double reflectivity, double lightIntensity) {
      _color = Color(color);
      _ambient = Color(ambient);
      _diffuse = Color(diffuse);
      _specular = Color(specular);
      _shininess = shininess;
      _opacity = opacity;
      _reflectivity = reflectivity;
      _lightIntensity = lightIntensity;
    }

    Geometry(const Geometry& geometry) {
      _color = Color(geometry.color());
      _ambient = Color(geometry.ambient());
      _diffuse = Color(geometry.diffuse());
      _specular = Color(geometry.specular());

      _shininess = geometry.shininess();
      _opacity = geometry.opacity();
      _reflectivity = geometry.reflectivity();
      _lightIntensity = geometry.lightIntensity();
    }

    virtual Intersection getIntersection(const Line& line, 
                                         double minDist,
                                         double maxDist) {
      Intersection in(false, *this, line, 0);
      return in;
    };

    inline Color color() const {
      return _color;
    }

    inline Color ambient() const {
      return _ambient;
    }

    inline Color diffuse() const {
      return _diffuse;
    }

    inline Color specular() const {
      return _specular;
    }

    inline double shininess() const {
      return _shininess;
    }

    inline double opacity() const {
      return _opacity;
    }

    inline double reflectivity() const {
      return _reflectivity;
    }

    inline double lightIntensity() const {
      return _lightIntensity;
    }
  };
}

#endif
