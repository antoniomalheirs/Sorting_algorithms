#include <iostream>
#include <chrono> 
#include <string>
#include <iomanip>

template <typename T>
void measureSortingTime(void (*sortFunction)(T[], int), T arr[], int n, const std::string& sortName) {
    auto start = std::chrono::high_resolution_clock::now(); // Marca o inicio da execucao

    sortFunction(arr, n); // Chama a funcao de ordenacao com 2 parametros

    auto end = std::chrono::high_resolution_clock::now(); // Marca o final da execucao
    std::chrono::duration<double> duration = end - start; // Calcula a duracao em segundos

    // Configura a saida para mostrar exatamente 10 casas decimais
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

template <typename T>
int countIterations(int (*sortFunction)(T[], int, int), T arr[], int low, int high) {
    return sortFunction(arr, low, high);
}

void bubbleSort(int arr[], int n) {
    int iterations = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            iterations++;

            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }

    std::cout << "Bubble Sort iteracoes: " << iterations << std::endl;
}

void insertionSort(int arr[], int n) {
    int iterationss = 0;

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key)
        {
            
            arr[j + 1] = arr[j];
            j--;
            iterationss++;
        }

        arr[j + 1] = key;
    }

    std::cout << "Insertion Sort iterações: " << iterationss << std::endl;
}

void selectionSort(int arr[], int n) {
    int iterationsss = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            iterationsss++;

            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        std::swap(arr[i], arr[minIndex]);
    }

    std::cout << "Selection Sort iterações: " << iterationsss << std::endl;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) 
    {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) 
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) 
    {
        R[j] = arr[mid + 1 + j];
    }

    int x = 0, y = 0, k = left;
    while (x < n1 && y < n2) 
    {
        if (L[x] <= R[y]) 
        {
            arr[k++] = L[x++];
        }
        else 
        {
            arr[k++] = R[y++];
        }
    }

    while (x < n1) 
    {
        arr[k++] = L[x++];
    }

    while (y < n2) 
    {
        arr[k++] = R[y++];
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int mergeSort2(int arr[], int left, int right) {
    int iterations = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        iterations += mergeSort2(arr, left, mid);
        iterations += mergeSort2(arr, mid + 1, right);
        merge(arr, left, mid, right);
        iterations += right - left + 1; // Contar o número de elementos mesclados
    }
    return iterations;
}

int quickSort2(int arr[], int low, int high) {
    if (low < high) {
        int partitionIndex = partition(arr, low, high);
        int leftIterations = quickSort2(arr, low, partitionIndex - 1);
        int rightIterations = quickSort2(arr, partitionIndex + 1, high);
        return leftIterations + rightIterations + 1; // +1 para contar a própria iteração atual
    }
    return 0;
}

