#include "Header.h"
    
    //! ����� ��������� �������������� ��������
    
    /*!
        ������������ ��� ������ 
        ������ � ������ ����������
    */
class ZDivExcept {

    public:
        //! ������ ����������
        string ex_name;
        //! ������������ �������� ����������
        double ex_double;
        
        //! ����������� �������� ������
        /*!
            /param inp_name ��� ������ ��������� ����������
            /param inp_doub ������������ �������� ��������� ����������
        */
        ZDivExcept(string inp_name, double inp_doub);
};

    //! ������� �����
    /*!
        ������������ ��� �������� ���� �������� � �������
        ��������� ��������� ���� ������
    */
class Admin {

    private:
        protected:
        //! ������� �������
        string f_name;
        //! ����������, ������ ����������
        double self_mark, coll_mark;

    public:

        //! ����������� �������� ������ ��� ����������
        Admin();

        //! ����������� �������� ������
        /*!
            \param inp_name ������� �������
            \param inp_self ����������
            \param inp_coll ������ ���������� 
        */
        Admin(string inp_name, int inp_self, int inp_coll);

        //! ����������
        virtual ~Admin();

        //! ������
        void Set();
    
        //! ������
        void Get();

        //! ������ ���� self_mark
        //! \return ������� self_mark
        double Get_self();

        //! ���������� �� ��������
        //! \return ��������� �� �������
        double Div();

};

    //! ����������� �����
    /*!
        ������������ ��� �������� ���� �������� � �������
        ��������� ��������� ���� ������
        ������������ ����������� ������ ���������
    */
class Junior: protected Admin {

    private:
        //! ������ ���������
        double p;
    public:

        //! ����������� �������� ������ ��� ����������
        Junior();

        //! ����������� �������� ������
        /*!
            \param inp_name ������� �������
            \param inp_self ����������
            \param inp_coll ������ ����������
            \param inp_p ������ ���������
        */
        Junior(string inp_name, int inp_mark, int inp_coll, int inp_p);

        //! ������
        void Set();

        //! ������
        void Get();

        //! ������ ���� self_mark
        //! \return ������� self_mark
        double Get_self();

        //! ���������� �� ��������
        //! \return ��������� �� �������
        double Div();

};
