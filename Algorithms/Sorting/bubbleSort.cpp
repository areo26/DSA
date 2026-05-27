#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        bool isSwaped = false;
        for(int j = 0; j < arr.size() - i -1; j++) {
            if(arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
                isSwaped = true;
            } 
        }
        if(!isSwaped) {
            break;
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
    bubbleSort(vec);
    display(vec);
    return 0;
}