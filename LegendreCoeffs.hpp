#ifndef _LEGENDRECOEFFS_HPP
#define _LEGENDRECOEFFS_HPP
#include "polynomial.hpp"
#include <algorithm>
class LegendreCoeffs{
    std::vector<Polynomial> _LegPoly;
public :
    void display();
    LegendreCoeffs();
    LegendreCoeffs(int l);
    std::vector<double> getCoeffs(int l);
    void trace(int N,int =6);
};

double CalculInteg(int l,int m);
#endif// _LEGENDRECOEFFS_HPP
