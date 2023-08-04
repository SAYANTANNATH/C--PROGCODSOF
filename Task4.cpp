#include <iostream>
#include <vector>
using namespace std;

struct Task {
    string description;
    bool completed;
    Task(const string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& desc) { tasks.push_back(Task(desc)); }
    void viewTasks() {
        if (tasks.empty()) cout << "No tasks in the list." << endl;
        else for (size_t i = 0; i < tasks.size(); ++i)
            cout << i + 1 << ". " << (tasks[i].completed ? "[X] " : "[ ] ") << tasks[i].description << endl;
    }
    void markCompleted(int index) { tasks[index].completed = true; }
    void removeTask(int index) { tasks.erase(tasks.begin() + index); }
};

int main() {
    ToDoList todoList;
    char choice;
    cout << "Welcome to the To-Do List Manager!" << endl;
    while (true) {
        cout << "\nMenu:\n1. Add Task\n2. View Tasks\n3. Mark Completed\n4. Remove Task\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case '1': { cout << "Enter task description: "; string desc; cin.ignore(); getline(cin, desc); todoList.addTask(desc); } break;
            case '2': todoList.viewTasks(); break;
            case '3': { int index; cout << "Enter task index to mark as completed: "; cin >> index; todoList.markCompleted(index - 1); } break;
            case '4': { int index; cout << "Enter task index to remove: "; cin >> index; todoList.removeTask(index - 1); } break;
            case '5': cout << "Goodbye!" << endl; return 0;
            default: cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}