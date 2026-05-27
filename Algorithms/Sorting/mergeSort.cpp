#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, std::vector<int>& larr, std::vector<int>& rarr) {
    int i = 0, l = 0, r = 0;
    while(l < larr.size() && r < rarr.size()) {
        if(larr[l] < rarr[r]) {
            arr[i++] = larr[l++];
        } else {
            arr[i++] = rarr[r++];
        }
    }
    while(l < larr.size()) {
        arr[i++] = larr[l++];
    }
    while(r < rarr.size()) {
        arr[i++] = rarr[r++];
    }
}

void mergeSort(std::vector<int>& arr) {
    if(arr.size() <= 1) return;
    int mid = arr.size() / 2;
    std::vector<int> larr, rarr;
    for(int i = 0; i < arr.size(); i++) {
        if(i < mid) {
            larr.push_back(arr[i]);
        } else {
            rarr.push_back(arr[i]);
        }
    }
    mergeSort(larr);
    mergeSort(rarr);
    merge(arr, larr, rarr);
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
    mergeSort(vec);
    display(vec);
    return 0;
}