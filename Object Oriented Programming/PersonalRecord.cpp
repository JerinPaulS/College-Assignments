/*
Write C++ program using STL for sorting and searching with user defined records such as person record(Name, DOB, Telephone number) using vector container.
*/
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class PersonalRecord{
private:
  string name;
  int id;
  long telenumber;
  string dob;

public:
  PersonalRecord(int i, string nm, string db, long num){
    id = i;
    name = nm;
    dob = db;
    telenumber = num;
  }

  PersonalRecord(){
    id = 0;
    name = "";
    dob = "";
    telenumber = 0;
  }

  string getName(){
    return name;
  }

  int getId(){
    return id;
  }

  long getNum(){
    return telenumber;
  }

  string getDob(){
    return dob;
  }
};

vector<PersonalRecord> records;
void dataEntry();
void display();
void recordOrdered();
void search();

bool compare(PersonalRecord& record1, PersonalRecord& record2){
   return record1.getId() < record2.getId();
}

int main(){
  int count = 0;
  int temp = 0;
  cout << "Enter the number of IDs: ";
  cin >> count;
  temp = count;
  /*PersonalRecord obj(123, "Jerin", "19/03/1999", 9878765654);
  PersonalRecord obj1(6, "Paul", "12/03/1999", 98787345654);
  PersonalRecord obj2(30, "Tom", "19/03/1959", 9878123654);
  records.push_back(obj);
  records.push_back(obj1);
  records.push_back(obj2);*/
  while(temp > 0){
      dataEntry();
      temp -= 1;
  }
  display();
  search();
  recordOrdered();
  return 0;
}

void dataEntry(){
  int i = 0;
  string nm = "", db = "";
  long num = 0;
  cout << "Enter the ID: ";
  cin >> i;
  cout << "Enter the name: ";
  cin >> nm;
  cout << "Enter the Date of Birth: ";
  cin >> db;
  cout << "Enter the telephone number: ";
  cin >> num;
  PersonalRecord obj(i, nm, db, num);
  records.push_back(obj);
}

void display(){
  for(int i = 0; i < records.size(); i++)
    cout << records[i].getId() << ", " << records[i].getName() << ", " << records[i].getDob() << ", " << records[i].getNum() << "\n";
}

void recordOrdered(){
  sort(records.begin(), records.end(), compare);
  display();
}

void search(){
  int flag = 0, sid = 0;
  cout << "Enter the ID to search: ";
  cin >> sid;
  for(int i = 0; i < records.size(); i++){
    if(sid == records[i].getId()){
      flag = 1;
      break;
    }
  }
  if(flag == 0)
    cout << "Element not found" << "\n";
  else
    cout << "Elemet found" << "\n";
}
