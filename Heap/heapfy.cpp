#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//  function for heapify  (this follow the top-bottom approch)
void heapify(vector<int> &arr, int index, int size)
{
    // assuming the largest number is in the index
    int largest = index;

    // we need to compare it with its leaf child and the right child so that any number having high vakue in the leaf will be bougth up
    // left child index of the node
    int left = 2 * index + 1;

    // right child index of the node
    int right = 2 * index + 2;

    // check if the left child is in the range and is the left child greater that the current node
    if (left < size && arr[left] > arr[index])
    {
        largest = left;
    }

    // check if the right child is in the range and is the right child greater that the current node
    if (right < size && arr[right] > arr[index])
    {
        largest = right;
    }

    //  swap anly if the index which we thought would be greater is not equal to actuly index containing the greater element
    if (largest != index)
    {

        swap(arr[index], arr[largest]);
        //  further again heapify the largest to check if the nodes below doesnt have the largest number
        heapify(arr, largest, size);
    }
}

//  function for the max heap
void buildMaxHeap(vector<int> &arr)
{
    int n = arr.size();

    // start from the last non leaf node (i.e non leaf meaning node that has children)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        // place the node at it's correct's place by using heapify process
        heapify(arr, i, n);
    }
}

int main()
{
    vector<int> arr = {20, 30, 16, 8, 50};
    cout << "Original Array: ";
    for (int num : arr)
        cout << num << " ";

    buildMaxHeap(arr);
    cout << "\nMax Heap: ";
    for (int num : arr)
        cout << num << " ";
}