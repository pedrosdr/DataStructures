#include <iostream>
#include <vector>
#include <math.h>
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
};

int main(int argc, char* argv[])
{
    vector<vector<float>*>* vect = new vector<vector<float>*>();
    vect->push_back(new vector<float>{2.33485, 4.5, 3.3});
    vect->push_back(new vector<float>{1.1, 2.2, 7.6});
    vect->push_back(new vector<float>{4.5, 2.3, 1.7});
    vect->push_back(new vector<float>{1.1, 2.1, 5.7});
    Tensor* t = Tensor::fromVector(vect);
    Tensor* t2 = t->pow(3);
    t->display();
    t2->display();
    return 0;
}