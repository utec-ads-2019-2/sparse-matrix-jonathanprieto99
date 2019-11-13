#ifndef SPARSE_MATRIX_MATRIX_H
#define SPARSE_MATRIX_MATRIX_H

#include <stdexcept>
#include "node.h"

using namespace std;

template <typename T>
class Matrix {
private:
    Node<T> *root;
    unsigned rows, columns;

public:
    Matrix(unsigned rows, unsigned columns): root(nullptr), rows(rows), columns(columns){

        root = new Node<T>(-1,-1,-1);
        Node<T>* actual1 = root;
        Node<T>* actual2 = root;
//Se invirtio ambos for
        //Rows
        for (unsigned int i = 0; i < columns+1; ++i) {
            auto* TempNode = new Node<T>(i, -1, i);
            actual1->next = TempNode;
            actual1 = actual1->next;
        }

        //Columns
        for (unsigned int j = 0; j < rows+1; ++j) {
            auto* TempNode = new Node<T>(-1, j, j);
            actual2->down = TempNode;
            actual2 = actual2->down;
        }
    };

    Node<T>* find(int X, int Y) const{
        if(X > columns || Y > rows){
            cerr<<"Indice fuera de rango (revisar x e y!)";
        }else{
            Node<T>* actual = root;
            //Recorriendo Fila
            while ((actual->x < X) && actual->next != nullptr) {
                actual = actual->next;
            }
            //Recorriendo Columna
            while ((actual->y < Y) && actual->down != nullptr) {
                actual = actual->down;
            }
            if (actual->x == X && actual->y == Y) {
                return actual;
            }
            else {
                return nullptr;
            }
        }
    }

    T getdata(int x, int y) const{
        if(find(x,y) == nullptr){
            return 0;
        }
        else{
            return find(x,y)->data;
        }
    }

    void addNode(int x, int y, T data) const{
        //Update data if exists
        if(find(x,y) != nullptr){
            find(x,y)->data = data;
        }
        //Whole Insertion
        else{
            auto *NodeTemp = new Node<T>(x,y,data);
            Node<T> *RecorredorX = root->next;
            Node<T> *RecorredorY = root->down;
            //Podria ser while(RecorredorX->x != x)
            //verif <=
            while(RecorredorX->x < x){
                RecorredorX=RecorredorX->next;
            }
            //Podria ser while(RecorredorY->y != y)
            while(RecorredorY->y < y){
                RecorredorY=RecorredorY->down;
            }
            if(RecorredorX->down == nullptr){
                RecorredorX->down = NodeTemp;
            }
            else{
                //Vamos bajando en Y hasta encontrar un espacion vacio
                while(RecorredorX->y != y && RecorredorX->down != nullptr){
                    RecorredorX = RecorredorX->down;
                }
                //Ingresamos el nodo temporal en el espacio en blanco
                if(RecorredorX->down == nullptr){
                    RecorredorX->down = NodeTemp;
                }
                //Se crea un nodo en el que se asigna el ultimo, luego se asigna a esa posicion el nodo nuevo y se asigna al down de ese, el que estab ahi antes.
                else{
                    Node<T> *newDown = RecorredorX->down;
                    RecorredorX->down = NodeTemp;
                    NodeTemp->down = newDown;
                }
            }
            if(RecorredorY->next == nullptr){
                RecorredorY->next = NodeTemp;
            }
            else{
                while(RecorredorY->x != x && RecorredorY->next != nullptr){
                    RecorredorY = RecorredorY->next;
                }
                if(RecorredorY->next == nullptr){
                    RecorredorY->next = NodeTemp;
                }
                else{
                    Node<T> *newNext = RecorredorY->next;
                    RecorredorY->next = NodeTemp;
                    NodeTemp->next = newNext;
                }
            }
        }
    }

