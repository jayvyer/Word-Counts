#include <fstream>
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <math.h>



int main(int argc, char *argv[])
{
  using namespace std;
  typedef int Count;
  typedef pair<string,Count> WordCount;
  auto args = vector<string>(&argv[0], &argv[argc]);
  if(args.size() < argc){
    cout << "usage: ./wordcounts MAX_N_OUT MIN_WORD_LEN MAX_WORD_LEN FILE...";
  }
  else if(args[2] > args[3]){
    cout << "MIN_WORD_LEN " << args[2] << " is greater than MAX_WORD_LEN " << args[3];
  }
  else if(args[1].length() != (int) log10 ((double) stoi(args.at(1))) + 1){
    cout << "bad integer value" << "''" << args.at(1) << "'' for " << "MAX_N_OUT";
  }
  else if(args[2].length() != (int) log10 ((double) stoi(args.at(2))) + 1){
    cout << "bad integer value" << "''" << args.at(2) << "'' for " << "MIN_WORD_LEN";
  }
  else if(args[3].length() != (int) log10 ((double) stoi(args.at(3))) + 1){
    cout << "bad integer value" << "''" << args.at(3) << "'' for " << "MAX_WORD_LEN";
  }
  unordered_map<string,Count> map;
  int MAX_N_OUT = stoi(args.at(1));
  int MIN_WORD_LEN = stoi(args.at(2));
  int MAX_WORD_LEN = stoi(args.at(3));
  int j;
  for(int filenum = 4; filenum < argc ; filenum++){
    ifstream in(args.at(filenum));
    while(in.good()){
      string str;
      in >> str;
      for(int i = 0; str[i] != '\0'; i++) {
         while(!( (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '\0')) {
            for(int j = i; str[j] != '\0'; j++) {
               str[j] = str[j+1];
            }
         }
         if(str[i] >= 'A' && str[i] <= 'Z'){
           str[i] = str[i] - ('Z' - 'z');
         }
      }
      bool check = true;
      for(int i = 0; str[i] != '\0'; i++) {
        if(!(str[i] >= 'a' && str[i] <= 'z')){
          bool check = false;
        }
      }
      if(str.length() >= MIN_WORD_LEN && str.length() <= MAX_WORD_LEN && check){
        Count& count = map[str];
        count += 1;
      }
    }
    if(!in.eof()){
      cout << "No such file or directory";
    }
  }
  auto wordCounts = vector<WordCount>(map.begin(),map.end());
  sort(wordCounts.begin(), wordCounts.end(),
          [](WordCount a, WordCount b) -> bool
          { return a.second == b.second ? (1+b.first.compare(a.first))/2 : a.second > b.second;
          });
  for(int i = 0; i < MAX_N_OUT; i++){
    cout << "\n" << wordCounts[i].first << ": " << wordCounts[i].second;
  }
  return 0;
}
