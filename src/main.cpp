#include <iostream>
#include <fstream>

#include <gsl_wrapper/matrix.h>
#include <gsl_wrapper/vector.h>

using gsl_wrapper::Matrix;
using gsl_wrapper::Vector;

int main()
{
    //Matrix
    Matrix a = {{1, 2}, {3, 4}};
    std::cout << a << std::endl;

    Matrix sized(2, 2);
    sized[0][0] = 2;
    sized[0][1] = 3;
    sized[1][0] = 4;
    sized[1][1] = 5;
    std::cout << sized << std::endl;

    gsl_matrix *matrix_ptr = a.get_gsl_matrix();

    {
        std::ofstream file("Matrix.dat");
        file << a;
    }

    //Vector
    Vector b = {1, 2, 3, 4};
    std::cout << b << std::endl;

    Vector sized_vector(2);
    sized_vector[0] = 1;
    sized_vector[1] = 2;
    std::cout << sized_vector << std::endl;

    gsl_vector *vector_ptr = sized_vector.get_gsl_vector();
    {
        std::ofstream file("Vector.dat");
        file << b;
    }

    return 0;
}