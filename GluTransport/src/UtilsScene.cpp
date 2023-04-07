#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include<math.h>
#include<UtilsMamun.h>
GLfloat xBack=-0.3f;
GLfloat yBack=-0.2f;
GLfloat r=-0.2f;

int spokeCount=10;

GLfloat greenColor[]={0.0f, 0.9f, 0.2f};
GLfloat redColor[]={0.9f, 0.2f, 0.3f};

void RenderBackWheel()
{
    drawCircle(xBack,yBack,r,greenColor);

    drawRingSpoke(xBack,yBack,r,spokeCount,redColor);

}
