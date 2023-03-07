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
  virtual void read(std::ostream &flux) = 0;
  ostream &operator<<( ostream &flux, Polygon const& polygon);


  private:
);

class Square : public Square
{
  public:
  Square(int m_side): m_side = side{}
  ~Square(){}
  long ToString(){};
  long getArea(){return side * side;}
  long getPerimeter(){return side * 4;}

  private:
  int side;
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
