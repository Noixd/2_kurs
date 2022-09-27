#include "header.h"
#include "Square.h"

int main(){
    
    setlocale(LC_ALL, "ru");

    Square sq1;

    Square sq2(25, 10);

		sq1.SetX();

		sq1.SetY();

		sq1.Get();
	
		sq2.Get();

		sq1.Area();
	
		sq2.Area();
		
		Square sq3 = sq1;

       		sq3.Get();

	return 0;
}

