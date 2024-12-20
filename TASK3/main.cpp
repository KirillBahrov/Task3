#include <iostream>
#include <string>
#include "../Solver/Matrix.h"
#include "../Solver/Exercise.h"
#include "../Solver/MyExercise.h"
#include "../Solver/IStreamGeneretor.h"
#include "../Solver/RandomGenerator.h"

using namespace RUT;

void runExercise(int rows, int cols, const std::string& dataType, const std::string& inputMethod) {
    if (dataType == "int") {
        if (inputMethod == "random") {
            RandomGenerator<int> gen(-100, 100);
            MyExercise<int> exercise(rows, cols, gen);

            exercise.matrix->fillMatrix(&gen);

            std::cout << "Исходная матрица:\n";
            exercise.printMatrix();

            exercise.Task1();
            std::cout << "\nМатрица после задания 1:\n";
            exercise.printMatrix();

            exercise.Task2();
            std::cout << "\nМатрица после задания 2:\n";
            exercise.printMatrix();
        }
        else if (inputMethod == "manual") {
            IStreamGenerator<int> gen(std::cin);
            MyExercise<int> exercise(rows, cols, gen);

            std::cout << "Введите элементы матрицы по строкам:\n";
            exercise.matrix->fillMatrix(&gen);

            std::cout << "Исходная матрица:\n";
            exercise.printMatrix();

            exercise.Task1();
            std::cout << "\nМатрица после задания 1:\n";
            exercise.printMatrix();

            exercise.Task2();
            std::cout << "\nМатрица после задания 2:\n";
            exercise.printMatrix();
        }
        else {
            std::cout << "Неподдерживаемый способ ввода.\n";
        }
    }
    else if (dataType == "double") {
        if (inputMethod == "random") {
            RandomGenerator<double> gen(-100.0, 100.0);
            MyExercise<double> exercise(rows, cols, gen);

            exercise.matrix->fillMatrix(&gen);

            std::cout << "Исходная матрица:\n";
            exercise.printMatrix();

            exercise.Task1();
            std::cout << "\nМатрица после задания 1:\n";
            exercise.printMatrix();

            exercise.Task2();
            std::cout << "\nМатрица после задания 2:\n";
            exercise.printMatrix();
        }
        else if (inputMethod == "manual") {
            IStreamGenerator<double> gen(std::cin);
            MyExercise<double> exercise(rows, cols, gen);

            std::cout << "Введите элементы матрицы по строкам:\n";
            exercise.matrix->fillMatrix(&gen);

            std::cout << "Исходная матрица:\n";
            exercise.printMatrix();

            exercise.Task1();
            std::cout << "\nМатрица после задания 1:\n";
            exercise.printMatrix();

            exercise.Task2();
            std::cout << "\nМатрица после задания 2:\n";
            exercise.printMatrix();
        }
        else {
            std::cout << "Неподдерживаемый способ ввода.\n";
        }
    }
    else {
        std::cout << "Неподдерживаемый тип данных.\n";
    }
}

int main() {
    int rows, cols;
    std::string dataType, inputMethod;

    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;
    std::cout << "Введите тип данных (int, double): ";
    std::cin >> dataType;
    std::cout << "Введите способ ввода матрицы (random, manual): ";
    std::cin >> inputMethod;

    
    runExercise(rows, cols, dataType, inputMethod);
    

    return 0;
}