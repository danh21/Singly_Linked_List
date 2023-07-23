#include <bits/stdc++.h>
#include "singly_List.h"

using namespace std;



int main() {    
    int n, k, data, pos, thres, oldData, newData, opt, isQuit = 0;
    singList *list1 = NULL;



    while (1) {
        cout << endl << " ---------------------------- MENU --------------------------- " << endl;
        cout << "0. Quit" << endl;
        cout << "1. Create list" << endl;
        cout << "2. Display list" << endl;
        cout << "3. Insert node" << endl;
        cout << "4. Delete node" << endl;
        cout << "5. Print node" << endl;
        cout << "6. Convert data of node" << endl;
        cout << "7. Delete node whose data is greater than threshold" << endl;
        cout << "8. Reverse every k nodes" << endl;
        cout << "9. Remove duplicate nodes" << endl;
        cout << "10. Ascending sorting" << endl;
        cout << "Enter your option: ";
        cin >> opt;

        switch (opt)
        {
            case 0:
                cout << "Quited process of list 1" << endl << endl;
                isQuit = 1;
                break;
            case 1:
                cout << "Enter the number of nodes: ";
                cin >> n;
                list1 = createList(n);  
                break;
            case 2:
                printList(list1);
                break;
            case 3:
                cout << "Enter the position: ";
                cin >> pos;
                cout << "Enter data: ";
                cin >> data;
                insertAt(list1, pos, data);
                break;
            case 4:
                cout << "Enter the position: ";
                cin >> pos;
                deleteAt(list1, pos);
                break;
            case 5:
                cout << "Enter the position: ";
                cin >> pos;
                printElement(list1, pos);
                break;
            case 6:
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                convert(list1, oldData, newData);
                break;
            case 7:
                cout << "Enter the threshold: ";
                cin >> thres;
                deleteDataGrtThThres(list1, thres);
                break;
            case 8:
                cout << "Enter k: ";
                cin >> k;
                list1 = reverse(list1, k);
                break;
            case 9:
                list1 = removeDuplicates(list1);
                break;
            case 10:
                ascendingSort(list1);
                break;
            default:
                cout << "Invalid option !" << endl;
                break;
        }

        if (isQuit) {
            isQuit = 0;
            break; 
        }
    }



    // cout << "Enter data of list 2:" << endl;
    // singList *list2 = createList(3);
    // singList *Union = makeUnion(list1, list2);
    // cout << "The union ";
    // printList(Union);



    delete list1;
    return 0;
}