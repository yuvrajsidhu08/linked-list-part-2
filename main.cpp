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
