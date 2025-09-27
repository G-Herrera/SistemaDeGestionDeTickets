#include "Prerequisites.h"
#include "Ticket.h"
#include "GestorDeTickets.h"


int main() {
	
	Fecha fechaActual;
	int op,id, estadoInt;;
	std::string titulo, descripcion;
	EstadoTicket estado;
	GestorDeTickets gestor;
	Ticket nuevoticket;
	do {
		fechaActual.getFechaActual();
		system("cls");
		std::cout << "Sistema de tickets\n";
		std::cout<<"--SELECCIONA UNA OPCIÓN--\n";
		std::cout << "1. Crear ticket\n";
		std::cout << "2. Listar tickets\n";
		std::cout << "3. Editar ticket\n";
		std::cout << "4. Eliminar ticket\n";
		std::cout << "5. Salir\n";
		std::cin >> op;
		std::cin.ignore(); // Limpiar el buffer de entrada
		switch (op) {
			case 1:
				std::cout << "Crear ticket\n";
				std::cout << "Ingrese el titulo del ticket: ";
				std::getline(std::cin, titulo);
				std::cout << "Ingrese la descripcion del ticket: ";
				std::getline(std::cin, descripcion);
				std::cout << "Ingrese el estado del ticket (1: PENDIENTE, 2: ENPROGRESO, 3: RESUELTO): ";
				std::cin >> estadoInt;
				estado = static_cast<EstadoTicket>(estadoInt);
				gestor.agregarTicket(nuevoticket);
				gestor.insertarTitulo(titulo);
				break;
			case 2:
				std::cout << "Listar tickets\n";
				gestor.listarTickets();
				system("pause");
				break;
			/*
			case 3:
				std::cout << "Editar ticket\n";
				gestor.listarTickets();
				std::cout << "Ingrese el ID del ticket a editar: ";
				std::cin >> id;
				std::cin.ignore(); // Limpiar el buffer de entrada
				do
				{
					system("cls");
					std::cout << "--SELECCIONA UNA OPCIÓN--\n";
					std::cout << "1. Editar titulo\n";
					std::cout << "2. Editar descripcion\n";
					std::cout << "3. Editar estado\n";
					std::cout << "4. Editar todo\n";
					std::cout << "5. Volver al menú principal\n";
					std::cin >> op;
					std::cin.ignore(); // Limpiar el buffer de entrada
					switch (op) {
					case 1:
						std::cout << "Ingrese el nuevo titulo del ticket: ";
						std::getline(std::cin, titulo);
						gestor.editarTicket(id, Ticket(id, titulo, descripcion, estado, fechaActual));
						break;
					case 2:
						std::cout << "Ingrese la nueva descripcion del ticket: ";
						std::getline(std::cin, descripcion);
						gestor.editarTicket(id, Ticket(id, titulo, descripcion, estado, fechaActual));
						break;
					case 3:
						std::cout << "El estado del ticket se actualizará al siguiente en"; 
						std::cout<< "la secuencia(PENDIENTE->ENPROGRESO->RESUELTO)" <<std::endl;
						gestor.cambiarEstadoTicket(id);
						std::cout << "Estado actualizado." << std::endl;
						std::cout << "El nuevo estado es : " << gestor.getEstadoTicket(id) << std::endl;
						system("pause");
						/*
						std::cout << "Ingrese el nuevo estado del ticket (1: PENDIENTE, 2: ENPROGRESO, 3: RESUELTO): ";
						std::cin >> estadoInt;
						std::cin.ignore(); // Limpiar el buffer de entrada
						estado = static_cast<EstadoTicket>(estadoInt);
						gestor.editarTicket(id, Ticket(id, titulo, descripcion, estado, fechaActual));
						break;
					case 4:
						break;
					default:
						if (op != 5) {
							std::cout << "Opción no válida. Intente de nuevo.\n";
						}
						break;
					}
				} while (op!=5);
				op = 0;
				break;*/
				default:
				break;
			}
	} while (op!=5);
	
	return 0;
}