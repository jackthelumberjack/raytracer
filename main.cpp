#include <cmath>
#include <iostream>
#include <string>

#include "Vector.hpp"
#include "Line.hpp"
#include "Geometry.hpp"
#include "Sphere.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include "Intersection.hpp"
#include "Material.hpp"

#include "Scene.hpp"

using namespace std;
using namespace rt;

double imageToViewPlane(int n, int imgSize, double viewPlaneSize) {
  double u = (double)n*viewPlaneSize/(double)imgSize;
  u -= viewPlaneSize/2;
  return u;
}

const Intersection findFirstIntersection(const Line& ray,
                                         double minDist, double maxDist) {
  Intersection intersection;

  for(int i=0; i<geometryCount; i++) {
    Intersection in = scene[i]->getIntersection(ray, minDist, maxDist);
    if(in.valid()) {
      if(!intersection.valid()) {
        intersection = in;
      }
      else if(in.t() < intersection.t()) {
        intersection = in;
      }
    }
  }

  return intersection;
}

int main() {
  Vector viewPoint(0, 0, 0);
  Vector viewDirection(0, 0, 1);
  Vector viewUp(0, -1, 0);

  double frontPlaneDist = 2;
  double backPlaneDist = 1000;

  double viewPlaneDist = 100;
  double viewPlaneWidth = 200;
  double viewPlaneHeight = 100;

  int imageWidth = 1000;
  int imageHeight = 500;

  Vector viewParallel = viewUp^viewDirection;

  viewDirection.normalize();
  viewUp.normalize();
  viewParallel.normalize();

  Image image(imageWidth, imageHeight);

  for (int x = 0; x < imageWidth; x++) {
    for (int y = 0; y < imageHeight; y++) {
      Vector x1(viewPoint + viewDirection*viewPlaneDist + viewUp*imageToViewPlane(y, imageHeight, viewPlaneHeight) +
          viewParallel*imageToViewPlane(x, imageWidth, viewPlaneWidth));

      Vector x0(viewPoint.x(), viewPoint.y(), viewPoint.z());

      Line ray(x0, x1, false);

      for (int p=0; p < geometryCount; p++) {
        Intersection first = findFirstIntersection(ray, frontPlaneDist, backPlaneDist);
        if (first.valid()) {
          Color color = first.geometry().color();
          image.setPixel(x, y, color);
        }
      }

    }
  }

  image.store("C:\\Users\\breba\\Downloads\\scene.ppm");

  for(int i=0; i<geometryCount; i++) {
    delete scene[i];
  }

  return 0;
}