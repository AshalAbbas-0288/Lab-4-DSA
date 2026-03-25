//Ashal Abbas
//L1F24BSCS-0288
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class myQueue {
private:
    T* arr;
    int frontIndex;
    int rearIndex;
    int capacity;
    int count;

public:
    myQueue(int size) {
        capacity = size;
        arr = new T[capacity];
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    void enQueue(T value) {
        if (isFull()) return;
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = value;
        count++;
    }

    T deQueue() {
        if (isEmpty()) return T();
        T item = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return item;
    }

    T front() const {
        if (isEmpty()) return T();
        return arr[frontIndex];
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    void display() const {
        if (isEmpty()) return;
        int i = frontIndex;
        for (int j = 0; j < count; j++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }

    ~myQueue() {
        delete[] arr;
    }
};

int main() {
    myQueue<int> tickets(10);
    int choice, id;
    do {
        cout << "1. Add Ticket" << endl;
        cout << "2. Resolve Ticket" << endl;
        cout << "3. Next Ticket" << endl;
        cout << "4. Display Tickets" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter 4-digit Ticket ID:" << endl;
            cin >> id;
            tickets.enQueue(id);
            break;
        case 2:
            cout << "Resolved Ticket: " << tickets.deQueue() << endl;
            break;
        case 3:
            cout << "Next Ticket: " << tickets.front() << endl;
            break;
        case 4:
            cout << "Pending Tickets: ";
            tickets.display();
            break;
        }
    } while (choice != 5);

    return 0;
}
