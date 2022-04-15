all : hello

hello : hello_mpi.c
	mpicc hello_mpi.c -o hello

.PHONY:
run :
	mpirun -np 3 hello

clean :
	rm hello