#include "../functions/functions.h"

void merge(std::vector<int> &arr, int left, int mid, int right)
{
    // Calcula os tamanhos dos subvetores
    int n1 = mid - left + 1;
    int n2 = right - mid;

    //Subvetores para aordenação
    std::vector<int> leftArr(n1); 
    std::vector<int> rightArr(n2);

    // Copia os dados dos subvetores originais para os subvetores temporários
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Mescla os subvetores em ordem crescente
    while (i < n1 && j < n2){
        if (leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        }else{
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copia quaisquer elementos restantes do subvetor esquerdo
    while (i < n1){
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copia quaisquer elementos restantes do subvetor direito
    while (j < n2){
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int> &arr, int left, int right){
    // Verifica se há mais de um elemento para ordenar
    if (left < right){
        int mid = left + (right - left) / 2;

        // Chama a função mergeSort recursivamente para os subvetores esquerdo e direito
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Mescla os subvetores ordenados em um único vetor ordenado
        merge(arr, left, mid, right);
    }
}



int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    std::vector<int> vetor;
    srand(static_cast<unsigned>(time(nullptr)));

    fill(vetor);

    int arrSize = vetor.size();

    auto inicio = std::chrono::high_resolution_clock::now();

    mergeSort(vetor, 0, arrSize - 1);

    auto fim = std::chrono::high_resolution_clock::now();
    auto tempo = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);

    std::cout << "O tempo necessario para ordenar todos os numeros foi de: " << tempo.count() << " milissegundos" << std::endl;

    system("pause");

    show(vetor);

    return 0;
}
