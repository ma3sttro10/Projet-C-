#include "LegendreCoeffs.hpp"

/*Écrivez une méthode getCoeffs(int l) qui retourne le tableau de 
coefficients de 𝑃ℓ, quel que soit ledegré ℓ. La méthode utilisera les 
fonctionnalités de la classe Polynomial pour mettre à jour le 
tableau mentionné à la question précédente si les coefficients ne sont
 pas encore calculés pour ce degré ℓ.*/
// Constructeur : 
    LegendreCoeffs::LegendreCoeffs(){ 
    Polynomial P0({1}),P1({0,1});
    _LegPoly.push_back(P0);
    _LegPoly.push_back(P1);
      }
// Constructeur : 
/*
LegendreCoeffs::LegendreCoeffs(int l){
    Polynomial P0({1}),P1({0,1});
    _LegPoly.push_back(P0);
    _LegPoly.push_back(P1);
    while(_LegPoly.size()<= l){
    int d = _LegPoly.size();
    std::vector<real> c1 = _LegPoly[d-1].getCoeffs();
    std::vector<double> c2 =_LegPoly[d-2].getCoeffs();
    std::vector<double> pl(d+1,0.0);
    // next Poly :
    for(int i =0;i<d;i++){
        pl[i+1] += ((2*d - 1)*c1[i])/d ;
    }
    for(int i =0;i<d;i++){
        pl[i] -=(d-1)*c2[i]/d ;
    }
    _LegPoly.push_back(Polynomial(pl));
}
}
*/
// display : 
void LegendreCoeffs::display(){
    for(int i = 0;i<_LegPoly.size();i++){
        _LegPoly[i].display();
    }
}
    
// Methode getCoeffs : 
std::vector<double> LegendreCoeffs::getCoeffs(int l){
    if (l==0 or l==1){return _LegPoly[l].getCoeffs();}
    while(_LegPoly.size()<= l){
    int d = _LegPoly.size();
    std::vector<real> c1 = _LegPoly[d-1].getCoeffs();
    std::vector<double> c2 =_LegPoly[d-2].getCoeffs();
    std::vector<double> Pl(d+1,0.0);
    // next Poly :
    for(int i =0;i<c1.size();i++){
        Pl[i+1] += ((2*d - 1)*c1[i])/d ;
    }
    for(int i =0;i<c2.size();i++){
        Pl[i] -= (d-1)*c2[i]/d ;
    }
    _LegPoly.push_back(Polynomial(Pl));
    };
    return _LegPoly[l].getCoeffs();
}
double CalculInteg(int l,int m){
    double res = 0.;
    int N = 10000;
    double dx = 2./N ;
    std::vector<real> x;
    LegendreCoeffs P;
    Polynomial Pl(P.getCoeffs(l));
    Polynomial Pm(P.getCoeffs(m));
    double count = -1.;
    while(count <= 1){
        x.push_back(count);
        count += dx;
    }
    for (int i =0;i<=N;i++){
        res += dx * Pl.eval(x[i])*Pm.eval(x[i]);
    }

    return res;
}
void LegendreCoeffs::trace(int N,int l){
    double dx = 2./N ;
    std::vector<real> x;
    double count = -1. ;
    while(count <= 1){
        x.push_back(count);
        count += dx;
    }
    for (int i =0;i<l;i++){
        this->getCoeffs(i+1);
        this->_LegPoly[i].save(x,"P"+ std::to_string(i)+".dat");
    }
}
