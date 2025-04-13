#include <iostream>

using namespace std;

typedef int element;
struct Dlist_node {
    element data;
    Dlist_node* llink;
    Dlist_node* rlink;
};

void init(Dlist_node* head) {
    head->llink = head;
    head->rlink = head;
}

void dinsert(Dlist_node* pre, element data) {
    Dlist_node* node = (Dlist_node*)malloc(sizeof(Dlist_node));

    node->data = data;
    node->llink = pre;
    node->rlink = pre->rlink;

    pre->rlink->llink = node;
    pre->rlink = node;
}

void ddel(Dlist_node* del) {
    del->llink->rlink = del->rlink;
    del->rlink->llink = del->llink;
    free(del);
}

int main() {
    int N, K, M;
    cin >> N >> K >> M;

    Dlist_node* head = (Dlist_node*)malloc(sizeof(Dlist_node));
    init(head);

    for (int i = 1; i <= N; ++i) dinsert(head->llink, i);

    Dlist_node* cur = head->rlink;
    int count = 0;
    bool reverse = false;
    bool reversed_once = false;  // 반전 여부 체크

    while (N--) {
        for (int i = 1; i < K; ) {
            cur = reverse ? cur->llink : cur->rlink;
            if (cur == head) continue;
            ++i;
        }

        cout << cur->data << endl;
        ++count;

        if (count == M && !reversed_once) {
            reverse = !reverse;
            reversed_once = true;
        }

        Dlist_node* next = reverse ? cur->llink : cur->rlink;
        if (next == head) next = reverse ? next->llink : next->rlink;

        ddel(cur);
        cur = next;
    }


    free(head);
    return 0;
}
