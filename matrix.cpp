#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <functional>
#include "headers/print.h"

using std::vector;
using std::cout;

class Matrix
{
    private:
        // Fields
        vector<vector<float>*>* arr;
        int nrow;
        int ncol;

        // Constructors
        Matrix(vector<vector<float>*>* arr)
        {
            this->arr = arr;
            nrow = arr->size();
            ncol = arr->at(0)->size();
        }
        
    public:
        // Constructors / Destructors
        ~Matrix()
        {
            if(arr != nullptr)
            {
                for(auto vectPtr : *arr)
                    delete vectPtr;
                delete arr;
            }
        }

        // Methods
        static Matrix* fromVector(vector<vector<float>*>* arr)
        {
            return new Matrix(arr);
        }

        Matrix* copy()
        {
            vector<vector<float>*>* arr = new vector<vector<float>*>();
            for(int i = 0; i < size(0); i++)
            {
                arr->push_back(new vector<float>());
                for(int j = 0; j < size(1); j++)
                    arr->at(i)->push_back(at(i, j));
            }

            return Matrix::fromVector(arr);
        }

        float at(int i, int j)
        {
            return arr->at(i)->at(j);
        }

        int size(int index)
        {
            if(index == 0)
                return arr->size();
            if(index == 1) {
                return arr->at(0)->size();
            }
            throw std::invalid_argument("size: index out of bounds");
        }

        void display()
        {
            cout << "[";
            for(int i = 0; i < nrow; i++)
            {
                cout << "[";
                for(int j = 0; j < ncol; j++)
                {
                    cout << round(arr->at(i)->at(j) * 1000) / 1000;
                    if(j != ncol - 1)
                        cout << ", ";
                }
                cout << "]";
                if(i != nrow - 1)
                    cout << std::endl << " ";
            }
            cout << "]" << std::endl;
        }

        Matrix* apply(std::function<float(float)> func)
        {
            for(int i = 0; i < nrow; i++)
            {
                for(int j = 0; j < ncol; j++)
                    arr->at(i)->at(j) = func((arr->at(i)->at(j)));
            }
            return this;
        }

        Matrix* apply(std::function<float(float, float)> func, float num)
        {
            for(int i = 0; i < nrow; i++)
            {
                for(int j = 0; j < ncol; j++)
                    arr->at(i)->at(j) = func((arr->at(i)->at(j)), num);
            }
            return this;
        }

        Matrix* sqrt()
        {
            return apply([](float f) {return std::sqrt(f);});
        }

        Matrix* exp()
        {
            return apply([](float f) {return std::exp(f);});
        }

        Matrix* pow(float num)
        {
            return apply([](float f1, float f2) {return std::pow(f1, f2);}, num);
        }

        Matrix* transpose()
        {
            vector<vector<float>*>* newArr = new vector<vector<float>*>();
            for(int j = 0; j < ncol; j++)
            {
                newArr->push_back(new vector<float>());
                for(int i = 0; i < nrow; i++)
                    newArr->at(j)->push_back(arr->at(i)->at(j));
            }
            delete arr;
            arr = newArr;
            std::swap(nrow, ncol);
            return this;
        }

        Matrix* matmul(Matrix* other)
        {
            if(ncol != other->nrow)
                throw std::invalid_argument("matmul: number of rows and columns do not match");

            vector<vector<float>*>* newArr = new vector<vector<float>*>();
            for(int i = 0; i < nrow; i++)
            {
                newArr->push_back(new vector<float>());
                for(int j = 0; j < other->ncol; j++)
                {
                    float sum = 0.0f;
                    for(int k = 0; k < ncol; k++)
                    {
                        sum += arr->at(i)->at(k) * other->arr->at(k)->at(j);
                    }
                    newArr->at(i)->push_back(sum);
                }
            }
            delete arr;
            arr = newArr;
            ncol = other->ncol;
            return this;
        }
};

int main(int argc, char* argv[])
{
    vector<vector<float>*>* vect = new vector<vector<float>*>();
    vect->push_back(new vector<float>{2.3, 4.5, 3.3});
    vect->push_back(new vector<float>{1.1, 2.2, 7.6});
    vect->push_back(new vector<float>{4.5, 2.3, 1.7});
    vect->push_back(new vector<float>{1.1, 2.1, 5.7});
    Matrix* t = Matrix::fromVector(vect);

    vect = new vector<vector<float>*>();
    vect->push_back(new vector<float>{2.3, 4.5});
    vect->push_back(new vector<float>{1.1, 2.2});
    vect->push_back(new vector<float>{4.5, 2.3});
    Matrix* t2 = Matrix::fromVector(vect);

    t->copy()->sqrt()->pow(3)->matmul(t2)->transpose()->display();

    t->display();
    t->sqrt()->display();
    
    return 0;
}