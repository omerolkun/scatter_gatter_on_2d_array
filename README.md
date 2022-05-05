# scatter_gatter_on_2d_array

this file is an example for usage of MPI_Scatter and MPI_Gather methods.
Process 0 is creating a 2D array. The row number and the column number of the matrix is equal which is number of the process in the communication.

MPI_Scatter method distrubute the rows for every process.
After the processes calculate the row sum, MPI_Gather method sends all sums to the root which is Process 0.

Finallly, Process 0 add all data and display the sum of the elements of the matrix.
