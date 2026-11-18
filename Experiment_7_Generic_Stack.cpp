// Experiment 7: Generic Stack using C++ Templates
// Tests the stack with int, float, and std::string.

#include <iostream>
#include <string>

template <typename T>
class Stack {
private:
    static constexpr int CAPACITY = 10;
    T arr[CAPACITY];
    int top;

public:
    Stack() : top(-1) {}

    bool push(const T& value) {
        if (top >= CAPACITY - 1) {
            std::cout << "Stack overflow! Cannot push more elements.\n";
            return false;
        }

        arr[++top] = value;
        return true;
    }

    bool pop(T& value) {
        if (top < 0) {
            std::cout << "Stack underflow! The stack is empty.\n";
            return false;
        }

        value = arr[top--];
        return true;
    }

    bool isEmpty() const {
        return top == -1;
    }
};

int main() {
    Stack<int> s1;
    s1.push(10);

    int intValue;
    if (s1.pop(intValue)) {
        std::cout << "Int: " << intValue << '\n';
    }

    Stack<float> s2;
    s2.push(5.5f);

    float floatValue;
    if (s2.pop(floatValue)) {
        std::cout << "Float: " << floatValue << '\n';
    }

    Stack<std::string> s3;
    s3.push("Hello");

    std::string stringValue;
    if (s3.pop(stringValue)) {
        std::cout << "String: " << stringValue << '\n';
    }

    return 0;
}
