#include <iostream>
#include <fstream>
#include <string>

    using namespace std;

bool IsLooggedIn(){
    string username, password, un, pw;

    cout << "Enter username: ", cin >> username;
    cout << "Enter password: ", cin >> password;

    ifstream read("data\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if ( un == username && pw == password){
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    int choice;
    cout << "1.Login\n2 2.Sin up\nYoure choise", cin >> choice;
    if (choice == 1){
        string username,password;
        cout << 'select a username: ', cin >> username;
        cout << 'select a password: ', cin >> password;

        ofstream file;
        file.open("/home/alex-ngr1/Documents/logging");
        file << username << endl << password;
        fclose;
       
        mani();
    }
    else if (choice == 2){
        bool status = IsLooggedIn();

        if (!status){
            cout << "False Login! " << endl;
            system("PAUSE:");
            return 0;
        }
        else{
            cout << "Succesfully logged in!: " << endl;
            system("PAUSE:");
            return 1;
        }
    }
    
    return 0;
}
