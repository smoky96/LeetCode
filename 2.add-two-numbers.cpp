#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode result(0);
        ListNode* p = &result;
        int carry = 0;
        int a = 0;
        int b = 0;
        int sum = 0;
        while (l1 || l2 || carry) {
            a = l1 ? l1 -> val : 0;
            b = l2 ? l2 -> val : 0;
            sum = a + b + carry;
            p -> next = new ListNode(sum % 10);
            carry = sum / 10;
            p = p -> next;
            l1 = l1 ? l1 -> next : l1;
            l2 = l2 ? l2 -> next : l2;
        }
        return result.next;
    }
};

void test(ListNode* l1, ListNode* l2) {
    Solution s;
    ListNode* result = s.addTwoNumbers(l1, l2);
    cout << "ListNode 1: ";
    while (l1) {
        cout << l1 -> val;
        if (l1 -> next) cout << " -> ";
        l1 = l1 -> next;
    }
    cout << endl;
    cout << "ListNode 2: ";
    while (l2) {
        cout << l2 -> val;
        if (l2 -> next) cout << " -> ";
        l2 = l2 -> next;
    }
    cout << endl;
    cout << "result: ";
    while (result) {
        cout << result -> val;
        if (result -> next) cout << " -> ";
        result = result -> next;
    }
    cout << endl;
}

int main() {
    ListNode l1(0);
    ListNode* p1 = &l1;
    ListNode l2(0);
    ListNode* p2 = &l2;
    int a[] = {9, 1, 6};
    int b[] = {0};
    for (int i = 0; i < 3; i++) {
        p1 -> next = new ListNode(a[i]);
        p1 = p1 -> next;
    }
    for (int i = 0; i < 1; i++) {
        p2 -> next = new ListNode(b[i]);
        p2 = p2 -> next;
    }
    
    test(l1.next, l2.next);

    ListNode l3(0);
    ListNode* p3 = &l3;
    ListNode l4(0);
    ListNode* p4 = &l4;
    int c[] = {4, 5, 9};
    int d[] = {6, 8, 7, 3};
    for (int i = 0; i < 3; i++) {
        p3 -> next = new ListNode(c[i]);
        p3 = p3 -> next;
    }
    for (int i = 0; i < 4; i++) {
        p4 -> next = new ListNode(d[i]);
        p4 = p4 -> next;
    }
    
    test(l3.next, l4.next);

    cout << "press enter to continue" << endl;
    cin.get();
    
    return 0;
}