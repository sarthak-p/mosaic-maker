/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;

using namespace std; 

/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
AnagramDict::AnagramDict(const string& filename)
{
    ifstream file(filename);
    string word;
    if (file.is_open()) {
        string word2; 
        while (getline(file, word)) {
            word2 = word;
            sort(word2.begin(), word2.end());
            dict[word2].push_back(word);
        }
    }
}

/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
    size_t word_size = words.size();
    for (size_t i = 0; i < word_size; i++) {
        string word = words[i];
        sort(word.begin(), word.end());
        dict[word].push_back(words[i]);
    }
}

/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    string str = word; 
    sort(str.begin(), str.end());

    if (dict.find(str) == dict.end()) {
        return vector<string>(); 
    }
    return dict.at(str);
}

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    /* Your code goes here! */
    vector<vector<string>> out;

    for (auto each : dict) {
        if (1 < each.second.size()) {
            out.push_back(each.second);
        }
    }
    return out; 
}
