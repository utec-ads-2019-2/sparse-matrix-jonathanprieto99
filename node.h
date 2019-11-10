#ifndef SPARSE_MATRIX_NODE_H
#define SPARSE_MATRIX_NODE_H

template <typename T>
class Matrix;

//Nodo Externo
template <typename T>
class Node {
protected:
    int posicion;
    Node<T> *next, *down;

public:
    explicit Node();

    friend class Matrix<T>;
};

//Nodo Interno
template <typename T>
class Node2 {
protected:
    int x;
    int y;
    int data;
    Node2<T> *next, *down;

public:
    explicit Node2();

    friend class Matrix<T>;
};


#endif //SPARSE_MATRIX_NODE_H
