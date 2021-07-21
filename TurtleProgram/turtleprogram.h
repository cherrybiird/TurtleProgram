

#ifndef A1_TURTLEPROGRAM_H
#define A1_TURTLEPROGRAM_H
#pragma once

#include <iostream>
#include <string>

class TurtleProgram {
private:
  int arrLength_;
  std::string* s_; // array of strings

public:

  // 1. constructor and destructor
  TurtleProgram();
  // 2 parameter
  TurtleProgram(std::string s, std::string n);
  // copy constructor
//  TurtleProgram(const TurtleProgram &rhs);
  virtual ~TurtleProgram(); // destructor

  // 2. overloaded cout operator
  friend std::ostream &operator<<(std::ostream &os, const TurtleProgram&
                                                        turtle);

  // 3. overloaded equality and inequality operators
  TurtleProgram operator==(const TurtleProgram& b)const;
  TurtleProgram operator!=(const TurtleProgram& b)const;

  // 4. operator =, +, +=
  void operator=(const TurtleProgram& rhs)const;
  void operator+(const TurtleProgram& b)const;
  void operator+=(const TurtleProgram& b)const;

  // 5. *, *=
  void operator*(const TurtleProgram& rhs);
  void operator*=(const TurtleProgram& rhs);

  // 6. getLength, getIndex, setIndex
  int getLength()const;
  std::string getIndex(int index)const;
  void setIndex(int index, const std::string& insert);
};

#endif // A1_TURTLEPROGRAM_H
