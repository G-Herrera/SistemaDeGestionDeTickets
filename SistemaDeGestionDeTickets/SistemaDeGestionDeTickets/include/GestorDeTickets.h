#pragma once
#include "Ticket.h"

class 
GestorDeTickets {
public:
	GestorDeTickets()=default;
	~GestorDeTickets()=default;
	
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
	void insertarTitulo(std::string Titulo) {
		if (!m_tickets.empty()) {
			m_tickets.back().setTitulo(Titulo);
		}
	}
	/*
	void
	agregarTicket(int id, std::string titulo, std::string descripcion, EstadoTicket estado,
		Fecha fechaTicket) {
		m_tickets.push_back(Ticket(id, titulo, descripcion, estado, fechaTicket));
	};
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

	void cambiarEstadoTicket(int id) {
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
		
	}

	std::string
	getEstadoTicket(int id) {
		for (const auto& ticket : m_tickets) {
			if (ticket.getId() == id) {
				return std::to_string(ticket.getEstado());
			}
		}
		return "No encontrado";
	};
private:
	std::vector<Ticket> m_tickets;
};

