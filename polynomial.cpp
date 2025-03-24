#include "polynomial.hpp"
#include <fstream>
#include <cmath>

Polynomial::
Polynomial(const std::vector<real>& c) {
  _coeffs = c;
}

Polynomial::
Polynomial(const Polynomial& that) {
  _coeffs = that._coeffs;
}

int Polynomial::
degree () const {
  return _coeffs.size()-1;
}

real Polynomial::
eval(const real x) const {

  int n = this->degree();
  real res = _coeffs[n];
  for (int i=n-1;i>=0; i--) {
    res *= x;
    res += _coeffs[i]; 
  }
  return res;

}

real Polynomial::
evalDeriv(const real x) const {

  int n = degree();
  real res = n*_coeffs[n];
  for (int i=n-1;i>=1; i--) {
    res *= x;
    res += i*_coeffs[i];
  }
  return res;

}
void Polynomial::
display() {
  for (real c:_coeffs)
    std::cout << c << " ";
  std::cout << std::endl;
}
//
Polynomial Polynomial::getDerivPolynomial(){
  Polynomial q;
  q._coeffs.resize(_coeffs.size() - 1);
  for(int i = 0;i<q._coeffs.size();i++){
    q._coeffs[i] = (i+1)*_coeffs[i+1];
  }
  return q;
}
//

void Polynomial::save(const std::vector<real>& x,const std::string filename
,bool deriv){
  std::ofstream os(filename);

  if(deriv){
    for(int i = 0;i<x.size();i++){
      os << x[i] << "  " << evalDeriv(x[i]) << std::endl;
    }
  }
  else{
    for(int i = 0;i<x.size();i++){
      os << x[i] << "  " << eval(x[i]) << std::endl;
    }
  }
};