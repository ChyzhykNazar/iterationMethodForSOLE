/*Знайти розв'язок СЛАР методом ітерацій з точнстю 0.01*/
/*Find a solution of system of linear equation using iteration method with precision of 0.01*/

#include <iostream>
#include <fstream>

using namespace std; 

void simpleIteration() {
    cout << "___________________________Iteration's method________________________________" << endl;
    double eps = 0.01;
    double norm = 0;
    int n = 0;
    int p = 0;
    int iter = 0;
    ifstream file;
    file.open("iterationMethod.txt");
    file >> n;
    double** a;
    double* b = new double[n];
    double* coeff = new double[n];           //created in order to write down by what coefficients we multiplied our columns
    double* xk = new double[n];
    double* xk1 = new double[n];
    a = new double* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new double[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file >> a[i][j];
        }
        file >> b[i];
    }
    for (int i = 0; i < n; i++) {
        file >> coeff[i];
    }
    file.close();
    for (int i = 0; i < n; i++) {
        xk1[i] = 0;
        xk[i] = 0;
    }
    do {
        iter++;
        for (int i = 0; i < n; i++) {
            xk1[i] = b[i];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    xk1[i] = xk1[i] - (a[i][j] * xk[j]);        //If it is not a diagonal element, then perform the action
                }
            }
            xk1[i] = xk1[i] / a[i][i];                          //divide into a diagonal element
        }
        norm = abs(xk1[0] - xk[0]);                             //when the cycle should end
        for (int i = 0; i < n; i++) {
            if (abs(xk1[i] - xk[i]) > norm) {
                norm = abs(xk1[i] - xk[i]);
            }
            xk[i] = xk1[i];
        }
    } while (norm > eps);
    for (int i = 0; i < n; i++)
    {
        xk[i] *= coeff[i];
        cout << "x[" << i << "] = " << xk[i] << endl << endl;           //output of roots
    }
    cout << "Iter: " << iter << endl << endl;
}


int main()
{
    simpleIteration();
}