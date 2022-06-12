#include <iostream>
#include <string>
#include <GL/glut.h>
#include "GameUpdate.h"
#include "SceneUpdate.h"

using namespace std;

//Version Normal
//Game game;
//Scene scene;

//Version Deluxe

GameUpdate game;
SceneUpdate scene;

bool fullScreenMode = false;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int WINDOW_POSITION_X = 300;
const int WINDOW_POSITION_Y = 400;
const GLclampf RED = 0.0;
const GLclampf GREEN = 0.0;
const GLclampf BLUE = 0.0;
const GLclampf ALPHA = 1.0;

const char TITLE[] = "PARTE 1";


void writeLine(string text) {
    cout << text << endl;

}
void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspecRatio = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, aspecRatio, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}



void keyPressed(unsigned char key, int px, int py) {

    //writeLine("tecla pulsada");
    game.ProcessKeyPressed(key,px,py);

    
    /*if (key == 'a') {
        game.cambiarEscena();
    }
    */
    glutPostRedisplay();

}

void mouseMoved(int x, int y) {

    game.ProcessMouseMovement(x, y);
    glutPostRedisplay();

}



void mouseClicked(int button, int state, int x, int y) {

    writeLine("click");
    game.ProcessMouseClick(button, state, x, y);
    int WINAPI gluProject(
        GLdouble objx,
        GLdouble objy,
        GLdouble objz,
        const GLdouble modelMatrix[16],
        const GLdouble projMatrix[16],
        const GLint    viewport[4],
        GLdouble * winx,
        GLdouble * winy,
        GLdouble * winz
    );

    //float x3 = (2.0f * x) / WINDOW_WIDTH - 1.0f;
    //float y3 = 1.0f - (2.0f * y) / WINDOW_HEIGHT;
    //float z3 = 1.0f;
    //Vector3D ray_nds = Vector3D(x3, y3, z3);
    //Vector3D ray_clip = Vector3D(ray_nds.getCoordinateX(), -1.0, 1.0);
    //Vector3D ray_eye =  * ray_clip;
    //cout << ray_nds << endl;
    glutPostRedisplay();

}

//float x = (2.0f * x) / WINDOW_WIDTH - 1.0f;
//float y = 1.0f - (2.0f * y) / WINDOW_HEIGHT;
//float z = 1.0f;
//Vector3D ray_nds = Vector3D(x, y, z);
//Vector3D ray_clip = Vector3D(ray_nds.getCoordinateX(), -1.0, 1.0);
//Vector3D ray_eye = inverse(projection_matrix) * ray_clip;

//hola buenas
void initGraphics() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    
    
    //GLfloat ambientColor[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    //GLfloat lightPosBase[] = { 0.0f, 0.0f, 0.0f, 0.0f }; //10
    //GLfloat lightColor0[] = { 0.0f, 0.0f, 0.0f,0.0f };

    //GLfloat color[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // blue
    //GLfloat white[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    //glLightfv(GL_LIGHT0, GL_POSITION, lightPosBase);
    //glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    //glLightfv(GL_LIGHT0, GL_SPECULAR, lightColor0);
    //glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
    //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
    //glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
    //glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100);
    //glEnable(GL_LIGHT0);
    
    GLfloat ambientColor1[4] = { 0.5f, 0.5f, 0.5f, 0.0f };
    GLfloat lightPos1[4] = { 1.0f, 1.0f, 1.0f, 0.0f };
    GLfloat lightColor1[4] = { 1.0f, 1.0f, 1.0f, 0.0f };
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, lightColor1);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor1);
    glEnable(GL_LIGHT1);


    glEnable(GL_COLOR_MATERIAL);
    glClearColor(RED, GREEN, BLUE, ALPHA);
    game.Init();

    
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    game.Render();

    glutSwapBuffers();

    
}
void idle() {

    game.Update();
    glutPostRedisplay();
    game.resuelveColisiones();
}

void specialKey(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_F11:
            //ANTENCIO ESTO NO FUNCIONA AHORA FUNCIONA PORQ HAY UN BOOL ARRIBA QUE NO DEBE ESTAR
            fullScreenMode = !fullScreenMode;
            if (fullScreenMode) {
                glutFullScreen();
            }else{
                glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
                glutPositionWindow(WINDOW_POSITION_X, WINDOW_POSITION_Y);
            }
            break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(WINDOW_POSITION_X, WINDOW_POSITION_Y);
    glutCreateWindow(TITLE);

    //
    //tratamiento de eventos
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyPressed);
    glutSpecialFunc(specialKey);

    glutPassiveMotionFunc(mouseMoved);
    //glutMotionFunc(mouseMoved);
    glutMouseFunc(mouseClicked);
    glutIdleFunc(idle);
    //iniciando graphicos
    initGraphics();
    
    //bucle infinito
    
    glutMainLoop();
}

