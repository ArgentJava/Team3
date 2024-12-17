/*  Alyssa Trevino
    24FA-CS211
    12/8/24
    Friend.cpp
*/
#include "Friend.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

/////////////////////////////////////   Main starts here    ///////////////////////////////////////////

int main(){
    vector<Friend> friends;
    string newName, newPhone;
    int newScore;
    string line;
    Friend F1(newName, newPhone, newScore);
    std::fstream myfile("data.txt", std::ios::in | std::ios::out | std::ios::app);
    
    int lineCount = 0;
    /*while(std::getline(myfile, line)){
        ++lineCount;
    }
    std::cout << "Number of lines in text file: " << lineCount << endl;
    myfile.close();*/
    
    

    //Populate array with existing data from data.bin file
    
    
    cout << "\t\tWELCOME TO RANKMATES! \nA social platform to pit your friends against eachother to see who's really your #1 mate!" << endl;
    int choice = 0;
    while(choice != 3){
        cout << "\nWhat would you like to do today?\n";
        cout << "1. Add friends" << endl;
        cout << "2. Display Friends" << endl;
        cout << "3. Exit application" << endl;
        cin >> choice;
        std::fstream myfile("data.txt", std::ios::in | std::ios::out | std::ios::app);
        //Choice is 1, prompt user to enter information for new Friend object.
        if(choice == 1){
            string newName, newPhone;
            int newScore;
            cout << "What's your friends name?\n";
            cin >> newName;
            cout << "What's your friends phone number (digits only)?\n";
            cin >> newPhone;
            cout << "How would you score your friendship? (1-100)\n";
            cin >> newScore;
            
            //New Friend object is created with given input, appended to object array.
            Friend F1(newName, newPhone, newScore);
            
            cout << "\nYou've added " << newName << ", with phone number " << newPhone << " and a score of " << newScore << ".\n" << endl;
            myfile << newName << "\t\t" << newPhone << "\t\t" << newScore;
            myfile << endl;
            //appended here.
            friends.push_back(F1);
            myfile.close();
            
        }
        
        else if(choice == 2){
            
            //Display all instances of Friend in vector
            /*for(int i=0; i < friends.size(); i++){
                friends[i].displayFriend();
                ifstream myfile("data.txt");
                myfile << F1.getName() << "/t/t" << F1.getPhNum() << "/t/t" << F1.getScore() << "\n" << endl;
            }*/
            std::fstream myfile("data.txt", std::ios::in | std::ios::out | std::ios::app);
            while(getline (myfile, line)){
                cout << line << '\n';
            }
            myfile.close();
        }
        
        else if(choice != 1 && choice !=2 && choice != 3){
            cerr
                << "Error: Unknown selection made.\n"
                << endl;
        }
        myfile.close();
    }
    return 0;
}