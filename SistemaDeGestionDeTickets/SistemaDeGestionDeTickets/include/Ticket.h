#pragma once
#include "Prerequisites.h"

/*
 * @class Ticket
 *	@brief Clase que representa un ticket en el sistema de gestion de tickets.
 * 
 * La clase Ticket encapsula los atributos y metodos relacionados con un ticket, contiene
 * informacion como ID, titulo, descripcion, estado y fecha de creacion.
 */
class Ticket
{
public:
	/**
	 * @brief Constructor y Destructor por defecto.
	 */
	Ticket() = default;
	~Ticket() = default;
	//Getters
	/**
	 * @brief Obtiene el ID del ticket.
	 * @return El ID del ticket.
	 */
	int
	getId() const {
		return m_id;
	};

	/**
	 * @brief Obtiene el título del ticket.
	 * @return El título del ticket.
	 */
	std::string
	getTitulo() const {
		return m_titulo;
	};

	/**
	 * @brief Obtiene la descripción del ticket.
	 * @return La descripción del ticket.
	 */
	std::string
	getDescripcion() const {
		return m_descripcion;
	};

	/**
	 * @brief Obtiene el estado del ticket.
	 * @return El estado del ticket.
	 */
	EstadoTicket
	getEstado() const {
		return m_estado;
	};

	/**
	 * @brief Obtiene la fecha de creación del ticket.
	 * @return La fecha de creación del ticket.
	 */
	Fecha
	getFechaTicket() const {
		return m_fechaTicket;
	};

	//Setters
	/**
	 * @brief Establece el ID del ticket.
	 * @param id El nuevo ID del ticket.
	 * 
	 * Asigna un nuevo ID al ticket.
	 */
	void 
	setId(int id) {
		m_id = id;
	};

	/**
	 * @brief Establece el título del ticket.
	 * @param titulo El nuevo título del ticket.
	 * 
	 * Asigna un nuevo título al ticket.
	 */
	void 
	setTitulo(const std::string& titulo) {
		m_titulo = titulo;
	};

	/**
	 * @brief Establece la descripción del ticket.
	 * @param descripcion La nueva descripción del ticket.
	 * 
	 * Asigna una nueva descripción al ticket.
	 */
	void 
	setDescripcion(const std::string& descripcion) {
		m_descripcion = descripcion;
	};

	/**
	 * @brief Establece el estado del ticket.
	 * @param estado El nuevo estado del ticket.
	 * 
	 * Asigna un nuevo estado al ticket.
	 */
	void 
	setEstado(EstadoTicket estado) {
		m_estado = estado;
	};

	/**
	 * @brief Establece la fecha de creación del ticket.
	 * @param fechaTicket La nueva fecha de creación del ticket.
	 * 
	 * Asigna la fecha de creación al ticket.
	 */
	void 
	setFechaTicket(Fecha fechaTicket) {
		m_fechaTicket = fechaTicket;
	}
private:
	int m_id; ///< ID unico del ticket
	std::string m_titulo; ///< Titulo del ticket
	std::string m_descripcion; ///< Descripcion del ticket
	EstadoTicket m_estado;	///< Estado del ticket (PENDIENTE, ENPROGRESO, RESUELTO)
	Fecha m_fechaTicket; ///< Fecha de creacion del ticket
};


