#ifndef HEADER
#define HEADER
#define TEST_MESS

#include <iostream>

using namespace std;


#endif

class Arrays {
    private:
        int n, m;
        double **pDoubelArray;

    public:

        __declspec(property(get = ElQt)) int E_Q;

        __declspec(property(put = PlusScl)) double P_S;
        
        Arrays(): n(), m(), pDoubelArray() {
            
            #ifdef TEST_MESS
            cout << "Obj created" << endl;
            #endif
        }

        Arrays(int inpn, int inpm, double** inparr): n(inpn), m(inpm), pDoubelArray(inparr) {

            pDoubelArray = new double* [n];

                 for (int i = 0; i < n; i++)
        {
            pDoubelArray [i] = new double [m];
        }

            #ifdef TEST_MESS
            cout << "Obj created" << endl;
            #endif
        }

        Arrays(const Arrays &copy) {
            
            n = copy.n;
			m = copy.m;
            pDoubelArray = copy.pDoubelArray;

            #ifdef TEST_MESS
            cout << "Obj copy created" << endl;
            #endif
        }

        ~Arrays () {
            #ifdef TEST_MESS
            cout << "Obj destroyed" << endl;
            #endif
        }

        void SetArr() {
            cout <<  "Input vertical size: ";
            cin >> n;
            cout <<  "Input horizontal size: ";
            cin >> m;

                pDoubelArray = new double* [n];

            for (int i = 0; i < n; i++)
            {
            pDoubelArray [i] = new double [m];
            }

            cout << "Input array's value" << endl;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << "Element " << i << "x" << j << ": ";
                    cin >> pDoubelArray [i][j];
                }
            }
        }

        void GetArr () {
            cout << "Array's value:" << endl;
            int i = 0;

            for (int i = 0; i < n; i++)
            {   
                cout << "String " << i << ": ";
                for (int j = 0; j < m; j++)
                    cout << pDoubelArray [i][j] << " ";
                
                cout << endl;
            }
        }

        void SortArr () {

            int str;
            double t;
            cout << "Input string for sort: ";
            cin >> str;
            while (true) {

                cin >> str;

                if (cin.fail() || str < 0 || str > n) {

                    cin.clear();
                    cin.ignore(32767, '\n');

                    cout << "Incorrect value" << endl;
                }
                else break;
            }

            for (int i = 0; i < m; i++) {
                int i_min = i;
                for (int j = i + 1; j < m; j++)
                    if (pDoubelArray[str][j] > pDoubelArray[str][i_min]) { i_min = j; }

                t = pDoubelArray[str][i_min];
                pDoubelArray[str][i_min] = pDoubelArray[str][i];
                pDoubelArray[str][i] = t;
            }
        }

        int ElQt () {

            return n*m;
        }

        void PlusScl (double sc) {

            for (int i = 0; i < n; i++)
            {
                for (int j = 0;  j< m; j++)
                pDoubelArray [i][j] += sc;
            }
        }
};

int main () {

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