#ifndef UTILSMAMUN_H
#define UTILSMAMUN_H

void drawCircle(GLfloat x, GLfloat y, GLfloat radius, GLfloat color[], bool isCloud);
void drawCloudCircle(float centerX, float centerY, float radius, int numSegments);

void drawRingSpoke(GLfloat x, GLfloat y, GLfloat radius, int spokeCount, GLfloat color[]);

void drawLine(GLfloat xStart, GLfloat yStart, GLfloat xEnd, GLfloat yEnd, GLfloat color[]);

void drawRectangle(GLfloat x, GLfloat y, GLfloat width, GLfloat height, GLfloat color[]);

void drawCloud(float centerX, float centerY, float radius);

//void drawTriangle(GLfloat startX, GLfloat startY, GLfloat highX, GLfloat highY, GLfloat endX,GLfloat endY, GLfloat color[]);
void drawTriangle(float startX, float startY, float size, float color[]);

void drawTriangles(float startX,float startY,int count, float color[]);

void drawEdge(float start[],float End[], float color[]);

void drawSurface(GLfloat layerStart[], GLfloat layerEnd[], GLfloat color[] );

void drawMarker(float startingPoints[],float endingPoints[],int markerCount, float color[],bool onLadder);

void DrawLadder(float startingPoints[],float endingPoints[],int markerCount, float color[]);

void drawRectangleInPixel(GLfloat x, GLfloat y, GLint pixelWidth, GLint pixelHeight, GLfloat color[3]);
#endif // UTILSMAMUN_H
