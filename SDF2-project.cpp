#include <iostream>
#include <windows.h>
#include <GL/glut.h> 
#include <cmath>
#include <math.h>
float ss=0.0f;
float a = 0.0f;
bool animate = false;
const float PI = 3.14159265f;
float esger = 0.1f;
float bulud = 0.0f;
float p = 0.0f;
int state = 1;
int byrq=0;
float n = 2.4f;
float m = 2.4f;
float sm = 0.99f;
float h=0.0f;
void initGL() {

glClearColor(135.0f / 255.0f, 206.0f / 255.0f, 235.0f / 255.0f, 1.0f);

}
void drawEllipse(float x_radius, float y_radius, float x_center, float y_center) {
    glBegin(GL_POLYGON);

    for (float angle = 0.0; angle <= 360.0; angle += 0.1) {
  	        glColor3f(110.0f / 255.0f, 110.0f / 255.0f, 98.0f / 255.0f);

       float x = x_center + x_radius * cos(angle * 3.14159 / 360.0);
           glColor3f(200.0f / 255.0f, 180.0f / 255.0f, 162.0f / 255.0f);

       float y = y_center + y_radius * sin(angle * 3.14159 / 360.0);

       glVertex2f(x, y);
    }
    
    glEnd();
}


void drawSUNCircle(float cx, float cy, float r, int num_segments, float c1, float c2, float c3) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(c1, c2, c3);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}


void drawOval(float cx, float cy, float rx, float ry, int num_segments, float c1, float c2, float c3) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(c1, c2, c3);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = rx * cosf(theta);
        float y = ry * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void drawTree(float x, float y, float scale) {
    // Draw trunk
    glBegin(GL_QUADS);
    glColor3f(0.545f, 0.271f, 0.075f); // Brown color
    glVertex2f(x - (0.02f * scale), y + (0.3f * scale));
    glVertex2f(x + (0.02f * scale), y + (0.3f * scale));
    glVertex2f(x + (0.02f * scale), y );
    glVertex2f(x - (0.02f * scale), y );
    glEnd();

    // Draw leaves
    glBegin(GL_TRIANGLES);
    glColor3f(19.0f / 255.0f, 39.0f / 255.0f, 32.0f / 255.0f);
    
    glVertex2f(x - (0.2f * scale), y + (0.25f * scale));
                glColor3f(60.0f / 255.0f, 48.0f / 255.0f, 22.0f / 255.0f);
    glVertex2f(x + (0.2f * scale), y + (0.25f * scale));
    glVertex2f(x, y + (0.4f * scale));
    glEnd();

    glBegin(GL_TRIANGLES);
    
    glVertex2f(x - (0.15f * scale), y + (0.35f * scale));
        glColor3f(115.0f / 255.0f, 98.0f / 255.0f, 28.0f / 255.0f);
    glVertex2f(x + (0.15f * scale), y + (0.35f * scale));
    glVertex2f(x, y + (0.5f * scale));
    glEnd();

    glBegin(GL_TRIANGLES);
    
    glVertex2f(x - (0.1f * scale), y + (0.45f * scale));
    glColor3f(123.0f / 255.0f, 110.0f / 255.0f, 57.0f / 255.0f);

    glVertex2f(x + (0.1f * scale), y + (0.45f * scale));
    glVertex2f(x, y + (0.6f * scale));
    glEnd();
}

float cloudPosition=-1.5f;
void animateCloud(int value) {
    cloudPosition += 0.01f; 
    if(cloudPosition==1.9f){
    	cloudPosition=-0.9f;
	}
    
    glutPostRedisplay(); 
    
    glutTimerFunc(200, animateCloud, 0); 
	
    
}

void drawCylinder(float height, float radius, int slices) {
    GLUquadric *quadric = gluNewQuadric();
    gluQuadricNormals(quadric, GLU_SMOOTH);
    gluCylinder(quadric, radius, radius, height, slices, 1);
    gluDeleteQuadric(quadric);
}

void drawSphere(float radius, int slices, int stacks) {
    GLUquadric *quadric = gluNewQuadric();
    gluQuadricNormals(quadric, GLU_SMOOTH);
    gluSphere(quadric, radius, slices, stacks);
    gluDeleteQuadric(quadric);
}

void drawLoopLine(float x,float y,float nextX, float nextY){
	float av=nextY-y;
	float c=0.05;
	int N = abs(static_cast<int>((nextY - y) / c));
	
	for (int i=0;i<=N;i++){
		glColor3f(33.0f / 255.0f, 40.0f / 255.0f, 48.0f / 255.0f);
glLineWidth(2.0f);
		glBegin(GL_LINES);
glVertex2f(x, y);
glVertex2f(nextX,y);
	glEnd();	
	y+=c;
	
	}
}
void drawCircle(float centerX, float centerY, float radius, float r, float g, float b);

	void drawClouds(){
		
   
   	 drawCircle(cloudPosition+0.8f, 0.8f, 0.08f, 1.0f, 1.0f, 1.0f); 
    drawCircle(cloudPosition+0.7f, 0.85f, 0.1f, 1.0f, 1.0f, 1.0f); 
    drawCircle(cloudPosition+0.55f, 0.8f, 0.08f, 1.0f, 1.0f, 1.0f); 
    drawCircle(cloudPosition+0.7f, 0.95f, 0.09f, 1.0f, 1.0f, 1.0f); 
    drawCircle(cloudPosition+0.5f, 0.95f, 0.05f, 1.0f, 1.0f, 1.0f); 
    drawCircle(cloudPosition+0.4f, 0.9f, 0.03f, 1.0f, 1.0f, 1.0f); 
    drawCircle(cloudPosition + 0.2f, 0.85f, 0.07f, 1.0f, 1.0f, 1.0f);
    drawCircle(cloudPosition + 0.1f, 0.9f, 0.06f, 1.0f, 1.0f, 1.0f);
    drawCircle(cloudPosition - 0.1f, 0.85f, 0.08f, 1.0f, 1.0f, 1.0f);
    drawCircle(cloudPosition - 0.2f, 0.95f, 0.09f, 1.0f, 1.0f, 1.0f);
    drawCircle(cloudPosition - 0.3f, 0.9f, 0.05f, 1.0f, 1.0f, 1.0f);  
    
    drawCircle(cloudPosition-0.8f, 0.8f, 0.08f, 1.0f, 1.0f, 1.0f);
    drawCircle(cloudPosition-0.7f, 0.85f, 0.1f, 1.0f, 1.0f, 1.0f); 
    drawCircle(cloudPosition-0.55f, 0.8f, 0.08f, 1.0f, 1.0f, 1.0f); 
    drawCircle(cloudPosition-0.7f, 0.95f, 0.09f, 1.0f, 1.0f, 1.0f); 
    drawCircle(cloudPosition-0.5f, 0.95f, 0.05f, 1.0f, 1.0f, 1.0f); 
    drawCircle(cloudPosition-0.4f, 0.9f, 0.03f, 1.0f, 1.0f, 1.0f); // White color
    
    
    drawCircle(cloudPosition-0.8f, 0.8f, 0.08f, 1.0f, 1.0f, 1.0f); 
    drawCircle(cloudPosition-0.7f, 0.85f, 0.1f, 1.0f, 1.0f, 1.0f); 
    drawCircle(cloudPosition-0.55f, 0.8f, 0.08f, 1.0f, 1.0f, 1.0f); 
    drawCircle(cloudPosition-0.7f, 0.95f, 0.09f, 1.0f, 1.0f, 1.0f); 
    drawCircle(cloudPosition-0.5f, 0.95f, 0.05f, 1.0f, 1.0f, 1.0f); 
    drawCircle(cloudPosition-0.4f, 0.9f, 0.03f, 1.0f, 1.0f, 1.0f); 
    drawCircle(cloudPosition + 0.2f, 0.85f, 0.07f, 1.0f, 1.0f, 1.0f);
    drawCircle(cloudPosition + 0.1f, 0.9f, 0.06f, 1.0f, 1.0f, 1.0f);
    drawCircle(cloudPosition + 0.1f, 0.85f, 0.08f, 1.0f, 1.0f, 1.0f);
    drawCircle(cloudPosition + 0.2f, 0.95f, 0.09f, 1.0f, 1.0f, 1.0f);
    drawCircle(cloudPosition + 0.3f, 0.9f, 0.05f, 1.0f, 1.0f, 1.0f);  
    
    drawCircle(cloudPosition+0.8f, 0.8f, 0.08f, 1.0f, 1.0f, 1.0f);
    drawCircle(cloudPosition+0.7f, 0.85f, 0.1f, 1.0f, 1.0f, 1.0f); 
    drawCircle(cloudPosition+0.55f, 0.8f, 0.08f, 1.0f, 1.0f, 1.0f); 
    drawCircle(cloudPosition+0.7f, 0.95f, 0.09f, 1.0f, 1.0f, 1.0f); 
    drawCircle(cloudPosition+0.5f, 0.95f, 0.05f, 1.0f, 1.0f, 1.0f); 
    drawCircle(cloudPosition+0.4f, 0.9f, 0.03f, 1.0f, 1.0f, 1.0f); // White color
   
}

void drawCircle(float centerX, float centerY, float radius, float r, float g, float b){
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(r, g, b);
    glVertex2f(centerX, centerY); // Center of circle
    for (float angle = 0.0f; angle <= 360.0f; angle += 2.0f) {
        float x_pos = centerX + radius * cos(angle * 3.1415926f / 180.0f);
        float y_pos = centerY + radius * sin(angle * 3.1415926f / 180.0f);
        glVertex2f(x_pos, y_pos);
    }
    glEnd();
}


void drawLines() {
    glBegin(GL_LINES);
    glColor3f(251.0f / 255.0f, 250.0f / 255.0f, 249.0f / 255.0f);
   
glVertex2f(-0.3f, 1.0f);
glVertex2f(0.08f, 0.8f);
glVertex2f(-0.3f, 1.0f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.5f, 1.0f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.4f, 1.0f);
glVertex2f(0.08f, 0.8f);


glVertex2f(-0.3f, 0.9f);
glVertex2f(0.08f, 0.8f);
glVertex2f(-0.4f, 0.9f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.5f, 0.9f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.4f, 0.9f);
glVertex2f(0.08f, 0.8f);


glVertex2f(-0.3f, 0.8f);
glVertex2f(0.08f, 0.8f);
glVertex2f(-0.4f, 0.8f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.5f, 0.8f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.4f, 0.8f);
glVertex2f(0.08f, 0.8f);


glVertex2f(-0.3f, 0.7f);
glVertex2f(0.08f, 0.8f);
glVertex2f(-0.4f, 0.7f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.5f, 0.7f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.4f, 0.7f);
glVertex2f(0.08f, 0.8f);


glVertex2f(-0.2f, 0.6f);
glVertex2f(0.08f, 0.8f);
glVertex2f(-0.3f, 0.6f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.4f, 0.6f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.3f, 0.6f);
glVertex2f(0.08f, 0.8f);


glVertex2f(-0.3f, 0.75f);
glVertex2f(0.08f, 0.8f);
glVertex2f(-0.4f, 0.75f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.5f, 0.75f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.4f, 0.75f);
glVertex2f(0.08f, 0.8f);


glVertex2f(-0.3f, 0.7f);
glVertex2f(0.08f, 0.8f);
glVertex2f(-0.4f, 0.7f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.5f, 0.7f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.4f, 0.7f);
glVertex2f(0.08f, 0.8f);


glVertex2f(-0.2f, 0.6f);
glVertex2f(0.08f, 0.8f);
glVertex2f(-0.3f, 0.6f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.4f, 0.6f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.3f, 0.6f);
glVertex2f(0.08f, 0.8f);


glVertex2f(0.1f, 0.4f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.0f, 0.4f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.2f, 0.4f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.1f, 0.4f);
glVertex2f(0.08f, 0.8f);


glVertex2f(0.0f, 0.5f);
glVertex2f(0.08f, 0.8f);
glVertex2f(-0.1f, 0.5f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.3f, 0.5f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.2f, 0.5f);
glVertex2f(0.08f, 0.8f);

glVertex2f(0.0f, 1.0f);
glVertex2f(0.08f, 0.8f);
glVertex2f(-0.1f, 1.0f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.3f, 1.0f);
glVertex2f(0.08f, 0.8f);
glVertex2f(0.2f, 1.0f);
glVertex2f(0.08f, 0.8f);

    
    glEnd();
}


void smaller1(int value) {
   if ( n>0.03f) {
         n*=sm;
        glutPostRedisplay(); 
        glutTimerFunc(8, smaller1, 0); 
    }
}
void smaller2(int value) {
   if ( m>0.09f) {
         m*=sm;
        glutPostRedisplay(); 
        glutTimerFunc(8, smaller2, 0); 
    }
}
void portal(int value){

		p+=0.01f;
		 glutPostRedisplay(); 
    glutTimerFunc(10, portal, 0);

}
void update(int value) {
    bulud += 0.01;  

     
    if (bulud > 1.9f) {
        bulud = -0.9f;
    }

    glutPostRedisplay(); 
    glutTimerFunc(80, update, 0);  
}
void timer(int value) {
   if (animate && a<=0.05f) {
         a+=0.01f;
        glutPostRedisplay(); 
        glutTimerFunc(200, timer, 0); 
    }
}


void keyboard(unsigned char key, int x, int y) {
	
	 if (key == 'd' || key == 'D') {
        ss -= 0.01f;
        glutPostRedisplay();
    }
    
    if (key == 'p' || key == 'P') {
        animate = true;  
        glutTimerFunc(0, timer, 0); 
    }
    if(key == 'o' || key == 'O'){
    	glutTimerFunc(0, portal, 0);
	}
	if (key == 'b' || key == 'B'){
    	byrq=8;
        glutPostRedisplay();
	}
	if(key== 'q' || key == 'Q'){
		state=2;
		glutTimerFunc(0, smaller1, 0);
		glutTimerFunc(0, smaller2, 0);
	}
	if (key == 'w' || key == 'W'){
    	state=3;
        glutPostRedisplay();
	}
	 if (key == 'a' || key == 'A') {
        h -= 0.01f;
        glutPostRedisplay();
    }
    
    if (key == 's' || key == 'S') {
        h += 0.01f;
        glutPostRedisplay();
		}
	if (key == 'e' || key == 'E'){
    	state=4;
        glutPostRedisplay();
	}
	if (key == 'x' || key == 'X'){
    	state=6;
        glutPostRedisplay();
	}
	if (key == 'r' || key == 'R'){
    	state=5;
        glutPostRedisplay();
	}
}
void drawCircle(float centerX, float centerY, float radius, int numSegments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; i++) {
        float theta = 2.0f * PI * float(i) / float(numSegments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x + centerX, y + centerY);
    }
    glEnd();
}
void drawVerticalLine(float x,float y,float endPointX,float endPointY){

	float avarage=0.009f;
	float num=(endPointX-x)/avarage;
		float increaseofY=(endPointY-y)/num;
	if(num>0){
		for(int i=0;i<num;i++){
			glLineWidth(0.001f);
glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINES); 

glColor3f(142.0f / 255.0f, 124.0f / 255.0f, 100.0f / 255.0f);
glVertex2f(x, 0.0f);
glVertex2f(x, y);
x+=avarage;
y+=increaseofY;
glEnd();
}
}
else{
	num=abs(num);
	for(int i=0;i<num;i++){
			glLineWidth(0.001f);
glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINES); 
			

glColor3f(78.0f / 255.0f, 78.0f / 255.0f, 68.0f / 255.0f);
glVertex2f(x, 0.0f);
glVertex2f(x, y);
x-=avarage;
y-=increaseofY;
glEnd();
}
}
}
void drawFilledEllipse(float centerX, float centerY, float radiusX, float radiusY, int numSegments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY); 
    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * PI * float(i) / float(numSegments);
        float x = radiusX * cosf(theta);
        float y = radiusY * sinf(theta);
        glVertex2f(x + centerX, y + centerY);
    }
    glEnd();
}
void drawHorizontalLine(float x,float Xend, float y,float Yend1,float Yend2 ){
	
	float avarageY=0.009f;
	float numY=(Yend1-y)/avarageY;
    float increaseofX=(Yend2-Yend1)/numY;

	for(int i=0;i<numY;i++){
		glLineWidth(0.001f);
		glEnable(GL_LINE_SMOOTH);
		glBegin(GL_LINES); 
glColor3f(130.0f / 255.0f, 122.0f / 255.0f, 103.0f / 255.0f);
glVertex2f(x, y);
glVertex2f(Xend,y+0.00000001);
y+=avarageY;

glEnd();
	}
}
void drawHorizontalLineDegree(float x,float Xend, float y,float Yend1,float Yend2 ){
	
	float avarageY=0.009f;
	float numY=(Yend1-y)/avarageY;
	float degree=Yend2-Yend1;
    float increaseofX=(Yend2-Yend1)/numY;

	for(int i=0;i<numY;i++){
		glLineWidth(0.05f);
		glEnable(GL_LINE_SMOOTH);
		glBegin(GL_LINES); 
glColor3f(142.0f / 255.0f, 124.0f / 255.0f, 100.0f / 255.0f);
glVertex2f(x, y);

glVertex2f(Xend,y+degree);

y+=avarageY;
glColor3f(120.0f / 255.0f, 113.0f / 255.0f, 94.0f / 255.0f);


glEnd();
	}
}
void drawHorizontalLineDegree1(float x,float Xend, float y,float Yend1,float Yend2 ){
	
	float avarageY=0.1f;
	float numY=(Yend1-y)/avarageY;
	float degree=Yend2-Yend1;
    float increaseofX=(Yend2-Yend1)/numY;

	for(int i=0;i<numY;i++){
		glLineWidth(1.0f);
		glEnable(GL_LINE_SMOOTH);
		glBegin(GL_LINES); 
glColor3f(64.0f / 255.0f, 46.0f / 255.0f, 23.0f / 255.0f);
glVertex2f(x, y);

glVertex2f(Xend,y+degree);

y+=avarageY;
glColor3f(120.0f / 255.0f, 113.0f / 255.0f, 94.0f / 255.0f);


glEnd();
	}
}
void drawFilledCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);  
    glColor3f(0.0f, 0.5f, 0.0f);  
    glVertex2f(cx, cy);  
    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void display() {
glClear(GL_COLOR_BUFFER_BIT); 
//////ORTAQ HISSE
if(state==1){
/////////////////////////NURLAN
glColor3f(1.0, 1.0, 1.0); 
  drawCircle(-0.8+bulud,0.8, 0.05, 100);
  glColor3f(1.0, 1.0, 1.0);
  drawCircle(-0.83+bulud, 0.75, 0.06, 100);
  glColor3f(1.0, 1.0, 1.0);
  drawCircle(-0.78+bulud, 0.75, 0.06, 100);
   
  glColor3f(1.0, 1.0, 1.0); 
  drawCircle(-0.5+bulud,0.8, 0.07, 100);
  glColor3f(1.0, 1.0, 1.0);
  drawCircle(-0.54+bulud, 0.75, 0.08, 100);
  glColor3f(1.0, 1.0, 1.0);
  drawCircle(-0.47+bulud, 0.75, 0.08, 100);
///////////////////////////
/////////////////////////NIHAT
glBegin(GL_LINES); 
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.01f, 0.373f);
glVertex2f(0.01f, 0.42f);

glEnd();
 glBegin(GL_LINES); 
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.047f, 0.373f);
glVertex2f(0.047f, 0.42f);
glEnd();
glBegin(GL_LINES); 
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.08f, 0.373f);
glVertex2f(0.08f, 0.42f);
glEnd();
glBegin(GL_LINES); 
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.1f, 0.373f);
glVertex2f(0.1f, 0.42f);
glEnd();
glBegin(GL_LINES); 
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.14f, 0.373f);
glVertex2f(0.14f, 0.42f);
glEnd();
glBegin(GL_LINES); 
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.16f, 0.373f);
glVertex2f(0.16f, 0.42f);
glEnd();
glBegin(GL_LINES); 
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.2f, 0.373f);
glVertex2f(0.2f, 0.42f);
glEnd();
glBegin(GL_LINES); 
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.22f, 0.373f);
glVertex2f(0.22f, 0.42f);
glEnd();


// middle part
glBegin(GL_QUADS); 
glColor3f(207.0f / 255.0f, 187.0f / 255.0f, 162.0f / 255.0f);
glVertex2f(-0.277f, 0.0f);
glColor3f(176.0f / 255.0f, 152.0f / 255.0f, 124.0f / 255.0f);

glVertex2f(-0.277f, 0.37f);
glColor3f(120.0f / 255.0f, 113.0f / 255.0f, 94.0f / 255.0f);

glVertex2f(0.4f, 0.4f);
glColor3f(252.0f / 255.0f, 236.0f / 255.0f, 211.0f / 255.0f);

glVertex2f(0.4f, 0.0f);
glColor3f(252.0f / 255.0f, 236.0f / 255.0f, 211.0f / 255.0f);

glEnd();

//Windows
glBegin(GL_QUADS); 
glColor3f(165.0f / 255.0f, 155.0f / 255.0f, 143.0f / 255.0f);
glVertex2f(-0.1f, 0.288f);
glVertex2f(-0.05f, 0.29f);
glColor3f(92.0f / 255.0f, 80.0f / 255.0f, 71.0f / 255.0f);

glVertex2f(-0.05f, 0.35f);
glColor3f(92.0f / 255.0f, 80.0f / 255.0f, 71.0f / 255.0f);

glVertex2f(-0.1f, 0.348f);
glColor3f(92.0f / 255.0f, 80.0f / 255.0f, 71.0f / 255.0f);

glEnd();

