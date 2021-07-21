#include "turtleprogram.h"
#include <iostream>

TurtleProgram::TurtleProgram() {
  arrLength_ = 0;
  s_ = new std::string[arrLength_];
}

/**
 * Constructor. Takes in two string parameters.
 * @param d - string (directions = Forward, Right)
 * @param n - string (number = 10, 20, 30 etc)
 */
TurtleProgram::TurtleProgram(std::string d, std::string n) {
  arrLength_ = 2;
  s_ = new std::string[arrLength_];
  s_[0] = std::move(d);
  s_[1] = std::move(n);
}

/**
 * Destructor. Deallocates s_.
 */
TurtleProgram::~TurtleProgram() {
  delete[] s_;
}

/**
 * ostream &operator. Used to output TurtleProgram object to the terminal.
 * EXAMPLE: An empty object will look like [].
 * If there are contents then it will look something like this: [F 10]
 * @param os - std::ostream &os
 * @param turtle - const TurtleProgram
 * @return os
 */
std::ostream &operator<<(std::ostream &os, const TurtleProgram &turtle) {
  if (turtle.arrLength_ == 0) {
    // empty object []
    os << "[";
    os << "]";
    return os;
  }

  os << "[";
  for (int i = 0; i < turtle.arrLength_; i++) {
    if (i == turtle.arrLength_ - 1) {
      // gets rid of extra space before "]"
      os << turtle.s_[i];
      os << "]";
      return os;
    }
    os << turtle.s_[i] << " ";
  }
  return os;
}

/**
 * Returns the numbers of strings in the program.
 * EXAMPLE: [F 10]'s length is 2.
 * @return arrLength_ - int
 */
int TurtleProgram::getLength() const {
   return arrLength_;
}

/**
 * Returns the string based on given index. Index must be an integer which
 * exists within the TurtleProgram's length.
 * Entering an invalid index will result in an out of bounds message.
 * @param index - integer
 * @return s_[index]
 */
std::string TurtleProgram::getIndex(int index) const {
  if (index == 0) {
    // to handle empty object
    return s_[index];
  }

  // if index is greater than array length or less than 0
  if ((index > (arrLength_ - 1)) || (index < 0)) {
    return "index is out of bounds.";
  };

  return s_[index];
}

/**
 * Sets a string based on index and string that is inserted. Must follow
 * [LETTER NUMBER] format.
 * TurtleProgram tp2 ("F", "10");
 * tp2.setIndex(0, "R");
 * tp2.setIndex(1, "90");
 * tp2 after 2 calls to setIndex: [R 90]
 * @param index - int
 * @param insert - const std::string&
 */
void TurtleProgram::setIndex(int index, const std::string& insert) {
  if (index == 0) {
    // setting into a empty object
    s_[0] = insert;
    return;
  }

  if ((index < 0) || (index > (arrLength_ - 1))) return; // invalid index

  // otherwise we insert
  s_[index] = insert;
}
