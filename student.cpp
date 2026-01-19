#include "student.h"
#include <cstring>

Student::Student(const char* f, const char* l, int i, float g) {
  first = new char[strlen(f) + 1];
  strcpy(first, f);
}
