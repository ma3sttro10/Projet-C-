#ifndef _POLYNOMIAL_HPP_
#define _POLYNOMIAL_HPP_
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using real = double;

// A class to represent real-valued polynomials
class Polynomial {

  public:

    // Default constructor, initialize to 0
    Polynomial() {_coeffs = {0};};

    // Constructor with coefficients
    Polynomial(const std::vector<real>&);

    // Copy constructor
    Polynomial(const Polynomial&);

    std::vector<real> getCoeffs() const {return _coeffs;};

    // Return degree of polynomial
    int degree() const;

    // Return value at point
    real eval(const real x) const;

    // Return derivative at point
    real evalDeriv(const real x) const;

    // Prints coeffs on screen
    void display();
    // Get derivative
    Polynomial getDerivPolynomial();
    //Operator = 
    Polynomial& operator=(const Polynomial& that) {
        if (this != &that) {
            _coeffs = that._coeffs;  // Copy the value
        }
        return *this;
    }
    // Operator + :
    Polynomial operator +(const Polynomial& that){
      std::vector<real> res(0.);
      if(this->degree()<=that.degree()){
        res.resize(that._coeffs.size());
      }
      else{
          res.resize(this->_coeffs.size());
      }
        
        for(int i = 0 ;i<that.degree()+1;i++){
          res[i] += that._coeffs[i];
        }
        for(int i = 0 ;i<this->degree()+1;i++){
          res[i] += this->_coeffs[i];
        }
      return Polynomial(res);
    };
    // operator * :
    Polynomial operator*(const Polynomial& that){
      std::vector<real> res(this->degree()+that.degree() + 1,0.);
      std::vector<real> p1 = this->getCoeffs();
      std::vector<real> p2 = that.getCoeffs();
      for(int i =0;i<p1.size();i++){
        for(int j=0;j<p2.size();j++){
          res [i+j] +=p1[i]*p2[j];
        }
      }
      return Polynomial(res);
    };
    //save :
    void save(const std::vector<real>&,const std::string ,bool = false);
  private:

    std::vector<real> _coeffs;

};

#endif//_POLYNOMIAL_HPP_

