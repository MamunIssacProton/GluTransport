#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include<math.h>
# define PI    3.14159265358979323846

void drawCircle(GLfloat x, GLfloat y, GLfloat radius, GLfloat color[], bool isFilledColor)
{

    int lineAmount = 5200;
	GLfloat twicePi = 2.0f * PI;

    glColor3f(color[0],color[1], color[2]);
    if(isFilledColor)
    {
        glBegin(GL_POLYGON);
    }
    else
    {
        glBegin(GL_LINE_LOOP);
    }

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


void drawRectangle(GLfloat x, GLfloat y, GLfloat width, GLfloat height, GLfloat color[])
{
    GLfloat lowerStartX=x;
    GLfloat lowerStartY=y;

    GLfloat lowerEndX=x+width;
    GLfloat lowerEndY=y;

    GLfloat upperStartX=x;
    GLfloat upperStartY=y+height;

    GLfloat upperEndX=upperStartX+width;
    GLfloat upperEndY=upperStartY;

    drawLine(lowerStartX,lowerStartY,lowerEndX,lowerEndY,color);
    drawLine(upperStartX,upperStartY,upperEndX,upperEndY,color);

    drawLine(lowerStartX,lowerStartY,upperStartX,upperEndY,color);
    drawLine(lowerEndX,lowerEndY,upperEndX,upperEndY,color);
}

void drawSurface(GLfloat first[], GLfloat second[], GLfloat third[], GLfloat fourth[], GLfloat color[] )
{
     glBegin(GL_QUADS);
     glColor3f(color[0],color[1], color[2]);
     glVertex2f(first[0],first[1]);
     glVertex2f(second[0],second[1]);
     glVertex2f(third[0], third[1]);
     glVertex2f(fourth[0],fourth[1]);

     glEnd();
}

void drawCloud(GLfloat startX, GLfloat startY, GLfloat r, GLfloat color[] )
{
//    for(int i=0;i<2;i++)
//    {
//
//        startX+=
//    }
     drawCircle(startX,startY,r,color,true);
     drawCircle(startX+.4f,startY,r+.1f,color, true);
     drawCircle(startX+.2f, startY-.1f,r-.1f,color,true);
}

void drawTriangle(GLfloat startX, GLfloat startY, GLfloat highX, GLfloat highY, GLfloat endX,GLfloat endY, GLfloat color[])
{
    glBegin(GL_TRIANGLES);
    glColor3f(color[0],color[1], color[2]);
    glVertex2f(startX, startY);
    glVertex2f(highX,highY);
    glVertex2f(endX,endY);
    glEnd();

}

