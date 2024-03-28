#include <iostream>
#include <string>
#include <fstream>
#include <iomanip> // For using the ignore() function
using namespace std;

struct todolist {
    string task;
    int id;
};

int ID; // Ensure this variable is declared globally

// Function prototypes
void banner();
void Addtask();
void showtask();
int searchtask();
void deletetask();
void updatetask();

int main(int argc, char** argv) {
    // Your main function code...
}

void banner() {
    // Your banner function code...
}

void Addtask() {
    system("cls");
    banner();
    todolist todo;
    cout << "Enter new task:\n";
    cin.get();
    getline(cin, todo.task);
    char save, y, n;
    cout << "Save (y/n):\n";
    cin >> save;
    if (save == 'y') {
        ID++;
        ofstream fout;
        fout.open("todolist.txt");
        fout << "\n" << ID;
        fout << "\n" << todo.task;
        fout.close();
        char more;
        cout << "Add more task (y/n):\n";
        cin >> more;
        if (more == 'y') {
            Addtask();
        }
        else {
            system("cls");
            cout << "Added successfully.\n";
            return;
        }
    }
    system("cls");
}

void showtask() {
    system("cls");
    banner();
    todolist todo;
    ifstream fin;
    fin.open("todo.txt");
    cout << "Task:\n";
    while (!fin.eof()) {
        fin.ignore();
        getline(fin, todo.task);
        if (todo.task != " ") {
            cout << "\t " << todo.id << ": " << todo.task << endl;
        }
        else {
            cout << "\t Empty" << endl;
        }
    }
    fin.close();
    char exit, y, n;
    cout << "Exit (y/n):\n";
    cin >> exit;
    if (exit != 'y') {
        showtask();
    }
    system("cls");
}

int searchtask() {
    system("cls");
    banner();
    int id;
    cout << "Enter task ID:\n";
    cin >> id;
    todolist todo;
    ifstream fin("todo.txt");
    while (!fin.eof()) {
        fin >> todo.id;
        fin.ignore();
        getline(fin, todo.task);
        if (todo.id == id) {
            system("cls");
            cout << "\t" << todo.id << ": " << todo.task << endl;
            return id;
        }
    }
    system("cls");
    cout << "Not found.\n";
    return 0;
}

void deletetask() {
    system("cls");
    int id = searchtask();
    if (id != 0) {
        char del;
        cout << "\nDelete? (y/n)\n";
        cin >> del;
        if (del == 'y') {
            todolist todo;
            ofstream tempfile;
            tempfile.open("temp.txt");
            ifstream fin;
            fin.open("todo.txt");
            int index = 1;
            while (!fin.eof()) {
                fin >> todo.id;
                fin.ignore();
                getline(fin, todo.task);
                if (todo.id != id) {
                    tempfile << "\n" << index;
                    tempfile << "\n" << todo.task;
                    index++;
                    ID--;
                }
            }
            fin.close();
            tempfile.close();
            remove(todo.task.c_str());
            rename("temp.txt", "todo.txt");
            system("cls");
            cout << "Deleted successfully!\n";
        }
        else {
            system("cls");
            cout << "Not deleted.\n";
        }
    }
}

