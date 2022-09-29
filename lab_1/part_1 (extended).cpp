#include <iostream>
#include <locale>

using namespace std;

class Square
{
	private:
		double x1;
		double y1;
		int adress = 0;

	public:

		static int i;

		Square() { 

			i++;
			adress = i;
			x1 = 0;
			y1 = 0;

			cout << "Create obj " << adress << endl;
		}

		Square(double inpx, double inpy) {

			i++;
			adress = i;
			x1 = inpx;
			y1 = inpy;

			cout << "Create obj " << adress << endl;
		}

		Square(const Square &copy) {

			i++;
			adress = i;
			x1 = copy.x1;
			y1 = copy.y1;

			cout << "Copy obj " << copy.adress << " to " << adress << endl;
		}

		~Square() {
			
			cout << "Destruct obj " << adress << endl;
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
			cout << "Coordinates of " << adress << " rectanlge" << endl << "X: " << x1 << " px" << endl << "Y: " << y1 << " px" << endl;
		}

		void get_adr() {
			cout << adress << endl;
		}

		void Area() {

			cout << "Area of " << adress << " rectanlge: "; 

			cout << abs(x1 * y1) << endl;
		}
};

int Square :: i;

int main() {
	
	setlocale(LC_ALL, "ru");
	
	Square sq1;

	Square sq2(25, 10);

	Square sq4;

		sq1.SetX();

		sq1.SetY();

		sq1.Get();
	
		sq2.Get();

		sq1.Area();
	
		sq2.Area();
		
		Square sq3 = sq1;
	

	return 0;
}
