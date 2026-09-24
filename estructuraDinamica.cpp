/*
 *  estructuraDinamica.h
 *  EstructuraDinamica
 *
 *  Created by Santi Espigule.
 *  Copyright (c) 2004 IMA-UdG.
 *
 * JSS - 2009
 *    cal afegir-hi els metodes a implementar
* JSS - 2022
 *    es obligatori implementar el destructor 
 */

#include "estructuraDinamica.h"
#include <iostream>


estructuraDinamica::estructuraDinamica( )
{
// aquest constructor es dona fet i no es pot canviar
	final = NULL;
}

estructuraDinamica::estructuraDinamica(const estructuraDinamica &e){
	if (e.final == nullptr) {
    	final = nullptr;
	}
    else {
        node *inici = e.final->seguent;
        node *p = new node;
        p->dada = inici->dada;
        node *nouInici = p;
        node *actual = inici->seguent;

		while (actual != inici) {

            node *nou = new node;
            nou->dada = actual->dada;
            p->seguent = nou;
            p = nou;
            actual = actual->seguent;
        }

        p->seguent = nouInici;
        final = p;
    }
}

estructuraDinamica::~estructuraDinamica() {
    if (final != nullptr) {
        node *primero = final->seguent;
        node *p = primero;

        while (p != final) {
            node *aux = p;
            p = p->seguent;
            delete aux;
        }

        delete final;
        final = nullptr;
    }
}

void estructuraDinamica::AfegirInici(int i){
	node * p = new node;
	p->dada = i;

	if(final == nullptr){
		p->seguent = p;
		final = p;
		final = p = final->seguent;
	}
	else{
		p->seguent = final -> seguent;
		final -> seguent = p;
	}
}

void estructuraDinamica::Llistar() const
{
// aquest metode es dona fet i no es pot canviar
    node *p;

    if (final != NULL) 
    {
        p = final->seguent;
        while (p != final) 
        {
            cout << p->dada << " ";
            p = p->seguent;
        }
        cout << final->dada;
    }
    cout << endl;
}
