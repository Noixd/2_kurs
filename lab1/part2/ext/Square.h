#include "header.h"

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
			cout << "Input Y" << endl;

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
			cout << "Coordinates of " << adress << " rectanlge" << endl << "X: " << x1 << " px" << endl << "Y: " << y1 << " px" << endl;
		}

		void get_adr() {
			cout << adress << endl;
		}

		void Area() {

			cout << "Area of " << adress << " rectanlge: "; 

			cout << abs(x1 * y1) << endl;
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