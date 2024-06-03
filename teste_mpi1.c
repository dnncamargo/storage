#include <stdio.h>
#include "mpi.h"

// argc = quantidade de parâmetros passados pelo terminal
// argv = vetor de strings, onde cada posição corresponde a um parâmetro passado no terminal
int main(int argc, char *argv[]){
	int size, id;
	// Aqui inicia o bloco de execução paralela usando MPI
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);

	if(id == 0){
		// MASTER
		// Todas as instruções neste bloco serão executadas somente pelo processo 0.
		char msg[10];
		MPI_Status st;
		MPI_Recv(msg, 10, MPI_CHAR, 1, 0, MPI_COMM_WORLD, &st);
		printf("Mensagem : %s", msg);
 	}else if(id == 1){ // WORKERS
		// Todas as instruções neste bloco serão executadas pelo processo 1.
		char msg[10] = "douglas";
		MPI_Send(msg, 10, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
	}
	printf("TESTE ID = %d Total de processos = %d \n", id, size);

	// Todas as instruções fora dos blocos serão executadas por todos os processos.


	MPI_Finalize();


}
