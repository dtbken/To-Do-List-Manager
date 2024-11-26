#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 

struct Task {
    std::string description;
    bool is_done;

    Task(const std::string& desc) : description(desc), is_done(false) {}
};

void clearConsole() {
#if defined(_WIN32) || defined(_WIN64)
    system("cls"); // For Windows
#else
    system("clear"); // For Linux/Mac
#endif
}

void displayTasks(const std::vector<Task>& tasks) {
    std::cout << "\n--- To-Do List ---\n";
    if (tasks.empty()) {
        std::cout << "No tasks available!\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].description
            << " [" << (tasks[i].is_done ? "Done" : "Not Done") << "]\n";
    }
}

void addTask(std::vector<Task>& tasks) {
    clearConsole();
    std::cout << "Enter task description: ";
    std::string description;
    std::cin.ignore();
    std::getline(std::cin, description);

    tasks.emplace_back(description);
    std::cout << "Task added successfully!\n";
}

void markTaskDone(std::vector<Task>& tasks) {
    clearConsole();
    displayTasks(tasks);

    std::cout << "Enter the task number to mark as done: ";
    size_t task_num;
    std::cin >> task_num;

    if (task_num == 0 || task_num > tasks.size()) {
        std::cout << "Invalid task number!\n";
        return;
    }

    tasks[task_num - 1].is_done = true;
    std::cout << "Task marked as done.\n";
}

void deleteTask(std::vector<Task>& tasks) {
    clearConsole();
    displayTasks(tasks);

    std::cout << "Enter the task number to delete: ";
    size_t task_num;
    std::cin >> task_num;

    if (task_num == 0 || task_num > tasks.size()) {
        std::cout << "Invalid task number!\n";
        return;
    }

    tasks.erase(tasks.begin() + task_num - 1);
    std::cout << "Task deleted successfully.\n";
}

int main() {
    std::vector<Task> tasks;
    int choice;

    do {
        clearConsole();
        std::cout << "--- To-Do List Manager ---\n";
        std::cout << "1. View Tasks\n";
        std::cout << "2. Add Task\n";
        std::cout << "3. Mark Task as Done\n";
        std::cout << "4. Delete Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        clearConsole();
        switch (choice) {
        case 1:
            displayTasks(tasks);
            break;
        case 2:
            addTask(tasks);
            break;
        case 3:
            markTaskDone(tasks);
            break;
        case 4:
            deleteTask(tasks);
            break;
        case 5:
            std::cout << "Goodbye!\n";
            break;
        default:
            std::cout << "Invalid option! Try again.\n";
        }

        std::cout << "\nPress Enter to continue...";
        std::cin.ignore();
        std::cin.get();

    } while (choice != 5);

    return 0;
}
