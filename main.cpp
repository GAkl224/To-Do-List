#include <iostream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class TodoList {
private:
    struct Task {
        string description;
        bool completed;

        Task(const string& desc, bool isCompleted) : description(desc), completed(isCompleted) {}
    };

    vector<Task> tasks;

public:
    void add(const string& description) {
        tasks.push_back(Task(description, false));
    }

    void complete(const string& description) {
        for (Task& task : tasks) {
            if (task.description == description) {
                task.completed = true;
                return;
            }
        }
    }

    void all() const {
        cout << "All tasks:\n";
        for (const Task& task : tasks) {
            cout << "- " << task.description << " [" << (task.completed ? "Completed" : "Incomplete") << "]\n";
        }
        cout << endl;
    }

    void complete() const {
        cout << "Completed tasks:\n";
        for (const Task& task : tasks) {
            if (task.completed) {
                cout << "- " << task.description << endl;
            }
        }
        cout << endl;
    }

    void incomplete() const {
        cout << "Incomplete tasks:\n";
        for (const Task& task : tasks) {
            if (!task.completed) {
                cout << "- " << task.description << endl;
            }
        }
        cout << endl;
    }

    void clear() {
        tasks.clear();
        cout << "All tasks cleared.\n\n";
    }
};

int main() {
    TodoList list;

    list.add("Homework");
    list.add("Walk the Dog");
    list.add("Wash and Fold laundry");
    list.add("Buy a birthday gift");

    list.complete("Homework");

    list.all();
    list.complete();
    list.incomplete();

    list.clear();

    list.all();

    return 0;
}