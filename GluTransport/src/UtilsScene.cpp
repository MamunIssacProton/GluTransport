#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include<math.h>
#include<UtilsMamun.h>
GLfloat xBack=-0.3f;
GLfloat yBack=-0.2f;

GLfloat xFront=0.6f;
GLfloat yFront=-0.2f;
GLfloat r=-0.2f;

GLfloat steeringX=0.21f;
GLfloat steeringY=0.3f;

GLfloat steeringFirstStartX=0.19f;
GLfloat steeringFirstStartY=0.25f;

GLfloat steeringFirstEndX=0.23f;
GLfloat steeringFirstEndY=0.33f;

GLfloat steeringLastStartX=0.26f;
GLfloat steeringLastStartY=0.27f;


GLfloat steeringLastEndX=0.17f;
GLfloat steeringLastEndY=0.32f;

GLfloat steeringStartX=0.3f;
GLfloat steeringStartY=0.2f;
GLfloat steeringEndX=0.22f;
GLfloat steeringEndY=0.31f;

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
//GLfloat cloudyColor[]={0.09f,0.88f,0.9f};
GLfloat cloudyColor[]={0.0973f,0.973f,0.996f};
//container

GLfloat containerX=-0.7f;
GLfloat containerY=0.21f;

GLfloat containerWidth=0.3f;
GLfloat containerHeight=0.2f;


GLfloat tailStartX=-0.7f;
GLfloat tailStartY=0.2f;

GLfloat tailEndX=-0.2f;
GLfloat tailEndY=0.2f;

//seat
GLfloat seatRodStartX=-0.2f;
GLfloat seatRodStartY=0.2f;

GLfloat seatRodEndX=-0.199f;
GLfloat seatRodEndY=0.3f;

GLfloat seatStartX=-0.24f;
GLfloat seatStartY=0.3f;

GLfloat seatEndX=-0.16f;
GLfloat seatEndY=0.3f;

GLfloat cloudStartX=0.44f;
GLfloat cloudStartY=0.79f;
GLfloat cloudRadius=.2f;


GLfloat mountainStartX=-0.9;
GLfloat mountainStartY=0.6;
GLfloat mountainHighX=-0.7f;
GLfloat mountainHighY=0.9f;
GLfloat mountainEndX=-0.5f;
GLfloat mountainEndY=0.6f;

GLfloat roadFirst[]={-1.0f,-0.5f};
GLfloat roadSecond[]={-0.84f,-0.3f};
GLfloat roadThird[]={1.0f,-1.0f};
GLfloat roadFourth[]={1.0f,-0.5f};
void RenderBackWheel()
{
    drawCircle(xBack,yBack,r,greenColor,false);

    drawRingSpoke(xBack,yBack,r,spokeCount,redColor);

}

void RenderFrontWheel()
{
    drawCircle(xFront,yFront,r,greenColor,false);

    drawRingSpoke(xFront,yFront,r,spokeCount,redColor);
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

void RenderContainer()
{

    drawRectangle(containerX,containerY,containerWidth,containerHeight,greenColor);
}

void RenderTail()
{
    drawLine(tailStartX,tailStartY,tailEndX,tailEndY,blackColor);
}

void RenderSeat()
{
    drawLine(seatRodStartX,seatRodStartY,seatRodEndX,seatRodEndY,redColor);
    drawLine(seatStartX,seatStartY,seatEndX, seatEndY,blackColor);
}
void RenderSteering()
{
    drawCircle(steeringX,steeringY,0.05f,greenColor,false);
    drawLine(steeringFirstStartX,steeringFirstStartY,steeringFirstEndX,steeringFirstEndY,blackColor);
    drawLine(steeringLastStartX,steeringLastStartY,steeringLastEndX,steeringLastEndY,blackColor);
    drawLine(steeringStartX, steeringStartY, steeringEndX, steeringEndY,blackColor);
}

void RenderCloud()
{
     drawCloud(cloudStartX,cloudStartY,cloudRadius,cloudyColor);
}

void RenderRoad()
{
    drawSurface(roadFirst,roadSecond,roadThird, roadFourth,blackColor);
}

void RenderMountain()
{
    for(int i=0; i<3; i++)
    {
        drawTriangle(mountainStartX,mountainStartY,mountainHighX, mountainHighY, mountainEndX, mountainEndY,blackColor);
        mountainStartX+=0.3f;
        mountainHighX+=0.2f;

    }

}

void RenderBridge()
{

}


