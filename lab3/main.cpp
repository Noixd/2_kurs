#include "Header.h"
#include "Classes.cpp"

int main() {

    Admin a1("Smith", 7, 6);
    Junior j1("Black", 10, 10, 9);

    a1.Get();
    cout << "Q = " << a1.Div() << endl;

    j1.Get();
    cout << "Q = " << j1.Div() << endl;

    return 0;
}