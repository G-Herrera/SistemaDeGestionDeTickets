#pragma once
#include "Ticket.h"

class 
GestorDeTickets {
public:
	GestorDeTickets();
	~GestorDeTickets();

	void
	agregarTicket(const Ticket& ticket) {
		m_tickets.push_back(ticket);
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
			std::cout << "ID: " << ticket.getId() << ", Título: " << ticket.getTítulo()
			<< ", Descripción: " << ticket.getDescripcion() << ", Estado: " << 
			ticket.getEstado() << ", Fecha: " << 
			ticket.getFechaTicket().toString(ticket.getFechaTicket().dia,
			ticket.getFechaTicket().mes, ticket.getFechaTicket().anio,
			ticket.getFechaTicket().hora) << std::endl;
		}
	};

private:
	std::vector<Ticket> m_tickets;
};

