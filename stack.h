#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate

template <typename T>
class Stack : private std::vector<T> // Private inheritance
{
public:
    Stack() = default; // Use the default constructor of std::vector

    // Check if the stack is empty
    bool empty() const {
        return std::vector<T>::empty();
    }

    // Get the size of the stack
    size_t size() const {
        return std::vector<T>::size();
    }

    // Add an item to the top of the stack
    void push(const T& item) {
        std::vector<T>::push_back(item); // Use push_back from std::vector
    }

    // Remove the top item from the stack
    void pop() {
        if (this->empty()) {
            throw std::underflow_error("Stack underflow");
        }
        std::vector<T>::pop_back(); // Use pop_back from std::vector
    }

    // Get the top item of the stack
    const T& top() const {
        if (this->empty()) {
            throw std::underflow_error("Stack underflow");
        }
        return std::vector<T>::back(); // Use back from std::vector to access the last element
    }
};


#endif