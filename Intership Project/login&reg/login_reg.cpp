#include <iostream>
 #include <fstream>
 #include <string>

 using namespace std;
 void registerUser(){
    string username,password;
    cout<<" Enter username:"<<endl;;
    cin>>username;
    cout<<"Enter password:"<<endl;
    cin>>password;

    ofstream file("users.txt",ios::app);
    if (file.is_open()){
        file << username << " " << password <<endl;
        file.close();
        cout<<"Registration successful!\n";
    }
    else{
        cout<<"opening file error.\n";
    }
 }

 void loginUser(){
    string username,password,u,p;
    bool loginsuccess = false;

    cout<<"Enter username:";
    cin>>username;
    cout<<"Enter password:";
    cin>>password;

    ifstream file("users.txt");
    if (file.is_open()){
        while(file >> u >> p){
            if(u == username && p == password){
                loginsuccess = true;
                break;
            }
        }
        file.close();
        if (loginsuccess)
        cout<<"login successful! welcome,"<< username <<"!\n";
         
        else
        cout<<"login failed! invalid username or password.\n";
    }
    else{
        cout<<"Opening file error.\n";
    }

 }
 int main(){
    int choice;

    while (true){
        cout<<"\n==== Login system ====\n";
        cout<<"1. Register"<<endl;
        cout<<"2. login"<<endl;
        cout<<"3. exit"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>choice;

  switch(choice){
     case 1:
         registerUser();
         break;
     case 2:
         loginUser();
         break;
     case 3:
         cout<<"Exiting program.\n";
         return 0;
     default:
     cout<<"invalid choice. try again.\n";
  }
    }
    return 0;
 }