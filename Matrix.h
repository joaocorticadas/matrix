#include <iostream>
#include <vector>
#include <memory>

#pragma once

class Matrix 
{
    public:
        //Variables
        int x, y;
        std::vector<int> matrix_input;
        std::vector<std::vector<int> > matrix_data;

        //Methods
        int addElements();
        void printElements();
        template <typename T, typename... Types>
        int addElements(T var1, Types... var2);

        //Operator Overload
        Matrix operator + (Matrix const &ori);
        Matrix operator - (Matrix const &ori);
        Matrix operator * (Matrix const &ori);

        //Constructors
        Matrix();
        Matrix(int setX, int setY);
};
