#include <iostream>
#include <vector>

void heapifyUp(std::vector<int>& heap,  int i) {
    while(i > 0) {
        int parent = (i-1) / 2;
        if(heap[i] < heap[parent]) {
            std::swap(heap[i], heap[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(std::vector<int>& heap,  int i, int n) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < n && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if(right < n && heap[right] < heap[smallest]) {
        smallest = right;
    }
    if(i != smallest) {
        std::swap(heap[i], heap[smallest]);
        heapifyDown(heap, smallest, n);
    }
}

void buildHeap_1(std::vector<int>& heap) {
    for(int i = 0; i < heap.size(); i++) {
        heapifyUp(heap, i);
    }
}

void buildHeap_2(std::vector<int>& heap) {
    int n = heap.size();
    for(int i = n/2-1; i >= 0; i--) {
        heapifyDown(heap, i, n);
    }
}

void display(std::vector<int>& arr) {
    for(int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec = {12,3,2,3,4,2,1,3,4,21,2};
    display(vec);
    //buildHeap_1(vec); // Time Complaxity (nlogn)
    buildHeap_2(vec); // Time Complaxity (n)
    display(vec);
}