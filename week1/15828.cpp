#include <iostream>

using namespace std;

typedef int element;
struct list_node {
  element data;
  struct list_node *link;
};

struct list_type {
  int size;
  list_node *head;
  list_node *tail;
};

list_type* create();
void insert_last(list_type* plist, element data);
void dequeue(list_type* plist);
void print_list(list_type* plist);
bool isempty(list_type* plist);
bool isfull(int size, int N);
void free_memory(list_type* plist);


int main() {
  int N, buf;
  cin >> N;
  list_type* plist = create();

  while(true) {
    cin >> buf;
    if (buf == -1) break;
    if (buf == 0){
      if (isempty(plist) == false) dequeue(plist);
    }
    else if (buf > 0) {
      if (isfull(plist->size, N) == false) insert_last(plist, buf);
    }
  }
  if (isempty(plist) == true) cout << "empty";
  else print_list(plist);
  free_memory(plist);

  return 0;
}


list_type* create(){
  list_type *plist = (list_type*)malloc(sizeof(list_type));
  plist->size = 0;
  plist->head = plist->tail = NULL;

  return plist;
}


void insert_last(list_type* plist, element data){
  list_node* temp = (list_node*)malloc(sizeof(list_node));
  temp->data = data;
  temp->link = NULL;

  if (plist->tail == NULL) plist->head = plist->tail = temp;
  else {
    plist->tail->link = temp;
    plist->tail = temp;
  }
  plist->size++;
}


void dequeue(list_type* plist){
  if (plist->head == NULL) return;
  list_node* temp = plist->head;
  plist->head = temp->link;
  free(temp);
  plist->size--;
  if (plist->head == NULL) 
    plist->tail = NULL;
}

void print_list(list_type* plist){
  list_node* temp = plist->head;
  while(temp != NULL) {
    cout << temp->data << " ";
    temp = temp->link;
  }
}

bool isempty(list_type* plist){
  return plist->tail == NULL;
}

bool isfull(int size, int N){
  if(size < N) return false;
  else return true;
}


void free_memory(list_type* plist) {
  list_node* temp;
  while(plist->head != NULL) {
    temp = plist->head;
    plist->head = temp->link;
    free(temp);
  }
  free(plist);
}