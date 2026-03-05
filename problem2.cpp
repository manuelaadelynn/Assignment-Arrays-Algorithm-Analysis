/*
Compilation command:
g++ -std=c++17 -Wall -Wextra problem2.cpp -o problem2
*/

#include <iostream>
#include <iomanip>

using namespace std;

struct DynArray {
    int* data;
    int size;
    int capacity;
};

void initArray(DynArray &arr, int cap) {
    arr.data = new int[cap];
    arr.size = 0;
    arr.capacity = cap;
}

void freeArray(DynArray &arr) {
    delete[] arr.data;
    arr.data = nullptr;
}

void resize(DynArray &arr) {
    int newCap = arr.capacity * 2;
    int* newData = new int[newCap];

    for(int i = 0; i < arr.size; i++)
        newData[i] = arr.data[i];

    delete[] arr.data;
    arr.data = newData;
    arr.capacity = newCap;
}

void pushBack(DynArray &arr, int val) {
    if(arr.size == arr.capacity)
        resize(arr);

    arr.data[arr.size++] = val;
}

void insertAt(DynArray &arr, int index, int val) {
    if(arr.size == arr.capacity)
        resize(arr);

    for(int i = arr.size; i > index; i--)
        arr.data[i] = arr.data[i-1];

    arr.data[index] = val;
    arr.size++;
}

void removeAt(DynArray &arr, int index) {
    for(int i = index; i < arr.size-1; i++)
        arr.data[i] = arr.data[i+1];

    arr.size--;
}

int getAt(DynArray &arr, int index) {
    return arr.data[index];
}

void setAt(DynArray &arr, int index, int val) {
    arr.data[index] = val;
}

void printTable(DynArray &arr) {

    cout << "+-------+-------+\n";
    cout << "| Index | Value |\n";
    cout << "+-------+-------+\n";

    for(int i = 0; i < arr.size; i++) {
        cout << "| "
             << setw(5) << i << " | "
             << setw(5) << arr.data[i] << " |\n";
    }

    cout << "+-------+-------+\n";
    cout << "size=" << arr.size
         << "   cap=" << arr.capacity << "\n\n";
}

int main() {

    DynArray arr;
    initArray(arr,8);

    // Step 1
    pushBack(arr,10);
    pushBack(arr,20);
    pushBack(arr,30);
    pushBack(arr,40);
    pushBack(arr,50);

    printTable(arr);

    // Step 2
    insertAt(arr,2,25);
    printTable(arr);

    // Step 3
    removeAt(arr,0);
    printTable(arr);

    // Step 4
    cout << "Element at index 2: "
         << getAt(arr,2) << "\n\n";

    // Step 5
    setAt(arr,2,99);
    printTable(arr);

    freeArray(arr);
}