glBegin(GL_QUADS); 
glColor3f(165.0f / 255.0f, 155.0f / 255.0f, 143.0f / 255.0f);
glVertex2f(0.1f, 0.298f);
glVertex2f(0.15f, 0.3f);
glColor3f(92.0f / 255.0f, 80.0f / 255.0f, 71.0f / 255.0f);

glVertex2f(0.15f, 0.36f);
glColor3f(92.0f / 255.0f, 80.0f / 255.0f, 71.0f / 255.0f);

glVertex2f(0.1f, 0.358f);
glColor3f(92.0f / 255.0f, 80.0f / 255.0f, 71.0f / 255.0f);

glEnd();
glBegin(GL_QUADS); 
glColor3f(165.0f / 255.0f, 155.0f / 255.0f, 143.0f / 255.0f);
glVertex2f(0.3f, 0.298f);
glVertex2f(0.35f, 0.3f);
glColor3f(92.0f / 255.0f, 80.0f / 255.0f, 71.0f / 255.0f);

glVertex2f(0.35f, 0.36f);
glColor3f(92.0f / 255.0f, 80.0f / 255.0f, 71.0f / 255.0f);

glVertex2f(0.3f, 0.358f);
glColor3f(92.0f / 255.0f, 80.0f / 255.0f, 71.0f / 255.0f);

glEnd();

drawVerticalLine(-0.277f,0.37f,0.4f,0.4f);
drawHorizontalLineDegree(-0.277f,0.4f,0.0f,0.37f,0.4f);

// between middle and right part

glBegin(GL_QUADS); 
glColor3f(200.0f / 255.0f, 187.0f / 255.0f, 162.0f / 255.0f);
glVertex2f(0.4f, 0.0f);
glVertex2f(0.4f, 0.4f);
glColor3f(178.0f / 255.0f, 164.0f / 255.0f, 142.0f / 255.0f);


glVertex2f(0.5f, 0.42f);
glVertex2f(0.5f, 0.0f);

glEnd();
drawVerticalLine(0.4f,0.4f,0.5f,0.42f);
drawHorizontalLineDegree(0.4f,0.5f,0.0f,0.4f,0.42f);


//right part
glBegin(GL_QUADS); 
glColor3f(200.0f / 255.0f, 180.0f / 255.0f, 162.0f / 255.0f);
glVertex2f(0.5f, 0.0f);
glVertex2f(0.5f, 0.423f);
glColor3f(110.0f / 255.0f, 110.0f / 255.0f, 98.0f / 255.0f);

glVertex2f(0.7f, 0.423f);

glVertex2f(0.7f, 0.0f);

glEnd();
//drawEllipse(0.105, 0.07, 0.6, 0.39);
drawVerticalLine(0.5f,0.425f,0.7f,0.425f);
drawHorizontalLine(0.5f,0.7f,0.0f,0.425f,0.425f);






//left part 1
glBegin(GL_QUADS); 
glColor3f(200.0f / 255.0f, 180.0f / 255.0f, 162.0f / 255.0f);
glVertex2f(-0.277f, 0.0f);

glVertex2f(-0.277f, 0.37f);
glColor3f(101.0f / 255.0f, 94.0f / 255.0f, 84.0f / 255.0f);

glVertex2f(-0.6f, 0.5f);
glColor3f(133.0f / 255.0f, 123.0f / 255.0f, 105.0f / 255.0f);


glVertex2f(-0.6f, 0.0f);
glColor3f(172.0f / 255.0f, 157.0f / 255.0f, 138.0f / 255.0f);

glEnd();
drawVerticalLine(-0.277f,0.37f,-0.6f,0.5f);
drawHorizontalLineDegree(-0.277f,-0.6f,0.0f,0.37f,0.5f);

//left part 2
glBegin(GL_QUADS); 
glColor3f(200.0f / 255.0f, 180.0f / 255.0f, 162.0f / 255.0f);
glVertex2f(-0.6f, 0.0f);
glVertex2f(-0.6f, 0.8f);
glColor3f(101.0f / 255.0f, 94.0f / 255.0f, 84.0f / 255.0f);
glVertex2f(-0.95f, 0.85f);
glColor3f(133.0f / 255.0f, 123.0f / 255.0f, 105.0f / 255.0f);

glVertex2f(-0.95f, 0.0f);
glColor3f(172.0f / 255.0f, 157.0f / 255.0f, 138.0f / 255.0f);


glEnd();

drawVerticalLine(-0.6f,0.8f,-0.95f,0.8f);
drawHorizontalLineDegree(-0.6f,-0.95f,0.0f,0.8f,0.85f);
//left part 3
glBegin(GL_QUADS); 
glColor3f(200.0f / 255.0f, 180.0f / 255.0f, 162.0f / 255.0f);

glVertex2f(-0.95f, 0.0f);
glVertex2f(-0.95f, 0.57f);
glColor3f(101.0f / 255.0f, 94.0f / 255.0f, 84.0f / 255.0f);
glVertex2f(-1.0f, 0.6f);
glVertex2f(-1.0f, 0.0f);
glColor3f(172.0f / 255.0f, 157.0f / 255.0f, 138.0f / 255.0f);


glEnd();
drawVerticalLine(-0.95f,0.57f,-1.0f,0.6f);
drawHorizontalLineDegree(-0.95f,-1.0f,0.0f,0.57f,0.6f);

//Door sides

glBegin(GL_QUADS); 
glColor3f(172.0f / 255.0f, 157.0f / 255.0f, 138.0f / 255.0f);

glVertex2f(0.07f, 0.0f);
glVertex2f(0.07f, 0.21f);
glVertex2f(0.21f, 0.22f);
glVertex2f(0.21f, 0.0f);


glEnd();
drawHorizontalLineDegree1(0.07f,0.21f,0.0f,0.21f,0.22f);


glBegin(GL_QUADS); 
glColor3f(133.0f / 255.0f, 123.0f / 255.0f, 105.0f / 255.0f);

glVertex2f(0.08f, 0.0f);
glVertex2f(0.08f, 0.2f);
glVertex2f(0.2f, 0.21f);
glVertex2f(0.2f, 0.0f);


glEnd();

// door
// door
glBegin(GL_POLYGON); 
glColor3f(30.0f / 255.0f, 21.0f / 255.0f, 16.0f / 255.0f);

glVertex2f(0.09f, 0.0f);
glVertex2f(0.09f, 0.15f);
glVertex2f(0.14f, 0.18f);
glColor3f(84.0f / 255.0f, 64.0f / 255.0f, 55.0f / 255.0f);

glVertex2f(0.19f, 0.15f);
glColor3f(128.0f / 255.0f, 110.0f / 255.0f, 96.0f / 255.0f);

glVertex2f(0.19f, 0.0f);


glEnd();
// Right side of door

glBegin(GL_QUADS); 
glColor3f(149.0f / 255.0f, 133.0f / 255.0f, 108.0f / 255.0f);

glVertex2f(0.18f, 0.0f);
glVertex2f(0.18f, 0.24f);
glVertex2f(0.24f, 0.24f);
glVertex2f(0.24f, 0.0f);


glEnd();

drawVerticalLine(0.18f,0.24f,0.24f,0.24f);
drawHorizontalLineDegree(0.18f,0.24f,0.0f,0.24f,0.24f);
// Right side of door SHADE
glBegin(GL_QUADS); 
glColor3f(78.0f / 255.0f, 83.0f / 255.0f, 76.0f / 255.0f);



glVertex2f(0.24f, 0.0f);
glVertex2f(0.24f, 0.24f);
glColor3f(172.0f / 255.0f, 157.0f / 255.0f, 138.0f / 255.0f);

glVertex2f(0.28f, 0.2f);
glVertex2f(0.28f, 0.0f);


glEnd();



// Shusha yazisi
// S

 glBegin(GL_QUADS); 
glColor3f(148.0f / 255.0f, 28.0f / 255.0f, 64.0f / 255.0f);
glVertex2f(0.0f, 0.4f);
glVertex2f(0.05f, 0.41f);
glVertex2f(0.05f, 0.43f);
glVertex2f(0.0f, 0.42f);


glEnd();

glBegin(GL_QUADS); 
glColor3f(148.0f / 255.0f, 28.0f / 255.0f, 64.0f / 255.0f);
glVertex2f(0.04f, 0.42f);
glVertex2f(0.05f, 0.43f);
glVertex2f(0.05f, 0.46f);
glVertex2f(0.04f, 0.46f);


glEnd();

glBegin(GL_QUADS); 
glColor3f(148.0f / 255.0f, 28.0f / 255.0f, 64.0f / 255.0f);
glVertex2f(0.01f, 0.45f);
glVertex2f(0.05f, 0.46f);
glVertex2f(0.05f, 0.48f);
glVertex2f(0.01f, 0.47f);


glEnd();
 
 glBegin(GL_QUADS); 
glColor3f(148.0f / 255.0f, 28.0f / 255.0f, 64.0f / 255.0f);
glVertex2f(0.01f, 0.46f);
glVertex2f(0.02f, 0.46f);
glVertex2f(0.02f, 0.5f);
glVertex2f(0.01f, 0.5f);


glEnd();

 glBegin(GL_QUADS); 
glColor3f(148.0f / 255.0f, 28.0f / 255.0f, 64.0f / 255.0f);
glVertex2f(0.01f, 0.5f);
glVertex2f(0.05f, 0.51f);
glVertex2f(0.05f, 0.53f);
glVertex2f(0.01f, 0.52f);
glEnd();

glBegin(GL_QUADS); 
glColor3f(148.0f / 255.0f, 28.0f / 255.0f, 64.0f / 255.0f);
glVertex2f(0.02f, 0.39f);
glVertex2f(0.03f, 0.39f);
glVertex2f(0.03f, 0.41f);
glVertex2f(0.02f, 0.41f);


glEnd();


/// U
glBegin(GL_QUADS); 
glColor3f(148.0f / 255.0f, 28.0f / 255.0f, 64.0f / 255.0f);
glVertex2f(0.07f, 0.4f);
glVertex2f(0.11f, 0.41f);
glVertex2f(0.11f, 0.43f);
glVertex2f(0.07f, 0.42f);


glEnd();

glBegin(GL_QUADS); 
glColor3f(148.0f / 255.0f, 28.0f / 255.0f, 64.0f / 255.0f);
glVertex2f(0.07f, 0.42f);
glVertex2f(0.08f, 0.42f);
glVertex2f(0.08f, 0.47f);
glVertex2f(0.07f, 0.465f);


glEnd();
glBegin(GL_QUADS); 
glColor3f(148.0f / 255.0f, 28.0f / 255.0f, 64.0f / 255.0f);
glVertex2f(0.1f, 0.42f);
glVertex2f(0.11f, 0.42f);
glVertex2f(0.11f, 0.48f);
glVertex2f(0.1f, 0.475f);


glEnd();


// s
glBegin(GL_QUADS); 
glColor3f(148.0f / 255.0f, 28.0f / 255.0f, 64.0f / 255.0f);
glVertex2f(0.13f, 0.4f);
glVertex2f(0.17f, 0.41f);
glVertex2f(0.17f, 0.43f);
glVertex2f(0.13f, 0.42f);



glEnd();
glBegin(GL_QUADS); 
glColor3f(148.0f / 255.0f, 28.0f / 255.0f, 64.0f / 255.0f);
glVertex2f(0.16f, 0.42f);
glVertex2f(0.17f, 0.42f);
glVertex2f(0.17f, 0.45f);
glVertex2f(0.16f, 0.45f);



glEnd();

glBegin(GL_QUADS); 
glColor3f(148.0f / 255.0f, 28.0f / 255.0f, 64.0f / 255.0f);
glVertex2f(0.13f, 0.44f);
glVertex2f(0.17f, 0.45f);
glVertex2f(0.17f, 0.47f);
glVertex2f(0.13f, 0.46f);



glEnd();
glBegin(GL_QUADS); 
glColor3f(148.0f / 255.0f, 28.0f / 255.0f, 64.0f / 255.0f);
glVertex2f(0.13f, 0.46f);
glVertex2f(0.14f, 0.46f);
glVertex2f(0.14f, 0.48f);
glVertex2f(0.13f, 0.48f);



glEnd();
glBegin(GL_QUADS); 
glColor3f(148.0f / 255.0f, 28.0f / 255.0f, 64.0f / 255.0f);
glVertex2f(0.13f, 0.47f);
glVertex2f(0.17f, 0.48f);
glVertex2f(0.17f, 0.5f);
glVertex2f(0.13f, 0.49f);
glEnd();
glBegin(GL_QUADS); 
glColor3f(148.0f / 255.0f, 28.0f / 255.0f, 64.0f / 255.0f);
glVertex2f(0.149f, 0.395f);
glVertex2f(0.156f, 0.395f);
glVertex2f(0.156f, 0.41f);
glVertex2f(0.149f, 0.41f);
glEnd();

//a
glBegin(GL_QUADS); 
glColor3f(148.0f / 255.0f, 28.0f / 255.0f, 64.0f / 255.0f);
glVertex2f(0.19f, 0.4f);
glVertex2f(0.23f, 0.41f);
glVertex2f(0.23f, 0.43f);
glVertex2f(0.19, 0.42f);
glEnd();

glBegin(GL_QUADS); 
glColor3f(148.0f / 255.0f, 28.0f / 255.0f, 64.0f / 255.0f);
glVertex2f(0.19f, 0.42f);
glVertex2f(0.2f, 0.42f);
glVertex2f(0.2f, 0.48f);
glVertex2f(0.19, 0.48f);
glEnd();

 glBegin(GL_QUADS); 
glColor3f(148.0f / 255.0f, 28.0f / 255.0f, 64.0f / 255.0f);
glVertex2f(0.19f, 0.46f);
glVertex2f(0.23f, 0.47f);
glVertex2f(0.23f, 0.49f);
glVertex2f(0.19f, 0.48f);
glEnd();
glBegin(GL_QUADS); 
glColor3f(148.0f / 255.0f, 28.0f / 255.0f, 64.0f / 255.0f);
glVertex2f(0.22f, 0.42f);
glVertex2f(0.23f, 0.42f);
glVertex2f(0.23f, 0.5f);
glVertex2f(0.22f, 0.5f);
glEnd();

glBegin(GL_QUADS); 
glColor3f(148.0f / 255.0f, 28.0f / 255.0f, 64.0f / 255.0f);
glVertex2f(0.23f, 0.41f);
glVertex2f(0.24f, 0.42f);
glVertex2f(0.24f, 0.43f);
glVertex2f(0.23f, 0.43f);
glEnd();
//////////////////////////////


///////////////////////ELNUR
// YASILLIQ

glBegin(GL_TRIANGLES);
glColor3f(82.0f / 255.0f, 194.0f / 255.0f, 52.0f / 255.0f);
glVertex2f(-1.0f, 0.5f);
glVertex2f(-0.1f, 0.0f);
glVertex2f(-1.0f, 0.0f);
glEnd();

glBegin(GL_QUADS); 

glColor3f(82.0f / 255.0f, 194.0f / 255.0f, 52.0f / 255.0f); 
glVertex2f(-1.0f, 0.0f);
glVertex2f(1.0f, 0.0f);

glVertex2f(1.0f, -1.0f);
glVertex2f(-1.0f, -1.0f);
glEnd();

// YOL 
glBegin(GL_QUADS);
glColor3f(171.0f / 255.0f, 186.0f / 255.0f, 171.0f / 255.0f);
glVertex2f(0.09f, 0.0f);
glVertex2f(-0.09f, -1.0f);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.4f, -1.0f);
glVertex2f(0.18f, 0.0f);
glEnd(); 
//////////////////////////////////////////
// lower tree
/////////////////NURLAN
glBegin(GL_QUADS); 
glColor3f(0.545f, 0.271f, 0.075f); // Brown color
glVertex2f(-0.4f, 0.0f);
glVertex2f(-0.35f, 0.0f);
glVertex2f(-0.35f, -0.1f);
glVertex2f(-0.4f, -0.1f);

glColor3f(0.545f, 0.271f, 0.075f); // Brown color
glVertex2f(0.5f, 0.0f);
glVertex2f(0.45f, 0.0f);
glVertex2f(0.45f, -0.1f);
glVertex2f(0.5f, -0.1f);

glBegin(GL_QUADS); 
glColor3f(0.545f, 0.271f, 0.075f); // Brown color
glVertex2f(-0.35f, -0.45f);
glVertex2f(-0.3f, -0.45f);
glVertex2f(-0.3f, -0.55f);
glVertex2f(-0.35f, -0.55f);
 

glEnd();
glBegin(GL_TRIANGLES); 
glColor3f(0.0f, 0.5f, 0.0f);
glVertex2f(-0.48f, 0.0f);
glVertex2f(-0.27f, 0.0f);
glVertex2f(-0.375f, 0.15f);

glColor3f(0.0f, 0.5f, 0.0f);
glVertex2f(-0.45f, 0.09f);
glVertex2f(-0.3f, 0.09f);
glVertex2f(-0.375f, 0.2f);

glColor3f(0.0f, 0.5f, 0.0f);
glVertex2f(0.58f, 0.0f);
glVertex2f(0.37f, 0.0f);
glVertex2f(0.475f, 0.15f);

glColor3f(0.0f, 0.5f, 0.0f);
glVertex2f(0.55f, 0.09f);
glVertex2f(0.4f, 0.09f);
glVertex2f(0.475f, 0.2f);

glColor3f(0.0f, 0.5f, 0.0f);
glVertex2f(-0.42f, -0.45f);
glVertex2f(-0.22f, -0.45f);
glVertex2f(-0.32f, -0.3f);

glColor3f(0.0f, 0.5f, 0.0f);
glVertex2f(-0.39f, -0.36f);
glVertex2f(-0.25f, -0.36f);
glVertex2f(-0.32f, -0.25f);

glEnd();
glColor3f(1.0f, 0.0f, 0.0f);//flower
drawFilledEllipse(0.4, -0.2,0.02,0.01,100);
glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(0.4, -0.2,0.01,0.02,100);
glColor3f(1.0f, 1.0f, 0.0f);
drawCircle(0.4, -0.2, 0.005, 100);

 glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(0.4, -0.5,0.02,0.01,100);
glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(0.4, -0.5,0.01,0.02,100);
glColor3f(1.0f, 1.0f, 0.0f);
drawCircle(0.4, -0.5, 0.005, 100);
 
 glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(0.5, -0.52,0.02,0.01,100);
glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(0.5, -0.52,0.01,0.02,100);
glColor3f(1.0f, 1.0f, 0.0f);
drawCircle(0.5, -0.52, 0.005, 100);




glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(0.6, -0.6,0.02,0.01,100);
glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(0.6, -0.6,0.01,0.02,100);
glColor3f(1.0f, 1.0f, 0.0f);
drawCircle(0.6, -0.6, 0.005, 100);

glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(0.4, -0.8,0.02,0.01,100);
glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(0.4, -0.8,0.01,0.02,100);
glColor3f(1.0f, 1.0f, 0.0f);
drawCircle(0.4, -0.8, 0.005, 100);

glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(0.7, -0.5,0.02,0.01,100);
glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(0.7, -0.5,0.01,0.02,100);
glColor3f(1.0f, 1.0f, 0.0f);
drawCircle(0.7, -0.5, 0.005, 100);



glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(0.8, -0.2,0.02,0.01,100);
glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(0.8, -0.2,0.01,0.02,100);
glColor3f(1.0f, 1.0f, 0.0f);
drawCircle(0.8, -0.2, 0.005, 100);

glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(0.8, -0.4,0.02,0.01,100);
glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(0.8, -0.4,0.01,0.02,100);
glColor3f(1.0f, 1.0f, 0.0f);
drawCircle(0.8, -0.4, 0.005, 100);
 
 glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(0.6, -0.3,0.02,0.01,100);
glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(0.6, -0.3,0.01,0.02,100);
glColor3f(1.0f, 1.0f, 0.0f);
drawCircle(0.6, -0.3, 0.005, 100);

glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(0.7, -0.7,0.02,0.01,100);
glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(0.7, -0.7,0.01,0.02,100);
glColor3f(1.0f, 1.0f, 0.0f);
drawCircle(0.7, -0.7, 0.005, 100);

glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(-0.4, -0.2,0.02,0.01,100);
glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(-0.4, -0.2,0.01,0.02,100);
glColor3f(1.0f, 1.0f, 0.0f);
drawCircle(-0.4, -0.2, 0.005, 100);

glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(-0.6, -0.6,0.02,0.01,100);
glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(-0.6, -0.6,0.01,0.02,100);
glColor3f(1.0f, 1.0f, 0.0f);
drawCircle(-0.6, -0.6, 0.005, 100);

glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(-0.4, -0.8,0.02,0.01,100);
glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(-0.4, -0.8,0.01,0.02,100);
glColor3f(1.0f, 1.0f, 0.0f);
drawCircle(-0.4, -0.8, 0.005, 100);

glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(-0.7, -0.5,0.02,0.01,100);
glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(-0.7, -0.5,0.01,0.02,100);
glColor3f(1.0f, 1.0f, 0.0f);
drawCircle(-0.7, -0.5, 0.005, 100);

glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(-0.8, -0.2,0.02,0.01,100);
glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(-0.8, -0.2,0.01,0.02,100);
glColor3f(1.0f, 1.0f, 0.0f);
drawCircle(-0.8, -0.2, 0.005, 100);

glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(-0.8, -0.4,0.02,0.01,100);
glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(-0.8, -0.4,0.01,0.02,100);
glColor3f(1.0f, 1.0f, 0.0f);
drawCircle(-0.8, -0.4, 0.005, 100);
 
 glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(-0.6, -0.3,0.02,0.01,100);
glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(-0.6, -0.3,0.01,0.02,100);
glColor3f(1.0f, 1.0f, 0.0f);
drawCircle(-0.6, -0.3, 0.005, 100);

glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(-0.7, -0.7,0.02,0.01,100);
glColor3f(1.0f, 0.0f, 0.0f);
drawFilledEllipse(-0.7, -0.7,0.01,0.02,100);
glColor3f(1.0f, 1.0f, 0.0f);
drawCircle(-0.7, -0.7, 0.005, 100);


    glColor3f(0.3, 0.0, 0.5);//small portal
    drawFilledEllipse(0.5 , 0.5, 0.001+(0.3*a), 0.001+(0.7*a), 100);
     glColor3f(0.3+(5.8*a), 0.0, 0.5+(1.8*a));
    drawFilledEllipse(0.5, 0.5, 0.001+(0.25*a), 0.001+(0.6*a), 100);
    glColor3f(0.3+(7.8*a), 0.0, 0.5+(3.8*a));
    drawFilledEllipse(0.5, 0.5, 0.001+(0.2*a), 0.001+(0.5*a), 100);
     glColor3f(0.3+(9.8*a), 0.0, 0.5+(5.8*a));
    drawFilledEllipse(0.5, 0.5, 0.001+(0.15*a), 0.001+(0.4*a), 100);
     glColor3f(0.3+(11.8*a), 0.0, 0.5+(7.8*a));
    drawFilledEllipse(0.5, 0.5, 0.001+(0.1*a), 0.001+(0.3*a), 100);
     glColor3f(0.3+(13.8*a), 0.0, 0.5+(9.8*a));
    drawFilledEllipse(0.5, 0.5, 0.001+(0.05*a), 0.001+(0.2*a), 100);
     glColor3f(0.3+(30*a), 0.0+(14*a), 0.5+(26*a));
    drawFilledEllipse(0.501, 0.5, 0.001+(0.03*a), 0.001+(0.1*a), 100);//
  
  
    glColor3f(0.3, 0.0, 0.5);//big portal
    drawFilledEllipse(0.235+(6*a), -0.65+(2*a), 0.01+(3*a), 0.01+(7*a), 100);

    
    glBegin(GL_QUADS);//body
glColor3f(0.0, 0.3, 0.0);
glVertex2f((0.2f-ss), (-0.5f));
glVertex2f((esger-ss), (-0.5f));
glVertex2f((esger-ss), (-0.7f));
glVertex2f((0.2f-ss), (-0.7f));
glEnd();

glBegin(GL_QUADS);//sol qol
glColor3f(0.0, 0.3, 0.0);
glVertex2f((0.07f-ss), (-0.5f));
glVertex2f((esger-ss), (-0.5f));
glVertex2f((esger-ss), (-0.63f));
glVertex2f((0.07f-ss), (-0.63f));

glColor3f(1.0, 0.5, 0.5);
 glVertex2f((0.07f-ss), (-0.63f));
glVertex2f((esger-ss), (-0.63f));
glVertex2f((esger-ss), (-0.66f));
glVertex2f((0.07f-ss), (-0.66f));

//right qol
glColor3f(0.0, 0.3, 0.0);
glVertex2f((0.2f-ss), (-0.5f));
glVertex2f((0.23f-ss), (-0.5f));
glVertex2f((0.23f-ss), (-0.63f));
glVertex2f((0.2f-ss), (-0.63f));

glColor3f(1.0, 0.5, 0.5);
 glVertex2f((0.2f-ss), (-0.63f));
glVertex2f((0.23f-ss), (-0.63f));
glVertex2f((0.23f-ss), (-0.66f));
glVertex2f((0.2f-ss), (-0.66f));
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0, 0.5, 0.5);//head
 glVertex2f((0.12f-ss), (-0.46f));
glVertex2f((0.18f-ss), (-0.46f));
glVertex2f((0.18f-ss), (-0.5f));
glVertex2f((0.12f-ss), (-0.5f));

glColor3f(0.0, 0.3, 0.0);
 glVertex2f((0.12f-ss), (-0.43f));
glVertex2f((0.18f-ss), (-0.43f));
glVertex2f((0.18f-ss), (-0.46f));
glVertex2f((0.12f-ss), (-0.46f));

glEnd();
glBegin(GL_TRIANGLES);
glColor3f(0.0, 0.3, 0.0);//papaq
 glVertex2f((0.19f-ss), (-0.445f));
glVertex2f((0.18f-ss), (-0.445f));
glVertex2f((0.18f-ss), (-0.46f));
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0, 0.3, 0.0);//sol ve sag ayaq
 glVertex2f((0.11f-ss), (-0.7f));
glVertex2f((0.11f-ss), (-0.73f));
glVertex2f((0.19f-ss), (-0.73f));
glVertex2f((0.19f-ss), (-0.7f));

glColor3f(0.0, 0.3, 0.0);
 glVertex2f((0.11f-ss), (-0.78f));
glVertex2f((0.11f-ss), (-0.73f));
glVertex2f((0.14f-ss), (-0.73f));
glVertex2f((0.14f-ss), (-0.78f));

glColor3f(0.0, 0.3, 0.0);
 glVertex2f((0.16f-ss), (-0.78f));
glVertex2f((0.16f-ss), (-0.73f));
glVertex2f((0.19f-ss), (-0.73f));
glVertex2f((0.19f-ss), (-0.78f));

glColor3f(0.0, 0.0, 0.0);//foot
 glVertex2f((0.16f-ss), (-0.8f));
glVertex2f((0.16f-ss), (-0.78f));
glVertex2f((0.19f-ss), (-0.78f));
glVertex2f((0.19f-ss), (-0.8f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.11f-ss), (-0.8f));
glVertex2f((0.11f-ss), (-0.78f));
glVertex2f((0.14f-ss), (-0.78f));
glVertex2f((0.14f-ss), (-0.8f));

glEnd();

 glBegin(GL_LINES);
 glColor3f(0.0f, 0.0f, 0.0f);
 glVertex2f((0.12f-ss), (-0.43f));
glVertex2f((0.18f-ss), (-0.43f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.12f-ss), (-0.43f));
glVertex2f((0.12f-ss), (-0.5f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.18f-ss), (-0.43f));
glVertex2f((0.18f-ss), (-0.5f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.12f-ss), (-0.46f));
glVertex2f((0.18f-ss), (-0.46f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.07f-ss), (-0.5f));
glVertex2f((0.23f-ss), (-0.5f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.23f-ss), (-0.5f));
glVertex2f((0.23f-ss), (-0.66f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.07f-ss), (-0.5f));
glVertex2f((0.07f-ss), (-0.66f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.1f-ss), (-0.55f));
glVertex2f((0.1f-ss), (-0.7f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.2f-ss), (-0.55f));
glVertex2f((0.2f-ss), (-0.7f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.1f-ss), (-0.66f));
glVertex2f((0.07f-ss), (-0.66f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.1f-ss), (-0.63f));
glVertex2f((0.07f-ss), (-0.63f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.2f-ss), (-0.66f));
glVertex2f((0.23f-ss), (-0.66f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.2f-ss), (-0.63f));
glVertex2f((0.23f-ss), (-0.63f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.1f-ss), (-0.7f));
glVertex2f((0.2f-ss), (-0.7f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.11f-ss), (-0.7f));
glVertex2f((0.11f-ss), (-0.8f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.19f-ss), (-0.7f));
glVertex2f((0.19f-ss), (-0.8f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.16f-ss), (-0.73f));
glVertex2f((0.16f-ss), (-0.8f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.14f-ss), (-0.73f));
glVertex2f((0.14f-ss), (-0.8f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.14f-ss), (-0.78f));
glVertex2f((0.11f-ss), (-0.78f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.16f-ss), (-0.78f));
glVertex2f((0.19f-ss), (-0.78f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.14f-ss), (-0.73f));
glVertex2f((0.16f-ss), (-0.73f));
 glEnd();
 
 glBegin(GL_LINES);//belindeki xett
 glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.11f-ss), (-0.3f));
glVertex2f((0.11f-ss), (-0.6f));
 glEnd();
 
 glBegin(GL_QUADS);//bayraq
  glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.11f-ss), (-0.3f));
glVertex2f((0.11f-ss), (-0.45f));
glVertex2f((-0.03f-ss), (-0.45f));
glVertex2f((-0.03f-ss), (-0.3f));

glColor3ub(0, 56, 168);
 glVertex2f((0.11f-ss), (-0.3f));
glVertex2f((0.11f-ss), (-0.35f));
glVertex2f((-0.03f-ss), (-0.35f));
glVertex2f((-0.03f-ss), (-0.3f));

glColor3ub(234, 29, 44);
glVertex2f((0.11f-ss), (-0.35f));
glVertex2f((0.11f-ss), (-0.4f));
glVertex2f((-0.03f-ss), (-0.4f));
glVertex2f((-0.03f-ss), (-0.35f));

glColor3ub(0, 128, 0);
glVertex2f((0.11f-ss), (-0.4f));
glVertex2f((0.11f-ss), (-0.45f));
glVertex2f((-0.03f-ss), (-0.45f));
glVertex2f((-0.03f-ss), (-0.4f));
 glEnd();
 
 glBegin(GL_QUADS);//sari chanta
 glColor3f(1.0, 1.0, 0.0);
 glVertex2f((0.105f-ss), (-0.5f));
glVertex2f((0.115f-ss), (-0.5f));
glVertex2f((0.115f-ss), (-0.53f));
glVertex2f((0.105f-ss), (-0.53f));

glColor3f(1.0, 1.0, 0.0);
 glVertex2f((0.185f-ss), (-0.5f));
glVertex2f((0.195f-ss), (-0.5f));
glVertex2f((0.195f-ss), (-0.53f));
glVertex2f((0.185f-ss), (-0.53f));

glColor3f(1.0, 1.0, 0.0);
 glVertex2f((0.105f-ss), (-0.53f));
glVertex2f((0.195f-ss), (-0.53f));
glVertex2f((0.195f-ss), (-0.6f));
glVertex2f((0.105f-ss), (-0.6f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.145f-ss), (-0.55f));
glVertex2f((0.154f-ss), (-0.55f));
glVertex2f((0.154f-ss), (-0.56f));
glVertex2f((0.145f-ss), (-0.56f));


 glEnd();
 
 glBegin(GL_LINES);
 glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.105f-ss), (-0.5f));
glVertex2f((0.105f-ss), (-0.6f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.105f-ss), (-0.5f));
glVertex2f((0.115f-ss), (-0.5f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.115f-ss), (-0.53f));
glVertex2f((0.185f-ss), (-0.53f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.105f-ss), (-0.6f));
glVertex2f((0.195f-ss), (-0.6f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.185f-ss), (-0.5f));
glVertex2f((0.195f-ss), (-0.5f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.195f-ss), (-0.5f));
glVertex2f((0.195f-ss), (-0.6f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.185f-ss), (-0.5f));
glVertex2f((0.185f-ss), (-0.53f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.115f-ss), (-0.5f));
glVertex2f((0.115f-ss), (-0.53f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.109f-ss), (-0.555f));
glVertex2f((0.191f-ss), (-0.555f));

 glEnd();
 
  glColor3f(1.0, 1.0, 1.0); //yarim ay
    drawCircle(0.05-ss, -0.375, 0.015, 100);
 
glColor3ub(234, 29, 44); 
  drawCircle(0.045-ss, -0.375, 0.011, 100);
  
  glBegin(GL_QUADS); //ulduz   
     glColor3f(1.0, 1.0, 1.0); 
      glVertex2f((0.021f-ss), (-0.375f));//1
      glVertex2f((0.0245f-ss), (-0.356f));
      glVertex2f((0.029f-ss), (-0.375f));//2
      glVertex2f((0.0245f-ss), (-0.394f));

      glColor3f(1.0, 1.0, 1.0); 
      glVertex2f((0.011f-ss), (-0.375f));
      glVertex2f((0.0255f-ss), (-0.37f));//3
      glVertex2f((0.039f-ss), (-0.375f));
      glVertex2f((0.0255f-ss), (-0.38f));//4
  glEnd();
  glBegin(GL_TRIANGLES);//ulduz
   glColor3f(1.0, 1.0, 1.0); 
      glVertex2f((0.021f-ss), (-0.375f));
      glVertex2f((0.0245f-ss), (-0.37f));
      glVertex2f((0.016f-ss), (-0.356f));
      
       glColor3f(1.0, 1.0, 1.0); 
       glVertex2f((0.029f-ss), (-0.375f));//2
       glVertex2f((0.0245f-ss), (-0.37f));//3
       glVertex2f((0.034f-ss), (-0.356f));
       
       glColor3f(1.0, 1.0, 1.0); 
       glVertex2f((0.021f-ss), (-0.375f));//1
        glVertex2f((0.0245f-ss), (-0.38f));//4
         glVertex2f((0.016f-ss), (-0.392f));
         
         glColor3f(1.0, 1.0, 1.0); 
         glVertex2f((0.029f-ss), (-0.375f));//2
       glVertex2f((0.0245f-ss), (-0.38f));//4
       glVertex2f((0.034f-ss), (-0.392f));
  glEnd(); 
  
  
   glColor3f(0.3+(5.8*a), 0.0, 0.5+(1.8*a));
   drawFilledEllipse(0.235+(5.7*a), -0.65+(2*a), 0.01+(2.5*a), 0.01+(6*a), 100);
    glColor3f(0.3+(7.8*a), 0.0, 0.5+(3.8*a));
    drawFilledEllipse(0.235+(5.4*a), -0.65+(2*a), 0.01+(2*a), 0.01+(5*a), 100);
     glColor3f(0.3+(9.8*a), 0.0, 0.5+(5.8*a));
    drawFilledEllipse(0.235+(5.1*a), -0.65+(2*a), 0.01+(1.5*a), 0.01+(4*a), 100);
     glColor3f(0.3+(11.8*a), 0.0, 0.5+(7.8*a));
    drawFilledEllipse(0.235+(5*a), -0.65+(2*a), 0.01+(1*a), 0.01+(3*a), 100);
     glColor3f(0.3+(13.8*a), 0.0, 0.5+(9.8*a));
    drawFilledEllipse(0.235+(5.2*a), -0.65+(2*a), 0.01+(0.5*a), 0.01+(2*a), 100);
     glColor3f(0.3+(30*a), 0.0+(14*a), 0.5+(26*a));
    drawFilledEllipse(0.235+(5.3*a), -0.65+(2*a), 0.01+(0.3*a)+p, 0.01+(1*a)+p, 100);//
}
//////////////////////////
////////NURLAN --->STATE 2
  else if(state == 2){
  
 
  
  glBegin(GL_QUADS);///////////////////////////////////////////////////////////////////////////daggg
glColor3f(80.0f / 255.0f, 112.0f / 255.0f, 20.0f / 255.0f);
glVertex2f(-2.0f, 0.1f);

glVertex2f(2.0f, 0.1f);
glColor3f(143.0f / 255.0f, 164.0f / 255.0f, 26.0f / 255.0f);

glVertex2f(2.0f, -1.0f);

glVertex2f(-2.0f, -1.0f);
glColor3f(133.0f / 255.0f, 142.0f / 255.0f, 26.0f / 255.0f);

  glEnd();
  
    // River side

glBegin(GL_POLYGON);
glColor3f(7.0f / 255.0f, 57.0f / 255.0f, 171.0f / 255.0f);

glVertex2f(0.8f, -1.0f); 
glColor3f(96.0f / 255.0f, 166.0f / 255.0f, 238.0f / 255.0f);

glVertex2f(0.6f, -1.0f);
glColor3f(35.0f / 255.0f, 96.0f / 255.0f, 173.0f / 255.0f);

glVertex2f(-0.1f, 0.1f); 
glVertex2f(0.1f, 0.1f); 
glEnd();
  
  glBegin(GL_TRIANGLES); 
glColor3f(113.0f / 255.0f, 94.0f / 255.0f, 98.0f / 255.0f);
glVertex2f(-2.0f, -0.2f);
glColor3f(113.0f / 255.0f, 94.0f / 255.0f, 98.0f / 255.0f);
glVertex2f(-0.1f, 0.4f);
glColor3f(91.0f / 255.0f, 71.0f / 255.0f, 78.0f / 255.0f);

glVertex2f(0.3f, 0.07f);

glEnd();

glBegin(GL_TRIANGLES); 
glColor3f(40.0f / 255.0f, 39.0f / 255.0f, 57.0f / 255.0f);
glVertex2f(2.0f, -0.5f);
glColor3f(143.0f / 255.0f, 117.0f / 255.0f, 100.0f / 255.0f);

glVertex2f(0.7f, 0.68f);
glColor3f(112.0f / 255.0f, 98.0f / 255.0f, 88.0f / 255.0f);

glVertex2f(0.2f, 0.0f);
glEnd();

glBegin(GL_TRIANGLES); 
glColor3f(55.0f / 255.0f, 60.0f / 255.0f, 88.0f / 255.0f);
glVertex2f(-3.0f, -0.5f);
glColor3f(80.0f / 255.0f, 81.0f / 255.0f, 82.0f / 255.0f);


glVertex2f(-0.7f, 0.8f);
glColor3f(90.0f / 255.0f, 71.0f / 255.0f, 76.0f / 255.0f);


glVertex2f(-0.1f, 0.0f);

glEnd();///////////////////////////////////////

 glBegin(GL_TRIANGLES);
  glColor3f(0.0, 0.0, 0.0);
  glVertex2f(-0.3f+bulud , 0.77f);
glVertex2f(-0.36f+bulud , 0.77f);
glVertex2f(-0.4f+bulud, 0.82f);
glColor3f(1.0, 1.0, 1.0);
  glVertex2f(-0.31f+bulud , 0.78f);
glVertex2f(-0.35f+bulud , 0.78f);
glVertex2f(-0.39f+bulud, 0.81f);

glBegin(GL_TRIANGLES);
  glColor3f(0.0, 0.0, 0.0);
  glVertex2f(-0.3f+bulud, 0.74f);
glVertex2f(-0.36f +bulud, 0.74f);
glVertex2f(-0.4f+bulud, 0.69f);
 glColor3f(1.0, 1.0, 1.0);
  glVertex2f(-0.31f+bulud , 0.73f);
glVertex2f(-0.35f +bulud, 0.73f);
glVertex2f(-0.39f+bulud, 0.7f);


glColor3f(0.0, 0.0, 0.0);
  glVertex2f(-0.3f+bulud , 0.77f);
glVertex2f(-0.3f+bulud , 0.74f);
glVertex2f(-0.25f+bulud, 0.755f);
  glEnd();

  glBegin(GL_QUADS);
  glColor3f(0.0, 0.0, 0.0);
  glVertex2f(-0.36f+bulud , 0.74f);
glVertex2f(-0.36f+bulud , 0.77f);
glVertex2f(-0.3f+bulud, 0.77f);
glVertex2f(-0.3f+bulud , 0.74f);

glColor3f(1.0, 1.0, 1.0);
  glVertex2f(-0.35f+bulud , 0.745f);
glVertex2f(-0.35f +bulud, 0.765f);
glVertex2f(-0.31f+bulud, 0.765f);
glVertex2f(-0.31f+bulud , 0.745f);

  glEnd();
  glColor3f(1.0, 1.0, 1.0);
  drawCircle(-0.3+bulud, 0.755, 0.009, 100);
  
  glBegin(GL_LINES);
  glColor3f(0.0, 0.0, 0.0);
 glVertex2f(-0.555f+bulud, 0.85f);
glVertex2f(-0.36f+bulud , 0.74f);
glColor3f(0.0, 0.0, 0.0);
glVertex2f(-0.36f+bulud, 0.77f);
 glVertex2f(-0.555f +bulud, 0.7f);
  glEnd();
  
  glBegin(GL_QUADS);//flying bayraq

glColor3ub(0, 56, 168);
 glVertex2f(-0.555f +bulud, 0.7f);
glVertex2f(-0.555f +bulud, 0.75f);
glVertex2f(-0.91f+bulud , 0.75f);
glVertex2f(-0.91f+bulud, 0.7f);

glColor3ub(234, 29, 44);
glVertex2f(-0.555f+bulud , 0.75f);
glVertex2f(-0.555f +bulud, 0.8f);
glVertex2f(-0.91f +bulud, 0.8f);
glVertex2f(-0.91f+bulud, 0.75f);

glColor3ub(0, 128, 0);
glVertex2f(-0.555f +bulud, 0.8f);
glVertex2f(-0.555f+bulud , 0.85f);
glVertex2f(-0.91f +bulud, 0.85f);
glVertex2f(-0.91f+bulud, 0.8f);
glEnd();

 glColor3f(1.0, 1.0, 1.0); //yarim ay
    drawCircle(-0.73+bulud, 0.775, 0.015, 100);
 
glColor3ub(234, 29, 44); 
  drawCircle(-0.735+bulud, 0.775, 0.011, 100);
 glBegin(GL_QUADS); //ulduz   
     glColor3f(1.0, 1.0, 1.0); 
      glVertex2f(-0.751f+bulud, 0.775f);//1
      glVertex2f(-0.7545f+bulud, 0.756f);
      glVertex2f(-0.759f+bulud, 0.775f);//2
      glVertex2f(-0.7545f+bulud, 0.794f);

      glColor3f(1.0, 1.0, 1.0); 
      glVertex2f(-0.741f+bulud, 0.775f);
      glVertex2f(-0.7555f+bulud, 0.77f);//3
      glVertex2f(-0.769f+bulud, 0.775f);
      glVertex2f(-0.7555f+bulud, 0.78f);//4
  glEnd();
  glBegin(GL_TRIANGLES);//ulduz
   glColor3f(1.0, 1.0, 1.0); 
      glVertex2f(-0.751f+bulud, 0.775f);
      glVertex2f(-0.7545f+bulud, 0.77f);
      glVertex2f(-0.746f+bulud, 0.756f);
      
       glColor3f(1.0, 1.0, 1.0); 
       glVertex2f(-0.759f+bulud, 0.775f);//2
       glVertex2f(-0.7545f+bulud, 0.77f);//3
       glVertex2f(-0.764f+bulud, 0.756f);
       
       glColor3f(1.0, 1.0, 1.0); 
       glVertex2f(-0.751f+bulud, 0.775f);//1
        glVertex2f(-0.7545f+bulud, 0.78f);//4
         glVertex2f(-0.746f+bulud, 0.792f);
         
         glColor3f(1.0, 1.0, 1.0); 
         glVertex2f(-0.759f+bulud, 0.775f);//2
       glVertex2f(-0.7545f+bulud, 0.78f);//4
       glVertex2f(-0.764f+bulud, 0.792f);
  glEnd();
//
  
glBegin(GL_QUADS); 
glColor3f(200.0f / 255.0f, 180.0f / 255.0f, 162.0f / 255.0f);
glVertex2f(-1.0f, -1.1f);
glVertex2f(-1.0f, -0.523f);
glColor3f(110.0f / 255.0f, 110.0f / 255.0f, 98.0f / 255.0f);
glVertex2f(0.8f, -0.523f);
glVertex2f(0.8f, -1.1f);

glEnd();
glBegin(GL_QUADS);
glColor3f(200.0f / 255.0f, 180.0f / 255.0f, 162.0f / 255.0f);
glVertex2f(0.7f, -0.6f);
glVertex2f(0.7f, -0.7f);
glVertex2f(0.6f, -0.7f);
glVertex2f(0.6f, -0.6f);


glColor3f(110.0f / 255.0f, 110.0f / 255.0f, 98.0f / 255.0f);
glVertex2f(0.68f, -0.62f);
glVertex2f(0.68f, -0.68f);
glVertex2f(0.62f, -0.68f);
glVertex2f(0.62f, -0.62f);

glColor3f(200.0f / 255.0f, 180.0f / 255.0f, 162.0f / 255.0f);
glVertex2f(0.66f, -0.64f);
glVertex2f(0.66f, -0.66f);
glVertex2f(0.64f, -0.66f);
glVertex2f(0.64f, -0.64f);
glEnd();


 if(byrq==8){
  glBegin(GL_QUADS);//asilan bayraq
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.645f, -0.655f);
glVertex2f(0.645f, -0.2f);
glVertex2f(0.655f, -0.2f);
glVertex2f(0.655f, -0.655f);

glColor3ub(0, 56, 168);
 glVertex2f(0.655f , -0.2f);
glVertex2f(0.655f , -0.25f);
glVertex2f(0.81f , -0.25f);
glVertex2f(0.81f, -0.2f);

glColor3ub(234, 29, 44);
glVertex2f(0.655f , -0.25f);
glVertex2f(0.655f , -0.3f);
glVertex2f(0.81f , -0.3f);
glVertex2f(0.81f, -0.25f);

glColor3ub(0, 128, 0);
glVertex2f(0.655f , -0.3f);
glVertex2f(0.655f , -0.35f);
glVertex2f(0.81f , -0.35f);
glVertex2f(0.81f, -0.3f);
glEnd();

 glColor3f(1.0, 1.0, 1.0); //yarim ay
    drawCircle(0.73, -0.275, 0.015, 100);
 
glColor3ub(234, 29, 44); 
  drawCircle(0.735, -0.275, 0.011, 100);
 glBegin(GL_QUADS); //ulduz   
     glColor3f(1.0, 1.0, 1.0); 
      glVertex2f(0.751f, -0.275f);//1
      glVertex2f(0.7545f, -0.256f);
      glVertex2f(0.759f, -0.275f);//2
      glVertex2f(0.7545f, -0.294f);

      glColor3f(1.0, 1.0, 1.0); 
      glVertex2f(0.741f, -0.275f);
      glVertex2f(0.7555f, -0.27f);//3
      glVertex2f(0.769f, -0.275f);
      glVertex2f(0.7555f, -0.28f);//4
  glEnd();
  glBegin(GL_TRIANGLES);//ulduz
   glColor3f(1.0, 1.0, 1.0); 
      glVertex2f(0.751f, -0.275f);
      glVertex2f(0.7545f, -0.27f);
      glVertex2f(0.746f, -0.256f);
      
       glColor3f(1.0, 1.0, 1.0); 
       glVertex2f(0.759f, -0.275f);//2
       glVertex2f(0.7545f, -0.27f);//3
       glVertex2f(0.764f, -0.256f);
       
       glColor3f(1.0, 1.0, 1.0); 
       glVertex2f(0.751f, -0.275f);//1
        glVertex2f(0.7545f, -0.28f);//4
         glVertex2f(0.746f, -0.292f);
         
         glColor3f(1.0, 1.0, 1.0); 
         glVertex2f(0.759f, -0.275f);//2
       glVertex2f(0.7545f, -0.28f);//4
       glVertex2f(0.764f, -0.292f);
  glEnd();
  
}

        
      
    
    glBegin(GL_QUADS);//body
