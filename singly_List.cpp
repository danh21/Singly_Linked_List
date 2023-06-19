#include <iostream>
using namespace std;



#define ERR_NUMS        "The number of nodes is out of range !"
#define ERR_EMPTY       "List is empty !"
#define ERR_POS         "Position is out of range !"
#define ERR_DUPLICATED  "No conversion !"



struct node {
    int data;
    node *next;
};

struct singList {
    int numOfNodes;
    node *head;
};



node *createNode(int data) {
    node *temp = new node;
    temp->next = NULL; 
    temp->data = data;
    return temp;
}



node *addElement(node *p, int data) {
    node *temp = createNode(data);
    p->next = temp;                 // add node at the end of list
    return temp;                    // return new node
}



singList *createList(int n) {
    singList *list = new singList; 
    list->numOfNodes = n;

    try {
        if (n < 1)
            throw ERR_NUMS;

        node *p;   
        int data;

        for (int i = 0; i < n; i++) {
            cout << "Enter data of node: ";
            cin >> data;
            if (i == 0) {
                list->head = createNode(data);
                p = list->head;
            }
            else
                p = addElement(p, data);
        }  
    }

    catch (char const *exc) {
        cout << exc << endl;
        list->head = NULL;
    }

    return list;
}



void printList(singList *list) {
	node *p = list->head;

    try {
        if (p == NULL)
            throw ERR_EMPTY;
        
        cout << "List includes " << list->numOfNodes << " nodes: ";
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    catch (char const *exc) {
        cout << exc << endl;
    }
}



singList *insertAt(singList *list, int pos, int data) {    // insert new node at position
    node *p = list->head;

    try {
        if (p == NULL)
            throw ERR_EMPTY;

        if ((pos < 0) || (pos > list->numOfNodes))
            throw ERR_POS;

        node *temp = new node;  // new node
        temp->data = data;

        if (pos == 0) {         // first node
            temp->next = p;
            list->head = temp;
        }
        else {
            for (int i = 1; i < pos; i++)
                p = p->next;
            temp->next = p->next;
            p->next = temp;
        }

        list->numOfNodes++;
    }

    catch (char const *exc) {
        cout << exc << endl;
    }

    return list;
}



singList *deleteAt(singList *list, int pos) {
    node *p = list->head;

    try {
        if (p == NULL)
            throw ERR_EMPTY;

        if (pos < 0 || pos >= list->numOfNodes)
            throw ERR_POS;

        if (pos == 0)
            list->head = p->next;
        else {
            for (int i = 1; i < pos; i++)
                p = p->next;
            node *temp = p->next;       // node will be deleted
            p->next = temp->next;
            delete(temp); 
        } 

        list->numOfNodes--; 
    }

    catch (char const *exc) {
        cout << exc << endl;
    }     

    return list;
}



void printElement(singList *list, int pos) {
	node *p = list->head;

    try {
        if (p == NULL)
            throw ERR_EMPTY;

        if (pos < 0 || pos >= list->numOfNodes)
            throw ERR_POS;

        for (int i = 0; i < pos; i++)
            p = p->next;
        cout << "Data of this node: " << p->data << endl;
    }

    catch (char const *exc) {
        cout << exc << endl;
    } 
}



singList *convert(singList *list, int oldData, int newData) {  // convert oldData to newData
    node *p = list->head;

    try {
        if (p == NULL)
            throw ERR_EMPTY;

        if (oldData == newData)
            throw ERR_DUPLICATED;

        while (p != NULL) {
            if (p->data == oldData)
                p->data = newData;
            p = p->next;
        }
    }

    catch (char const *exc) {
        cout << exc << endl;
    } 

    return list;
}



singList *deleteDataGrtThThres(singList *list, int threshold) {       // delete node whose data is greater than threshold
    node *p = list->head;

    try {
        if (p == NULL)
            throw ERR_EMPTY;

        for (int i = 0; i < list->numOfNodes; i++) {
            if (p->data > threshold) {
                p = p->next;
                list = deleteAt(list, i--);
            }
            else
                p = p->next;
        }
    }

    catch (char const *exc) {
        cout << exc << endl;
    } 

    return list;
}



int main() {    
    int n, data, pos, thres, oldData, newData, opt;
    singList *list;

    cout << "Enter the number of nodes: ";
    cin >> n;
    list = createList(n);   

    while (1) {
        cout << "MENU: " << endl;
        cout << "0. Quit" << endl;
        cout << "1. Display list" << endl;
        cout << "2. Insert node" << endl;
        cout << "3. Delete node" << endl;
        cout << "4. Print node" << endl;
        cout << "5. Convert data of node" << endl;
        cout << "6. Delete node whose data is greater than threshold" << endl;
        cout << "Enter your option: ";
        cin >> opt;

        switch (opt)
        {
            case 0:
                return 0;
            case 1:
                printList(list);
                break;
            case 2:
                cout << "Enter the position: ";
                cin >> pos;
                cout << "Enter data: ";
                cin >> data;
                list = insertAt(list, pos, data);
                break;
            case 3:
                cout << "Enter the position: ";
                cin >> pos;
                list = deleteAt(list, pos);
                break;
            case 4:
                cout << "Enter the position: ";
                cin >> pos;
                printElement(list, pos);
                break;
            case 5:
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data to replace: ";
                cin >> newData;
                list = convert(list, oldData, newData);
                break;
            case 6:
                cout << "Enter the threshold to delete node whose data is greater than threshold: ";
                cin >> thres;
                list = deleteDataGrtThThres(list, thres);
                break;
            default:
                cout << "Invalid option !" << endl;
                break;
        }
    }

    return 0;
}