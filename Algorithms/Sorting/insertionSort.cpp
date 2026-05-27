#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    for(int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void display(std::vector<int>& arr) {
    for(int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec = {2,9,3,4,2,1,-9,4,3,2,1,5,-8,34,0};
    std::cout << "Unsorted : ";
    display(vec);
    std::cout << "Sorted : ";
    insertionSort(vec);
    display(vec);
    return 0;
}