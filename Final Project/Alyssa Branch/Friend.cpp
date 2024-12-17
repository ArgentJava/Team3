/*  Alyssa Trevino
    24FA-CS211
    12/8/24
    Friend.cpp
*/
#include "Friend.hpp"
#include <iostream>
#include <string>
using namespace std;

    Friend::Friend(){};
    Friend::Friend(string name, long long num, int score)
    : Name{name}, phNum{num}, friendScore{score} {};
    Friend::~Friend(){};
    void Friend::setName(string& newName){
        Name = newName;
    };
    string Friend::getName(){
        return Name;
    };
    void Friend::setPhNum(long long& newNum){
        phNum = newNum;
    };
    long long Friend::getPhNum(){
        return phNum;
    };
    void Friend::setScore(int& newScore){
        friendScore = newScore;
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
    int Friend::getScore(){
        return friendScore;
    };
    void Friend::displayFriend(){
        cout << "\t" << getName() << "\t" << getPhNum() << "\t" << getScore() << endl;
    };
    
