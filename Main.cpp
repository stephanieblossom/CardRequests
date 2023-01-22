// CPP code to illustrate Queue in 
// Standard Template Library (STL)
#include <string>
#include <fstream>
#include <iostream>
#include <queue>
using namespace std;

class Officer {
public:
    string position;
    double date;
    double amount;
    double time;
};

// Print the queue
void showq(queue<Officer> x){
    queue<Officer> g = x;
    while (!g.empty()) {
        cout << '\t' << g.front().date;
        g.pop();
    }
    cout << '\n';
}





int minIndex(queue<Officer>& q, int sortedIndex)
{
    int min_index = -1;
    int min_val = INT_MAX;
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
        Officer curr = q.front();
        q.pop();  // This is dequeue() in C++ STL

        // we add the condition i <= sortedIndex
        // because we don't want to traverse
        // on the sorted part of the queue,
        // which is the right part.
        if (curr.date <= min_val && i <= sortedIndex)
        {
            min_index = i;
            min_val = curr.date;
        }
        q.push(curr);
    }
    return min_index;
}

// Moves given minimum element to rear of 
// queue
void insertMinToRear(queue<Officer>& q, int min_index)
{
    Officer min_val;
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
        Officer curr = q.front();
        q.pop();
        if (i != min_index)
            q.push(curr);
        else
            min_val = curr;
    }
    q.push(min_val);
}

void sortQueue(queue<Officer>& q)
{
    for (int i = 1; i <= q.size(); i++)
    {
        int min_index = minIndex(q, q.size() - i);
        insertMinToRear(q, min_index);
    }
}

int main(){
    queue<Officer> requests;//initialize the queue and object attributes
    double date;
    string position{};
    double amount;
    double time;

    // Create and open a text file
    ofstream MyFile("queue.txt");

    // Write to the file
    MyFile << "Files can be tricky, but it is fun enough!";

    // Close the file
    MyFile.close();


    int flag = 0;
    while (flag == 0) {
        cout << "  REQUEST QUEUE　\n\n";
        cout << "Option 1: Print queue\n";
        cout << "Option 2: Add to queue\n";
        cout << "Option 3: Remove most recent\n";
        cout << "Option 4: exit?\n";
        int option;
        cin >> option;

        if (option == 1) {
            cout << "The queue of requests is : ";
            showq(requests);

            cout << "size: " << requests.size();
            cout << "next person : " << requests.front().position;
            cout << "last person) : " << requests.back().position;
        }


        if (option == 2) {
            cout << "When does the officer need the card?\n";
            cin >> date;
            cout << "What is the officer's position?\n";
            cin >> position;
            cout << "What is the amount?\n";
            cin >> amount;
            cout << "Pickup time:\n";
            cin >> time;


            Officer obj1;
            obj1.date = date;
            obj1.amount = amount;
            obj1.position = position;
            obj1.time = time;

            requests.push(obj1);
            sortQueue(requests);
    }
        if (option == 4) {
            MyFile << requests; //fucking idk lol

            cout << "\nrequests.pop() : ";
            requests.pop();
            showq(requests);
            flag = 1;
            return 0;
        }
    }
}