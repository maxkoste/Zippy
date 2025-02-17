#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

bool compareFrequency(const pair<char, int>& a, const pair<char, int>& b){
    return a.second > b.second;
}

void countLetterFrequency(const string& filePath){

    ifstream f(filePath);

    if(!f.is_open()){
        cerr << "Error opening the file";
    }

    //map for storing the letters
    map<char, int> letterFrequency;
    
    char c;
    while (f.get(c)){

        c = tolower(c);
        //if its a letter it gets stored!
        if(isalpha(c)){
            letterFrequency[c]++;
        }
    }

    f.close();

    vector<pair<char, int>> sortedVec(letterFrequency.begin(), letterFrequency.end());

    sort(sortedVec.begin(), sortedVec.end(), compareFrequency);

    //print the amount of times the letter occurs to the terminal!
    for(const auto& pair : sortedVec){
        cout << pair.first << " " << pair.second << endl;
    }
}

int main(){

    string filePath = "../test.txt";
    countLetterFrequency(filePath);
    return 0;
}