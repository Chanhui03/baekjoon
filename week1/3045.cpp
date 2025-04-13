#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef int element;
struct Dlist_node {
  element data;
  struct Dlist_node* llink;
  struct Dlist_node* rlink;
};

void init(Dlist_node* phead);
void dinsert(Dlist_node* pre, element data);
void ddel(Dlist_node* head, Dlist_node* del);
void dprocess(Dlist_node* head, char cmd, int X, int Y, vector<string>& ops);
void dfront(Dlist_node* head, int X, int Y);
void dback(Dlist_node* head, int X, int Y);
int resort(Dlist_node* head);

int main() {
  int N, M;
  cin >> N >> M;

  Dlist_node* head = new Dlist_node;
  Dlist_node* last = head;
  init(head);

  for (int i = 0; i < N; i++) {
    dinsert(last, i);
    last = last->rlink;
  }

  vector<string> operations;

  for (int i = 0; i < M; i++) {
    char cmd;
    int X, Y;
    cin >> cmd >> X >> Y;
    dprocess(head, cmd, X, Y, operations);
  }

  int count = resort(head);
  cout << count << '\n';

  for (const auto& op : operations) {
    cout << op << '\n';
  }

  return 0;
}

void init(Dlist_node* phead) {
  phead->llink = phead;
  phead->rlink = phead;
}

void dinsert(Dlist_node* pre, element data) {
  Dlist_node* n = new Dlist_node;
  n->data = data;
  n->llink = pre;
  n->rlink = pre->rlink;

  pre->rlink->llink = n;
  pre->rlink = n;
}

void ddel(Dlist_node* head, Dlist_node* del) {
  if (del == head) return;

  del->llink->rlink = del->rlink;
  del->rlink->llink = del->llink;
  delete(del);
}

void dprocess(Dlist_node* head, char cmd, int X, int Y, vector<string>& ops) {
  if (X == Y) return; // 무의미한 연산은 생략
  ops.push_back(string(1, cmd) + " " + to_string(X) + " " + to_string(Y));
  if (cmd == 'A') dfront(head, X, Y);
  else if (cmd == 'B') dback(head, X, Y);
}

void dfront(Dlist_node* head, int X, int Y) {
  Dlist_node* p = head->rlink;
  Dlist_node* targetX = nullptr;
  Dlist_node* targetY = nullptr;

  while (p != head) {
    if (p->data == X) targetX = p;
    if (p->data == Y) targetY = p;
    p = p->rlink;
  }

  if (!targetX || !targetY) return;

  ddel(head, targetX);
  dinsert(targetY->llink, X);
}

void dback(Dlist_node* head, int X, int Y) {
  Dlist_node* p = head->rlink;
  Dlist_node* targetX = nullptr;
  Dlist_node* targetY = nullptr;

  while (p != head) {
    if (p->data == X) targetX = p;
    if (p->data == Y) targetY = p;
    p = p->rlink;
  }

  if (!targetX || !targetY) return;

  ddel(head, targetX);
  dinsert(targetY, X);
}

int resort(Dlist_node* head) {
  Dlist_node* p = head->rlink;
  vector<int> arr;
  
  while (p != head) {
    arr.push_back(p->data);
    p = p->rlink;
  }

  vector<int> lis;
  for (int x : arr) {
    auto it = lower_bound(lis.begin(), lis.end(), x);
    if (it == lis.end()) lis.push_back(x);
    else *it = x;
  }

  return arr.size() - lis.size(); // 필요한 연산 수
}
