#include "stdafx.h"
#include "cell.h"


cell::cell()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			temp.count = 0;
			x = rand() % 2;

			if (x == 0)
			{
				temp.live = false;
			}
			else
			{
				temp.live = true;
			}

			temp.posx = i;
			temp.posy = j;

			prev.push_back(temp);
			curr.push_back(temp);
		}
	}
}

cell::~cell()
{
	prev.clear();
	curr.clear();
}
