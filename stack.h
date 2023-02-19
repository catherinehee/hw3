#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>


// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
    private:
        std::vector<T> data;
};

template<typename T>
Stack<T>::Stack()
{

}

template<typename T>
Stack<T>::~Stack()
{

}

template<typename T>
size_t Stack<T>::size() const
{
    return data.size();
}

template<typename T>
bool Stack<T>::empty() const
{
    return (data.size() == 0);
}

template<typename T>
void Stack<T>::push(const T& item)
{
    data.push_back(item);
}

template<typename T>
void Stack<T>::pop()
{
    if (Stack<T>::size() == 0)
        throw std::underflow_error("underflow_error");
    data.pop_back();
    
}

template<typename T>
T const & Stack<T>::top() const
{
    size_t curr_size = Stack<T>::size();
    if (curr_size == 0)
        throw std::underflow_error("underflow_error");
    return data[curr_size-1];
}

#endif