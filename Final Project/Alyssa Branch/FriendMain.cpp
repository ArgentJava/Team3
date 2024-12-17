/*  Alyssa Trevino
    24FA-CS211
    12/8/24
    Friend.cpp
*/
#include "Friend.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(){
    Friend F1("Ruben", 5598246140, 99);
    cout << F1.getName() << "\t" << 
    F1.getPhNum() << "\t" <<
    F1.getScore() << "\t" <<
    F1.incScore(5) << "\t" <<
    F1.decScore(3) << "\t" <<
    F1.altScore() << endl;
    // cout << F1.displayFriend();

    return 0;
}