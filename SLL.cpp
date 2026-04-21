#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class SinglyLinkedList {
private:
    Node* head;
    
public:
    SinglyLinkedList() {
        head = NULL;
    }
    
    void insertAtBeginning(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << x << " at beginning\n";
    }
    
    void insertAtEnd(int x) {
        Node* newNode = new Node(x);
        
        if (head == NULL) {
            head = newNode;
            cout << "Inserted " << x << " at end (list was empty)\n";
            return;
        }
        
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Inserted " << x << " at end\n";
    }
    
    void insertAtPosition(int x, int pos) {
        if (pos == 1) {
            insertAtBeginning(x);
            return;
        }
        
        Node* newNode = new Node(x);
        Node* temp = head;
        
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        
        if (temp == NULL) {
            cout << "Position out of bounds\n";
            return;
        }
        
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << x << " at position " << pos << "\n";
    }
    
    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        
        Node* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from beginning\n";
        delete temp;
    }
    
    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        
        if (head->next == NULL) {
            cout << "Deleted " << head->data << " from end\n";
            delete head;
            head = NULL;
            return;
        }
        
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        
        cout << "Deleted " << temp->next->data << " from end\n";
        delete temp->next;
        temp->next = NULL;
    }
    
    void deleteAtPosition(int pos) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        
        if (pos == 1) {
            deleteAtBeginning();
            return;
        }
        
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        
        if (temp == NULL || temp->next == NULL) {
            cout << "Position out of bounds\n";
            return;
        }
        
        Node* nodeToDelete = temp->next;
        cout << "Deleted " << nodeToDelete->data << " from position " << pos << "\n";
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }
    
    bool search(int x) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == x) {
                cout << "Found " << x << " in the list\n";
                return true;
            }
            temp = temp->next;
        }
        cout << "Element " << x << " not found\n";
        return false;
    }
    
    int getLength() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    int getAt(int pos) {
        Node* temp = head;
        for (int i = 1; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }
        
        if (temp == NULL) {
            cout << "Position out of bounds\n";
            return -1;
        }
        
        return temp->data;
    }
    
    void display() {
        if (head == NULL) {
            cout << "List: [EMPTY]\n";
            return;
        }
        
        cout << "List: ";
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) {
                cout << " -> ";
            } else {
                cout << " -> NULL";
            }
            temp = temp->next;
        }
        cout << "\n";
    }
    
    void reverseIterative() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;
        cout << "List reversed (Iterative)\n";
    }
    
    void reverseRecursive() {
        reverseRecursiveHelper(head);
        cout << "List reversed (Recursive)\n";
    }
    
private:
    void reverseRecursiveHelper(Node* curr) {
        if (curr == NULL || curr->next == NULL) {
            head = curr;
            return;
        }
        
        Node* next = curr->next;
        reverseRecursiveHelper(next);
        
        next->next = curr;
        curr->next = NULL;
    }
    
public:
    bool hasCycle() {
        if (head == NULL) {
            cout << "List is empty\n";
            return false;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                cout << "Cycle detected\n";
                return true;
            }
        }
        
        cout << "No cycle found\n";
        return false;
    }
    
    int findMiddle() {
        if (head == NULL) {
            cout << "List is empty\n";
            return -1;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        cout << "Middle element: " << slow->data << "\n";
        return slow->data;
    }
    
    void removeDuplicates() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        
        Node* curr = head;
        
        while (curr != NULL && curr->next != NULL) {
            if (curr->data == curr->next->data) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
        
        cout << "Duplicates removed\n";
    }
    
    void mergeSorted(SinglyLinkedList& other) {
        SinglyLinkedList result;
        Node* temp1 = head;
        Node* temp2 = other.head;
        
        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->data <= temp2->data) {
                result.insertAtEnd(temp1->data);
                temp1 = temp1->next;
            } else {
                result.insertAtEnd(temp2->data);
                temp2 = temp2->next;
            }
        }
        
        while (temp1 != NULL) {
            result.insertAtEnd(temp1->data);
            temp1 = temp1->next;
        }
        
        while (temp2 != NULL) {
            result.insertAtEnd(temp2->data);
            temp2 = temp2->next;
        }
        
        head = result.head;
        cout << "Lists merged\n";
    }
    
    bool isPalindrome() {
        if (head == NULL || head->next == NULL) {
            cout << "Is palindrome\n";
            return true;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* secondHalf = slow;
        Node* firstHalfEnd = slow;
        
        Node* prev = NULL;
        Node* curr = secondHalf;
        Node* next = NULL;
        
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        Node* ptr1 = head;
        Node* ptr2 = prev;
        
        while (ptr1 != NULL && ptr2 != NULL) {
            if (ptr1->data != ptr2->data) {
                cout << "Not a palindrome\n";
                return false;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        cout << "Is palindrome\n";
        return true;
    }
    
    void deleteAll() {
        Node* temp = head;
        while (temp != NULL) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = NULL;
        cout << "List deleted\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, data, pos;
    
    while (true) {
        cout << "\nSingly Linked List Operations\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Search\n";
        cout << "8. Display\n";
        cout << "9. Get Length\n";
        cout << "10. Get Element at Position\n";
        cout << "11. Reverse (Iterative)\n";
        cout << "12. Reverse (Recursive)\n";
        cout << "13. Detect Cycle\n";
        cout << "14. Find Middle\n";
        cout << "15. Remove Duplicates\n";
        cout << "16. Check Palindrome\n";
        cout << "17. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                list.insertAtBeginning(data);
                break;
                
            case 2:
                cout << "Enter data: ";
                cin >> data;
                list.insertAtEnd(data);
                break;
                
            case 3:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter position: ";
                cin >> pos;
                list.insertAtPosition(data, pos);
                break;
                
            case 4:
                list.deleteAtBeginning();
                break;
                
            case 5:
                list.deleteAtEnd();
                break;
                
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                list.deleteAtPosition(pos);
                break;
                
            case 7:
                cout << "Enter element to search: ";
                cin >> data;
                list.search(data);
                break;
                
            case 8:
                list.display();
                break;
                
            case 9:
                cout << "Length: " << list.getLength() << "\n";
                break;
                
            case 10:
                cout << "Enter position: ";
                cin >> pos;
                cout << "Element at position " << pos << ": " << list.getAt(pos) << "\n";
                break;
                
            case 11:
                list.reverseIterative();
                list.display();
                break;
                
            case 12:
                list.reverseRecursive();
                list.display();
                break;
                
            case 13:
                list.hasCycle();
                break;
                
            case 14:
                list.findMiddle();
                break;
                
            case 15:
                list.removeDuplicates();
                list.display();
                break;
                
            case 16:
                list.isPalindrome();
                break;
                
            case 17:
                list.deleteAll();
                cout << "Exiting...\n";
                return 0;
                
            default:
                cout << "Invalid choice\n";
        }
    }
    
    return 0;
}