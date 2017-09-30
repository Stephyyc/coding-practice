/* Prompt: A kidnapper wrote a ransom note but is worried it will be traced back to him. 
He found a magazine and wants to know if he can cut out whole words from it and use them to create an untraceable replica of his ransom note. 
The words in his note are case-sensitive and he must use whole words available in the magazine, 
meaning he cannot use substrings or concatenation to create the words he needs.

Given the words in the magazine and the words in the ransom note, 
print Yes if he can replicate his ransom note exactly using whole words from the magazine; otherwise, print No.
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool ransom_note(vector<string> magazine, vector<string> ransom) {    
    
    map<string,int> my_map;
    for (int j = 0; j < magazine.size(); j++) {
        string magazine_word = magazine[j];
        
        if (my_map.count(magazine_word) > 0) {
            my_map[magazine_word] = my_map[magazine_word]+1;      
        }
        else
            my_map[magazine_word] = 1;
    }
        
    for(int i = 0; i < ransom.size(); i++) {
        string word = ransom[i];
        if(!my_map.count(word)>0) {
            return false;
        }
        
        else {
            my_map[word]--;
            if (my_map[word] == 0) {
                my_map.erase(word);
            }
        }
    }
    
    return true;
    
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
