#include <bits/stdc++.h>

using namespace std;





/* --------------------------------------------------------- MACROES - START --------------------------------------------------------- */
#define ERR_EMPTY       "List is empty !"
#define ERR_VAL         "Value is invalid !"
#define ERR_DUPLICATED  "No conversion !"

/* --------------------------------------------------------- MACROES - END ----------------------------------------------------------- */





/* ----------------------------------------------------- DATA STRUCTS - START -------------------------------------------------------- */
struct node {
    int data;
    node *next;

    node(int value) {
        data = value;
        next = NULL;
    }
};



struct singList {
    node *head;
    int numOfNodes;
};
/* ----------------------------------------------------- DATA STRUCTS - END ---------------------------------------------------------- */





/* ------------------------------------------------------ PROTOTYPE - START ---------------------------------------------------------- */
/**
 * @brief create a new list
 * 
 * @param nums - the number of nodes
 * @return singList* 
 */
singList *createList(int nums);    



/**
 * @brief print all nodes of list
 * 
 * @param list 
 */
void printList(singList *list);



/**
 * @brief insert new node at any position
 * 
 * @param list 
 * @param pos - postion of new node
 * @param data - data of new node
 */
void insertAt(singList *list, int pos, int data);



/**
 * @brief delete node at any position
 * 
 * @param list 
 * @param pos - positon of node to be deleted
 */
void deleteAt(singList *list, int pos);



/**
 * @brief print data of any nodes
 * 
 * @param list 
 * @param pos - position of node to be printed
 */
void printElement(singList *list, int pos);



/**
 * @brief convert old data to new data for list
 * 
 * @param list 
 * @param oldData 
 * @param newData 
 */
void convert(singList *list, int oldData, int newData);



/**
 * @brief delete node whose data is greater than threshold
 * 
 * @param list 
 * @param threshold 
 */
void deleteDataGrtThThres(singList *list, int threshold);



/**
 * @brief union list should include all the distinct elements only of 2 linked lists and should be sorted in ascending order
 * 
 * https://practice.geeksforgeeks.org/problems/union-of-two-linked-list/1?page=1&sprint=83b2c7d1bddb3959499090546f7b6843&sortBy=submissions
 * 
 * @param list1 
 * @param list2 
 * @return singList* 
 */
singList* makeUnion(singList* list1, singList* list2);



/**
 * @brief reverse every k nodes in the linked list. 
 * If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed
 * 
 * https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1?page=1&sprint=83b2c7d1bddb3959499090546f7b6843&sortBy=submissions
 * 
 * @param list 
 * @param k - k nodes to be reversed
 * @return singList* 
 */
singList *reverse(singList* list, int k);



/**
 * @brief remove duplicate elements from this unsorted Linked List. 
 * 
 * https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1?page=1&sprint=83b2c7d1bddb3959499090546f7b6843&sortBy=submissions
 * 
 * @param list 
 * @return singList* 
 */
singList *removeDuplicates(singList *list); 



/**
 * @brief ascending sorting
 * 
 * https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
 * 
 * @param list 
 */
void ascendingSort(singList *list);
/* ------------------------------------------------------- PROTOTYPE - END ----------------------------------------------------------- */





/* --------------------------------------------------------- FUNCTIONS - START ------------------------------------------------------- */
singList *createList(int nums) 
{           
    singList *list = new singList; 
    list->head = NULL;
    list->numOfNodes = nums;

    try {
        if (nums < 1)
            throw ERR_VAL;

        node *p;   
        int data;

        for (int i = 0; i < nums; i++) {
            cout << "Enter data of node: ";
            cin >> data;

            if (list->head == NULL) {
                list->head = new node(data);
                p = list->head;
            }
            else {
                p->next = new node(data);
                p = p->next;
            }
        }  
    }

    catch (char const *exc) {
        cout << exc << endl;
    }

    return list;
}



