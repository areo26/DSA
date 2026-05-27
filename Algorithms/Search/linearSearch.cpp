#include <iostream>
#include <vector>

int linearSearch(std::vector<int>& arr, int key) {
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::vector<int> vec = {1,9,8,7,4,3,2,5};
    std::cout << linearSearch(vec, 7);
}