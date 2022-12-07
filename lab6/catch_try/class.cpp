#include "Header.h"
#include "class.h"


ZDivExcept :: ZDivExcept(string inp_name, double inp_doub) {
    ex_double = inp_doub;
    ex_name = inp_name;
}

Admin :: Admin() : f_name(), self_mark(0), coll_mark(0) {
    cout << "Create obj " << endl;
};

Admin :: Admin(string inp_name, int inp_self, int inp_coll): f_name(inp_name), self_mark(inp_self), coll_mark(inp_coll) {
    if (self_mark == 0.0) throw ZDivExcept(f_name, self_mark);
    cout << "Create obj " << endl;
};

Admin :: ~Admin() {
    cout << "Destruct obj " << endl;
};

void Admin :: Set() {
    cout << "First name: ";
    cin >> f_name;
    cout << "Self mark: ";
    cin >> self_mark;
    cout << "Collective mark: ";
    cin >> coll_mark;
}

void Admin :: Get() {
    cout << "First name: " << f_name << endl;
    cout << "Self mark: " << self_mark << endl;
    cout << "Collective mark: " << coll_mark << endl;
};

double Admin :: Get_self() {
    return self_mark;
}

double Admin :: Div () {
    return coll_mark/self_mark;
};

Junior :: Junior() : Admin(), p() {
    //if (self_mark == 0.0) throw ZDivExcept(f_name, self_mark);
    cout << "Create obj " << endl;
};

Junior :: Junior (string inp_name, int inp_mark, int inp_coll, int inp_p): Admin (inp_name, inp_mark, inp_coll), p(inp_p) {
    if (self_mark == 0.0) throw ZDivExcept(f_name, self_mark);
    cout << "Create obj " << endl;
};

void Junior :: Set () {
    cout << "First name: ";
    cin >> f_name;
    cout << "Self mark: ";
    cin >> self_mark;
    cout << "Collective mark: ";
    cin >> coll_mark;
    cout << "P: ";
    cin >> p;
}

void Junior :: Get () {
    Admin::Get();
    cout << "P = " << p << endl;
};

double Junior :: Get_self () {
    return self_mark;
}

double Junior :: Div () {
    return 0.3*(coll_mark/self_mark)+0.7*p;
};
