// Parcial2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <mysql.h>
#include <iostream>
using namespace std;

int estadoq;


void insert() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "root", "parcial2", 3306, NULL, 0);
    string idempleado, nombres, apellidos, direccion, telefono, dpi, genero, fnac, finiciolab, idpuesto;
    if (conectar) {
        cout << "Ingrese id de empleado" << endl;
        cin >> idempleado;
        cout << "Ingrese nombres" << endl;
        cin >> nombres;
        cout << "Ingrese apellidos" << endl;
        cin >> apellidos;
        cout << "Ingrese direccion" << endl;
        cin >> direccion;
        cout << "Ingrese telefono" << endl;
        cin >> telefono;
        cout << "Ingrese DPI" << endl;
        cin >> dpi;
        cout << "Ingrese genero (0=femenino / 10=masculino)" << endl;
        cin >> genero;
        cout << "Ingrese fecha de nacimiento (dd-MM-yy)" << endl;
        cin >> fnac;
        cout << "Ingrese idpuesto" << endl;
        cin >> idpuesto;
        cout << "Ingrese fecha de inicio de labores (dd-MM-yy)" << endl;
        cin >> finiciolab;

        string insert = "INSERT INTO empleados VALUES(" + idempleado + ",'" + nombres + "','" + apellidos + "','" + direccion + "','" + telefono + "','" + dpi + "'," + genero + ",'" + fnac + "'," + idpuesto + ",'" + finiciolab + "',NOW())";
        const char* i = insert.c_str();
        estadoq = mysql_query(conectar, i);
        if (!estadoq) {
            cout << "Ingreso exitoso" << endl;
        }
        else {
            cout << "Error al ingresar" << endl;
        }
    }
    else {
        cout << "Error al conectar" << endl;
    }
}

int main()
{
    insert();
    system("pause");
    return 0;
}




