#include <iostream>
class Matrix {
protected:
    char matrix[10][10];
public:
    void readMatrix() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                std::cin >> matrix[i][j];
            }
        }
    }
    void printMatrix() const {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                std::cout << matrix[i][j];
            }
            std::cout << std::endl;
        }
    }
};

class Rust : public Matrix {
public:
    void rustSpread(int rust) {
        for (int r = 0; r < rust; r++) {
            char newMatrix[10][10];
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    newMatrix[i][j] = matrix[i][j];
                }
            }
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (matrix[i][j] == '!') {
						infect(newMatrix, i - 1, j); // Up
                        infect(newMatrix, i + 1, j);
                        infect(newMatrix, i, j - 1);
                        infect(newMatrix, i, j + 1);
                    }
                }
            }
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    matrix[i][j] = newMatrix[i][j];
                }
            }
        }
    }

    void infect(char newMatrix[10][10], int row, int col) {
        if (row < 0 || row >= 10 || col < 0 || col >= 10)
            return;

        if (newMatrix[row][col] == '!' || newMatrix[row][col] == '#')
            return;

        if (newMatrix[row][col] == '.') {
            newMatrix[row][col] = '!';
        }
    }
};

int main() {
    Rust rustObj;
    rustObj.readMatrix();

    int n;
    std::cin >> n;

    rustObj.rustSpread(n);

    rustObj.printMatrix();

    return 0;
}
