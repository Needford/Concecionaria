#include "modelo.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

// Implementación de los constructores de Carro y Cliente
Carro::Carro(int id, const std::string& marca, const std::string& modelo, int ano, int vendido_a, int comprado_a,
          double precio_venta, double precio_compra, const std::string& cliente, bool vendido)
    : id(id), marca(marca), modelo(modelo), ano(ano), vendido_a(vendido_a), comprado_a(comprado_a),
      precio_venta(precio_venta), precio_compra(precio_compra), cliente(cliente), vendido(vendido) {}

Cliente::Cliente(int id, const std::string& nombre, const std::string& apellido, const std::string& correo, int edad)
    : id(id), nombre(nombre), apellido(apellido), correo(correo), edad(edad) {}

// Implementación de los métodos de acceso de Carro
int Carro::getId() const { return id; }
std::string Carro::getMarca() const { return marca; }
std::string Carro::getModelo() const { return modelo; }
int Carro::getAno() const { return ano; }
int Carro::getVendidoA() const { return vendido_a; }
int Carro::getCompradoA() const { return comprado_a; }
double Carro::getPrecioVenta() const { return precio_venta; }
double Carro::getPrecioCompra() const { return precio_compra; }
std::string Carro::getCliente() const { return cliente; }
bool Carro::estaVendido() const { return vendido; }

// Implementación de los métodos de acceso de Cliente
int Cliente::getId() const { return id; }
std::string Cliente::getNombre() const { return nombre; }
std::string Cliente::getApellido() const { return apellido; }
std::string Cliente::getCorreo() const { return correo; }
int Cliente::getEdad() const { return edad; }

void cargarDatosCarros(Carro**& carros, int& numCarros) {
    std::ifstream archivo("autos.csv");
    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo de carros." << std::endl;
        return;
    }

    std::string linea;
    getline(archivo, linea); // Leer la primera línea (encabezados) y descartarla

    while (getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string dato;

        getline(ss, dato, ';'); // Leer y asignar la ID
        carros[numCarros]->id = stoi(dato);

        getline(ss, carros[numCarros]->marca, ';'); // Leer y asignar la marca
        getline(ss, carros[numCarros]->modelo, ';'); // Leer y asignar el modelo

        getline(ss, dato, ';'); // Leer y asignar el año
        carros[numCarros]->ano = stoi(dato);

        getline(ss, dato, ';'); // Leer y asignar el cliente al que se vendió
        carros[numCarros]->vendido_a = stoi(dato);

        getline(ss, dato, ';'); // Leer y asignar el cliente al que se compró
        carros[numCarros]->comprado_a = stoi(dato);

        getline(ss, dato, ';'); // Leer y asignar el precio de venta
        carros[numCarros]->precio_venta = stod(dato);

        getline(ss, dato); // Leer y asignar el precio de compra
        carros[numCarros]->precio_compra = stod(dato);

        numCarros++;

        if (numCarros >= MAX_CARROS) {
            std::cout << "Se ha alcanzado el límite máximo de carros." << std::endl;
            break;
        }
    }

    archivo.close();
}

void cargarDatosClientes(Cliente**& clientes, int& numClientes) {
    std::ifstream archivo("clientes.csv");
    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo de clientes." << std::endl;
        return;
    }

    std::string linea;
    getline(archivo, linea); // Leer la primera línea (encabezados) y descartarla

    while (getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string dato;

        getline(ss, dato, ';'); // Leer y asignar la ID
        clientes[numClientes]->id = stoi(dato);

        getline(ss, clientes[numClientes]->nombre, ';'); // Leer y asignar el nombre
        getline(ss, clientes[numClientes]->apellido, ';'); // Leer y asignar el apellido

        getline(ss, clientes[numClientes]->correo, ';'); // Leer y asignar el correo

        getline(ss, dato); // Leer y asignar la edad
        clientes[numClientes]->edad = stoi(dato);

        numClientes++;

        if (numClientes >= MAX_CLIENTES) {
            std::cout << "Se ha alcanzado el límite máximo de clientes." << std::endl;
            break;
        }
    }

    archivo.close();
}

void guardarClientes(const Cliente** clientes, int numClientes) {
    std::ofstream archivo("clientes.csv");
    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo de clientes para guardar." << std::endl;
        return;
    }

    archivo << "id;nombre;apellido;correo;edad" << std::endl;
    for (int i = 0; i < numClientes; ++i) {
        archivo << clientes[i]->id << ';' << clientes[i]->nombre << ';' << clientes[i]->apellido << ';' << clientes[i]->correo << ';'
                << clientes[i]->edad << std::endl;
    }

    archivo.close();
}

