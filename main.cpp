#include <iostream>

using namespace std;
#define MAX 100
struct Object{
    string name,color,size;
    int amount,cost;
}Objects[100];
int Counter=0;
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
void ADD_NEW(){
    cout<<"NAME?"<<endl;
        cin>>Objects[Counter].name;
    cout<<"COLOR?"<<endl;
        cin>>Objects[Counter].color;
    cout<<"SIZE?"<<endl
          <<"  S/M/L/XL/XXL/XXL";
        cin>>Objects[Counter].size;
    cout<<"AMOUNT?"<<endl;
        cin>>Objects[Counter].amount;
    cout<<"COST?"<<endl;
        cin>>Objects[Counter].cost;
    Counter++;
    return;
}
void SEARCH(){
    bool flag=false;
    string name;
    cin>>name;
    for(int i=0;i<Counter;i++){
        if(name==Objects[i].name){
            cout<<Objects[i].color<<endl;
            cout<<Objects[i].size<<endl;
            cout<<Objects[i].color<<endl;
            cout<<Objects[i].amount<<endl;
            cout<<Objects[i].cost<<endl;
            cout<<"__________________"<<endl;
            flag=true;
        }
    }
    if(flag==false)
        cout<<"NOT FOUND!"<<endl;
    return;
}
void swap(Object *xp, Object *yp)
{
    Object temp = *xp;
    *xp = *yp;
    *yp = temp;}
// A function to implement bubble sort
void SORT(){
    int i, j;
        for (i = 0; i < Counter-1; i++)

        // Last i elements are already in place
        for (j = 0; j < Counter-i-1; j++)
            if (Objects[j].cost > Objects[j+1].cost)
                swap(&Objects[j], &Objects[j+1]);
}
void LIST(){
    for(int i=0;i<Counter;i++){
            cout<<Objects[i].name<<endl;
            cout<<Objects[i].color<<endl;
            cout<<Objects[i].size<<endl;
            cout<<Objects[i].color<<endl;
            cout<<Objects[i].amount<<endl;
            cout<<Objects[i].cost<<endl;
            cout<<"__________________"<<endl;
   }
    return;
}
void DELETE(){
    Object temp;
    cout<<"NAME?"<<endl;
        cin>>temp.name;
    cout<<"COLOR?"<<endl;
        cin>>temp.color;
    cout<<"SIZE?"<<endl
          <<"  S/M/L/XL/XXL/XXL";
        cin>>temp.size;
    cout<<"AMOUNT?"<<endl;
        cin>>temp.amount;
    cout<<"COST?"<<endl;
        cin>>temp.cost;
        for(int i=0;i<Counter;i++){
                if(temp.name==Objects[i].name&&temp.size==Objects[i].size&&temp.color==Objects[i].color){
                    Objects[Counter].name="";
                    Objects[Counter].color="";
                    Objects[Counter].size="";
                    for (int j = i; j < Counter; ++j)
                        Objects[j] = Objects[j + 1];
                    Counter--;
                    break;
                }
       }
        return;
}
void menue(){
    bool flag=true;
    while(flag){
        cout<<"1)ADD NEW";
        cout<<"2)DELETE";
        cout<<"3)SEARCH";
        cout<<"4)SORT";
        cout<<"5)LIST";
        cout<<"6)EXIT"<<endl;
        int choice=0;
        cin>>choice;
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
            flag=false;
            break;
        }

    }
    exit(0);
}
