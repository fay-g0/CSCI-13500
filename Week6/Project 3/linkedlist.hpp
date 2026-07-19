#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_
#include <stdexcept> 

// Node struct - the building block of our linked list
// Each node stores an integer value and a pointer to the next node
struct Node {
  int value;
  Node* next;

  // Default constructor (does not initialize members)
  // This is implicitly defined, but we'll explicitly declare it for clarity
  Node() : value(0), next(nullptr) {}

  // Parameterized constructor for convenience
  // Initializes the node with a value and sets next to nullptr
  explicit Node(int passed_value) : value(passed_value), next(nullptr) {}
};

// LinkedList class - a pointer-based dynamic data structure
// Provides operations to insert, remove, search, and manipulate nodes
class LinkedList {
 public:
  // Constructor: initializes an empty list
  LinkedList();

  // Destructor: cleans up all dynamically allocated nodes
  ~LinkedList();

  // --- Core Operations ---

  // Insert a new node with the given value at the end of the list
  // @param value: the integer to insert
  // @return: nothing
  void InsertNode(const int value);

  // Insert a new node with the given value at the beginning of the list
  // @param value: the integer to insert
  // @return: nothing
  void InsertNodeFront(const int value);

  // Insert a new node with the given value at a specific 1-based position
  // @param value: the integer to insert
  // @param position: 1-based index where the node should be inserted
  // @throws std::out_of_range if position is invalid
  // @return: nothing
  void InsertNodeAt(const int value, const int position);

  // Remove the node at a specific 1-based position
  // @param position: 1-based index of the node to remove
  // @return: true if successfully removed, false if position is invalid
  bool Remove(const int position);

  // Check if a value exists in the list
  // @param value: the integer to search for
  // @return: true if found, false otherwise
  bool Contains(const int value) const;

  // Get the value at a specific 1-based position
  // @param position: 1-based index to look up
  // @return: the integer value at that position
  // @throws std::out_of_range if position is invalid
  int GetValueAtPosition(const int position) const;

  // Reverse the current list in place, returning a new heap-allocated list
  // The current list becomes empty after this operation
  // @return: pointer to a new LinkedList containing the reversed nodes
  LinkedList* ReverseList();

  // Merge two lists by alternating nodes from each list
  // Neither original list is modified
  // @param second_list: the other list to merge with
  // @return: pointer to a new heap-allocated merged list
  LinkedList* MergeIntertwine(const LinkedList& second_list) const;

  // --- Utility Operations ---

  // Print all values in the list in chain format
  // Example: 10 -> 23 -> 4 -> nullptr
  void PrintValues() const;

  // Print the 1-based position and memory address of each node
  // Example: 1 0x7fff5fbff8c0
  void PrintAddresses() const;

  // Get the current number of nodes in the list
  // @return: the size of the list
  int GetSize() const;

 private:
  int size_;   // Number of nodes currently in the list
  Node* head_; // Pointer to the first node (front/beginning) of the list
};

#endif