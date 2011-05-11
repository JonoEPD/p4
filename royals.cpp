// Author: Sean Davis

#include "royals.h"
#include "RunRoyals.h"
#include <iostream>
#include "QuadraticProbing.h"
#include <cstring>

using namespace std;

Royal::Royal()
{
  name[0] = '\0'; //null string
}

Royal::Royal(const Person &x)
{
  strcpy(name,x.name);
  spouseCount = x.spouseCount;
}

Royals::Royals(const Person *people, int count) : hashTable(count*2)
{
  for(int i = 0; i < count; i++)
    {
      hashTable.insert(new Royal(people[i]));
    }
  for(int i = 0; i < count; i++)
    {
     
    }
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
  int tmp = hashTable.findPos(name)-1; //no idea why +1
  return hashTable.array[tmp].element->spouseCount;
} // getSiblings()


int Royals::getSiblings(const char *name, int birthYear)
{
  return 0;
} // getSiblings()
