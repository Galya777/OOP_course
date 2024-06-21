#ifndef __POINT3D_HPP
#define __POINT3D_HPP

#include "point2d.hpp"

using DPoint2D = Point2D<double>;

class Point3D {
// double x, y, z;
// ниво 0
    DPoint2D p;
    double z;
public:
// ниво 1
    Point3D() {
        // !!! p.x = p.y = z = 0;
        p = DPoint2D();
        z = 0;
    }
    Point3D(double _x, double _y, double _z) {
        p = DPoint2D(_x, _y);
        z = _z;
    }
    Point3D(DPoint2D const& _p, double _z) { p = _p; z = _z; }

    // селектори
    DPoint2D getP() const { return p; }
    double getX() const { return p.getX(); }
    double getY() const { return p.getY(); }
    double getZ() const { return z; }

    void setP(DPoint2D const& _p) { p =  _p; }
    void setX(double _x) { p.setX(_x); }
    void setY(double _y) { p.setY(_y); }
    void setZ(double _z) { z = _z; }

// ниво 2:
    void print() const;
    void printnl() const;
    double distanceToOrigin() const;
    double distanceTo(Point3D const& other) const;

    void translate(double dx, double dy, double dz);
    void translate(Point3D const& vec);
};

#endif