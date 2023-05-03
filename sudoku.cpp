#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <cstdio>

#define N 9

using namespace std;

class Sudoku {
public:
    int grid[N][N];
    bool ktra = false;
    //kiem tra so trung trong cot
    bool checkCol(int col, int num) {
        for (int row = 0; row < N; row++)
            if (grid[row][col] == num)
                return true;
        return false;
    }

    //kiem tran so co trung trong hang
    bool checkRow(int row, int num) {
        for (int col = 0; col < N; col++)
            if (grid[row][col] == num)
                return true;
        return false;
    }
    // kiem tra so co trung trong mang con 3x3
    bool checkBox(int boxStartRow, int boxStartCol, int num) {
        for (int row = 0; row < 3; row++)
            for (int col = 0; col < 3; col++)
                if (grid[row + boxStartRow][col + boxStartCol] == num)
                    return true;
        return false;
    }
    //kiem tra so co trung trong hang, cot va mang con 3x3
    bool checkAll(int row, int col, int num) {
        return !checkRow(row, num) && !checkCol(col, num) && !checkBox(row - row % 3,
            col - col % 3, num);
    }
    // nhap tu ban phim
    void sudokuInput() { // nhap tu ban phim
        cout << "nhap:\n";
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                cout << "grid[" << row << "][" << col << "] :";
                cin >> grid[row][col];
            }
        }
        ktra = true;
    }
    // in ra ket qua
    void sudokuGrid() {
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                if (col == 3 || col == 6)
                    cout << " | ";
                cout << grid[row][col] << " ";
            }
            if (row == 2 || row == 5) {
                cout << endl;
                for (int i = 0; i < N; i++)
                    cout << "---";
            }
            cout << endl;
        }
    }
    // tim vi tri trong
    bool findEmptyPlace(int& row, int& col) {
        for (row = 0; row < N; row++)
            for (col = 0; col < N; col++)
                if (grid[row][col] == 0)
                    return true;
        return false;
    }

    bool solveSudoku() {
        int row, col;
        if (!findEmptyPlace(row, col))
            return true; //khi tat ca dc dien
        for (int num = 1; num <= 9; num++) {  //so hop le nam trong khoang 1-9
            if (checkAll(row, col, num)) { //kiem tra so co trung trong hang, cot va mang 3x3

                grid[row][col] = num;

                if (solveSudoku()) //de quy
                    return true;

                grid[row][col] = 0; // khi khong co dieu kien nao thoa gan =0
            }
        }
        return false;
    }
};

class Menu {
private:
    Sudoku sudoku;
public:
    void sudoku_NhapNhanh() {
        int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
        };
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                sudoku.grid[row][col] = grid[row][col];
            }
        }
        cout << "da nhap xong:\n";
        sudoku.sudokuGrid();
        sudoku.ktra = true;
    }
    void sudokuOut_Solve() {
        if (sudoku.ktra) {
            cout << "ket qua:\n";
            if (sudoku.solveSudoku() == true)
                sudoku.sudokuGrid();
            else
                cout << "Khong giai duoc!!";
        }
        else {
            sudoku_NhapNhanh();
            cout << "nhan phim bat ky de xem ket qua:\n";
            system("pause");
            if (sudoku.solveSudoku() == true)
                sudoku.sudokuGrid();
            else
                cout << "Khong giai duoc!!";
        }
    }
    void inMenu()
    {
        int Kytu;
        do {
            system("cls");
            system("color f0");
            cout << "1. Nhap sudoku tu ban phim\n";
            cout << "2. Nhap nhanh sudoku\n";
            cout << "3. In ket qua sudoku\n";
            cout << "9. Thoat \n";
            cout << "Bam phim chuc nang:\t";
            cin >> Kytu;
            switch (Kytu) {
            case 1:sudoku.sudokuInput(); sudoku.sudokuGrid(); break;
            case 2:sudoku_NhapNhanh(); system("pause"); break;
            case 3:sudokuOut_Solve(); system("pause"); break;
            }
        } while (Kytu != 9);
    }
};

int main() {
    Menu menu;
    menu.inMenu();
    return 0;
}