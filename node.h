#ifndef SPARSE_MATRIX_NODE_H
#define SPARSE_MATRIX_NODE_H

template <typename T>
class Matrix;

//Nodo Externo
template <typename T>
class NodeExterno {
protected:
    int posicion;
    //El header necesita o next o down, tener cuidado se usa siguiente como ambos
    NodeExterno<T> *siguiente;

public:
    explicit NodeExterno(int posicion) : posicion(posicion){
        siguiente=nullptr;
    };

    void killSelf(){
        if(siguiente){
            siguiente->killSelf();
            delete this;
        }
        else{
            delete this;
        }
    }

    friend class Matrix<T>;
};

//Nodo Interno
template <typename T>
class NodeInterno {
protected:
    int x;
    int y;
    T data;
    NodeInterno<T> *next, *down;

public:
    explicit NodeInterno(int posX, int posY, T data):x(x), y(y), data(data){
        next = nullptr;
        down = nullptr;
    };

    void killSelf(){
        if(next){
            next->killSelf();
            delete this;
        }
        else{
            delete this;
        }
    }

    friend class Matrix<T>;
};


#endif //SPARSE_MATRIX_NODE_H
