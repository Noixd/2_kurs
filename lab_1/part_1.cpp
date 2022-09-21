#include <iostream>
#include <locale>

using namespace std;

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

	Square(double inpx, double inpy) {
		cout << "Create obj " << endl;
		x1 = inpx;
		y1 = inpy;
	}

	Square(const Square &copy) {
		cout << "Copy obj" << endl;
		x1 = copy.x1;
		y1 = copy.y1;
	}

	~Square() {
		
		cout << "Destruct obj" << endl;
	}

	void SetX() { 
		cout << "Input X" << endl;
		cin >> x1;
	}

	void SetY() { 
		cout << "Input Y" << endl;
		cin >> y1;
	}

	void Get() {
		cout << "Coordinates" << endl << "X: " << x1 << "px" << endl << "Y: " << y1 << "px" << endl;
	}

	double Area() {

		return x1 * y1;
	}

	/*void DI() {
		int i = 1000;
		while (i>0)
		{
			cout << i << endl;
			i -= 7;
		}
	}*/
};

int main() {
	
	setlocale(LC_ALL, "ru");
	
	Square sq1;

	Square sq2(25, 10);

		sq1.SetX();

		sq1.SetY();

	cout << "1 rectangle: " << endl;

		sq1.Get();
	
	cout << "2 rectangle: " << endl;

		sq2.Get();

	cout << "Area of 1 rectangle: " << sq1.Area() << endl;
	
	cout << "Area of 2 rectangle: " << sq2.Area() << endl;
		
	cout << "Copy 1 rectangle to 3" <<	endl;

		Square sq3 = sq1;
	
	cout << "3 rectangle: " << endl;

		sq3.Get();

	return 0;
}
