#ifndef ARREGLO_DINAMICO_H
#define ARREGLO_DINAMICO_H

#include <iostream>
using namespace std;

template <class T>//La T representa un tipo de dato generico
class ArregloDinamico{

    public:
    ArregloDinamico(); //Constructor
    ~ArregloDinamico(); //Destructor

    void insertar_final(const T &s);//Aqui inserta elememtos en la posicion que marque el contador
    void insertar_inicio(const T &s);//Inserta elementos siempre en la posicion 0
    void insertar(const T &s, size_t pos);//Insertar en una posicion valida donde existe informacion
   
    void eliminar_final();
    void eliminar_inicio();
    void eliminar(size_t pos);//Eliminar un elemento de una posicion valida

    T* buscar(const T& s);//Nos va a retornar la posicion de memoria donde esta el elemento a buscar
    ArregloDinamico<T*> buscar_todos(const T& s);//Va a buscar todos los elementos que coincidan con el template
    //Va a retornar un arreglo de punteros -> Todos los elementos del areglo van a ser un puntero    

    size_t size();//Para retornar los elementos en el arreglo

    //Sobrecargar el operador de los [] para mostrar los datos
    T operator [] (size_t pos){
        return arreglo[pos];
    }

    friend ArregloDinamico<T>& operator<<(ArregloDinamico<T> &a, const T& s){//Va a recibir un arreglo y el elemento a insertar
        a.insertar_final(s);
        return a;
    }

    private:
        T *arreglo;//Es un arreglo de tipo T
        string st;
        size_t tam;
        size_t cont;
        const static int MAX = 8; 
        void expandir();//Crecer el arreglo
};

template <class T>
ArregloDinamico<T>::ArregloDinamico(){
    arreglo = new T [MAX];//Crea el arreglo dinamico reservando la memoria
    cont = 0;
    tam = MAX; //tam = 8;
}

template <class T>
ArregloDinamico<T>::~ArregloDinamico(){
    delete [] arreglo;
}

template <class T>
void ArregloDinamico<T>::insertar_final(const T &s){
    if(cont == tam){//Nuestro arreglo esta lleno
        //expandir la capacidad para seguir almacenando info
        expandir();
    }

    arreglo[cont] = s;//El arreglo inicia en la posicion cont 
                      //y guarda en esa posicion lo que se le pase como parametro
    cont++;
}

template <class T>
void ArregloDinamico<T>::insertar_inicio(const T &s){
    if(cont == tam){//Nuestro arreglo esta lleno
        //expandir la capacidad para seguir almacenando info
        expandir();
    }

    for (size_t i = cont; i>0; i--){//Va a iniciar desde el final del arreglo
                                    //Y se van a mover los elementos hacia la derecha

            arreglo[i] = arreglo[i-1];//Mover nuestro elemento a la siguiente posicion
    }

    arreglo[0] = s;//En la posicion 0 se va a agregar el elemento que recibe como parametro
    cont++;
}

template <class T>
void ArregloDinamico<T>::insertar(const T &s, size_t pos){
    if (pos >= cont){
        cout<<"La posicion no es valida";
        return; 
    }
    
    if (cont == tam){//Si el arreglo esta lleno, se expande
        expandir();
    }

    for (size_t i = cont; i > pos; i--){
        arreglo[i] = arreglo[i-1];//Va a recorrer una posicion a la derecha los elementos
    }

    arreglo[pos] = s;//En la posicion pos se va a insertar el elemento que le mandamos
    cont ++;
    
}

template <class T>
void ArregloDinamico<T>::eliminar_final(){
    if (cont == 0){
        cout<<"El arreglo esta vacio";
        return;
    }

    cont--;//Solo se decrementa el contador para que apunte al ultimo valor, pero no sera valido
}

template <class T>
void ArregloDinamico<T>::eliminar_inicio(){
    if (cont == 0){
        cout<<"El arreglo esta vacio";
        return;
    }
    for(size_t i=0; i<cont-1; i++){
        arreglo[i] = arreglo[i+1];//Se van a recorrer los elementos una posicion a la derecha
    }
    cont--;
}

template <class T>
void ArregloDinamico<T>::eliminar(size_t pos){
    if (cont == 0){
        cout<<"El arreglo esta vacio";
        return;
    }
    for(size_t i=pos; i<cont-1; i++){
        arreglo[i] = arreglo[i+1];
    }
    cont--;
}

template <class T>
size_t ArregloDinamico<T>::size(){
    return cont;
}

template <class T>
void ArregloDinamico<T>::expandir(){

    T *nuevo = new T [tam+MAX];//Se va a expandir el tamaÃ±o del arreglo

    for (size_t i = 0; i < cont; i++){
        nuevo[i] = arreglo[i];//Copia los elementos hacia el nuevo arreglo
    }

    delete[] arreglo;
    arreglo = nuevo;//Copiar las direcciones de memoria del primer arreglo hacia el nuevo, porque son punteros
    tam += MAX;//El tamaÃ±o ahora es el tamaÃ±o + 8, que vale la variable MAX  
}

template <class T>
T* ArregloDinamico<T>::buscar(const T& s){
    for(size_t i=0; i< cont; i++){
        if(s == arreglo[i]){//Si el elemento que queremos buscar esta en el arreglo
            return &arreglo[i];//Se retorna la direccion de memoria de ese elemento 
                               //en esa posicion del arreglo
        }
    }
    
    return nullptr;//Caso base -> se retorna un puntero nulo (en una posicion no valida)
    
}

template<class T>
ArregloDinamico<T*> ArregloDinamico<T>::buscar_todos(const T& s){
    ArregloDinamico<T*> punteros;//Definimos el arreglo de punteros
    
    for(size_t i=0; i< cont; i++){
        if(s == arreglo[i]){//Si el elemento que queremos buscar esta en el arreglo
            punteros.insertar_final(&arreglo[i]);//En el arreglo de punteros se va a insertar al final
                                                 //las direcciones de memoria donde se encuentra el elemento en la posicion i
        }
    }
    return punteros;
}


#endif //ARREGLO_DINAMICO_H