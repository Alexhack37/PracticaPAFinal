/*
 * planoY.cpp
 *
 *  Created on: Nov 6, 2015
 *      Author: francisco
 */

#include "planoY.h"

PlanoY::~PlanoY() {
    // TODO Auto-generated destructor stub
}
void PlanoY::Render() {
    Color c = this->getRgb();
    glColor3f(c.getRedComponent(), c.getGreenComponent(), c.getBlueComponent());
    glBegin(GL_POLYGON);
    glVertex3f(-s, p, -s);
    glVertex3f(s, p, -s);
    glVertex3f(s, p, s);
    glVertex3f(-s, p, s);
    glEnd();
}