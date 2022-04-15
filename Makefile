all : hello

hello : hello_mpi.c
	mpicc hello_mpi.c -o hello

.PHONY:
run :
	mpirun -np 4 hello

clean :
	rm hello