#pragma once
#include "Prerequisites.h"

class Ticket
{
public:
	Ticket(int id, std::string titulo, std::string descripcion, EstadoTicket estado,
		Fecha fechaTicket) : m_id(id), m_titulo(titulo), m_descripcion(descripcion),
		m_estado(estado), m_fechaTicket(fechaTicket) {
	};
	~Ticket() = default;
	//Getters
	int
	getId() const {
		return m_id;
	};

	std::string
	getTitulo() const {
		return m_titulo;
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
	setTitulo(const std::string& titulo) {
		m_titulo = titulo;
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
	std::string m_titulo;
	std::string m_descripcion;
	EstadoTicket m_estado;
	Fecha m_fechaTicket;
};


