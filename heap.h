#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <functional>
#include <stdexcept>

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
    Heap(int m = 2, PComparator c = PComparator()) : arity(m), comp(c) {
        if (m < 2) {
            throw std::invalid_argument("Heap arity must be at least 2");
        }
    }


  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap() = default;

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
    void push(const T& item) {
        data.push_back(item);
        upHeap(data.size() - 1);
    }

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
    bool empty() const {
      return data.empty();
    }

    /**
   * @brief Returns size of the heap
   * 
   */
    size_t size() const {
        return data.size();
    }
private:
  /// Add whatever helper functions and data members you need below
    std::vector<T> data;
    int arity;
    PComparator comp;

    void upHeap(size_t childIndex) {
        while (childIndex > 0) {
            size_t parentIndex = (childIndex - 1) / arity;
            if (comp(data[childIndex], data[parentIndex])) {
                std::swap(data[childIndex], data[parentIndex]);
                childIndex = parentIndex;
            } else {
                break;
            }
        }
    }

    void downHeap(size_t parentIndex) {
        while (true) {
            size_t minChildIndex = parentIndex * arity + 1;
            if (minChildIndex >= data.size()) {
                break; // No children
            }

            // Find the minimum (or maximum, depending on the comparator) among the children
            size_t endIndex = std::min(minChildIndex + arity, data.size());
            for (size_t i = minChildIndex + 1; i < endIndex; ++i) {
                if (comp(data[i], data[minChildIndex])) {
                    minChildIndex = i;
                }
            }

            // If the parent is greater (or less, depending on the comparator) than the min (or max) child, swap them
            if (comp(data[minChildIndex], data[parentIndex])) {
                std::swap(data[parentIndex], data[minChildIndex]);
                parentIndex = minChildIndex;
            } else {
                break; // The heap property is satisfied
            }
        }
    }



};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::underflow_error("Heap is empty");
    // ================================
    // throw the appropriate exception
    // ================================


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
    throw std::underflow_error("Heap is empty");

    // ================================
    // throw the appropriate exception
    // ================================


  }

    data[0] = data.back();
    data.pop_back();
    downHeap(0);

}



#endif

