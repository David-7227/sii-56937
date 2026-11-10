// Raqueta.h: interface for the Raqueta class.
//
//////////////////////////////////////////////////////////////////////
#ifndef RAQUETA_H	// Esto lo necesitamos poner para poder repetir el include Raqueta.h
#define RAQUETA_H	// en distintos archivos que se llaman entre si.

#include "Plano.h"
#include "Vector2D.h"

class Raqueta : public Plano  
{
public:
	Vector2D velocidad;

	Raqueta();
	virtual ~Raqueta();

	void Mueve(float t);
};

#endif
