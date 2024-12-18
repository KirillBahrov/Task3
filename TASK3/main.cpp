#include <locale>
#include "../Solver/RandomGenerator.h"
#include "../Solver/IStreamGeneretor.h"
#include "../Solver/MyExercise.h"
#include "../Solver/Matrix.h"


int main() {
    setlocale(LC_ALL, "RU");

    RUT::RandomGenerator<int> intGen(-100, 100);
    RUT::MyExercise<int> intExercise(3, 3, intGen);

    size_t rows, cols;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of cols: ";
    std::cin >> cols;


    int fillMethod = 0;
    std::cout << "Choose the way to fill in the matrix:\n1. Random filling\n2. Keyboard input\n";
    std::cin >> fillMethod;

    Generator* generator = nullptr;
    Matrix<int> matrix(rows, cols);

    std::cout << "Исходная матрица:\n" << matrix.ToString();

    Task1<int> task1(rows, cols, *gen);
    *task1.getMatrix() = matrix;
    task1.solve();
    std::cout << "After Task1:\n" << task1.getMatrix()->ToString();

    Task2<int> task2(rows, cols, *gen);
    *task2.getMatrix() = *task1.getMatrix();
    task2.solve();
    std::cout << "After Task2:\n" << task2.getMatrix()->ToString();

    delete gen;
    return 0;
}
