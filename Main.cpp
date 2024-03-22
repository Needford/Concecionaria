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
