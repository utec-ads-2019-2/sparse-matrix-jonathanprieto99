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
    Node<T> *next, *down;
public:
    explicit Node(int x, int y, T data): x(x), y(y), data(data){
        next = nullptr;
        down = nullptr;
    };

    void killSelf(){
        if(next != nullptr and down != nullptr){
            next->killSelf();
            //down->killSelf();
            delete this;
        }
        else{
            delete this;
        }
    }

    friend class Matrix<T>;
};


#endif //SPARSE_MATRIX_NODE_H
