// Parcial2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <mysql.h>
#include <iostream>
using namespace std;
int main()
{
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "root", "parcial2", 3306, NULL, 0);
    if (conectar) {
        cout << "Conexion exitosa..." << endl;
    } else {
        cout << "Error al conectar" << endl;
    }
    system("pause");
    return 0;
}

