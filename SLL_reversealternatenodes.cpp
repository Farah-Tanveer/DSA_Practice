void reverseAlternateNodes() {
        if (head == NULL || head->next == NULL) {
            cout << "List has less than 2 nodes\n";
            return;
        }
        
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        int count = 0;
        
        while (curr != NULL) {
            if (count % 2 == 0) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            } else {
                prev = curr;
                curr = curr->next;
            }
            count++;
        }
        
        head = prev;
        cout << "Reversed alternate nodes\n";
    }