#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        int min_idx = i;
        for(int j = i+1; j < arr.size(); j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            } 
        }
        if(min_idx != i) {
           std::swap(arr[min_idx], arr[i]);
        }
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
    selectionSort(vec);
    display(vec);
    return 0;
}