//gcc -Wall orden.cpp -lm -o grafica

#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(){
	 int NUM_COMANDOS=5;

    char * configGnuplot[] = {"set title \"QuickSort VS MergeSort: NroDatos VS Tiempo\"", 
                                "set ylabel \"Tiempo\"",
                                "set xlabel \"NroDatos\"",
                                "plot \"QuickSort.txt\" using 1:2 with lines",
										  "replot \"MergeSort.txt\" using 1:2 with lines"
                               };

    FILE * ventanaGnuplot = popen ("gnuplot -persist", "w");

    // Ejecuta los comandos del GNU Plot uno por uno
    for (int i=0;i<NUM_COMANDOS;i++){
		 fprintf(ventanaGnuplot, "%s \n", configGnuplot[i]);
	 }

    return 0;

}