glColor3f(0.0, 0.3, 0.0);
glVertex2f((0.2f-ss-0.4f), (-0.5f));
glVertex2f((0.1f-ss-0.4f), (-0.5f));
glVertex2f((0.1f-ss-0.4f), (-0.7f));
glVertex2f((0.2f-ss-0.4f), (-0.7f));
glEnd();

glBegin(GL_QUADS);//sol qol
glColor3f(0.0, 0.3, 0.0);
glVertex2f((0.07f-ss-0.4f), (-0.5f));
glVertex2f((0.1f-ss-0.4f), (-0.5f));
glVertex2f((0.1f-ss-0.4f), (-0.63f));
glVertex2f((0.07f-ss-0.4f), (-0.63f));

glColor3f(1.0, 0.5, 0.5);
 glVertex2f((0.07f-ss-0.4f), (-0.63f));
glVertex2f((0.1f-ss-0.4f), (-0.63f));
glVertex2f((0.1f-ss-0.4f), (-0.66f));
glVertex2f((0.07f-ss-0.4f), (-0.66f));

//right qol
glColor3f(0.0, 0.3, 0.0);
glVertex2f((0.2f-ss-0.4f), (-0.5f));
glVertex2f((0.23f-ss-0.4f), (-0.5f));
glVertex2f((0.23f-ss-0.4f), (-0.63f));
glVertex2f((0.2f-ss-0.4f), (-0.63f));

glColor3f(1.0, 0.5, 0.5);
 glVertex2f((0.2f-ss-0.4f), (-0.63f));
glVertex2f((0.23f-ss-0.4f), (-0.63f));
glVertex2f((0.23f-ss-0.4f), (-0.66f));
glVertex2f((0.2f-ss-0.4f), (-0.66f));
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0, 0.5, 0.5);//head
 glVertex2f((0.12f-ss-0.4f), (-0.46f));
glVertex2f((0.18f-ss-0.4f), (-0.46f));
glVertex2f((0.18f-ss-0.4f), (-0.5f));
glVertex2f((0.12f-ss-0.4f), (-0.5f));

glColor3f(0.0, 0.3, 0.0);
 glVertex2f((0.12f-ss-0.4f), (-0.43f));
glVertex2f((0.18f-ss-0.4f), (-0.43f));
glVertex2f((0.18f-ss-0.4f), (-0.46f));
glVertex2f((0.12f-ss-0.4f), (-0.46f));

glEnd();
glBegin(GL_TRIANGLES);
glColor3f(0.0, 0.3, 0.0);//papaq
 glVertex2f((0.19f-ss-0.4f), (-0.445f));
glVertex2f((0.18f-ss-0.4f), (-0.445f));
glVertex2f((0.18f-ss-0.4f), (-0.46f));
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0, 0.3, 0.0);//sol ve sag ayaq
 glVertex2f((0.11f-ss-0.4f), (-0.7f));
glVertex2f((0.11f-ss-0.4f), (-0.73f));
glVertex2f((0.19f-ss-0.4f), (-0.73f));
glVertex2f((0.19f-ss-0.4f), (-0.7f));

glColor3f(0.0, 0.3, 0.0);
 glVertex2f((0.11f-ss-0.4f), (-0.78f));
glVertex2f((0.11f-ss-0.4f), (-0.73f));
glVertex2f((0.14f-ss-0.4f), (-0.73f));
glVertex2f((0.14f-ss-0.4f), (-0.78f));

glColor3f(0.0, 0.3, 0.0);
 glVertex2f((0.16f-ss-0.4f), (-0.78f));
glVertex2f((0.16f-ss-0.4f), (-0.73f));
glVertex2f((0.19f-ss-0.4f), (-0.73f));
glVertex2f((0.19f-ss-0.4f), (-0.78f));

glColor3f(0.0, 0.0, 0.0);//foot
 glVertex2f((0.16f-ss-0.4f), (-0.8f));
glVertex2f((0.16f-ss-0.4f), (-0.78f));
glVertex2f((0.19f-ss-0.4f), (-0.78f));
glVertex2f((0.19f-ss-0.4f), (-0.8f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.11f-ss-0.4f), (-0.8f));
glVertex2f((0.11f-ss-0.4f), (-0.78f));
glVertex2f((0.14f-ss-0.4f), (-0.78f));
glVertex2f((0.14f-ss-0.4f), (-0.8f));

glEnd();

 glBegin(GL_LINES);
 glColor3f(0.0f, 0.0f, 0.0f);
 glVertex2f((0.12f-ss-0.4f), (-0.43f));
glVertex2f((0.18f-ss-0.4f), (-0.43f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.12f-ss-0.4f), (-0.43f));
glVertex2f((0.12f-ss-0.4f), (-0.5f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.18f-ss-0.4f), (-0.43f));
glVertex2f((0.18f-ss-0.4f), (-0.5f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.12f-ss-0.4f), (-0.46f));
glVertex2f((0.18f-ss-0.4f), (-0.46f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.07f-ss-0.4f), (-0.5f));
glVertex2f((0.23f-ss-0.4f), (-0.5f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.23f-ss-0.4f), (-0.5f));
glVertex2f((0.23f-ss-0.4f), (-0.66f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.07f-ss-0.4f), (-0.5f));
glVertex2f((0.07f-ss-0.4f), (-0.66f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.1f-ss-0.4f), (-0.55f));
glVertex2f((0.1f-ss-0.4f), (-0.7f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.2f-ss-0.4f), (-0.55f));
glVertex2f((0.2f-ss-0.4f), (-0.7f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.1f-ss-0.4f), (-0.66f));
glVertex2f((0.07f-ss-0.4f), (-0.66f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.1f-ss-0.4f), (-0.63f));
glVertex2f((0.07f-ss-0.4f), (-0.63f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.2f-ss-0.4f), (-0.66f));
glVertex2f((0.23f-ss-0.4f), (-0.66f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.2f-ss-0.4f), (-0.63f));
glVertex2f((0.23f-ss-0.4f), (-0.63f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.1f-ss-0.4f), (-0.7f));
glVertex2f((0.2f-ss-0.4f), (-0.7f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.11f-ss-0.4f), (-0.7f));
glVertex2f((0.11f-ss-0.4f), (-0.8f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.19f-ss-0.4f), (-0.7f));
glVertex2f((0.19f-ss-0.4f), (-0.8f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.16f-ss-0.4f), (-0.73f));
glVertex2f((0.16f-ss-0.4f), (-0.8f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.14f-ss-0.4f), (-0.73f));
glVertex2f((0.14f-ss-0.4f), (-0.8f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.14f-ss-0.4f), (-0.78f));
glVertex2f((0.11f-ss-0.4f), (-0.78f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.16f-ss-0.4f), (-0.78f));
glVertex2f((0.19f-ss-0.4f), (-0.78f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.14f-ss-0.4f), (-0.73f));
glVertex2f((0.16f-ss-0.4f), (-0.73f));
 glEnd();
 if(byrq==0){
 	glBegin(GL_LINES);//belindeki xett
 glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.11f-ss-0.4f), (-0.3f));
glVertex2f((0.11f-ss-0.4f), (-0.6f));
 glEnd();
 
 glBegin(GL_QUADS);//bayraq
  glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.11f-ss-0.4f), (-0.3f));
glVertex2f((0.11f-ss-0.4f), (-0.45f));
glVertex2f((-0.03f-ss-0.4f), (-0.45f));
glVertex2f((-0.03f-ss-0.4f), (-0.3f));

glColor3ub(0, 56, 168);
 glVertex2f((0.11f-ss-0.4f), (-0.3f));
glVertex2f((0.11f-ss-0.4f), (-0.35f));
glVertex2f((-0.03f-ss-0.4f), (-0.35f));
glVertex2f((-0.03f-ss-0.4f), (-0.3f));

glColor3ub(234, 29, 44);
glVertex2f((0.11f-ss-0.4f), (-0.35f));
glVertex2f((0.11f-ss-0.4f), (-0.4f));
glVertex2f((-0.03f-ss-0.4f), (-0.4f));
glVertex2f((-0.03f-ss-0.4f), (-0.35f));

glColor3ub(0, 128, 0);
glVertex2f((0.11f-ss-0.4f), (-0.4f));
glVertex2f((0.11f-ss-0.4f), (-0.45f));
glVertex2f((-0.03f-ss-0.4f), (-0.45f));
glVertex2f((-0.03f-ss-0.4f), (-0.4f));
 glEnd();
 
 
 
  glColor3f(1.0, 1.0, 1.0); //yarim ay
    drawCircle(0.05-ss-0.4f, -0.375, 0.015, 100);
 
glColor3ub(234, 29, 44); 
  drawCircle(0.045-ss-0.4f, -0.375, 0.011, 100);
  
  glBegin(GL_QUADS); //ulduz   
     glColor3f(1.0, 1.0, 1.0); 
      glVertex2f((0.021f-ss-0.4f), (-0.375f));//1
      glVertex2f((0.0245f-ss-0.4f), (-0.356f));
      glVertex2f((0.029f-ss-0.4f), (-0.375f));//2
      glVertex2f((0.0245f-ss-0.4f), (-0.394f));

      glColor3f(1.0, 1.0, 1.0); 
      glVertex2f((0.011f-ss-0.4f), (-0.375f));
      glVertex2f((0.0255f-ss-0.4f), (-0.37f));//3
      glVertex2f((0.039f-ss-0.4f), (-0.375f));
      glVertex2f((0.0255f-ss-0.4f), (-0.38f));//4
  glEnd();
  glBegin(GL_TRIANGLES);//ulduz
   glColor3f(1.0, 1.0, 1.0); 
      glVertex2f((0.021f-ss-0.4f), (-0.375f));
      glVertex2f((0.0245f-ss-0.4f), (-0.37f));
      glVertex2f((0.016f-ss-0.4f), (-0.356f));
      
       glColor3f(1.0, 1.0, 1.0); 
       glVertex2f((0.029f-ss-0.4f), (-0.375f));//2
       glVertex2f((0.0245f-ss-0.4f), (-0.37f));//3
       glVertex2f((0.034f-ss-0.4f), (-0.356f));
       
       glColor3f(1.0, 1.0, 1.0); 
       glVertex2f((0.021f-ss-0.4f), (-0.375f));//1
        glVertex2f((0.0245f-ss-0.4f), (-0.38f));//4
         glVertex2f((0.016f-ss-0.4f), (-0.392f));
         
         glColor3f(1.0, 1.0, 1.0); 
         glVertex2f((0.029f-ss-0.4f), (-0.375f));//2
       glVertex2f((0.0245f-ss-0.4f), (-0.38f));//4
       glVertex2f((0.034f-ss-0.4f), (-0.392f));
  glEnd();
  
 }
 
  
 glBegin(GL_QUADS);//sari chanta
 glColor3f(1.0, 1.0, 0.0);
 glVertex2f((0.105f-ss-0.4f), (-0.5f));
glVertex2f((0.115f-ss-0.4f), (-0.5f));
glVertex2f((0.115f-ss-0.4f), (-0.53f));
glVertex2f((0.105f-ss-0.4f), (-0.53f));

glColor3f(1.0, 1.0, 0.0);
 glVertex2f((0.185f-ss-0.4f), (-0.5f));
glVertex2f((0.195f-ss-0.4f), (-0.5f));
glVertex2f((0.195f-ss-0.4f), (-0.53f));
glVertex2f((0.185f-ss-0.4f), (-0.53f));

glColor3f(1.0, 1.0, 0.0);
 glVertex2f((0.105f-ss-0.4f), (-0.53f));
glVertex2f((0.195f-ss-0.4f), (-0.53f));
glVertex2f((0.195f-ss-0.4f), (-0.6f));
glVertex2f((0.105f-ss-0.4f), (-0.6f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.145f-ss-0.4f), (-0.55f));
glVertex2f((0.154f-ss-0.4f), (-0.55f));
glVertex2f((0.154f-ss-0.4f), (-0.56f));
glVertex2f((0.145f-ss-0.4f), (-0.56f));


 glEnd();
 
 glBegin(GL_LINES);
 glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.105f-ss-0.4f), (-0.5f));
glVertex2f((0.105f-ss-0.4f), (-0.6f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.105f-ss-0.4f), (-0.5f));
glVertex2f((0.115f-ss-0.4f), (-0.5f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.115f-ss-0.4f), (-0.53f));
glVertex2f((0.185f-ss-0.4f), (-0.53f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.105f-ss-0.4f), (-0.6f));
glVertex2f((0.195f-ss-0.4f), (-0.6f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.185f-ss-0.4f), (-0.5f));
glVertex2f((0.195f-ss-0.4f), (-0.5f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.195f-ss-0.4f), (-0.5f));
glVertex2f((0.195f-ss-0.4f), (-0.6f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.185f-ss-0.4f), (-0.5f));
glVertex2f((0.185f-ss-0.4f), (-0.53f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.115f-ss-0.4f), (-0.5f));
glVertex2f((0.115f-ss-0.4f), (-0.53f));

glColor3f(0.0, 0.0, 0.0);
 glVertex2f((0.109f-ss-0.4f), (-0.555f));
