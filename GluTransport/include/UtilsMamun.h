#ifndef UTILSMAMUN_H
#define UTILSMAMUN_H

void drawCircle(GLfloat x, GLfloat y, GLfloat radius, GLfloat color[], bool isCloud);

void drawRingSpoke(GLfloat x, GLfloat y, GLfloat radius, int spokeCount, GLfloat color[]);

void drawLine(GLfloat xStart, GLfloat yStart, GLfloat xEnd, GLfloat yEnd, GLfloat color[]);

void drawRectangle(GLfloat x, GLfloat y, GLfloat width, GLfloat height, GLfloat color[]);

void drawCloud(GLfloat startX, GLfloat startY, GLfloat r, GLfloat color[] );

void drawTriangle(GLfloat startX, GLfloat startY, GLfloat highX, GLfloat highY, GLfloat endX,GLfloat endY, GLfloat color[]);

void drawSurface(GLfloat first[], GLfloat second[], GLfloat third[], GLfloat fourth[], GLfloat color[] );

#endif // UTILSMAMUN_H
