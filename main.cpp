#include <iostream>
#include "arreglo_dinamico.h"
#include "Computadora.h"
using namespace std;


int main(){
    
    ArregloDinamico<Computadora> compu;//Arreglo dinamico que va a almacenar computadoras

    Computadora c1("Windows", "16 GB", "Lenovo 330S", 12500.00);
    Computadora c2("Windows", "12 GB", "HP Pavilio", 18799.00);
    Computadora c3("Windows", "13 GB", "Lenovo Chromebook", 7193.50);
    Computadora c4("MacOS", "8 GB", "MacBook Pro", 36209.00);
    Computadora c5("MacOS", "8 GB", "Apple iMac", 29999.00);
    
    compu << c1 << c2 << c3 << c4 << c5;//Se agregan las computadoras al arreglo de computadoras
    
    Computadora c6("Windows", "12 GB", "HP Pavilio", 18799.00);
    
    ArregloDinamico<Computadora*> compus = compu.buscar_todos(c6);;//Arreglo de punteros de computadoras

    if(compus.size() > 0){
        for(size_t i=0; i<compus.size(); i++){
            Computadora *co = compus[i];//En un puntero, se guardan las posiciones de memoria donde hay conicidencias
                                        //segun lo que retorna la sobrecarga del operador []
            cout<<*co<<endl;
        }
    }
    else{
        cout<<"No existen coincidencias"<<endl;
    }

    // Computadora *pt = compu.buscar(c6);//Se busca por SO(1er parametro)

    // if(pt != nullptr){
    //      cout<<*pt<<endl;
    // }
    // else{
    //      cout<<"No existe"<<endl;
    // }

    
    /*ArregloDinamico<string> str;//La T en la clase va a recibir strings
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
    cout<<endl;*/

    return 0;
}
