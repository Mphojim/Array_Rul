#include <iostream>

const int ARRAY_SIZE = 100;
const int NUM_GENERATIONS = 50;
const char BLOCK = 219;
void printArray(int* Arr) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if(Arr[i]==0)
        {
            std::cout << " ";
        }
        else
        {
            std::cout << BLOCK;
        }

    }
    std::cout << std::endl;
}

int main() {
    int current[ARRAY_SIZE] = {0};
    int next[ARRAY_SIZE] = {0};


    // Initialize the first generation with a single cell in the middle
    current[ARRAY_SIZE / 2] = 1;

    // Print the first generation
    printArray(current);

    // Generate the next 50 generations
    for (int gen = 1; gen <= NUM_GENERATIONS; gen++) {
        // Compute the next generation using the Rule 30 rule
        for (int i = 1; i < ARRAY_SIZE - 1; i++) {
            int left = current[i - 1];
            int center = current[i];
            int right = current[i + 1];
            next[i] = left ^ (center | right);
        }

        // Copy the next generation to the current array
        for (int i = 0; i < ARRAY_SIZE; i++) {
            current[i] = next[i];
        }

        // Print the current generation
        printArray(current);
    }

    return 0;
}
