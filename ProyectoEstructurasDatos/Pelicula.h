#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
class Pelicula
{
private:
	int codPelicula;
	std::string nombre;
	int anno;
	std::string director;
	int cantSolicitudes;

public:
	Pelicula();
	Pelicula(int, std::string, int, std::string, int);

	int getCodPelicula();
	void setCodPelicula(int);

	std::string getNombre();
	void setNombre(std::string);

	int getAnno();
	void setAnno(int);

	std::string getDirector();
	void setDirector(std::string);

	int getCantSolicitudes();
	void setCantSolicitudes(int);

	bool equals(Pelicula);
};
