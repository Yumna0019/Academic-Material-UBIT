// proper way of openmp code : sum of n num
#include <iostream>
#include <omp.h>  // Include OpenMP header

using namespace std;

int main() {
    const int n = 100;
    int arr[n];
    for (int i = 0; i < n; i++) arr[i] = i + 1;

    int sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    cout << "Sum: " << sum << endl;
    return 0;
}


// sum of n numbers
    const int n=100;
    int arr[n];
    for(int i=0; i<n; i++) arr[i]=i+1;
    int sum=0;

    #pragma omp parallel for reduction(+:sum)
    for(int i=0; i<n;i++){
        sum+=arr[i];
    }

    cout<<"Sum: "<<sum<<endl;
    
//  sum of vectors
    int sum=0; 
    int n=5;
    int v1[n] = {1,2,3,4,5};
    int v2[n] = {1,2,3,4,5};
    int v3[n];

    #pragma omp parallel for 
    for(int i=0; i<n;i++){
        v3[i] = v1[i] + v2[i];
    }
    
    for(int i=0; i<n; i++){
        cout<<v3[i]<<" , " ;
    }

// vector multiplication
    int n=5;
    int v1[n] = {1,2,3,4,5};
    int v2[n] = {1,2,3,4,5};
    int v3[n];
    #pragma omp parallel for
    for(int i=0; i<n;i++){
        v3[i] = v1[i] * v2[i];
    }
    
    for(int i=0; i<n; i++){
        cout<<v3[i]<<" , " ;
    }

//dot product of vectors
    int n=3;
    int v1[n] = {1,2,3};
    int v2[n] = {1,2,3};
    int dot=0;

    #pragma omp parallel for reduction(+:dot)
    for(int i=0; i<n; i++){
        dot+= v1[i]*v2[i];
    }

    cout<<"The answer is: "<<dot<<endl;

//  matrix addition
    int n=3;
    int sum=0;
    int a[n][n] = {{1,2,3},{4,5,6},{7,8,9}};
    int b[n][n] = {{9,8,7},{6,5,4},{3,2,1}};
    int c[n][n];
    
    #pragma omp parallel for 
    for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    
    for(int i=0; i<n;i++){
        for(int j=0;j<n; j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
//  matrix multiplication
    int n=3;
    int sum=0;
    int a[n][n] = {{1,2,3},{4,5,6},{7,8,9}};
    int b[n][n] = {{9,8,7},{6,5,4},{3,2,1}};
    int c[n][n] = {0};
    
    #pragma omp parallel for 
    for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0; k<n; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    
    for(int i=0; i<n;i++){
        for(int j=0;j<n; j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
