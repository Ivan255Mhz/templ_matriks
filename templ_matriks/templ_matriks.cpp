
#include "Matrix.h"

int main()
{
    srand(time(NULL));

    Matrix<int> a(3,5);

    Matrix<int> b(3, 5);
    
   
    Matrix<int> c = a + b;

    Matrix<int> d = c;

    d.print();



}

