#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include<math.h>
# define PI    3.14159265358979323846

void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

    int lineAmount = 5200;
	GLfloat twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.1f, 0.0f);
	glBegin(GL_LINE_LOOP);
		for(int i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);

		}
	glEnd();
glColor3f(1.0f, 0.0f, 0.0f); // set color to red
glBegin(GL_LINES);

	  glVertex2f(x, y); // center of the circle
    for(int i = 0; i <= 10; i++) {
        glVertex2f(x + radius * cos(i * twicePi / 10), y + radius * sin(i * twicePi / 10)); // end point of the line
        glVertex2f(x, y); // center of the circle
    }
glEnd();
	glFlush();
}
