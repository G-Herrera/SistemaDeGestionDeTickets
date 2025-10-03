#include "Prerequisites.h"
#include "Ticket.h"
#include "GestorDeTickets.h"

/**
 * @file main.cpp
 * @brief Programa principal para el sistema de gestion de tickets.
 * @author Gerardo Herrera
 * @date 2024-06-10
 * Este archivo contiene la funcion principal del programa que maneja el menu del sistema,
 * permitiendo al usuario crear, listar, editar y eliminar tickets.
 */

/**
 * @brief Funcion principal del programa.
 * @return Codigo de salida del programa.
 *
 * La funcion muestra un menu interactivo que permite al usario:
 * - Crear un nuevo ticket
 * - Listar todos los tickets
 * - Editar un ticket existente
 * - Eliminar un ticket
 * - Eliminar todos los tickets
 * 
 * El programa utiliza las clases Fecha, Ticket y GestorDeTickets para manejar la logica.
 * El menu se repite hasta que el usuario decide salir.
 */
int main() {
	Fecha g_fechaActual;	///< Objeto para manejar la fecha actual
	EstadoTicket g_estado; 	///< Variable para manejar el estado del ticket
	GestorDeTickets g_gestor; ///< Objeto para gestionar los tickets
	Ticket g_ticketActual; ///< Objeto para manejar el ticket actual
	int g_op, g_id, g_estadoInt = 1; ///< Variables para manejar opciones y IDs
	char opcion; ///< Variable para manejar opciones de usuario
	std::string g_titulo, g_descripcion; ///< Variables para manejar titulo y descripcion
	bool g_listaVacia, g_ticketEncontrado; ///< Variables para verificar estado de la lista y existencia de tickets
	do {
		g_fechaActual.getFechaActual();
		system("cls");
		std::cout << "Sistema de tickets\n";
		std::cout<<"--SELECCIONA UNA OPCION--\n";
		std::cout << "1. Crear ticket\n";
		std::cout << "2. Listar tickets\n";
		std::cout << "3. Editar ticket\n";
		std::cout << "4. Eliminar ticket\n";
		std::cout << "5. Eliminar todos los tickets\n";
		std::cout << "6. Eliminar tickets completados\n";
		std::cout << "7. Salir\n";
		std::cin >> g_op;
		std::cin.ignore(); // Limpiar el buffer de entrada
		switch (g_op) {
		case 1:
			/**
			 * @brief Opcion 1: Crear un nuevo ticket.
			 *
			 * Se solicita al usuario ingresar el titulo y la descripcion del ticket.
			 * luego, se establece el estado inicial del ticket como PENDIENTE.
			 * Por ultimo, se agrega el ticket al gestor.
			 */
			std::cout << "Crear ticket\n";
			std::cout << "Ingrese el titulo del ticket: ";
			std::getline(std::cin, g_titulo);
			std::cout << "Ingrese la descripcion del ticket: ";
			std::getline(std::cin, g_descripcion);
			g_estado = static_cast<EstadoTicket>(g_estadoInt);
			g_gestor.agregarTicket(g_ticketActual);
			g_gestor.insertarTitulo(g_titulo);
			g_gestor.insertarDescripcion(g_descripcion);
			g_gestor.insertarEstado(g_estado);
			g_gestor.insertarFecha(g_fechaActual);

			break;
		case 2:
			/**
			 * @brief Opcion 2: Listar todos los tickets.
			 *
			 * Se verifica si la lista de tickets está vacía. Si es así, se informa al usuario.
			 * Si hay tickets, se llaman a los métodos del gestor para listar los tickets.
			 */
			if (g_gestor.listaVacia()) {
				std::cout << "No hay tickets para mostrar.\n";
				system("pause");
				break;
			}
			std::cout << "Listar tickets\n";
			g_gestor.listarTickets();
			system("pause");
			break;
		case 3:
			/**
			 * @brief Opcion 3: Editar un ticket existente.
			 *
			 * Se verifica si la lista de tickets está vacía. Si es así, se informa al usuario.
			 * Si hay tickets, se muestran los tickets y se solicita el ID del ticket a editar.
			 * Si el ticket existe, se muestra un submenú para editar el titulo, descripcion,
			 * estado o todo el ticket.
			 */
			if (g_gestor.listaVacia()) {
				std::cout << "No hay tickets para editar.\n";
				system("pause");
				break;
			}
			std::cout << "Editar ticket\n";
			g_gestor.listarTickets();
			do {
				std::cout << "Ingrese el ID del ticket a editar: ";
				std::cin >> g_id;
				std::cin.ignore(); // Limpiar el buffer de entrada
				g_ticketEncontrado = g_gestor.ticketExiste(g_id);
				if (!g_ticketEncontrado) {
					std::cout << "Ticket no encontrado. Intente de nuevo.\n";
				}
			} while (!g_ticketEncontrado);
			do
			{
				system("cls");
				std::cout << "--SELECCIONA UNA OPCION--\n";
				std::cout << "1. Editar titulo\n";
				std::cout << "2. Editar descripcion\n";
				std::cout << "3. Editar estado\n";
				std::cout << "4. Editar todo\n";
				std::cout << "5. Volver al menu principal\n";
				std::cin >> g_op;
				std::cin.ignore(); // Limpiar el buffer de entrada
				g_ticketActual = g_gestor.obtenerTicket(g_id, g_ticketActual);
				g_titulo = g_ticketActual.getTitulo();
				g_descripcion = g_ticketActual.getDescripcion();
				g_estado = g_ticketActual.getEstado();
				g_fechaActual = g_ticketActual.getFechaTicket();
				switch (g_op) {
				case 1:
					/**
					 * @brief Opcion 1: Editar el titulo del ticket.
					 *
					 * Se solicita al usuario ingresar el nuevo titulo del ticket.
					 */
					std::cout << "Ingrese el nuevo titulo del ticket: ";
					std::getline(std::cin, g_titulo);
					g_gestor.modificarTituloTicket(g_id, g_titulo);
					break;
				case 2:
					/**
					 * @brief Opcion 2: Editar la descripcion del ticket.
					 *
					 * Se solicita al usuario ingresar la nueva descripcion del ticket.
					 */
					std::cout << "Ingrese la nueva descripcion del ticket: ";
					std::getline(std::cin, g_descripcion);
					g_gestor.modificarDescripcionTicket(g_id, g_descripcion);
					break;
				case 3:
					/**
					 * @brief Opcion 3: Editar el estado del ticket.
					 *
					 * Se informa al usuario sobre la secuencia de estados y se cambia el estado
					 * del ticket.
					 */
					std::cout << "El estado del ticket se actualizara al siguiente en";
					std::cout << "la secuencia(PENDIENTE->ENPROGRESO->RESUELTO)" << std::endl;
					g_gestor.cambiarEstadoTicket(g_id);
					std::cout << "Estado actualizado." << std::endl;
					std::cout << "El nuevo estado es : " << g_gestor.estadoToString(g_gestor.obtenerTicket(g_id, g_ticketActual).getEstado()) << std::endl;
					system("pause");
					break;
				case 4:
					/**
					 * @brief Opcion 4: Editar todo el ticket.
					 *
					 * Se solicita al usuario ingresar los nuevos datos del ticket. Se pregunta
					 * si desea mantener el estado actual ya que este se actualiza automaticamente.
					 */
					std::cout << "Ingrese el nuevo titulo del ticket: ";
					std::getline(std::cin, g_titulo);
					g_gestor.modificarTituloTicket(g_id, g_titulo);
					std::cout << "Ingrese la nueva descripcion del ticket: ";
					std::getline(std::cin, g_descripcion);
					g_gestor.modificarDescripcionTicket(g_id, g_descripcion);
					do {
						std::cout << "Quieres mantener el estado actual? (s/n): ";
						std::cin >> opcion;
						std::cin.ignore(); // Limpiar el buffer de entrada
						if (opcion == 's' || opcion == 'S') {
							break;
						}
						else if (opcion == 'n' || opcion == 'N') {
							g_gestor.cambiarEstadoTicket(g_id);
						}
						else {
							std::cout << "Opcion no valida. Intente de nuevo.\n";
						}
					} while (opcion != 'n' && opcion != 'N' && opcion != 's' && opcion != 'S');
					break;
				default:
					if (g_op != 5) {
						std::cout << "Opcion no valida. Intente de nuevo.\n";
					}
					break;
				}
			} while (g_op != 5);
			break;
		case 4:
			/**
			 * @brief Opcion 4: Eliminar un ticket.
			 *
			 * Se verifica si la lista de tickets está vacía. Si es así, se informa al usuario.
			 * Se solicita al usuario ingresar el ID del ticket a eliminar. Si el ticket existe,
			 * se procede a eliminarlo. Sino, se informa al usuario que el ticket no fue
			 * encontrado.
			 */
			if (g_gestor.listaVacia()) {
				std::cout << "No hay tickets para eliminar.\n";
				system("pause");
				break;
			}
			std::cout << "Eliminar ticket\n";
			g_gestor.listarTickets();
			do {
				std::cout << "Ingrese el ID del ticket a editar: ";
				std::cin >> g_id;
				std::cin.ignore(); // Limpiar el buffer de entrada
				g_ticketEncontrado = g_gestor.ticketExiste(g_id);
				if (!g_ticketEncontrado) {
					std::cout << "Ticket no encontrado. Intente de nuevo.\n";
				}
			} while (!g_ticketEncontrado);
			g_gestor.eliminarTicket(g_id);
			std::cout << "Ticket eliminado.\n";
			system("pause");
			break;
		case 5:
			/**
			 * @brief Opcion 5: Eliminar todos los tickets.
			 *
			 * Se verifica si la lista de tickets está vacía. Si es así, se informa al usuario.
			 * Si hay tickets, se procede a eliminarlos.
			 */
			if (g_gestor.listaVacia()) {
				std::cout << "No hay tickets para eliminar.\n";
				system("pause");
				break;
			}
			std::cout << "Eliminar todos los tickets\n";
			g_gestor.eliminarTodosLosTickets();
			std::cout << "Todos los tickets han sido eliminados.\n";
			system("pause");
			break;
		case 6:
			/**
			 * @brief Opcion 6: Eliminar tickets completados.
			 *
			 * Se verifica si la lista de tickets está vacía. Si es así, se informa al usuario.
			 * Si hay tickets, se procede a eliminar aquellos que han sido resueltos.
			 */
			if (g_gestor.listaVacia()) {
					std::cout << "No hay tickets para eliminar.\n";
					system("pause");
					break;
			}
			std::cout << "Eliminar ticket completados \n";
			g_gestor.eliminarTicketsCompletados();
			std::cout << "Tickets completados han sido eliminados.\n";
			system("pause");
			break;
			default:
				break;
			}
	} while (g_op!=7);
	return 0;
}