glVertex2f((0.191f-ss-0.4f), (-0.555f));

 glEnd();
 
  
  
  glColor3f(0.3, 0.0, 0.5);//portal
    drawFilledEllipse( -0.8 , -0.5, 0.15, 0.35, 100);
     glColor3f(0.59f, 0.0f, 0.59f);
    drawFilledEllipse( -0.8 , -0.5, 0.13, 0.32, 100);
    glColor3f(0.69f, 0.0f, 0.69f);
     drawFilledEllipse(-0.8 , -0.5, 0.11, 0.27, 100);
     glColor3f(0.79f, 0.0f, 0.79f);
   drawFilledEllipse( -0.8 , -0.5, 0.09, 0.24, 100);
     glColor3f(0.89f, 0.0f, 0.89f);
    drawFilledEllipse(-0.82 , -0.5, 0.07, 0.2, 100);
     glColor3f(0.99f, 0.0f, 0.99f);
    drawFilledEllipse( -0.81 , -0.5, 0.05, 0.18, 100);
     glColor3f(1.55f, 1.0f, 1.55f);
     drawFilledEllipse(-0.79 , -0.5, n, m, 100);//0.03..0.09 
	 }
    
     
     ///////////////////////// STATE 3----> NIHAT
	 if(state==3) {
    


//sky
glBegin(GL_QUADS); 
glColor3f(135.0f / 255.0f, 206.0f / 255.0f, 235.0f / 255.0f);
glVertex2f(-1.0f, 0.0f);

glVertex2f(-1.0f, 1.0f);

glVertex2f(1.0f, 1.0f);
glColor3f(249.0f / 255.0f, 211.0f / 255.0f, 132.0f / 255.0f);

glVertex2f(1.0f, 0.0f);
glColor3f(249.0f / 255.0f, 211.0f / 255.0f, 132.0f / 255.0f);

glEnd();
//sun shade
glBegin(GL_POLYGON);
glColor3f(154.0f / 255.0f, 188.0f / 255.0f, 196.0f / 255.0f);

    float radius14 = 0.35f;
    for (float angle = 0.0f; angle <= 360.0f; angle += 10.0f) {
        float x_pos = 0.08f + radius14 * cos(angle * 3.1415926f / 180.0f);

        float y_pos = 0.8f + radius14 * sin(angle * 3.1415926f / 180.0f);
        glVertex2f(x_pos, y_pos);
        
    }
    glEnd();
    glBegin(GL_POLYGON);
glBegin(GL_POLYGON);
glColor3f(175.0f / 255.0f, 158.0f / 255.0f, 151.0f / 255.0f);

    float radius13 = 0.296f;
    for (float angle = 0.0f; angle <= 360.0f; angle += 10.0f) {
        float x_pos = 0.08f + radius13 * cos(angle * 3.1415926f / 180.0f);

        float y_pos = 0.8f + radius13 * sin(angle * 3.1415926f / 180.0f);
        glVertex2f(x_pos, y_pos);
        
    }
    glEnd();
    glBegin(GL_POLYGON);
glBegin(GL_POLYGON);
glColor3f(213.0f / 255.0f, 157.0f / 255.0f, 112.0f / 255.0f);

    float radius12 = 0.29f;
    for (float angle = 0.0f; angle <= 360.0f; angle += 10.0f) {
        float x_pos = 0.08f + radius12 * cos(angle * 3.1415926f / 180.0f);

        float y_pos = 0.8f + radius12 * sin(angle * 3.1415926f / 180.0f);
        glVertex2f(x_pos, y_pos);
        
    }
    glEnd();
    glBegin(GL_POLYGON);
glBegin(GL_POLYGON);
glColor3f(250.0f / 255.0f, 165.0f / 255.0f, 80.0f / 255.0f);

    float radius11 = 0.28f;
    for (float angle = 0.0f; angle <= 360.0f; angle += 10.0f) {
        float x_pos = 0.08f + radius11 * cos(angle * 3.1415926f / 180.0f);

        float y_pos = 0.8f + radius11 * sin(angle * 3.1415926f / 180.0f);
        glVertex2f(x_pos, y_pos);
        
    }
    glEnd();
    glBegin(GL_POLYGON);
glBegin(GL_POLYGON);
glColor3f(255.0f / 255.0f, 145.0f / 255.0f, 65.0f / 255.0f);

    float radius10 = 0.27f;
    for (float angle = 0.0f; angle <= 360.0f; angle += 10.0f) {
        float x_pos = 0.08f + radius10 * cos(angle * 3.1415926f / 180.0f);

        float y_pos = 0.8f + radius10 * sin(angle * 3.1415926f / 180.0f);
        glVertex2f(x_pos, y_pos);
        
    }
    glEnd();
    glBegin(GL_POLYGON);


glBegin(GL_POLYGON);
glColor3f(255.0f / 255.0f, 151.0f / 255.0f, 62.0f / 255.0f);

    float radius7 = 0.26f;
    for (float angle = 0.0f; angle <= 360.0f; angle += 10.0f) {
        float x_pos = 0.08f + radius7 * cos(angle * 3.1415926f / 180.0f);

        float y_pos = 0.8f + radius7 * sin(angle * 3.1415926f / 180.0f);
        glVertex2f(x_pos, y_pos);
        
    }
    glEnd();
    glBegin(GL_POLYGON);
glColor3f(249.0f / 255.0f, 153.0f / 255.0f, 55.0f / 255.0f);

    float radius8 = 0.25f;
    for (float angle = 0.0f; angle <= 360.0f; angle += 10.0f) {
        float x_pos = 0.08f + radius8 * cos(angle * 3.1415926f / 180.0f);

        float y_pos = 0.8f + radius8 * sin(angle * 3.1415926f / 180.0f);
        glVertex2f(x_pos, y_pos);
        
    }
    glEnd();
  glBegin(GL_POLYGON);
glColor3f(255.0f / 255.0f, 172.0f / 255.0f, 69.0f / 255.0f);

    float radius9 = 0.24f;
    for (float angle = 0.0f; angle <= 360.0f; angle += 10.0f) {
        float x_pos = 0.08f + radius9 * cos(angle * 3.1415926f / 180.0f);

        float y_pos = 0.8f + radius9 * sin(angle * 3.1415926f / 180.0f);
        glVertex2f(x_pos, y_pos);
        
    }
    glEnd();
glBegin(GL_POLYGON);
glColor3f(248.0f / 255.0f, 213.0f / 255.0f, 126.0f / 255.0f);

    float radius3 = 0.23f;
    for (float angle = 0.0f; angle <= 360.0f; angle += 10.0f) {
        float x_pos = 0.08f + radius3 * cos(angle * 3.1415926f / 180.0f);

        float y_pos = 0.8f + radius3* sin(angle * 3.1415926f / 180.0f);
        glVertex2f(x_pos, y_pos);
        
    }
    glEnd();
    glBegin(GL_POLYGON);
glColor3f(248.0f / 255.0f, 233.0f / 255.0f, 183.0f / 255.0f);

    float radius4 = 0.21f;
    for (float angle = 0.0f; angle <= 360.0f; angle += 10.0f) {
        float x_pos = 0.08f + radius4 * cos(angle * 3.1415926f / 180.0f);

        float y_pos = 0.8f + radius4* sin(angle * 3.1415926f / 180.0f);
        glVertex2f(x_pos, y_pos);
        
    }
    glEnd();
     glBegin(GL_POLYGON);
     glColor3f(255.0f / 255.0f, 246.0f / 255.0f, 214.0f / 255.0f);


    float radius5 = 0.2f;
    for (float angle = 0.0f; angle <= 360.0f; angle += 10.0f) {
        float x_pos = 0.08f + radius5 * cos(angle * 3.1415926f / 180.0f);

        float y_pos = 0.8f + radius5* sin(angle * 3.1415926f / 180.0f);
        glVertex2f(x_pos, y_pos);
        
    }
    glEnd();
     glBegin(GL_POLYGON);
glColor3f(255.0f / 255.0f, 250.0f / 255.0f, 229.0f / 255.0f);

    float radius6 = 0.19f;
    for (float angle = 0.0f; angle <= 360.0f; angle += 10.0f) {
        float x_pos = 0.08f + radius6 * cos(angle * 3.1415926f / 180.0f);

        float y_pos = 0.8f + radius6* sin(angle * 3.1415926f / 180.0f);
        glVertex2f(x_pos, y_pos);
        
    }
    glEnd();
    
    
// sun
glBegin(GL_POLYGON);
glColor3f(251.0f / 255.0f, 250.0f / 255.0f, 249.0f / 255.0f);

    float radius1 = 0.18f;
    for (float angle = 0.0f; angle <= 360.0f; angle += 10.0f) {
    	
        float x_pos = 0.08f + radius1 * cos(angle * 3.1415926f / 180.0f);

        float y_pos = 0.8f + radius1 * sin(angle * 3.1415926f / 180.0f);
        glVertex2f(x_pos, y_pos);
        
    }
    glEnd();
    
 drawLines();
    
     
//Mountains
glBegin(GL_TRIANGLES); 
glColor3f(159.0f / 255.0f, 195.0f / 255.0f, 223.0f / 255.0f);
glVertex2f(-2.0f, -0.5f);
glColor3f(93.0f / 255.0f, 146.0f / 255.0f, 186.0f / 255.0f);
glVertex2f(-0.1f, 0.4f);
glColor3f(88.0f / 255.0f, 161.0f / 255.0f, 201.0f / 255.0f);
glColor3f(145.0f / 255.0f, 190.0f / 255.0f, 224.0f / 255.0f);

glVertex2f(0.3f, 0.07f);

glEnd();

glBegin(GL_TRIANGLES); 
glColor3f(41.0f / 255.0f, 87.0f / 255.0f, 130.0f / 255.0f);
glVertex2f(2.0f, -0.5f);
glVertex2f(0.7f, 0.68f);
glColor3f(88.0f / 255.0f, 161.0f / 255.0f, 201.0f / 255.0f);
glVertex2f(0.1f, 0.0f);
glColor3f(145.0f / 255.0f, 190.0f / 255.0f, 224.0f / 255.0f);
glEnd();

glBegin(GL_TRIANGLES); 
glColor3f(145.0f / 255.0f, 190.0f / 255.0f, 224.0f / 255.0f);
glVertex2f(0.1f, 0.0f);
glVertex2f(0.7f, 0.68f);
glColor3f(250.0f / 255.0f, 197.0f / 255.0f, 131.0f / 255.0f);
glVertex2f(0.15f, 0.0f);
glColor3f(145.0f / 255.0f, 190.0f / 255.0f, 224.0f / 255.0f);


glEnd();

glBegin(GL_TRIANGLES); 
glColor3f(254.0f / 255.0f, 209.0f / 255.0f, 137.0f / 255.0f);
glVertex2f(-0.7f, -0.7f);

glColor3f(159.0f / 255.0f, 195.0f / 255.0f, 223.0f / 255.0f);
glVertex2f(0.26f, 0.37f);
glColor3f(88.0f / 255.0f, 161.0f / 255.0f, 201.0f / 255.0f);

glVertex2f(0.6f, 0.002f);

glEnd();


glBegin(GL_TRIANGLES); 
glColor3f(31.0f / 255.0f, 83.0f / 255.0f, 123.0f / 255.0f);
glVertex2f(-3.0f, -0.5f);
glVertex2f(-0.7f, 0.8f);
glColor3f(88.0f / 255.0f, 161.0f / 255.0f, 201.0f / 255.0f);
glColor3f(145.0f / 255.0f, 190.0f / 255.0f, 224.0f / 255.0f);

glVertex2f(0.0f, 0.0f);

glEnd();


glBegin(GL_TRIANGLES); 
glColor3f(145.0f / 255.0f, 190.0f / 255.0f, 224.0f / 255.0f);

glVertex2f(-0.7f, 0.8f);
glVertex2f(0.1f, 0.0f);
glColor3f(250.0f / 255.0f, 197.0f / 255.0f, 131.0f / 255.0f);

glVertex2f(0.0f, 0.0f);

glEnd();
glLineWidth(1.0f);
glBegin(GL_LINE_STRIP); 
glColor3f(36.0f / 255.0f, 74.0f / 255.0f, 112.0f / 255.0f);
glVertex2f(-0.7f, 0.8f);
glColor3f(36.0f / 255.0f, 74.0f / 255.0f, 112.0f / 255.0f);
glVertex2f(-0.68f, 0.75f);
glVertex2f(-0.64f, 0.7f);
glColor3f(88.0f / 255.0f, 161.0f / 255.0f, 201.0f / 255.0f);
glVertex2f(-0.56f, 0.5f);
glVertex2f(-0.46f, 0.4f);
glVertex2f(-0.35f, 0.0f);
glColor3f(250.0f / 255.0f, 197.0f / 255.0f, 131.0f / 255.0f);
glEnd();

drawClouds();

// left hills

glBegin(GL_QUADS); 
glColor3f(108.0f / 255.0f, 140.0f / 255.0f, 119.0f / 255.0f);
glVertex2f(-1.0f, 0.5f);
glColor3f(214.0f / 255.0f, 186.0f / 255.0f, 68.0f / 255.0f);
glVertex2f(-1.0f, -1.0f);
glVertex2f(-0.2f, -1.0f);
glVertex2f(-0.2f, -0.1f);
glEnd();

glBegin(GL_QUADS); 
glColor3f(108.0f / 255.0f, 140.0f / 255.0f, 119.0f / 255.0f);
glVertex2f(-1.0f, 0.5f);
glColor3f(214.0f / 255.0f, 186.0f / 255.0f, 68.0f / 255.0f);

glVertex2f(-1.0f, -1.0f);

glVertex2f(-0.2f, -1.0f);
glVertex2f(-0.2f, -0.1f);
glEnd();
glBegin(GL_QUADS); 
glColor3f(122.0f / 255.0f, 135.0f / 255.0f, 153.0f / 255.0f);
glVertex2f(-1.0f, 0.2f);
glColor3f(214.0f / 255.0f, 186.0f / 255.0f, 68.0f / 255.0f);

glVertex2f(-1.0f, -1.0f);

glVertex2f(-0.7f, -1.0f);
glVertex2f(-0.7f, -0.1f);


glEnd();

glBegin(GL_QUADS); 
glColor3f(122.0f / 255.0f, 135.0f / 255.0f, 153.0f / 255.0f);
glVertex2f(-1.0f, 0.0f);
glColor3f(214.0f / 255.0f, 186.0f / 255.0f, 68.0f / 255.0f);

glVertex2f(-1.0f, -1.0f);

glVertex2f(-0.8f, -1.0f);
glVertex2f(-0.8f, -0.1f);


glEnd();



// ellips hill

glBegin(GL_POLYGON);
glColor3f(153.0f / 255.0f, 117.0f / 255.0f, 25.0f / 255.0f);

    float radius2 = 0.7f;
    for (float angle = 0.0f; angle <= 360.0f; angle += 10.0f) {
        float x_pos = 0.6f + radius2 * cos(angle * 2.2f / 180.0f);

        float y_pos = -0.36f + radius2 * sin(angle * 3.1415926f / 180.0f);
        glVertex2f(x_pos, y_pos);
        
    }
    glEnd();
   



//4
glBegin(GL_QUADS); 
glColor3f(77.0f / 255.0f, 87.0f / 255.0f, 20.0f / 255.0f);
glVertex2f(-1.0f, -0.1f);
glColor3f(153.0f / 255.0f, 117.0f / 255.0f, 25.0f / 255.0f);
glVertex2f(-1.0f, -1.0f);

glVertex2f(1.0f, -1.0f);
glColor3f(165.0f / 255.0f, 94.0f / 255.0f, 7.0f / 255.0f);
glVertex2f(1.0f, 0.2f);
glColor3f(153.0f / 255.0f, 117.0f / 255.0f, 25.0f / 255.0f);


glEnd();

//2
glBegin(GL_QUADS); 
glColor3f(77.0f / 255.0f, 87.0f / 255.0f, 20.0f / 255.0f);
glVertex2f(-1.0f, -0.2f);
glColor3f(153.0f / 255.0f, 117.0f / 255.0f, 25.0f / 255.0f);
glVertex2f(-1.0f, -1.0f);

glVertex2f(1.0f, -1.0f);
glColor3f(165.0f / 255.0f, 94.0f / 255.0f, 7.0f / 255.0f);
glVertex2f(1.0f, -0.1f);
glColor3f(153.0f / 255.0f, 117.0f / 255.0f, 25.0f / 255.0f);


glEnd();

// door + way
glBegin(GL_QUADS); 
glColor3f(250.0f / 255.0f, 219.0f / 255.0f, 126.0f / 255.0f);
glVertex2f(0.57f, -0.225f);
glVertex2f(0.61f, -0.24f);

glVertex2f(-0.1f, -0.58f);
glVertex2f(-0.1f, -0.51f);
glEnd();
// 1
glBegin(GL_QUADS); 
glColor3f(77.0f / 255.0f, 87.0f / 255.0f, 20.0f / 255.0f);

glVertex2f(-1.0f, -0.6f);
glColor3f(202.0f / 255.0f, 170.0f / 255.0f, 40.0f / 255.0f);

glVertex2f(-1.0f, -1.0f);
glColor3f(77.0f / 255.0f, 87.0f / 255.0f, 20.0f / 255.0f);

glVertex2f(1.0f, -1.0f);
glColor3f(165.0f / 255.0f, 94.0f / 255.0f, 7.0f / 255.0f);
glVertex2f(1.0f, -0.4f);
glColor3f(89.0f / 255.0f, 91.0f / 255.0f, 30.0f / 255.0f);



glEnd();

//HOME 1
//Main
glBegin(GL_QUADS); 
glColor3f(83.0f / 255.0f, 46.0f / 255.0f, 19.0f / 255.0f);

glVertex2f(-0.42f, -0.87f);

glVertex2f(-0.1f, -0.8955555f);
glColor3f(26.0f / 255.0f, 68.0f / 255.0f, 54.0f / 255.0f);

glVertex2f(-0.09f, -1.0f);

glVertex2f(-0.44, -1.0f);


glEnd();

glBegin(GL_QUADS); 
glColor3f(118.0f / 255.0f, 100.0f / 255.0f, 76.0f / 255.0f);

glVertex2f(-0.4f, -0.9f);

glVertex2f(-0.1f, -0.8955555f);
glColor3f(116.0f / 255.0f, 122.0f / 255.0f, 128.0f / 255.0f);

glVertex2f(-0.1f, -0.5955555f);
glColor3f(75.0f / 255.0f, 101.0f / 255.0f, 109.0f / 255.0f);

glVertex2f(-0.4f, -0.6f);
glColor3f(163.0f / 255.0f, 183.0f / 255.0f, 189.0f / 255.0f);



//Left side
glBegin(GL_QUADS); 
glColor3f(235.0f / 255.0f, 238.0f / 255.0f, 211.0f / 255.0f);

glVertex2f(-0.4f, -0.9f);

glVertex2f(-0.42f, -0.87f);
glColor3f(116.0f / 255.0f, 122.0f / 255.0f, 128.0f / 255.0f);

glVertex2f(-0.42f, -0.57f);
glColor3f(75.0f / 255.0f, 101.0f / 255.0f, 109.0f / 255.0f);

glVertex2f(-0.4f, -0.6f);
glColor3f(133.0f / 255.0f, 183.0f / 255.0f, 189.0f / 255.0f);
glEnd();
//Up triangle
glBegin(GL_TRIANGLES); 
glColor3f(47.0f / 255.0f, 32.0f / 255.0f, 19.0f / 255.0f);
glVertex2f(-0.4f, -0.6f);
glColor3f(138.0f / 255.0f, 73.0f / 255.0f, 2.0f / 255.0f);
glVertex2f(-0.25f, -0.49f);
glColor3f(135.0f / 255.0f, 60.0f / 255.0f, 1.0f / 255.0f);
glVertex2f(-0.1f, -0.5955555f);
glEnd();
// Triangle left side

glBegin(GL_QUADS); 
glColor3f(131.0f / 255.0f, 140.0f / 255.0f, 157.0f / 255.0f);
glVertex2f(-0.4005f, -0.62f);
glVertex2f(-0.43f, -0.58f);
glColor3f(116.0f / 255.0f, 122.0f / 255.0f, 128.0f / 255.0f);
glVertex2f(-0.28f, -0.45f);
glColor3f(75.0f / 255.0f, 101.0f / 255.0f, 109.0f / 255.0f);
glVertex2f(-0.25f, -0.49f);
glColor3f(133.0f / 255.0f, 183.0f / 255.0f, 189.0f / 255.0f);
glEnd();

// right side
glBegin(GL_QUADS); 
glLineWidth(2.0f);
glColor3f(192.0f / 255.0f, 159.0f / 255.0f, 126.0f / 255.0f);
glVertex2f(-0.28f, -0.45f);
glColor3f(112.0f / 255.0f, 78.0f / 255.0f, 51.0f / 255.0f);
glVertex2f(-0.25f, -0.49f);
glColor3f(235.0f / 255.0f, 238.0f / 255.0f, 211.0f / 255.0f);

glVertex2f(-0.1f, -0.5955555f);
glVertex2f(-0.08f, -0.6f);
glColor3f(131.0f / 255.0f, 140.0f / 255.0f, 157.0f / 255.0f);
glEnd();

// up window
glBegin(GL_QUADS); 
glLineWidth(2.0f);
glColor3f(25.0f / 255.0f, 41.0f / 255.0f, 41.0f / 255.0f);
glVertex2f(-0.26f, -0.57f);
glVertex2f(-0.26f, -0.52f);
glVertex2f(-0.24f, -0.52f);
glVertex2f(-0.24f, -0.57f);
glEnd();
// wingow line
glLineWidth(2.0f);
glBegin(GL_LINES); 
glColor3f(176.0f / 255.0f, 192.0f / 255.0f, 191.0f / 255.0f);

glVertex2f(-0.265f, -0.57f);
glVertex2f(-0.265f, -0.52f);

glVertex2f(-0.265f, -0.52f);
glVertex2f(-0.235f, -0.52f);

glVertex2f(-0.235f, -0.57f);
glVertex2f(-0.265f, -0.57f);

glVertex2f(-0.235f, -0.52f);
glVertex2f(-0.235f, -0.57f);

glVertex2f(-0.25f, -0.52f);
glVertex2f(-0.25f, -0.57f);

glVertex2f(-0.235f, -0.545f);
glVertex2f(-0.265f, -0.545f);

glEnd();

drawLoopLine(-0.4f,-0.9f,-0.1f,-0.6f);
// main window 1

glBegin(GL_QUADS); 
glColor3f(25.0f / 255.0f, 41.0f / 255.0f, 41.0f / 255.0f);
glVertex2f(-0.32f, -0.65f);
glVertex2f(-0.36f, -0.65f);
glVertex2f(-0.36f, -0.74f);
glVertex2f(-0.32f, -0.74f);
glEnd();

glBegin(GL_QUADS); 
glColor3f(25.0f / 255.0f, 41.0f / 255.0f, 41.0f / 255.0f);
glVertex2f(-0.14f, -0.65f);
glVertex2f(-0.18f, -0.65f);
glVertex2f(-0.18f, -0.74f);
glVertex2f(-0.14f, -0.74f);
glEnd();

glBegin(GL_LINES);
glColor3f(176.0f / 255.0f, 192.0f / 255.0f, 191.0f / 255.0f);

glVertex2f(-0.36f, -0.65f);
glVertex2f(-0.36f, -0.74f);

glVertex2f(-0.36f, -0.74f);
glVertex2f(-0.32f, -0.74f);

glVertex2f(-0.32f, -0.74f);
glVertex2f(-0.32f, -0.65f);

glVertex2f(-0.36f, -0.65f);
glVertex2f(-0.32f, -0.65f);

glVertex2f(-0.34f, -0.65f);
glVertex2f(-0.34f, -0.74f);

glVertex2f(-0.36f, -0.695f);
glVertex2f(-0.32f, -0.695f);



glVertex2f(-0.18f, -0.65f);
glVertex2f(-0.18f, -0.74f);

glVertex2f(-0.18f, -0.74f);
glVertex2f(-0.14f, -0.74f);

glVertex2f(-0.14f, -0.74f);
glVertex2f(-0.14f, -0.65f);

glVertex2f(-0.18f, -0.65f);
glVertex2f(-0.14f, -0.65f);

glVertex2f(-0.16f, -0.65f);
glVertex2f(-0.16f, -0.74f);

glVertex2f(-0.18f, -0.695f);
glVertex2f(-0.14f, -0.695f);

glVertex2f(0.58f, -0.1f);
glVertex2f(0.54f, -0.1f);

glEnd();

// HOME2 SHADOW
glBegin(GL_QUADS); 
glColor3f(83.0f / 255.0f, 46.0f / 255.0f, 19.0f / 255.0f);

glVertex2f(0.5f, -0.2f);

glVertex2f(1.0f, -0.4f);
glColor3f(26.0f / 255.0f, 68.0f / 255.0f, 54.0f / 255.0f);

glVertex2f(1.0f, -0.2f);

glVertex2f(0.91f, -0.2f);


glEnd();
//HOME MAIN

glBegin(GL_QUADS); 
glColor3f(108.0f / 255.0f, 34.0f / 255.0f, 0.0f / 255.0f);
glVertex2f(0.5f, 0.07f);

glVertex2f(0.7f, 0.0f);

glVertex2f(0.7f, -0.27f);
glColor3f(145.0f / 255.0f, 69.0f / 255.0f, 20.0f / 255.0f);

glVertex2f(0.5f, -0.2f);
glEnd();

glBegin(GL_QUADS); 
glColor3f(34.0f / 255.0f, 30.0f / 255.0f, 31.0f / 255.0f);
glVertex2f(0.7f, -0.27f);

glVertex2f(0.91f, -0.2f);

glVertex2f(0.91f, 0.0f);

glVertex2f(0.7f, 0.0f);
glColor3f(145.0f / 255.0f, 69.0f / 255.0f, 20.0f / 255.0f);

glEnd();
// HOME UP
glBegin(GL_TRIANGLES); 
glColor3f(108.0f / 255.0f, 34.0f / 255.0f, 0.0f / 255.0f);
glVertex2f(0.5f, 0.07f);

glVertex2f(0.7f, 0.0f);
glColor3f(145.0f / 255.0f, 69.0f / 255.0f, 20.0f / 255.0f);
glVertex2f(0.6f, 0.15f);
glEnd();

glBegin(GL_QUADS); 
glColor3f(54.0f / 255.0f, 100.0f / 255.0f, 133.0f / 255.0f);
glVertex2f(0.6f, 0.15f);

glVertex2f(0.7f, -0.05f);

glVertex2f(0.92f, 0.0f);
glColor3f(39.0f / 255.0f, 67.0f / 255.0f, 91.0f / 255.0f);

glVertex2f(0.83f, 0.2f);
glEnd();

glBegin(GL_QUADS); 
glColor3f(54.0f / 255.0f, 100.0f / 255.0f, 133.0f / 255.0f);
glVertex2f(0.48f, 0.07f);

glVertex2f(0.5f, 0.07f);

glVertex2f(0.6f, 0.15f);
glColor3f(39.0f / 255.0f, 67.0f / 255.0f, 91.0f / 255.0f);

glVertex2f(0.61f, 0.13f);
glEnd();

//door
glBegin(GL_QUADS); 
glColor3f(15.0f / 255.0f, 19.0f / 255.0f, 20.0f / 255.0f);
glVertex2f(0.57f, -0.225f);

glVertex2f(0.61f, -0.24f);

glVertex2f(0.61f, -0.14f);
glColor3f(12.0f / 255.0f, 42.0f / 255.0f, 53.0f / 255.0f);

glVertex2f(0.57f, -0.13f);


glEnd();

// Windows home 2

glBegin(GL_QUADS); 
glColor3f(134.0f / 255.0f, 170.0f / 255.0f, 182.0f / 255.0f);
glVertex2f(0.52f, -0.08f);

glVertex2f(0.56f, -0.09f);

glVertex2f(0.56f, -0.031f);
glColor3f(12.0f / 255.0f, 42.0f / 255.0f, 53.0f / 255.0f);

glVertex2f(0.52f, -0.02f);
glEnd();
glBegin(GL_QUADS); 
glColor3f(134.0f / 255.0f, 170.0f / 255.0f, 182.0f / 255.0f);
glVertex2f(0.64f, -0.1f);

glVertex2f(0.68f, -0.11f);

glVertex2f(0.68f, -0.051f);
glColor3f(12.0f / 255.0f, 42.0f / 255.0f, 53.0f / 255.0f);

glVertex2f(0.64f, -0.04f);
glEnd();

// 
glLineWidth(2.0f);
glBegin(GL_LINES); 
glColor3f(209.0f / 255.0f, 186.0f / 255.0f, 154.0f / 255.0f);
glVertex2f(0.52f, -0.08f);
glVertex2f(0.56f, -0.09f);

glVertex2f(0.56f, -0.09f);
glVertex2f(0.56f, -0.031f);

glVertex2f(0.52f, -0.08f);
glVertex2f(0.52f, -0.02f);

glVertex2f(0.52f, -0.02f);
glVertex2f(0.56f, -0.031f);

glVertex2f(0.54f, -0.08f);
glVertex2f(0.54f, -0.02f);

glVertex2f(0.64f, -0.1f);
glVertex2f(0.68f, -0.11f);

glVertex2f(0.68f, -0.051f);
glVertex2f(0.64f, -0.04f);

glVertex2f(0.64f, -0.1f);
glVertex2f(0.64f, -0.04f);

glVertex2f(0.68f, -0.051f);
glVertex2f(0.68f, -0.11f);

glVertex2f(0.66f, -0.1f);
glVertex2f(0.66f, -0.04f);

glEnd();

glBegin(GL_POLYGON);
glColor3f(48.0f / 255.0f, 70.0f / 255.0f, 85.0f / 255.0f);

    float radius100 = 0.05f;
    for (float angle = 0.0f; angle <= 360.0f; angle += 10.0f) {
        float x_pos = 0.8f + radius100 * cos(angle * 3.1415926f / 220.0f);

        float y_pos = -0.25f + radius100 * sin(angle * 3.1415926f / 180.0f);
        glVertex2f(x_pos, y_pos);
        
    }
    glEnd();
    
    glBegin(GL_POLYGON);
glColor3f(28.0f / 255.0f, 47.0f / 255.0f, 54.0f / 255.0f);

    float radius101 = 0.04f;
    for (float angle = 0.0f; angle <= 360.0f; angle += 10.0f) {
        float x_pos = 0.83f + radius101 * cos(angle * 3.1415926f / 220.0f);

        float y_pos = -0.26f + radius101 * sin(angle * 3.1415926f / 180.0f);
        glVertex2f(x_pos, y_pos);
        
    }
    glEnd();
 drawTree(0.0f, 0.0f, 0.3f);
  drawTree(-0.2f, -0.2f, 0.4f);
    drawTree(-0.3f, -0.25f, 0.6f);
      drawTree(-0.4f, -0.4f, 0.2f);
        drawTree(-0.6f, -0.6f, 0.55f);
          drawTree(-0.8f, -0.8f, 0.4f);
                    drawTree(-0.9f, -0.9f, 0.4f);

          drawTree(-0.95f, -0.9f, 0.67f);

          drawTree(0.05f, -0.9f, 0.8f);
                    drawTree(0.09f, -0.9f, 0.2f);

                      drawTree(-0.86f, -0.5f, 0.37f);

            drawTree(-0.9f, -0.5f, 0.7f);
                        drawTree(-0.8f, -0.52f, 0.75f);
            drawTree(0.8f, 0.3f, 0.08f);
 drawTree(0.83f, 0.3f, 0.1f);
  drawTree(0.85f, 0.32f, 0.1f);
   drawTree(0.8f, 0.3f, 0.08f);
    drawTree(0.83f, 0.35f, 0.12f);
 drawTree(0.9f, 0.2f, 0.08f);
  drawTree(0.91f, 0.233f, 0.1f);
   drawTree(0.8f, 0.3f, 0.08f);

 drawTree(0.85f, 0.26f, 0.089f);
  drawTree(0.87f, 0.28f, 0.1f);
   drawTree(0.82f, 0.26f, 0.08f);


 glBegin(GL_TRIANGLES);
  glColor3f(0.0, 0.0, 0.0);
  glVertex2f(-0.3f+bulud , 0.77f);
glVertex2f(-0.36f+bulud , 0.77f);
glVertex2f(-0.4f+bulud, 0.82f);
glColor3f(1.0, 1.0, 1.0);
  glVertex2f(-0.31f+bulud , 0.78f);
glVertex2f(-0.35f+bulud , 0.78f);
glVertex2f(-0.39f+bulud, 0.81f);

glBegin(GL_TRIANGLES);
  glColor3f(0.0, 0.0, 0.0);
  glVertex2f(-0.3f+bulud, 0.74f);
glVertex2f(-0.36f +bulud, 0.74f);
glVertex2f(-0.4f+bulud, 0.69f);
 glColor3f(1.0, 1.0, 1.0);
  glVertex2f(-0.31f+bulud , 0.73f);
glVertex2f(-0.35f +bulud, 0.73f);
glVertex2f(-0.39f+bulud, 0.7f);


glColor3f(0.0, 0.0, 0.0);
  glVertex2f(-0.3f+bulud , 0.77f);
glVertex2f(-0.3f+bulud , 0.74f);
glVertex2f(-0.25f+bulud, 0.755f);
  glEnd();

  glBegin(GL_QUADS);
  glColor3f(0.0, 0.0, 0.0);
  glVertex2f(-0.36f+bulud , 0.74f);
glVertex2f(-0.36f+bulud , 0.77f);
glVertex2f(-0.3f+bulud, 0.77f);
glVertex2f(-0.3f+bulud , 0.74f);

glColor3f(1.0, 1.0, 1.0);
  glVertex2f(-0.35f+bulud , 0.745f);
glVertex2f(-0.35f +bulud, 0.765f);
glVertex2f(-0.31f+bulud, 0.765f);
glVertex2f(-0.31f+bulud , 0.745f);

  glEnd();
  glColor3f(1.0, 1.0, 1.0);
  drawCircle(-0.3+bulud, 0.755, 0.009, 100);
  
  glBegin(GL_LINES);
  glColor3f(0.0, 0.0, 0.0);
 glVertex2f(-0.555f+bulud, 0.85f);
glVertex2f(-0.36f+bulud , 0.74f);
glColor3f(0.0, 0.0, 0.0);
glVertex2f(-0.36f+bulud, 0.77f);
 glVertex2f(-0.555f +bulud, 0.7f);
  glEnd();
  
  glBegin(GL_QUADS);//flying bayraq

glColor3ub(0, 56, 168);
 glVertex2f(-0.555f +bulud, 0.7f);
glVertex2f(-0.555f +bulud, 0.75f);
glVertex2f(-0.91f+bulud , 0.75f);
glVertex2f(-0.91f+bulud, 0.7f);

glColor3ub(234, 29, 44);
glVertex2f(-0.555f+bulud , 0.75f);
glVertex2f(-0.555f +bulud, 0.8f);
glVertex2f(-0.91f +bulud, 0.8f);
glVertex2f(-0.91f+bulud, 0.75f);

glColor3ub(0, 128, 0);
glVertex2f(-0.555f +bulud, 0.8f);
glVertex2f(-0.555f+bulud , 0.85f);
glVertex2f(-0.91f +bulud, 0.85f);
glVertex2f(-0.91f+bulud, 0.8f);
glEnd();

 glColor3f(1.0, 1.0, 1.0); //yarim ay
    drawCircle(-0.73+bulud, 0.775, 0.015, 100);
 
glColor3ub(234, 29, 44); 
  drawCircle(-0.735+bulud, 0.775, 0.011, 100);
 glBegin(GL_QUADS); //ulduz   
     glColor3f(1.0, 1.0, 1.0); 
      glVertex2f(-0.751f+bulud, 0.775f);//1
      glVertex2f(-0.7545f+bulud, 0.756f);
      glVertex2f(-0.759f+bulud, 0.775f);//2
      glVertex2f(-0.7545f+bulud, 0.794f);

      glColor3f(1.0, 1.0, 1.0); 
      glVertex2f(-0.741f+bulud, 0.775f);
      glVertex2f(-0.7555f+bulud, 0.77f);//3
      glVertex2f(-0.769f+bulud, 0.775f);
      glVertex2f(-0.7555f+bulud, 0.78f);//4
  glEnd();
  glBegin(GL_TRIANGLES);//ulduz
   glColor3f(1.0, 1.0, 1.0); 
      glVertex2f(-0.751f+bulud, 0.775f);
      glVertex2f(-0.7545f+bulud, 0.77f);
      glVertex2f(-0.746f+bulud, 0.756f);
      
       glColor3f(1.0, 1.0, 1.0); 
       glVertex2f(-0.759f+bulud, 0.775f);//2
       glVertex2f(-0.7545f+bulud, 0.77f);//3
       glVertex2f(-0.764f+bulud, 0.756f);
       
       glColor3f(1.0, 1.0, 1.0); 
       glVertex2f(-0.751f+bulud, 0.775f);//1
        glVertex2f(-0.7545f+bulud, 0.78f);//4
         glVertex2f(-0.746f+bulud, 0.792f);
         
         glColor3f(1.0, 1.0, 1.0); 
         glVertex2f(-0.759f+bulud, 0.775f);//2
       glVertex2f(-0.7545f+bulud, 0.78f);//4
       glVertex2f(-0.764f+bulud, 0.792f);
  glEnd();
	}
   
   ///////////////////////STATE 4 AND 6 ------> ELDAR
    if(state==4){

// River side
glColor3f(0.0f, 0.6f, 0.8f);
glBegin(GL_POLYGON);
glVertex2f(-1.0f, 0.0f); 
glVertex2f(1.0f, 0.0f);
glVertex2f(1.0f, -1.0f); 
glVertex2f(-1.0f, -1.0f); 
glEnd();


// mountain left 1
glColor3f(0.5, 0.3, 0.1);
glBegin(GL_TRIANGLES);
glVertex2f(-1.0f, 0.8f); 
glVertex2f(1.0f, 0.1f);
glVertex2f(-1.0f, -0.2f); 
glEnd();
// mountain right 1
glColor3f(0.5, 0.2, 0.1);
glBegin(GL_TRIANGLES);
glVertex2f(1.0f, 0.7f); 
glVertex2f(-0.3f, -0.3f);
glVertex2f(1.0f, -0.2f); 
glEnd();

// mountain left 2
glColor3f(0.6, 0.3, 0.1);
glBegin(GL_TRIANGLES);
glVertex2f(-1.0f, 0.6f); 
glVertex2f(0.7f, -0.3f);
glVertex2f(-1.0f, -0.6f); 
glEnd();

// mountain right 2
glColor3f(0.5, 0.3, 0.2);
glBegin(GL_TRIANGLES);
glVertex2f(1.0f, -0.2f); 
glVertex2f(0.5f, -0.6f);
glVertex2f(1.0f, -0.7f); 
glEnd();
// the bridge
// first part
glColor3f(0.96f, 0.87f, 0.70f);
glBegin(GL_POLYGON);


glVertex2f(-1.0f, -0.5f); //1
glVertex2f(-1.0f, 0.2f); //2
glVertex2f(-0.35f, 0.2f);
glVertex2f(-0.35f, 0.0f); //22
glVertex2f(-0.5f, -0.2f); //23
glVertex2f(-0.5f, -0.5f); //24

glEnd();

// second part
glColor3f(0.96f, 0.87f, 0.70f);
glBegin(GL_POLYGON);

glVertex2f(-0.35f, 0.2f);
glVertex2f(0.0f, 0.2f);
glVertex2f(0.0f, 0.0f); //17
glVertex2f(-0.15f, -0.2f); //18
glVertex2f(-0.2f, -0.2f); //21
glVertex2f(-0.35f, 0.0f); //22

glEnd();

// third part
glColor3f(0.96f, 0.87f, 0.70f);
glBegin(GL_POLYGON);

glVertex2f(0.0f, 0.2f);
glVertex2f(0.35f, 0.2f);
glVertex2f(0.35f, 0.0f); //12
glVertex2f(0.2f, -0.2f); //13
glVertex2f(0.15f, -0.2f); //16
glVertex2f(0.0f, 0.0f); //17

glEnd();

// fourth part
glColor3f(0.96f, 0.87f, 0.70f);
glBegin(GL_POLYGON);

glVertex2f(0.35f, 0.2f);
glVertex2f(0.7f, 0.2f);
glVertex2f(0.7f, 0.0f); //7
glVertex2f(0.55f, -0.2f); //8
glVertex2f(0.5f, -0.2f); //11
glVertex2f(0.35f, 0.0f); //12

glEnd();

// fifth part
glColor3f(0.96f, 0.87f, 0.70f);
glBegin(GL_POLYGON);


glVertex2f(0.7f, 0.2f);
glVertex2f(1.0f, 0.2f); //3
glVertex2f(1.0f, -0.2f); 
glVertex2f(0.85f, -0.2f); //6
glVertex2f(0.7f, 0.0f); //7

glEnd();

// barrier 1
glColor3f(0.96f, 0.87f, 0.70f);
glBegin(GL_POLYGON);


glVertex2f(-0.15f, -0.2f); //18
glVertex2f(-0.15f, -0.5f); //19
glVertex2f(-0.2f, -0.5f); //20
glVertex2f(-0.2f, -0.2f); //21

glEnd();

// barrier 2
glColor3f(0.96f, 0.87f, 0.70f);
glBegin(GL_POLYGON);


glVertex2f(0.2f, -0.2f); //13
glVertex2f(0.2f, -0.5f); //14
glVertex2f(0.15f, -0.5f); //15
glVertex2f(0.15f, -0.2f); //16

glEnd();

// barrier 3
glColor3f(0.96f, 0.87f, 0.70f);
glBegin(GL_POLYGON);


glVertex2f(0.55f, -0.2f); //8
glVertex2f(0.55f, -0.5f); //9
glVertex2f(0.5f, -0.5f); //10
glVertex2f(0.5f, -0.2f); //11
glEnd();

// barrier 4
glColor3f(0.96f, 0.87f, 0.70f);
glBegin(GL_POLYGON);

glVertex2f(1.0f, -0.2f); 
glVertex2f(1.0f, -0.5f); //4
glVertex2f(0.85f, -0.5f); //5
glVertex2f(0.85f, -0.2f); //6


glEnd();



// railway
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_LINES);

