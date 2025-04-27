#include <iostream>
using namespace std;

template <typename T>
class CircularDoublyLinkedList{
private:
    struct Node{
        T data;
        Node* next;
        Node* prev;
        Node(T value){
            data = value;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;
    int count;

public:
    CircularDoublyLinkedList(){
        head = nullptr;
        count = 0;
    }


    T front(){
        if (empty()){
            cout << "La lista esta vacia" << endl;
            return T();
        }
        return head->data;
    }


    T back(){
        if (empty()){
            cout << "La lista esta vacia" << endl;
            return T();
        }
        return head->prev->data;
    }


    void push_front(T value){
        Node* newNode = new Node(value);
        if (empty()){
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        } else{
            Node* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
        }
        count++;
    }


    void push_back(T value){
        Node* newNode = new Node(value);
        if (empty()){
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        } else{
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
        count++;
    }


    T pop_front(){
        if (empty()){
            cout << "La lista esta vacia" << endl;
            return T();
        }

        T value = head->data;

        if (count == 1){
            delete head;
            head = nullptr;
        } else{
            Node* tail = head->prev;
            Node* temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
        }
        count--;
        return value;
    }


    T pop_back(){
        if (empty()){
            cout << "La lista esta vacia" << endl;
            return T();
        }

        Node* tail = head->prev;
        T value = tail->data;

        if (count == 1){
            delete head;
            head = nullptr;
        } else{
            Node* newTail = tail->prev;
            newTail->next = head;
            head->prev = newTail;
            delete tail;
        }
        count--;
        return value;
    }


    void insert(T value, int position){
        if (position < 0 || position > count){
            cout << "Posicion invalida." << endl;
            return;
        }

        if (position == 0){
            push_front(value);
        } else if (position == count){
            push_back(value);
        } else{
            Node* newNode = new Node(value);
            Node* current = head;
            for (int i = 0; i < position; i++){
                current = current->next;
            }
            Node* previous = current->prev;
            previous->next = newNode;
            newNode->prev = previous;
            newNode->next = current;
            current->prev = newNode;
            count++;
        }
    }


    void remove(int position){
        if (position < 0 || position >= count){
            cout << "Posicion invalida." << endl;
            return;
        }

        if (position == 0){
            pop_front();
        } else if (position == count - 1){
            pop_back();
        } else{
            Node* current = head;
            for (int i = 0; i < position; i++){
                current = current->next;
            }
            Node* previous = current->prev;
            Node* nextNode = current->next;
            previous->next = nextNode;
            nextNode->prev = previous;
            delete current;
            count--;
        }
    }


    bool empty(){
        return head == nullptr;
    }


    int size(){
        return count;
    }


    void clear(){
        while (!empty()){
            pop_front();
        }
    }

    void reverse() {
        if (empty() || count == 1){
            return;
        }
    
        Node* current = head;
        Node* temp = nullptr;
        int numNodes = count;
    
        for (int i = 0; i < numNodes; i++){
            temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = temp;
        }
    
        head = head->prev; 
    }
};
