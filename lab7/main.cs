/*С этой лабой есть приколы как её делать
  Спрашивайте, если что не будет получаться*/

using System;

namespace ConsoleApp1
{
    class Square {

        private double x1;
        private double y1;
        private int address = 0;

        public static int i;
        public Square() {
            i++;
            address = i;
            x1 = 0;
            y1 = 0;

            Console.WriteLine("Create obj {0}", address);
        }



        public Square(double inpx, double inpy) {
            i++;
            address = i;
            x1 = inpx;
            y1 = inpy;

            Console.WriteLine("Create obj {0}", address);
        }

        public Square(Square copy) {

			i++;
			address = i;
			x1 = copy.x1;
			y1 = copy.y1;

            Console.WriteLine("Copy obj {0} to {1}", copy.address, address);

        }

        ~Square() {
            Console.WriteLine("Destruct obj {0}", address);
        }

        public double X1 {            
            get {
                return x1;
            }
           
            set {
                x1 = value;
            }
        }

        public double Y1
        {
            get
            {
                return y1;
            }

            set
            {
                y1 = value;
            }
        }

        void SetX()
        {
            Console.WriteLine("Input X");
            X1 = double.Parse(Console.ReadLine());
        }

        void SetY()
        {
            Console.WriteLine("Input Y");
            Y1 = double.Parse(Console.ReadLine());
        }

        void Get() {
            Console.WriteLine("Coordinates of {0} rectanlge", address);
            Console.WriteLine("X: {0} px", X1);
            Console.WriteLine("Y: {0} px", Y1);
        }

        void Area () {
            Console.WriteLine("Area of {0} rectanlge: {1}", address, Math.Abs(x1 * y1));
        }

        static void Main ()
        {
            Square square = new Square();

            Square square1 = new Square(25,5);

            square.SetX();

            square.SetY();

            square.Get();

            square1.Get();

            square.Area();

            Square square2 = new Square(square1);

            square2.Get();

        }
    }
}
