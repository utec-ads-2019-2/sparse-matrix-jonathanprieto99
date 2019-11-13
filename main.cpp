#include <iostream>
#include "tester/tester.h"
#include "matrix.h"

int main() {
    Tester::execute();
/*
    //Setear nueva Matriz
    //Matrix<int> Matrix_TEST(5,5);
    //Matrix_TEST.set(0,1,3);
    //Matrix_TEST.set(2,0,5);
    //Matrix_TEST.set(4,4,6);
    //------------------------------------------//
    Matrix<int> Matrix_TEST(4,5);
    Matrix_TEST.set(0,1,3);
    Matrix_TEST.set(2,0,5);
    Matrix_TEST.set(4,3,6);

    cout<<"Matriz test: "<<endl;
    Matrix_TEST.print();

    cout<<"Find: "<<endl;
    cout<<Matrix_TEST.getdata(0,1)<<endl; //Funciona Find

    cout<<"T operator: "<<endl;
    cout<<Matrix_TEST.operator()(2,0)<<endl; //Funciona (Toperator)

    cout<<"Multiplicacion por escalar: (Funciona)"<<endl;
    Matrix_TEST.operator*(2).print(); //No Funciona (Multiplicacion por Escalar)

    cout<<"Set en 0 (Borrar): "<<endl;
    Matrix_TEST.set(0,1,0); //Funciona (Borrar)
    Matrix_TEST.print();

    //Setear de nuevo nodo
    Matrix_TEST.set(1,1,3);

    //Setear Nueva Matriz
    Matrix<int> Matrix_TEST2(5,5);
    Matrix_TEST2.set(1,1,3);
    Matrix_TEST2.set(2,0,5);
    Matrix_TEST2.set(4,3,6);

    //Print nueva Matriz
    cout<<"Matriz test2: "<<endl;
    Matrix_TEST2.print();

    cout<<"Matriz test1:"<<endl;
    Matrix_TEST.print();

    cout<<"Multiplicacion de dos matrices: (Funciona) "<<endl;
    Matrix_TEST.operator*(Matrix_TEST2).print();

    cout<<"Suma de dos matrices: (Funciona)"<<endl;
    Matrix_TEST.operator+(Matrix_TEST2).print();

    cout<<"Resta de dos matrices (Funciona): "<<endl;
    Matrix_TEST.operator-(Matrix_TEST2).print();

    cout<<"Matriz transpuesta: "<<endl;
    Matrix_TEST.transpose().print();
*/
    return EXIT_SUCCESS;
}
