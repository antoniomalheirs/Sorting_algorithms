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

template <typename T>
void measureSortingTime(void (*sortFunction)(T[], int, int), T arr[], int low, int high, const std::string& sortName) {
    auto start = std::chrono::high_resolution_clock::now();

    sortFunction(arr, low, high);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

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

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        std::swap(arr[i], arr[minIndex]);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
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

    // Medição do tempo para Selection Sort
    std::cout << "Selection Sort:" << std::endl;
    measureSortingTime(selectionSort, Ordenado, n, "Array ordenado");
    measureSortingTime(selectionSort, Parcial, n, "Array parcial");
    measureSortingTime(selectionSort, Randomico, n, "Array randomico");
    std::cout << std::endl;

    // Medição do tempo para Quick Sort
    std::cout << "Quick Sort:" << std::endl;
    measureSortingTime(quickSort, Ordenado, 0, n - 1, "Array ordenado");
    measureSortingTime(quickSort, Parcial, 0, n - 1, "Array parcial");
    measureSortingTime(quickSort, Randomico, 0, n - 1, "Array randomico");
    std::cout << std::endl;

    return 0;
}




