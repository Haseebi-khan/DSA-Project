#pragma once
#include <iostream>
#include "1UI.h"
// Doubly Linked List (DLL)

class node
{
public:
    int data;
    node *next;
    node *pre;
    node(int value = 0) : data(value), next(nullptr), pre(nullptr) {}
};

class doublyLinkedList
{
private:
    node *head, *tail;

public:
    // Constructor
    doublyLinkedList()
    {
        head = tail = nullptr;
        for (int value = 1; value <= 9; value++)
        {
            if (value == 9)
            {
                value = 0;
                node *newNode = new node(value);

                tail->next = newNode;
                newNode->pre = tail;
                tail = newNode;
                break;
            }
            else
            {

                node *newNode = new node(value);
                if (head == nullptr)
                {
                    head = tail = newNode;
                }
                else
                {
                    tail->next = newNode;
                    newNode->pre = tail;
                    tail = newNode;
                }
            }
        }
    }
    // Destructor
    ~doublyLinkedList()
    {
        while (head != nullptr)
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void Display()
    {
        if (head == nullptr)
        {
            cout << "Linked list Underflow.\n";
        }
        else
        {
            node *temp = head;
            while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};
