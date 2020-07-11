#include <iostream>
#include <string>
using namespace std;
#define MAX 100
struct Object{
    string name, color, size;
    int amount, cost;
}Objects[100];
int Counter = 0;
void ADD_NEW();
void SEARCH();
void SORT();
void LIST();
void DELETE();
void menue();
int main()
{
    menue();
    return 0;
}
bool CHEK_TYPE(string s){
    bool flag=true;
    for (int i = 0; i < s.length(); i++){
        if (48 <= int(s[i]) && int(s[i]) <= 57){
            flag = false;
            break;
        }

    }
    return flag;
}
void ADD_NEW(){
    cout << "NAME?" << endl
        << "  MANTO/SHIRT/BLOUSE/PANTS/SCARF/SKIRT ?" << endl;
    cin >> Objects[Counter].name;
    bool flag = CHEK_TYPE(Objects[Counter].name);
    if (flag==false){
        cout << "ERROR!!\nENTER TRUE NAME.\n";
        cin >> Objects[Counter].name;
    }
    cout << "COLOR?" << endl;
    cin >> Objects[Counter].color;
    flag = CHEK_TYPE(Objects[Counter].color);
    if (flag == false){
        cout << "ERROR!!\nENTER TRUE COLOR.\n";
        cin >> Objects[Counter].color;
    }
    cout << "SIZE?" << endl
        << "  S/M/L/XL/XXL/XXL\n";
    cin >> Objects[Counter].size;
    cout << "AMOUNT?" << endl;
    cin >> Objects[Counter].amount;
    cout << "COST?" << endl;
    cin >> Objects[Counter].cost;
    Counter++;
    cout << "DONE!"<<endl;
    return;
}
void SEARCH(){
    bool flag = false;
    string name;
    cin >> name;
    for (int i = 0; i<Counter; i++){
        if (name == Objects[i].name){
            cout << Objects[i].color << endl;
            cout << Objects[i].size << endl;
            cout << Objects[i].color << endl;
            cout << Objects[i].amount << endl;
            cout << Objects[i].cost << endl;
            cout << "__________________" << endl;
            flag = true;
        }
    }
    if (flag == false)
        cout << "NOT FOUND!" << endl;
    return;
}
void swap(Object *xp, Object *yp)
{
    Object temp = *xp;
    *xp = *yp;
    *yp = temp;
}
// A function to implement bubble sort
void SORT(){
    int i, j;
    for (i = 0; i < Counter - 1; i++)

        // Last i elements are already in place
    for (j = 0; j < Counter - i - 1; j++)
    if (Objects[j].cost > Objects[j + 1].cost)
        swap(&Objects[j], &Objects[j + 1]);
    cout << "DONE!" << endl;
}
void LIST(){
    for (int i = 0; i<Counter; i++){
        cout << Objects[i].name << endl;
        cout << Objects[i].color << endl;
        cout << Objects[i].size << endl;
        cout << Objects[i].color << endl;
        cout << Objects[i].amount << endl;
        cout << Objects[i].cost << endl;
        cout << "__________________" << endl;
    }
    return;
}
void DELETE(){
    Object temp;
    cout << "NAME?" << endl
        << "  MANTO/SHIRT/BLOUSE/PANTS/SCARF/SKIRT ?" << endl;
    cin >> temp.name;
    cout << "COLOR?" << endl;
    cin >> temp.color;
    cout << "SIZE?" << endl
        << "  S/M/L/XL/XXL/XXL ?" << endl;
    cin >> temp.size;
    for (int i = 0; i<Counter; i++){
        if (temp.name == Objects[i].name&&temp.size == Objects[i].size&&temp.color == Objects[i].color){
            Objects[Counter].name = "";
            Objects[Counter].color = "";
            Objects[Counter].size = "";
            for (int j = i; j < Counter; ++j)
                Objects[j] = Objects[j + 1];
            Counter--;
            break;
        }
    }
    cout << "DONE!" << endl;
    return;
}
void menue(){
    bool flag = true;
    while (flag){
        cout << "1)ADD NEW" << endl;
        cout << "2)DELETE" << endl;
        cout << "3)SEARCH" << endl;
        cout << "4)SORT" << endl;
        cout << "5)LIST" << endl;
        cout << "6)EXIT" << endl;
        int choice = 0;
        cin >> choice;
        switch (choice) {
        case 1:
            ADD_NEW();
            break;
        case 2:
            DELETE();
            break;
        case 3:
            SEARCH();
            break;
        case 4:
            SORT();
            break;
        case 5:
            LIST();
            break;
        case 6:
            flag = false;
            break;
        }

    }
    exit(0);
}
