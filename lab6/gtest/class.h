#include "Header.h"
    
    //! Класс обработки исключительных ситуаций
    
    /*!
        Предназначен для записи 
        данных в момент исключения
    */
class ZDivExcept {

    public:
        //! Строка исключения
        string ex_name;
        //! Вещественное значение исключения
        double ex_double;
        
        //! Конструктор базового класса
        /*!
            /param inp_name Имя записи вызвавшей исключение
            /param inp_doub Вещественное значение вызвавшее исключение
        */
        ZDivExcept(string inp_name, double inp_doub);
};

    //! Базовый класс
    /*!
        Предназначен для создания базы учеников и отметок
        Обработки созданной базы данных
    */
class Admin {

    private:
        protected:
        //! Фамилия ученика
        string f_name;
        //! Самооценка, оценка коллектива
        double self_mark, coll_mark;

    public:

        //! Конструктор базового класса без параметром
        Admin();

        //! Конструктор базового класса
        /*!
            \param inp_name Фамилия ученика
            \param inp_self Самооценка
            \param inp_coll Оценка коллектива 
        */
        Admin(string inp_name, int inp_self, int inp_coll);

        //! Деструктор
        virtual ~Admin();

        //! Сеттер
        void Set();
    
        //! Геттер
        void Get();

        //! Геттер поля self_mark
        //! \return Текущее self_mark
        double Get_self();

        //! Вычисление по варианту
        //! \return вчисление по заданию
        double Div();

};

    //! Производный класс
    /*!
        Предназначен для создания базы учеников и отметок
        Обработки созданной базы данных
        Присутствует возможность оценки потомками
    */
class Junior: protected Admin {

    private:
        //! Оценка потомками
        double p;
    public:

        //! Конструктор базового класса без параметром
        Junior();

        //! Конструктор базового класса
        /*!
            \param inp_name Фамилия ученика
            \param inp_self Самооценка
            \param inp_coll Оценка коллектива
            \param inp_p Оценка потомками
        */
        Junior(string inp_name, int inp_mark, int inp_coll, int inp_p);

        //! Сеттер
        void Set();

        //! Геттер
        void Get();

        //! Геттер поля self_mark
        //! \return Текущее self_mark
        double Get_self();

        //! Вычисление по варианту
        //! \return вчисление по заданию
        double Div();

};
