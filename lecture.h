
#ifndef LECTURE_H
#define LECTURE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

const set<string> stop_words = { "the", "for", "was", "and", "that", "but",
                          "had", "you", "she", "all", "with", "could",
                          "some", "from", "not", "can", "her", "just",
                          "know", "would", "there", "what", "they" };

struct Counter{
private:
    vector<string> words;
    map<string,int> counts;

public:
    explicit Counter(const string& direction, const string& url) {
        // TODO
        ifstream file(direction + url);
        string content;

        for_each(istream_iterator<string> (file), istream_iterator<string> (), [&content](const auto& element) { content += element + ' '; });
        file.close();

        string clean_content;
        bool insideLabel = false;

        for_each(content.begin(),content.end(),[&clean_content,&insideLabel](char c){
            if (c == '<') { insideLabel = true; }
            if (c == '>') { insideLabel = false; }
            if (!insideLabel && c != '>') { clean_content += c; }
        });

        Iterators(clean_content);
    }

    void Iterators(string text) {
        replace_if(text.begin(), text.end(), [](char c) { return c == '-' ? 0 : !isalnum(c);}, ' ');
        transform(text.begin(), text.end(), text.begin(), [](char c) { return tolower(c); });

        stringstream ss(text);

        vector<string> yesReps;
        for_each(istream_iterator<string> (ss), istream_iterator<string> (),[&](const string& element){ yesReps.push_back(element); });

        for_each(yesReps.begin(),yesReps.end(),[&](const string& element)
        { (element.length() < 3 || stop_words.find(element) != stop_words.end()) ?  0 : counts[element]++ ; } );
        yesReps.resize(0);
    }

    int operator()(const string& word) {
        // TODO
        int number = 0;
        for_each(counts.begin(),counts.end(),[&word,&number](const pair<string, int>& element){ if (element.first == word) number = element.second; });
        return number;
    }

    vector<string> ranking(){
        // TODO
        vector<pair<string, int>> sorted(counts.begin(), counts.end());
        sort(sorted.begin(), sorted.end(), [](pair<string, int>& a, const pair<string, int>& b){ return a.second > b.second; });

        for_each(sorted.begin(),sorted.end(),[this](const pair<string, int>& element) { words.push_back(element.first); });
        sorted.resize(0);
        return words;
    }

   ~Counter() { words.resize(0); counts.clear(); }
};

#endif //LECTURE_H