void printList(singList *list) 
{
    try {
        if (list == NULL)
            throw ERR_EMPTY;
        
	    node *p = list->head;
        cout << "List includes " << list->numOfNodes << (list->numOfNodes == 1 ? " node: " : " nodes: ");

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



void insertAt(singList *list, int pos, int data) 
{    
    try {
        if (list == NULL)
            throw ERR_EMPTY;

        if ((pos < 0) || (pos > list->numOfNodes))
            throw ERR_VAL;

        node *p = list->head;
        node *temp = new node(data);        // new node

        if (pos == 0) {                     // head of list
            temp->next = p;
            list->head = temp;
        }
        else {                              // other positions
            for (int i = 1; i < pos; i++)
                p = p->next;                // pointer is in front of the position to be inserted
            temp->next = p->next;
            p->next = temp;
        }

        list->numOfNodes++;                 // increase the number of nodes
    }

    catch (char const *exc) {
        cout << exc << endl;
    }
}



void deleteAt(singList *list, int pos) 
{
    try {
        if (list == NULL)
            throw ERR_EMPTY;

        if (pos < 0 || pos >= list->numOfNodes)
            throw ERR_VAL;

        node *p = list->head;

        if (pos == 0)                           // head of list
            list->head = p->next;
        else {
            for (int i = 1; i < pos; i++)
                p = p->next;
            node *temp = p->next;               // node will be deleted
            p->next = temp->next;
            delete temp; 
        } 

        list->numOfNodes--;                     // decrease the number of nodes
    }

    catch (char const *exc) {
        cout << exc << endl;
    }     
}



void printElement(singList *list, int pos) 
{
    try {
        if (list == NULL)
            throw ERR_EMPTY;

        if (pos < 0 || pos >= list->numOfNodes)
            throw ERR_VAL;

        node *p = list->head;

        for (int i = 0; i < pos; i++)
            p = p->next;
        cout << "Data of node: " << p->data << endl;
    }

    catch (char const *exc) {
        cout << exc << endl;
    } 
}



void convert(singList *list, int oldData, int newData) 
{ 
    try {
        if (list == NULL)
            throw ERR_EMPTY;

        if (oldData == newData)
            throw ERR_DUPLICATED;

        node *p = list->head;

        while (p != NULL) {
            if (p->data == oldData)
                p->data = newData;
            p = p->next;
        }
    }

    catch (char const *exc) {
        cout << exc << endl;
    } 
}



void deleteDataGrtThThres(singList *list, int threshold) 
{      
    try {
        if (list == NULL)
            throw ERR_EMPTY;

        node *p = list->head;

        for (int i = 0; i < list->numOfNodes; i++) {
            if (p->data > threshold) {
                p = p->next;
                deleteAt(list, i--);
            }
            else
                p = p->next;
        }
    }

    catch (char const *exc) {
        cout << exc << endl;
    }
}



singList* makeUnion(struct singList* list1, struct singList* list2)
{
    try {
        if (list1 == NULL || list2 == NULL)
            throw ERR_EMPTY;

        singList *Unique = new singList;
        node *p;
        vector<int> bothLists, uniqueArr;
        int i;
        
        p = list1->head;                                 // bothLists includes all nodes of both lists
        while (p) {
            bothLists.push_back(p->data);
            p = p->next;
        }       
        p = list2->head;
        while (p) {
            bothLists.push_back(p->data);
            p = p->next;
        }
        
        sort(bothLists.begin(), bothLists.end());       // ascending sorting
        
        for (i = 0; i < bothLists.size(); i++)          // create array containing unique nodes
            if (i == 0 || bothLists[i] != bothLists[i-1])
                uniqueArr.push_back(bothLists[i]);
        
        Unique->numOfNodes = uniqueArr.size();
        Unique->head = NULL;

        for (i = 0; i < uniqueArr.size(); i++) {
            if (Unique->head == NULL) {
                Unique->head = new node(uniqueArr[0]);
                p = Unique->head;
            }
            else {
                p->next = new node(uniqueArr[i]);
                p = p->next;
            }
        }
        
        return Unique;
    }

    catch (char const *exc) {
        cout << exc << endl;
    } 
}



singList *reverse(singList* list, int k) 
{
    try {
        if (list == NULL)
            throw ERR_EMPTY;

        if (k < 1)
            throw ERR_VAL;

        singList *rev = new singList;
        rev->head = NULL;
        rev->numOfNodes = list->numOfNodes;

        node *p = list->head, *p1;
        stack<int> Data;
        int i;
        
        while (p != NULL) {
            for (i = 0; i < k; i++) {               // push k nodes to stack to reverse
                Data.push(p->data);
                p = p->next;
                if (p == NULL)                      // traversed to the end of list
                    break;
            }
            
            while (!Data.empty()) {                 // pop data and handle
                if (rev->head == NULL) {            // init
                    rev->head = new node(Data.top());
                    p1 = rev->head;
                }
                else {
                    p1->next = new node(Data.top());
                    p1 = p1->next;
                }
                Data.pop();
            }
        }
        
        return rev;
    }

    catch (char const *exc) {
        cout << exc << endl;
    }
}



singList *removeDuplicates(singList *list)
{
    try {
        if (list == NULL)
            throw ERR_EMPTY;

        singList *nonDuplicate = new singList;
        nonDuplicate->head = NULL;
        nonDuplicate->numOfNodes = 0;

        node *p = list->head, *p1;  
        unordered_map<int, int> mp;                     
        
        while (p != NULL) {
            if (mp.find(p->data) == mp.end()) {         // if node is not appeared yet
                mp[p->data] = 1;                        // mark appearance
                
                if (nonDuplicate->head == NULL) {       // add this node to non-duplicate list
                    nonDuplicate->head = new node(p->data);
                    p1 = nonDuplicate->head;
                }
                else {
                    p1->next = new node(p->data);
                    p1 = p1->next;
                }

                nonDuplicate->numOfNodes++;
            }
            
            p = p->next;                                // traverse original list
        }
        
        return nonDuplicate;
    }

    catch (char const *exc) {
        cout << exc << endl;
    }
}



void ascendingSort(singList *list) {
    try {
        if (list == NULL)
            throw ERR_EMPTY;

        node *p = list->head; 
        vector<int> nodes;
        
        while (p != NULL) {                 // push data of nodes into vector to sort
            nodes.push_back(p->data);
            p = p->next;
        }
        
        sort(nodes.begin(), nodes.end());
        
        p = list->head;
        for (int data : nodes) {            // push data of nodes back into list after sorting
            p->data = data;
            p = p->next;
        }
    }

    catch (char const *exc) {
        cout << exc << endl;
    }
}
/* --------------------------------------------------------- FUNCTIONS - END ------------------------------------------------------- */