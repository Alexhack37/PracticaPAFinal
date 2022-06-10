/*
 * Plano.h
 *
 *  Created on: Oct 5, 2015
 *      Author: francisco
 */
#include "planoX.h"
#include "contorno.h"
PlanoX::~PlanoX() {
    // TODO Auto-generated destructor stub
}

void PlanoX::Render() {
    Color c = this->getRgb();
    glColor3f(c.getRedComponent(), c.getGreenComponent(), c.getBlueComponent());
    glBegin(GL_POLYGON);
    glVertex3f(p, -s, -s);
    glVertex3f(p, s, -s);
    glVertex3f(p, s, s);
    glVertex3f(p, -s, s);
    glEnd();
}