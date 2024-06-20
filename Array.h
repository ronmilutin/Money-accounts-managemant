/* Assignment C++: 2
   Author: Ido Shwartz, ID: 318732856
   Author: Ron Milutin, ID: 316389584
*/
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;


template <typename T>
class Array {
private:
    int size;
    T* elements;

public:
    Array() : size(0), elements(nullptr) {}
    ~Array() {
        delete[] elements;  // Release dynamically allocated memory
    }

    void add(T element) {
        T* newArray = new T[size + 1];  // Create a new array with increased size
        for (int i = 0; i < size; ++i) {
            newArray[i] = elements[i];  // Copy elements from the old array
        }
        newArray[size] = element; // Add the new element to the end
        size++;
        delete[] elements;  // Release the old array memory
        elements = newArray;  // Update the array pointer
    }

    T remove(int index) {
        if (index < 0 || index >= size) {
            throw(1);
        }

        T removedElement = elements[index];  // Save the element to be removed

        T* newArray = new T[size - 1];  // Create a new array with reduced size
        for (int i = 0, j = 0; i < size; ++i) {
            if (i != index) {
                newArray[j++] = elements[i];  // Copy elements, skipping the removed one
            }
        }

        delete[] elements;  // Release the old array memory
        elements = newArray;  // Update the array pointer
        --size;  // Decrease the size of the array
        return removedElement;  // Return the removed element
    }

    int getSize() const {
        return size;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw (1);
        }
        return elements[index];  // Return a reference to the element at the specified index
    }

    friend ostream& operator<<(ostream& os, const Array<T>& arr) {
        os << "[";
        for (int i = 0; i < arr.size; ++i) {
            os << arr.elements[i];
            if (i != arr.size - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }
};

#endif // ARRAY_H
