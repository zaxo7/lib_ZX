#include "functions.h"

int oldsec = 0;

int c_lines(std::string const path)
{
	int l=0;
	char c;

	std::ifstream F2(path.c_str());

	do
	{
		c=F2.get();
		if(c=='\n')
		{
			l++;
		}
	}while(c!=EOF);
	return l;
}
int randx(int min,int max)
{
	return (rand() % (min - max)) + min;
}
pdate* date(pdate* now)
{
	int sec = time(0) - oldsec;
    int mode = 0;
    if(now == NULL)
    {
    	now = (pdate *)malloc(sizeof(now));
    	mode = 1;
    }

    //std::cout << "start at :" << time(0) << std::endl;

	int leap = 2;
	if(oldsec == 0)
	{
		now->hour = 1; //for GMT+1
		now->day = 0;
		now->month = 1;
		now->year = 1970;
	}
	oldsec = time(0);
	for (int i = sec; i >= 0; i--)
	{
		if (now->second >= 59)
		{
			now->second = 0;

			if (now->minute >= 59)
			{
				now->minute = 0;

				if (now->hour >= 23)
				{
					now->hour = 0;

					if ((now->month == 1 || now->month == 3 || now->month == 5 || now->month == 7 || now->month == 8 || now->month == 10 || now->month == 12  ) && (now->day == 31))
					{
						now->day = 1;
						if (now->month >= 12)
						{
							now->month = 1;
							now->year++;
							if (leap >= 4)
							{
								leap = 1;
							}
							else
							{
								leap++;
							}
						}
						else
						{
							now->month++;
						}
					}
					else if ((now->month == 4 || now->month == 6 || now->month == 9 || now->month == 11) && (now->day == 30))
					{
						now->day = 1;
						if (now->month == 12)
						{
							now->month = 1;
							now->year++;
							if (leap >= 4)
							{
								leap = 1;
							}
							else
							{
								leap++;
							}
						}
						else
						{
							now->month++;
						}
					}
					else if (now->month == 2)
					{
						if ((leap == 4) && ((now->year % 100) != 0))
						{
							if (now->day >= 29)
							{
								now->day = 1;
								if (now->month >= 12)
								{
									now->month = 1;
									now->year++;
									if (leap >= 4)
									{
										leap = 1;
									}
									else
									{
										leap++;
									}
								}
								else
								{
									now->month++;
								}
							}
							else
							{
								now->day++;
							}
						}
						else
						{
							if (now->day == 28)
							{
								now->day = 1;
								if (now->month >= 12)
								{
									now->month = 1;
									now->year++;
									if (leap >= 4)
									{
										leap = 1;
									}
									else
									{
										leap++;
									}
								}
								else
								{
									now->month++;
								}
							}
							else
							{
								now->day++;
							}

						}
					}
					else
					{
						now->day++;
					}
				}
				else
				{
					now->hour++;
				}
			}
			else
			{
				now->minute++;
			}
		}
		else
		{
			now->second++;
		}
	}

	if(!mode)
	{
		std::cout << now->hour << ":" << now->minute << ":" << now->second  << " GMT+1      ";
		std::cout << now->day << "/" << now->month << "/" << now->year;
		return NULL;
	}
	{
		return now;
	}
	//std::cout << "\nend at :" << time(0) << std::endl;
}



//////////// Liste chainée

List::List()
{
	create_list();
}
List::List(int first_member_value)
{
	create_list(first_member_value);
	element_count = 0;
}

void List::create_list(int first_member_value)
{
	first_member = (list*)malloc(sizeof(list));

	first_member->member = first_member_value;

	first_member->prev = NULL;
	first_member->next = NULL;

}

bool List::push_back(int new_member)
{
	if (first_member == NULL)
	{
		return 0;
	}

	list* current_member=first_member;
	loop:if(current_member->next == NULL)
	{
		current_member->next = (list*)malloc(sizeof(list));

		current_member->next->member = new_member;

		current_member->next->prev = current_member;
		current_member->next->next = NULL;
	}
	else
	{
		current_member = current_member->next;

		goto loop;
	}

	return 1;
}

bool List::pop_back(void)
{
	if (first_member == NULL)
	{
		return 0;
	}

	list* current_member=first_member;
	loop:if(current_member->next == NULL)
	{

		current_member = current_member->prev;

		free(current_member->next);
		
		current_member->next = NULL;
	}
	else
	{
		current_member = current_member->next;

		goto loop;
	}

	return 1;
}

bool List::pop_front()
{
	if (first_member == NULL)
	{
		return 0;
	}

	list* current_first_member = first_member;
	
	free(current_first_member);

	first_member = first_member->next;

	first_member->prev = NULL;

	return 1;
}

bool List::push_front(int new_member)
{
	if (first_member == NULL)
	{
		return 0;
	}

	list* oldfirst = first_member;

	first_member->prev = (list*)malloc(sizeof(list));

	first_member = first_member->prev;

	first_member->prev = NULL;
	first_member->next = oldfirst;

	first_member->member = new_member;

	return 1;
}


void List::print(void)
{
	list *current_member = first_member;
	
		loop:if(current_member->next == NULL)
		{
		std::cout << current_member->member;
		}
		else
		{
			std::cout << current_member->member << " < ";
			current_member = current_member->next;
			goto loop;
		}

	std::cout << std::endl;
}