    void remove(Node<T>* nodo) const{
        //int xtemp=nodo->x;
        //int ytemp=nodo->y;
        //if(find(xtemp,ytemp)!= nullptr){
        if(nodo != nullptr){
            Node<T> *RecorredorX = root->next;
            Node<T> *RecorredorY = root->down;
            //Set X coordinates
            while(RecorredorX->x != nodo->x){
                RecorredorX = RecorredorX->next;
            }
            //Set Y coordinates
            while(RecorredorY->y != nodo->y){
                RecorredorY = RecorredorY->down;
            }
            //Buscando para abajo
            while(RecorredorX->down != nodo){
                RecorredorX = RecorredorX->down;
            }
            //Buscando para la derecha
            while(RecorredorY->next != nodo){
                RecorredorY = RecorredorY->next;
            }
            RecorredorX->down = nodo->down;
            RecorredorY->next = nodo->next;
            nodo = nullptr;
        }
        else{
            return;
        }
    }

    void set(int y, int x, T data) const{
       //Si se setea la data de una matriz en 0, es que queremos eliminar ese nodo
        if(data != 0){
            addNode(x, y, data);
        }
        else{
            remove(find(x, y));
        }
    }

    T operator()(int x, int y) const{
        Node<T>* NodeTemp = find(x, y);
        if(NodeTemp == nullptr){
            return 0;
        }
        else{
            return NodeTemp->data;
        }
    }

    //Multiplicacion de Matriz por escalar
    Matrix<T> operator*(T scalar) const{
        Matrix<T> newMatrix(rows, columns);
        //Se iterara por filas y columnas para acceder a todos los elementos
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if(find(j,i) != nullptr){
                    newMatrix.set(i, j, operator()(j, i)*scalar);
                }
            }
        }
        return newMatrix;
    }

//Multiplicacion de Matriz por matriz
    //La matriz resultante mantiene el numero de filas de la original y el numero de columnas de la otra (other)
    Matrix<T> operator*(Matrix<T> other) const{
        if(rows!=other.rows){
            cerr<<("Tamano Incorrecto");
        }
        //Creamos la nueva Matriz
        Matrix<T> newMatrix(rows, other.columns);
        //Iteramos sobre las columnas de la otra matriz
        for (int i = 0; i < other.columns; ++i) {
            //Iteramos sobre las filas que son las mismas
            for (int j = 0; j < rows; ++j) {
                //Esto va dar el valor a ingresar en la matriz
                T sumrow = 0;
                //Iteramos sobre las columnas de la matriz actual
                for (int k = 0; k < columns; ++k) {
                    if (find(i, j) != nullptr && other.find(i, j) != nullptr) {
                        sumrow = sumrow + operator()(j, k) * operator()(k, i);
                    }
                }
                newMatrix.set(i, j, sumrow);
            }
        }
        return newMatrix;
    };

    //Suma de matriz mas matriz
    Matrix<T> operator+(Matrix<T> other) const{
        if(rows != other.rows || columns != other.columns){
            cerr<<("Tamano Diferente");
        }
        //Both have to be of the same size
        Matrix<T> newMatrix(rows, columns);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                newMatrix.set(i, j, operator()(j,i) + other.operator()(j,i));
            }
        }
        return newMatrix;
    };

    //Resta de matriz menos matriz
    Matrix<T> operator - (Matrix<T> other) const{
        if(rows != other.rows || columns != other.columns){
            cerr<<("Tamano Diferente");
        }
        //Both have to be of the same size
        Matrix<T> newMatrix2(rows, columns);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                newMatrix2.set(i, j, operator()(j, i) - other.operator()(j,i));
            }
        }
        return newMatrix2;
    };

    //Matriz Transpuesta
    Matrix<T> transpose() const{
        Matrix<T> newMatrix(rows, columns);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
               if(find(i,j) != nullptr){
                   newMatrix.set(i,j,find(i,j)->data);
               }
            }
        }
        newMatrix.print();
        return newMatrix;
    };

    //Print
    void print() const{
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if(find(j, i) != nullptr){
                    cout<< find(j,i)->data<<" ";
                }
                else{
                    cout<<"0";
                }
            }
            cout<<endl;
        }
    };

    ~Matrix(){
        for (int i = 0; i < rows; ++i) {
            if(find(0, i)){
                find(0,i)->killSelf();
            }
        }
    };

};

#endif //SPARSE_MATRIX_MATRIX_H