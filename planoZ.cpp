/*
 * planoZ.cpp
 *
 *  Created on: Nov 7, 2015
 *      Author: francisco
 */

#include "planoZ.h"

PlanoZ::~PlanoZ() {
    // TODO Auto-generated destructor stub
}
void PlanoZ::Render() {
    Color c = this->getRgb();
    glColor3f(c.getRedComponent(), c.getGreenComponent(), c.getBlueComponent());
    glBegin(GL_POLYGON);
    glVertex3f(-s, -s, p);
    glVertex3f(s, -s, p);
    glVertex3f(s, s, p);
    glVertex3f(-s, s, p);
    glEnd();
}
