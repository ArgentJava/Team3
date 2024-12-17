/*  Alyssa Trevino 
    & Jestyn Lytle
    24FA-CS211
    12/16/24
    Friend.cpp
*/
#include "Friend.hpp"
#include <iostream>
#include <string>
using namespace std;

    //  Profile Class Implimentations
    Profile::Profile(){};
    Profile::Profile(string name)
    : Name{name}{};
    Profile::~Profile(){};

    //  Friend Class Implimentations
    Friend::Friend(){};
    Friend::Friend(string name, string num, int score)
    : Profile{name}, phNum{num}, friendScore{score} {};
    Friend::~Friend(){};

    string Friend::getName(){
        return Name;
    };
    string Friend::getPhNum(){
        if (phNum.length() != 10){
            return "INVALID NUMBER";
        }
        string formatted = "(";
        formatted += phNum.substr(0,3);
        formatted += ") ";
        formatted += phNum.substr(3,3);
        formatted += "-";
        formatted += phNum.substr(6,4);
        return formatted;
    };
    int Friend::getScore(){
        return friendScore;
    };
    int Friend::incScore(int amount){
        friendScore = friendScore + amount;
        return friendScore;
    };
    int Friend::decScore(int amount){
        friendScore = friendScore - amount;
        return friendScore;
    };
    int Friend::altScore(){
        return ++friendScore;
    };
    void Friend::displayFriend(){
        cout << "\t" << getName() << "\t" << getPhNum() << "\t" << getScore() << endl;
    };
    
