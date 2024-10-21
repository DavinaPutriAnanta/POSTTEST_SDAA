#include <bits/stdc++.h>
#include <math.h>
using namespace std;

struct Workout {
    string name;
    string category;
    int duration; 
    Workout *next;
};

struct StackNode {
    Workout *workout;
    StackNode *next;
};

struct QueueNode {
    Workout *workout;
    QueueNode *next;
};
StackNode *top = nullptr;

void push(Workout *workout) {
    StackNode *newNode = new StackNode;
    newNode->workout = workout;
    newNode->next = top;
    top = newNode;
}

Workout *pop() {
    if (top == nullptr) {
        cout << "Stack is empty!" << endl;
        return nullptr;
    }
    StackNode *temp = top;
    Workout *poppedWorkout = temp->workout;
    top = top->next;
    delete temp;
    return poppedWorkout;
}

void displayStack() {
    StackNode *temp = top;
    while (temp != nullptr) {
        cout << temp->workout->name << " | " << temp->workout->category << " | " << temp->workout->duration << " minutes" << endl;
        temp = temp->next;
    }
}
QueueNode *front = nullptr;
QueueNode *rear = nullptr;

void enqueue(Workout *workout) {
    QueueNode *newNode = new QueueNode;
    newNode->workout = workout;
    newNode->next = nullptr;
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

Workout *dequeue() {
    if (front == nullptr) {
        cout << "Queue is empty!" << endl;
        return nullptr;
    }
    QueueNode *temp = front;
    Workout *dequeuedWorkout = temp->workout;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    return dequeuedWorkout;
}

void displayQueue() {
    QueueNode *temp = front;
    while (temp != nullptr) {
        cout << temp->workout->name << " | " << temp->workout->category << " | " << temp->workout->duration << " minutes" << endl;
        temp = temp->next;
    }
}
void addWorkout(Workout **head, string name, string category, int duration) {
    Workout *newWorkout = new Workout;
    newWorkout->name = name;
    newWorkout->category = category;
    newWorkout->duration = duration;
    newWorkout->next = *head;
    *head = newWorkout;
}

void editWorkout(Workout *head, string oldName, string newName, string newCategory, int newDuration) {
    Workout *temp = head;
    while (temp != nullptr) {
        if (temp->name == oldName) {
            temp->name = newName;
            temp->category = newCategory;
            temp->duration = newDuration;
            return;
        }
        temp = temp->next;
    }
    cout << "Workout not found!" << endl;
}

void deleteWorkout(Workout **head, string name) {
    Workout *temp = *head;
    Workout *prev = nullptr;

    if (temp != nullptr && temp->name == name) {
        *head = temp->next;
        delete temp;
        return;
    }

    while (temp != nullptr && temp->name != name) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Workout not found!" << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
}

int getLength(Workout *head) {
    int count = 0;
    Workout *temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void displayWorkouts(Workout *head) {
    while (head != nullptr) {
        cout << head->name << " | " << head->category << " | " << head->duration << " minutes" << endl;
        head = head->next;
    }
    cout << endl;
}
int fibMonaccianSearch(Workout *head, int x, int n) {
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;
    Workout *temp = head;

    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;
    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);
        temp = head;
        for (int j = 0; j < i; j++) {
            temp = temp->next;
        }

        if (temp->duration < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (temp->duration > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else {
            return i;
        }
    }

    temp = head;
    for (int j = 0; j < offset + 1; j++) {
        temp = temp->next;
    }

    if (fibMMm1 && temp->duration == x) {
        return offset + 1;
    }

    return -1;
}
int jumpSearch(Workout *head, int x, int n) {
    int step = sqrt(n);
    int prev = 0;
    Workout *temp = head;

    while (temp != nullptr && temp->duration < x) {
        prev = step;
        step += sqrt(n);

        for (int i = 0; i < step && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (prev >= n) {
            return -1;
        }
    }

    temp = head;
    for (int i = 0; i < prev && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp != nullptr && temp->duration == x) {
        return prev;
    }

    return -1;
}
const int NO_OF_CHARS = 256;
void badCharHeuristic(string str, int size, int badChar[NO_OF_CHARS]) {
    for (int i = 0; i < NO_OF_CHARS; i++) {
        badChar[i] = -1;
    }
    for (int i = 0; i < size; i++) {
        badChar[(int)str[i]] = i;
    }
}

void search(Workout *head, string pat) {
    int m = pat.size();
    Workout *temp = head;

    while (temp != nullptr) {
        int n = temp->name.size();
        int badChar[NO_OF_CHARS];
        badCharHeuristic(pat, m, badChar);
        int s = 0;

        while (s <= (n - m)) {
            int j = m - 1;

            while (j >= 0 && pat[j] == temp->name[s + j]) {
                j--;
            }

            if (j < 0) {
                cout << temp->name << endl;
                break;
            } else {
                s += max(1, j - badChar[temp->name[s + j]]);
            }
        }
        temp = temp->next;
    }
}
void merge(Workout **headRef, Workout *left, Workout *right) {
    Workout dummy;
    Workout *tail = &dummy;
    dummy.next = nullptr;

    while (left != nullptr && right != nullptr) {
        if (left->duration <= right->duration) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }
    tail->next = (left == nullptr) ? right : left;
    *headRef = dummy.next;
}

void split(Workout *source, Workout **frontRef, Workout **backRef) {
    Workout *fast = source->next;
    Workout *slow = source;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
}

void mergeSort(Workout **headRef) {
    if (*headRef == nullptr || (*headRef)->next == nullptr) {
        return;
    }

    Workout *head = *headRef;
    Workout *a;
    Workout *b;

    split(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    merge(headRef, a, b);
}

Workout *getTail(Workout *cur) {
    while (cur != nullptr && cur->next != nullptr) {
        cur = cur->next;
    }
    return cur;
}

Workout *partition(Workout *head, Workout *end, Workout **newHead, Workout **newEnd) {
    Workout *pivot = end;
    Workout *prev = nullptr;
    Workout *cur = head;
    Workout *tail = pivot;

    while (cur != pivot) {
        if (cur->duration < pivot->duration) {
            if ((*newHead) == nullptr) {
                (*newHead) = cur;
            }
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) {
                prev->next = cur->next;
            }
            Workout *temp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }

    if ((*newHead) == nullptr) {
        (*newHead) = pivot;
    }

    (*newEnd) = tail;
    return pivot;
}

Workout *quickSortRecur(Workout *head, Workout *end) {
    if (!head || head == end) {
        return head;
    }

    Workout *newHead = nullptr;
    Workout *newEnd = nullptr;

    Workout *pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Workout *temp = newHead;
        while (temp->next != pivot) {
            temp = temp->next;
        }
        temp->next = nullptr;

        newHead = quickSortRecur(newHead, temp);
        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}

void quickSort(Workout **headRef) {
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
}

int main() {
    int choice, duration;
    string name, category, searchName;
    Workout *head = nullptr;

    addWorkout(&head, "Cardio", "Endurance", 30);
    addWorkout(&head, "Squat", "Strength", 45);
    addWorkout(&head, "Yoga", "Flexibility", 60);

    while (true) {
        cout << "\nMenu\n";
        cout << "1. Add Workout\n";
        cout << "2. Edit Workout\n";
        cout << "3. Delete Workout\n";
        cout << "4. Display Workouts\n";
        cout << "5. Push to Stack\n";
        cout << "6. Pop from Stack\n";
        cout << "7. Enqueue to Queue\n";
        cout << "8. Dequeue from Queue\n";
        cout << "9. Merge Sort (Ascending)\n";
        cout << "10. Quick Sort (Descending)\n";
        cout << "11. Fibonacci Search by Duration\n";
        cout << "12. Jump Search by Duration\n";
        cout << "13. Boyer-Moore Search by Name\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter workout name: ";
                cin >> name;
                cout << "Enter category: ";
                cin >> category;
                cout << "Enter duration (minutes): ";
                cin >> duration;
                addWorkout(&head, name, category, duration);
                break;
            case 2:
                cout << "Enter workout name to edit: ";
                cin >> searchName;
                cout << "Enter new name: ";
                cin >> name;
                cout << "Enter new category: ";
                cin >> category;
                cout << "Enter new duration (minutes): ";
                cin >> duration;
                editWorkout(head, searchName, name, category, duration);
                break;
            case 3:
                cout << "Enter workout name to delete: ";
                cin >> name;
                deleteWorkout(&head, name);
                break;
            case 4:
                displayWorkouts(head);
                break;
            case 5:
                cout << "Enter workout name to push to stack: ";
                cin >> name;
                push(new Workout{name, category, duration});
                break;
            case 6:
                cout << "Workout popped: " << pop()->name << endl;
                break;
            case 7:
                cout << "Enter workout name to enqueue to queue: ";
                cin >> name;
                enqueue(new Workout{name, category, duration});
                break;
            case 8:
                cout << "Workout dequeued: " << dequeue()->name << endl;
                break;
            case 9:
                mergeSort(&head);
                displayWorkouts(head);
                break;
            case 10:
                quickSort(&head);
                displayWorkouts(head);
                break;
            case 11:
                cout << "Enter duration to search using Fibonacci Search: ";
                cin >> duration;
                if (fibMonaccianSearch(head, duration, getLength(head)) != -1) {
                    cout << "Workout found with duration " << duration << " minutes." << endl;
                } else {
                    cout << "Workout not found." << endl;
                }
                break;
            case 12:
                cout << "Enter duration to search using Jump Search: ";
                cin >> duration;
                if (jumpSearch(head, duration, getLength(head)) != -1) {
                    cout << "Workout found with duration " << duration << " minutes." << endl;
                } else {
                    cout << "Workout not found." << endl;
                }
                break;
            case 13:
                cout << "Enter workout name to search using Boyer-Moore: ";
                cin >> searchName;
                search(head, searchName);
                break;
        }
    }

    return 0;
}
