#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

struct 
Fecha {
	int dia;
	int mes;
	int anio;
	int hora;

	void 
	getFechaActual() {
		time_t t = time(0);
		tm* now = localtime(&t);
		dia = now->tm_mday;
		mes = now->tm_mon + 1; // tm_mon is 0-11
		anio = now->tm_year + 1900; // tm_year is years since 1900
		hora = now->tm_hour;
		std::cout << toString(dia, mes, anio, hora) << std::endl;
	}

	std::string
	toString(int dia, int mes, int anio, int hora) {
		return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio) + " " + std::to_string(hora) + ":00";
	};
};

enum
EstadoTicket {
	PENDIENTE = 1,
	ENPROGRESO = 2,
	RESUELTO = 3
};
