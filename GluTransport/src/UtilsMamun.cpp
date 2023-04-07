#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include<math.h>
# define PI    3.14159265358979323846

void drawCircle(GLfloat x, GLfloat y, GLfloat radius, GLfloat color[])
{
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

    int lineAmount = 5200;
	GLfloat twicePi = 2.0f * PI;

    glColor3f(color[0],color[1], color[2]);
	glBegin(GL_LINE_LOOP);
		for(int i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);

		}
	glEnd();

	glFlush();
}

void drawRingSpoke(GLfloat x, GLfloat y, GLfloat radius, int spokeCount, GLfloat color[])

{
    glColor3f(color[0],color[1], color[2]);
    glBegin(GL_LINES);
    GLfloat twicePi = 2.0f * PI;
    glVertex2f(x, y);
    for(int i = 0; i <=spokeCount; i++)
    {
        glVertex2f(x + radius * cos(i * twicePi / spokeCount), y + radius * sin(i * twicePi / spokeCount));
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}


void drawLine(GLfloat xStart, GLfloat yStart, GLfloat xEnd, GLfloat yEnd, GLfloat color[])
{
    glColor3f(color[0],color[1], color[2]);
    glBegin(GL_LINES);
    glVertex2f(xStart,yStart);
    glVertex2f(xEnd, yEnd);
    glEnd();
    glFlush();
}
