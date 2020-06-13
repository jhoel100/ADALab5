//gcc -Wall orden.cpp -lm -o grafica

#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(){
	 system("g++ orden.cpp -o orden.out");
	 system("./orden.out");
	 system("gcc -Wall grafica.cpp -lm -o grafica");
	 system("gcc -Wall grafica2.cpp -lm -o grafica2");
	 system("gcc -Wall grafica3.cpp -lm -o grafica3");
	 system("gcc -Wall grafica4.cpp -lm -o grafica4");
	 system("gcc -Wall grafica5.cpp -lm -o grafica5");
	 system("gcc -Wall grafica6.cpp -lm -o grafica6");
	 system("gcc -Wall grafica7.cpp -lm -o grafica7");
	 system("gcc -Wall grafica8.cpp -lm -o grafica8");

	 system("./grafica");
	 system("./grafica2");
	 system("./grafica3");
	 system("./grafica4");
	 system("./grafica5");
	 system("./grafica6");
	 system("./grafica7");
	 system("./grafica8");

    return 0;

}
