// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<map>
#include<string>
#include"extend.h"
using namespace std;
int main(int argc, char* argv[])
{
	string in;
	int characters = 0;
	int words = 0;
	int lines = 0;
	if (argc == 1)
	{
		in = "input.txt";
	}
	else
	{
		in = argv[1];
	}
	Zsn zsn(in);
	characters = zsn.charact();
	words = zsn.word();
	lines = zsn.line();
	zsn.top10();
	return 0;
}
/*int charact(string fname)//？？ 
{
	FILE *fin;
	int countcharact = 0;
	char achar;
	fopen_s(&fin, fname.c_str(), "r");
	int getchar = fread(&achar, 1, 1, fin);//用1？ 
	while (getchar)
	{
		countcharact++;
		getchar = fread(&achar, 1, 1, fin);
	}
	fclose(fin);
	return countcharact;
}

int line(string fname)
{
	FILE *fin;
	int countline = 0;
	char achar;
	fopen_s(&fin, fname.c_str(), "r");
	int getchar = fread(&achar, 1, 1, fin);
	while (getchar)
	{
		if (achar >= 33)	isline = true;
		if (achar == '\n'&&isline == true)
		{
			countline++;
			isline = false;
		}
		getchar = fread(&achar, 1, 1, fin);
	}
	if (isline == true)
	{
		countline++;
		isline = false;
	}
	fclose(fin);
	return countline;
}




int word(string fname)
{
	FILE *fin;
	int countword = 0;
	char achar;
	bool wordjudge = false;
	fopen_s(&fin, fname.c_str(), "r");
	int i = 0, j = 0;
	int getchar = fread(&achar, 1, 1, fin);
	while (getchar)
	{
		if ((achar <= 57 && achar >= 48) || (achar >= 65 && achar <= 90) || (achar >= 97 && achar <= 122))//
		{
			j++;
			if ((achar >= 65 && achar <= 90) || (achar >= 97 && achar <= 122))
			{
				i++;
			}
			if (j == 4 && i == 4)
			{
				wordjudge = true;
			}//判断是否为单词 

		}
		else
		{
			if (wordjudge == true)
			{
				countword++;
				wordjudge = false;
			}
			i = j = 0;
		}
		getchar = fread(&achar, 1, 1, fin);
	}
	if (wordjudge == true)
	{
		countword++;
		wordjudge = false;
		i = j = 0;
	}
	fclose(fin);
	cout << countword << endl;
	cin >> countword;
	return countword;
}

void top10(string fname)
{
	FILE *fin;
	char achar;
	bool wordjudge = false;
	char ex[2];
	char word[100];memset(word, '\0', 100);
	fopen_s(&fin, fname.c_str(), "r");
	map<string, int>map1;
	int i = 0, j = 0;
	int getchar = fread(&achar, 1, 1, fin);
	while (getchar)
	{
		if ((achar <= 57 && achar >= 47) || (achar >= 65 && achar <= 90) || (achar >= 97 && achar <= 122))//
		{
			++j;
			if ((achar >= 65 && achar <= 90) || (achar >= 97 && achar <= 122))
			{
				i++;
			}
			if (j == 4 && i == 4)
			{
				wordjudge = true;
			}//判断是否为单词 
			memset(ex, '\0', 2);
			ex[0] = achar;
			strcat_s(word, strlen(word) + strlen(ex) + 1, ex);
		}
		else
		{
			if (wordjudge == true)
			{
				if (!map1[word])
				{
					map1[word] = 1;
				}
				else
				{
					map1[word]++;
				}
				wordjudge = false;
			}
			i = j = 0;
			memset(word, '\0', 100);
		}
		getchar = fread(&achar, 1, 1, fin);
	}
	if (wordjudge == true)
	{
		if (!map1[word])
		{
			map1[word] = 1;
		}
		else
		{
			map1[word]++;
		}
		wordjudge = false;
	}
	fclose(fin);
	//排序
	map<string, int>::iterator iter1;
	map<string, int>::iterator iter2;

	iter1 = map1.begin();

	for (i = 1;i <= 10;i++)
	{

		if (map1.size() < i) break;
		for (iter2 = map1.begin();iter2 != map1.end();iter2++)
		{
			if (iter2->second > iter1->second)
			{
				iter1 = iter2;
			}
		}
		cout << "<" << iter1->first << ">: " << iter1->second << endl;
		iter1->second = 0;
		iter1 = map1.begin();
	}
	cin >> achar;
}


*/



