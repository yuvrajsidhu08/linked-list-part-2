#include <iostream>
#include <iomanip>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

// Adds a student to the linked list in sorted order by ID
Node* add(Node* head, Student* s) {
  if (!head || s->getID() < head->get_value()->getID())
    return new Node(s, head);

  head->set_next(add(head->get_next(), s));
  return head;
}

// Prints all students in the list
void print(Node* head) {
  if (!head) return;

  Student* s = head->get_value();
  cout << s->getFirst() << " " << s->getLast()
       << ", " << s->getID()
       << ", " << fixed << setprecision(2)
       << s->getGPA() << endl;

  print(head->get_next());
}

// Removes a student with the given ID
Node* remove(Node* head, int id) {
  if (!head) return NULL;

  if (head->get_value()->getID() == id) {
    Node* next = head->get_next();
    delete head->get_value();
    delete head;
    return next;
  }

  head->set_next(remove(head->get_next(), id));
  return head;
}

// Returns the sum of all student GPAs
float sum(Node* head) {
  if (!head) return 0;
  return head->get_value()->getGPA() + sum(head->get_next());
}

// Returns the number of students in the list
int count(Node* head) {
  if (!head) return 0;
  return 1 + count(head->get_next());
}

// Deletes all nodes and students in the list
void clear(Node* head) {
  if (!head) return;
  clear(head->get_next());
  delete head->get_value();
  delete head;
}

int main() {
  Node* head = NULL;
  char cmd[20];

  while (true) {
    cin >> cmd;

    if (!strcmp(cmd, "ADD")) {
      char f[50], l[50];
      int id;
      float gpa;
      cin >> f >> l >> id >> gpa;
      head = add(head, new Student(f, l, id, gpa));
    }
    else if (!strcmp(cmd, "PRINT")) {
      print(head);
    }
    else if (!strcmp(cmd, "DELETE")) {
      int id;
      cin >> id;
      head = remove(head, id);
    }
    else if (!strcmp(cmd, "AVERAGE")) {
      int c = count(head);
      if (c)
        cout << fixed << setprecision(2) << sum(head) / c << endl;
      else
        cout << "0.00" << endl;
    }
    else if (!strcmp(cmd, "QUIT")) {
      clear(head);
      break;
    }
  }

  return 0;
}
