#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const string File_name = "todolist.txt";

vector<string> loadTasks()
{
    vector<string> tasks;
    ifstream file(File_name);
    string line;

    while (getline(file,line))
    {
        if (!line.empty())
        {
            tasks.push_back(line);
        }
        
    }
    file.close();
    return tasks;
}

void saveTsks(const vector<string>&tasks)
{
    ofstream file(File_name);
    for (const string& task : tasks)
    {
        file << task << endl;
    }
    file.close();
}

void diplayTasks(const vector<string>&tasks)
{
    if(tasks.empty())
    {
        cout << "No tasks in the to-do list." << endl;
        return;
    }

        cout << "To-Do List:" << endl;
        for (int i = 0; i < tasks.size(); ++i)
        {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
}

void addTask(vector<string>&tasks)
{
    cout <<"enter your task : " << endl;
    string task;
    getline(cin,task); 

    if(task.empty())
    {
        cout << "Task cannot be empty." << endl;
        return;
    }
    tasks.push_back(task);
    saveTsks(tasks);
    cout << "Task added successfully." << endl;

}

void removeTask(vector<string>&tasks)
{
    if(tasks.empty())
    {
        cout << "No tasks to remove." << endl;
        return;
    }
    diplayTasks(tasks);
    cout << "Enter the number of the task to remove: ";
    int index;
    cin >> index;
    cin.ignore();

    if (index < 1 || index > tasks.size())
    {
        cout << "Invalid task number." << endl;
        return;
    }
    tasks.erase(tasks.begin() + index - 1);
    saveTsks(tasks);
    cout << "Task removed successfully." << endl;

}
void completeTask(vector<string>& tasks)
{
    if(tasks.empty())
    {
        cout << "No tasks available." << endl;
        return;
    }

    diplayTasks(tasks);

    cout << "Enter task number to mark as completed: ";

    int index;
    cin >> index;
    cin.ignore();

    if(index < 1 || index > tasks.size())
    {
        cout << "Invalid task number." << endl;
        return;
    }

    if(tasks[index - 1].find("[Done]") != string::npos)
    {
        cout << "Task already completed." << endl;
        return;
    }

    tasks[index - 1] += " [Done]";

    saveTsks(tasks);

    cout << "Task marked as completed." << endl;
}

void DisplayMenu()
{
    cout << "To-Do List Application" << endl;
    cout << "1. Display Tasks" << endl;
    cout << "2. Add Task" << endl;
    cout << "3. Remove Task" << endl;
    cout << "4. Complete Task" << endl;
    cout << "5. Exit" << endl;
}


int main()
{

    vector<string> tasks = loadTasks();
    while(true)
    {
        DisplayMenu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {        case 1:
            diplayTasks(tasks);
            break;
        case 2:
            addTask(tasks);
            break;
        case 3:
            
            removeTask(tasks);
            break;  
        case 4:
            completeTask(tasks);
            break;
        case 5:
            cout << "Exiting the application. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}