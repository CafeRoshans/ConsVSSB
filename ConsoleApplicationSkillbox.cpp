#include <iostream>
#include <iomanip>

int main() {
    const int N = 5;
    const int T = 13; // у меня 14 число на момент задания

    int matrix[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = i + j;
        }
    }

    std::cout << "Matrix " << N << "x" << N << ":" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << std::setw(2) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    int sum = 0;
    for (int j = 0; j < N; j++) {
        sum += matrix[T % N - 1][j];
    }

    std::cout << sum << std::endl;

    std::cout << (T%N-2)*N+(N*(N+1))/2 << std::endl; // в одну строку через формулу

    return 0;
}