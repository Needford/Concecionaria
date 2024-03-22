#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

const int MAX_CARROS = 2000;
const int MAX_CLIENTES = 200;

// Estructura para almacenar la información de un carro
struct Carro {
    int id;
    string marca;
    string modelo;
    int ano;
    int vendido_a;
    int comprado_a;
    double precio_venta;
    double precio_compra;
    string cliente;
    bool vendido;
};

// Estructura para almacenar la información de un cliente
struct Cliente {
    int id;
    string nombre;
    string apellido;
    string correo;
    int edad;
};
// Arreglos para almacenar los datos de los carros y clientes
Carro carros[MAX_CARROS];
Cliente clientes[MAX_CLIENTES];
int numCarros = 0;
int numClientes = 0;

// Función para cargar los datos de carros desde un archivo CSV
void cargardatoscarros() {
    ifstream archivo("autos.csv");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de carros." << endl;
        return;
    }

    string linea;
    getline(archivo, linea); // Leer la primera línea (encabezados) y descartarla

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string dato;

        getline(ss, dato, ';'); // Leer y asignar la ID
        carros[numCarros].id = stoi(dato);

        getline(ss, carros[numCarros].marca, ';'); // Leer y asignar la marca
        getline(ss, carros[numCarros].modelo, ';'); // Leer y asignar el modelo

        getline(ss, dato, ';'); // Leer y asignar el año
        carros[numCarros].ano = stoi(dato);

        getline(ss, dato, ';'); // Leer y asignar el cliente al que se vendió
        carros[numCarros].vendido_a = stoi(dato);

        getline(ss, dato, ';'); // Leer y asignar el cliente al que se compró
        carros[numCarros].comprado_a = stoi(dato);

        getline(ss, dato, ';'); // Leer y asignar el precio de venta
        carros[numCarros].precio_venta = stod(dato);

        getline(ss, dato); // Leer y asignar el precio de compra
        carros[numCarros].precio_compra = stod(dato);

        numCarros++;

        if (numCarros >= MAX_CARROS) {
            cout << "Se ha alcanzado el límite máximo de carros." << endl;
            break;
        }
    }

    archivo.close();
}

// Función para cargar los datos de clientes desde un archivo CSV
void cargardatosclientes() {
    ifstream archivo("clientes.csv");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de clientes." << endl;
        return;
    }

    string linea;
    getline(archivo, linea); // Leer la primera línea (encabezados) y descartarla

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string dato;

        getline(ss, dato, ';'); // Leer y asignar la ID
        clientes[numClientes].id = stoi(dato);

        getline(ss, clientes[numClientes].nombre, ';'); // Leer y asignar el nombre
        getline(ss, clientes[numClientes].apellido, ';'); // Leer y asignar el apellido

        getline(ss, clientes[numClientes].correo, ';'); // Leer y asignar el correo

        getline(ss, dato); // Leer y asignar la edad
        clientes[numClientes].edad = stoi(dato);

        numClientes++;

        if (numClientes >= MAX_CLIENTES) {
            cout << "Se ha alcanzado el límite máximo de clientes." << endl;
            break;
        }
    }

    archivo.close();
}

// Función para vender un carro
void venderCarro(int idCarro, const string& nombreCliente) {
    for (int i = 0; i < numCarros; ++i) {
        if (carros[i].id == idCarro) {
            if (!carros[i].vendido) {
                carros[i].vendido = true;
                carros[i].cliente = nombreCliente;
                cout << "Carro vendido a " << nombreCliente << " por $" << carros[i].precio_venta << endl;
            } else {
                cout << "El carro ya ha sido vendido." << endl;
            }
            return;
        }
    }
    cout << "No se encontró el carro con la ID especificada." << endl;
}