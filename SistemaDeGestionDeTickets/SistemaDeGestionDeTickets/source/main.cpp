#include "Prerequisites.h"
#include "Ticket.h"
#include "GestorDeTickets.h"


int main() {
	
	Fecha fechaActual;
	int op,id, estadoInt=1;
	char opcion;
	std::string titulo, descripcion;
	EstadoTicket estado;
	GestorDeTickets gestor;
	Ticket ticketActual;
	bool listaVacia, ticketEncontrado;
	do {
		fechaActual.getFechaActual();
		system("cls");
		std::cout << "Sistema de tickets\n";
		std::cout<<"--SELECCIONA UNA OPCIÓN--\n";
		std::cout << "1. Crear ticket\n";
		std::cout << "2. Listar tickets\n";
		std::cout << "3. Editar ticket\n";
		std::cout << "4. Eliminar ticket\n";
		std::cout << "5. Eliminar todos los tickets\n";
		std::cout << "6. Salir\n";
		std::cin >> op;
		std::cin.ignore(); // Limpiar el buffer de entrada
		switch (op) {
			case 1:
				std::cout << "Crear ticket\n";
				std::cout << "Ingrese el titulo del ticket: ";
				std::getline(std::cin, titulo);
				std::cout << "Ingrese la descripcion del ticket: ";
				std::getline(std::cin, descripcion);
				estado = static_cast<EstadoTicket>(estadoInt);
				gestor.agregarTicket(ticketActual);
				gestor.insertarTitulo(titulo);
				gestor.insertarDescripcion(descripcion);
				gestor.insertarEstado(estado);
				gestor.insertarFecha(fechaActual);
				
				break;
			case 2:
				if (gestor.listaVacia()) {
					std::cout << "No hay tickets para mostrar.\n";
					system("pause");
					break;
				}
				std::cout << "Listar tickets\n";
				gestor.listarTickets();
				system("pause");
				break;
			case 3:
				if (gestor.listaVacia()) {
					std::cout << "No hay tickets para editar.\n";
					system("pause");
					break;
				}
				std::cout << "Editar ticket\n";
				gestor.listarTickets();
				do {
					std::cout << "Ingrese el ID del ticket a editar: ";
					std::cin >> id;
					std::cin.ignore(); // Limpiar el buffer de entrada
					ticketEncontrado = gestor.ticketExiste(id);
					if (!ticketEncontrado) {
						std::cout << "Ticket no encontrado. Intente de nuevo.\n";
					}
				} while (!ticketEncontrado);
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
					ticketActual=gestor.obtenerTicket(id, ticketActual);
					titulo = ticketActual.getTitulo();
					descripcion = ticketActual.getDescripcion();
					estado = ticketActual.getEstado();
					fechaActual = ticketActual.getFechaTicket();
					switch (op) {
					case 1:
						std::cout << "Ingrese el nuevo titulo del ticket: ";
						std::getline(std::cin, titulo);
						gestor.modificarTituloTicket(id, titulo);
						break;
					case 2:
						std::cout << "Ingrese la nueva descripcion del ticket: ";
						std::getline(std::cin, descripcion);
						gestor.modificarDescripcionTicket(id, descripcion);
						break;
					case 3:
						std::cout << "El estado del ticket se actualizará al siguiente en"; 
						std::cout<< "la secuencia(PENDIENTE->ENPROGRESO->RESUELTO)" <<std::endl;
						gestor.cambiarEstadoTicket(id);
						std::cout << "Estado actualizado." << std::endl;
						std::cout << "El nuevo estado es : " << gestor.getEstadoTicket(id) << std::endl;
						system("pause");
						break;
					case 4:
						std::cout << "Ingrese el nuevo titulo del ticket: ";
						std::getline(std::cin, titulo);
						gestor.modificarTituloTicket(id, titulo);
						std::cout << "Ingrese la nueva descripcion del ticket: ";
						std::getline(std::cin, descripcion);
						gestor.modificarDescripcionTicket(id, descripcion);
						do {
							std::cout << "Quieres mantener el estado actual? (s/n): ";
							std::cin >> opcion;
							std::cin.ignore(); // Limpiar el buffer de entrada
							if (opcion == 's' || opcion == 'S') {
								break;
							}
							else if (opcion =='n' || opcion == 'N') {
								gestor.cambiarEstadoTicket(id);
							}
							else {
								std::cout << "Opción no válida. Intente de nuevo.\n";
							}
						} while (opcion != 'n' && opcion != 'N' && opcion!='s' && opcion!='S');
						break;
					default:
						if (op != 5) {
							std::cout << "Opción no válida. Intente de nuevo.\n";
						}
						break;
					}
				} while (op!=5);
				break;
			case 4:
				if (gestor.listaVacia()) {
					std::cout << "No hay tickets para eliminar.\n";
					system("pause");
					break;
				}
				std::cout << "Eliminar ticket\n";
				gestor.listarTickets();
				do {
					std::cout << "Ingrese el ID del ticket a editar: ";
					std::cin >> id;
					std::cin.ignore(); // Limpiar el buffer de entrada
					ticketEncontrado = gestor.ticketExiste(id);
					if (!ticketEncontrado) {
						std::cout << "Ticket no encontrado. Intente de nuevo.\n";
					}
				} while (!ticketEncontrado);
				gestor.eliminarTicket(id);
				std::cout << "Ticket eliminado.\n";
				system("pause");
				break;
			case 5:
				if (gestor.listaVacia()) {
					std::cout << "No hay tickets para eliminar.\n";
					system("pause");
					break;
				}
				std::cout << "Eliminar todos los tickets\n";
				gestor.eliminarTodosLosTickets();
				std::cout << "Todos los tickets han sido eliminados.\n";
				system("pause");
				break;
			default:
				break;
			}
	} while (op!=6);
	return 0;
}