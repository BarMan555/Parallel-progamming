﻿#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;
using namespace chrono;

typedef std::vector<vector<double>> Matrix;
const string PATH_MATRIX1 = "C:/Users/boris/Desktop/paralel_programming/lab_1/Matrix_Multiply/matrix1.txt";
const string PATH_MATRIX2 = "C:/Users/boris/Desktop/paralel_programming/lab_1/Matrix_Multiply/matrix2.txt";
const string PATH_RESULT = "C:/Users/boris/Desktop/paralel_programming/lab_1/Matrix_Multiply/result.txt";

void read_matrix(const string& filename, Matrix& matrix) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    std::string line;
    int columns, rows;

    std::getline(file, line);
    std::istringstream size(line);
    size >> rows >> columns;

    matrix.resize(rows);
    
    // Построчное чтение
    int i = 0;
    while (std::getline(file, line)) {
        // Создание потока для разбора строки
        std::istringstream iss(line);
        double num;

        // Извлечение чисел из строки и запись в матрицу
        for(int j = 0; j < columns; j++){
            iss >> num;
            matrix[i].push_back(num);
        }
        i++;

        if (i == rows) { break; }
    }
    file.close();
}

void write_matrix(const string& filename, const Matrix& matrix, const int& rows, const int& columns, const double& time) {
    std::ofstream out_file(filename);

    if (!out_file.is_open()) {
        std::cerr << "Error creating file!" << std::endl;
        return;
    }

    out_file << "rows: " << rows << std::endl;
    out_file << "columns: " << columns << std::endl;
    out_file << "time: " << time << " ms\n\n";

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            out_file << matrix[i][j] << " ";
        }
        out_file << "\n";  // Новая строка для каждой строки матрицы
    }

    out_file.close();
}

void multiply_matrix(Matrix& result, const Matrix& matrix1, const Matrix& matrix2,
    const int rows1, const int columns1, const int columns2) {
    
    result.resize(rows1);
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < columns2; ++j) {
            double sum = 0;
            for (int k = 0; k < columns1; ++k) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i].push_back(sum);
        }
    }
}

int main() {
    Matrix matrix1;
    read_matrix(PATH_MATRIX1, matrix1);

    Matrix matrix2;
    read_matrix(PATH_MATRIX2, matrix2);

    int rows1, columns1, rows2, columns2;
    rows1 = matrix1.size();
    rows2 = matrix2.size();
    columns1 = matrix1[0].size();
    columns2 = matrix2[0].size();

    if (columns1 != rows2) {
        std::cerr << "Number columns of matrix 1 != number rows of matrix 2! Error!";
        return -1;
    }

    Matrix result;

    auto start = high_resolution_clock::now();
    multiply_matrix(result, matrix1, matrix2, rows1, columns1, columns2);
    auto end = high_resolution_clock::now();

    auto time = duration_cast<microseconds>(end - start).count();

    std::cout << "rows: " << result.size() << std::endl;
    std::cout << "columns: " << result[0].size() << std::endl;
    std::cout << "time: " << time << " ms\n\n";

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    write_matrix(PATH_RESULT, result, result.size(), result[0].size(), time);

    return 0;
}