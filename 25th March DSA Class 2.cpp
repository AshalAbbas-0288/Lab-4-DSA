//Ashal Abbas
// L1F24BSCS-0288

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class myQueue {
private:
    T* stack1;
    T* stack2;
    int top1, top2;
    int capacity;

public:
    myQueue(int size) {
        capacity = size;
        stack1 = new T[capacity];
        stack2 = new T[capacity];
        top1 = -1;
        top2 = -1;
    }

    void enQueue(T value) {
        if (top1 == capacity - 1) return;
        stack1[++top1] = value;
    }

    T deQueue() {
        if (isEmpty()) return T();
        if (top2 == -1) {
            while (top1 >= 0) {
                stack2[++top2] = stack1[top1--];
            }
        }
        return stack2[top2--];
    }

    T front() {
        if (isEmpty()) return T();
        if (top2 == -1) {
            while (top1 >= 0) {
                stack2[++top2] = stack1[top1--];
            }
        }
        return stack2[top2];
    }

    bool isEmpty() {
        return (top1 == -1 && top2 == -1);
    }

    void display() {
        if (isEmpty()) return;
        if (top2 == -1) {
            for (int i = 0; i <= top1; i++) {
                cout << stack1[i] << " ";
            }
        }
        else {
            for (int i = top2; i >= 0; i--) {
                cout << stack2[i] << " ";
            }
            for (int i = 0; i <= top1; i++) {
                cout << stack1[i] << " ";
            }
        }
        cout << endl;
    }

    ~myQueue() {
        delete[] stack1;
        delete[] stack2;
    }
};

int main() {
    myQueue<int> q(10);
    int choice, value;
    do {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cin >> value;
            q.enQueue(value);
            break;
        case 2:
            cout << q.deQueue() << endl;
            break;
        case 3:
            cout << q.front() << endl;
            break;
        case 4:
            q.display();
            break;
        }
    } while (choice != 5);
    return 0;
}
