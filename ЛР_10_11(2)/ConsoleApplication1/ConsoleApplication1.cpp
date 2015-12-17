//Первый контейнер - multimap
//Второй контейнер - set
//Втроенный тип данных - float

#include "stdafx.h"
#include <iostream>
#include "button.h"
#include <map>
using namespace std;

class string
{
	int str;
	int operator >> (const string &a)
	{
		str = rand() % 10;
		return 0;
	}
	void operator << (const string &a)
	{
		
		cout << str;
		cout << endl;
	}
};

class Str :public multimap<char*, button>
{
private:
	button but;
public:
	void write()
	{
		for (auto iter = begin(); iter != end(); iter++)
		{
			cout << iter->first << " : ";
			cout << iter->second.but << endl;
		}
	}

	void ddelete(int first, int end)
	{
		auto iter = begin();
		for (int i = 0; i < end; i++)
		{
			if (i >= first - 1)
			{
				erase(iter++);
			}
			else iter++;
		}
	}

	void swap(Str &x, Str &y)
	{
		auto iter1 = x.begin();
		auto iter2 = x.end();

		y.insert(iter1, iter2);
	}
};


void main()
{
	setlocale(LC_CTYPE, "rus");

	Str Map;
	Str Map2;

	Map.insert(pair<char*, button>("str1", 1));
	Map.insert(pair<char*, button>("str1", 2));
	Map.insert(pair<char*, int>("str2", 3));
	cout << "Map: " << endl;
	Map.write();
	cout << endl;

	cout << "Delete str1: " << endl;
	Map.erase("str1");
	Map.write();
	cout << endl;

	cout << "Insert str1111: " << endl;
	Map.insert(pair<char*, button>("str1111", 10));
	Map.write();
	cout << endl;


	cout << "\n\n\n";
	cout << "Map2 clear: "<<endl;
	Map2.write();

	cout << "New container: " << endl;
	Map2.swap(Map, Map2);
	Map2.write();
	
}