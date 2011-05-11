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
  birthYear = x.birthYear;
  spouseCount = x.spouseCount;
}

Royals::Royals(const Person *people, int count) : hashTable(count*2)
{
  int i = 0;
  insertDriver(people,i,count);
}  // Royals()

void Royals::insertDriver(const Person *people, int &i, int count)
{
  Person root = people[i]; //root to recurse from
  bool exit = 0;
  while(!exit && i < count)
    {
      int length_i = strlen(people[i].ID);
      int length_r = strlen(root.ID);
      if(length_i > length_r) //new root
	{
	  insertDriver(people, i, count);
	}
      else if(length_i == length_r) //equal -- siblings with root
	{
	  hashTable.insert(new Royal(people[i]));
	  i++;
	}
      else //less, recurse back
	{
	  exit = 1;
	}
    }
}


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
  int tmp = hashTable.findPos(name, birthYear); //no idea why +1
  return hashTable.array[tmp].element->spouseCount;
} // getSiblings()


int Royals::getSiblings(const char *name, int birthYear)
{
  return 0;
} // getSiblings()
