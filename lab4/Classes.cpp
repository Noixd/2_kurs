#include "Header.h"

class Admin {

protected:
    double self_mark, coll_mark;

public:
    string f_name;

    Admin(): f_name(), self_mark(), coll_mark() {
        cout << "Create obj ";
    }

    Admin(string inp_name, int inp_self, int inp_coll): f_name(inp_name), self_mark(inp_self), coll_mark(inp_coll) {
        cout << "Create obj " << endl;
    }

    virtual ~Admin() {
        cout << "Destruct obj " << endl;
    }

    void Set() {
        cout << "First name: ";
        while (true) {
			
				cin >> f_name;

				if (cin.fail()) {
					
					cin.clear();
					cin.ignore(32767,'\n');

					cout << "Incorrect value" << endl;
			    }
			else break;
            }
        
        cout << "Self mark: ";
        while (true) {
                
                    cin >> self_mark;
                    if (cin.fail()) {
                            
                        cin.clear();
                        cin.ignore(32767,'\n');

                        cout << "Incorrect value" << endl;
                        }
                else break;
                }

        cout << "Collective mark: ";
        while (true) {
			
				cin >> coll_mark;

				if (cin.fail()) {
					
					cin.clear();
					cin.ignore(32767,'\n');

					cout << "Incorrect value" << endl;
			}
			else break;
        }
    }

    void Get() {
        
        cout << "First name: " << f_name << endl;
        cout << "Self mark: " << self_mark << endl;
        cout << "Collective mark: " << coll_mark << endl;
    }

    double Div () {

        return coll_mark/self_mark;
    }
};

class Junior: public Admin {

    private:
        double p;
        
    public:
        static int i;
        int address;

        Junior(): Admin(), p() {

            i++;
            address = i;
            cout << address << endl;
        }

        Junior (string inp_name, int inp_mark, int inp_coll, int inp_p): Admin (inp_name, inp_mark, inp_coll), p(inp_p) {

            i++;
            address = i;
            cout << address << endl;
        }

        string Set() {

            Admin::Set();
            cout << "Student's mark: ";

            while (true) {
			
				cin >> p;

				if (cin.fail()) {
					
					cin.clear();
					cin.ignore(32767,'\n');

					cout << "Incorrect value" << endl;
			    }
			else break;
            }

            return "First name: \"" + f_name + "\" Self mark: " + to_string(self_mark) + " Collective mark: " + 
            to_string(coll_mark) + " Student's mark: " + to_string(p);
        }

        void Get() {
            Admin::Get();
            cout << "P = " << p << endl;
        }

        int Div() {
            return 0.3*(coll_mark/self_mark)+0.7*p;
        }

        void Sort (string* sort_arr, string* pole_arr, int count){
            
                string t, p;
                int i_min;

                for (int i = 0; i < count; i++) {
                    i_min = i;
                    for (int j = i + 1; j < count; j++)
                        if (pole_arr[j] > pole_arr[i_min])  i_min = j;
                        
                        t = sort_arr[i_min];
                        sort_arr[i_min] = sort_arr[i];
                        sort_arr[i] = t;
                }
            }    
};