glVertex2f(-1.0f, 0.15f); //2
glVertex2f(1.0f, 0.15f); //1

glVertex2f(-1.0f, 0.2f); //2
glVertex2f(1.0f, 0.2f);  //2

glEnd();

// train
glColor3f(0.529f, 0.808f, 0.922f);
glBegin(GL_POLYGON);

glVertex2f(0.6f+h, 0.15f);
glVertex2f(0.6f+h, 0.2f);
glVertex2f(0.7f+h, 0.25f);
glVertex2f(1.0f+h, 0.25f);
glVertex2f(1.0f+h, 0.15f);

glEnd();

// train windows
// lokomotiv
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLES);

glVertex2f(0.63f+h, 0.19f);
glVertex2f(0.7f+h, 0.22f);
glVertex2f(0.7f+h, 0.19f);

glEnd();


//1
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_POLYGON);

glVertex2f(0.73f+h, 0.22f);
glVertex2f(0.77f+h, 0.22f);
glVertex2f(0.77f+h, 0.19f);
glVertex2f(0.73f+h, 0.19f);

glEnd();

//2
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_POLYGON);

glVertex2f(0.8f+h, 0.22f);
glVertex2f(0.84f+h, 0.22f);
glVertex2f(0.84f+h, 0.19f);
glVertex2f(0.8f+h, 0.19f);

glEnd();

//3
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_POLYGON);

glVertex2f(0.87f+h, 0.22f);
glVertex2f(0.91f+h, 0.22f);
glVertex2f(0.91f+h, 0.19f);
glVertex2f(0.87f+h, 0.19f);

glEnd();

//4
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_POLYGON);

glVertex2f(0.94f+h, 0.22f);
glVertex2f(0.98f+h, 0.22f);
glVertex2f(0.98f+h, 0.19f);
glVertex2f(0.94f+h, 0.19f);

glEnd();


/* the bridge
glColor3f(0.1, 0.3, 0.2);
glBegin(GL_LINE_STRIP);

glVertex2f(-0.8f, -0.5f); //1
glVertex2f(-0.8f, 0.2f); //2
glVertex2f(0.95f, 0.2f); //3
glVertex2f(0.95f, -0.5f); //4
glVertex2f(0.85f, -0.5f); //5
glVertex2f(0.85f, -0.2f); //6
glVertex2f(0.7f, 0.0f); //7
glVertex2f(0.55f, -0.2f); //8
glVertex2f(0.55f, -0.5f); //9
glVertex2f(0.5f, -0.5f); //10
glVertex2f(0.5f, -0.2f); //11
glVertex2f(0.35f, 0.0f); //12
glVertex2f(0.2f, -0.2f); //13
glVertex2f(0.2f, -0.5f); //14
glVertex2f(0.15f, -0.5f); //15
glVertex2f(0.15f, -0.2f); //16
glVertex2f(0.0f, 0.0f); //17
glVertex2f(-0.15f, -0.2f); //18
glVertex2f(-0.15f, -0.5f); //19
glVertex2f(-0.2f, -0.5f); //20
glVertex2f(-0.2f, -0.2f); //21
glVertex2f(-0.35f, 0.0f); //22
glVertex2f(-0.5f, -0.2f); //23
glVertex2f(-0.5f, -0.5f); //24
glVertex2f(-0.8f, -0.5f); //1
glEnd();
glFlush();
*/


// mountain left 3
glColor3f(0.5, 0.3, 0.2);
glBegin(GL_TRIANGLES);
glVertex2f(-1.0f, -0.1f); 
glVertex2f(-0.3f, -0.7f);
glVertex2f(-1.0f, -0.9f); 
glEnd();
// mountain right 3
glColor3f(0.5, 0.3, 0.1);
glBegin(GL_TRIANGLES);
glVertex2f(1.0f, -0.4f); 
glVertex2f(0.3f, -1.0f); 
glVertex2f(1.0f, -1.0f);

glEnd();


glBegin(GL_TRIANGLES);
  glColor3f(0.0, 0.0, 0.0);
  glVertex2f(-0.3f+bulud , 0.77f);
