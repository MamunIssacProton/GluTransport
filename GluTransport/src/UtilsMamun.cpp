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

	//glFlush();
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
   // glFlush();
}


void drawLine(GLfloat xStart, GLfloat yStart, GLfloat xEnd, GLfloat yEnd, GLfloat color[])
{
    glColor3f(color[0],color[1], color[2]);
    glBegin(GL_LINES);
    glVertex2f(xStart,yStart);
    glVertex2f(xEnd, yEnd);
    glEnd();
   // glFlush();
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

void drawEdge(float start[],float End[], float color[])
{

    glColor3f(color[0],color[1], color[2]);
    glLineWidth(2.5f);
    glBegin(GL_LINES);

    glVertex2f(start[0],start[1]);
    glVertex2f(End[0], End[1]);
    glEnd();
    //glFlush();
}

void drawSurface(GLfloat layerStart[], GLfloat layerEnd[], GLfloat color[])
{
   glColor3f(color[0],color[1],color[2]);
   glRectf(layerStart[0],layerStart[1],layerEnd[0],layerEnd[1]);

  // glFlush();
}

void drawMarker(float startingPoints[],float endingPoints[],int markerCount, float color[],bool onladder)
{
    float width=endingPoints[0]-startingPoints[0];
    float height=endingPoints[1]-startingPoints[1];
    float space[]={((width/markerCount+1.3f)-1),height/(markerCount)};
    if(onladder)
    {
        space[0]=width/(markerCount-1);

    }

    float layerStart[2],layerEnd[2],spacing[2];
    spacing[0]=space[0];
    spacing[1]=space[1];

        for(int i=0;i<markerCount;i++)
       {
        layerStart[0]=startingPoints[0]+i*space[0];
        layerEnd[0]=layerStart[0]+width;
        layerStart[1]=startingPoints[1]+i*space[1];
        layerEnd[1]=layerStart[1]+height;
        drawSurface(layerStart,layerEnd,color);

      }



}

void DrawLadder(float startingPoints[],float endingPoints[],int stepCount, float color[])
{
    float width=endingPoints[0]-startingPoints[0];
    float height=endingPoints[1]-startingPoints[1];
    float stepHeight=height/stepCount;
    float space[]={width/stepCount,height/stepCount};
    float layerStart[2],layerEnd[2],spacing[2];
    spacing[0]=space[0];
    spacing[1]=0.0f;
    for(int i=0;i<stepCount;i++)
    {
        layerStart[0]=startingPoints[0]+i*spacing[0];
        layerEnd[0]=width-spacing[0];
        layerStart[1]=startingPoints[1]+i*stepHeight;
        layerEnd[1]=layerStart[1]+stepHeight;
        drawMarker(layerStart,layerEnd,stepCount-1,color,true);
    }
}


void drawCloudCircle(float centerX, float centerY, float radius, int numSegments)
 {
   glBegin(GL_TRIANGLE_FAN);
   for (int i = 0; i <= numSegments; i++)
        {
      float theta = ((float)i / (float)numSegments) * 2.0f * PI;
      float x = radius * cos(theta);
      float y = radius * sin(theta);
      glVertex2f(x + centerX, y + centerY);
   }
   glEnd();
}

void drawCloud(float centerX, float centerY, float radius )
{
    glColor3f(1.0f, 1.0f, 1.0f);
   drawCloudCircle(centerX, centerY, radius, 50);
   drawCloudCircle(centerX - radius / 2, centerY - radius / 3, radius / 2, 50);
   drawCloudCircle(centerX + radius / 2, centerY - radius / 3, radius / 2, 50);

   // Draw the cloud edges
   drawCloudCircle(centerX + radius / 3, centerY + radius / 3, radius / 2, 50);
   drawCloudCircle(centerX - radius / 3, centerY + radius / 3, radius / 2, 50);
}





void drawTriangle(float startX, float startY, float size, float color[])
 {

   float x1 = startX;
   float y1 = startY;
   float x2 = startX + size;
   float y2 = startY;
   float x3 = startX + (size / 2);
   float y3 = startY + size;

   glBegin(GL_TRIANGLES);
   glColor3f(color[0],color[1],color[2]);

   glVertex2f(x1, y1);
   glColor3f(0.0f, 1.0f, 0.0f);
   glVertex2f(x2, y2);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex2f(x3, y3);

   glEnd();
}
void drawTriangles(float startX,float startY,int count, float color[])
 {
   float spacing = 0.5f / (float)count;

   float size = spacing;


   for (int i = 0; i < count; i++)
   {
      drawTriangle(startX, startY, size,color);
      startX += spacing;
      size += spacing;
   }
}


void drawTextOnScreen(float position[],float color[],string text)
{
    glColor3f(color[0], color[1],color[2]);

    // Set text position
    glRasterPos2f(position[0], position[1]);

    // Draw text
//    glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);

    glFlush();
}

void drawBoat(float startX, float startY, float size, float color[] ) {
   glColor3f(color[0], color[1],color[2]);

   float width = size * 2.0f;
   float height = size * 1.0f;
   float midX = startX + width * 0.5f;
   float midY = startY + height * 0.5f;

   glBegin(GL_POLYGON);
   glVertex2f(startX, startY);                 
   glVertex2f(startX + width * 0.5f, startY);  
   glVertex2f(startX + width * 0.5f, midY + height * 0.1f);  
   glVertex2f(midX + width * 0.3f, midY + height * 0.1f);    
   glVertex2f(midX + width * 0.3f, midY + height * 0.3f);    
   glVertex2f(midX - width * 0.3f, midY + height * 0.3f);   
   glVertex2f(midX - width * 0.3f, midY + height * 0.1f);     
   glVertex2f(startX - width * 0.5f, midY + height * 0.1f);   
   glVertex2f(startX - width * 0.5f, startY);  

   glEnd();

   glBegin(GL_LINES);
   glVertex2f(midX, midY + height * 0.3f);   // Point J
   glVertex2f(midX, midY + height * 0.6f);   // Point K
   glEnd();

   glFlush();
}

