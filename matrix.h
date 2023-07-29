#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
template <typename T>
class Matrix
{
    Matrix () = delete;
    public:
    Matrix (int rows, int cols) : rows(rows), cols(cols)
    {
        pointer = new T*[rows];
        for (int i = 0; i != cols; ++i)
        {
            pointer[i] = new T[cols];
            for (int j = 0; j != rows; ++j){
                pointer[i][j]={};
            }
        }
    }
    Matrix (const Matrix& other) {
        if (this != &other) 
        {
            for (int i=0;i<rows;i++) {
                for (int j=0;j<cols;j++){
                    this->pointer[i][j]=other.pointer[i][j];
                }
            }
        }
    }
    ~Matrix () {
        for (int i = 0; i != rows; ++i)
        {
            delete [] pointer[i];
        }
        delete [] pointer;
    }

    void fill_matrix ()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                std::cin >> pointer[i][j];
            }
        }
    }

    void print_matrix() 
    {
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++)
            {
                std::cout << pointer[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix operator + (const Matrix& other) 
    {
        Matrix sum (rows, cols);
        for (unsigned i = 0; i < rows; i++)
        {
            for (unsigned j = 0; j < cols; j++)
            {
                sum.pointer[i][j] = this->pointer[i][j] + other.pointer[i][j];
            }
        }
        return sum;
    }

    Matrix operator - (const Matrix& other) 
    {
        Matrix dif (rows, cols);
        for (unsigned i = 0; i < rows; i++)
        {
            for (unsigned j = 0; j < cols; j++)
            {
                dif.pointer[i][j] = this->pointer[i][j] - other.pointer[i][j];
            }
        }
        return dif;
    }

    Matrix& operator=(const Matrix& other)
    {
        if (this != &other) 
        {
           Matrix tmp(other);
           std::swap(*this, tmp);
        }
        return *this;
    }

    Matrix& operator=(Matrix&& other)
    {
        std::swap(*this, other);
        return *this;
    }

    int determinant (int size)
    {
    if(rows!=cols)
        throw std::invalid_argument("Matrix is not square");
    int result = 0;
    if (size == 1) 
    {
         return pointer [0][0];
    }
    
    else if (size == 2) 
    {
        return (pointer [0][0] * pointer [1][1]) - (pointer [0][1] * pointer [1][0]);
    }
 
    else 
    {
        int sign = 1;
        for (int i = 0; i < size; i++) 
        {
            Matrix submatrix (size - 1, size - 1);
            int subm_i = 0, subm_j = 0;
            for (int j = 1; j < size; j++) 
            {
                for (int k = 0; k < size; k++) 
                {
                    if (k == i) 
                    {
                        continue;
                    }
                    submatrix.pointer [subm_i][subm_j] = pointer [j][k];
                    subm_j++;
                }
                subm_i++;
                subm_j = 0;
            }
			
            result += sign * pointer [0][i] * submatrix.determinant(size - 1);
            sign *= (-1);
            return result;
        }
    }
}

void transpose () 
{
    Matrix tr_m (cols, rows);
    for (unsigned j = 0; j < rows; j++)
    {
        for (unsigned q = 0; q < cols; q++)
        {
            tr_m.pointer[q][j] = pointer[j][q];
        }
    }
    std::swap(rows,cols);
    std::move(tr_m);
}


    private:
    T** pointer;
    int rows;
    int cols;
};


