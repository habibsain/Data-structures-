//merge sort

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right) {
    //cout << "Merging " << left << " to " << mid << " and " << mid + 1 << " to " << right << endl;
    //temp.reserve(right - left + 1); 
    int i = left, j = mid +1, k = left;
    while (i <= mid && j <= right) {
        //cout << "i = " << i << ", j = " << j << ", k = " << k << endl;

        if (arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        //cout << "i = " << i << ", k = " << k << endl;
        temp[k++] = arr[i++];
    }
    while (j <= right){
        //cout << "j = " << j << ", k = " << k << endl;

        temp[k++] = arr[j++];
    }

    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(vector<int> &arr, vector<int> &temp, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

void mergeSort(vector<int> &arr) {
    int n = arr.size();
    vector<int> temp(n);
    mergeSort(arr, temp, 0, n - 1);
}





int main(){
    vector<int> new_arr{2, 5, 1, 4, 10, 15, 0, 9, 7, 3, 8, 6};
    int n = new_arr.size();
    mergeSort(new_arr);
    int i = 0;
    while(i < n){
        cout << new_arr[i++] << " ";
    }
    cout << endl;

}