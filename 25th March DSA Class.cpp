//Ashal Abbas
//L1F24BSCS-0288

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class AbstractQueue {
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractQueue() {}
};

template <typename T>
class myQueue : public AbstractQueue<T> {
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
    myQueue<int> q(5);
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
