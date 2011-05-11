// Author: Sean Davis

#include "royals.h"
#include "RunRoyals.h"
#include <iostream>

using namespace std;

Royals::Royals(const Person *people, int count)
{
  for(int i = 0; i < 20; i++)
    cout << people[i].name << endl;
}  // Royals()


void Royals::getAncestor(const char *descendentName1, int descendentBirthYear1,
    const char *descendentName2, int descendentBirthYear2,
    const char **ancestorName, int *ancestorBirthYear)
{
} // getAncestor()


int Royals::getChildren(const char *name, int birthYear)
{
  return 0;
} // getSiblings()


void Royals::getDescendent(const char *ancestorName, int ancestorBirthYear,
    const char **descendentName, int *descendentBirthYear)
{
} //getDescedent()


int Royals::getMarriages(const char *name, int birthYear)
{
  return 0;
} // getSiblings()


int Royals::getSiblings(const char *name, int birthYear)
{
  return 0;
} // getSiblings()
