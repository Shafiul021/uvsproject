#include <bits/stdc++.h>
using namespace std;

class Task {
private:
    string title;
    string description;
    string dueDate;
    bool completed;

public:
    Task(string _title, string _description, string _dueDate)
        : title(_title), description(_description), dueDate(_dueDate), completed(false) {
    }

    string getTitle() {
        return title;
    }

    string getDescription() {
        return description;
    }

    string getDueDate() {
        return dueDate;
    }

    bool isCompleted() {
        return completed;
    }

    void markAsCompleted() {
        completed = true;
    }

    void displayTask() {
        cout << "\nTitle: " << title << endl;
        cout << "Description: " << description << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "Status: " << (completed ? "Completed" : "Not Completed") << endl;
    }
};

class TaskTracker {
private:
    vector<Task> tasks;

public:
    void addTask(Task task) {
        tasks.push_back(task);
    }

    void displayAllTasks() {
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << "Task " << i + 1 << endl;
            tasks[i].displayTask();
            cout << endl;
        }
    }

    void markTaskAsCompleted(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            tasks[taskIndex].markAsCompleted();
            cout << "Task marked as completed." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

int main() {
    TaskTracker tracker;

    while (true) {
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, description, dueDate;
                cout << "\nEnter title: ";
                cin >> title;
                cout << "Enter description: ";
                cin >> description;
                cout << "Enter due date: ";
                cin >> dueDate;

                Task newTask(title, description, dueDate);
                tracker.addTask(newTask);
                cout << "Task added successfully." << endl;
                break;
            }
            case 2:
                tracker.displayAllTasks();
                break;
            case 3: {
                int index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                tracker.markTaskAsCompleted(index);
                break;
            }
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please select again." << endl;
        }
    }
}
