#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;  // the data value
    Node* next;  // pointer to the next node

    // Constructor with data and next node
    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

int main() {
    int n;
    cin >> n;  // Read the number of elements

    vector<int> arr(n);

    // Read array elements from input
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Creating a new Node with the first element of the array
    Node* y = new Node(arr[0]);

    // Outputting the pointer address and value
    cout << y << '\n';         // Outputs the memory address of y
    cout << y->data << '\n';   // Outputs the value stored in y (which is arr[0])

    // Clean up dynamically allocated memory
    delete y;

    return 0;
}
