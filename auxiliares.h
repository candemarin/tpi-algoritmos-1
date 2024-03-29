//
// Este archivo contiene las declaraciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con el código
// de esas mismas funciones, que estará en auxiliares.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

bool posValida(unsigned long tableroSize, pos p);

bool hayMina(tablero& t, pos p);

int cantSinMinas(tablero&t);

bool posEnJugadas(tablero&t, jugadas& j, pos p);

void rellenar(tablero& t, banderitas& b, pos p, jugadas& j);

bool sugerencia121Valida(tablero& t, banderitas& b, jugadas& j, int index, pos& p);

template <typename T>
typename vector<T>::iterator busquedaLineal(vector<T>& vec, T elem){
    auto it = vec.begin();

    while(it != vec.end() && *it != elem){
        it += 1;
    }

    return it;
}

/*
 * Usadas solo en TESTS
 */

bool esPermutacion(jugadas& v, jugadas& w);
