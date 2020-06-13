#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <chrono>
#include <time.h>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int relOrden(const void * numero1, const void * numero2) 
{ 
    return ( *(int*)numero1 - *(int*)numero2 ); 
} 

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

	 int NUM_ELEMENTOS=100000;
	 int paso=1000;
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
		 vector<int> arr3(n*paso);
		 arr3.reserve(n*paso);
		 int *arr4;
		 arr4 = new int [n*paso];

		 for(int i=1;i<=n*paso;i++){
			arr[i-1]=1 + rand() % (n*n*paso - 1);
			arr2[i-1]=arr[i-1];
			arr3[i-1]=arr[i-1];
			arr4[i-1]=arr[i-1];
		 }
	  	 
		 int nn = sizeof(arr) / sizeof(arr[0]);

		 auto inicioSort = chrono::high_resolution_clock::now();
	    std::sort(arr.begin(),arr.end());
		 auto finSort = chrono::high_resolution_clock::now();
		 long long tiemposort = chrono::duration_cast<chrono::nanoseconds> (finSort-inicioSort).count();

	    valoresY[n-1]=tiemposort;

		 auto inicioQuick = chrono::high_resolution_clock::now();
		 QuickSort(arr2,0,n*paso-1);
		 auto finQuick = chrono::high_resolution_clock::now();
		 long long tiempoQuick = chrono::duration_cast<chrono::nanoseconds> (finQuick-inicioQuick).count();

	    valoresY2[n-1]=tiempoQuick;

		 auto inicioMerge = chrono::high_resolution_clock::now();
		 MergeSort(arr3,0,n*paso-1);
		 auto finMerge = chrono::high_resolution_clock::now();
		 long long tiempoMerge = chrono::duration_cast<chrono::nanoseconds> (finMerge-inicioMerge).count();

	    valoresY3[n-1]=tiempoMerge;

		 auto inicioQSort = chrono::high_resolution_clock::now();
		 qsort(arr4, n*paso, sizeof(int), relOrden);
		 auto finQSort = chrono::high_resolution_clock::now();
		 long long tiempoQSort = chrono::duration_cast<chrono::nanoseconds> (finQSort-inicioQSort).count();

	    valoresY4[n-1]=tiempoQSort;

		 delete [] arr4;
		 
	 }

	 //Lee el archivo puntosGraficar par aguardar los valores
    FILE * archivoPuntos = fopen("Sort.txt", "w");
    FILE * archivoPuntos2 = fopen("QuickSort.txt", "w");
    FILE * archivoPuntos3 = fopen("MergeSort.txt", "w");
    FILE * archivoPuntos4 = fopen("QSort.txt", "w");

    for (i=0;i<NUM_PUNTOS;i++){
 		 fprintf(archivoPuntos, "%lf %lf \n", valoresX[i], valoresY[i]);
 	 }
    for (i=0;i<NUM_PUNTOS;i++){
 		 fprintf(archivoPuntos2, "%lf %lf \n", valoresX[i], valoresY2[i]);
 	 }
    for (i=0;i<NUM_PUNTOS;i++){
 		 fprintf(archivoPuntos3, "%lf %lf \n", valoresX[i], valoresY3[i]);
 	 }
    for (i=0;i<NUM_PUNTOS;i++){
 		 fprintf(archivoPuntos4, "%lf %lf \n", valoresX[i], valoresY4[i]);
 	 }

    fclose(archivoPuntos);
    fclose(archivoPuntos2);
    fclose(archivoPuntos3);
    fclose(archivoPuntos4);

   return 0;

}
