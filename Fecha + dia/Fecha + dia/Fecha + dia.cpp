//*Ana Rosa Marmolejo Cervantes 2�O    26 de septiembre de 2022

#include <iomanip>
#include <iostream>  //librerias
#include <sstream>
#include <string>
#include <conio.h>
using namespace std;


class Date
{
private:
    int month;
    int day;
    int year;

public:
    Date();
    Date(int m, int d, int y);  //nombre de los argumentos


    void setDate(int m, int d, int y); // metodo para cambiar objeto


    void getDate(int& m, int& d, int& y) const;  // obtener fecha
    void showDate() const;

    bool isLeap(int y) const; //es el argumento un a�o bisiesto?
    bool CheckDate(int m, int d, int y) const;  // es el argumento una fecha valida?
};


Date::Date(int d, int m, int y) //constructor de fecha
{
    if (CheckDate(day, month, year))
    {
        day = d;
        month = m;
        year = y;
    }
}

void Date::getDate(int& d, int& m, int& y) const //obtener la fecha
{
    d = day;
    m = month;
    y = year;
}

bool Date::CheckDate(int day, int month, int year) const
{
    bool result = true;
    int daysInMonths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (year < 1800 || year>2100)
        result = false;
    if (isLeap(year))
    {
        daysInMonths[1] = 29;
    }
    if (month < 1 || month > 12)
    {
        result = false;
    }
    else if (day < 1 || day > daysInMonths[month - 1])
    {
        result = false;
    }
    return result;
}

bool Date::isLeap(int year) const
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return true;
    else
        return false;
}

int main(void)
{

    int day, month, year;

    cout << "Inserte fecha  Day/Month/Year : \n";

    cin >> day >> month >> year;
    Date d1(day, month, year); //instanciando la clase creando un objeto
  

  
    day++;
    if (day > 31)    //si despu�s de sumar el d�a es mayor a 31 el dia sera 1
    {
        day = 1;   
        month++;     
        if (month > 12) //si despu�s de incrementar el mes es mayor a 12 el mes sera enero del siguiente a�o
        {
            month = 1; 
            year++;  
        }
    }
    else if (day == 29 && month == 2) //si es febrero y despu�s de incrementar el d�a es 29 sera el primero del siguiente mes
    {
        day = 1;            
        month++;             
    }
    else if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))//si el d�a es 31 y es un mes de 30 d�as el siguiente dia sera 1     
    {
        day = 1;            
        month++;             
    }

    //mostrar fecha
    cout << setfill('0') << setw(2) << endl << day << "-" << setw(2) << month << "-" << setw(4) << year << endl;
    return 0;
}