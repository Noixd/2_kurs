#include "header.h"

class Square		//базовый класс
{		int adress = 0;
	protected:
		double x1, y1;
	public:
		static int i;

		Square() { 

			x1 = 0;
			y1 = 0;
			i++;
			adress = i;

			cout << "Create obj " << adress << endl;
		}

		Square(double inpx, double inpy) {
			
			x1 = inpx;
			y1 = inpy;
			i++;
			adress = i;

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
		
			cout << "Input X1" << endl;

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
			
			cout << "Input Y1" << endl;

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
			cout << "Coordinates of " << adress << " point" << endl << "X: " << x1 << " px" << endl << "Y: " << y1 << " px" << endl;
		}

		void Area() {

			cout << "Area of " << adress << " rectanlge: "; 

			cout << abs(x1 * y1) << endl;
		}
};

class Line : public Square {	//производный класс с модификатором public

	private:
		double x2, y2;
		int adress = 0; 

	public:

		Line(): Square() {
			x2 = 0;
			y2 = 0;	 
		}

		void SetX2() { 

			cout << "Input X2" << endl;

			while (true) {		
			
				cin >> x2;

				if (cin.fail()) {
					
					cin.clear();
					cin.ignore(32767,'\n');

					cout << "Incorrect value" << endl;
			}
			else break;
			}
		}

		void SetY2() { 
			
			cout << "Input Y2" << endl;

			while (true) {
			
				cin >> y2;

				if (cin.fail()) {
					
					cin.clear();
					cin.ignore(32767,'\n');

					cout << "Incorrect value" << endl;
			}
			else break;
			}
		}

		void Get1() {

			Get();
			cout << "Coordinates of " << adress << " point" << endl << "X: " << x2 << " px" << endl << "Y: " << y2 << " px" << endl;
		}

		void lenght() {	// метод рассчёта расстояния от точки до точки

			double line_segment_length = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));

			cout << "Lenght of line: " << line_segment_length << endl;
		}
};
