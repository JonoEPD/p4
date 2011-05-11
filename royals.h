// Author: Sean Davis

#ifndef ROYALS_H
#define	ROYALS_H
#include "RunRoyals.h"
#include "QuadraticProbing.h"

using namespace std;

class Royal {
 public:
  Royal();
  Royal(const Person &);
  char name[100];
  int birthYear;
  int spouseCount;
  int n_child;
  Royal* children[24];
  int n_parent;
  Royal* parents[2];
};

class Royals {
public:
  Royals(const Person *people, int count);
  QuadraticHashTable <Royal *> hashTable;
  void insertDriver(const Person*, const Person*, int&, int);
  void getAncestor(const char *descendentName1, int descendentBirthYear1,
    const char *descendentName2, int descendentBirthYear2,
    const char **ancestorName, int *ancestorBirthYear);
  int getChildren(const char*name, int birthYear);
  void getDescendent(const char *ancestorName, int ancestorBirthYear,
    const char **descendentName, int *descendentBirthYear);
  int getMarriages(const char*name, int birthYear);
  int getSiblings(const char*name, int birthYear);
};

#endif	/* ROYALS_H */

