//
//  carparkautomation.cpp
//  CarparkAutomation
//
//  Created by Mehmet Tugrul Savran on 10/8/13.
//  Copyright (c) 2013 CuriouScientists. All rights reserved.
//  LET THE GAMES BEGIN!

#import "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <cmath>
#include <ctime>
#define MAX 100
using namespace std;

class Vehicle{
public:
    string plate;
    string person_name, person_surname, person_phone;
    time_t entry; //we're creating a time variable called entry
}car[MAX];
class Carpark{
public:
    string employee_id, employee_password;
    int i, budget;
    Carpark(string id, string s){
        employee_id=id;
        employee_password=s;
        budget=0; //We set the total budget as zero
        i=-1; //index i is set as -1.
        
    }
    void menu(){
        int choice;
        cout<<"CARPARK PROGRAM"<<endl;
        cout<<"---------------"<<endl;
        cout<<"1.Incoming Vehicle"<<endl;
        cout<<"2.Leaving Vehicle"<<endl;
        cout<<"3.List Vehicles"<<endl;
        cout<<"4.Report"<<endl;
        cout<<"5.Quit"<<endl;
        choice = getch();
        switch(choice){
            case '1': incoming();
                break;
            case '2': leave();
                break;
            case '3': list();
                break;
            case '4': report();
                break;
            case '5': exit(0); //we're leaving!
            default:cout<< "BAD CHOICE!" << endl;
                system ("pause");
                system ("cls");
                menu();
                break;
        }
    }
    
    void incoming(){
        system ("cls");
        i++;
        cout<<"Name of the Owner:";
        cin>>car[i].person_name;
        cout<<"Last Name of the Owner:";
        cin>>car[i].person_surname;
        cout<<"Phone number of the Owner:";
        cin>>car[i].person_phone;
        cout<<"The plate of the Car";
        cin>>car[i].plate;
        cout<<"Operation Successful."<<endl;
        time(&car[i].entry);
        system("pause");
        system("cls");
        menu();
        
    }
    
    void leave(){
        system("cls");
        bool found=false;
        int j=0,k,hour;
        double sure;
        time_t quit;
        string plat;
        time(&quit);
        cout<<"Enter Plate Number";
        cin>>plat;
        while(j<=i){
            if (car[j].plate==plat){
                sure = difftime(quit,car[j].entry);
                for(k=j;k<=i;k++){
                    car[k]=car[k+1];
                }
                i--;
                found=true;
                break;
            }
            j++;
        }
        if(found==true){
            cout<<"Plate Number Not Found!"<<endl;
            system("pause");
            system("cls");
            menu();
        }
        sure=sure/3600;
        hour=ceil(sure);
        cout<<"Price="<<hour*5<<"$USD"<<endl;
        budget+=hour*5;
        system("pause");
        system("cls");
        menu();
    }
    
    void list(){
        system("cls");      //Oh, this is to clear the screen ;)
        for (int j=0; j<=1;j++){
            cout<<car[j].plate<<endl;
        }
        system("pause");   //Wait until an action is done! :-)
        system("cls");
        menu();
    }
    
    void report(){
        system("cls");
        cout<<"Current income="<<budget<<"$USD"<<endl;
        system("pause");
        system("cls");
        menu();
    }
};


int main()
{
    Carpark employee("tugrulsavran", "mts");
    string name, chiffre;
    int i=0;
    cout<<"CARPARK PROGRAM"<<endl;
    while(1){
        cout<<"Enter the username:"<<endl;
        cin>>name;
        cout<<"Enter the password:"<<endl;
        cin>>chiffre;
        if(employee.employee_id==name)
            if (employee.employee_password==chiffre) {
                cout<<"Password correct!"<<endl;
                system("pause");
                break;
                
            }
        cout<<"Try again!"<<endl;
        system("pause");
        system("cls");
    }
    
    system("cls");
    employee.menu();
    system("pause");
    return 0;
}

