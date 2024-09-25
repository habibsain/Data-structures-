//priority queue using vector

/*
Inputs: a sequence of numbers to be inserted into the priority queue

return: the minimum value everytime

Using following operations:
1. define heap using vector
2. insert into heap
3. heapify op
4. extract min
*/

#include<iostream>
#include<vector>
using namespace std;

//swap function
void swap(vector<int> & heap, int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

//heapify function
void heapify(vector<int> & heap, int i) {

    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < heap.size() && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < heap.size() && heap[right] < heap[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(heap, i, smallest);
        heapify(heap, smallest);
    }
}

//insert function
void insert(vector<int> & heap, int value) {
    if (heap.size() == 0) {
        heap.push_back(value);
        return;
    }
    heap.push_back(value);
    int i = heap.size() - 1;
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap, i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

//extract min
int extractMin(vector<int> & heap) {
    int min = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapify(heap, 0);
    return min;
}


int main(){

    vector<int> heap;
    
    insert(heap, 5);
    insert(heap, 3);
    insert(heap, 8);
    insert(heap, 2);
    insert(heap, 4);
    insert(heap, 6);
    insert(heap, 9);
    insert(heap, 7);

    while(heap.size() != 0) {
        cout << extractMin(heap) << " ";
    }


    return 0;
}