#include "loadTexture.h"
#include <stdlib.h>
#include <GL/glut.h>
#include <String.h>
#include<iostream>
using namespace std;


#define checkImageWidth 128
#define checkImageHeight 102
#define N 60
GLubyte checkImage[checkImageHeight][checkImageWidth][4];
GLuint textureEarth,textureBg;




int view = 1;                                                                    //view!=0->orthogonal,view=0->perspective
double bshining =0.0;                                                            //sun'ss shining
double bx_lcounter=0.0,by_lcounter=0.0;                                          //sun's light_position
double cubex_tcounter=0,cubey_tcounter=0,cubez_tcounter=0;                       //CUBE's position translate
double cubex_rcounter=0, cubey_rcounter=0,cubez_rcounter=0,earithf_rcounter=0;   //earith rotate
double bgx_rcounter=0, bgy_rcounter=0,bgz_rcounter=0,bgf_rcounter=0;             //cube rotate
double lred=1.0, lgreen=0.0, lblue=0.0;                                          //light color
double bx_scounter=0.0,by_scounter=0.0;                                          //sun's light specular
float x[N],y[N];
char pictureName[20]="Data/earth.bmp";


/*************************key events************************************/
void processSimpleKeys(unsigned char key,int x,int y)
{
	switch(key){
		case 'w':
		case 'W':cubex_rcounter++;break;
		case 'x':
		case 'X':cubex_rcounter--;break;
		case 'd':
		case 'D':cubey_rcounter++;break;
		case 'a':
		case 'A':cubey_rcounter--;break;
		case 'e':
		case 'E':cubez_rcounter++;break;
		case 'z':
		case 'Z':cubez_rcounter--;break;
		case 's':
		case 'S':cubex_rcounter=0;
			     cubey_rcounter=0;
				 cubez_rcounter=0;break;
		case 'j':
		case 'J':cubex_tcounter++;break;
		case 'g':
		case 'G':cubex_tcounter--;break;
		case 'y':
		case 'Y':cubey_tcounter++;break;
		case 'n':
		case 'N':cubey_tcounter--;break;
		case 'b':
		case 'B':cubez_tcounter++;break;
		case 'u':
		case 'U':cubez_tcounter--;break;
		case 'h':
		case 'H':cubex_tcounter=0;
				 cubey_tcounter=0;
				 cubez_tcounter=0;break;
		case 127:bx_scounter--;break;                   //127->delete key ascii code
		case 13:bx_scounter=0;by_scounter=0;break;       //90->enter key
	}
	
	int modifier_key = glutGetModifiers();
	if (modifier_key & GLUT_ACTIVE_CTRL) {
	   bx_lcounter=0.0;
	   by_lcounter=0.0;
	}
	glutPostRedisplay();
}
void processSpecialKeys(int key, int x, int y)
{
	switch(key) {
		case GLUT_KEY_F1:view = 1;break;
		case GLUT_KEY_F2:view = 0;break;
		case GLUT_KEY_F3:strcpy(pictureName,"Data/earth.bmp");break;
		case GLUT_KEY_F4:strcpy(pictureName,"Data/bEarth.bmp");;break;
		case GLUT_KEY_F9:lred=1.0;lgreen=1.0;lblue=0.0;break;
		case GLUT_KEY_F10:lred=1.0;lgreen=0.0;lblue=0.0;break;	
		case GLUT_KEY_F11:lred=0.0;lgreen=1.0;lblue=0.0;break;
		case GLUT_KEY_F8:lred=0.0;lgreen=0.0;lblue=1.0;break;
		case GLUT_KEY_F7: bx_lcounter=0.0;by_lcounter=0.0;break;
		case GLUT_KEY_RIGHT : bx_lcounter ++; break;
		case GLUT_KEY_LEFT : bx_lcounter --; break;
		case GLUT_KEY_UP :  by_lcounter ++; break;
		case GLUT_KEY_DOWN : by_lcounter--; break;
		case GLUT_KEY_HOME : by_scounter ++; break;
		case GLUT_KEY_END : by_scounter--; break;
		case GLUT_KEY_PAGE_UP :bshining++; break;
		case GLUT_KEY_PAGE_DOWN :bx_scounter++; break;
		case GLUT_KEY_INSERT :bshining--; break;
	}
	
}
/***************************ASSIATANT FUNCTION**************************/
void init(void) 
{

   GLfloat mat_ambient[]={1.0, 0.0, 0.0, 1.0};
   GLfloat mat_diffuse[]={0.0, 0.0, 0.8, 1.0};
   GLfloat mat_specular[] = { 1.0+0.5*bx_scounter,1.0+0.5*by_scounter,1.0, 1.0};
   GLfloat mat_shininess[] = { 50.0+5*bshining};
   GLfloat light_position[] = { 1.0+0.5*bx_lcounter,1.0+0.5*by_lcounter,1.0,0.0};
   GLfloat  light_color[] = { lred, lgreen, lblue, 0.0 };

   glShadeModel (GL_SMOOTH);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glMaterialfv(GL_FRONT, GL_AMBIENT, light_color);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, light_color);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);
   glLightfv(GL_LIGHT0, GL_AMBIENT, light_color);

	
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);

}
//drawing function
/***************************draw the sky***********************/
void draw_Tbackground()                                                        
{
	
	glTranslatef(0.0, 0.0, -10.0f);

	//// texture //////////////////
	glEnable(GL_TEXTURE_2D);
	textureBg= loadTexture("Data/star2.bmp"); 
	

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
	glBindTexture (GL_TEXTURE_2D, textureBg); 
	
	glBegin(GL_POLYGON);
		
	    glTexCoord2f(0.0, 0.0); glVertex3f(-20.0, -20.0, 0.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(20.0, -20.0, 0.0);
		glTexCoord2f(1.0, 1.0); glVertex3f(20.0, 20.0, 0.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(-20.0, 20.0, 0.0);
    glEnd();
	glDisable(GL_TEXTURE_2D);
}

void draw_cube()
{ 
	glBegin(GL_QUADS);
		glColor3f(1,0,0);
		glVertex3f(-1.5f, -1.5f,  1.5f); // Bottom left
		glVertex3f( 1.5f, -1.5f,  1.5f); // Bottom right
		glVertex3f( 1.5f,  1.5f,  1.5f); // Top right
		glVertex3f(-1.5f,  1.5f,  1.5f); // Top left

		glVertex3f(-1.5f, -1.5f, -1.5f); // Bottom right  
		glVertex3f(-1.5f,  1.5f, -1.5f); // Top right 
		glVertex3f( 1.5f,  1.5f, -1.5f); // Top left 
		glVertex3f( 1.5f,  -1.5f,  -1.5f); // Bottom left 

		glColor3f(1,1,0);
		glVertex3f(-1.5f,  1.5f, -1.5f); // Top left 
		glVertex3f(-1.5f,  1.5f,  1.5f); // Bottom left 
		glVertex3f( 1.5f,  1.5f,  1.5f); // Bottom right 
		glVertex3f( 1.5f,  1.5f, -1.5f); // Top right

		glVertex3f(-1.5f, -1.5f, -1.5f); // Top right 
		glVertex3f( 1.5f, -1.5f, -1.5f); // Top left 
		glVertex3f( 1.5f, -1.5f,  1.5f); // Bottom left 
		glVertex3f(-1.5f, -1.5f,  1.5f); // Bottom right 

		glColor3f(0,0,1);
		glVertex3f( 1.5f, -1.5f, -1.5f); // Bottom right 
		glVertex3f( 1.5f,  1.5f, -1.5f); // Top right 
		glVertex3f( 1.5f,  1.5f,  1.5f); // Top left 
		glVertex3f( 1.5f, -1.5f,  1.5f); // Bottom left 
		// Left face
		glVertex3f(-1.5f, -1.5f,-1.5f); // Bottom left 
		glVertex3f(-1.5f, -1.5f,  1.5f); // Bottom right 
		glVertex3f(-1.5f,  1.5f,  1.5f); // Top right 
		glVertex3f(-1.5f,  1.5f, -1.5f); // Top left 
	glEnd();
}

void draw_earith()
{
	glColor3f(0.0, 0.0, 1.0);
	glEnable(GL_TEXTURE_2D);
	textureEarth = loadTexture(pictureName);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
	glBindTexture (GL_TEXTURE_2D, textureEarth); 
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
    glTranslatef(-5.5f, 0.0f, 0.0f);  // Move left and into the screen
    glutSolidSphere (1, 60, 60);
	glDisable(GL_TEXTURE_2D);
}

void draw_circle()
{
	int i;
	int PI=3.1416;
	glLoadIdentity();
	//glTranslatef(5.0,2.0,0.0);
	glBegin(GL_LINE_LOOP);
		glColor3f(1.0,1.0,0.0);
		for(i=0;i<N;i++){
			x[i]=5.8*cos((float)2*i*PI/N);
			y[i]=2.9*sin((float)2*i*PI/N);
			glVertex2f(x[i],y[i]);
		}
	glEnd();

}
void draw_ball()
{ 
  glColor3f(0.8, 0.0, 0.0);
  glutSolidSphere (1.5, 60, 60);
  glDisable(GL_LIGHTING);
  glDisable(GL_LIGHT0);
  glDisable(GL_DEPTH_TEST);
}

/*********************drawing *******************************/
void draw_object(void)
{
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);

/********************TEXTURE BACKGROUND *************************************/
  draw_Tbackground();
  glPushMatrix();

/********************DRAW EARTH *************************************/
  glLoadIdentity();
  draw_earith();
/********************DRAW THE CIRCLE PATH *************************************/
  glTranslatef(0.0f, 2.0f, -6.0f);
  draw_circle();
/********************DRAW SUN *************************************/
  init();                                                 //light init
	
  glTranslatef(1.0f, 0.0f, 0.0f);
  draw_ball();
   
  glPopMatrix();
  glClearDepth(1.0f);                                  // Depth buffer setup
  glEnable(GL_DEPTH_TEST);                // Enables depth testing
 /********************DRAW CUBE *************************************/
  glTranslatef(-6.0f,-5.0f,6.0f);
  glRotatef(15.0f, 1.0f, 0.0f, 0.0f); 
  glRotatef(15.0f, 0.0f, 0.0f, 1.0f);

  glTranslatef(0.0f+0.5*cubex_tcounter,0.0f+0.5*cubey_tcounter,0.0f+0.5*cubez_tcounter);
  glRotatef(0.0+5*cubex_rcounter,1.0,0.0,0.0);
  glRotatef(0.0+5*cubey_rcounter,0.0,1.0,0.0);
  glRotatef(0.0+5*cubez_rcounter,1.0,0.0,1.0);
  draw_cube();
  glFlush ();
}

void reshape(int w, int h)
{
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   if(view!=0){
	   if (w <= h)
			 glOrtho (-10, 10, -10*(GLfloat)h/(GLfloat)w,
				10*(GLfloat)h/(GLfloat)w, -5.0, 100.0);
		else
			 glOrtho (-10*(GLfloat)w/(GLfloat)h,
				 10*(GLfloat)w/(GLfloat)h, -10, 10, -5.0, 100.0);
   }
   else{
      float width=10.0,height;                                           //define the xy plane
	  height=width * h/w;
	  glFrustum(-width/2, width/2, -height/2, height/2, 1.0, 100.0);
	  glTranslatef(0.0,0.0,-3.0);
   }
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (400, 400); 
   glutInitWindowPosition (350, 350);
   glutCreateWindow (argv[0]);
   init ();
   glutReshapeFunc(reshape);
   glutDisplayFunc(draw_object);
   glutIdleFunc(draw_object);
   glutSpecialFunc(processSpecialKeys);
   glutKeyboardFunc(processSimpleKeys);
   glutMainLoop();
   return 0;
}
