//Первый контейнер - multimap
//Второй контейнер - set


#include "stdafx.h"
#include <iostream>
#include <map>
using namespace std;

class Str :public multimap<char*, int>
{
public:
	void write()
	{
		for (auto iter = begin(); iter != end(); iter++)
		{
			cout << iter->first << " : ";
			cout << iter->second << endl;
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

	Map.insert(pair<char*, int>("str1", 1));
	Map.insert(pair<char*, int>("str1", 2));
	Map.insert(pair<char*, int>("str2", 3));
	cout << "Map: " << endl;
	Map.write();
	cout << endl;

	cout << "Delete str1: " << endl;
	Map.erase("str1");
	Map.write();
	cout << endl;

	cout << "Insert str1111: " << endl;
	Map.insert(pair<char*, int>("str1111", 10));
	Map.write();
	cout << endl;


	cout << "\n\n\n";
	cout << "Map2 clear: "<<endl;
	Map2.write();

	cout << "New container: " << endl;
	Map2.swap(Map, Map2);
	Map2.write();
	
}