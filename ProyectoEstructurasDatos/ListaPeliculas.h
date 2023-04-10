#pragma once
#include <stdlib.h>
#include <iostream>
#include "NodoPelicula.h"

class ListaPeliculas
{
private:
	NodoPelicula* cab;
	int largo;

public:
	ListaPeliculas();
	~ListaPeliculas();

	NodoPelicula* getCab();
	void setCab(NodoPelicula*);

	int getLargo();
	void setLargo(int);



	//UTILITARIOS

	NodoPelicula* dirNodoPelicula(Pelicula);

	NodoPelicula* dirAnterior(Pelicula x);

	bool esVacia();

	void agregarInicio();

	void agregarFinal(Pelicula _pelicula);

	bool retirarPelicula(Pelicula pelicula);

	Pelicula consultarPelicula(int codigo);

	void desplegarLista();


};

