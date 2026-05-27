#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int key) {
    
    if(arr.empty()) return -1;

    int start = 0, end = (arr.size() - 1);
    
    while(start <= end) {
        int mid = start + (end-start)/2;
        if(arr[mid] == key) {
            return mid;
        } else if(key > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    return - 1;
}

int main() {
    std::vector<int> vec = {1,3,5,7,9,11};
    std::cout << binarySearch(vec, 9);
}