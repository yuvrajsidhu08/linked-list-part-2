#include <iostream>
#include <iomanip>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

Node* add(Node* head, Student* s) {
  if (!head || s->getID() < head->get_value()->getID())
    return new Node(s, head);

  head->set_next(add(head->get_next(), s));
  return head;
}

void print(Node* head) {
  if (!head) return;
  Student* s = head->get_value();
  cout << s->getFirst() << " " << s->getLast()
       << ", " << s->getID()
       << ", " << fixed << setprecision(2)
       << s->getGPA() << endl;
  print(head->get_next());
}

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