glVertex2f(-0.36f+bulud , 0.77f);
glVertex2f(-0.4f+bulud, 0.82f);
glColor3f(1.0, 1.0, 1.0);
  glVertex2f(-0.31f+bulud , 0.78f);
glVertex2f(-0.35f+bulud , 0.78f);
glVertex2f(-0.39f+bulud, 0.81f);

glBegin(GL_TRIANGLES);
  glColor3f(0.0, 0.0, 0.0);
  glVertex2f(-0.3f+bulud, 0.74f);
glVertex2f(-0.36f +bulud, 0.74f);
glVertex2f(-0.4f+bulud, 0.69f);
 glColor3f(1.0, 1.0, 1.0);
  glVertex2f(-0.31f+bulud , 0.73f);
glVertex2f(-0.35f +bulud, 0.73f);
glVertex2f(-0.39f+bulud, 0.7f);


glColor3f(0.0, 0.0, 0.0);
  glVertex2f(-0.3f+bulud , 0.77f);
glVertex2f(-0.3f+bulud , 0.74f);
glVertex2f(-0.25f+bulud, 0.755f);
  glEnd();

  glBegin(GL_QUADS);
  glColor3f(0.0, 0.0, 0.0);
  glVertex2f(-0.36f+bulud , 0.74f);
glVertex2f(-0.36f+bulud , 0.77f);
glVertex2f(-0.3f+bulud, 0.77f);
glVertex2f(-0.3f+bulud , 0.74f);

glColor3f(1.0, 1.0, 1.0);
  glVertex2f(-0.35f+bulud , 0.745f);
glVertex2f(-0.35f +bulud, 0.765f);
glVertex2f(-0.31f+bulud, 0.765f);
glVertex2f(-0.31f+bulud , 0.745f);

  glEnd();
  glColor3f(1.0, 1.0, 1.0);
  drawCircle(-0.3+bulud, 0.755, 0.009, 100);
  
  glBegin(GL_LINES);
  glColor3f(0.0, 0.0, 0.0);
 glVertex2f(-0.555f+bulud, 0.85f);
glVertex2f(-0.36f+bulud , 0.74f);
glColor3f(0.0, 0.0, 0.0);
glVertex2f(-0.36f+bulud, 0.77f);
 glVertex2f(-0.555f +bulud, 0.7f);
  glEnd();
  
  glBegin(GL_QUADS);//flying bayraq

glColor3ub(0, 56, 168);
 glVertex2f(-0.555f +bulud, 0.7f);
glVertex2f(-0.555f +bulud, 0.75f);
glVertex2f(-0.91f+bulud , 0.75f);
glVertex2f(-0.91f+bulud, 0.7f);

glColor3ub(234, 29, 44);
glVertex2f(-0.555f+bulud , 0.75f);
glVertex2f(-0.555f +bulud, 0.8f);
glVertex2f(-0.91f +bulud, 0.8f);
glVertex2f(-0.91f+bulud, 0.75f);

glColor3ub(0, 128, 0);
glVertex2f(-0.555f +bulud, 0.8f);
glVertex2f(-0.555f+bulud , 0.85f);
glVertex2f(-0.91f +bulud, 0.85f);
glVertex2f(-0.91f+bulud, 0.8f);
glEnd();

 glColor3f(1.0, 1.0, 1.0); //yarim ay
    drawCircle(-0.73+bulud, 0.775, 0.015, 100);
 
glColor3ub(234, 29, 44); 
  drawCircle(-0.735+bulud, 0.775, 0.011, 100);
 glBegin(GL_QUADS); //ulduz   
     glColor3f(1.0, 1.0, 1.0); 
      glVertex2f(-0.751f+bulud, 0.775f);//1
      glVertex2f(-0.7545f+bulud, 0.756f);
      glVertex2f(-0.759f+bulud, 0.775f);//2
      glVertex2f(-0.7545f+bulud, 0.794f);

      glColor3f(1.0, 1.0, 1.0); 
      glVertex2f(-0.741f+bulud, 0.775f);
      glVertex2f(-0.7555f+bulud, 0.77f);//3
      glVertex2f(-0.769f+bulud, 0.775f);
      glVertex2f(-0.7555f+bulud, 0.78f);//4
  glEnd();
  glBegin(GL_TRIANGLES);//ulduz
   glColor3f(1.0, 1.0, 1.0); 
      glVertex2f(-0.751f+bulud, 0.775f);
      glVertex2f(-0.7545f+bulud, 0.77f);
      glVertex2f(-0.746f+bulud, 0.756f);
      
       glColor3f(1.0, 1.0, 1.0); 
       glVertex2f(-0.759f+bulud, 0.775f);//2
       glVertex2f(-0.7545f+bulud, 0.77f);//3
       glVertex2f(-0.764f+bulud, 0.756f);
       
       glColor3f(1.0, 1.0, 1.0); 
       glVertex2f(-0.751f+bulud, 0.775f);//1
        glVertex2f(-0.7545f+bulud, 0.78f);//4
         glVertex2f(-0.746f+bulud, 0.792f);
         
         glColor3f(1.0, 1.0, 1.0); 
         glVertex2f(-0.759f+bulud, 0.775f);//2
       glVertex2f(-0.7545f+bulud, 0.78f);//4
       glVertex2f(-0.764f+bulud, 0.792f);
  glEnd();
