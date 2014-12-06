#pragma once
#include<iostream>
#include<vector>
#include<ctime>
#include<glut.h>
#include<freeglut.h>

using namespace std;

class cell
{
public:
	cell();

	struct cells
	{
		int posx, posy, count;
		bool live;
	} temp;

	vector<cells> prev, curr;
	int x;

	~cell();
};

