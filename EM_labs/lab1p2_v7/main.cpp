#include "Header.h"
#include "Classes.cpp"

int main (){

    int z;

    Arrays Arr1;

    Arr1.SetArr();

    Arr1.GetArr();

    Arr1.SortArr();

    Arr1.GetArr();

    Arr1.E_Q;

    cout << "Elements quanity: " << Arr1.E_Q << endl;

    cout << "Input term: ";
    cin >> z;

    Arr1.P_S = z;

    Arr1.GetArr();

    return 0;
}