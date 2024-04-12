#ifndef MODELO_HPP
#define MODELO_HPP

#include <string>

class Carro {
public:
    Carro(int id, const std::string& marca, const std::string& modelo, int ano, int vendido_a, int comprado_a,
          double precio_venta, double precio_compra, const std::string& cliente, bool vendido);

    // Métodos de acceso
    int getId() const;
    std::string getMarca() const;
    std::string getModelo() const;
    int getAno() const;
    int getVendidoA() const;
    int getCompradoA() const;
    double getPrecioVenta() const;
    double getPrecioCompra() const;
    std::string getCliente() const;
    bool estaVendido() const;

private:
    int id;
    std::string marca;
    std::string modelo;
    int ano;
    int vendido_a;
    int comprado_a;
    double precio_venta;
    double precio_compra;
    std::string cliente;
    bool vendido;
};

class Cliente {
public:
    Cliente(int id, const std::string& nombre, const std::string& apellido, const std::string& correo, int edad);

    // Métodos de acceso
    int getId() const;
    std::string getNombre() const;
    std::string getApellido() const;
    std::string getCorreo() const;
    int getEdad() const;

private:
    int id;
    std::string nombre;
    std::string apellido;
    std::string correo;
    int edad;
};

void cargarDatosCarros(Carro**& carros, int& numCarros);
void cargarDatosClientes(Cliente**& clientes, int& numClientes);
void guardarClientes(const Cliente** clientes, int numClientes);
void agregarCliente(Cliente**& clientes, int& numClientes);
void mostrarClientes(const Cliente** clientes, int numClientes);
void eliminarCliente(Cliente**& clientes, int& numClientes, int idCliente);
void agregarCarro(Carro**& carros, int& numCarros);
void mostrarInfoCarro(const Carro& carro, const Cliente** clientes, int numClientes);

#endif
