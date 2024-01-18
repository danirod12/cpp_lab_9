#include <iostream>
#include <iomanip>

template<typename T, typename K>
K *cast(const T *array, size_t size) {
    K *newArray = new K[size];
    for (int i = 0; i < size; ++i) {
        newArray[i] = static_cast<K>(array[i]);
    }
    return newArray;
}

template<typename T>
void print(const T *array, size_t size) {
    for (int i = 0; i < size; ++i) {
        if (i > 0) {
            std::cout << "\t";
        }
        std::cout << array[i];
    }
}

int main() {
    // Init array of int
    int* ints = new int[] {1, 2, 3, 4, 5, 6};
    int size = 6;

    // Cast to double
    double* doubles = cast<int, double>(ints, size);
    // Increment first double number as an example
    doubles[0] += 0.33;

    // Cast back from doubles to ints
    int* ints2 = cast<double, int>(doubles, size);

    // Demonstrate how it works using custom print function
    std::cout << std::setprecision(10);
    print(doubles, size);
    std::cout << std::endl;
    print(ints2, size);
    return 0;
}
