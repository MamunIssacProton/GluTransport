#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include<math.h>
#include<UtilsMamun.h>
GLfloat xBack=-0.3f;
GLfloat yBack=-0.2f;
GLfloat r=-0.2f;

int spokeCount=10;

GLfloat xStartWheelsConnector=-0.2489f;
GLfloat yStartWheelConnector=-0.2f;

GLfloat xEndWheelsConnector=0.6;
GLfloat yEndWheelConnector=-0.2f;

GLfloat xStartBackWheelLeftRodConnector=-0.3f;
GLfloat yStartBackWheelLeftRodConnector=-0.2f;

GLfloat xEndBackWheelLeftRodConnector=-0.2f;
GLfloat yEndtBackWheelLeftRodConnector=0.2f;


//Front side first wheel
GLfloat xStartFrontWheelRightRodConnector=0.6f;
GLfloat yStartFrontWheelRightRodConnector=-0.2f;

GLfloat xEndFrontWheelRightRodConnector=0.3f;
GLfloat yEndtFrontWheelRightRodConnector=0.2f;

GLfloat xBackUpperLeftRodConnector=-0.2f;
GLfloat yBackUpperLeftRodConnector=0.2f;

GLfloat xFrontUpperRightRodConnector=0.3f;
GLfloat yFrontUpperRightRodConnector=0.2f;

GLfloat greenColor[]={0.0f, 0.9f, 0.2f};
GLfloat redColor[]={0.9f, 0.2f, 0.3f};
GLfloat blackColor[]={0.2f,0.1f,0.4f};
void RenderBackWheel()
{
    drawCircle(xBack,yBack,r,greenColor);

    drawRingSpoke(xBack,yBack,r,spokeCount,redColor);

}

void RenderPartsConnector()
{
    //lower rod connected to the wheels

    drawLine(xStartWheelsConnector, yStartWheelConnector,xEndWheelsConnector, yEndWheelConnector, blackColor);

    // left rod connected to back wheel

    drawLine(xStartBackWheelLeftRodConnector, yStartBackWheelLeftRodConnector,xEndBackWheelLeftRodConnector, yEndtBackWheelLeftRodConnector, blackColor);

    //right rod front wheel

    drawLine(xStartFrontWheelRightRodConnector, yStartFrontWheelRightRodConnector,xEndFrontWheelRightRodConnector, yEndtFrontWheelRightRodConnector, blackColor);
//

    drawLine(xFrontUpperRightRodConnector, yFrontUpperRightRodConnector,xBackUpperLeftRodConnector, yBackUpperLeftRodConnector, blackColor);
}

