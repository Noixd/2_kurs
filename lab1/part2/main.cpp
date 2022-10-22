#include "Header.h"
#include "class.cpp"

int main() {
	
	setlocale(LC_ALL, "ru");
	
	Sq sq1;

	Sq sq2(25, 10);

		sq1.SetX();

		sq1.SetY();

	cout << "Первый объект:" << endl;

		sq1.Get();
	
	cout << "Второй объект:" << endl;

		sq2.Get();

	cout << "Квадрат первого объекта: " << sq1.Cube() << endl;
	
	cout << "Квадрат второго объекта: " << sq2.Cube() << endl;
		
	cout << "Копирование первого объекта в третий" <<	endl;

		Sq sq3 = sq1;
	
	cout << "Третий объект:" << endl;

		sq3.Get();

	return 0;
}