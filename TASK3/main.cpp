#include <locale>
#include "../Solver/RandomGenerator.h"
#include "../Solver/IStreamGeneretor.h"
#include "../Solver/MyExercise.h"


int main() {
    setlocale(LC_ALL, "RU");

    RUT::RandomGenerator<int> intGen(-100, 100);
    RUT::MyExercise<int> intExercise(3, 3, intGen);

    std::cout << "Матрица с случайными значениями (int):\n";
    intExercise.fillMatrix();
    intExercise.printMatrix();

    std::cout << "\nПосле Task1 (замена максимального по модулю элемента на противоположный):\n";
    intExercise.Task1();
    intExercise.printMatrix();

    std::cout << "\nПосле Task2 (вставка первой строки после каждой чётной строки):\n";
    intExercise.Task2();
    intExercise.printMatrix();

    std::cout << "\nВведите значения для матрицы 2x2 (double):\n";
    RUT::IStreamGenerator<double> userInputGen;
    RUT::MyExercise<double> doubleExercise(2, 2, userInputGen);

    doubleExercise.fillMatrix();
    std::cout << "Матрица, введённая пользователем:\n";
    doubleExercise.printMatrix();

    return 0;
}