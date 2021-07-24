// 1.7 Rotate Matrix
// Brute Force

// Q: Given an image represented by an N x N matrix, where each pixel in the image is represented by an integer,
// write a method to rotate the image by 90 degrees.

// Assuming the string has only upper and lowercase letters (a-z)
#include <iostream>
#include <array>
#include <stdlib.h>

int** makeMatrix(int size) {
    int** matrix = new int*[size];
    for(int i = 0; i < size; ++i) {
        matrix[i] = new int[size];
    }
    return matrix;
}

// O(
int** rotateMatrix(int** matrix, int size) {
    
    int** rotatedMatrix = makeMatrix(size);

    for (int col = 0; col < size; ++col) {
        for (int row = 0; row < size; ++row) {
            rotatedMatrix[col][size-row-1] = matrix[row][col];
        }
    }
    return rotatedMatrix;
}

void printMatrix(int** matrix, int size) {

    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            std::cout << matrix[row][col] << " ";
        }
        std::cout << "" << std::endl;
    }
}

void deleteMatrix(int** matrix) {


}

void tests() {
    int size = 4;
    int** testMatrix = makeMatrix(size);
    for (int col = 0; col < size; ++col) {
        for (int row = 0; row < size; ++row) {
            testMatrix[row][col] = rand() % 9;
        }
    }
    printMatrix(testMatrix, size);
    testMatrix = rotateMatrix(testMatrix, size);
    std::cout << "" << std::endl;
    printMatrix(testMatrix, size);

}




int main() {
    tests();
    return 0;
}