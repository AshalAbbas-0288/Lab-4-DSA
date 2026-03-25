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

    void reverseFirstK(int k) {
        if (k <= 1 || k > count) return;
        T* temp = new T[k];
        for (int i = 0; i < k; i++) {
            temp[i] = deQueue();
        }
        for (int i = k - 1; i >= 0; i--) {
            enQueue(temp[i]);
        }
        int remaining = count - k;
        for (int i = 0; i < remaining; i++) {
            enQueue(deQueue());
        }
        delete[] temp;
    }

    ~myQueue() {
        delete[] arr;
    }
};

int main() {
    int n, k, value;
    cout << "Enter size of queue:" << endl;
    cin >> n;
    myQueue<int> q(n);
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enQueue(value);
    }
    cout << "Enter K:" << endl;
    cin >> k;
    q.reverseFirstK(k);
    cout << "Queue after reversing first K elements:" << endl;
    q.display();
    return 0;
}
