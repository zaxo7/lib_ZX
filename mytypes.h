#ifndef DEF_MYTYPES
#define DEF_MYTYPES

struct zpos
{
	int x;
	int y;
	int z;
};
typedef struct zpos zpos;

struct pdate
{
	int second;
	int minute;
	int hour;

	int day;
	int month;
	int year;
};
typedef struct pdate pdate;

struct list
{
	list *prev;
	int member;
	list *next;
};
typedef struct list list;

#endif