#include <iostream>
#include <vector>
#include <memory>
#include "Matrix.h"

//Constructors
Matrix :: Matrix(int setX, int setY)
{
    x = setX;
    y = setY;
};

Matrix :: Matrix()
{
    x = 0;
    y = 0;
};

//Methods
int Matrix :: addElements() 
{
    if((int)matrix_input.size() != x * y){
        std::cout << "The number of arguments does not match the size of the matrix" << std::endl;
        return -1;
    }
    int k = 0;
    for (int i = 0; i < y; i++) 
    {
        std::vector<int> row;
        for (int j = 0; j < x; j++)
        {
            row.push_back(matrix_input[k]);
            k++;
        };
        matrix_data.push_back(row);
    };
    return 0;
};

template <typename T, typename... Types>
int Matrix :: addElements(T var1, Types... var2) 
{
    matrix_input.push_back(var1);
    this->addElements(var2...);
    return 0;
}

void Matrix :: printElements() 
{
    for (int i = 0; i < (int)matrix_data.size(); i++)
    {
        for (int j = 0; j < (int)matrix_data[i].size(); j++)
        {
            std::cout << matrix_data[i][j] << "\t";
        };
        std::cout << "\n";
    }
}

//Operator Overload
Matrix Matrix :: operator + (Matrix const &ori)
{
    Matrix ret;
    ret.x = ori.x;
    ret.y = ori.y;
    ret.matrix_data = ori.matrix_data;
    if(matrix_data.size() == 0 || ori.matrix_data.size() == 0){
        std::cout << "This operation cannot be performed" << std::endl;
        return ret;
    }
    for (int i = 0; i < (int)ori.matrix_data.size(); i++)
    {
        for (int j = 0; j < (int)ori.matrix_data[i].size(); j++)
        {
            ret.matrix_data[i][j] = matrix_data[i][j] +  ori.matrix_data[i][j];
        };
    }
    return ret;
};

Matrix Matrix :: operator * (Matrix const &ori){
    Matrix ret;
    ret.x = ori.x;
    ret.y = y;
    int temp;

    if(matrix_data.size() == 0 || ori.matrix_data.size() == 0){
        std::cout << "This operation cannot be performed" << std::endl;
        return ret;
    }
    if (ret.x != ret.y) {
        std::cout << "Invalid Arguments" << std::endl;
        return ret;
    }
    for (int i = 0; i < ret.x; i++){
        for (int j = 0; j < ret.y; j++){
            temp = 0;  
            for (int k = 0; k < x; k++){
                temp = temp + (matrix_data[i][k] * ori.matrix_data[k][j]);
                
            }
            ret.matrix_input.push_back(temp);
        };
    }
    ret.addElements();
    return ret; 
}

Matrix Matrix :: operator - (Matrix const &ori)
{
    Matrix ret;
    ret.x = ori.x;
    ret.y = ori.y;
    ret.matrix_data = ori.matrix_data;

    if(matrix_data.size() == 0 || ori.matrix_data.size() == 0){
        std::cout << "This operation cannot be performed" << std::endl;
        return ret;
    }
    for (int i = 0; i < (int)ori.matrix_data.size(); i++)
    {
        for (int j = 0; j < (int)ori.matrix_data[i].size(); j++)
        {
            ret.matrix_data[i][j] = matrix_data[i][j] -  ori.matrix_data[i][j];
        };
    }
    return ret;
}