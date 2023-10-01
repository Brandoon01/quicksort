//codigo de Julian David Ortiz Molina.
//Juan camilo Baez Bautista.
//Brandon Stick Buitrago Ruiz.

#include <iostream>
#include <stdlib.h>
#include <time.h>

void quicksort(int lista[], int izquierda, int derecha) {
    int i = izquierda, j = derecha;
    int pivot = lista[(izquierda + derecha) / 2];

    while (i <= j) {
        while (lista[i] < pivot) {
            i++;
        }
        while (lista[j] > pivot) {
            j--;
        }
        if (i <= j) {
            std::swap(lista[i], lista[j]);
            i++;
            j--;
        }
    }

    if (izquierda < j) {
        quicksort(lista, izquierda, j);
    }
    if (i < derecha) {
        quicksort(lista, i, derecha);
    }
}

int main() {
    const int tamaño = 20;
    int lista[tamaño];
    bool elegidos[21];
    int posibles = 21;
    int contador, posicion;
    int i, j;
    std::srand(std::time(nullptr));

    for (i = 0; i < 21; i++) {
        elegidos[i] = false;
    }
    for (i = 0; i < 20; i++) {
        posicion = std::rand() % posibles + 1;
        j = 0;
        contador = 0;
        while (contador < posicion) {
            if (!elegidos[j++]) contador++;
        }
        j--;
        elegidos[j] = true;
        posibles--;
        lista[i] = j;
        std::cout << " " << j;
    }

    std::cout << "\n\nLista desordenada: ";
    for (i = 0; i < tamaño; i++) {
        std::cout << lista[i] << " ";
    }
    quicksort(lista, 0, tamaño - 1);

    std::cout << "\nLista ordenada: ";
    for (i = 0; i < tamaño; i++) {
        std::cout << lista[i] << " ";
    }

    return 0;
}

