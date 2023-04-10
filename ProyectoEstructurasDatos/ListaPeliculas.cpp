#include "ListaPeliculas.h"


ListaPeliculas::ListaPeliculas() {
	this -> cab = NULL;
	this->largo = 0;
}

ListaPeliculas::~ListaPeliculas() {

}

NodoPelicula* ListaPeliculas::getCab() {
	return this->cab;
}

void ListaPeliculas::setCab(NodoPelicula* pelicula) {
	this->cab = pelicula;
}

int ListaPeliculas::getLargo() {
	return this->largo;
}

void ListaPeliculas::setLargo(int largo) {
	this->largo = largo;
}

void ListaPeliculas::desplegarLista() {
	if (esVacia()){
		std::cout << "La lista esta vacia...";
	}
	else {
		NodoPelicula* aux = getCab();
		int i = 1;
		//aux apunta al primer nodo de la lista
		while (aux != NULL) { //La lista termina al llegar a null
			std::cout << i << ". " << aux->getPelicula().getCodPelicula() << " - " << aux->getPelicula().getNombre() << " - " << aux->getPelicula().getAnno() << " - " << aux->getPelicula().getDirector() << " - " << aux->getPelicula().getCantSolicitudes() << "\n";
			aux = aux->getSgte(); //Permite pasar el siguiente nodo
			i++;
		}
		std::cout << "Fin de la lista \n";
	}
}

NodoPelicula* ListaPeliculas::dirNodoPelicula(Pelicula x) { 
	//Devuelve la direccion del nodo cuya valor sea pelicula
	
	NodoPelicula* aux = NULL;
	bool encontrado = false;
	if (!esVacia()) {
		aux = getCab();
		do
		{
			if (aux->getPelicula().equals(x)) encontrado = true;
			else aux = aux->getSgte();
		} while (aux != getCab() && !encontrado);
	}
	if (encontrado) return aux;
	else return NULL;
}

NodoPelicula* ListaPeliculas::dirAnterior(Pelicula x) {
	bool encontrado = false;
	NodoPelicula* aux = NULL;

	if (getLargo() > 1) {
		aux = getCab();
		while ((aux->getSgte() != NULL) && (!encontrado)) {
			if (aux->getSgte()->getPelicula().equals(x))
				encontrado = true;
			else
				aux = aux->getSgte();
		}
	}

	if (encontrado)
		return aux;
	else
		return NULL;

}

bool ListaPeliculas::esVacia() {
	return cab == NULL;
}

void ListaPeliculas::agregarInicio() {

}

void ListaPeliculas::agregarFinal(Pelicula _pelicula) {

	//Paso #1 crear el nodo
	NodoPelicula* nuevo = new NodoPelicula(_pelicula);

	if (esVacia())
	{
		nuevo->setSgte(nuevo);
		nuevo->setAnte(nuevo);
		setCab(nuevo);
	}
	else {
		NodoPelicula* ult = getCab()->getAnte();
		//Paso 2. Enlazar el nuevo nodo a la lista
		nuevo->setSgte(getCab());
		nuevo->setAnte(ult);
		//Paso 3. Reacomodar la lista con el nuevo nodo
		ult->setSgte(nuevo);
		getCab()->setAnte(nuevo);
	}
	setLargo(getLargo() + 1);
}

bool ListaPeliculas::retirarPelicula(Pelicula pelicula) {
	bool removido = false;
	if (!esVacia()) {
		NodoPelicula* aux = NULL;
		if (getCab()->getPelicula().getCodPelicula() == pelicula.getCodPelicula()) {
			//Proceso de remover el primer nodo
			aux = getCab();//Paso #1: Apunte el nodo a eliminar
			//Paso #2: reacomodar la lista sin el nodo
			setCab(aux->getSgte());
			setLargo(getLargo() - 1);
			delete aux; //Paso #3 Eliminar el nodo
			removido = true;
		}
		else {
			NodoPelicula* ant = dirAnterior(pelicula);
			if (ant != NULL){
				aux = ant->getSgte();//Paso #1 Apunte el nodo a eliminar
				ant->setSgte(aux->getSgte());
				setLargo(getLargo() - 1);
				delete aux; // Eliminar el Nodo
				removido = true;
			}
		}
	}
	return removido;
}

Pelicula ListaPeliculas::consultarPelicula(int codigo) {
	NodoPelicula* aux = NULL;

	if (!esVacia()) {
		aux = getCab();
		while (aux != NULL && aux -> getPelicula().getCodPelicula() != codigo)
		{
			aux = aux->getSgte();
		}
	}

	return aux->getPelicula();
}
