#include <iostream>

using namespace std;

class ComplexNumber
{
  private:
    double re;
    double im;
    double module;
    double angle;
    void init()
      {
        module = re * re + im * im;
        angle = atan(im / re);
      }

  public:
    ComplexNumber(double n_re=0; double n_im=0):n_re=re; n_im=im;{}
    ~ComplexNumber(){}
    ComplexNumber operator+(ComplexNumber number1, ComplexNumber number2);
    ComplexNumber operator-(ComplexNumber number1, ComplexNumber number2);
    ComplexNumber operator*(double koef);
    ComplexNumber operator*(ComplexNumber number2);
    void printComplex();
};

ComplexNumber ComplexNumber::operator+(ComplexNumber number1, ComplexNumber number2)
{
  return ComplexNumber(re + number2.re, im + number2.im);
}

ComplexNumber ComplexNumber::operator-(ComplexNumber number1, ComplexNumber number2)
{
  return ComplexNumber(re - number2.re, im - number2.im);
}

ComplexNumber ComplexNumber::operator*(double koef)
{
  return ComplexNumber(re * koef, im * koef);
}

ComplexNumber ComplexNumber::operator*(ComplexNumber number2)
{
  return ComplexNumber(re * n2.re - im * n2.im, re * n2.im + im * n2.re);
}

void ComplexNumber::printComplex()
{
  cout <<re;
  if(im>=0)
    cout<<"+";

  cout<<im<<"i"<endl;
}

int main()
{
  ComplexNumber n1(-1, 3);
  ComplexNumber n2(0, 5);
  n1.printComplex();
  n2.printComplex();

  return 0;
}

