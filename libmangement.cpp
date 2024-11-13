#include <iostream>

#include<string>
    using namespace std;
    struct node
    {
        int id;
        string name;
        float price;
        struct node *next;
    };
    
    node* head=0;
    void insert_first()
    {
        node* newnode = new node;
        cout << "Enter the id:";
        cin >> newnode->id;
        cout << "Enter the book name:";
        cin >> newnode->name;
        cout << "Enter the book price:";
        cin >> newnode->price;
        newnode->next = head;
        head = newnode;
        cout<<"Book is added at first position"<<endl;
    }

    void insert_last()
    {
        node* newnode = new node;
        cout << "Enter the id:";
        cin >> newnode->id;
        cout << "Enter the book name:";
        cin >> newnode->name;
        cout << "Enter the book price:";
        cin >> newnode->price;
        node* temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = 0;
        cout<<"Book is added at last position"<<endl;
    }

    void insert_at_position()
    {
        int pos = 0, count = 0, i=0;

        cout << "Enter the position where you want to add :";
        cin >> pos;
        node* temp = head;
        while (temp != 0)
        {
            temp = temp->next;
            count++;
        }
        if (pos > count)
        {
            cout << "Invalid Position" << endl;
        }
        else
        {
            temp = head;
            while (pos < 0 || pos > count)
            {
                temp = temp->next;
                i++;
            }
        }
        node* newnode = new node;
        cout << "Enter the id:";
        cin >> newnode->id;
        cout << "Enter the book name:";
        cin >> newnode->name;
        cout << "Enter the book price:";
        cin >> newnode->price;

        temp = head;
        for (int i = 0; i < pos - 1; i++)
        { 
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        cout << "Book is added at "<<pos<< " position" << endl;
    }

    void display()
    {
        node* temp = head;
        cout<<"Id\tName\tPrice"<<endl;
        while (temp != 0)
        {
            cout << temp->id << "\t" << temp->name << "\t" << temp->price<<endl;
            temp = temp->next;
        }
    }

    void delete_first()
    {
        if (head == 0)
        {
            cout << "list is empty" << endl;
        }
        else
        {
            node* temp = head;
            head = head->next;
            delete temp;
            cout<<"Book is deleted at first position"<<endl;
        }
    }
    void delete_last()
    {
        struct node *prenode;
        node* temp = head;
        while (temp->next != 0)
        {
            prenode = temp;
            temp = temp->next;
        }
        prenode->next = 0;
        delete temp;
        cout << "Book is deleted at last position" << endl;
    }

    void delete_at_position()
    {
        struct node *nextnode;
        int pos=0, i, count = 0;
        node* temp = head;
        cout << "Enter the position where you want to add :";
        cin >> pos;
        while (temp != 0)
        {
            temp = temp->next;
            count++;
        }
        if (pos > count)
        {
            cout << "Invalid Position" << endl;
        }
        else
        {
            temp = head;
            while (i < pos)
            {
                temp = temp->next;
                i++;
            }
        }
        temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        nextnode = temp->next;
        temp->next = nextnode->next;
        delete nextnode;
        cout << "Book is deleted at " << pos << "position" << endl;
    }

    int main()
    {
        int ch, k, n;
        cout << "Enter the size of Books you want:";
        cin >> n;
        do
        {
            cout << "Menu\n1.Insert at first\n2.Insert at last\n3.Insert at position\n4.Delete at first\n5.Delete at last\n6.Delete at position\n7.Display\nExite\nEnter your choice:";
            cin >> ch;
            switch (ch)
            {
            case 1:
                insert_first();
                break;
            case 2:
                insert_last();
                break;
            case 3:
                insert_at_position();
                break;
            case 4:
                delete_first();
                break;
            case 5:
                delete_last();
                break;
            case 6:
                delete_at_position();
                break;
            case 7:
                display();
                break;
            case 8:
            default:
                cout << "Wrong choice" << endl;
            }
            cout << "if you want to continue enter 1:";
            cin >> k;

        } while (k == 1);
    }

