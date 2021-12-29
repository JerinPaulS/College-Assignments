/*
Write a program in C++ to use map associative container. The keys will be the names of states, and the values will be the populations of the states. When the program runs, the
user is prompted to type the name of a state. The program then looks in the map, using the state name as an index, and returns the population of the state.
*/
#include "iostream"
#include "iterator"
#include "map"

using namespace std;

int main(){
  int count = 0;
  int population = 0;
  string key = "";
  string st = "";
  map<string, int> state;
  cout << "Enter the number of IDs: ";
  cin >> count;
  while(count > 0){
    cout << "Enter the state name: ";
    cin >> st;
    cout << "Enter the population: ";
    cin >> population;
    state.insert(pair<string, int>(st, population));
    count -= 1;
  }
  map<string, int>::iterator itr;
  for(itr = state.begin(); itr != state.end(); ++itr)
      cout << '\t' << itr->first << '\t' << itr->second << '\n';
  cout << "Enter the state: ";
  cin >> key;
  auto val = state.find(key);
  if (state.count(key) == 0)
    cout << "Key Not Present";
  else
    cout << val->second;
  return 0;
}