//

	}
  if(state==6){
// left upper wing
glBegin(GL_POLYGON); 
glColor3f(1.0f, 0.0f, 1.0f);

glVertex2f(-0.7f, 0.9f); 
glVertex2f(-0.1f, 0.3f); // also the first coordinate of the body
glVertex2f(-0.2f, 0.0f);
glVertex2f(-0.4f, 0.17f); // also the first coordinate of left lower wing
glVertex2f(-0.7f, 0.4f);
glVertex2f(-0.8f, 0.7f);
glVertex2f(-0.8f, 0.8f);
glEnd();
// Left lower wing
glBegin(GL_POLYGON); 
glColor3f(1.0f, 0.0f, 1.0f);

glVertex2f(-0.4f, 0.17f);
glVertex2f(-0.6f, -0.1f);
glVertex2f(-0.8f, -0.4f);
glVertex2f(-0.9f, -0.7f);
glVertex2f(-0.95f, -0.9f);
glVertex2f(-0.6f, -0.85f);
glVertex2f(-0.4f, -0.7f);
glVertex2f(-0.3f, -0.55f); // first of the middle
glVertex2f(-0.45f, -0.3f);
glVertex2f(-0.4f, -0.15f);
glVertex2f(-0.2f, 0.0f);
glEnd();


// Body
glBegin(GL_POLYGON); 
glColor3f(0.5f, 1.0f, 0.5f);

glVertex2f(-0.1f, 0.3f); // also the second coordinate of the left upper wing
glVertex2f(0.05f, 0.5f);
glVertex2f(0.2f, 0.55f);
glVertex2f(0.3f, 0.43f);
glVertex2f(0.4f, 0.4f);
glVertex2f(0.35f, 0.37f);
glVertex2f(0.15f, 0.33f);
glVertex2f(0.3f, 0.2f);
glVertex2f(0.25f, 0.0f);
glVertex2f(0.1f, 0.1f);
glVertex2f(-0.2f, 0.0f);
glEnd();


// Middle wing
glBegin(GL_POLYGON); 
glColor3f(0.8f, 0.0f, 0.8f);

glVertex2f(-0.3f, -0.55f);
glVertex2f(-0.2f, -0.6f);
glVertex2f(-0.08f, -0.55f);
glVertex2f(-0.0f, -0.45f);
glVertex2f(0.05f, -0.25f);
glVertex2f(0.25f, 0.0f);
glVertex2f(0.1f, 0.1f);
glVertex2f(-0.2f, 0.0f);
glVertex2f(-0.4f, -0.15f);
glVertex2f(-0.4f, -0.15f);
glVertex2f(-0.4f, -0.7f);
glEnd();

// right upper wing
glBegin(GL_POLYGON); 
glColor3f(0.7f, 0.0f, 0.7f);

glVertex2f(0.3f, -0.1f);
glVertex2f(0.9f, 0.2f);
glVertex2f(0.5f, -0.4f);
glVertex2f(0.3f, -0.15f);
glEnd();



// lower wing
glBegin(GL_POLYGON); 
glColor3f(1.0f, 0.0f, 1.0f);

glVertex2f(0.05f, -0.3f);
glVertex2f(0.0f, -0.45f);
glVertex2f(0.05f, -0.75f);
glVertex2f(0.35f, -0.4f);
glVertex2f(0.15f, -0.25f);
glEnd();



// right lower wing
glBegin(GL_POLYGON); 
glColor3f(0.75f, 0.0f, 0.75f);

glVertex2f(0.25f, 0.0f);
glVertex2f(-0.0f, -0.45f);
glVertex2f(0.05f, -0.25f);
glVertex2f(0.3f, -0.9f);
glVertex2f(0.7f, -0.95f);
glVertex2f(0.78f, -0.80f);
glVertex2f(0.7f, -0.70f);
glVertex2f(0.7f, -0.45f);
glVertex2f(0.6f, -0.35f);
glVertex2f(0.3f, -0.1f);
glEnd();




  }
  
  
  ////////////////////////STATE 5---------> ELNUR
  if(state==5){
   // BULUD
        
    drawOval(0.0, 0.75, 0.2, 0.1, 10000, 1.0, 1.0, 1.0);
    drawOval(-0.2, 0.75, 0.2, 0.1, 10000, 1.0, 1.0, 1.0);
    drawSUNCircle(-0.1, 0.80, 0.15, 10000, 1.0, 1.0, 1.0); 
// SOL  MINARE birinci kvadrati
glBegin(GL_QUADS);
glColor3f(0.5f, 0.5f, 0.5f);
glVertex2f(-0.543f,-0.078f);
glVertex2f(-0.469f,-0.059f);
glVertex2f(-0.469f,0.15f);
glVertex2f(-0.543f,0.15f);

glEnd();
// sol minare naxislar
glLineWidth(2.0f);
glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(-0.469f,0.15f);
glVertex2f(-0.543f,0.12f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(-0.469f,0.12f);
glVertex2f(-0.543f,0.09f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(-0.469f,0.09f);
glVertex2f(-0.543f,0.06f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(-0.469f,0.06f);
glVertex2f(-0.543f,0.03f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(-0.469f,0.03f);
glVertex2f(-0.543f,0.0f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(-0.469f,0.0f);
glVertex2f(-0.543f,-0.03f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(-0.469f,-0.03f);
glVertex2f(-0.543f,-0.06f);

glEnd();


glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(-0.543f,0.15f);
glVertex2f(-0.469f,0.12f);

glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(-0.543f,0.12f);
glVertex2f(-0.469f,0.09f);

glEnd();


glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(-0.543f,0.09f);
glVertex2f(-0.469f,0.06f);

glEnd();


glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(-0.543f,0.06f);
glVertex2f(-0.469f,0.03f);

glEnd();



glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(-0.543f,0.03f);
glVertex2f(-0.469f,0.0f);

glEnd();



glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(-0.543f,0.0f);
glVertex2f(-0.469f,-0.03f);

glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(-0.543f,-0.03f);
glVertex2f(-0.469f,-0.06f);

glEnd();

// sol minarenin ikinci kvadrati 

glBegin(GL_QUADS);
glColor3f(0.5f, 0.5f, 0.5f);

glVertex2f(-0.469f,0.15f);
glVertex2f(-0.469f,0.4f);
glVertex2f(-0.543f,0.4f);
glVertex2f(-0.543f,0.15f);
glEnd();
// sol minerinin ikinci ellipsisi
drawEllipse( 0.0378f,  0.0378f,  -0.507f,  0.15f);
// sol minarenin ikinici kvadratinin naxislari 


glLineWidth(2.0f);
glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(-0.543f,0.4f);
glVertex2f(-0.469f,0.38f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(-0.543f,0.38f);
glVertex2f(-0.469f,0.36f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(-0.543f,0.36f);
glVertex2f(-0.469f,0.34f);
glEnd();


glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(-0.543f,0.34f);
glVertex2f(-0.469f,0.32f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(-0.543f,0.32f);
glVertex2f(-0.469f,0.3f);
glEnd();


glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(-0.543f,0.3f);
glVertex2f(-0.469f,0.28f);
glEnd();



glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(-0.543f,0.28f);
glVertex2f(-0.469f,0.26f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(-0.543f,0.26f);
glVertex2f(-0.469f,0.24f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(-0.543f,0.24f);
glVertex2f(-0.469f,0.22f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(-0.543f,0.22f);
glVertex2f(-0.469f,0.2f);
glEnd();
glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(-0.543f,0.2f);
glVertex2f(-0.469f,0.18f);
glEnd();

drawEllipse( 0.05f,  0.05f,  -0.5f,  -0.1f);

// sol minarenin 3 cu kvadrati 

glBegin(GL_QUADS);
glColor3f(0.5f, 0.5f, 0.5f);

glVertex2f(-0.469f,0.4f);
glVertex2f(-0.469f,0.65f);
glVertex2f(-0.543f,0.65f);
glVertex2f(-0.543f,0.4f);
glEnd();
// sol minarenin  3 cu ellipsisi

drawEllipse( 0.0378f,  0.0378f,  -0.507f,  0.4f);

// sol minarenin 3 cu kvadratin naxislari
glLineWidth(2.0f); 
glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(-0.543f,0.65f);
glVertex2f(-0.469f,0.62f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(-0.543f,0.62f);
glVertex2f(-0.469f,0.59f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(-0.543f,0.59f);
glVertex2f(-0.469f,0.56f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(-0.543f,0.56f);
glVertex2f(-0.469f,0.53f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(-0.543f,0.53f);
glVertex2f(-0.469f,0.5f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(-0.543f,0.5f);
glVertex2f(-0.469f,0.47f);
glEnd();


glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(-0.543f,0.47f);
glVertex2f(-0.469f,0.44f);
glEnd();




glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(-0.469f,0.65f);
glVertex2f(-0.543f,0.62f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(-0.469f,0.62f);
glVertex2f(-0.543f,0.59f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(-0.469f,0.59f);
glVertex2f(-0.543f,0.56f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(-0.469f,0.56f);
glVertex2f(-0.543f,0.53f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(-0.469f,0.53f);
glVertex2f(-0.543f,0.5f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(-0.469f,0.5f);
glVertex2f(-0.543f,0.47f);
glEnd();


glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(-0.469f,0.47f);
glVertex2f(-0.543f,0.44f);
glEnd();

// sol minarenin  4 cu ellipsis

drawEllipse( 0.0378f,  0.0378f,  -0.507f,  0.65f);
glEnd();
 
 // sol minarenin ayi  
 glBegin(GL_LINES);
 glColor3f(0.0f,0.0f,0.0f);
 glVertex2f(-0.507f,0.687f);
 glVertex2f(-0.507f,0.74f);
glEnd();

glColor3f(1.0, 1.0, 1.0); //yarim ay
    drawCircle(-0.507, 0.74, 0.015, 100);
 
glColor3ub(135, 206, 235); 
  drawCircle(-0.502, 0.74, 0.011, 100);
// Sagin ilk kvadrati 

glBegin(GL_QUADS);
glColor3f(0.5f, 0.5f, 0.5f);
glVertex2f(0.543f,-0.078f);
glVertex2f(0.469f,-0.059f);
glVertex2f(0.469f,0.15f);
glVertex2f(0.543f,0.15f);
glEnd();
// sag ilk ellipsisi
drawEllipse( 0.05f,  0.05f,  0.5f,  -0.1f);

// sag minare naxislar
glLineWidth(2.0f);
glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(0.469f,0.15f);
glVertex2f(0.543f,0.12f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(0.469f,0.12f);
glVertex2f(0.543f,0.09f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(0.469f,0.09f);
glVertex2f(0.543f,0.06f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(0.469f,0.06f);
glVertex2f(0.543f,0.03f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(0.469f,0.03f);
glVertex2f(0.543f,0.0f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(0.469f,0.0f);
glVertex2f(0.543f,-0.03f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(0.469f,-0.03f);
glVertex2f(0.543f,-0.06f);

glEnd();


glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(0.543f,0.15f);
glVertex2f(0.469f,0.12f);

glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(0.543f,0.12f);
glVertex2f(0.469f,0.09f);

glEnd();


glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(0.543f,0.09f);
glVertex2f(0.469f,0.06f);

glEnd();


glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(0.543f,0.06f);
glVertex2f(0.469f,0.03f);

glEnd();



glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(0.543f,0.03f);
glVertex2f(0.469f,0.0f);

glEnd();



glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(0.543f,0.0f);
glVertex2f(0.469f,-0.03f);

glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(0.543f,-0.03f);
glVertex2f(0.469f,-0.06f);

glEnd();

// sag minarenin ikinci kvadrati 

glBegin(GL_QUADS);
glColor3f(0.5f, 0.5f, 0.5f);

glVertex2f(0.469f,0.15f);
glVertex2f(0.469f,0.4f);
glVertex2f(0.543f,0.4f);
glVertex2f(0.543f,0.15f);
glEnd();
// sol minarenin ikinci ellipsisi
drawEllipse( 0.0378f,  0.0378f,  0.507f,  0.15f);

// sag minarenin ikinci kvadradtinin naxislari 

glLineWidth(2.0f);
glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(0.543f,0.4f);
glVertex2f(0.469f,0.38f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(0.543f,0.38f);
glVertex2f(0.469f,0.36f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(0.543f,0.36f);
glVertex2f(0.469f,0.34f);
glEnd();


glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(0.543f,0.34f);
glVertex2f(0.469f,0.32f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(0.543f,0.32f);
glVertex2f(0.469f,0.3f);
glEnd();


glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(0.543f,0.3f);
glVertex2f(0.469f,0.28f);
glEnd();



glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(0.543f,0.28f);
glVertex2f(0.469f,0.26f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(0.543f,0.26f);
glVertex2f(0.469f,0.24f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(0.543f,0.24f);
glVertex2f(0.469f,0.22f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(0.543f,0.22f);
glVertex2f(0.469f,0.2f);
glEnd();
glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(0.543f,0.2f);
glVertex2f(0.469f,0.18f);
glEnd();

// sag minarenin 3 cu kvadrati 

glBegin(GL_QUADS);
glColor3f(0.5f, 0.5f, 0.5f);

glVertex2f(0.469f,0.4f);
glVertex2f(0.469f,0.65f);
glVertex2f(0.543f,0.65f);
glVertex2f(0.543f,0.4f);
glEnd();
// sag minarenin  3 cu ellipsisi

drawEllipse( 0.0378f,  0.0378f,  0.507f,  0.4f);

// sag minareinin 3 cu kvadratinin naxislari
glLineWidth(2.0f); 
glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(0.543f,0.65f);
glVertex2f(0.469f,0.62f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(0.543f,0.62f);
glVertex2f(0.469f,0.59f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(0.543f,0.59f);
glVertex2f(0.469f,0.56f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(0.543f,0.56f);
glVertex2f(0.469f,0.53f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(0.543f,0.53f);
glVertex2f(0.469f,0.5f);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(0.543f,0.5f);
glVertex2f(0.469f,0.47f);
glEnd();


glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(0.543f,0.47f);
glVertex2f(0.469f,0.44f);
glEnd();




glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(0.469f,0.65f);
glVertex2f(0.543f,0.62f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(0.469f,0.62f);
glVertex2f(0.543f,0.59f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(0.469f,0.59f);
glVertex2f(0.543f,0.56f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(0.469f,0.56f);
glVertex2f(0.543f,0.53f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(0.469f,0.53f);
glVertex2f(0.543f,0.5f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(0.469f,0.5f);
glVertex2f(0.543f,0.47f);
glEnd();


glBegin(GL_LINES);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(0.469f,0.47f);
glVertex2f(0.543f,0.44f);
glEnd();

// sag minarenin 4 cu ellipsisi;
drawEllipse( 0.0378f,  0.0378f,  0.507f,  0.65f);

// sag minarenin ayi 
 glBegin(GL_LINES);
 glColor3f(0.0f,0.0f,0.0f);
 glVertex2f(0.507f,0.687f);
 glVertex2f(0.507f,0.74f);
glEnd();

glColor3f(1.0, 1.0, 1.0); //yarim ay
    drawCircle(0.507, 0.74, 0.015, 100);
 
glColor3ub(135, 206, 235); 
  drawCircle(0.502, 0.74, 0.011, 100);

//DAM 
glBegin(GL_TRIANGLES);
glColor3f(0.8863f, 0.3098f, 0.3098f);
glVertex2f(0.0f,0.1f);
glVertex2f(-0.6f,-0.1f);
glVertex2f(0.6f,-0.1f);
glEnd();
// Giris qapsinin solu
glBegin(GL_QUADS);
glColor3f(0.8f, 0.8f, 0.8f);
glVertex2f(-0.55f,-0.1f);
glVertex2f(-0.4f,-0.1f);
glVertex2f(-0.4f,-0.6f);
glVertex2f(-0.55f,-0.6f);
glEnd();
// Giris qapsinin solunun dekoru
glLineWidth(0.5f);
glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.55f,-0.15f);
glVertex2f(-0.52f,-0.15f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.55f,-0.2f);
glVertex2f(-0.52f,-0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.55f,-0.25f);
glVertex2f(-0.52f,-0.25f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.55f,-0.3f);
glVertex2f(-0.52f,-0.3f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.55f,-0.35f);
glVertex2f(-0.52f,-0.35f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.55f,-0.4f);
glVertex2f(-0.52f,-0.4f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.55f,-0.45f);
glVertex2f(-0.52f,-0.45f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.55f,-0.5f);
glVertex2f(-0.52f,-0.5f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.55f,-0.55f);
glVertex2f(-0.52f,-0.55f);
glEnd();

// ortadaki duzbucaqlilar

glLineWidth(0.5f);
glBegin(GL_QUADS);
glColor3f(0.9f,0.9f,0.9f); // RENGINI DUZELT 
glVertex2f(-0.51f,-0.14f);
glVertex2f(-0.44f,-0.14f);
glVertex2f(-0.44f,-0.34f);
glVertex2f(-0.51f,-0.34f);
glEnd();

glLineWidth(0.5f);
glBegin(GL_QUADS);
glColor3f(0.9f,0.9f,0.9f); // RENGINI DUZELT 
glVertex2f(-0.51f,-0.38f);
glVertex2f(-0.44f,-0.38f);
glVertex2f(-0.44f,-0.57f);
glVertex2f(-0.51f,-0.57f);
glEnd();

// qiragdaki cixintilar 

glLineWidth(0.5f);
glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.4f,-0.15f);
glVertex2f(-0.43f,-0.15f);
glEnd();


glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.4f,-0.2f);
glVertex2f(-0.43f,-0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.4f,-0.25f);
glVertex2f(-0.43f,-0.25f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.4f,-0.3f);
glVertex2f(-0.43f,-0.3f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.4f,-0.35f);
glVertex2f(-0.43f,-0.35f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.4f,-0.4f);
glVertex2f(-0.43f,-0.4f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.4f,-0.45f);
glVertex2f(-0.43f,-0.45f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.4f,-0.5f);
glVertex2f(-0.43f,-0.5f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.4f,-0.55f);
glVertex2f(-0.43f,-0.55f);
glEnd();

// Giris qapsinin sagi
glBegin(GL_QUADS);
glColor3f(0.8f, 0.8f, 0.8f);
glVertex2f(0.55f,-0.1f);
glVertex2f(0.4f,-0.1f);
glVertex2f(0.4f,-0.6f);
glVertex2f(0.55f,-0.6f);
glEnd();

// Qiraqdaki cixintilar
glLineWidth(0.5f);
glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.55f,-0.15f);
glVertex2f(0.52f,-0.15f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.55f,-0.2f);
glVertex2f(0.52f,-0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.55f,-0.25f);
glVertex2f(0.52f,-0.25f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.55f,-0.3f);
glVertex2f(0.52f,-0.3f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.55f,-0.35f);
glVertex2f(0.52f,-0.35f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.55f,-0.4f);
glVertex2f(0.52f,-0.4f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.55f,-0.45f);
glVertex2f(0.52f,-0.45f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.55f,-0.5f);
glVertex2f(0.52f,-0.5f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.55f,-0.55f);
glVertex2f(0.52f,-0.55f);
glEnd();


glLineWidth(0.5f);
glBegin(GL_QUADS);
glColor3f(0.9f,0.9f,0.9f); // RENGINI DUZELT 
glVertex2f(0.51f,-0.14f);
glVertex2f(0.44f,-0.14f);
glVertex2f(0.44f,-0.34f);
glVertex2f(0.51f,-0.34f);
glEnd();

glLineWidth(0.5f);
glBegin(GL_QUADS);
glColor3f(0.9f,0.9f,0.9f); // RENGINI DUZELT 
glVertex2f(0.51f,-0.38f);
glVertex2f(0.44f,-0.38f);
glVertex2f(0.44f,-0.57f);
glVertex2f(0.51f,-0.57f);
glEnd();

// Giris qapsinin saginin dekoru 

glLineWidth(0.5f);
glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.4f,-0.15f);
glVertex2f(0.43f,-0.15f);
glEnd();


glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.4f,-0.2f);
glVertex2f(0.43f,-0.2f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.4f,-0.25f);
glVertex2f(0.43f,-0.25f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.4f,-0.3f);
glVertex2f(0.43f,-0.3f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.4f,-0.35f);
glVertex2f(0.43f,-0.35f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.4f,-0.4f);
glVertex2f(0.43f,-0.4f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.4f,-0.45f);
glVertex2f(0.43f,-0.45f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.4f,-0.5f);
glVertex2f(0.43f,-0.5f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(0.4f,-0.55f);
glVertex2f(0.43f,-0.55f);
glEnd();


// ESAS HISSE 

glBegin(GL_QUADS);
glColor3f(0.85f,0.85f,0.85f); // RENGINI DUZELT 
glVertex2f(-0.4f,-0.1f);
glVertex2f(0.4f,-0.1f);
glVertex2f(0.4f,-0.6f);
glVertex2f(-0.4f,-0.6f);
glEnd();

// ESAS HISSE 3 EDED CIXINTI;
glBegin(GL_POLYGON);
glColor3f(0.5f,0.5f,0.5f); 
glVertex2f(-0.4f,-0.6f);
glVertex2f(-0.4f,-0.35f);
glVertex2f(-0.27f,-0.2f);
glVertex2f(-0.14f,-0.35f);
glVertex2f(-0.14f,-0.6f);
glEnd();


glBegin(GL_POLYGON);
glColor3f(0.5f,0.5f,0.5f);  
glVertex2f(-0.14f,-0.6f);
glVertex2f(-0.14f,-0.35f);
glVertex2f(-0.01f,-0.2f);
glVertex2f(0.13f,-0.35f);
glVertex2f(0.13f,-0.6f);

glEnd();

glBegin(GL_POLYGON);
glColor3f(0.5f,0.5f,0.5f);
glVertex2f(0.13f,-0.6f);
glVertex2f(0.13f,-0.35f);
glVertex2f(0.259f,-0.2f);
glVertex2f(0.399f,-0.35f);
glVertex2f(0.399f,-0.6f);
glEnd();


// MESCIDIN EN ALT HISSESI
glBegin(GL_QUADS);
glColor3f(0.7f,0.7f,0.7f); 
glVertex2f(-0.56f,-0.6f);
glVertex2f(0.56f,-0.6f);
glVertex2f(0.56f,-0.7f);
glVertex2f(-0.56f,-0.7f);
glEnd();
// Mescidin en alt hissesnin sol hissesi
glBegin(GL_QUADS);
glColor3f(0.6157f, 0.3373f, 0.0f);
glVertex2f(-0.37f,-0.63f);
glVertex2f(-0.33f,-0.63f);
glVertex2f(-0.33f,-0.68f);
glVertex2f(-0.37f,-0.68f);
glEnd();

glBegin(GL_QUADS);
 glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.36f,-0.64f);
glVertex2f(-0.34f,-0.64f);
glVertex2f(-0.34f,-0.67f);
glVertex2f(-0.36f,-0.67f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.6157f, 0.3373f, 0.0f);
glVertex2f(-0.31f,-0.63f);
glVertex2f(-0.26f,-0.63f);
glVertex2f(-0.26f,-0.68f);
glVertex2f(-0.31f,-0.68f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.6157f, 0.3373f, 0.0f);
glVertex2f(-0.23f,-0.63f);
glVertex2f(-0.19f,-0.63f);
glVertex2f(-0.19f,-0.68f);
glVertex2f(-0.23f,-0.68f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.22f,-0.64f);
glVertex2f(-0.20f,-0.64f);
glVertex2f(-0.20f,-0.67f);
glVertex2f(-0.22f,-0.67f);
glEnd();
// STAIRS


glBegin(GL_POLYGON);
glColor3f(0.71f, 0.72f, 0.53f);
glVertex2f(-0.1f,-0.6f);
glVertex2f(0.09f,-0.6f);
glVertex2f(0.19f,-0.70f);
glVertex2f(0.09f,-0.75f);
glVertex2f(-0.1f,-0.75f);
glVertex2f(-0.2f,-0.70f);
glEnd();

glLineWidth(1.5f);
glBegin(GL_LINE_STRIP);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.11f,-0.62f);
glVertex2f(-0.07f,-0.64f);
glVertex2f(0.05f,-0.64f);
glVertex2f(0.1f,-0.62f);
glEnd();

glBegin(GL_LINE_STRIP);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.13f,-0.64f);
glVertex2f(-0.09f,-0.66f);
glVertex2f(0.05f,-0.66f);
glVertex2f(0.12f,-0.64f);
glEnd();


glBegin(GL_LINE_STRIP);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.15f,-0.66f);
glVertex2f(-0.11f,-0.68f);
glVertex2f(0.08f,-0.68f);
glVertex2f(0.15f,-0.66f);
glEnd();

glBegin(GL_LINE_STRIP);
glColor3f(0.0f,0.0f,0.0f);
glVertex2f(-0.17f,-0.68f);
glVertex2f(-0.13f,-0.70f);
glVertex2f(0.11f,-0.70f);
glVertex2f(0.17f,-0.68f);
glEnd();

// MESCIDIN ALTININ SAG HISSESI 
glBegin(GL_QUADS);
glColor3f(0.6157f, 0.3373f, 0.0f);
glVertex2f(0.37f,-0.63f);
glVertex2f(0.33f,-0.63f);
glVertex2f(0.33f,-0.68f);
glVertex2f(0.37f,-0.68f);
glEnd();

glBegin(GL_QUADS);
 glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.36f,-0.64f);
glVertex2f(0.34f,-0.64f);
glVertex2f(0.34f,-0.67f);
glVertex2f(0.36f,-0.67f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.6157f, 0.3373f, 0.0f);
glVertex2f(0.31f,-0.63f);
glVertex2f(0.26f,-0.63f);
glVertex2f(0.26f,-0.68f);
glVertex2f(0.31f,-0.68f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.6157f, 0.3373f, 0.0f);
glVertex2f(0.23f,-0.63f);
glVertex2f(0.19f,-0.63f);
glVertex2f(0.19f,-0.68f);
glVertex2f(0.23f,-0.68f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.22f,-0.64f);
glVertex2f(0.20f,-0.64f);
glVertex2f(0.20f,-0.67f);
glVertex2f(0.22f,-0.67f);
glEnd();

//QAPILAR 
glBegin(GL_QUADS);
glColor3f(0.6157f, 0.3373f, 0.0f);
glVertex2f(-0.31f,-0.57f);
glVertex2f(-0.31f,-0.45f);
glVertex2f(-0.2f,-0.45f);
glVertex2f(-0.2f,-0.57f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.6157f, 0.3373f, 0.0f);
glVertex2f(-0.08f,-0.57f);
glVertex2f(-0.08f,-0.41f);
glVertex2f(0.06f,-0.41f);
glVertex2f(0.06f,-0.57f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.6157f, 0.3373f, 0.0f);
glVertex2f(0.31f,-0.57f);
glVertex2f(0.31f,-0.45f);
glVertex2f(0.2f,-0.45f);
glVertex2f(0.2f,-0.57f);
glEnd();
// qapinin  yeri 
glBegin(GL_QUADS);
glColor3f(0.71f, 0.72f, 0.53f);
glVertex2f(-0.4f,-0.6f);
glVertex2f(-0.4f,-0.57f);
glVertex2f(0.399f,-0.57f);
glVertex2f(0.399f,-0.6f);
glEnd();
// TUTACAQ

glLineWidth(2.0f);
glBegin(GL_LINES);
 glColor3f(0.5490f, 0.4039f, 0.1961f);
glVertex2f(-0.4f,-0.53f);
glVertex2f(-0.14f,-0.53f);
glEnd();

glLineWidth(2.0f);
glBegin(GL_LINES);
 glColor3f(0.5490f, 0.4039f, 0.1961f);
glVertex2f(0.13f,-0.53f);
glVertex2f(0.4f,-0.53f);
glEnd();

glLineWidth(0.2f);
glBegin(GL_LINES);
 glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.37f,-0.53f);
glVertex2f(-0.37f,-0.6f);
glEnd();

glBegin(GL_LINES);
 glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.34f,-0.53f);
glVertex2f(-0.34f,-0.6f);
glEnd();



glBegin(GL_LINES);
 glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.31f,-0.53f);
glVertex2f(-0.31f,-0.6f);
glEnd();


glBegin(GL_LINES);
 glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.28f,-0.53f);
glVertex2f(-0.28f,-0.6f);
glEnd();

glBegin(GL_LINES);
 glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.25f,-0.53f);
glVertex2f(-0.25f,-0.6f);
glEnd();

glBegin(GL_LINES);
 glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.22f,-0.53f);
glVertex2f(-0.22f,-0.6f);
glEnd();

glBegin(GL_LINES);
 glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.18f,-0.53f);
glVertex2f(-0.18f,-0.6f);
glEnd();

glLineWidth(0.2f);
glBegin(GL_LINES);
 glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.37f,-0.53f);
glVertex2f(0.37f,-0.6f);
glEnd();

glBegin(GL_LINES);
 glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.34f,-0.53f);
glVertex2f(0.34f,-0.6f);
glEnd();



glBegin(GL_LINES);
 glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.31f,-0.53f);
glVertex2f(0.31f,-0.6f);
glEnd();


glBegin(GL_LINES);
 glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.28f,-0.53f);
glVertex2f(0.28f,-0.6f);
glEnd();

glBegin(GL_LINES);
 glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.25f,-0.53f);
glVertex2f(0.25f,-0.6f);
glEnd();

glBegin(GL_LINES);
 glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.22f,-0.53f);
glVertex2f(0.22f,-0.6f);
glEnd();

glBegin(GL_LINES);
 glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.18f,-0.53f);
glVertex2f(0.18f,-0.6f);
glEnd();


// GREEN BOX 
glBegin(GL_QUADS);
glColor3f(0.0745f, 0.3686f, 0.0941f);
glVertex2f(-0.3f,-0.12f);
glVertex2f(0.3f,-0.12f);
glVertex2f(0.3f,-0.18f);
glVertex2f(-0.3f,-0.18f);
glEnd();

//GUNES
        drawSUNCircle(-0.8, 0.8, 0.1, 10000, 1.0, 1.0, 0.0);
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(-0.8f, 0.55f);
        glVertex2f(-0.8f, 1.0f);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(-1.0f, 0.8f);
        glVertex2f(-0.55f, 0.8f);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(-0.63f, 0.97f);
        glVertex2f(-0.97f, 0.63f);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(-0.97f, 0.97f);
        glVertex2f(-0.63f, 0.63f);
        glEnd();
     
// direkler
glLineWidth(3.0f);
glBegin(GL_LINES);
glColor3f(0.9f,0.9f,0.9f); // RENGINI DUZELT 
glVertex2f(-0.14f,-0.35f);
glVertex2f(-0.14f,-0.6f);

glEnd();

glLineWidth(3.0f);
glBegin(GL_LINES);
glColor3f(0.9f,0.9f,0.9f); // RENGINI DUZELT 
glVertex2f(0.13f,-0.35f);
glVertex2f(0.13f,-0.6f);
glEnd();
// MESCIDIN ON HISSESI
glBegin(GL_QUADS);
glColor3f(0.71f, 0.72f, 0.53f);
glVertex2f(-0.56f,-0.7f);
glVertex2f(0.56f,-0.7f);
glVertex2f(1.0f,-1.0f);
glVertex2f(-1.0f,-1.0f);
glEnd();
// YASILLIQ 
glBegin(GL_QUADS);
glColor3f(0.0745f, 0.3686f, 0.0941f);
glVertex2f(-0.55f,-0.35f);
glVertex2f(-1.0f,-0.35f);
glColor3f(0.1412f, 0.5294f, 0.1686f);
glVertex2f(-1.0f,-1.0f);
glVertex2f(-0.56f,-0.7f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0745f, 0.3686f, 0.0941f);
glVertex2f(0.55f,-0.35f);
glVertex2f(1.0f,-0.35f);
glColor3f(0.1412f, 0.5294f, 0.1686f);
glVertex2f(1.0f,-1.0f);
glVertex2f(0.56f,-0.7f);
glEnd();

// LAMPALAR
glBegin(GL_QUADS);
glColor3f(0.0353f, 0.1686f, 0.0314f);
glVertex2f(-0.98f,-0.94f);
glVertex2f(-0.98f,-0.89f);
glVertex2f(-0.94f,-0.89f);
glVertex2f(-0.94f,-0.94f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8471f, 0.8902f, 0.0431f);
glVertex2f(-0.99f,-0.89f);
glVertex2f(-0.99f,-0.86f);
glVertex2f(-0.93f,-0.86f);
glVertex2f(-0.93f,-0.89f);
glEnd();


glBegin(GL_QUADS);
glColor3f(0.0353f, 0.1686f, 0.0314f);
glVertex2f(0.98f,-0.94f);
glVertex2f(0.98f,-0.89f);
glVertex2f(0.94f,-0.89f);
glVertex2f(0.94f,-0.94f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.8471f, 0.8902f, 0.0431f);
glVertex2f(0.99f,-0.89f);
glVertex2f(0.99f,-0.86f);
glVertex2f(0.93f,-0.86f);
glVertex2f(0.93f,-0.89f);
glEnd();

// TUTACAQ


// yerin daslari
glLineWidth(0.5f);
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.63f,-0.75f);
glVertex2f(0.63f,-0.75f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.7f,-0.8f);
glVertex2f(0.7f,-0.8f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.77f,-0.85f);
glVertex2f(0.77f,-0.85f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.84f,-0.9f);
glVertex2f(0.84f,-0.9f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.91f,-0.95f);
glVertex2f(0.91f,-0.95f);
glEnd();


glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.4f,-0.7f);
glVertex2f(-0.78f,-1.0f);
glEnd();


glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.24f,-0.7f);
glVertex2f(-0.64f,-1.0f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-0.08f,-0.7f);
glVertex2f(-0.44f,-1.0f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.08f,-0.7f);
glVertex2f(-0.22f,-1.0f);
glEnd();


glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.24f,-0.7f);
glVertex2f(0.0f,-1.0f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.4f,-0.7f);
glVertex2f(0.22f,-1.0f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.56f,-0.7f);
glVertex2f(0.44f,-1.0f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.7f,-0.8f);
glVertex2f(0.66f,-1.0f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.84f,-0.9f);
glVertex2f(0.82f,-1.0f);
glEnd();
// guller

drawSUNCircle(0.8, -0.75, 0.025, 10000, 1.0, 0.75, 0.8);
drawSUNCircle(0.8, -0.8, 0.025, 10000, 1.0, 0.75, 0.8);
drawSUNCircle(0.765, -0.775, 0.025, 10000, 1.0, 0.75, 0.8);
drawSUNCircle(0.835, -0.775, 0.025, 10000, 1.0, 0.75, 0.8);
drawSUNCircle(0.8, -0.775, 0.025, 10000, 1.0, 1.0, 0.0);


drawSUNCircle(-0.8, -0.75, 0.025, 10000, 1.0, 0.0, 0.8);
drawSUNCircle(-0.8, -0.8, 0.025, 10000, 1.0, 0.0, 0.8);
drawSUNCircle(-0.765, -0.775, 0.025, 10000, 1.0, 0.0, 0.8);
drawSUNCircle(-0.835, -0.775, 0.025, 10000, 1.0, 0.0, 0.8);
drawSUNCircle(-0.8, -0.775, 0.025, 10000, 1.0, 1.0, 0.0);

drawSUNCircle(-0.9, -0.65, 0.025, 10000, 1.0, 1.0, 0.8);
drawSUNCircle(-0.9, -0.7, 0.025, 10000, 1.0, 1.0, 0.8);
drawSUNCircle(-0.865, -0.675, 0.025, 10000, 1.0, 1.0, 0.8);
drawSUNCircle(-0.935, -0.675, 0.025, 10000, 1.0, 1.0, 0.8);
drawSUNCircle(-0.9, -0.675, 0.025, 10000, 0.0, 0.0, 1.0);

drawSUNCircle(0.9, -0.65, 0.025, 10000, 1.0, 0.0, 1.8);
drawSUNCircle(0.9, -0.7, 0.025, 10000, 1.0, 0.0, 1.8);
drawSUNCircle(0.865, -0.675, 0.025, 10000, 1.0, 0.0, 1.8);
drawSUNCircle(0.935, -0.675, 0.025, 10000, 1.0, 0.0, 1.8);
drawSUNCircle(0.9, -0.675, 0.025, 10000, 0.4, 0.6, 0.0);


drawSUNCircle(0.7, -0.5, 0.025, 10000, 1.0, 0.6, 0.8);
drawSUNCircle(0.7, -0.55, 0.025, 10000, 1.0, 0.6, 0.8);
drawSUNCircle(0.665, -0.525, 0.025, 10000, 1.0, 0.6, 0.8);
drawSUNCircle(0.735, -0.525, 0.025, 10000, 1.0, 0.6, 0.8);
drawSUNCircle(0.7, -0.525, 0.025, 10000, 1.0, 1.0, 1.0);

drawSUNCircle(-0.7, -0.5, 0.025, 10000, 1.0, 0.4, 1.8);
drawSUNCircle(-0.7, -0.55, 0.025, 10000, 1.0, 0.4, 1.8);
drawSUNCircle(-0.665, -0.525, 0.025, 10000, 1.0, 0.4, 1.8);
drawSUNCircle(-0.735, -0.525, 0.025, 10000, 1.0, 0.4, 1.8);
drawSUNCircle(-0.7, -0.525, 0.025, 10000, 1.0, 0.0, 0.0);


  }
 glutSwapBuffers();
}


int main(int argc, char** argv) {
glutInit(&argc, argv);
glutCreateWindow("Vertex, Primitive & Color"); 
glutInitWindowSize(320, 320);
glutInitWindowPosition(50, 50);
 glutKeyboardFunc(keyboard);
glutDisplayFunc(display); 
glutTimerFunc(15000, animateCloud, 0);
glutTimerFunc(0, update, 0);
initGL();
glutMainLoop(); 
return 0;
}