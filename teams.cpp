#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void maketeams(int len, int size1, int size2, int pindex, string team1[], string team2[], string plist[]);

// *You* are not allowed to use global variables
//  but for just the output portion *we* will. ;>
int combo = 1;

// @brief Prints a single combination of teams
//
// @param[in] team1 Array containing the names of team 1
// @param[in] team2 Array containing the names of team 2
// @param[in] len Size of each array
void printSolution(const string* team1, 
		   const string* team2,
		   int len)
{
  cout << "\nCombination " << combo++ << endl;
  cout << "T1: ";
  for(int i=0; i < len; i++){
    cout << team1[i] << " ";
  }
  cout << endl;
  cout << "T2: ";
  for(int i=0; i < len; i++){
    cout << team2[i] << " ";
  }
  cout << endl;
}

// You may add additional functions here
void maketeams(int len, int size1, int size2, int pindex, string *team1, string *team2, string *plist){
 //base case
 if(len == 0){
  cout << "no players"<< endl;
  }
  //cout << pindex <<endl;
  //check if team1 is full
  if(size1 != len/2){
    team1[size1] = plist[pindex];
    maketeams(len, size1+1, size2, pindex+1, team1, team2, plist);
  }
  //check if team2 is full
  if(size2 != len/2){
    team2[size2] = plist[pindex];
    maketeams(len, size1, size2+1, pindex+1, team1, team2, plist);
  }
  if(pindex == len){
  printSolution(team1, team2, len/2);
  }

}


int main(int argc, char* argv[])
{
  int len;

  if(argc < 2){
    cerr << "Please provide a file of names" << endl;
    return 1;
  }
  //open file
  ifstream infile;
  infile.open (argv[1]);
  if(infile.fail()){
    cout<<"Error"<<endl;
  }
  //get size of list
  infile >> len;
  //cout << len <<endl;
    //dynamically allocate memory
  string *team1 = new string [len/2];
  string *team2 = new string [len/2];
  string *plist = new string [len];
  //read file and copy names to plist
  for (int i = 0; i < len; i++){
    infile >> plist[i];
  }
  //call function
  //cout<<"test"<<endl;
  maketeams(len, 0,0,0,team1,team2, plist);
  //cout<< "test1"<<endl;
  //deallocate memory
  delete [] team1;
  delete [] team2;
  delete [] plist;

  return 0;
}
