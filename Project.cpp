#include <iostream>
#include <fstream>
#include <string.h>
// #include <stdlib.h>
// #include <windows.h>

using namespace std;
 // FUNCTION
void login();
void registration();
void forgot();

// MAIN MENU

int main(){


    int c;
    cout<<"\t\t\t______________________________________________\n\n\n";
    cout<<"\t\t\t_____________Welcome to the login page________\n\n\n";
    cout<<"\t\t\t_______________       MENU       _____________\n\n\n";
    cout<<"                                                     \n\n";
    cout<<"\t| Press 1 to LOGIN                        |"<<endl;
    cout<<"\t| Press 2 to REGISTER                     |"<<endl;
    cout<<"\t| Press 3 if you forgot your PASSWORD     |"<<endl;
    cout<<"\t| Press 4 to EXIT                         |"<<endl;
    cin>>c;
    cout<<endl;

//

    switch (c)
    {
    case 1:
        login();
        break; 
    case 2:
        registration();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout<<"\t\t\t Thankyou! \n\n";
    default:
    system("cls");  // screen cleaning
    //if (system("clear")) system( "cls" );
        cout<<"\t\t\t Please select from options given above \n"<<endl;
        break;
        main();
    }
    
}
        // LOGIC
    void logic()
    {
     int count;
     string userID, password, id, pass;
     system("cls");
     cout<<"\t\t\t Please enter the username and password: "<<endl;
     cout<<"\t\t\t USERNAME: ";
     cin>>userID;
     cout<<"\t\t\t PASSWORD: ";
     cin>>password;

     ifstream input("records.txt");
     while (input>>id>>pass)
     {
        if(id==userID && pass==password)
        {
            count=1;
            system("cls");

        }
     }
     input.close();
     
     if(count==1)
     {
        cout<<userID<<"\n Your LOGIN is successfull \n Thanks for logging in ! \n";
        main();
     }
     else{
        cout<<"\n LOGIN ERROR \n Please check your username and password\n";
        main();
     }
    }
        // REGISTRATION
    void registration()
    {
    string ruserId,rpassword,rid,rpass;
    system("cls");
    cout<<"\t\t\t Enter the username: ";
    cin>>ruserId;
    cout<<"\t\t\t Enter Password: ";
    cin>>rpassword;
    // write to a file
    ofstream f1("record.txt", ios::app); // using application
    f1<<ruserId<<" "<<rpassword<<endl;
    system("cls");
    cout<<"\n\t\t\t Registration is successfull! \n";
    main();
    }
    void forgot()
    {
        int option;
        system("cls");
        cout<<"\t\t\t You forgot the password? No worries \n";
        cout<<"Press 1 to search your id by username: "<<endl;
        cout<<"Press 2 to go back to the main menu: "<<endl;
        cout<<"\t\t\t Enter your choice: ";
        cin>>option;
        switch(option)
        {
            case 1:
            {
                int count=0;
                string suserId,sId,spass;
                cout<<"\n\t\t\tEnter the username which you remembered: ";
                cin>>suserId;
                // Checking the presence of a person in the file
                ifstream f2("record.txt");
                while(f2>>sId>>spass){
                    if(sId==suserId)
                    {
                        count=1;
                    }
                }
                f2.close();
                if(count==1)
                {
                  cout<<"\n\n Youre account is found";
                  cout<<"\n\n Youre password is: "<<spass;
                  main();
                }
                else
                {
                    cout<<"\n\t Sorry youre account is not found! \n";
                    main();
                }
                break;

            }

                case 2:
                {
                    main();
                    }  
                default:
                    cout<<"\t\t\t Wrong choice ! Please try again"<<endl;
                    forgot();
            
        }
    }
