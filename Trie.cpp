#include<bits/stdc++.h>
using namespace std;

class Trie{
    public:
    class node{
        public:
        bool end;
        node* next[26];

        node() 
        {
            end = false;
            for(int i = 0 ; i < 26 ; i++){
                next[i] = NULL;
            }
        }
    };
    
    node* root;

    Trie(){
        root = new node();
    }

    void insert(string word){
        int i = 0 ; 
        node* it = root ;

        while(i < word.size()){
            if(it->next[word[i]-'a'] == NULL)
                it->next[word[i]-'a'] = new node();
            it = it->next[word[i]-'a'];
            i++;
        }
        it->end = true;
    }
    bool search(string word){
        int i = 0 ; 
        node* it = root ;

        while(i < word.size()){
            if(it->next[word[i] - 'a'] == NULL) return false;
            it = it->next[word[i] - 'a'];
            i++;
        }
        return it->end;
    }
    
};

int main(){

    Trie* myTrie = new Trie();

    vector <string> words;
    string w;
    while(getline(cin , w)){
        if(w == ".") break;

        words.push_back(w);
    }
    for(int i = 0 ; i < words.size() ; i++){
        myTrie->insert(words[i]);
    }
    if(myTrie->search("madhav")){
        cout<<"madhav exist\n";
    }
    else cout<<"not exist\n";

    if(myTrie->search("amit")){
        cout<<"amit exist\n";
    }
    else cout<<"not exist\n";

    return 0;

}