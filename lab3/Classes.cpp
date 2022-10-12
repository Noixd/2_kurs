#include "Header.h"

class Admin
{
protected:
    string f_name;
    double self_mark, coll_mark;
public:
    Admin(): f_name(0), self_mark(0), coll_mark(0) {
        cout << "Create obj " << endl;
    }

    Admin(string inp_name, int inp_self, int inp_coll): f_name(inp_name), self_mark(inp_self), coll_mark(inp_coll) {
        cout << "Create obj " << endl;
    }

    ~Admin(){
        cout << "Destruct obj " << endl;
    }

    void Get(){
        cout << "First name: " << f_name << endl;
        cout << "Self mark: " << self_mark << endl;
        cout << "Collective mark: " << coll_mark << endl;
    }

    double Div (){
        return coll_mark/self_mark;
    }
};

class Junior: protected Admin {

    private:
        double p;
    public:
        Junior (string inp_name, int inp_mark, int inp_coll, int inp_p): Admin (inp_name, inp_mark, inp_coll), p(inp_p) {
            cout << "Create obj " << endl;
        }

        void Get(){
        Admin::Get();
        cout << "P = " << p << endl;
        }

        int Div() {
            return 0.3*(coll_mark/self_mark)+0.7*p;
        }
};

