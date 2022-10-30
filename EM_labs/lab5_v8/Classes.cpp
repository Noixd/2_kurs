#include "Header.h"
#include "Classes.h"

void Gen_Dir::Add_elem() {

    string inp;
    int count, mark, i = 0;

    cout << "Input capacity: ";
    while (true) {

            cin >> count;

            if (cin.fail() || count < 0) {

                cin.clear();
                cin.ignore(32767, '\n');

                cout << "Incorrect value" << endl;
            }
            else break;
        }

    while(i < count)
    {   
        i++;
        cout << "Input " << i << " name : ";
        cin >> inp;
        cout << "Input mark : ";
        while (true) {

            cin >> mark;

            if (cin.fail() || mark > 10 || mark < 0) {

                cin.clear();
                cin.ignore(32767, '\n');

                cout << "Incorrect value" << endl;
            }
            else break;
        }
        inp = to_string(mark) + " " + inp;
        gen_list.push_front(inp);
    }
}

void Gen_Dir::Del_elem() {
    
    unsigned short count;
    auto iter_name = gen_list.begin();

    cout << "Input number of removing element: ";

    while (true) {

        cin >> count;

        if (cin.fail() || count > gen_list.size()) {

            cin.clear();
            cin.ignore(32767, '\n');

            cout << "Incorrect value" << endl;
        }
        else break;
    }

    for ( unsigned short i = 1; i < count; i++) iter_name++;

    gen_list.erase(iter_name);    
}

void Gen_Dir::Get_elem() {

    cout << "List Gen_Dir" << endl << endl << "# Mark Name" << endl;

    int i = 1;
    for (auto iter = gen_list.begin(); iter != gen_list.end(); ++iter)
    {   
        cout << i << ". " << *iter << endl;
        i++;
    }
}

void Gen_Dir::Sort() {

    gen_list.sort(greater<string>());
}

Gen_Dir::Gen_Dir() {
    #ifdef TEST_MESS
        cout << "Obj created" << endl;
    #endif
} 

Gen_Dir::~Gen_Dir() {
    #ifdef TEST_MESS
        cout << "Obj destroyed" << endl;
    #endif
} 