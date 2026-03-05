/*
Compilation command:
g++ -std=c++17 -Wall -Wextra problem3.cpp -o problem3
*/

#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

int linearSearch(const int arr[], int n, int target) { // O(n)
    for (int i = 0; i < n; i++)
        if (arr[i] == target)
            return i;
    return -1;
}

int binarySearch(const int arr[], int n, int target) { // O(log n)
    int lo = 0, hi = n - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    return -1;
}

int* generateSortedArray(int n) {
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
        arr[i] = i * 2; // 0,2,4,...

    return arr;
}

void printHeader() {

    cout << "\nSearch Comparison (Linear vs Binary)\n";

    cout << "+-------+-------------+--------+-------------+-------------+---------+\n";
    cout << "| Size  | Scenario    | Target | Linear idx  | Binary idx  | Agree?  |\n";
    cout << "+-------+-------------+--------+-------------+-------------+---------+\n";
}

void printRow(int n, const string& scenario, int target, int lin, int bin) {

    cout << "| "
         << setw(5) << n << " | "
         << setw(11) << scenario << " | "
         << setw(6) << target << " | "
         << setw(11) << lin << " | "
         << setw(11) << bin << " | "
         << setw(7) << (lin == bin ? "YES" : "NO") << " |\n";
}

void printFooter() {
    cout << "+-------+-------------+--------+-------------+-------------+---------+\n";
}

int main() {

    printHeader();

    int sizes[] = {10,100,1000};

    for (int n : sizes) {

        int* arr = generateSortedArray(n);

        // Scenario 1: target exists
        int target1 = arr[n/2];
        int lin1 = linearSearch(arr,n,target1);
        int bin1 = binarySearch(arr,n,target1);

        printRow(n,"FOUND",target1,lin1,bin1);
        assert(lin1 == bin1);

        // Scenario 2: target not found
        int target2 = -1;
        int lin2 = linearSearch(arr,n,target2);
        int bin2 = binarySearch(arr,n,target2);

        printRow(n,"NOT FOUND",target2,lin2,bin2);
        assert(lin2 == bin2);

        delete[] arr;
    }

    printFooter();

    return 0;
}