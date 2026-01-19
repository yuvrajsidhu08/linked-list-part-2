#ifndef STUDENT_H
#define STUDENT_H

class Student {
  public:
    Student(const char*, const char*, int, float);
    ~Student();

    const char* getFirst();
    const char* getLast();
    int getID();
    float getGPA();

  private:
    char* first;
    char* last;
    int id;
    float gpa;
};

#endif
