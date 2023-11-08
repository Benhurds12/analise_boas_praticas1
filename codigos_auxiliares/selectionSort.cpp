#include <iostream>

using namespace std;
void swapping(int &a, int &b) {         //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}

void display(const int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}

void selectionSort(int *array, int size) {
   int i, j;
   for(i = 0; i < size - 1; i++) {
      int imin = i; // Movido a declaração para o escopo interno
      for(j = i + 1; j < size; j++) {
         if(array[j] < array[imin]) {
            imin = j;
         }
      }
      // Colocando na posição correta
      swap(array[i], array[imin]);
   }
}


int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];           //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   selectionSort(arr, n);
   cout << "Array after Sorting: ";
   display(arr, n);
}
