#include <iostream>
using namespace std;

class PizzaParlorQueue {
private:
    int front, rear;
    int maxSize;
    int *queue;

public:
    // Constructor to initialize queue
    PizzaParlorQueue(int size) {
        maxSize = size;
        queue = new int[maxSize];
        front = -1;
        rear = -1;
    }

    // Destructor to free allocated memory
    ~PizzaParlorQueue() {
        delete[] queue;
    }

    // Check if the queue is full
    bool isFull() {
        return rear == maxSize - 1;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1 || front > rear;
    }

    // Add an order to the queue
    void enqueue(int order) {
        if (isFull()) {
            cout << "Queue is full. Cannot take more orders.\n";
        } else {
            if (front == -1) {
                front = 0;  // Initial order
            }
            rear++;
            queue[rear] = order;
            cout << "Order " << order << " added to the queue.\n";
        }
    }

    // Serve the first order in the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No orders to serve.\n";
        } else {
            cout << "Order " << queue[front] << " served.\n";
            front++;
        }
    }

    // Display all orders in the queue
    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
        } else {
            cout << "Current orders in the queue: ";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int maxOrders;
    cout << "**WELCOME TO YOU KAMINI PIZZA PARLAR**"<<endl;
    cout << "Enter the maximum number of orders the pizza parlor can take: ";
    cin >> maxOrders;

    PizzaParlorQueue parlor(maxOrders);

    int choice, order;
    do {
        cout << "\n--- Pizza Parlor Menu ---\n";
        cout << "1. Add Order (Enqueue)\n";
        cout << "2. Serve Order (Dequeue)\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter order number to add: ";
            cin >> order;
            parlor.enqueue(order);
            break;
        case 2:
            parlor.dequeue();
            break;
        case 3:
            parlor.displayQueue();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

   return 0;
}
