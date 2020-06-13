#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <chrono>

using namespace std;

int Particion(vector<int>& arreglo, int inicio, int fin)  
{  
	 int pivote=arreglo[fin];
	 int i=inicio-1;

	 int auxiliar;	 

	 for(int j=inicio;j<fin;j++){
			if(arreglo[j]<=pivote){
				i=i+1;
				auxiliar=arreglo[i];
				arreglo[i]=arreglo[j];
				arreglo[j]=auxiliar;
			}
	 }
	 auxiliar=arreglo[i+1];
	 arreglo[i+1]=arreglo[fin];
	 arreglo[fin]=auxiliar;

	return i+1;
	
}  

void QuickSort(vector<int>& arreglo, int inicio, int fin) 
{  
	if(inicio<fin){
		int medio=Particion(arreglo,inicio,fin);
		QuickSort(arreglo,inicio,medio-1);
		
		QuickSort(arreglo,medio+1,fin);
	}
}


void Intercala(vector<int>& arreglo, int inicio,int medio, int fin){
	vector<int> auxiliar(fin-inicio+1);
	int i;
	int j;
	int k;
	for(i=inicio;i<=medio;i++){
		auxiliar[i-inicio]=arreglo[i];
	}
	for(j=medio+1;j<=fin;j++){
		auxiliar[fin+medio+1-j-inicio]=arreglo[j];
	}
	i=inicio;
	j=fin;
	for(k=inicio;k<=fin;k++){
		if(auxiliar[i-inicio]<=auxiliar[j-inicio]){
			arreglo[k]=auxiliar[i-inicio];
			i=i+1;
		}else{
			arreglo[k]=auxiliar[j-inicio];
			j=j-1;
		}
	}

}

void MergeSort(vector<int>& arreglo, int inicio, int fin){
	if(inicio<fin){
		int medio=floor((inicio+fin)/2);
		MergeSort(arreglo,inicio,medio);
		MergeSort(arreglo,medio+1,fin);
		Intercala(arreglo,inicio,medio,fin);
		
	}	

}

int main(){

	 int NUM_ELEMENTOS=100;
	 int paso=5;
	 int NUM_PUNTOS=NUM_ELEMENTOS/paso;

    // X, Y valores de los puntos a graficar
	 vector<double> valoresX(NUM_PUNTOS);
	 valoresX.reserve(NUM_PUNTOS);
	 vector<double> valoresY(NUM_PUNTOS);
	 valoresY.reserve(NUM_PUNTOS);
	 vector<double> valoresY2(NUM_PUNTOS);
	 valoresY2.reserve(NUM_PUNTOS);
	 vector<double> valoresY3(NUM_PUNTOS);
	 valoresY3.reserve(NUM_PUNTOS);
	 vector<double> valoresY4(NUM_PUNTOS);
	 valoresY4.reserve(NUM_PUNTOS);

	 clock_t t_ini, t_fin;
	 double secs;

    register int i=0;

	 srand(time(NULL));

	 for(int n=1;n<=NUM_PUNTOS;n++){
		 valoresX[n-1] =n*paso;
		 
		 vector<int> arr(n*paso);
		 arr.reserve(n*paso);
		 vector<int> arr2(n*paso);
		 arr2.reserve(n*paso);

		 for(int i=1;i<=n*paso;i++){
			arr[i-1]=1 + rand() % (n*n*paso - 1);
			arr2[i-1]=1 + rand() % (n*n*paso - 1);
		 }
	  	 
		 int nn = sizeof(arr) / sizeof(arr[0]);

		 t_ini = clock();
	    std::sort(arr.begin(),arr.end());
		 t_fin = clock();

		 secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
	    valoresY[n-1]=secs*1000;

		 t_ini = clock();
		 QuickSort(arr2,0,n*paso-1);
		 t_fin = clock();

		 secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
	    valoresY2[n-1]=secs*1000;
		 
	 }

	 //Lee el archivo puntosGraficar par aguardar los valores
    FILE * archivoPuntos = fopen("MergeSort.txt", "w");
    FILE * archivoPuntos2 = fopen("QuickSort.txt", "w");

    for (i=0;i<NUM_PUNTOS;i++){
 		 fprintf(archivoPuntos, "%lf %lf \n", valoresX[i], valoresY[i]);
 	 }
    for (i=0;i<NUM_PUNTOS;i++){
 		 fprintf(archivoPuntos2, "%lf %lf \n", valoresX[i], valoresY2[i]);
 	 }

    fclose(archivoPuntos);
    fclose(archivoPuntos2);

   return 0;

}
