#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

bool wordChange(char c){
    return c == '\'' || !isalpha(c); 
}

bool comp(pair<double,int> a, pair<double,int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
int solution(string word, vector<string> pages) {
    int answer = 0;
    map<string, int> saveIdx;
    vector<vector<string>> exLinks;
    vector<int> basicScore;
    vector<pair<double,int>> matchScore;
    
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    int i = 0;
    for(string page : pages){
        transform(page.begin(), page.end(), page.begin(), ::tolower);
        
        string content = "<meta property=\"og:url\" content=\"https://";
        int contentPos = page.find(content);
        int contentStart = contentPos + content.length();
        int contentEnd = page.substr(contentStart).find("\"/>");
        string url = page.substr(contentStart, contentEnd);
        saveIdx[url] = i;
        
        int bodyStart = page.find("<body>");
        int bodyEnd = page.find("</body>");
        string bodyPart = page.substr(bodyStart, bodyEnd - bodyStart);
        
        vector<string> links;
        string href = "<a href=\"https://";
        int hrefPos = bodyPart.find(href);
        while(hrefPos != string::npos){
            int hrefStart = hrefPos + href.length();
            int hrefEnd = bodyPart.substr(hrefStart).find("\">");
            links.push_back(bodyPart.substr(hrefStart, hrefEnd));
            hrefPos = bodyPart.find(href, hrefEnd + hrefStart);
        }
        exLinks.push_back(links);
        replace_if(bodyPart.begin(), bodyPart.end(), wordChange, ' ');
        
        int score = 0;
        istringstream iss(bodyPart);
        string token;
        while(getline(iss, token, ' ')){
            if(token == word) score++;
        }
        basicScore.push_back(score);
        i++;
    }
    
    for(int i = 0 ; i < pages.size(); i++){
        matchScore.push_back({basicScore[i],i});
    }
    
    for(int i = 0; i < exLinks.size(); i++){
        int size = exLinks[i].size();
        for(int j = 0; j < size; j++){
            if(saveIdx.find(exLinks[i][j]) != saveIdx.end()){
                matchScore[saveIdx[exLinks[i][j]]].first += (double)basicScore[i] / (double)size;
            }
        }
    }
    sort(matchScore.begin(), matchScore.end(), comp);
    answer = matchScore[0].second;
    return answer;
}