#include<bits/stdc++.h>
using namespace std;

class TrieNode{

    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char data){

            this->data = data;

            for(int i = 0; i < 26; i++){
                this->children[i] = NULL;
            }
            this->isTerminal = false;
        }
};

class Trie{

    TrieNode *node;

    bool searchUtil(TrieNode* root, string word){

        //base case
        if(word.length()== 0){
            return root->isTerminal;
        }
            
        int index = word[0] - 'A';

        if(root->children[index]){
            return searchUtil(root->children[index], word.substr(1));
        }
        else{
            return false;
        }
    }

    void insertUtil(TrieNode *root, string word){

        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        // ek khud krlo baki recursion sambhal lega

        int index = word[0] - 'A'; // it is assumed that all the letters would be capital
        TrieNode *child;

        if(root ->children[index]){ // children is already present 
            child = root->children[index];
        }
        else{ // children is absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // recursion

        insertUtil(child, word.substr(1));
    }

    bool SearchPrefixUtil(TrieNode* root, string word){
            
        //base case
        if(word.length() == 0) return true;

        int index = word[0] - 'A';

        if(root->children[index]){
            return SearchPrefixUtil(root->children[index], word.substr(1));
        }
        else{
            return false;
        }
    }

    public:
        Trie(){

            node = new TrieNode('\0'); // passed null character in the root
        }

        void insertWord(string word) { insertUtil(node, word);}

        bool searchWord(string word){return searchUtil(node,word);}

        bool searchPrefix(string word){ return SearchPrefixUtil(node, word);}
};

int main(){
    Trie *t = new Trie();

    t->insertWord("ABCD"); // passing lower case letters would give an error

    cout<<"is ABCD present or not : "<<t->searchWord("ABCD")<<endl;

    t->insertWord("MOHIT");
    
    cout<<"is MOHIT present in the trie--> "<<t->searchWord("MOHIT")<<endl;

    cout<<"is any word starting with MO present of not --> "<<t->searchPrefix("MO")<<endl;

}