void agregarCliente(Cliente**& clientes, int& numClientes) {
    if (numClientes >= MAX_CLIENTES) {
        std::cout << "No es posible agregar más clientes. Se ha alcanzado el límite máximo." << std::endl;
        return;
    }
    Cliente* nuevoCliente = new Cliente();
    nuevoCliente->id = 100 + numClientes; // Empezar desde 100 y aumentar en cada nuevo cliente
    std::cout << "Ingrese el nombre del cliente: ";
    std::cin >> nuevoCliente->nombre;
    std::cout << "Ingrese el apellido del cliente: ";
    std::cin >> nuevoCliente->apellido;
    std::cout << "Ingrese el correo del cliente: ";
    std::cin >> nuevoCliente->correo;
    std::cout << "Ingrese la edad del cliente: ";
    std::cin >> nuevoCliente->edad;
    clientes[numClientes] = nuevoCliente;
    numClientes++;
    guardarClientes(clientes, numClientes);
}

void mostrarClientes(const Cliente** clientes, int numClientes) {
    std::cout << "Lista de clientes:" << std::endl;
    for (int i = 0; i < numClientes; ++i) {
        std::cout << "ID: " << clientes[i]->id << ", Nombre: " << clientes[i]->nombre << ", Apellido: " << clientes[i]->apellido
             << ", Correo: " << clientes[i]->correo << ", Edad: " << clientes[i]->edad << std::endl;
    }
}

void eliminarCliente(Cliente**& clientes, int& numClientes, int idCliente) {
    int indiceEliminar = -1;
    for (int i = 0; i < numClientes; ++i) {
        if (clientes[i]->id == idCliente) {
            indiceEliminar = i;
            break;
        }
    }

    if (indiceEliminar != -1) {
        delete clientes[indiceEliminar];
        // Eliminar el cliente moviendo los elementos restantes hacia atrás
        for (int i = indiceEliminar; i < numClientes - 1; ++i) {
            clientes[i] = clientes[i + 1];
        }
        numClientes--;
        std::cout << "Cliente eliminado exitosamente." << std::endl;

        // Guardar los cambios en el archivo
        guardarClientes(clientes, numClientes);
    } else {
        std::cout << "No se encontró ningún cliente con el ID especificado." << std::endl;
    }
}

void agregarCarro(Carro**& carros, int& numCarros) {
    if (numCarros >= MAX_CARROS) {
        std::cout << "No es posible agregar más carros. Se ha alcanzado el límite máximo." << std::endl;
        return;
    }
    Carro* nuevoCarro = new Carro();
    nuevoCarro->id = 1000 + numCarros;
    std::cout << "Ingrese marca del carro: ";
    std::cin >> nuevoCarro->marca;
    std::cout << "Ingrese modelo del carro: ";
    std::cin >> nuevoCarro->modelo;
    std::cout << "Ingrese año del carro: ";
    std::cin >> nuevoCarro->ano;
    std::cout << "Ingrese el ID del cliente al que se vendió el carro: ";
    std::cin >> nuevoCarro->vendido_a;
    std::cout << "Ingrese el ID del cliente al que se compró el carro: ";
    std::cin >> nuevoCarro->comprado_a;
    std::cout << "Ingrese el precio de venta del carro: ";
    std::cin >> nuevoCarro->precio_venta;
    std::cout << "Ingrese el precio de compra del carro: ";
    std::cin >> nuevoCarro->precio_compra;
    carros[numCarros] = nuevoCarro;
    numCarros++;
    // Guardar los cambios en el archivo (si es necesario)
}

void mostrarInfoCarro(const Carro& carro, const Cliente** clientes, int numClientes) {
    std::string nombreVendedor, nombreComprador;

    // Buscar el nombre del cliente que vendió el carro
    for (int i = 0; i < numClientes; ++i) {
        if (clientes[i]->id == carro.vendido_a) {
            nombreVendedor = clientes[i]->nombre + " " + clientes[i]->apellido;
            break;
        }
    }

    // Buscar el nombre del cliente que compró el carro
    for (int i = 0; i < numClientes; ++i) {
        if (clientes[i]->id == carro.comprado_a) {
            nombreComprador = clientes[i]->nombre + " " + clientes[i]->apellido;
            break;
        }
    }

    // Mostrar la información completa del carro
    std::cout << "ID: " << carro.id << ", Marca: " << carro.marca << ", Modelo: " << carro.modelo
         << ", Año: " << carro.ano << ", Vendido por: " << nombreVendedor
         << ", Comprado por: " << nombreComprador << ", Precio de venta: " << carro.precio_venta
         << ", Precio de compra: " << carro.precio_compra << std::endl;
}
