#pragma once
#include "Ticket.h"

class
	GestorDeTickets {
public:
	GestorDeTickets() = default;
	~GestorDeTickets() = default;

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

	void
	insertarTitulo(std::string Titulo) {
		if (!m_tickets.empty()) {
			m_tickets.back().setTitulo(Titulo);
		}
	};

	void
	insertarDescripcion(std::string Descripcion) {
		if (!m_tickets.empty()) {
			m_tickets.back().setDescripcion(Descripcion);
		}
	};

	void
	insertarEstado(EstadoTicket estado) {
		if (!m_tickets.empty()) {
			m_tickets.back().setEstado(estado);
		}
	};

	void
	insertarFecha(Fecha fechaTicket) {
		if (!m_tickets.empty()) {
			m_tickets.back().setFechaTicket(fechaTicket);
		}
	};

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

	void
	editarTicket(int id, const Ticket& nuevoTicket) {
		for (auto& ticket : m_tickets) {
			if (ticket.getId() == id) {
				ticket = nuevoTicket;
				break;
			}
		}
	};

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

	Ticket
	obtenerTicket(int id, Ticket& ticket) const {
		for (const auto& t : m_tickets) {
			if (t.getId() == id) {
				ticket = t;
				return ticket;
			}
		}
	};

	bool 
	ticketExiste(int id) const {
		for (const auto& ticket : m_tickets) {
			if (ticket.getId() == id) {
				return true;
			}
		}
		return false;
	};

	bool 
	listaVacia() const {
		return m_tickets.empty();
	};

	void
	modificarTituloTicket(int id, const std::string& nuevoTitulo) {
		for (auto& ticket : m_tickets) {
			if (ticket.getId() == id) {
				ticket.setTitulo(nuevoTitulo);
				break;
			}
		}
	};

	void
	modificarDescripcionTicket(int id, const std::string& nuevaDescripcion) {
		for (auto& ticket : m_tickets) {
			if (ticket.getId() == id) {
				ticket.setDescripcion(nuevaDescripcion);
				break;
			}
		}
	};

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
			m_tickets[id - 1].setEstado(ENPROGRESO);
			break;
		case 2:
			m_tickets[id - 1].setEstado(RESUELTO);
			break;
		default:
			break;
		}
	};

	std::string
	getEstadoTicket(int id) {
		for (const auto& ticket : m_tickets) {
			if (ticket.getId() == id) {
				return std::to_string(ticket.getEstado());
			}
		}
		return "No encontrado";
	};

	void 
	eliminarTodosLosTickets() {
		m_tickets.clear();
	};

private:
	std::vector<Ticket> m_tickets;
};

