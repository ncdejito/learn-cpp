#include <iostream>
using namespace std;

template <typename T>
T findMax(T arr[], int size) {
    T maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    int intArray[] = { 5, 3, 9, 1, 7 };
    double doubleArray[] = { 3.14, 2.71, 1.618, 42.1 };

    int intMax = findMax(intArray, 5);
    double doubleMax = findMax(doubleArray, 4);

    cout << "Maximum integer value: " << intMax << endl;
    cout << "Maximum double value: " << doubleMax << endl;

    return 0;
}
