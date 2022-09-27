#include "header.h"

class Square
{
private:
	double x1;
	double y1;

public:
	Square() {
		cout << "Create obj " << endl;
		x1 = 0;
		y1 = 0;
	}

	Square (double inpx, double inpy) {
		cout << "Create obj " << endl;
		x1 = inpx;
		y1 = inpy;
	}

	Square (const Square &copy) {
		cout << "Copy obj" << endl;
		x1 = copy.x1;
		y1 = copy.y1;
	}

	~Square() {
		
		cout << "Destruct obj" << endl;
	}

	void SetX() { 
		while (true) {		
			
				cin >> x1;

				if (cin.fail()) {
					
					cin.clear();
					cin.ignore(32767,'\n');

					cout << "Incorrect value" << endl;
				}
				else break;
			}
	}

	void SetY() { 
		while (true) {		
			
				cin >> y1;

				if (cin.fail()) {
					
					cin.clear();
					cin.ignore(32767,'\n');

					cout << "Incorrect value" << endl;
				}
				else break;
			}
	}

	void Get() {
		cout << "Coordinates" << endl << "X: " << x1 << "px" << endl << "Y: " << y1 << "px" << endl;
	}

	double Area() {
		return x1 * y1;
	}

};
