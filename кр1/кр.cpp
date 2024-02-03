#include <iostream>
#include <ctime>
#include <cstdio>
#include <string>

void fillArray(int** arr, int rows, int columns) { // функция заполняем массив рандомными числами
    srand(time(NULL));
    int num;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            num = rand() % (100 - 1 + 1) + 1; // случайные числа от 1 до 100
            arr[i][j] = num;
        }
    }
}

void showArray(int** arr, int rows, int columns) { // функция выводит массив на экран
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << arr[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

int sumDiagonal(int** arr, int rows, int columns) { //функция складывает числа на главной диагонали
    int sum = 0;
    for (int i = 0; i < rows && i < columns; ++i) {
        sum += arr[i][i];
    }
    return sum;
}

struct Employee {
    std::string name;
    int age;
    int employee_id;
    std::string position;
};

const int maxEmployees = 50;
Employee employees[maxEmployees];
int employeeCount = 0;

void addEmployee() {
    if (employeeCount < maxEmployees) {
        std::cout << "Enter name: ";
        std::cin >> employees[employeeCount].name;
        std::cout << "Enter age: ";
        std::cin >> employees[employeeCount].age;
        std::cout << "Enter ID: ";
        std::cin >> employees[employeeCount].employee_id;
        std::cout << "Enter position: ";
        std::cin >> employees[employeeCount].position;
        employeeCount++;
    }
    else {
        std::cout << "Adding is not possible, the limit has been reached." << std::endl;
    }
}

void deleteEmployee() {
    int targetId;
    std::cout << "Enter the ID of the employee to delete: ";
    std::cin >> targetId;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].employee_id == targetId) {
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            return;
        }
    }
    std::cout << "Employee with ID " << targetId << " does not exist." << std::endl;
}

void updateInfo() {
    int targetId;
    std::cout << "Enter the ID of the employee to update: ";
    std::cin >> targetId;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].employee_id == targetId) {
            std::cout << "Enter new name: ";
            std::cin >> employees[i].name;
            std::cout << "Enter new age: ";
            std::cin >> employees[i].position;
            std::cout << "Enter new position: ";
            std::cin >> employees[i].position;
            return;
        }
    }
    std::cout << "Employee with ID " << targetId << " does not exist." << std::endl;
}

void printAll() {
    std::cout << "Number of employees in the company:" << std::endl;
    for (int i = 0; i < employeeCount; i++) {
        std::cout << "Name: " << employees[i].name << ", Age: " << employees[i].age << ", ID: " << employees[i].employee_id << ", Position: " << employees[i].position << std::endl;
    }
}

int main() {
    std::cout << std::endl << "#Task3#" << std::endl;
    int columns(0);
    int rows(0);
    std::cout << std::endl << "Enter the number of columns: ";
    std::cin >> columns; // вводим количество столбцов
    std::cout << std::endl << std::endl << "Enter the number of rows: ";
    std::cin >> rows; // вводим количество строк
    std::cout << std::endl;
    int** array = new int* [rows]; 
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[columns]; 
    }
    fillArray(array, rows, columns); // вызываем функцию заполнения массива
    showArray(array, rows, columns); // вызываем функцию вывода массива на экран
    int sum = sumDiagonal(array, rows, columns);
    std::cout << "Sum of the elements on main diagonal: " << sum << std::endl;
    for (int i = 0; i < rows; ++i) {
        delete[] array[i]; // очищаем память
    }
    delete[] array; // очищаем память


    std::cout << std::endl << "#Task4#" << std::endl;
    void (*functionPtr[])() = { addEmployee, deleteEmployee, updateInfo, printAll};

    while (true) {
        std::cout << "Choose an action:" << std::endl;
        std::cout << "1. Add employee" << std::endl;
        std::cout << "2. Delete employee" << std::endl;
        std::cout << "3. Update information about employee" << std::endl;
        std::cout << "4. Print all employees" << std::endl;
        std::cout << "5. Exit" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 5) {
            break;
        }
        else if (choice > 0 && choice < 5) {
            (*functionPtr[choice - 1])();
        }
        else {
            std::cout << "Incorrect choice, please try again." << std::endl;
        }
    }
    return 0;
}