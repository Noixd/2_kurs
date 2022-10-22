#include "Header.h"
#include "Classes.cpp"

int Junior::i;

int main() {

    Junior St1;
    int count;

    cout << "Num of strings in db" << endl;
    cin >> count;
    
    string *p_arr = new string[count];
    string *f_pole = new string[count];

    for (int c = 0; c < count; c++)
    {
        p_arr[c] = St1.Set();
        f_pole[c] = St1.f_name;
    }

    ofstream out1, out2;
    out1.open("in.txt");
    out2.open("out.txt");

    if(out1.is_open()){
        for (int c = 0; c < count; c++) out1 << p_arr[c] << endl;  
    }

    St1.Sort(p_arr, f_pole, count);

     for (int c = 0; c < count; c++)
        {
            out2 << p_arr[c] << endl;
        }

    out1.close();
    out2.close();
    
}