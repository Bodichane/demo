#include <iostream>

using namespace std;

class Polygon
(
  public:
  Polygon(){}
  virtual ~Polygon(){}
  virtual void ToString() = 0;
  virtual long getArea() = 0;
  virtual long getPerimeter() = 0;

  private:
);

class Square : public Square
{
  public:
  Square(){}
  ~Square(){}
  long ToString(){};
  long getArea(){return side * side;}
  long getPerimeter(){return side * 4;}

  private:
};

class Point
{
  public:
  Point(){}
  ~Point(){}
  Point operator==(Point x, Point y);
  Point operator!=(Point x,Point y);
  ostream &operator>>( ostream &flux, Point const& point);
  ostream &operator<<( ostream &flux, Point const& point);

};


int main()
{

  return 0;
}
