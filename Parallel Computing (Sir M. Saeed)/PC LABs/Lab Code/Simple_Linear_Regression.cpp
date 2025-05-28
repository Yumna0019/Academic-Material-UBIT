#include <iostream>
using namespace std;

int main() {
    // Input data
    double x[] = {1, 2, 3, 4, 5};
    double y[] = {2, 4, 5, 4, 5};
    int n = 5;

    // Step 1: Calculate means
    double sum_x = 0, sum_y = 0;
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
    }
    double mean_x = sum_x / n;
    double mean_y = sum_y / n;

    // Step 2: Calculate slope (b) and intercept (a)
    double num = 0, den = 0;
    for (int i = 0; i < n; i++) {
        num += (x[i] - mean_x) * (y[i] - mean_y);
        den += (x[i] - mean_x) * (x[i] - mean_x);
    }
    double b = num / den;                 // Slope
    double a = mean_y - b * mean_x;       // Intercept

    // Step 3: Show result
    cout << "y = " << a << " + " << b << "x" << endl;

    // Predict y for a new x
    double new_x = 6;
    double predicted_y = a + b * new_x;
    cout << "Predicted y for x = " << new_x << " is " << predicted_y << endl;

    return 0;
}



// OPENMP
//regression analysis equation
    const int n = 5;
    double x[n] = {1, 2, 3, 4, 5};
    double y[n] = {2, 4, 5, 4, 5};

    double sumX=0, sumY=0, sumXY=0, sumX2=0;
    
    #pragma omp parallel for reduction(+:sumX, sumY,sumXY, sumX2)
    for(int i=0; i<n ; i++){
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i]*y[i];
        sumX2 += x[i]*x[i];
    }
    
    double b = (n*sumXY - sumX*sumY) / (n*sumX2 - sumX*sumX);
    double a = (sumY - b*sumX)/n;
    
    cout<<"Equation: "<< a << " + "<<b<<" x "<<endl;