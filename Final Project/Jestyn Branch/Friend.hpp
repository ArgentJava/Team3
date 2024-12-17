/*  Alyssa Trevino
    24FA-CS211
    12/8/24
    Friend.hpp
*/
#ifndef Friend_hpp
#define Friend_hpp
#include <iostream>
#include <string>
using namespace std;

class Friend{
    private:
    string Name;
    string phNum;
    int friendScore;

    public:
    Friend();
    Friend(string Name, string phNum, int friendScore);
    ~Friend();
    void setName(string newName);
    string getName();
    void setPhNum(string newNum);
    string getPhNum();
    void setScore(int newScore);
    int incScore(int amount);
    int decScore(int amount);
    int altScore();
    int getScore();
    void displayFriend();

};
#endif 