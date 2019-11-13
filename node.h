#ifndef SPARSE_MATRIX_NODE_H
#define SPARSE_MATRIX_NODE_H

template <typename T>
class Matrix;

template <typename T>
class Node {
private:
    int x;
    int y;
    T data;

protected:
    Node<T> *next, *down;

public:
    explicit Node(int x, int y, T data): x(x), y(y), data(data), next(nullptr), down(nullptr){};

    void killSelf(){
        if(next != nullptr){
            next->killSelf();
            delete this;
        }
    }

    friend class Matrix<T>;
};


#endif //SPARSE_MATRIX_NODE_H
