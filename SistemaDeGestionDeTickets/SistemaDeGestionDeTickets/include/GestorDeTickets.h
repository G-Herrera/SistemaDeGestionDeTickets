#pragma once
#include "Ticket.h"

/**
 * @class GestorDeTickets
 * @brief Clase para gestionar una coleccion de tickets.
 * 
 *	La clase proporciona metodos para agregar, eliminar, editar y listar tickets.
 * Ademas, permite modificar atributos individuales de los tickets y 
 *	verificar su existencia.
 */

class
	GestorDeTickets {
public:
	/**
	 * @brief Constructor por defecto.
	 */
	GestorDeTickets() = default;
	~GestorDeTickets() = default;

	/**
	 * @brief Agrega un nuevo ticket a la lista.
	 * @param ticket El ticket a agregar.
	 * 
	 * Este metodo permite agregar un nuevo ticket a la lista de tickets.
	 */
	void
	agregarTicket(const Ticket& ticket) {
		if (m_tickets.empty()) {
			m_tickets.push_back(ticket);
			m_tickets[0].setId(1);
		}
		else {
			m_tickets.push_back(ticket);
			m_tickets.back().setId(m_tickets[m_tickets.size() - 2].getId() + 1);
		}
	};

	/**
	 * @brief Inserta un nuevo titulo al ticket actual.
	 * @param Titulo El titulo a insertar.
	 */
	void
	insertarTitulo(std::string Titulo) {
		if (!m_tickets.empty()) {
			m_tickets.back().setTitulo(Titulo);
		}
	};

	/**
	 * @brief Inserta una nueva descripcion al ticket actual.
	 * @param Descripcion La descripcion a insertar.
	 */
	void
	insertarDescripcion(std::string Descripcion) {
		if (!m_tickets.empty()) {
			m_tickets.back().setDescripcion(Descripcion);
		}
	};

	/**
	 * @brief Inserta un nuevo estado al ticket actual.
	 * @param Estado El estado a insertar.
	 */
	void
	insertarEstado(EstadoTicket estado) {
		if (!m_tickets.empty()) {
			m_tickets.back().setEstado(estado);
		}
	};

	/**
	 * @brief Inserta una nueva fecha al ticket actual.
	 * @param fechaTicket La fecha a insertar.
	 */
	void
	insertarFecha(Fecha fechaTicket) {
		if (!m_tickets.empty()) {
			m_tickets.back().setFechaTicket(fechaTicket);
		}
	};

	/**
	 * @brief Elimina un ticket de la lista.
	 * @param id El ID del ticket a eliminar.
	 *
	 * Este metodo permite eliminar un ticket de la lista de tickets basado en su ID.
	 */
	void
	eliminarTicket(int id) {
		m_tickets.erase
		(std::remove_if(
			m_tickets.begin(),
			m_tickets.end(),
			[id](const Ticket& ticket) { return ticket.getId() == id; }
		),
			m_tickets.end());
	};

	/*
	 * @brief Edita un ticket existente.
	 * @param id El ID del ticket a editar.
	 * @param nuevoTicket El nuevo ticket con la informacion actualizada.
	 */
	void
	editarTicket(int id, const Ticket& nuevoTicket) {
		for (auto& ticket : m_tickets) {
			if (ticket.getId() == id) {
				ticket = nuevoTicket;
				break;
			}
		}
	};

	/**
	 * @brief Lista todos los tickets.
	 *
	 * Este metodo permite listar todos los tickets en la coleccion, imprimiendo su titulo,
	 * descripcion, estado y fecha.
	 */
	void
	listarTickets() const {
		for (const auto& ticket : m_tickets) {
			std::cout << "ID: " << ticket.getId() << ", Titulo: " << ticket.getTitulo()
				<< ", Descripcion: " << ticket.getDescripcion() << ", Estado: " <<
				ticket.getEstado() << ", Fecha: " <<
				ticket.getFechaTicket().toString(ticket.getFechaTicket().dia,
					ticket.getFechaTicket().mes, ticket.getFechaTicket().anio,
					ticket.getFechaTicket().hora, ticket.getFechaTicket().mins,
					ticket.getFechaTicket().segs) << std::endl;
		}
	};

	/**
	 * @brief Obtiene un ticket por su ID.
	 * @param id El ID del ticket a obtener.
	 * @param ticket El ticket obtenido.
	 * @return El ticket obtenido.
	 *
	 * Este metodo permite obtener un ticket de la lista de tickets basado en su ID, con la
	 * finalidad de editarlo posteriormente.
	 */
	Ticket
	obtenerTicket(int id, Ticket& ticket) const {
		for (const auto& t : m_tickets) {
			if (t.getId() == id) {
				ticket = t;
				return ticket;
			}
		}
	};

	/**
	 * @brief Verifica si un ticket existe en la lista.
	 * @param id El ID del ticket a verificar.
	 * @return true si el ticket existe, false en caso contrario.
	 */
	bool 
	ticketExiste(int id) const {
		for (const auto& ticket : m_tickets) {
			if (ticket.getId() == id) {
				return true;
			}
		}
		return false;
	};

	/**
	 * @brief Verifica si la lista de tickets está vacía.
	 * @return true si la lista está vacía, false en caso contrario.
	 */
	bool 
	listaVacia() const {
		return m_tickets.empty();
	};

	/**
	 * @brief Modifica el título de un ticket existente.
	 * @param id El ID del ticket a modificar.
	 * @param nuevoTitulo El nuevo título del ticket.
	 * 
	 * Identifica el ticket por su ID y actualiza su título con el nuevo valor proporcionado.
	 */
	void
	modificarTituloTicket(int id, const std::string& nuevoTitulo) {
		for (auto& ticket : m_tickets) {
			if (ticket.getId() == id) {
				ticket.setTitulo(nuevoTitulo);
				break;
			}
		}
	};

	/**
	 * @brief Modifica la descripción de un ticket existente.
	 * @param id El ID del ticket a modificar.
	 * @param nuevaDescripcion La nueva descripción del ticket.
	 *
	 * Identifica el ticket por su ID y actualiza su descripción con el nuevo 
	 *	valor proporcionado.
	 */
	void
	modificarDescripcionTicket(int id, const std::string& nuevaDescripcion) {
		for (auto& ticket : m_tickets) {
			if (ticket.getId() == id) {
				ticket.setDescripcion(nuevaDescripcion);
				break;
			}
		}
	};

	/**
	 * @brief Cambia el estado de un ticket existente.
	 * @param id El ID del ticket a modificar.
	 *
	 * Identifica el ticket por su ID y actualiza su estado al siguiente en la secuencia.
	 */
	void
	cambiarEstadoTicket(int id) {
		int estadoAnterior = 0;
		for (const auto& ticket : m_tickets) {
			if (ticket.getId() == id) {
				estadoAnterior = ticket.getEstado();
				break;
			}
		}
		switch (estadoAnterior)
		{
		case 1:
			/**
			 * @brief Opcion 1: Cambia el estado de PENDIENTE a ENPROGRESO.
			 */
			m_tickets[id - 1].setEstado(ENPROGRESO);
			break;
		case 2:
			/**
			 * @brief Opcion 2: Cambia el estado de ENPROGRESO a RESUELTO.
			 */
			m_tickets[id - 1].setEstado(RESUELTO);
			break;
		default:
			break;
		}
	};

	/**
	 * @brief Obtiene el estado de un ticket por su ID.
	 * @param id El ID del ticket a obtener.
	 * @return El estado del ticket como una cadena.
	 */
	std::string
	getEstadoTicket(int id) {
		for (const auto& ticket : m_tickets) {
			if (ticket.getId() == id) {
				return std::to_string(ticket.getEstado());
			}
		}
		return "No encontrado";
	};

	/*
	 * @brief Elimina todos los tickets.
	 */
	void 
	eliminarTodosLosTickets() {
		m_tickets.clear();
	};

private:
	std::vector<Ticket> m_tickets; ///< Vector para almacenar los tickets
};

