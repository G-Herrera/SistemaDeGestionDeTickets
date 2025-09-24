#pragma once
#include "Prerequisites.h"

class Ticket
{
public:
	Ticket(int id, std::string t�tulo, std::string descripcion, EstadoTicket estado,
		Fecha fechaTicket) : m_id(id), m_t�tulo(t�tulo), m_descripcion(descripcion),
		m_estado(estado), m_fechaTicket(fechaTicket) {
	};
	~Ticket() = default;
	//Getters
	int
	getId() const {
		return m_id;
	};

	std::string
	getT�tulo() const {
		return m_t�tulo;
	};

	std::string
	getDescripcion() const {
		return m_descripcion;
	};

	EstadoTicket
	getEstado() const {
		return m_estado;
	};

	Fecha
	getFechaTicket() const {
		return m_fechaTicket;
	};

	//Setters
	void 
	setT�tulo(const std::string& t�tulo) {
		m_t�tulo = t�tulo;
	};

	void 
	setDescripcion(const std::string& descripcion) {
		m_descripcion = descripcion;
	};

	void 
	setEstado(EstadoTicket estado) {
		m_estado = estado;
	};

	void 
	setFechaTicket() {
		Fecha fechaActual;
		m_fechaTicket = fechaActual;
	}
private:
	int m_id;
	std::string m_t�tulo;
	std::string m_descripcion;
	EstadoTicket m_estado;
	Fecha m_fechaTicket;
};


