// Example test program to verify LinkedList functionality
#include "linkedlist.hpp"
#include <iostream>

int main() {
  // Test basic insertion
  LinkedList list;
  std::cout << "Testing InsertNode (at end):" << std::endl;
  list.InsertNode(10);
  list.InsertNode(20);
  list.InsertNode(30);
  list.PrintValues();  // Expected: 10 -> 20 -> 30 -> nullptr
  std::cout << "Size: " << list.GetSize() << std::endl;  // Expected: 3

  // Test InsertNodeFront
  std::cout << "\nTesting InsertNodeFront:" << std::endl;
  list.InsertNodeFront(5);
  list.PrintValues();  // Expected: 5 -> 10 -> 20 -> 30 -> nullptr

  // Test Contains
  std::cout << "\nTesting Contains:" << std::endl;
  std::cout << "Contains 20: " << list.Contains(20) << std::endl;  // Expected: 1
  std::cout << "Contains 100: " << list.Contains(100) << std::endl;  // Expected: 0

  // Test GetValueAtPosition
  std::cout << "\nTesting GetValueAtPosition:" << std::endl;
  std::cout << "Value at position 2: " << list.GetValueAtPosition(2) << std::endl;  // Expected: 10

  // Test InsertNodeAt
  std::cout << "\nTesting InsertNodeAt:" << std::endl;
  list.InsertNodeAt(15, 3);
  list.PrintValues();  // Expected: 5 -> 10 -> 15 -> 20 -> 30 -> nullptr

  // Test Remove
  std::cout << "\nTesting Remove:" << std::endl;
  list.Remove(3);
  list.PrintValues();  // Expected: 5 -> 10 -> 20 -> 30 -> nullptr

  // Test PrintAddresses
  std::cout << "\nTesting PrintAddresses:" << std::endl;
  list.PrintAddresses();

  // Test ReverseList
  std::cout << "\nTesting ReverseList:" << std::endl;
  LinkedList* reversed = list.ReverseList();
  std::cout << "Original list (now empty): ";
  list.PrintValues();  // Expected: nullptr
  std::cout << "Reversed list: ";
  reversed->PrintValues();  // Expected: 30 -> 20 -> 10 -> 5 -> nullptr
  delete reversed;  // Clean up the dynamically allocated list

  // Test MergeIntertwine
  std::cout << "\nTesting MergeIntertwine:" << std::endl;
  LinkedList list1;
  list1.InsertNode(1);
  list1.InsertNode(3);
  list1.InsertNode(5);
  
  LinkedList list2;
  list2.InsertNode(2);
  list2.InsertNode(4);
  list2.InsertNode(6);
  list2.InsertNode(8);

  std::cout << "List1: ";
  list1.PrintValues();
  std::cout << "List2: ";
  list2.PrintValues();

  LinkedList* merged = list1.MergeIntertwine(list2);
  std::cout << "Merged: ";
  merged->PrintValues();  // Expected: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 8 -> nullptr
  delete merged;

  std::cout << "\nOriginal lists unchanged:" << std::endl;
  std::cout << "List1: ";
  list1.PrintValues();  // Still: 1 -> 3 -> 5 -> nullptr
  std::cout << "List2: ";
  list2.PrintValues();  // Still: 2 -> 4 -> 6 -> 8 -> nullptr

  return 0;
}