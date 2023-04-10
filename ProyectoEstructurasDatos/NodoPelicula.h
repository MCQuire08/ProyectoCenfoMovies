#pragma once
#include "Pelicula.h"
class NodoPelicula
{

private:
	Pelicula pelicula;
	NodoPelicula* sgte;
	NodoPelicula* ante;

public:
	NodoPelicula();
	NodoPelicula(Pelicula);

	void setPelicula(Pelicula);
	Pelicula getPelicula();

	void setSgte(NodoPelicula*);
	NodoPelicula* getSgte();

	void setAnte(NodoPelicula*);
	NodoPelicula* getAnte();


};