int main() {
    int Ordenado[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int Parcial[] = { 1, 2, 3, 4, 5, 10, 9, 8, 7, 6 };
    int Randomico[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int* men=0;
    const int n = sizeof(Ordenado) / sizeof(Ordenado[0]);
    const int n2 = 100;

    int Ordenado2[n2];
    int Parcial2[n2];
    int Randomico2[n2];

    int O4[n2];
    int P4[n2];
    int R4[n2];
    int O3[n];
    int P3[n];
    int R3[n];

    for (int i = 0; i < n2; i++) { Ordenado2[i] = i + 1; }
    for (int i = 0; i < n2 / 2; i++) { Parcial2[i] = i + 1; }
    for (int i = n2 / 2; i < n2; i++) { Parcial2[i] = n2 - i; }
    for (int i = 0; i < n2; i++) { Randomico2[i] = n2 - i; }

    int choice;
    while (true) {
        // Restaurar os vetores aos estados iniciais
        std::copy(Ordenado2, Ordenado2 + n2, O4);
        std::copy(Parcial2, Parcial2 + n2, P4);
        std::copy(Randomico2, Randomico2 + n2, R4);

        std::copy(Ordenado, Ordenado + n, O3);
        std::copy(Parcial, Parcial + n, P3);
        std::copy(Randomico, Randomico + n, R3);

        std::cout << "Escolha uma opcao:" << std::endl;
        std::cout << "1- Bubble Sort" << std::endl;
        std::cout << "2- Insertion Sort" << std::endl;
        std::cout << "3- Selection Sort" << std::endl;
        std::cout << "4- Quick Sort" << std::endl;
        std::cout << "5- Merge Sort" << std::endl;
        std::cout << "6- Sair" << std::endl;
        std::cin >> choice;

        if (choice == 6) 
        {
            break;
        }

        switch (choice) {
        case 1:
            system("cls");
            // Medição do tempo para Bubble Sort
            std::cout << "Bubble Sort:" << std::endl;
            measureSortingTime(bubbleSort, O3, n, "Array ordenado");
            measureSortingTime(bubbleSort, P3, n, "Array parcial");
            measureSortingTime(bubbleSort, R3, n, "Array randomico");
            std::cout << std::endl;

            // Medição do tempo para Bubble Sort
            std::cout << "Bubble Sort:" << std::endl;
            measureSortingTime(bubbleSort, O4, n2, "Array ordenado");
            measureSortingTime(bubbleSort, P4, n2, "Array parcial");
            measureSortingTime(bubbleSort, R4, n2, "Array randomico");
            std::cout << std::endl;
            // Chamar a função de ordenação escolhida com Ordenado, Parcial ou Randomico
            // Imprimir o vetor ordenado após a operação
            break;

        case 2:
            system("cls");
            // Medição do tempo para Insertion Sort
            std::cout << "Insertion Sort:" << std::endl;
            measureSortingTime(insertionSort, O3, n, "Array ordenado");
            measureSortingTime(insertionSort, P3, n, "Array parcial");
            measureSortingTime(insertionSort, R3, n, "Array randomico");
            std::cout << std::endl;

            // Medição do tempo para Insertion Sort
            std::cout << "Insertion Sort:" << std::endl;
            measureSortingTime(insertionSort, O4, n2, "Array ordenado");
            measureSortingTime(insertionSort, P4, n2, "Array parcial");
            measureSortingTime(insertionSort, R4, n2, "Array randomico");
            std::cout << std::endl;
            // Chamar a função de ordenação escolhida com Ordenado, Parcial ou Randomico
            // Imprimir o vetor ordenado após a operação
            break;

        case 3:
            system("cls");
            // Medição do tempo para Selection Sort
            std::cout << "Selection Sort:" << std::endl;
            measureSortingTime(selectionSort, O3, n, "Array ordenado");
            measureSortingTime(selectionSort, P3, n, "Array parcial");
            measureSortingTime(selectionSort, R3, n, "Array randomico");
            std::cout << std::endl;

            // Medição do tempo para Selection Sort
            std::cout << "Selection Sort:" << std::endl;
            measureSortingTime(selectionSort, O4, n2, "Array ordenado");
            measureSortingTime(selectionSort, P4, n2, "Array parcial");
            measureSortingTime(selectionSort, R4, n2, "Array randomico");
            std::cout << std::endl;
            // Chamar a função de ordenação escolhida com Ordenado, Parcial ou Randomico
            // Imprimir o vetor ordenado após a operação
            break;

        case 4:
            system("cls");
            
            // Medição do tempo para Quick Sort
            std::cout << "Quick Sort:" << std::endl;
            std::cout << "Quick Sort iteracoes: " << countIterations(quickSort2, O3, 0, n - 1) << std::endl;
            measureSortingTime(quickSort, O3, 0, n - 1, "Array ordenado");
            std::cout << "Quick Sort iteracoes: " << countIterations(quickSort2, P3, 0, n - 1) << std::endl;
            measureSortingTime(quickSort, P3, 0, n - 1, "Array parcial");
            std::cout << "Quick Sort iteracoes: " << countIterations(quickSort2, R3, 0, n - 1) << std::endl;
            measureSortingTime(quickSort, R3, 0, n - 1, "Array randomico");
            std::cout << std::endl;

            // Medição do tempo para Quick Sort
            std::cout << "Quick Sort:" << std::endl;
            std::cout << "Quick Sort iteracoes: " << countIterations(quickSort2, O4, 0, n2 - 1) << std::endl;
            measureSortingTime(quickSort, O4, 0, n2 - 1, "Array ordenado");
            std::cout << "Quick Sort iteracoes: " << countIterations(quickSort2, P4, 0, n2 - 1) << std::endl;
            measureSortingTime(quickSort, P4, 0, n2 - 1, "Array parcial");
            std::cout << "Quick Sort iteracoes: " << countIterations(quickSort2, R4, 0, n2 - 1) << std::endl;
            measureSortingTime(quickSort, R4, 0, n2 - 1, "Array randomico");
            std::cout << std::endl;
            // Chamar a função de ordenação escolhida com Ordenado, Parcial ou Randomico
            // Imprimir o vetor ordenado após a operação
            break;

        case 5:
            system("cls");
            // Medição do tempo para Merge Sort
            std::cout << "Merge Sort:" << std::endl;
            std::cout << "Merge Sort iteracoes: " << countIterations(mergeSort2, O3, 0, n - 1) << std::endl;
            measureSortingTime(mergeSort, O3, 0, n - 1, "Array ordenado");
            std::cout << "Merge Sort iteracoes: " << countIterations(mergeSort2, P3, 0, n - 1) << std::endl;
            measureSortingTime(mergeSort, P3, 0, n - 1, "Array parcial");
            std::cout << "Merge Sort iteracoes: " << countIterations(mergeSort2, R3, 0, n - 1) << std::endl;
            measureSortingTime(mergeSort, R3, 0, n - 1, "Array randomico");
            std::cout << std::endl;

            // Medição do tempo para Merge Sort
            std::cout << "Merge Sort:" << std::endl;
            std::cout << "Merge Sort iteracoes: " << countIterations(mergeSort2, O4, 0, n2 - 1) << std::endl;
            measureSortingTime(mergeSort, O4, 0, n2 - 1, "Array ordenado");
            std::cout << "Merge Sort iteracoes: " << countIterations(mergeSort2, P4, 0, n2 - 1) << std::endl;
            measureSortingTime(mergeSort, P4, 0, n2 - 1, "Array parcial");
            std::cout << "Merge Sort iteracoes: " << countIterations(mergeSort2, R4, 0, n2 - 1) << std::endl;
            measureSortingTime(mergeSort, R4, 0, n2 - 1, "Array randomico");
            std::cout << std::endl;
            // Chamar a função de ordenação escolhida com Ordenado, Parcial ou Randomico
            // Imprimir o vetor ordenado após a operação
            break;

        default:
            system("cls");
            std::cout << "Opcao invalida!" << std::endl;
            std::cout << std::endl;
            break;
        }
    }

    return 0;
}

