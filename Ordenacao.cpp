#include <iostream>
#include <chrono> 
#include <string>
#include <iomanip>

template <typename T>
void measureSortingTime(void (*sortFunction)(T[], int), T arr[], int n, const std::string& sortName) {
    auto start = std::chrono::high_resolution_clock::now(); // Marca o início da execução

    sortFunction(arr, n); // Chama a função de ordenação com 2 parâmetros

    auto end = std::chrono::high_resolution_clock::now(); // Marca o final da execução
    std::chrono::duration<double> duration = end - start; // Calcula a duração em segundos

    // Configura a saída para mostrar exatamente 10 casas decimais
    std::cout << std::fixed << std::setprecision(10);
    std::cout << sortName << " tempo: " << duration.count() << " segundos" << std::endl;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int Ordenado[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int Parcial[] = { 1, 2, 3, 4, 5, 10, 9, 8, 7, 6 };
    int Randomico[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    int n = sizeof(Ordenado) / sizeof(Ordenado[0]);
    

    // Medição do tempo para Bubble Sort
    std::cout << "Bubble Sort:" << std::endl;
    measureSortingTime(bubbleSort, Ordenado, n, "Array ordenado");
    measureSortingTime(bubbleSort, Parcial, n, "Array parcial");
    measureSortingTime(bubbleSort, Randomico, n, "Array randomico");
    std::cout << std::endl;

    // Medição do tempo para Insertion Sort
    std::cout << "Insertion Sort:" << std::endl;
    measureSortingTime(insertionSort, Ordenado, n, "Array ordenado");
    measureSortingTime(insertionSort, Parcial, n, "Array parcial");
    measureSortingTime(insertionSort, Randomico, n, "Array randomico");
    std::cout << std::endl;

    

    return 0;
}




