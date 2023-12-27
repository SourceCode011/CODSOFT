#include <iostream>
#include <vector>
#include <string>

// Task structure
struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

// To-Do List class
class ToDoList {
private:
    std::vector<Task> tasks;

public:
    // Function to add a task to the list
    void addTask(const std::string& description) {
        tasks.emplace_back(description);
        std::cout << "Task added successfully.\n";
    }

    // Function to view tasks
    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks in the list.\n";
        } else {
            std::cout << "Tasks:\n";
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". " << tasks[i].description << " - "
                          << (tasks[i].completed ? "Completed" : "Pending") << "\n";
            }
        }
    }

    // Function to mark a task as completed
    void markTaskAsCompleted(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < static_cast<int>(tasks.size())) {
            tasks[taskIndex].completed = true;
            std::cout << "Task marked as completed.\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }

    // Function to remove a task from the list
    void removeTask(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < static_cast<int>(tasks.size())) {
            tasks.erase(tasks.begin() + taskIndex);
            std::cout << "Task removed successfully.\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }
};

int main() {
    ToDoList toDoList;

    char choice;
    do {
        // Display menu
        std::cout << "\n===== TO-DO LIST MANAGER =====\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                {
                    std::cin.ignore(); // Clear input buffer
                    std::cout << "Enter task description: ";
                    std::string description;
                    std::getline(std::cin, description);
                    toDoList.addTask(description);
                    break;
                }
            case '2':
                toDoList.viewTasks();
                break;
            case '3':
                {
                    int taskIndex;
                    std::cout << "Enter task index to mark as completed: ";
                    std::cin >> taskIndex;
                    toDoList.markTaskAsCompleted(taskIndex - 1);
                    break;
                }
            case '4':
                {
                    int taskIndex;
                    std::cout << "Enter task index to remove: ";
                    std::cin >> taskIndex;
                    toDoList.removeTask(taskIndex - 1);
                    break;
                }
            case '5':
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }

    } while (choice != '5');

    return 0;
}
