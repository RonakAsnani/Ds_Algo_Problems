#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = tail->next;
        }

        cin >> data;
    }
    return head;
}

// class Pair
// {
// public:
//     Node *head;
//     Node *tail;
// };
// Pair rev(Node *head)
// {
//     if (head->next == NULL || head == NULL)
//     {
//         Pair ans;
//         ans.head = head;
//         ans.tail = head;
//         return ans;
//     }
//     Pair small = rev(head->next);

//     small.tail->next = head;
//     head->next = NULL;

//     Pair ans;
//     ans.head = small.head;
//     ans.tail = head;
//     return ans;
// }

// Node *reve(Node *head)
// {
//     return rev(head).head;
// }

Node *rete(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *small = rete(head->next);
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return small;
}

int main()
{
    Node *head = takeinput();
    head = rete(head);
    print(head);
    return 0;
}