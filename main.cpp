
// Alejandro Hidalgo Badillo  A01423412
// Fecha 20 08 2022
//Actividad 1punto1 Implementacion de la tecnica de programacien divide y venceras

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void merge(double array[], int const left, int const mid, int const right) {
	//la funcion del merge tiene una complejidad On 
  auto const sub1 = mid - left + 1;
  auto const sub2 = right - mid;

  // Se crean los arreglos temporales
  auto *arrayIzq = new double[sub1], *arrayDer = new double[sub2];

  // Copiar datos a arreglos temporales
  for (auto i = 0; i < sub1; i++)
    arrayIzq[i] = array[left + i];
  for (auto j = 0; j < sub2; j++)
    arrayDer[j] = array[mid + 1 + j];

  auto indexS1 = 0, indexS2 = 0;
  int indexMA = left;

  while (indexS1 < sub1 && indexS2 < sub2) {
    if (arrayIzq[indexS1] >= arrayDer[indexS2]) {
      array[indexMA] = arrayIzq[indexS1];
      indexS1++;
    } else {
      array[indexMA] = arrayDer[indexS2];
      indexS2++;
    }
    indexMA++;
  }
  // se copian los elementos sobrantes de la izquierda
  while (indexS1 < sub1) {
    array[indexMA] = arrayIzq[indexS1];
    indexS1++;
    indexMA++;
  }
  // se copian los elementos sobrantes de la derecha
  while (indexS2 < sub2) {
    array[indexMA] = arrayDer[indexS2];
    indexS2++;
    indexMA++;
  }
  delete[] arrayIzq;	//se destruyen los arreglos arrayIzq / arrayDer
  delete[] arrayDer;	
}

void mergeSort(double array[], int const inicio, int const final) {
	//complejidad del mergSort es O logn
  if (inicio >= final)
    return; // recursividad

  auto mitad = inicio + (final - inicio) / 2;
  mergeSort(array, inicio, mitad); //se hace recursion 
  mergeSort(array, mitad + 1, final); //uso de la recursividad
  merge(array, inicio, mitad, final);
}

// Imprimir Arreglo
void printArray(double arr[], int size) {
  //complejidad de printArray es On
  for (auto i = 0; i < size; i++) {
    cout << arr[i] <<endl;
  }
}

int main() {
	//la complejidad del main es On
  auto start = std::chrono::high_resolution_clock::now();
  
	//declaracion de variables de entrada
	int N;
	
  cin >> N;
	//Se almacenan los datos que se quieren ordenar:
  double arr[N];
  for (int a = 0; a < N; a++) {
    cin >> arr[a];
  }

 //size es una variable solicitada por nuestra funcion merge para saber el final del arreglo
  auto size = sizeof(arr) / sizeof(arr[0]);


  mergeSort(arr, 0, size - 1);

  
  printArray(arr, size);
	//Complejidad general
	
	//el programa en general tiene una complejidad de O logn debido a la recursion generara en el mergeSort

	//la funcion es logaritmica debido a la recursion empleada en el merge sort
  return 0;
}
