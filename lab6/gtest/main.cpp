#include "Header.h"
#include "class.cpp"

/*!
\mainpage ������������ ������ 6
\author Osipenko
\date 07.12.2022
\section goal ������� �� ������������ ������ 6
\subsection task �������������� �������.
����������� �������� double ������� ��������� �� ������ 3
*/


int main() {
    
    try {
        Admin a2("Smith", 7, 6);
    }
    catch(ZDivExcept exception) {
        cout << "Zero divide error on: " << exception.ex_name << '\n';
    }
    
    try {
        Admin a_ex("Smith", 0, 6);
    }
    catch(ZDivExcept exception) {
        cout << "Zero divide error on: " << exception.ex_name << '\n';
    }

    try {
        Junior j1("Black", 10, 10, 9);
    }
    catch(ZDivExcept exception) {
        cout << "Zero divide error on: " << exception.ex_name << '\n';
    }

    try {
        Junior j_ex("Black", 0, 10, 9);
    }
    catch(ZDivExcept exception) {
        cout << "Zero divide error on: " << exception.ex_name << '\n';
    }

    Admin Ad1;
    Junior Jr1;

    Ad1.Set();

    Ad1.Get();

    cout << Ad1.Div() << endl;

    Jr1.Set();

    Jr1.Get();

    cout << Jr1.Div() << endl;
    
    return 0;
}