// GameOfLife.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<ctime>
#include<glut.h>
#include<freeglut.h>
#include "cell.h"

using namespace std;

cell life;

void initialize();
void calc();
void drawsquares();
void draw();
void TimerCalc(int value);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("The Game of Life");

	initialize();

	glutDisplayFunc(draw);
	glutTimerFunc(500, TimerCalc, 0);

	glutMainLoop();

	return 0;
}

void initialize()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, 10, 0, 10);
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawsquares();
	glutPostRedisplay();
	glutSwapBuffers();
	glFlush();
}

void TimerCalc(int value)
{
	calc();
	glutPostRedisplay();
	glutTimerFunc(500, TimerCalc, 0);
}

void calc()
{
	for (int i = 0; i < life.prev.size(); i++)
	{
		for (int j = 0; j < life.prev.size(); j++)
		{
			if (i == j)
			{
				continue;
			}

			if (life.prev[j].live)
			{
				if (life.prev[i].posx == life.prev[j].posx)
				{
					if (life.prev[i].posy == life.prev[j].posy + 1)
					{
						life.prev[i].count++;
					}

					if (life.prev[i].posy == life.prev[j].posy - 1)
					{
						life.prev[i].count++;
					}
				}

				if (life.prev[i].posy == life.prev[j].posy)
				{
					if (life.prev[i].posx == life.prev[j].posx + 1)
					{
						life.prev[i].count++;
					}

					if (life.prev[i].posx == life.prev[j].posx - 1)
					{
						life.prev[i].count++;
					}
				}

				if (life.prev[i].posx == life.prev[j].posx + 1)
				{
					if (life.prev[i].posy == life.prev[j].posy + 1)
					{
						life.prev[i].count++;
					}

					if (life.prev[i].posy == life.prev[j].posy - 1)
					{
						life.prev[i].count++;
					}
				}

				if (life.prev[i].posx == life.prev[j].posx - 1)
				{
					if (life.prev[i].posy == life.prev[j].posy + 1)
					{
						life.prev[i].count++;
					}

					if (life.prev[i].posy == life.prev[j].posy - 1)
					{
						life.prev[i].count++;
					}
				}
			}
		}
		if (life.prev[i].count < 2)
		{
			life.curr[i].live = false;
		}
		else if (life.prev[i].count > 3)
		{
			life.curr[i].live = false;
		}
		else if (life.prev[i].count == 3)
		{
			life.curr[i].live = true;
		}
		life.curr[i].count = 0;
	}

	life.prev = life.curr;

}

void drawsquares()
{
	for (int i = 0; i < life.curr.size(); i++)
	{
		if (life.curr[i].live)
		{
			glColor3f(0, 0, 0);
		}
		else
		{
			glColor3f(1, 1, 1);
		}
		glBegin(GL_QUADS);
			glVertex2i(life.curr[i].posx, life.curr[i].posy);
			glVertex2i(life.curr[i].posx + 1, life.curr[i].posy);
			glVertex2i(life.curr[i].posx + 1, life.curr[i].posy + 1);
			glVertex2i(life.curr[i].posx, life.curr[i].posy + 1);
		glEnd();
	}
}
