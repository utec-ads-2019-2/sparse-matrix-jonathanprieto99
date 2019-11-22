#include <iostream>
#include "tester/tester.h"
#include "matrix.h"

int main() {
    /*Matrix<int> Matrix_TEST(5,5);
    Matrix_TEST.set(0,1,3);
    Matrix_TEST.set(2,0,5);
    Matrix_TEST.set(4,3,6);

    cout<<"Matriz test: "<<endl;
    Matrix_TEST.print();

    cout<<"Matriz Transpuesta test: "<<endl;
    Matrix_TEST.transpose();*/

    Tester::execute();
    return EXIT_SUCCESS;
}
