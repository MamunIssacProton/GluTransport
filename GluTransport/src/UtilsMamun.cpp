#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include<math.h>
# define PI    3.14159265358979323846
#include<iostream>
using namespace std;
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

    cout<<lowerStartX<<endl;
    cout<<lowerStartY<<endl;
    cout<<upperStartX<<endl;
    cout<<upperStartY<<endl;
}
void drawRectangleInPixel(GLfloat x, GLfloat y, GLint pixelWidth, GLint pixelHeight, GLfloat color[3]) {
    // Calculate the width and height in the range of -1 to 1
    GLfloat width = 2.0f * pixelWidth / glutGet(GLUT_WINDOW_WIDTH) - 1.0f;
    GLfloat height = 2.0f * pixelHeight / glutGet(GLUT_WINDOW_HEIGHT) - 1.0f;

    // Set the color of the rectangle
    glColor3f(color[0], color[1], color[2]);

    // Draw the rectangle using lines
    glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x + width, y);

    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);

    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);

    glVertex2f(x, y + height);
    glVertex2f(x, y);
    glEnd();
}

void drawSurface(GLfloat first[], GLfloat second[], GLfloat third[], GLfloat fourth[], GLfloat color[] )
{

//     glColor3f(color[0],color[1], color[2]);
//    glRectf(first[0],first[1],second[0],second[1]);
glClear(GL_COLOR_BUFFER_BIT); // clear the color buffer

   glColor3f(1.0f, 0.0f, 0.0f); // set the color to red
   glRectf(-0.5f, -0.5f, 0.5f, 0.5f); // draw a rectangle from (-0.5,-0.5) to (0.5,0.5)

   glFlush();
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


