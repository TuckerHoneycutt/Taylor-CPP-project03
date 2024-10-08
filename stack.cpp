#include "stack.h"

// Constructor
Stack::Stack(int n) : num(n), top(-1) { array = new int[num]; }

// Destructor
Stack::~Stack() { delete[] array; }

// IsEmpty
bool Stack::IsEmpty() const { return top == -1; }

// IsFull
bool Stack::IsFull() const { return top == num - 1; }

// MakeEmpty
void Stack::MakeEmpty() { top = -1; }

// Top
int Stack::Top() const {
  // Check to see if stack is empty
  if (IsEmpty()) {
    throw StackEmpty();
  }
  // If not empty, return top element;
  return array[top];
}

// Size
int Stack::Size() const {
  // Return top element, offset by 1 because of 0 index
  return top + 1;
}

// Max
int Stack::Max() const {
  // Check to see if the stack is empty
  if (IsEmpty()) {
    throw StackEmpty();
  }
  // Define max and initalize it to be the first element
  int max = array[0];

  // Loop through items 1 -> end in stack. Compare to see if larger than first
  // index. If so set max to be that stack index.
  for (int i = 1; i <= top; i += 1) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

// Min
int Stack::Min() const {
  // Check to see if the stack is empty
  if (IsEmpty()) {
    throw StackEmpty();
  }

  // Define mine adn initalize it to be the first element.
  int min = array[0];

  // Loop through index 1 -> end in stack. Compare to see if smaller than first
  // index. If so set min to be that stack index
  for (int i = 1; i <= top; i += 1) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  return min;
}

// Peek
int Stack::Peek(unsigned int n) const {
  // Check to see if n is in bounds of stack
  if (n == 0 || n > static_cast<unsigned int>(top + 1)) {
    throw StackInvalidPeek();
  }

  // Return the nth element of the stack
  return array[top - n + 1];
}

// Capacity
int Stack::Capacity() const {
  // num is the capacity of the stack so just returns num
  return num;
}

// Resize
void Stack::Resize(int n) {
  // Create a new size that is twice n's capacity
  int new_size = num * 2;
  // Create a new stack that's twice n's capacity
  int *new_array = new int[new_size];

  // Iterate through first stack and copy each element over
  for (int i = 0; i <= top; i += 1) {
    new_array[i] = array[i];
  }

  // Cleanup and delete old stack
  delete[] array;

  // Set stack to be the new stack
  array = new_array;

  // Set capacity to be the new capacity
  num = new_size;

  Push(n);
}

// Push
void Stack::Push(int n) {
  // Check to see if the stack is full. If so resize the stack
  if (IsFull()) {
    Resize(n);
  } else {
    // Set the last element to be n
    array[top += 1] = n;
  }
}

// Pop
void Stack::Pop() {
  // Check to see if Stack is empty
  if (IsEmpty()) {
    throw StackEmpty();
  }
  top -= 1;
}
