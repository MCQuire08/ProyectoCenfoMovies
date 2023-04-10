#include "Pelicula.h"

Pelicula::Pelicula() {

}

Pelicula::Pelicula(int codPelicula, std::string nombre, int anno, std::string director, int cantSolicitudes) {
	this->codPelicula = codPelicula;
	this->nombre = nombre;
	this->anno = anno;
	this->director = director;
	this->cantSolicitudes = cantSolicitudes;
}

int Pelicula::getCodPelicula() {
	return this->codPelicula;
}

void Pelicula::setCodPelicula(int codPelicula) {
	this->codPelicula = codPelicula;
}

std::string Pelicula::getNombre() {
	return this->nombre;
}
void Pelicula::setNombre(std::string nombre) {
	this->nombre = nombre;
}

int Pelicula::getAnno() {
	return this->anno;
}

void Pelicula::setAnno(int anno) {
	this->anno = anno;
}

std::string Pelicula::getDirector() {
	return this->director;
}

void Pelicula::setDirector(std::string director) {
	this->director = director;
}

int Pelicula::getCantSolicitudes() {
	return this->cantSolicitudes;
}

void Pelicula::setCantSolicitudes(int cantSolicitudes) {
	this->cantSolicitudes = cantSolicitudes;
}

bool Pelicula::equals(Pelicula p)
{
	return (codPelicula == p.getCodPelicula());
}
