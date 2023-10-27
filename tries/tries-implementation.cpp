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

    void insertUtil(TrieNode *root, string word){

        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        // ek khud krlo baki recursion sambhal lega

        int index = word[0] - 'a'; // it is assumed that all the letters would be smaller
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
     
    bool searchUtil(TrieNode* root, string word){

        //base case
        if(word.length()== 0){
            return root->isTerminal;
        }
            
        int index = word[0] - 'a';

        if(root->children[index]){
            return searchUtil(root->children[index], word.substr(1));
        }
        else{
            return false;
        }
    }

    bool SearchPrefixUtil(TrieNode* root, string word){
            
        //base case
        if(word.length() == 0) return true;

        int index = word[0] - 'a';

        if(root->children[index]){
            return SearchPrefixUtil(root->children[index], word.substr(1));
        }
        else{
            return false;
        }
    }

    bool DeleteUtil(TrieNode* root, string word){

        if(word.length() == 0){

            if(root->isTerminal){
                root->isTerminal = false;
                return true;
            }
            return false;
        }

        int index = word[0] - 'a';

        if(root->children[index]){
            return DeleteUtil(root->children[index], word.substr(1));
        }
        else{
            return false;
        }
    }

    public:
        Trie(){

            node = new TrieNode('\0'); // passed null character in the root
        }

        void insertWord(string word) { insertUtil(node, word); }

        bool searchWord(string word){ return searchUtil(node,word); }

        bool searchPrefix(string word){ return SearchPrefixUtil(node, word); }

        void deleteWord(string word) {

            if(DeleteUtil(node, word)){
                cout<<"Word "<<word<<" is deleted successfully"<<endl;
            }
            else{
                cout<<"Word is not present or may not get deleted"<<endl;
            }
        }
};

int main(){
    Trie *t = new Trie();

    vector<string> names = {"mohit","aayush","jatin","ritika","ruchika","anamika","rohan"};

    for(int i = 0; i < names.size(); i++){
        t->insertWord(names[i]);
    }

    // t->insertWord("ABCD"); // passing lower case letters would give an error

    cout<<"is abcd present or not : "<<t->searchWord("abcd")<<endl;
    
    cout<<"is mohit present in the trie--> "<<t->searchWord("mohit")<<endl;

    cout<<"is any word starting with MO present of not --> "<<t->searchPrefix("mo")<<endl;

    t->deleteWord("anamika");
    t->deleteWord("anamika");
    
}