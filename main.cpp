#include "polynomial.hpp"
#include "LegendreCoeffs.hpp"
#include "harmoniques.hpp"
#include <cmath>
 // Question 5 exo 2 :
    /*
    std::vector<std::vector<double>> matrix(51,std::vector<double>(51,0.0));
    std::ofstream outFile("results.dat");
    for(int l=0;l<=50;l++){
        for(int m=0;m<=50;m++){
            if(l==m){
                matrix[l][m] = fabsl((2./(2*l+1)  - CalculInteg(l,m)));
            }
            else{
                matrix[l][m] = fabsl(CalculInteg(l,m));
            }
            outFile << matrix[l][m] << "\t";
        }
        outFile << "\n";
    }
    */
   /*do{ 
            std::ofstream ofile("Y_"+std::to_string(lmax)+"_"+std::to_string(m)+".txt");
            for(int i =0;i<step_phi;i++){
                while(teta < nteta){
                    ofile << phi << " " << teta << ylm(lmax,m,teta,phi) << std::endl;
                    //std::cout << phi << " " << teta << " "<< ylm(lmax,m,teta,phi) <<std::endl;
                    teta+= dteta ;
                }
                phi += dphi ;
            }

            m++;
        }while(m<=lmax);*/
int main(int argc,char* argv[]){
        int ntheta = std::stoi(argv[2]),nphi = std::stoi(argv[3]);
        int lmax = std::stoi(argv[1]);
        double dtheta = M_PI / ntheta ;
        double dphi = 2*M_PI / nphi ;
        for(int l=0 ;l<=lmax;l++){
            for(int m =-l;m<=l;m++){
                double theta = 0.,phi = 0.;
                std::ofstream ofile("y_"+std::to_string(l)+"_"+std::to_string(m)+".txt");
                for(int i =0 ;i<ntheta;i++){
                    theta = i*dtheta;
                    for(int j =0 ;j<nphi;j++){
                        phi = j * dphi;
                        ofile << ylm(l,m,theta,phi) << "\t";

                    }
                    ofile << "\n";
                }
            }
        }
        
    return 0;
}