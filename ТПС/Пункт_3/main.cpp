#ifndef HEADER
#define HEADER
#define PI 3.141592

#include <fstream>
#include <math.h>
#include <iostream>

using namespace std;

#endif

#define T0 0.00017     //!!ПЕРЕОПРЕДЕЛИТЬ!!
#define Tk 0.000005531
#define N0 32
#define U_inp_val1 1100 //значение в формуле первого сигнала
#define U_inp_val2 1050 //значение в формуле второго сигнала

int main() {

    double t [32];
    double U_first [32] , U_second [32];
    int i = 0 , C  = 1;

    ofstream out1;
    out1.open("Table.txt");
    out1.precision(6);
    
    while (C < 5) {   
        i = 0;
        if(out1.is_open()) {
            out1  << "Cycle " << C << endl << endl << "i" << "\tt,s" << "\tU8" << "\tU9" << endl;

            while (i < 32) {   
                t[i] = Tk * (i + 1)  + T0 * (C - 1);

                    // Формула для первого сигнала
                U_first [i] = 0.13 * ((1 - cos(4 * PI * U_inp_val1 * t[i]))/2);     

                    // Формула для второго сигнала
                U_second [i] = 0.15 * ((3*sin(2 * PI * U_inp_val2 * t [i]) + sin(6 * PI * U_inp_val2 * t[i]))/4);
                                
                out1 << i << "\t" << t[i] << "\t" << U_first[i] << "\t" << U_second[i] << endl;
                i++;
            }
            out1 << endl;
        }
        C++;
    }
    return 0;
}
