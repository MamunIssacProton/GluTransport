#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include<UtilsScene.h>


void renderBitmapString(float x, float y, float z, void *font, char *string) {
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

bool firsRender=true;
void display() {

  // glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
  glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
if(firsRender)
{


//    RenderBackWheel();
//    RenderPartsConnector();
//    RenderTail();
//
//    RenderFrontWheel();
//    RenderContainer();
//    RenderSeat();
//
//    RenderSteering();
//
//    RenderCloud();
//
//    RenderMountain();
//
//    RenderRoad();

        RenderCanvas();
        RenderMountains();
        RenderCloud();
        RenderRiverUnderBridge();
        RenderRoad();
        RenderWarehouse();
        RenderShop();
        RenderVehicle();
        RenderBoat();
}
   else
   {

   }
      //  AnimateVehicle();
     glFlush(); // Render now

}


void RenderMainScreen(int value)
{
    glutDestroyWindow(glutGetWindow());
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("Main Screen");
    glutFullScreen();
    glutDisplayFunc(display);
    glutTimerFunc(0, AnimateVehicle, 0);
    glutMainLoop();
}
void splashScreen()
{
    RenderSplash();
     glutSwapBuffers();

    // Wait for 3 seconds before switching to main screen
    glutTimerFunc(1000, RenderMainScreen, 0);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA));
    glutInitWindowSize(640, 480); // Set the window's initial width & height
    glutInitWindowPosition(80, 50);  // Set the window's initial position according to the monitor
    glutCreateWindow("GluTransport"); // Create a window with the given title
   // glutFullScreen();
//   HWND hWnd = GetForegroundWindow();
//    ShowWindow(hWnd, SW_MAXIMIZE);
//firsRender=true;
    glutDisplayFunc(display);
    //firsRender=false;

     // Register display callback handler for window re-paint
    glutTimerFunc(0,AnimateVehicle,0);
    glutTimerFunc(5,AnimateBoat,0);
         // display();
    glutMainLoop();

  // Enter the event-processing loop
    return 0;
}
