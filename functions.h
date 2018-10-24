#ifndef DEF_func
#define DEF_func
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <chrono>
#include <thread>
#include "mytypes.h"

void acii(void);
int c_lines(std::string const path);
int randx(int min,int max);

pdate* date(pdate* now=NULL);





class List
{
public:
	List();
	List(int first_member_value);

	void create_list(int first_member=0);
	bool push_back(int new_member = 0); // add the last member of list
	bool pop_back(void); // remove the last member of list
	bool pop_front(void); // remove the first element
	bool push_front(int new_member = 0); // add to the begining

	void print(void); // print the list

private:
	int element_count;
	list* first_member;
};


#endif