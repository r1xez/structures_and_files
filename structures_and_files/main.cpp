#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

void generateInputFile(const std::string& filename, int count = 20) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error creating input file.\n";
        return;
    }
    std::srand(std::time(nullptr));
    for (int i = 0; i < count; ++i) {
        file << (std::rand() % 200 - 100) / 10.0 << "\n";
    }
    file.close();
}

void task1_streams(const std::string& inputFile, const std::string& negativeFile, const std::string& positiveFile) {
    std::ifstream input(inputFile);
    std::ofstream negative(negativeFile);
    std::ofstream positive(positiveFile);

    if (!input.is_open() || !negative.is_open() || !positive.is_open()) {
        std::cerr << "Error opening files for Task 1.\n";
        return;
    }

    double number;
    int negativeCount = 0, positiveCount = 0;

    while (input >> number) {
        if (number < 0) {
            negative << number << "\n";
            negativeCount++;
        }
        else if (number > 0) {
            positive << number << "\n";
            positiveCount++;
        }
    }

    negative << "Count: " << negativeCount << "\n";
    positive << "Count: " << positiveCount << "\n";
}

void task2_streams(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream input(inputFile);
    std::ofstream output(outputFile);

    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Error opening files for Task 2.\n";
        return;
    }

    double number;
    int position = 1, negativeCount = 0;

    while (input >> number) {
        if (number < 0) {
            negativeCount++;
            output << "Position: " << position << ", Value: " << number << "\n";
        }
        position++;
    }

    std::cout << "Negative numbers count: " << negativeCount << "\n";
}

void task3_streams(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream input(inputFile);
    std::ofstream output(outputFile);

    if (!input.is_open() || !output.is_open()) {
        std::cerr << "Error opening files for Task 3.\n";
        return;
    }

    std::vector<double> positives, negatives, zeros;
    double number;

    while (input >> number) {
        if (number > 0) positives.push_back(number);
        else if (number < 0) negatives.push_back(number);
        else zeros.push_back(number);
    }

    for (double num : positives) output << num << "\n";
    for (double num : zeros) output << num << "\n";
    for (double num : negatives) output << num << "\n";
}

int main() {
    std::string inputFile = "input.txt";
    std::string negativeFile = "negatives.txt";
    std::string positiveFile = "positives.txt";
    std::string positionsFile = "positions.txt";
    std::string sortedFile = "sorted_output.txt";

    generateInputFile(inputFile);

    task1_streams(inputFile, negativeFile, positiveFile);
    task2_streams(inputFile, positionsFile);
    task3_streams(inputFile, sortedFile);

    std::cout << "Tasks completed. Check the output files.\n";

    return 0;
}
