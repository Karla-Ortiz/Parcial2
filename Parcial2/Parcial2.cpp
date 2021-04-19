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
        cout << "Ingrese fecha de nacimiento (yyyy-MM-dd)" << endl;
        cin >> fnac;
        cout << "Ingrese idpuesto" << endl;
        cin >> idpuesto;
        cout << "Ingrese fecha de inicio de labores (yyyy-MM-dd)" << endl;
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

void update() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "root", "parcial2", 3306, NULL, 0);
    string idempleado, nombres, apellidos, direccion, telefono, dpi, genero, fnac, finiciolab, idpuesto;
    if (conectar) {
        cout << "Ingrese id de empleado a modificar" << endl;
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
        cout << "Ingrese fecha de nacimiento (yyyy-MM-dd)" << endl;
        cin >> fnac;
        cout << "Ingrese idpuesto" << endl;
        cin >> idpuesto;
        cout << "Ingrese fecha de inicio de labores (yyyy-MM-dd)" << endl;
        cin >> finiciolab;

        string update = "UPDATE empleados SET nombres='" +nombres+"',apellidos='" + apellidos + "',direccion='" + direccion + "',telefono='" + telefono + "',dpi='" + dpi + "',genero=" + genero + ",fecha_nacimiento='" + fnac + "',idPuesto=" + idpuesto + ",fecha_inicio_labores='" + finiciolab + "',fechaingreso=NOW() WHERE idEmpleado=" +idempleado;
        const char* u = update.c_str();
        estadoq = mysql_query(conectar, u);
        if (!estadoq) {
            cout << "Modificacion exitosa" << endl;
        }
        else {
            cout << "Error al modificar" << endl;
        }
    }
    else {
        cout << "Error al conectar" << endl;
    }
}

void eliminar() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "root", "parcial2", 3306, NULL, 0);
    string idempleado;
    if (conectar) {
        cout << "Ingrese id de empleado a eliminar" << endl;
        cin >> idempleado;

        string del = "DELETE FROM empleados WHERE idEmpleado=" + idempleado;
        const char* d = del.c_str();
        estadoq = mysql_query(conectar, d);
        if (!estadoq) {
            cout << "Eliminacion exitosa" << endl;
        }
        else {
            cout << "Error al Eliminar" << endl;
        }
    }
    else {
        cout << "Error al conectar" << endl;
    }
}

void visualizar() {
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* result;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "root", "parcial2", 3306, NULL, 0);
    if (conectar) {
        string cons = "SELECT * FROM EMPLEADOS";
        const char* c = cons.c_str();
        estadoq = mysql_query(conectar, c);
        if (!estadoq) {
            result = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(result)) {
                cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | " << fila[6] << " | " << fila[7] << " | " << fila[8] << " | " << fila[9] << " | " << fila[10] << endl;
            }
        }
        else {
            cout << "Error al consultar" << endl;
        }
    }
    else {
        cout << "Error al conectar" << endl;
    }
}

int main()
{
    int opc = 0;
    while (opc != 5) {
        system("cls");
        cout << "Ingrese el numero de la opcion que desea realizar:" << endl;
        cout << "1. Ingresar" << endl;
        cout << "2. Modificar" << endl;
        cout << "3. Eliminar" << endl;
        cout << "4. Visualizar datos" << endl;
        cout << "5. Salir" << endl;
        cin >> opc;

        if (opc == 1) {
            system("cls");
            cout << "Opcion ingresar" << endl;
            insert();
            system("pause");
        }
        else if (opc == 2) {
            system("cls");
            cout << "Opcion modificar" << endl;
            update();
            system("pause");
        }
        else if (opc == 3) {
            system("cls");
            cout << "Opcion eliminar" << endl;
            eliminar();
            system("pause");
        }
        else if (opc == 4) {
            system("cls");
            cout << "Opcion visualizar" << endl;
            visualizar();
            system("pause");
        }
        else if (opc == 5) {
            cout << "Regrese pronto :D" << endl;
        }
    }
    system("pause");
    return 0;
}




