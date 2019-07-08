#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <iterator>
#include <string>
using namespace std;


int main()
{
    string word;
    
    ifstream inputFile;
    inputFile.open("typehere.txt");
    
    map<string,int> myMap;
    map<string,int>::iterator it = myMap.begin();
    
    while(inputFile >> word)
    {
        // Find punctuation and remove it
        for (int i = 0, len = word.size(); i < len; i++)
        {
            if (ispunct(word[i]))
            {
                word.erase(i--, 1);
                len = word.size();
            }
        }
        // Convert uppercase letter to lowercase
        word[0] = tolower(word[0]);
        
        myMap.insert(pair<string,int>(word, 0) );
        pair<map<string,int>::iterator, bool> ret;
        ret = myMap.insert ( pair<string,int>(word, 0) );
        if (ret.second == false)
        {
            ret.first->second++;
        }
        
        myMap.insert(it, pair<string,int>(word, 0));
        
        //myMap.insert (it, pair<string,int>(word, 400));
    }
    
    for (it = myMap.begin(); it != myMap.end(); ++it)
        cout << it->first << " => " << it->second << '\n';
    
    
    inputFile.close();
    
    return 0;
}
