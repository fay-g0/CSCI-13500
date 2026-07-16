#include "linkedlist.hpp"
#include <iostream> 
#include <stdexcept>  // For std::out_of_range

LinkedList::LinkedList() : size_(0), head_(nullptr) {
  // Initializer list sets size to 0 and head to nullptr
  // This represents an empty list
}

LinkedList::~LinkedList() {
  // Free all dynamically allocated nodes to prevent memory leaks
  Node* current = head_;
  while (current != nullptr) {
    Node* next_node = current->next;
    delete current;
    current = next_node;
  }
  head_ = nullptr;
  size_ = 0;
}

// iterate through all nodes to reach the tail
void LinkedList::InsertNode(const int value) {
  Node* new_node = new Node(value);

  if (head_ == nullptr) {
    // Empty list: new node becomes the head
    head_ = new_node;
  } else {
    // Traverse to the end of the list
    Node* current = head_;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = new_node;
  }
  size_++;
}

//Only need to update head pointer and set new node's next
void LinkedList::InsertNodeFront(const int value) {
  Node* new_node = new Node(value);
  new_node->next = head_;
  head_ = new_node;
  size_++;
}
//Must find the node before the insertion position
void LinkedList::InsertNodeAt(const int value, const int position) {
  // Validate position: allow insertion at end (position == size_ + 1)
  if (position < 1 || position > size_ + 1) {
    throw std::out_of_range("Invalid position for insertion");
  }

  // Special case --> insert at front
  if (position == 1) {
    InsertNodeFront(value);
    return;
  }

  // Special case --> insert at end
  if (position == size_ + 1) {
    InsertNode(value);
    return;
  }

  // Insert in the middle: traverse to the node before the insertion point
  Node* new_node = new Node(value);
  Node* current = head_;
  
  // Move to position - 1 (1-based, so we stop before the target)
  for (int i = 1; i < position - 1; i++) {
    current = current->next;
  }

  // Insert the new node
  new_node->next = current->next;
  current->next = new_node;
  size_++;
}

// Must find the node before the target to update its next pointer
bool LinkedList::Remove(const int position) {
  // Validate position
  if (position < 1 || position > size_) {
    return false;
  }

  Node* node_to_delete = nullptr;

  // Special case: remove the head
  if (position == 1) {
    node_to_delete = head_;
    head_ = head_->next;
  } else {
    // Traverse to the node before the one to remove
    Node* current = head_;
    for (int i = 1; i < position - 1; i++) {
      current = current->next;
    }
    node_to_delete = current->next;
    current->next = node_to_delete->next;
  }

  // Free the memory and update size
  delete node_to_delete;
  size_--;
  return true;
}


// examines every node to find the value
bool LinkedList::Contains(const int value) const {
  Node* current = head_;
  while (current != nullptr) {
    if (current->value == value) {
      return true;
    }
    current = current->next;
  }
  return false;
}

// iterate through nodes until reaching the specific index
int LinkedList::GetValueAtPosition(const int position) const {
  // Validate position
  if (position < 1 || position > size_) {
    throw std::out_of_range("Position out of bounds");
  }

  // Traverse to the target node
  Node* current = head_;
  for (int i = 1; i < position; i++) {
    current = current->next;
  }
  return current->value;
}

//Iterates through the list once, prepending nodes to the new list
LinkedList* LinkedList::ReverseList() {
  // Create a new list to hold the reversed nodes
  LinkedList* reversed_list = new LinkedList();

  // Iterate through the current list and prepend each node to the new list
  Node* current = head_;
  while (current != nullptr) {
    // Insert each node's value at the front of the new list
    // This naturally reverses the order
    reversed_list->InsertNodeFront(current->value);
    current = current->next;
  }

  // Reset the current list to empty
  // 1st delete all existing nodes
  current = head_;
  while (current != nullptr) {
    Node* next_node = current->next;
    delete current;
    current = next_node;
  }
  head_ = nullptr;
  size_ = 0;

  return reversed_list;
}

//Traverses both lists once, alternating nodes
LinkedList* LinkedList::MergeIntertwine(const LinkedList& second_list) const {
  LinkedList* merged_list = new LinkedList();

  Node* current1 = head_;
  Node* current2 = second_list.head_;

  // Alternate between the two lists
  while (current1 != nullptr || current2 != nullptr) {
    if (current1 != nullptr) {
      merged_list->InsertNode(current1->value);
      current1 = current1->next;
    }
    if (current2 != nullptr) {
      merged_list->InsertNode(current2->value);
      current2 = current2->next;
    }
  }

  return merged_list;
}

//Iterates through the list and prints each value
void LinkedList::PrintValues() const {
  if (head_ == nullptr) {
    std::cout << "nullptr" << std::endl;
    return;
  }

  Node* current = head_;
  while (current != nullptr) {
    std::cout << current->value;
    if (current->next != nullptr) {
      std::cout << " -> ";
    }
    current = current->next;
  }
  std::cout << " -> nullptr" << std::endl;
}

//Iterates through the list and prints each node's address
void LinkedList::PrintAddresses() const {
  Node* current = head_;
  int position = 1;
  while (current != nullptr) {
    std::cout << position << " " << current << std::endl;
    current = current->next;
    position++;
  }
}

//Returns the stored size_ member variable
int LinkedList::GetSize() const {
  return size_;
}