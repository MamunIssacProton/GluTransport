#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include<math.h>
#include<UtilsMamun.h>
#include<iostream>
using namespace std;
float canvasX=-1.0f;
float canvasY=1.0f;

float canvasHeight=0.5f;
float canvasWidth=0.7f;

float firstLayerStart[]={-1.0f,0.4f};
float firstLayerEnd[]={1.0f,1.0f};

float secondLayerStart[]={-1.0f,-0.5f};
float secondLayerEnd[]={1.0f,0.4f};


float thirdLayerStart[]={-1.0f,-1.0f};
float thirdLayerEnd[]={1.0f,-0.5f};

float roadStart[]={-1.0f, -0.3f};
float roadEnd[]={1.0f,0.25f};
float roadMarkerStart[]={-0.8f,0.0f};
float roadMarkerEnd[]={-0.7f,0.02f};
float bridgeStart[]={0.37f,-0.3f};
float bridgeEnd[]={0.63f,0.25f};
float riverStart[]={0.4f,-0.6f};
float riverEnd[]={0.6f,0.4f};

float boatStart[]={-0.9f,-0.9f};

float wareHouse[]={-0.95f,-0.4f};
float wareHouseBoundaryStart[]={-0.9f,-0.5f};
float wareHouseBoundaryEnd[]={-0.7f,-0.3f};

float shop[]={0.65f,0.5f};
float shopBoundaryStart[]={0.7f,0.3f};
float shopBoundaryEnd[]={0.9f,0.6f};

float cloud[]={0.1f,0.8f,0.25f};

float velocityX=0.1f;
float wheelBack[]={-0.75f,-0.0f};
float wheelFront[]={-0.35f,-0.0f};


float connectorBackFront[2][2]={{wheelBack[0],wheelBack[1]},
                                {wheelFront[0],wheelFront[1]}};

float connectorFrontUpper[2][2]={{wheelFront[0],wheelFront[1]}, {-.45f,0.3f}};

float connectorUpperToUpperLeft[2][2]={ {-.41f,0.2f},{-0.65f,0.2f}};

float connectorUpperLeftToBack[2][2]={{-0.65f,0.2f},{wheelBack[0],wheelBack[1]}};

float carrier[2][2]={{-0.68f,0.15f},{-0.95f,0.15f}};

float connectorFrontToUpperRod[]{wheelFront[1],0.42f,0.64f,0.16f};

float steering[3][2]={{-.45f,0.3f},
                      {-0.5,0.3f},
                      {-0.4f,0.3f},
                     };
float seat[2][2]={{-0.68f,0.2f},{-0.61f,0.23f}};
float container[2][2]={{-0.93f,0.15f},{-0.69f,0.32f}};

//float steering
//GLfloat xFront=0.6f;
//GLfloat yFront=-0.2f;
float r=-0.09f;

float titlePos[]={100,100};
float contributorsPos[4][2]={{100,120},{100,140}};

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

float greenColor[]={0.0f, 0.9f, 0.2f};
float redColor[]={0.9f, 0.2f, 0.3f};
float blackColor[]={0.2f,0.1f,0.4f};
float cloudyColor[]={0.0973f,0.973f,0.996f};
float skyColor[]={0.6f,0.8f,1.0f};
float waterColor[]={0.3f,0.6f,0.9f};
float whiteColor[]={1.0f,1.0f,1.0f};
float roadColor[]={0.1f,0.3,0.4f};
float limeColor[]={0.1f,1.0f,0.3f};
float orangeColor[]={0.9f,0.5f,0.2f};
//container
//
//GLfloat containerX=-0.7f;
//GLfloat containerY=0.21f;
//
//GLfloat containerWidth=0.3f;
//GLfloat containerHeight=0.2f;
//
//
//GLfloat tailStartX=-0.7f;
//GLfloat tailStartY=0.2f;
//
//GLfloat tailEndX=-0.2f;
//GLfloat tailEndY=0.2f;
//
////seat
//GLfloat seatRodStartX=-0.2f;
//GLfloat seatRodStartY=0.2f;
//
//GLfloat seatRodEndX=-0.199f;
//GLfloat seatRodEndY=0.3f;
//
//GLfloat seatStartX=-0.24f;
//GLfloat seatStartY=0.3f;
//
//GLfloat seatEndX=-0.16f;
//GLfloat seatEndY=0.3f;

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
      drawCircle(wheelBack[0],wheelBack[1],r,whiteColor,false);

      drawRingSpoke(wheelBack[0],wheelBack[1],r,spokeCount,whiteColor);

}

void RenderFrontWheel()
{
    drawCircle(wheelFront[0],wheelFront[1],r,whiteColor,false);

    drawRingSpoke(wheelFront[0],wheelFront[1],r,spokeCount,whiteColor);
}

