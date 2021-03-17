#include "scene.h"

#include <GL/glut.h>

void init_scene(Scene* scene)
{
	scene->teapot_rotation = 0.0;
}

void update_scene(Scene* scene, double time)
{
	scene->teapot_rotation += 10.0 * time;
	if (scene->teapot_rotation > 360.0)
	{
		scene->teapot_rotation -= 360;
	}
}

void draw_scene(const Scene* scene)
{
	int i, k;
	
    draw_origin();
	
	glPushMatrix();
	for (k = 0; k < 8; k++)
	{
		glPushMatrix(); //trnszformációs mátrix
		for (i = 0; i < 6; i++)
		{
			glBegin(GL_TRIANGLES);

			glColor3f(1, 0, 0);
			glVertex3f(0, 0, 0);

			glColor3f(0, 1, 0);
			glVertex3f(0, 0, 0);

			glColor3f(0, 0, 1);
			glVertex3f(0, 0, 0);

			glEnd();
			glTranslatef(0, 0, 0.5);
		}
		plPopMatrix();
		glTranslatef(0, 0, 0);	
	}
	glPopMatrix(); //tr. mátrix visszaállítása
	
	glPushMatrix();
	glRotatef(scene->teapot_rotation, 1, 0, 0);
	glColor3f(cos(scene->teapot_rotation / 60), sin(scene->teapot_rotation / 60), 1);
	glutWireTeapot(scene->teapot_rotation / 360.0);
	glPopMatrix();
}


void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}
