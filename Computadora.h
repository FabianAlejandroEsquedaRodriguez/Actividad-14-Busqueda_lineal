#ifndef COMPUTADORA_H
#define COMPUTADORA_H

#include <iostream>
#include <iomanip>//Para poder hacerlo como tabla

using namespace std;

class Computadora{

    //Metodos
    public:
        //Constructor parametrizado
        Computadora(const string &SO, const string &RAM, const string &Nombre_equipo, float precio);
        Computadora();//Constructor sin parametros

        //SETTERS Y GETTERS
        void setSistemaOperativo(const string &so);
        string getSistemaOperativo();

        void setMemoriaRAM(const string &ram);
        string getMemoriaRAM();

        void setNombreEquipo(const string &name);
        string getNombreEquipo();

        void setPrecio(float p);
        float getPrecio();

        friend ostream & operator<<(ostream &out, const Computadora &c){
            
            out<<left;
            out<<setw(22)<<c.SO;
            out<<setw(15)<<c.RAM;
            out<<setw(18)<<c.Nombre_equipo;
            out<<setw(15)<<c.precio;

            out<<endl;

            return out;
        }

        friend istream & operator>>(istream &in, Computadora &c){
            
            cout << "Sistema Operativo: ";
            getline(cin, c.SO);
            cout << "Memoria RAM: ";
            getline(cin,c.RAM);
            cout << "Nombre del equipo: ";
            getline(cin, c.Nombre_equipo);
            cout << "Precio: ";
            cin >> c.precio;

            return in;
        }

    //Atributos
    private:
        string SO;//Sistema Operativo
        string RAM;//Memoria RAM
        string Nombre_equipo;//Nombre del equipo;
        float precio;
};

#endif //COMPUTADORA_H