#include "harmoniques.hpp"
double mderiv(Polynomial Pl,int m,double teta){
    double res;
    for(int i =0;i<m;i++){
            Pl = Pl.getDerivPolynomial();
            res = Pl.eval(cos(teta));
        }
        return res;
}
double factorial(int n) {
    if (n <= 1) return 1.0;
    return n * factorial(n - 1);
}

double ylm(int l,int m,double teta,double phi){
    LegendreCoeffs A; 
    Polynomial Pl(A.getCoeffs(l));
    if(m == 0){
        double res;
        res = std::sqrt((2*l +1)/(4*M_PI)) *Pl.eval(std::cos(teta)) ;
        return res;
    }
    else if (m > 0){
        double res ;
        double res_deriv = mderiv(Pl,m,teta);
        int f1 = factorial(l-m);
        int f2 = factorial(l+m);
        double f = f1/(double)f2;
        res = std::sqrt((2*l+1)/(2*M_PI) * f)* pow(-1,m)*(1-pow(cos(teta),2)) *res_deriv* cos(m*phi);
        return res;
    }
    else{
        double res ;
        double res_deriv = mderiv(Pl,-m,teta);
        int f1 = factorial(l-m);
        int f2 = factorial(l+m);
        double f = f1/f2;
        res = std::sqrt((2*l+1)/(2*M_PI) * f)*f*(1-pow(cos(teta),2)) *res_deriv* sin(-m*phi);
        return res;
    }
}
