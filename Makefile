all : hello split

hello : hello_mpi.c
	mpicc hello_mpi.c -o ./bin/hello

split : comm_split_matrix_multiply.c
	mpicc comm_split_matrix_multiply.c -o ./bin/split

.PHONY:
runhello :
	mpirun -np 3 ./bin/hello

runsplit :
	mpirun -np 6 ./bin/split


clean :
	rm ./bin/*