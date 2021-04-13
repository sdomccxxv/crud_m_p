// CRUDC++.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <mysql.h>

using namespace std;
int q_estado;

void insertar_marca();
void mostrar_marca();
void actualizar_marca();
void insertar_prod();
void mostrar_prod();
void actualizar_prod();

int main()
{
    int a;
    cout << "Si desea\nIngresar, modificar o consultar datos de marca presione 1 \nIngresar, modificar o consultar datos de productos presione 2: ";
    cin >> a;

    switch (a)
    {
    case 1:
        int m;
        cout << "Si desea\ninsertar presione 1\n modificar presione 2 \n consultar presione 3: ";
        cin >> m;

        switch (m)
        {
        case 1:
            insertar_marca(); break;
        case 2:
            actualizar_marca(); break;
        case 3:
            mostrar_marca(); break;
        default:
            break;
        }
    case 2:
        int p;
        cout << "Si desea\ninsertar presione 1\n modificar presione 2 \n consultar presione 3: ";
        cin >> p;

        switch (p)
        {
        case 1:
            insertar_prod(); break;
        case 2:
            actualizar_prod(); break;
        case 3:
            mostrar_prod(); break;
        default:
            break;
        }
    }
    
}

void insertar_marca() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "150289", "db_crud", 3306, NULL, 0);
    if (conectar) {
        string marca;
        cout << "Ingrese marca: ";
        cin >> marca;

        string insertar = "INSERT INTO marcas(marca) VALUES ('" + marca + "');";
        
        const char* i = insertar.c_str();
        q_estado = mysql_query(conectar, i);

        if (!q_estado) {
            cout << "Ingreso de marca exitoso..." << endl;
        }
        else {
            cout << "Error al ingresar marca..." << endl;
            cout << insertar << endl << mysql_error(conectar) << endl;
        }
    }
    else {
        cout << "Conexion fallida..." << endl;
    }

}

void mostrar_marca() {
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;

    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "150289", "db_crud", 3306, NULL, 0);
    if (conectar) {
        string consulta = "SELECT * FROM marcas";
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);

        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado)) {
                cout << fila[0] << " - " << fila[1] << endl;
            }
        }
        else {
            cout << "Error al consultar..." << endl;
        }

    }
    else {
        cout << "Conexion fallida..." << endl;
    }
    system("pause");
}

void actualizar_marca() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "150289", "db_crud", 3306, NULL, 0);
    if (conectar) {
        //cout << "Conexion exitosa..." << endl;
        char idmarca;
        string marca;
        cout << "Ingrese id que desea modificar: ";
        cin >> idmarca;

        cout << "Ingrese nueva marca: ";
        cin >> marca;

        string update = "UPDATE marcas SET marca = '" + marca + "' WHERE idmarca = " + idmarca + "";
        const char* i = update.c_str();
        q_estado = mysql_query(conectar, i);

        if (!q_estado) {
            cout << "Actualizacion exitosa..." << endl;
        }
        else {
            cout << "Error al actualizar..." << endl;
            cout <<update <<endl<< mysql_error(conectar) << endl;
        }
    }
    else {
        cout << "Conexion fallida..." << endl;
    }
    system("pause");
}

void insertar_prod() {
    string nombre, descripcion, fecha_ingreso;
    char idmarca, existencia;
    string costo, venta;

    cout << "Ingrese el nombre del producto: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese la marca del producto: ";
    cin >> idmarca;

    cout << "Ingrese la descripcion del producto: ";
    cin.ignore();
    getline(cin, descripcion);

    cout << "Ingrese el precio costo del producto: ";
    cin >> costo;
    
    cout << "Ingrese el precio de venta del producto: ";
    cin >> venta;

    cout << "Ingrese la cantidad del producto: ";
    cin >> existencia;

    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "150289", "db_crud", 3306, NULL, 0);

    if (conectar) {
        string insert = "INSERT INTO productos(producto, idmarca, descripcion, precio_costo, precio_venta, existencia, fecha_ingreso) VALUES ('" + nombre + "', '" + idmarca + "', '" + descripcion + "', " + costo + "', '" + venta + "', NOW())";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar, i);

        if (!q_estado) {
            cout << "Ingreso exitoso..." << endl;
        }
        else {
            cout << "Error al ingresar..." << endl;
            cout << insert << endl << mysql_error(conectar) << endl;
        }
    }
    else {
        cout << "Conexion fallida..." << endl;
    }

    system("pause");
}

void mostrar_prod() {
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;

    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "150289", "db_crud", 3306, NULL, 0);
    if (conectar) {
        string consulta = "SELECT * FROM productos";
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);

        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado)) {
                cout << fila[0] << " - " << fila[1] << endl;
            }
        }
        else {
            cout << "Error al consultar..." << endl;
        }

    }
    else {
        cout << "Conexion fallida..." << endl;
    }
    system("pause");
}

void actualizar_prod() {

    string nombre, descripcion, fecha_ingreso;
    char idmarca, existencia;
    char costo, venta;

    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "150289", "db_crud", 3306, NULL, 0);
    if (conectar) {
        //cout << "Conexion exitosa..." << endl;
        char idmarca;
        string marca;
        cout << "Ingrese id que desea modificar: ";
        cin >> idmarca;

        cout << "Ingrese el nombre del producto: ";
        cin.ignore();
        getline(cin, nombre);

        cout << "Ingrese la marca del producto: ";
        cin >> idmarca;

        cout << "Ingrese la descripcion del producto: ";
        cin.ignore();
        getline(cin, descripcion);

        cout << "Ingrese el precio costo del producto: ";
        cin >> costo;

        cout << "Ingrese el precio de venta del producto: ";
        cin >> venta;

        cout << "Ingrese la cantidad del producto: ";
        cin >> existencia;

        string update = "UPDATE productos SET `producto` = '"+ nombre + "',`idMarca` = '"+ idmarca +"',`descripcion` = '" + descripcion + "',`precio_costo` = '" + costo + "',`precio_venta` = '" + venta + "',`existencia` = '" + existencia + "',`fecha_ingreso` = NOW()";
        const char* i = update.c_str();
        q_estado = mysql_query(conectar, i);

        if (!q_estado) {
            cout << "Actualizacion exitosa..." << endl;
        }
        else {
            cout << "Error al actualizar..." << endl;
            cout << update << endl << mysql_error(conectar) << endl;
        }
    }
    else {
        cout << "Conexion fallida..." << endl;
    }
    system("pause");
}