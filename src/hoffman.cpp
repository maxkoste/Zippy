#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cctype>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node{

    char data;
    int frequency;
    Node* left;
    Node* right;
    Node(char d, int f) : data(d), frequency(f), left(nullptr), right(nullptr){}

    bool operator>(const Node& other) const {
        return frequency > other.frequency;
    };
};


bool compareFrequency(const pair<char, int>& a, const pair<char, int>& b){
    return a.second > b.second;
}

Node* buildHuffmanTree(map<char, int>& letterFrequency){
    //creating minHeap a sorted priorety_queue
    priority_queue<Node*, vector<Node*>, greater<Node*>> minHeap;

    for(const auto& pair : letterFrequency){
        minHeap.push(new Node(pair.first, pair.second));
    }

    int nodeCounter = 0; 

    while(minHeap.size() > 1){

        if(nodeCounter > 1000){
            cout << "Too many nodes. Stopping early." << endl;
        }

        nodeCounter++;

        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* internalNode = new Node('\0', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;

        minHeap.push(internalNode);
    }
    return minHeap.top();
}

map<char, int> countLetterFrequency(const string& filePath){

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

    //sorting the map
    vector<pair<char, int>> sortedVec(letterFrequency.begin(), letterFrequency.end());
    sort(sortedVec.begin(), sortedVec.end(), compareFrequency);

    //print the amount of times the letter occurs to the terminal!
    for(const auto& pair : sortedVec){
        cout << pair.first << " " << pair.second << endl;
    }

    return letterFrequency;
}

void deleteTree(Node* root){
    if(root == nullptr){
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main(){

    string filePath = "../test.txt";

    map<char, int> letterFrequency = countLetterFrequency(filePath);

    Node* root = buildHuffmanTree(letterFrequency);

    deleteTree(root);
    
    return 0;
}