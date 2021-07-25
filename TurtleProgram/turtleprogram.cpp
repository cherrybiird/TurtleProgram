#include "turtleprogram.h"


/**
 * Default constructor. Initializes empty TurtleProgram Object with pointers
 * to a string array of length 0.
 */
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
  s_[0] = d;
  s_[1] = n;
}

/**
 * Copy constructor. Initializes member variables of object from the
 * parameter object (rhs).
 * @param rhs - const TurtleProgram&
 */
TurtleProgram::TurtleProgram(const TurtleProgram& rhs) {
  arrLength_ = rhs.arrLength_;
  s_ = new std::string[arrLength_];
  copy_(rhs);
}

/**
 * Copy constructor. Initializes member variables of object from the
 * parameter object (rhs). A dynamically allocated array's length is based on
 * size.
 * @param rhs - const TurtleProgram&
 *        size - int which determines the size of the array s_
 */
TurtleProgram::TurtleProgram(const TurtleProgram& rhs, int size) {
  arrLength_ = size;
  s_ = new std::string[arrLength_];
  copy_(rhs);
}

/**
 * Copy constructor that accepts two TurtleProgram objects. This is used to
 * combine both objects into one dynamically allocated array.
 * @param rhs - const TurtleProgram&
 */
TurtleProgram::TurtleProgram(const TurtleProgram& curr, const TurtleProgram&
rhs) {
  arrLength_ = curr.arrLength_ + rhs.arrLength_;
  s_ = new std::string[arrLength_];

  // part 1 - copy curr's contents into s_
  for (int i = 0; i < curr.arrLength_; i++){
    s_[i] = curr.s_[i];
  }

  // part 2 - now to copy the rhs (rest of the contents) into s_
  for (int i = 0; i < rhs.arrLength_; i++){
    s_[curr.arrLength_ + i] = rhs.s_[i];
  }
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
 * Overloaded == operator. Compares this and rhs TurtleProgram object to see
 * if they contain the same instructions.
 * @param rhs - const TurtleProgram &rhs
 * @return true - both objects contain the same instructions. Otherwise, false.
 */
bool TurtleProgram::operator==(const TurtleProgram &rhs) const {
  // compare size
  if (arrLength_ != rhs.arrLength_) return false;

  // same size; now compare contents
  for (int i = 0; i < arrLength_; i++ ) {
    if (s_[i] != rhs.s_[i]) {
      return false;
    }
  }

  // otherwise they should all be the same!
  return true;
}

/**
 * Overloaded != operator. Compares this and rhs object to see if they do not
 * contain the same instructions.
 * @param rhs - const TurtleProgram &rhs
 * @return true - both objects do not equal each other. Otherwise, false.
 */
bool TurtleProgram::operator!=(const TurtleProgram &rhs) const {
  return !(*this == rhs);
}

/**
 * Overloaded assignment (=) operator.
 * @param rhs - const TurtleProgram &rhs
 * @return *this - copied values from rhs into the existing object
 * if rhs is the same as *this, then it will automatically return *this.
 */
TurtleProgram& TurtleProgram::operator=(const TurtleProgram &rhs)  {
  // check if they are already equal
  if (this == &rhs) return *this;

  // if data exists, delete it
  if (s_) delete[] s_;

  arrLength_ = rhs.arrLength_;

  // copy data from rhs to implicit object
  s_ = new std::string[arrLength_];

  copy_(rhs); // copies all the contents within rhs to this

  return *this;
}

/**
 * Overloaded + operator. Adds lhs(*this) + rhs object.
 * @param rhs - const TurtleProgram &rhs
 * @return TurtleProgram(*this, rhs)
 */
TurtleProgram TurtleProgram::operator+(const TurtleProgram &rhs) const {
  // calls on copy constructor to combine two objects
  return TurtleProgram(*this, rhs);
}

/**
 * Overloaded += operator. Adds rhs TurtleProgram object to current object.
 * @param rhs - const TurtleProgram &rhs
 * @return *this = *this + rhs
 */
TurtleProgram& TurtleProgram::operator+=(const TurtleProgram &rhs) {
  return (*this = *this + rhs);
}

/**
 * Overloaded * operator. Multiples the contents within the lhs (current)
 * object with int.
 *
 * Size cannot be less than or equal to 0. This will return an empty
 * TurtleProgram object.
 * If size is 1, function returns the same object as it was before.
 *
 * Example:
 * tp2 = [R 90]
 * tp2 = tp2 * 3
 * tp2 = [R 90 R 90 R 90]
 * @param rhs - const TurtleProgram &rhs
 * @return
 */
TurtleProgram TurtleProgram::operator*(const int &size) const {
  if (size <= 0) return TurtleProgram();
  if (size == 1) return *this;

  TurtleProgram total(*this, arrLength_ * size);

  // to fill our partially filled-array
  for (int i = 0; i < total.arrLength_ - arrLength_; i++) {
    total.s_[arrLength_ + i] = total.s_[i];
  }
  return total;
}

/**
 * Overloaded *= operator. Does *this *= size. (Other way of writing *this =
 * *this * size)
 * @param rhs
 * @return
 */
TurtleProgram& TurtleProgram::operator*=(const int &size) {
  return (*this = *this * size);
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
  // if index is greater than array length or less than 0
  if ((index > (arrLength_ - 1)) || (index < 0)) {
    return "index is out of bounds.";
  }

  return s_[index];
}

/**
 * Sets a string based on index and string that is inserted. Must follow
 * [LETTER NUMBER] format when choosing an index.
 * EXMAPLE:
 * TurtleProgram tp2 ("F", "10");
 * tp2.setIndex(0, "R");
 * tp2.setIndex(1, "90");
 * tp2 after 2 calls to setIndex: [R 90]
 * @param index - int
 * @param insert - const std::string&
 */
void TurtleProgram::setIndex(int index, const std::string& insert) {
  if ((index < 0) || (index > (arrLength_ - 1))) return; // invalid index

  // otherwise we insert
  s_[index] = insert;
}

// ---------- PRIVATE HELPER FUNCTIONS ----------

/**
 * Private helper function that copies contents from rhs into current object.
 * @param rhs - const TurtleProgram& rhs
 */
void TurtleProgram::copy_(const TurtleProgram &rhs) {
  for (int i = 0; i < arrLength_; i++) {
    s_[i] = rhs.s_[i];
  }
}

