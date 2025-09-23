#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

struct Fecha {
	int dia;
	int mes;
	int anio;

	void getFechaActual() {
		time_t t = time(0);
		tm* now = localtime(&t);
		dia = now->tm_mday;
		mes = now->tm_mon + 1; // tm_mon is 0-11
		anio = now->tm_year + 1900; // tm_year is years since 1900
		std::cout << toString(dia, mes, anio) << std::endl;
	}

	std::string
		toString(int dia, int mes, int anio) {
		return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio);

	};
};

enum
	EstadoTicket {
	PENDIENTE = 1,
	ENPROGRESO = 2,
	RESUELTO = 3
};
