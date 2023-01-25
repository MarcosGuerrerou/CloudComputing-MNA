// Inclución de librería OpenMP (Procesamiento paralelo) y IOstream (Input / Output)
#include <omp.h>
#include <iostream>

// Definición de constantes para tamaño de los arreglos, tamaño de las divisiones y 
// cuántos serán mostrados en la consola.
#define N 1000
#define chunk 100
#define mostrar 10

// Declaración de función para imprimir arreglos.
void imprimeArreglo(float *d);

// Función principal
int main(){
    std::cout << "Sumando Arreglos en Paralelo! \n";
    
    // Declarar arreglos y contador.
    float a[N], b[N], c[N];
    int i;

    // Generación de arreglos a partir de valores pre-definidos.
    for (i=0; i < N; i++){
        a[i] = i*10;
        b[i] = (i+3)*3.7;
    }

    int pedazos = chunk;

    // Ciclo paralelo
    #pragma omp parallel for \
    shared(a,b,c, pedazos) private(i) \
    schedule(static, pedazos)

    // Ciclo para realizar operación
    for (i = 0; i < N; i++){
        c[i] = a[i] + b[i];
    }

    // Mostrar resultados
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);
}

// Función para imprimir arreglos
void imprimeArreglo(float *d){
    for (int x = 0; x < mostrar; x++){
        std::cout << d[x] << " - ";
    }
    std::cout << std::endl;
}