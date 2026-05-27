#include <iostream>
#include <vector>

int divide(std::vector<int>& arr, int start, int end) {
    // In nearly sorted or sorted data quick sort falls in O(n^2) time complaxity to avoid that following thing is used
    int rand = start + (std::rand() % (end - start + 1));
    std::swap(arr[end], arr[rand]);

    int pivot = arr[end];
    int i = start - 1;
    for(int j = start; j < end; j++) {
        if(arr[j] < pivot) {
            std::swap(arr[++i], arr[j]);
        }
    }
    std::swap(arr[++i], arr[end]);
    return i;
}


void quickSort(std::vector<int>& arr, int start, int end) {
    if(start >= end) return;
    int pivot = divide(arr, start, end);
    quickSort(arr, start, pivot-1);
    quickSort(arr, pivot+1, end);
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
    quickSort(vec, 0, vec.size() - 1);
    display(vec);
    return 0;
}