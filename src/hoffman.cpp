#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cctype>

using namespace std;

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

    //print the amount of times the letter occurs to the terminal!
    for(const auto& pair : letterFrequency){
        cout << pair.first << " " << pair.second << endl;
    }
}

int main(){

    string filePath = "../test.txt";
    countLetterFrequency(filePath);
    return 0;
}