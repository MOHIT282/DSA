#include<bits/stdc++.h>
using namespace std;

class TrieNode{

    public:
        char data;
        TrieNode* children[26];
        bool isTerminal = false;

        TrieNode(char data){

            this->data = data;
            for(int i = 0; i < 26; i++) this->children[i] = NULL;
            this->isTerminal = false;
        }
};

class Trie{

    private:
    TrieNode* node;

    void insertUtil(TrieNode*root, string word){

        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a'; // getting the location of the first character

        //check if we have a place to place the char

        TrieNode* child = root;

        if(root->children[index] != NULL){ // children alreay present
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

        int index = word[0] - 'a';

        if(root->children[index] != NULL) { // it means children is present or the next word is present in Trie

            return searchUtil(root->children[index], word.substr(1));
        }
        else{
            return false;
        }

    }

    bool searchUtilPrefix(TrieNode* root, string word){

        if(word.length() == 0) return true;

        int index = word[0] - 'a';

        if(root->children[index] != NULL) return searchUtilPrefix(root->children[index],word.substr(0));

        else return false;
    }

    bool deleteWordUtil(TrieNode* root, string word){

        if(word.length() == 0){

            if(root->isTerminal == true){
                root->isTerminal = false;
                return true;
            }
            else{
                return false;
            }
        }

        int index = word[0] - 'a';

        if(root->children[index] != NULL) return deleteWordUtil(root->children[index],word.substr(1));
        else return false;
    }
    int findPrefixLengthUtil(TrieNode* root, string word,int count){
        
        // cout<<"word is "<<word[0]<<" and isTerminal is "<<root->isTerminal<<endl;
        if(word.length() == 0){
            // if(root->isTerminal) cout<<"Terminal root reached "<<endl;
            return count;
        }

        int index = word[0] - 'a';

        if(root->children[index] != NULL) return findPrefixLengthUtil(root->children[index],word.substr(1),count+1);
        else return count;
    }

    public:
    Trie(){
        node = new TrieNode('\0');
    }
    void insert(string word) { insertUtil(node,word);}
    bool search(string word) { return searchUtil(node,word);}
    bool searchPrefix(string word) { return searchUtilPrefix(node,word);}
    bool deleteWord(string word){

        if (deleteWordUtil(node, word) == true) cout<<word<<" deleted Successfully :)"<<endl;

        else cout<<word<<" is not present :("<<endl;
    }
    int findPrefixLength(string word) { return findPrefixLengthUtil(node, word,0);}
};


int main(){

    Trie* node = new Trie();

    vector<string>names = {"mohit","anmol","karan","jatin","lakshay","ruchika","shivam","moh"};
    for(string &name: names) node->insert(name);

    cout<<"is mohit present in the dictionary -> "<<node->search("mohit")<<endl;
    cout<<"is jatin present in the dictionary -> "<<node->search("jatin")<<endl;
    node->deleteWord("rahul");
    node->deleteWord("ruchika");
    cout<<"Maximum length of Prefix of mohitos stored in dictionary is : "<<node->findPrefixLength("mohitos")<<endl;
    return 0;
}