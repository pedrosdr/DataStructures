#include <iostream>
#include <vector>
#include <math.h>
#include <stdexcept>
#include "headers/print.h"

using std::vector;
using std::cout;

class Tensor
{
    private:
        // Fields
        vector<vector<float>*>* arr;
        int nrow;
        int ncol;

        // Constructors
        Tensor(vector<vector<float>*>* arr)
        {
            this->arr = arr;
            nrow = arr->size();
            ncol = arr->at(0)->size();
        }
        
    public:
        // Constructors / Destructors
        ~Tensor()
        {
            if(arr != nullptr)
            {
                for(auto vectPtr : *arr)
                    delete vectPtr;
                delete arr;
            }
        }

        // Methods
        static Tensor* fromVector(vector<vector<float>*>* arr)
        {
            return new Tensor(arr);
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

        Tensor* apply(float (*func)(float))
        {
            vector<vector<float>*>* newArr = new vector<vector<float>*>();
            for(int i = 0; i < nrow; i++)
            {
                newArr->push_back(new vector<float>());
                for(int j = 0; j < ncol; j++)
                    newArr->at(i)->push_back(func((arr->at(i)->at(j))));
            }
            return new Tensor(newArr);
        }

        Tensor* apply(float (*func)(float, float), float num)
        {
            vector<vector<float>*>* newArr = new vector<vector<float>*>();
            for(int i = 0; i < nrow; i++)
            {
                newArr->push_back(new vector<float>());
                for(int j = 0; j < ncol; j++)
                    newArr->at(i)->push_back(func((arr->at(i)->at(j)), num));
            }
            return new Tensor(newArr);
        }

        Tensor* sqrt()
        {
            return apply(std::sqrt);
        }

        Tensor* exp()
        {
            return apply(std::exp);
        }

        Tensor* pow(float num)
        {
            return apply(std::pow, num);
        }

        Tensor* transpose()
        {
            vector<vector<float>*>* newArr = new vector<vector<float>*>();
            for(int j = 0; j < ncol; j++)
            {
                newArr->push_back(new vector<float>());
                for(int i = 0; i < nrow; i++)
                    newArr->at(j)->push_back(arr->at(i)->at(j));
            }
            return Tensor::fromVector(newArr);
        }

        Tensor* matmul(Tensor* other)
        {
            if(ncol != other->nrow)
                throw std::invalid_argument("matmul: number of rows and columns does not match");

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
            return Tensor::fromVector(newArr);
        }
};

int main(int argc, char* argv[])
{
    vector<vector<float>*>* vect = new vector<vector<float>*>();
    vect->push_back(new vector<float>{2.3, 4.5, 3.3});
    vect->push_back(new vector<float>{1.1, 2.2, 7.6});
    vect->push_back(new vector<float>{4.5, 2.3, 1.7});
    vect->push_back(new vector<float>{1.1, 2.1, 5.7});
    Tensor* t = Tensor::fromVector(vect);

    vect = new vector<vector<float>*>();
    vect->push_back(new vector<float>{2.3, 4.5});
    vect->push_back(new vector<float>{1.1, 2.2});
    vect->push_back(new vector<float>{4.5, 2.3});
    Tensor* t2 = Tensor::fromVector(vect);

    t->matmul(t2)->display();
    return 0;
}