#pragma once
#include "Prerequisites.h"

class Ticket
{
public:
	Ticket(int id, std::string título, std::string descripcion, EstadoTicket estado, 
	Fecha fechaTicket): m_id(id), m_título(título), m_descripcion(descripcion), 
	m_estado(estado), m_fechaTicket(fechaTicket) {};
	~Ticket();

	void 
	agregarTicket(int id, std::string título, std::string descripcion, 
	EstadoTicket estado, Fecha fechaTicket) {
		m_id = id;
		m_título = título;
		m_descripcion = descripcion;
		m_estado = estado;
		m_fechaTicket = fechaTicket;
	};

	void 
	eliminarTicket() {
		m_id = 0;
		m_título = "";
		m_descripcion = "";
		m_estado = PENDIENTE;
		m_fechaTicket = { 0,0,0 };
	};

	void 
	editarTicket(std::string título, std::string descripcion,EstadoTicket estado) {
		m_título = título;
		m_descripcion = descripcion;
		m_estado = estado;
	};

private:
	int m_id;
	std::string m_título;
	std::string m_descripcion;
	EstadoTicket m_estado;
	Fecha m_fechaTicket;
};


