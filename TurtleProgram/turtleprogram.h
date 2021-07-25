#ifndef A1_TURTLEPROGRAM_H
#define A1_TURTLEPROGRAM_H
#pragma once

#include <iostream>
#include <string>

/**
 * TurtleProgram class. Includes a private dynamically allocated string array
 * of pointers s_ and int arrLength_ which keeps track of the array length.
 */
class TurtleProgram {
private:
  int arrLength_;
  std::string* s_; // array of strings

  //extra
  void copy_(const TurtleProgram& rhs); // private helper function

public:

  // 1. constructor and destructor
  TurtleProgram();
  // 2 parameter
  TurtleProgram(std::string s, std::string n);
  // copy constructor
  TurtleProgram(const TurtleProgram &rhs);
  TurtleProgram(const TurtleProgram &rhs, int size);
  // copy constructor combines two objects
  TurtleProgram(const TurtleProgram &curr, const TurtleProgram &rhs);
  virtual ~TurtleProgram(); // destructor

  // 2. overloaded cout operator
  friend std::ostream &operator<<(std::ostream &os, const TurtleProgram&
  turtle);

  // 3. overloaded equality and inequality operators
  bool operator==(const TurtleProgram& rhs)const;
  bool operator!=(const TurtleProgram& rhs)const;

  // 4. operator =, +, +=
  TurtleProgram& operator=(const TurtleProgram& rhs);
  TurtleProgram operator+(const TurtleProgram& rhs)const;
  TurtleProgram& operator+=(const TurtleProgram& rhs);

  // 5. *, *=
  TurtleProgram operator*(const int &rhs) const;
  TurtleProgram& operator*=(const int &size);

  // 6. getLength, getIndex, setIndex
  int getLength()const;
  std::string getIndex(int index)const;
  void setIndex(int index, const std::string& insert);
};

#endif // A1_TURTLEPROGRAM_H
