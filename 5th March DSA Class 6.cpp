#include <iostream>
#include <string>
using namespace std;

class BankQueue {
private:
    string* arr;
    int frontIndex;
    int rearIndex;
    int capacity;
    int count;

public:
    BankQueue(int size) {
        capacity = size;
        arr = new string[capacity];
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    void enqueue(string customer) {
        if (isFull()) {
            cout << "Queue Full - Cannot add more customers" << endl;
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = customer;
        count++;
    }

    string dequeue() {
        if (isEmpty()) {
            cout << "Queue Empty - No customers to serve" << endl;
            return "";
        }
        string cust = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return cust;
    }

    string front() const {
        if (isEmpty()) {
            cout << "Queue Empty - No customers pending" << endl;
            return "";
        }
        return arr[frontIndex];
    }

    void display() const {
        if (isEmpty()) {
            cout << "No customers in queue" << endl;
            return;
        }
        int i = frontIndex;
        for (int j = 0; j < count; j++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }

    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == capacity; }

    ~BankQueue() { delete[] arr; }
};

int main() {
    BankQueue bq(5);
    int choice;
    string name;

    do {
        cout << "\n1. Add Customer" << endl;
        cout << "2. Serve Customer" << endl;
        cout << "3. Next Customer" << endl;
        cout << "4. Display Queue" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter customer name: ";
            cin >> name;
            bq.enqueue(name);
            break;
        case 2:
            cout << "Serving: " << bq.dequeue() << endl;
            break;
        case 3:
            cout << "Next Customer: " << bq.front() << endl;
            break;
        case 4:
            cout << "Queue: ";
            bq.display();
            break;
        }
    } while (choice != 5);

    return 0;
}
