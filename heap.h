#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

#include <vector>
#include <iostream>
template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

  int m;
  PComparator c;
  std::vector<T> data;

};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
{
  this -> m = m;
  this -> c = c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{
}



// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================

    throw std::underflow_error("underflow_error");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return data[0];

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("underflow_error");

  }
	T temp = data[0];
  data[0] = data[size()-1];
  data[size()-1] = temp;

  data.pop_back();

  int index = 0;
  while ((size_t) (m * index + 1 < size()) ) // has a child
  {

		T best_val = data[m * index + 1];
		size_t best_index = m * index + 1;

    for (int i = 1; i <= m && ((size_t) (m * index + i) < size()); i++) // check each child
    {
			size_t child_index = m * index + i;
      if (c(data[child_index], best_val)) // swap
      {
        best_val = data[child_index];
				best_index = child_index;
      }
    }

		if (c(best_val, data[index])) // swap
		{
			T temp = data[index];
			data[index] = data[best_index];
			data[best_index] = temp;

			index = best_index;
		}
		else
			break;
  }
  

}




template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{

    data.push_back(item);

    std::size_t index = data.size() - 1;
    while (index > 0) {
        std::size_t parent_index = (index - 1) / m;

        if (!c(data[index], data[parent_index])) {
            break;
        }

				T temp = data[index];
				data[index] = data[parent_index];
				data[parent_index] = temp;

        index = parent_index;
    }
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return (size() == 0);
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return data.size();
}


#endif

