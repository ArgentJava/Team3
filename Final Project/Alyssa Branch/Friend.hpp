/*  Alyssa Trevino 
    & Jestyn Lytle
    24FA-CS211
    12/16/24
    Friend.hpp
*/
    //  Defining Friend.hpp
#ifndef Friend_hpp
#define Friend_hpp
#include <iostream>
#include <string>
using namespace std;
    //  Creating base class Profile to hold Name variable and impliment virtual functions
class Profile{
protected:
    string Name;

public:
    //  Profile Constructors/Destructor
    Profile();
    Profile(string Name);
    //  Profile ~Destructor
    ~Profile();

    //  Pure virtual functions 
    ////virtual void setName(string newName) = 0;
    virtual string getName() = 0;
};

    //  Derived Friend class from Base Profile
class Friend: public Profile{
    private:
    //  Carries private phNum and friendScore data variables
    string phNum;
    int friendScore;

    public:
    //  Friend Constructors/Destructor
    Friend();
    Friend(string Name, string phNum, int friendScore);
    ~Friend();

    //  Declaration for getName() virtual function
    string getName();
    //  Getter functions for Friend variables phNum & friendScore
    string getPhNum();
    int getScore();
    //  Increase, Decrease, and Alter functions to edit score
    int incScore(int amount);
    int decScore(int amount);
    int altScore();
    void displayFriend();

};
#endif 
