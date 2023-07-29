#include <iostream>
#include "matrix.h"

int main()
{
   // M.print_matrix();
    int rows = 0;
    int cols = 0;
    int answer = 0;
    std::cout << "This is a simple program for working with integer matrices";
    std::cout << std::endl;
    std::cout << "Enter the number of rows" << std::endl;
    std::cin >> rows;
    std::cout << "Enter the number of cols" << std::endl;
    std::cin >> cols;
    Matrix <int> M(rows,cols);
    std::cout << "Now enter the matrix elements" << std::endl;
    M.fill_matrix();
    M.print_matrix();

    std::cout << "What would you like to do?" << std::endl;
    std::cout << "1. Sum a matrix with another"  << std::endl;
    std::cout << "2. Subtract another one from this matrix" << std::endl;
    std::cout << "3. Traspose matrix" << std::endl;
    std::cout << "4. Find matrix determinant" << std::endl;
    std::cout << "Enter the number of the desired operation or 0 to exit" << std::endl;
    std::cin >> answer;

    switch (answer)
    {
    case 1: 
        {
            std::cout << "Enter the elements of the second matrix" << std::endl;
            std::cout << "The second matrix must have " << rows << " rows and " << cols << " cols";
            std::cout << std::endl;
            Matrix<int> another_matrix (rows, cols);
            another_matrix.fill_matrix();
            M = M+another_matrix;
            M.print_matrix();
            break;
        }
    
    case 2:
        {    
            std::cout << "Enter the elements of the second matrix" << std::endl;
            std::cout << "The second matrix must have " << rows << " rows and " << cols << " cols";
            std::cout << std::endl;
            Matrix<int> another_matrix (rows, cols);
            another_matrix.fill_matrix();
            M = M-another_matrix;
            M.print_matrix();
        }
        break;
        

    case 3:
        {  
            M.transpose();
            M.print_matrix();
        }
        break;

    case 4:
        {
            if (rows == cols)
            {
                std::cout << "Determinant = " << M.determinant(rows);
            }
            else
            {
                std::cout << "Your matrix isn't square" << std::endl;
                std::cout << "It is impossible to find determinant" << std::endl;
            }
        }
        break;        

    case 0:
        break;
    }
    return 0;
}
    
    
    
    