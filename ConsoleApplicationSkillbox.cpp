#include <iostream>
#include <iomanip>
#include <time.h>

int main() {
    const int N = 5;

    time_t now = time(nullptr);
    struct tm localTime;
    localtime_s(&localTime, &now);
    int T = localTime.tm_mday;

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
        sum += matrix[T % N][j];
    }

    std::cout << sum << std::endl;
    std::cout << (T % N - 1) * N + (N * (N + 1)) / 2 << std::endl; // в одну строку через формулу

    return 0;
}