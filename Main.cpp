#include <iostream>
#include "modelo.hpp"

int main() {
    Carro* carros = nullptr;
    Cliente* clientes = nullptr;
    int numCarros = 0;
    int numClientes = 0;
    
    // Cargar datos al inicio del programa
    cargarDatosCarros(carros, numCarros);
    cargarDatosClientes(clientes, numClientes);

    int opcion;
    do {
        std::cout << "\nOPCIONES\n";
        std::cout << "1. Mostrar información de un vehiculo\n";
        std::cout << "2. Agregar un cliente\n";
        std::cout << "3. Mostrar lista de clientes\n";
        std::cout << "4. Eliminar cliente\n";
        std::cout << "5. Agregar un vehiculo\n";
        std::cout << "6. Salir del programa\n\n";
        std::cout << "Ingrese su opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                int idCarro;
                std::cout << "Ingrese el ID del vehículo: ";
                std::cin >> idCarro;
                // Buscar el carro por ID e imprimir su información si se encuentra
                for (int i = 0; i < numCarros; ++i) {
                    if (carros[i].id == idCarro) {
                        mostrarInfoCarro(carros[i], clientes, numClientes);
                        break;
                    }
                    if (i == numCarros - 1) {
                        std::cout << "No se encontró ningún vehículo con el ID especificado." << std::endl;
                    }
                }
                break;
            case 2:
                agregarCliente(clientes, numClientes);
                break;
            case 3:
                mostrarClientes(clientes, numClientes);
                break;
            case 4:
                int idCliente;
                std::cout << "Ingrese el ID del cliente a eliminar: ";
                std::cin >> idCliente;
                eliminarCliente(clientes, numClientes, idCliente);
                break;
            case 5:
                agregarCarro(carros, numCarros);
                break;
            case 6:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opción inválida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 6);

    delete[] carros; // Liberar memoria asignada al arreglo de carros
    delete[] clientes; // Liberar memoria asignada al arreglo de clientes

    return 0;
}