void RenderPartsConnector()
{

    drawEdge(connectorBackFront[0],connectorBackFront[1],limeColor);
    drawEdge(connectorFrontUpper[0],connectorFrontUpper[1],limeColor);
    drawEdge(connectorUpperToUpperLeft[0],connectorUpperToUpperLeft[1],limeColor);
    drawEdge(connectorUpperLeftToBack[0],connectorUpperLeftToBack[1],limeColor);
    drawEdge(carrier[0],carrier[1],orangeColor);
}

void RenderContainer()
{
    drawSurface(container[0],container[1],limeColor);
}

void RenderTail()
{
//    drawLine(tailStartX,tailStartY,tailEndX,tailEndY,blackColor);
}

void RenderSeat()
{

    drawSurface(seat[0],seat[1],redColor);
}
void RenderSteering()
{
    drawCircle(steering[0][0],steering[0][1],0.05f,orangeColor,false);
    drawEdge(steering[1],steering[2],limeColor);
}

void RenderCloud()
{
    drawCloud(cloud[0],cloud[1],cloud[2]);
}

void RenderRoad()
{
    drawSurface(roadStart,roadEnd,roadColor);

   // DrawLadder(roadStart,roadEnd,10,redColor);
     drawMarker(roadMarkerStart,roadMarkerEnd,4,redColor,false);
     drawSurface(bridgeStart,bridgeEnd,greenColor);
}
void RenderCanvas()
{
    drawSurface(firstLayerStart,firstLayerEnd,skyColor);
    drawSurface(secondLayerStart,secondLayerEnd,whiteColor);
    drawSurface(thirdLayerStart,thirdLayerEnd,waterColor);
}

void RenderMountains()
{
    drawTriangles(firstLayerStart[0],firstLayerStart[1],3,greenColor);
}

void RenderBridge()
{
    drawSurface(bridgeStart,bridgeEnd,greenColor);
}
void RenderWarehouse()
{
    drawSurface(wareHouseBoundaryStart,wareHouseBoundaryEnd,greenColor);
    drawTriangle(wareHouse[0],wareHouse[1],.3f,redColor);

}

void RenderShop()
{

    drawSurface(shopBoundaryStart,shopBoundaryEnd,greenColor);
    drawTriangle(shop[0],shop[1],.3f,redColor);
}
void RenderVehicle()
{
    glPushMatrix();
        RenderFrontWheel();
        RenderBackWheel();
        RenderPartsConnector();
        RenderSteering();
        RenderSeat();
        RenderContainer();
glPopMatrix();
}


void RenderRiverUnderBridge()
{
    drawSurface(riverStart,riverEnd,waterColor);
}
float rectX = 0.0f;
float rectY = 0.0f;

// Define the velocity of the rectangle
float rectVx = 0.1f;
float rectVy = 0.0f;

// Define the width and height of the rectangle
float rectWidth = 0.5f;
float rectHeight = 0.5f;
void Dis()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the rectangle
    glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(rectX, rectY, rectX + rectWidth, rectY + rectHeight);
    glFlush();
}
void AnimateVehicle(int time)
{
    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
     glScissor(0, 0, windowWidth, windowHeight);
    glEnable(GL_SCISSOR_TEST);
//
    glClear(GL_COLOR_BUFFER_BIT);

if(carrier[0][0]>=0.76f)
{
    return;
}
    wheelBack[0]+=velocityX;
    wheelFront[0]+=velocityX;

connectorBackFront[0][0]+=velocityX;
connectorBackFront[1][0]+=velocityX;
connectorFrontUpper[0][0]+=velocityX;
connectorFrontUpper[1][0]+=velocityX;
connectorUpperToUpperLeft[0][0]+=velocityX;
connectorUpperToUpperLeft[1][0]+=velocityX;
connectorUpperLeftToBack[0][0]+=velocityX;
connectorUpperLeftToBack[1][0]+=velocityX;


 carrier[0][0]+=velocityX;
 carrier[1][0]+=velocityX;

 seat[0][0]+=velocityX;
 seat[1][0]+=velocityX;

container[0][0]+=velocityX;
container[1][0]+=velocityX;
steering[0][0]+=velocityX;
steering[1][0]+=velocityX;
steering[2][0]+=velocityX;

    glutPostRedisplay();
   glutTimerFunc(550,AnimateVehicle,0);
}

void AnimateBoat(int time)
{
    if(boatStart[0]>=1)
    {
        boatStart[0]=-0.9f;
    }

    boatStart[0]+=velocityX;
     glutPostRedisplay();
   glutTimerFunc(550,AnimateBoat,0);
}
void RenderSplash()
{
//    drawTextOnScreen(titlePos,limeColor,"Bismillah");
}
void RenderBoat()
{
     drawBoat(boatStart[0],boatStart[1], 0.3f,limeColor);

}
