#include <iostream>
#include <vector>

using namespace std;

class Heap
{

public:
    vector<int> data;

    void insert(int value)
    {
        data.push_back(value);
        int index = data.size() - 1;

        while (index > 0)
        {
            int parentIndex = index / 2;

            if (data[parentIndex] < data[index])
            {
                swap(data[parentIndex], data[index]);
                index = parentIndex;
            }

            else
            {
                return;
            }
        }
    }

    void deletion()
    {

        swap(data[0], data[data.size() - 1]);
        data.pop_back();

        int index = 0;

        while (index < data.size())
        {

            int rightIndex = 2 * index + 1;
            int leftIndex = 2 * index;

            if (leftIndex < data.size() && data[leftIndex] > data[index] && data[leftIndex] > data[rightIndex])
            {
                swap(data[index], data[leftIndex]);
                index = leftIndex;
            }

            else if (rightIndex < data.size() && data[rightIndex] > data[index] && data[leftIndex] < data[rightIndex])
            {
                swap(data[index], data[rightIndex]);
                index = rightIndex;
            }

            else
            {
                return;
            }
        }
    }

    void print()
    {

        for (auto i : data)
            cout << i << " ";
        cout << endl;
    }
};

void heapify(int index, vector<int> &data, int size)
{

    int largest = index;
    int rightIndex = 2 * index + 2;
    int leftIndex = 2 * index + 1;

    if (leftIndex < size && data[leftIndex] > data[largest])
    {
        largest = leftIndex;
    }

    if (rightIndex < size && data[rightIndex] > data[largest])
    {
        largest = rightIndex;
    }

    if (largest != index)
    {
        swap(data[largest], data[index]);
        heapify(largest, data, size);
    }
}

void heapSort(vector<int> &arr, int n)
{

    int size = n;

    while (size)
    {

        swap(arr[0], arr[size - 1]);
        size--;

        heapify(0, arr, size);
    }
}

int main()
{

    Heap h;

    h.insert(60);
    h.insert(30);
    h.insert(50);
    h.insert(20);
    h.insert(40);
    h.print();

    /* h.deletion();
    h.print();


    for (int i = 2; i >= 0; i--)
        heapify(i, arr, 5); */

    heapSort(h.data, h.data.size());

    h.print();

    /* for (auto i : arr)
        cout << i << " ";
    cout << endl; */

    return 0;
}