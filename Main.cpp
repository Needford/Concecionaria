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
// Función para mostrar la información completa de un carro
void mostrarInfoCarro(const Carro& carro) {
    string nombreVendedor, nombreComprador;

    // Buscar el nombre del cliente que vendió el carro
    for (int i = 0; i < numClientes; ++i) {
        if (clientes[i].id == carro.vendido_a) {
            nombreVendedor = clientes[i].nombre + " " + clientes[i].apellido;
            break;
        }
    }

    // Buscar el nombre del cliente que compró el carro
    for (int i = 0; i < numClientes; ++i) {
        if (clientes[i].id == carro.comprado_a) {
            nombreComprador = clientes[i].nombre + " " + clientes[i].apellido;
            break;
        }
    }

    // Mostrar la información completa del carro
    cout << "ID: " << carro.id << ", Marca: " << carro.marca << ", Modelo: " << carro.modelo
         << ", Año: " << carro.ano << ", Vendido por: " << nombreVendedor
         << ", Comprado por: " << nombreComprador << ", Precio de venta: " << carro.precio_venta
         << ", Precio de compra: " << carro.precio_compra << endl;
}
// Función para guardar los datos de clientes en un archivo CSV
void guardarClientes() {
    ofstream archivo("clientes.csv");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de clientes para guardar." << endl;
        return;
    }

    archivo << "id;nombre;apellido;correo;edad" << endl;
    for (const auto& cliente : clientes) {
        archivo << cliente.id << ';' << cliente.nombre << ';' << cliente.apellido << ';' << cliente.correo << ';'
                << cliente.edad << endl;
    }

    archivo.close();
}

// Función para agregar un nuevo cliente
void agregarCliente() {
    Cliente cliente;
    cout << "Ingrese el ID del cliente: ";
    cin >> cliente.id;
    cout << "Ingrese el nombre del cliente: ";
    cin >> cliente.nombre;
    cout << "Ingrese el apellido del cliente: ";
    cin >> cliente.apellido;
    cout << "Ingrese el correo del cliente: ";
    cin >> cliente.correo;
    cout << "Ingrese la edad del cliente: ";
    cin >> cliente.edad;
    guardarClientes();
}

// Función para mostrar los clientes
void mostrarClientes() {
    cout << "Lista de clientes:" << endl;
    for (const auto& cliente : clientes) {
        cout << "ID: " << cliente.id << ", Nombre: " << cliente.nombre << ", Apellido: " << cliente.apellido
             << ", Correo: " << cliente.correo << ", Edad: " << cliente.edad << endl;
    }
}
// Función para eliminar un cliente
void eliminarCliente(int idCliente) {
    int indiceEliminar = -1;
    for (int i = 0; i < numClientes; ++i) {
        if (clientes[i].id == idCliente) {
            indiceEliminar = i;
            break;
        }
    }

    if (indiceEliminar != -1) {
        // Eliminar el cliente moviendo los elementos restantes hacia atrás
        for (int i = indiceEliminar; i < numClientes - 1; ++i) {
            clientes[i] = clientes[i + 1];
        }
        numClientes--;
        cout << "Cliente eliminado exitosamente." << endl;

        // Guardar los cambios en el archivo
        guardarClientes();
    } else {
        cout << "No se encontró ningún cliente con el ID especificado." << endl;
    }
}