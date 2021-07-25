#include "turtleprogram.h"
#include <iostream>

using namespace std;

int main() {
  TurtleProgram tp1;
  cout << "tp1: " << tp1 << endl;
  TurtleProgram tp2("F", "10");
  cout << "tp2: " << tp2 << endl;

  // custom test
  //  cout << "tp1 index 0 is: " << tp1.getIndex(0) << endl; // empty
  //  cout << "tp2 length is: " << tp2.getLength() << endl;  // custom
  //  cout << "tp2 index 0 is: " << tp2.getIndex(0) << endl;
  //  cout << "tp2 index of -1 is: " << tp2.getIndex(-1) << endl;
  // end of custom test 1

  TurtleProgram tp3("R", "90");
  tp1 = tp2 + tp3;
  cout << "tp1 now as tp2+tp3: " << tp1 << endl;
  tp1 = tp2 * 3;
  cout << "tp1 now as tp2 * 3: " << tp1 << endl;
  TurtleProgram tp4(tp1);
  cout << "tp4 is a copy of tp1: " << tp4 << endl;
  TurtleProgram tp5("F", "10");
  cout << "tp5: " << tp5 << endl;
  cout << boolalpha;
  cout << "tp2 and tp5 are == to each other: " << (tp2 == tp5) << endl;
  cout << "tp2 and tp3 are != to each other: " << (tp2 != tp3) << endl;
  cout << "index 0 of tp2 is " << tp2.getIndex(0) << endl;
  tp2.setIndex(0, "R");
  tp2.setIndex(1, "90");
  cout << "tp2 after 2 calls to setIndex: " << tp2 << endl;
  cout << "tp2 and tp3 are == to each other: " << (tp2 == tp3) << endl;

  //    need to write additional tests for += *=
  TurtleProgram c1("R", "90");
  TurtleProgram c2("F", "10");
  c1 += c2;
  cout << "c1 now as c1 = c1 + c2: " << c1 << endl;
  cout << "Done." << endl;
  return 0;
}

// output:
// tp1: []
// tp2: [F 10]
// tp1 now as tp2+tp3: [F 10 R 90]
// tp1 now as tp2 * 3: [F 10 F 10 F 10]
// tp4 is a copy of tp1: [F 10 F 10 F 10]
// tp5: [F 10]
// tp2 and tp5 are == to each other: true
// tp2 and tp3 are != to each other: true
// index 0 of tp2 is F
// tp2 after 2 calls to setIndex: [R 90]
// tp2 and tp3 are == to each other: true
// Done.
//
