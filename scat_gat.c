#include <stdio.h>
#include "mpi.h"
#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv []){
    int size, rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    int** ptr;
    int n = 8; //elements of array is n * n
    int columns = n;
    int rows = n;
    int root = 0;
    int send_data[];
    if(rank == root){
        //allocating the array
        ptr = (int**)malloc(rows*sizeof(int*));
        for(int i = 0; i < rows; i++){
            *(ptr + i ) = (int*)malloc(columns*sizeof(int));
        }
        srand(time(NULL));
        //assign values to array
        for(int i = 0; i < rows; i++){
            for(int j=0; j < columns; j++){
                ptr[i][j] = rand() % 50;
                printf("%d ",ptr[i][j]);
            }
            printf("\n");
        }
    }

    MPI_Finalize();
}