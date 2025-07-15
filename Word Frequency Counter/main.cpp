# include <iostream>
# include <fstream>
# include <string> 
# include <map>
# include <cctype>
# include <vector>
# include <algorithm> 
using namespace std;

string cleanWord(string word);

int main(){
    
    string fileName;

    cout << "Enter file name: ";
    cin >> fileName;
    
    ifstream inFile(fileName); //Opens example.txt
    //Check if file opened correctly
    if(!inFile.is_open()){
        cerr << "Error: Unable to open file." << std::endl;
        return 1;
    }

    string phrase;
    map<string, int> words;
    // Word by word
    while(inFile >> phrase){
        phrase = cleanWord(phrase);
        if(words.find(phrase) != words.end()){
            //Exists
            words[phrase]++;
        }
        else{
            //Not found
            words.insert({phrase, 1});
        }
    }
    
    //Vector of pairs from map
    vector<pair<string, int>> sortedWords(words.begin(), words.end());

    // Sort vector using comparison
    sort(sortedWords.begin(), sortedWords.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
    //Sort in descending order of frequency
        return a.second > b.second;
    });

    // Print each entry on its own line using 'endl'
    for (int i = 0; i < sortedWords.size(); i++) {
        cout << sortedWords[i].first << ": " << sortedWords[i].second << endl;
    }

    /* Prints map key and value to console
    for(const auto& pair : words){
        cout << pair.first << ": " << pair.second;
    }*/

}

string cleanWord(string word){
    string cleaned;
    // Convert to lower
    for(char c : word){
        cleaned += tolower(c);
    }
    //Remove punctuation
    while(!cleaned.empty() && ispunct(cleaned.back())){
        cleaned.pop_back();
    }
    return cleaned;
}