#include "student.h"
#include <cstring>

Student::Student(const char* f, const char* l, int i, float g) {
  first = new char[strlen(f) + 1];
  strcpy(first, f);

  last = new char[strlen(l) + 1];
  strcpy(last, l);

  id = i;
  gpa = g;
}

Student::~Student() {
  delete[] first;
  delete[] last;
}

const char* Student::getFirst() { return first; }
const char* Student::getLast() { return last; }
int Student::getID() { return id; }
float Student::getGPA() { return gpa; }
