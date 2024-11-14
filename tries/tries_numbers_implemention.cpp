// I wrote this code specifically for leetcode problem 3043. Find the length of the longest common prefix
#include <bits/stdc++.h>
using namespace std;

class TrieNode{

    public:
        char data;
        TrieNode* children[10];
        bool isTerminal;

        TrieNode(char data){

            this->data = data;
            for(int i = 0; i < 10; i++) this->children[i] = NULL;
            this->isTerminal = false;
        }
};

class Trie{

    TrieNode* node;

    void insertUtil(TrieNode* root, string word){

        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - '0';

        TrieNode* child;

        if(root->children[index] != NULL){ //already a children existed
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }
    bool searchUtil(TrieNode* root, string word){
        
        //base case
        if(word.length() == 0) return root->isTerminal;

        int index = word[0] - '0';

        if(root->children[index] != NULL) { // it means children is present or the next word is present in Trie

            return searchUtil(root->children[index], word.substr(1));
        }
        else{
            return false;
        }

    }

    int searchPrefixUtil(TrieNode* root, string word,int count){

        if(word.length() == 0){
            // cout<<"word is empty and count "<<count<<endl;
            return count;
        }

        int index = word[0] - '0';

        // cout<<"value is "<<word[0]<<" and the count is << "<<count+1<<endl;
        if(root->children[index] != NULL) return searchPrefixUtil(root->children[index], word.substr(1),count+1);
        else{
            // cout<<"total length reached and count is "<<count<<endl;
            return count;
        }
    }

    public:
    Trie(){
        node = new TrieNode('\0');
    }

    void insert(string word) {insertUtil(node, word);}
    bool search(string word) {return searchUtil(node, word);}
    int searchPrefix(string word) {return searchPrefixUtil(node, word, 0);}

};


int main(){

    Trie* node = new Trie();

    vector<string> values = {"1","2","3"};

    for(string &value: values) node->insert(value);

    vector<string> numbers = {"4","4"};

    cout<<"word 100 is present in dictionary -> "<<node->search("100")<<endl;
    cout<<"word 10 is present in dictionary -> "<<node->search("10")<<endl;
    cout<<"word 1000 is present in dictionary -> "<<node->search("1000")<<endl;
    int maxLen = 0;
    for(string &num: numbers){

        int len = node->searchPrefix(num);
        cout<<"count ->"<<len<<endl;
        maxLen = max(len, maxLen);
    }
    cout<<maxLen<<endl;
    return 0;
}