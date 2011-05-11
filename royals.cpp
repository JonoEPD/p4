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
  n_child = 0;
  n_parent = 0;
}

Royals::Royals(const Person *people, int count) : hashTable(count*2)
{
  int i = 0;
  insertDriver(people,NULL,i,count);
}  // Royals()

void Royals::insertDriver(const Person *people, const Person *parent, int &i, int count)
{
  Royal * r_parent = NULL;
  if(parent != NULL)
    {
      r_parent = hashTable.array[hashTable.findPos(parent->name,parent->birthYear)].element;
    }
  Person root = people[i]; //root to recurse from
  bool exit = 0;
  while(!exit && i < count)
    {
      int length_i = strlen(people[i].ID);
      int length_r = strlen(root.ID);
      if(length_i > length_r) //new root
	{
	  insertDriver(people, &people[i-1], i, count); //people[i-1] is parent
	}
      else if(length_i == length_r) //siblings or equal root
	{
	  
	  if(hashTable.array[hashTable.findPos(people[i].name,people[i].birthYear)].info == 1) //not duplicate (EMPTY == 1)
	    {
	      hashTable.insert(new Royal(people[i]));
	      Royal * child = hashTable.array[hashTable.findPos(people[i].name,people[i].birthYear)].element;
	      if(r_parent != NULL) //if not root
		{
		  r_parent->children[r_parent->n_child] = child;
		  r_parent->n_child++;
		  child->parents[0] = r_parent; //parents = 0 if empty
		  child->n_parent++;
		}
	    }
	  else //parents > 0
	    {
	      Royal * child = hashTable.array[hashTable.findPos(people[i].name,people[i].birthYear)].element;
	      if((child->parents[0] != r_parent) && (child->n_parent != 2)) //not duplicate
		{
		  r_parent->children[r_parent->n_child] = child;
		  r_parent->n_child++;
		  child->parents[1] = r_parent;
		  child->n_parent++;
		}
	    }
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
  int tmp = hashTable.findPos(name, birthYear);
  return hashTable.array[tmp].element->n_child;
} // getSiblings()


void Royals::getDescendent(const char *ancestorName, int ancestorBirthYear,
    const char **descendentName, int *descendentBirthYear)
{
  int pos = hashTable.findPos(ancestorName,ancestorBirthYear);
  Royal * a = hashTable.array[pos].element; 
  int n_c = a->n_child;
  if(n_c == 0) //no more descendents
    {
      	  if(*descendentBirthYear < a->birthYear || *descendentBirthYear == 0)
	    {
	      *descendentBirthYear = a->birthYear;
	      *descendentName = a->name;
	    }
    }
  else//more descendents
    {
      for(int i = 0; i < n_c; i++)
	{
	  getDescendent(a->children[i]->name,a->children[i]->birthYear,descendentName,descendentBirthYear);
	}
    }
  
} //getDescedent()


int Royals::getMarriages(const char *name, int birthYear)
{
  int tmp = hashTable.findPos(name, birthYear); //no idea why +1
  return hashTable.array[tmp].element->spouseCount;
} // getSiblings()


int Royals::getSiblings(const char *name, int birthYear)
{
  //siblings ordered by bday
  int pos = hashTable.findPos(name, birthYear);
  Royal * c = hashTable.array[pos].element;

  if(c->n_parent == 0) //root monarch
    return 0;
  else if(c->n_parent == 1)
    {
      return (c->parents[0]->n_child - 1);
    }
  else //n_parent == 2 
    {
      Royal *p1 = c->parents[0];
      Royal *p2 = c->parents[1];
      int n1 = p1->n_child;
      int n2 = p2->n_child;
      int i=0,j=0;
      int doubles = 0;
      while(i != n1 && j != n2)
	{
	  if(p1->children[i] == p2->children[j])
	    {
	      doubles++;
	      i++;
	      j++;
	    }
	  else //!=
	    {
	      if(p1->children[i]->birthYear <= p2->children[j]->birthYear)
		{
		  i++;
		}
	      else // n1 > n2
		{
		  j++;
		}
	    }
	}
      return (n1+n2-doubles-1); //subtract doubles, you aren't a sibling
    }

} // getSiblings()
