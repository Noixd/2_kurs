#include <iostream>             //Header.h
#include <locale>
#include <math.h>

using namespace std;

class Sq
{
private:
	double x, y;                    //Поля классов (переменные)

public:
	Sq() {                           //Базовый конструктор

		x = 0;
		y = 0;
        cout << "Объект создан" << endl;
	}

	Sq(double inpx, double inpy) {  //Конструктор с параметрами (перегруженный)

		x = inpx;
		y = inpy;
        cout << "Объект создан" << endl;
	}

	Sq(const Sq &copy) {        //Конструктор копирования

		cout << "Копирование объекта" << endl;
		x = copy.x;
		y = copy.y;
	}

	~Sq() {                     //Деструктор

		cout << "Объект уничтожен" << endl;
	}

	void SetX() {               //Сеттер для поля Х (принимает и записывает значение)

		cout << "Введите X" << endl;
		cin >> x;
	}

	void SetY() {               //Сеттер для поля Y (принимает и записывает значение)

		cout << "Введите Y" << endl;
		cin >> y;
	}

	void Get() {                //Геттер (выводит значения полей на экран)

		cout << "Значения" << endl << "X: " << x << "px" << endl << "Y: " << y << "px" << endl;
	}

	int Cube() {                //Расчёт по заданию

        if (x < y){
            return pow(x, 2);
        }
        else return pow (y, 2);
	}

};
								//Sourse.cpp

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
