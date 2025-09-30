#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

/**
 * @struct Fecha
 * @brief Estructura para manejar fechas y horas.
 * 
 * La estructura Fecha encapsula los atributos relacionados con la fecha y hora,
 * incluyendo dia, mes, anio, hora, minutos y segundos. Proporciona metodos para
 * obtener la fecha actual y convertirla a una cadena legible.
 */
struct 
Fecha {
	int dia; ///< Dia del mes
	int mes; ///< Mes del año
	int anio; ///< Año
	int hora; ///< Hora del día
	int mins; ///< Minutos
	int segs; ///< Segundos

	/**
	 * @brief Obtiene la fecha y hora actual del sistema.
	 * 
	 * Este metodo utiliza la biblioteca <ctime> para obtener la fecha y hora
	 * actual del sistema y asignarla a los atributos de la estructura.
	 */
	void 
	getFechaActual() {
		time_t t = time(0);
		tm now;
		localtime_s(&now, &t);
		dia = now.tm_mday;
		mes = now.tm_mon + 1; // tm_mon is 0-11
		anio = now.tm_year + 1900; // tm_year is years since 1900
		hora = now.tm_hour;
		mins = now.tm_min;
		segs = now.tm_sec;
		std::cout << toString(dia, mes, anio, hora, mins, segs) << std::endl;
	}

	/**
	 * @brief Convierte la fecha y hora a una cadena legible.
	 * @param dia El dia del mes.
	 * @param mes El mes del año.
	 * @param anio El año.
	 * @param hora La hora del día.
	 * @param mins Los minutos.
	 * @param segs Los segundos.
	 * @return Una cadena en formato "dd/mm/yyyy hh:mm:ss".
	 * 
	 * Este metodo convierte los atributos de la estructura en una cadena
	 * con un formato legible para su visualizacion.
	 */
	std::string
	toString(int dia, int mes, int anio, int hora, int mins, int segs) {
		return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio) + 
		" " + std::to_string(hora) + ":" + std::to_string(mins) + ":" + std::to_string(segs);
	};
};

/**
 * @enum EstadoTicket
 * @brief Enumeracion para representar los estados de un ticket.
 * 
 * La enumeracion EstadoTicket define los posibles estados que un ticket
 * puede tener en el sistema de gestion de tickets.
 */
enum
EstadoTicket {
	PENDIENTE = 1, ///< Estado del ticket: Pendiente
	ENPROGRESO = 2, ///< Estado del ticket: En Progreso
	RESUELTO = 3 ///< Estado del ticket: Resuelto
};
