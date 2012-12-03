//Charles Treatman  ctreatma
//analyze.cc

#include <iostream>
#include <fstream>
#include "skip_list.h"
#include "sorted_list.h"
#include "link_list.h"
#include "random_fun.h"

using namespace std;

int testMemberAccess(int n, SortedList* myList);
int testSize(int n, SortedList* myList);
double avgMemberAccess(int n, int trials, SortedList* myList);
double avgSize(int n, int trials, SortedList* myList);

int main(int argc, char**argv){
  using std::cerr;
  using std::cout;

  if(argc !=5){
    cerr <<"Executable analyze requires 4 arguments to run";
    exit(1);
  }
  
  int trials = atoi(argv[2]);
  int step = atoi(argv[3]);
  int cutoff = atoi(argv[4]);
  std::ofstream ofs(argv[1]);


  SkipList* sList = new SkipList();
  LinkList* lList = new LinkList();
  
  for(int i=step; i<=cutoff; i+=step){
    ofs << i << " ";
    ofs << avgMemberAccess(i, trials, sList) << " ";
    ofs << avgSize(i, trials, sList) << " "; 
    ofs << avgMemberAccess(i, trials, lList) << " ";
    ofs << avgSize(i, trials, lList) << "\n";
  }
  
}

int testMemberAccess(int n, SortedList* myList) {
  int count;
  
  if (!myList->empty()) {
    cerr << "test MemberAccess: You must pass an empty list!" << endl;
    exit(1);
  }
  else {
    for (int i = 0; i < n; ++i) {
      myList->insert(equilikely(0, 2*n));
    }
    count = myList->countAccesses();
    myList->member(equilikely(0, 2*n));
    count = myList->countAccesses() - count;
    myList->clear();
    return count;
  }
}

int testSize(int n, SortedList* myList) {
  int size;

  if (!myList->empty()) {
    cerr << "testSize: You must pass an empty list!" << endl;
    exit(1);
  }
  else {
    for (int i = 1; i <= n; ++i) {
      myList->insert(i);
    }
    size = myList->countBlocks();
    myList->clear();
    return size;
  }
}

double avgMemberAccess(int n, int trials, SortedList* myList) {
  double result = 0;

  if (!myList->empty()) {
    cerr << "avgMemberAccess:  You must pass an empty list!" << endl;
    exit(1);
  }
  else {
    for (int i = 0; i < trials; ++i) {
      result += testMemberAccess(n, myList);
    }
    result /= trials;
    return result;
  }
}

double avgSize(int n, int trials, SortedList* myList) {
  double result = 0;

  if (!myList->empty()) {
    cerr << "avgSize:  You must pass an empty list!" << endl;
    exit(1);
  }
  else {
    for (int i = 0; i < trials; ++i) {
      result += testSize(n, myList);
    }
    result /= trials;
    return result;
  }
}
