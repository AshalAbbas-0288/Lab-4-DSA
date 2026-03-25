#include <iostream>
#include <string>
using namespace std;

class PrintQueue {
private:
    string* arr;
    int frontIndex;
    int rearIndex;
    int capacity;
    int count;

public:
    PrintQueue(int size) {
        capacity = size;
        arr = new string[capacity];
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    void enqueue(string document_name) {
        if (isFull()) {
            cout << "Queue Full - Cannot add more print jobs" << endl;
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = document_name;
        count++;
    }

    string dequeue() {
        if (isEmpty()) {
            cout << "Queue Empty - No jobs to print" << endl;
            return "";
        }
        string doc = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return doc;
    }

    string front() const {
        if (isEmpty()) {
            cout << "Queue Empty - No jobs pending" << endl;
            return "";
        }
        return arr[frontIndex];
    }

    void display() const {
        if (isEmpty()) {
            cout << "No pending print jobs" << endl;
            return;
        }
        int i = frontIndex;
        for (int j = 0; j < count; j++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    ~PrintQueue() {
        delete[] arr;
    }
};

int main() {
    PrintQueue pq(5);
    int choice;
    string doc;

    do {
        cout << "\n1. Add Print Job" << endl;
        cout << "2. Print Document (Dequeue)" << endl;
        cout << "3. Check Front Document" << endl;
        cout << "4. Display Pending Jobs" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter document name: ";
            cin >> doc;
            pq.enqueue(doc);
            break;
        case 2:
            cout << "Printing: " << pq.dequeue() << endl;
            break;
        case 3:
            cout << "Next Document: " << pq.front() << endl;
            break;
        case 4:
            cout << "Pending Jobs: ";
            pq.display();
            break;
        }
    } while (choice != 5);

    return 0;
}
