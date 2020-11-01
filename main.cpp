#include <iostream>
#include "arreglo_dinamico.h"
using namespace std;


int main(){
    ArregloDinamico<string> str;//La T en la clase va a recibir strings
    size_t posicion;
    //Prueba 1 -> Insertar 4 strings al inicio y al final
    str.insertar_inicio("Prueba Numero 1.1");
    str.insertar_inicio("Prueba Numero 1");
    str.insertar_inicio("Prueba Numero 0");
    str.insertar_final("Prueba Numero 2");
    str.insertar_final("Prueba Numero 2.1");

    str.insertar("Insertar en una pos. valida", 2);//Insertar 1500 en la posicion 2

    str.eliminar_inicio();
    str.eliminar_final();
    str.eliminar(1);//Eliminar en la posicion 1

    cout<<endl;
    for (size_t i=0; i < str.size(); i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;

    string *s = str.buscar("Prueba Numero 1.1");//Guarda en un puntero, lo que nos retorne la funcion buscar()
    cout<<endl;
    cout<<s<<" "<<*s<<endl;//imprimir la direccion de memoria y lo que hay en esa direccion
    
    *s = "Fabian";//Podemos modificar el elemento en esap posicion de memoria
    cout<<endl;
    for (size_t i=0; i < str.size(); i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;

    return 0;
}