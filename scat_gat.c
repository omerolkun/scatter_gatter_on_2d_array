#include <stdio.h>
#include "mpi.h"
#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv []){
    int size, rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    
    int n = size;
    int arr[n][n];
    int root = 0;
    int gathered_data_to_root [size];
    if (rank  == root){
        srand(time(NULL));
        for(int i = 0; i < n; i++){
            for (int j = 0; j < n ; j++){
                arr[i][j]  = rand() % 30;
                printf("%d ",arr[i][j]);
            }
            printf("\n");
        }
        /*for(int i = 0; i < size; i++){
            printf("my rank is %d and gathered_data[%d] is %d \n",rank,i,gathered_data_to_root[i]);
        } */       
    }

    int recv[n];
    MPI_Scatter(*arr,n,MPI_INT,recv,n,MPI_INT,root,MPI_COMM_WORLD);
    for(int i = 0; i < n ; i++){
        //printf("my rank is %d and recv[%d] is %d \n",rank,i,recv[i]);
    }
    int partial_sum = 0;
    for (int i = 0; i < n; i++){
        partial_sum = partial_sum + recv[i];
    }
    printf("rank %d and sum %d \n",rank, partial_sum);
    MPI_Gather(&partial_sum,1,MPI_INT,&gathered_data_to_root,1,MPI_INT,root,MPI_COMM_WORLD);

    if(rank == root){
        int sum_of_arr = 0;
        for(int i = 0; i < size; i++){
            sum_of_arr = sum_of_arr + gathered_data_to_root[i];
        }
        printf("the sum of the array is %d \n",sum_of_arr);
    }


    MPI_Finalize();

    return 0;
}