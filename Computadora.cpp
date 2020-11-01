#include <iostream> 
#include "Computadora.h"

Computadora::Computadora(const string &SO, const string &RAM, const string &Nombre_equipo, float precio){
    this -> SO = SO;
    this -> RAM = RAM;
    this -> Nombre_equipo = Nombre_equipo;
    this -> precio = precio;
}

Computadora::Computadora(){}

void Computadora::setSistemaOperativo(const string &so){
    SO = so;
}
string Computadora::getSistemaOperativo(){
    return SO;
}

void Computadora::setMemoriaRAM(const string &ram){
    RAM = ram;
}
string Computadora::getMemoriaRAM(){
    return RAM;
}

void Computadora::setNombreEquipo(const string &name){
    Nombre_equipo = name;
}
string Computadora::getNombreEquipo(){
    return Nombre_equipo;
}

void Computadora::setPrecio(float p){
    precio = p;
}
float Computadora::getPrecio(){
    return precio;
}