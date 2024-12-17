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

class Serializable {
private:
    string name;
    string number;
    int score;

public:
    Serializable(){};
    // Constructor to initialize the data members
    Serializable(const string& name, string number, int score)
        : name(name)
        , number(number)
        , score(score)
    {
    }
    // Getter methods for the class
    string getName() const { return name; }
    string getNumber() const { return number; }
    int getScore() const { return score; }

    //  Function for Serialization
    void serialize(const string& filename)
    {
        ofstream file(filename, ios::binary|ios::app);
        if (!file.is_open()) {
            cerr
                << "Error: Failed to open file for writing."
                << endl;
            return;
        }
        file.write(reinterpret_cast<const char*>(this),
                   sizeof(*this));
        file << endl;
        file.close();
        cout << "Object serialized successfully." << endl;
    }

    //  Function for Deserialization
    static Serializable deserialize(const string& filename)
    {
        Serializable obj("", "", 0);
        ifstream file(filename, ios::binary|ios::app);
        if (!file.is_open()) {
            cerr
                << "Error: Failed to open file for reading."
                << endl;
            return obj;
        }
        file.read(reinterpret_cast<char*>(&obj),
                  sizeof(obj));
        file.close();
        cout << "Object deserialized successfully." << endl;
        return obj;
    }
};

/////////////////////////////////////   Main starts here    ///////////////////////////////////////////

int main(){
    vector<Friend> friends;
    
    int lineCount = 0;
    std::string line;
    std::ifstream myfile("data.bin");
     while(std::getline(myfile, line)){
        ++lineCount;
    }
  
    
    std::cout << "Number of lines in text file: " << lineCount << endl;
    myfile.close();
    
    

    //Populate array with existing data from data.bin file - not implemented.
    
    
    cout << "\t\tWELCOME TO RANKMATES! \nA social platform to pit your friends against eachother to see who's really your #1 mate!" << endl;
    int choice = 0;
    while(choice != 3){
        cout << "\nWhat would you like to do today?\n";
        cout << "1. Add friends" << endl;
        cout << "2. Display Friends" << endl;
        cout << "3. Exit application" << endl;
        cin >> choice;
        
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
            //Makes a serializable instance.
            Serializable original(F1.getName(), F1.getPhNum(), F1.getScore());
            cout << "\nYou've added " << newName << ", with phone number " << newPhone << " and a score of " << newScore << ".\n" << endl;
            //appended here.
            friends.push_back(F1);
            //serialized.
            original.serialize("data.bin");
            
        }
        
        else if(choice == 2){
            
            //Display all instances of Friend in vector
            for(int i=0; i < friends.size(); i++){
                friends[i].displayFriend();
                
            }
        }
        
        else if(choice != 1 && choice !=2 && choice != 3){
            cerr
                << "Error: Unknown selection made.\n"
                << endl;
        }
    }
  
    return 0;
}
