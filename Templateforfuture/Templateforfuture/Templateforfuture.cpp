#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;
template <typename T> class Item
{
public:
    T data;
    Item<T>* next;
    Item() {
        next = NULL;
        //previous = NULL;
        data = 0;
    }
    Item(T value) {
        this->data = value;
    }
};
template <class T> class LinkedList {
    Item<T>* head;
    Item<T>* tail;
    int length;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
        length = 0;
    }
    LinkedList(T* data, int count) {
        head = NULL;
        tail = NULL;
        length = 0;
        for (int i = 0; i < count; i++) {
            Append(data[i]);
        }
        length = count;
    }
    void Append(T value) {
        if (head == NULL) {
            head = new Item<T>; 
            head->data = value; 
            tail = head; 
            length++;
        }
        else
        {
            Item<T>* temp = new Item<T>;
            temp->data = value;
            tail->next = temp;
            tail = temp;
            length++;
        }


    }
    void Resize(int x) {
        this->length = x;
    }
    T GetFirst() {
        return head->data;
    }
    T Get(int index) {

        assert(index >= 0);
        assert(index <= this->GetLength());
        Item<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }
    T GetLast() {
        return tail->data;
    }
    int GetLength() {
        return this->length;
    }
    void Set(int index, T value) {
        assert(index >= 0);
        assert(index <= this->GetLength());
        Item<T>* buf = head;
        for (int i = 0; i < index; i++)
            buf = buf->next;
        buf->data = value;
    }
    void Remove(int n) {
        if (n != 0 ) {
            Item<T>* buf = head;
            for (int i = 0; i < n - 1; i++)
                buf = buf->next;
            Item<T>* temp1 = buf->next->next;
            delete buf->next;
            buf->next = temp1;
            length = length - 1;
        }
        else {
            Item<T>* buf = head;
            head = head->next;
            delete buf;
            length = length - 1;
        }
    }
    void Print() {
        cout << "Length " << this->GetLength()<<"\n";
        cout << "===================================\n";
            for (int i = 0; i < length; i++) {
                cout << "---------------------------\n";
                cout << i+1 << " Data \n" << this->Get(i) << "\n";
            }
    }
};
template <class T> class Menu {
private:
    LinkedList<T> data;
public:
    Menu() {
    }
    void FunctionMenu(T x) {
        int o = -1;
        while (o!=3)
        {
            cout << "What do you want:\n1.F1\n2.F2\n3.Exit\n";
            cin >> o;
            switch (o)
            {
            case 1: {
                cout << "First Function\n";
                break;
            }
            case 2: {
                cout << "Second Function\n";
                break;
            }
            case 3: {
                break;
            }
            default:
                break;
            }
        }
    }
    void GrandMenu() {
        cout << "Enter data\n";
        T x;
        cin >> x;
        int usrch = -1;
        while (usrch!=6) {
            cout << "What do you want?\n1.Save into the end of list\n2.Print all data\n3.Rewrite a cell\n4.Remove a cell\n5.Manipulations with entered data\n6.Exit\n";
            cin >> usrch;
            switch (usrch)
            {
            case 1: {
                cout << "Saving\n";
                data.Append(x);
                break;
            }
            case 2: {
                data.Print();
                break;
            }
            case 3: {
                cout << "What cell do you want to rewrite?\n";
                int i;
                cin >> i;
                while (i < 0) {
                    cout << "Your number is to small. Please, rewrite your number >=0\n";
                    cin >> i;
                }
                T newx;
                cin >> newx;
                data.Set(i, newx);
                break;
            }
            case 4: {cout << "What cell do you want to remove?\n";
                int i;
                cin >> i;
                while (i < 0) {
                    cout << "Your number is to small. Please, rewrite your number >=0\n";
                    cin >> i;
                }
                data.Remove(i-1);
                break;
            }
            case 5: {
                cout << "Do you whant manipulate:\n1.The entered data\n2.Data from your list\n";
                T l;
                int a = 0;
                cin >> a;
                if (a == 1)
                    l = x;
                if (a == 2) {
                    data.Print();
                    cout << "Which data do you whant?\n";
                    int r;
                    cin>>r;
                    l = data.Get(r - 1);
                }
                this->FunctionMenu(l);
                break;
            }
            case 6: {
                break;
            }
            default:
                break;
            }

        }
    }

};

int main()
{
    Menu <int> X;
}
