#include <pthread.h>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include "lab1_IO.h"
#include "timer.h"
#include <cmath>
using namespace std;

// P is the same is number of threads 
int p ;

// n is the size of matrix
int n ;

// Matrixes
int** A ;
int** B;
int** C;


// Performs Matrix Multiplication
void* threadfunction(void* thread_rank){
    int* rank = (int*) thread_rank ;

    int x = floor((*rank) / sqrt(p)) ;
    int y = (*rank) % int(sqrt(p)) ;

    int matrixAUpperBound = (n/sqrt(p) * (x + 1) ) -1 ;
    int matrixALowerBound = (n/sqrt(p)) * x ;

    int matrixBUpperBound = (n/sqrt(p) * (y + 1) ) -1 ;
    int matrixBLowerBound = (n/sqrt(p)) * y ;

    //     // Matrix Multiplication
    for(int i = matrixALowerBound ; i <= matrixAUpperBound ; i++){
        for(int k = 0 ; k < n ; k++){
            for(int j = matrixBLowerBound ; j <= matrixBUpperBound ; j++){
                C[i][j] += A[i][k] * B[k][j] ;
            }
        }
    }
}

// Perform Matrix Multiplication without the use of threads
void matrixMultiplicationNormal(int** A , int** B){
    int D[n][n] ;
    for(int i = 0 ; i < n ; i++){
        for(int k = 0 ; k < n ; k++){
            for(int j = 0; j < n ; j++){
                D[i][j] += A[i][k] * B[k][j] ;
            }
        }
    }
}

int main(int argc , char* argv[]){
    int NTHREADS = atoi(argv[1]) ;
    pthread_t threadId[NTHREADS] ;
    int threadRank[NTHREADS]  ;
    double start , end , nStart , nEnd , timetaken , ntimetaken;

    p = NTHREADS ;

    Lab1_loadinput(&A , &B , &n) ;

    C = new int*[n] ;

    for(int i = 0 ; i < n  ; i++){
        C[i] = new int[n] ;
    }
    
    for(int i = 0 ; i < n ; i++){
        for(int k = 0 ; k < n ; k++){
            C[i][k] = 0 ;
        }
    } 
    GET_TIME(start) ;
    for(int i = 0 ; i < NTHREADS ; i++){
        threadRank[i] = i ; 
        pthread_create(&threadId[i] , NULL , threadfunction  , (void *)&threadRank[i]) ;
    }
    
    for(int j =0; j < NTHREADS; j++){
        pthread_join( threadId[j], NULL); 
    }
    GET_TIME(end) ;

    GET_TIME(nStart) ;
    matrixMultiplicationNormal(A , B) ;
    GET_TIME(nEnd) ;

    ntimetaken = nEnd - nStart ;
    timetaken = end - start ;

    cout << "Time taken using no threads: " <<ntimetaken<< endl ;
    cout << "Time taken with the use of threads: "<<timetaken << endl ;

    Lab1_saveoutput(C , &n , timetaken) ;

}