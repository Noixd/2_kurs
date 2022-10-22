#include "Header.h"

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

		while (true) {		

				cin >> x;

				if (cin.fail()) {

					cin.clear();
					cin.ignore(32767,'\n');

					cout << "Incorrect value" << endl;
				}
				else break;
	    }
    }

	void SetY() {               //Сеттер для поля Y (принимает и записывает значение)

        cout << "Введите Y" << endl;
        
		while (true) {		
			
				cin >> y;

				if (cin.fail()) {

					cin.clear();
					cin.ignore(32767,'\n');

					cout << "Incorrect value" << endl;
				}
				else break;
	    }
    }

	void Get() {                //Геттер (выводит значения полей на экран)

		cout << "Значения" << endl << "X: " << x << endl << "Y: " << y << endl;
	}

	int Cube() {                //Расчёт по заданию

        if (x < y){
            return pow(x, 2);
        }
        else return pow (y, 2);
	}

};