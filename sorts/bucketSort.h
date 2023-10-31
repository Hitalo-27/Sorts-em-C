#include "../functions/functions.h"

// Função para classificar um balde usando o algoritmo de inserção
void insertionSort(std::vector<int>& bucket) {
    int n = bucket.size();
    for (int i = 1; i < n; i++) {
        int key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Função para realizar o Bucket Sort
void bucketSort(std::vector<int>& arr) {
    int n = arr.size();

    // Encontra o valor máximo no array
    int max_val = *std::max_element(arr.begin(), arr.end());

    // Crie baldes
    int num_buckets = max_val / 10 + 1;
    std::vector<std::vector<int>> buckets(num_buckets);

    // Coloca cada elemento no balde apropriado
    for (int i = 0; i < n; i++) {
        int index = arr[i] / 10;
        buckets[index].push_back(arr[i]);
    }

    // Classifica cada balde e coloque de volta no array original
    int index = 0;
    for (size_t i = 0; i < num_buckets; i++) {
        insertionSort(buckets[i]);
        for (size_t j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

SortResult runBucketSort(std::vector<int>& vetorBucket) {
    auto inicioBucket = std::chrono::high_resolution_clock::now();
    bucketSort(vetorBucket);
    auto fimBucket = std::chrono::high_resolution_clock::now();
    long long tempoBucket = std::chrono::duration_cast<std::chrono::milliseconds>(fimBucket - inicioBucket).count();

    SortResult result;
    result.name = "Bucket Sort";
    result.sortedArray = vetorBucket;
    result.timeMillis = tempoBucket;

    return result;
}
