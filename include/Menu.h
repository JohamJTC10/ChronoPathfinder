#ifndef MENU_H
#define MENU_H
#include<iostream>
#define endl '\n'
using namespace std;

class Menu
{
    public:
        Menu();
        void mostrar();
        int read();
        virtual ~Menu();

    protected:

    private:
        //void cleanScreen();
};

#endif // MENU_H
