#include<gl/glut.h>
#include<iostream>
#include<math.h>
using namespace std;

void init() {
	glClearColor(0.8, 0.87, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 800, 0, 800);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
}
//Function for drawing text
void WriteText(const char* text, int length, int x, int y) {
	double* matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(0, 800, 0, 800, -5, 5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x, y);
	for (int i = 0; i < length; i++) {
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}
//function for drawing circle
float theta;
void circle(int x, int y, int xr, int yr) {
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(x + xr * cos(theta), y + yr * sin(theta));
	}
	glEnd();
}
//draw cloud-1
float xpos = 0;
void cloud() {
	glColor3d(1, 1, 1);
	circle(xpos + 425, 665, 30, 30); //1
	circle(xpos + 430, 635, 30, 30);
	circle(xpos + 400, 650, 30, 30);
	circle(xpos + 460, 650, 30, 30);

	circle(xpos + 105, 740, 30, 30);//2
	circle(xpos + 100, 720, 30, 30);
	circle(xpos + 130, 730, 30, 30);
	circle(xpos + 70, 730, 30, 30);

	circle(xpos + 650, 580, 30, 30); //3
	circle(xpos + 650, 540, 25, 25);
	circle(xpos + 685, 560, 30, 30);
	circle(xpos + 615, 560, 25, 25);
}
//draw another shape of clouds
float xPosCl = 115;
void clouds() {
	glColor3d(1, 1, 1);
	glRectd(xPosCl - 10, 100, xPosCl + 95, 140);
	circle(xPosCl, 130, 30, 30);
	circle(xPosCl + 30, 150, 35, 40);
	circle(xPosCl + 60, 140, 30, 30);
	circle(xPosCl + 85, 130, 30, 30);
}
//duplicate cloud-2
void duplicloud2() {
	glPushMatrix();
	glTranslated(200, 420, 0);
	clouds();
	glTranslated(-450, 100, 0);
	clouds();
	glPopMatrix();
}
//birds
float xpob = 0;
float ypos = 0;
void birds() {
	glColor3f(0.36, 0.33, 0.32);
	glBegin(GL_POLYGON);  //1
	glVertex2i(xpob + 100, 650);
	glVertex2i(xpob + 120, 645);
	glVertex2i(xpob + 125, 650);
	glVertex2i(xpob + 120, 655);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(xpob + 110, 650);
	glVertex2i(xpob + 120, 650);
	glVertex2i(xpob + 107, ypos + 665);
	glEnd();

	glColor3f(0.50, 0.50, 0.50);
	glBegin(GL_POLYGON);  //2
	glVertex2i(xpob + 80, 620);
	glVertex2i(xpob + 100, 615);
	glVertex2i(xpob + 105, 620);
	glVertex2i(xpob + 100, 625);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(xpob + 90, 620);
	glVertex2i(xpob + 100, 620);
	glVertex2i(xpob + 87, ypos + 635);
	glEnd();

	glBegin(GL_POLYGON);//3
	glVertex2i(xpob + 215, 660);
	glVertex2i(xpob + 235, 655);
	glVertex2i(xpob + 240, 660);
	glVertex2i(xpob + 235, 665);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(xpob + 225, 660);
	glVertex2i(xpob + 235, 660);
	glVertex2i(xpob + 222, ypos + 675);
	glEnd();

	glColor3f(0.36, 0.33, 0.32);
	glBegin(GL_POLYGON);//4
	glVertex2i(xpob + 550, 645);
	glVertex2i(xpob + 570, 640);
	glVertex2i(xpob + 575, 645);
	glVertex2i(xpob + 570, 650);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(xpob + 560, 645);
	glVertex2i(xpob + 570, 645);
	glVertex2i(xpob + 557, ypos + 660);
	glEnd();

	glColor3f(0.36, 0.33, 0.32);
	glBegin(GL_POLYGON); //5
	glVertex2i(xpob + 430, 560);
	glVertex2i(xpob + 450, 555);
	glVertex2i(xpob + 455, 560);
	glVertex2i(xpob + 450, 565);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(xpob + 440, 560);
	glVertex2i(xpob + 450, 560);
	glVertex2i(xpob + 437, ypos + 575);
	glEnd();
}
//draw the seabed
void seabed() {
	glColor3d(0.6, 0.749, 0.694);
	circle(50, 50, 100, 65);
}
//coral reef NO.1
void coral1() {
	glBegin(GL_LINES);
	glVertex2d(687, 140);
	glVertex2d(680, 120);
	glVertex2d(687, 140);
	glVertex2d(690, 150);
	glVertex2d(687, 140);
	glVertex2d(680, 153);
	glVertex2d(687, 140);
	glVertex2d(697, 148);
	glVertex2d(690, 150);
	glVertex2d(693, 155);
	glVertex2d(690, 150);
	glVertex2d(687, 155);
	glVertex2d(680, 150);
	glVertex2d(683, 157);
	glVertex2d(680, 150);
	glVertex2d(677, 157);
	glVertex2d(697, 148);
	glVertex2d(700, 153);
	glVertex2d(697, 148);
	glVertex2d(694, 153);
	glEnd();
}
//duplicate coral reef NO.1
void duplicoral1() {
	glRectd(677, 100, 680, 130);
	glPushMatrix();
	glRotated(35, 0, 0, 1);
	glTranslated(-57, -415, 0);
	coral1();
	glTranslated(-10, -10, 0);
	coral1();
	glRotated(25, 0, 0, 1);
	glTranslated(-15, -300, 0);
	coral1();
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, -15, 0);
	coral1();
	glRotated(-35, 0, 0, 1);
	glTranslated(-192, 370, 0);
	coral1();
	glPopMatrix();
	glColor3d(0.86, 0.7, 0.6);
	circle(677, 100, 10, 5);
	circle(682, 103, 10, 5);
}
//draw the rocks
void rock() {
	glColor3d(0.86, 0.7, 0.6);
	circle(680, 150, 20, 15);
	glColor4d(0.6, 0.749, 0.6941, 1);
	circle(680, 130, 15, 10);
	glColor3d(0, 0.6, 0);
	circle(690, 150, 3, 10);
	glPushMatrix();
	glRotated(-30, 0, 0, 1);
	glTranslated(-160, 325, 0);
	circle(690, 150, 3, 10);
	glPopMatrix();
	glColor3d(0.2078, 0.2392, 0.215);
	circle(687, 140, 8, 5);
	circle(685, 140, 6, 6);
}
//draw the sea star 
void star() {
	glPushMatrix();
	glTranslated(350, -62, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(250, 250);
	glVertex2f(320, 210);
	glVertex2f(280, 280);
	glVertex2f(280, 200);
	glVertex2f(320, 250);
	glEnd();
	glPushMatrix();
	for (int i = 0; i < 15; i++) {
		glScaled(0.9, 0.9, 1);
		glTranslated(32.5, 26, 0);
		glBegin(GL_LINE_LOOP);
		glVertex2f(250, 250);
		glVertex2f(320, 210);
		glVertex2f(280, 280);
		glVertex2f(280, 200);
		glVertex2f(320, 250);
		glEnd();
	}
	glPopMatrix();
	glPopMatrix();
}
//coral reefs NO.2
float pointSize = 2;
void points() {
	glPointSize(pointSize);
	glBegin(GL_POINTS);
	glColor3d(1, 1, 0);
	glVertex2d(100, 75);
	glVertex2d(90, 45);
	glVertex2d(100, 35);
	glVertex2d(110, 65);
	glVertex2d(120, 55);
	glVertex2d(110, 45);
	glVertex2d(120, 35);
	glVertex2d(110, 25);
	glVertex2d(120, 15);
	glVertex2d(110, 10);
	glVertex2d(130, 10);
	glVertex2d(150, 15);
	glVertex2d(150, 30);
	glVertex2d(140, 10);
	glVertex2d(170, 30);
	glVertex2d(160, 10);
	glVertex2d(110, -6);
	glVertex2d(120, -10);
	glVertex2d(130, -12);
	glVertex2d(140, 0);
	glVertex2d(150, -5);
	glEnd();
}
void coralQuad2() {
	glBegin(GL_QUADS);
	glVertex2d(140, 0);
	glVertex2d(160, 0);
	glVertex2d(155, 50);
	glVertex2d(145, 50);
	glEnd();
	//the circle above quad-2
	circle(150, 50, 5, 10);
}
void coralReefs2() {
	glColor3f(0.5529, 0.6705, 0.4078);
	glBegin(GL_QUADS);
	//quad NO.1
	glVertex2d(100, 0);
	glVertex2d(130, 0);
	glVertex2d(125, 70);
	glVertex2d(105, 70);
	//quad NO.2
	glVertex2d(140, 0);
	glVertex2d(160, 0);
	glVertex2d(155, 50);
	glVertex2d(145, 50);
	glEnd();
	circle(135, 5, 10, 20);
	//the circle above quad-1
	circle(115, 70, 10, 20);
	//the circle above quad-2
	circle(150, 50, 5, 10);
    //circle to hide circle
	glColor3d(0.6, 0.749, 0.6941);
	circle(135, 30, 7, 20);
	glColor3f(0.5529, 0.6705, 0.4078);
	glPushMatrix();
	glRotated(-30, 0, 0, 1);
	glTranslated(-20, 60, 0);
	coralQuad2();
	glPopMatrix();
	glPushMatrix();
	glRotated(-30, 0, 0, 1);
	glTranslated(-70, 80, 0);
	coralQuad2();
	glPopMatrix();
	glPushMatrix();
	glRotated(-30, 0, 0, 1);
	glTranslated(-50, 40, 0);
	coralQuad2();
	glPopMatrix();
	glPushMatrix();
	glRotated(30, 0, 0, 1);
	glTranslated(-50, -50, 0);
	coralQuad2();
	glPopMatrix();
	glPushMatrix();
	glRotated(30, 0, 0, 1);
	glTranslated(50, -10, 0);
	glScaled(0.5, 0.5, 0.5);
	coralQuad2();
	glPopMatrix();
	glRectd(100, -17, 150, 5);
	points();
}
// draw smoke
float yposS = 200;
void smoke1() {
	glColor4d(0.4, 0.4, 0.4, 1);
	circle(600, yposS, 20, 20);
	circle(600, yposS + 20, 20, 20);
	circle(580, yposS + 5, 20, 24);
	circle(615, yposS + 10, 20, 18);
}
void smoke2() {
	glColor4d(0.4, 0.4, 0.4, 1);
	circle(500, yposS, 30, 30);
	circle(500, yposS + 50, 30, 25);
	circle(470, yposS + 20, 30, 26);
	circle(520, yposS + 30, 30, 20);
}
//duplicate smoke
void dupliSoke() {
	glPushMatrix();
	glScaled(0.7, 0.7, 0.7);
	glTranslated(-30, 20, 0);
	smoke1();
	glTranslated(10, -10, 0);
	smoke1();
	glTranslated(15, 0, 0);
	smoke1();
	glTranslated(80, -10, 0);
	smoke1();
	glTranslated(0, -80, 0);
	smoke1();
	glTranslated(50, -60, 0);
	smoke1();
	glTranslated(50, 0, 0);
	smoke1();
	glTranslated(60, -20, 0);
	smoke1();
	glTranslated(30, -80, 0);
	smoke1();
	glTranslated(10, -70, 0);
	smoke1();
	glTranslated(0, -70, 0);
	smoke1();
	glTranslated(-60, 0, 0);
	smoke2();
	glTranslated(40, 0, 0);
	smoke2();
	glTranslated(20, -30, 0);
	smoke2();
	glTranslated(0, -20, 0);
	smoke2();
	glTranslated(30, -10, 0);
	smoke2();
	glTranslated(0, -70, 0);
	smoke2();
	glTranslated(10, -30, 0);
	smoke2();
	glTranslated(-100, 0, 0);
	smoke2();
	glTranslated(30, 0, 0);
	smoke2();
	glTranslated(20, -30, 0);
	smoke2();
	glTranslated(0, -20, 0);
	smoke2();
	glTranslated(30, -10, 0);
	smoke2();
	glTranslated(0, -70, 0);
	smoke2();
	glTranslated(10, -30, 0);
	smoke2();
	glTranslated(0, 0, 0);
	smoke2();
	glTranslated(40, 0, 0);
	smoke2();
	glTranslated(20, -30, 0);
	smoke2();
	glTranslated(0, -20, 0);
	smoke2();
	glTranslated(30, -10, 0);
	smoke2();
	glTranslated(0, -70, 0);
	smoke2();
	glTranslated(10, -30, 0);
	smoke2();
	glTranslated(-120, 0, 0);
	smoke2();
	glTranslated(40, -70, 0);
	smoke2();
	glTranslated(20, -30, 0);
	smoke2();
	glTranslated(0, -20, 0);
	smoke2();
	glTranslated(30, -10, 0);
	smoke2();
	glTranslated(0, -70, 0);
	smoke2();
	glTranslated(10, -30, 0);
	smoke2();
	glTranslated(-100, 0, 0);
	smoke2();
	glTranslated(40, -70, 0);
	smoke2();
	glTranslated(20, -30, 0);
	smoke2();
	glTranslated(0, -20, 0);
	smoke2();
	glTranslated(30, -10, 0);
	smoke2();
	glTranslated(0, -70, 0);
	smoke2();
	glTranslated(10, -30, 0);
	smoke2();
	glPopMatrix();
}
float xPos0 = 0;
float yPos0 = 280;
float xPos1 = 150;
float yPos1 = 250;
float xPos2 = 300;
float yPos2 = 275;
float xPos3 = 450;
float yPos3 = 245;

void waves() {
	glColor4f(0.5529411765, 0.7490196078, 0.8901960784, 0.7);
	circle(xPos0, yPos0, 100, 50);
	circle(xPos2, yPos2, 100, 50);
	circle(xPos1, yPos1, 100, 50);
	circle(xPos3, yPos3, 100, 50);
}
//draw fishes
float xPosF = 150;
float yPosF = 150;
void fish() {
	//upper fin
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(1, 0.5, 0.3);
	glVertex2i(xPosF - 2, yPosF + 8);
	glVertex2i(xPosF + 4, yPosF + 10);
	glVertex2i(xPosF - 5, yPosF + 17);
	glVertex2i(xPosF + 1, yPosF + 14);
	glEnd();
	glPopMatrix();
	//lower fin
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(1, 0.5, 0.3);
	glVertex2i(xPosF - 2, yPosF - 8);
	glVertex2i(xPosF + 4, yPosF - 10);
	glVertex2i(xPosF - 5, yPosF - 17);
	glVertex2i(xPosF + 1, yPosF - 14);
	glEnd();
	glPopMatrix();
	//fish body
	glColor4d(1, 0.5, 0.3, 0.7);
	circle(xPosF, yPosF, 15, 10);
	//eyes
	glColor4d(1, 1, 1, 0.7);
	circle(xPosF + 7, yPosF, 3, 3);
	glColor3d(0, 0, 0);
	circle(xPosF + 9, yPosF, 1.5, 2);
	//fish mouth
	glBegin(GL_TRIANGLES);
	glColor4f(0.5529411765, 0.7490196078, 0.8901960784, 1);
	glVertex2d(xPosF + 12, yPosF);
	glVertex2d(xPosF + 15, yPosF + 3);
	glVertex2d(xPosF + 15, yPosF - 3);
	glEnd();
	//tail fin
	glColor4d(1, 0.5, 0.3, 1);
	circle(xPosF - 25, yPosF, 15, 10);
	//circle for hiding tail fin
	glColor4f(0.5529411765, 0.7490196078, 0.8901960784, 1);
	circle(xPosF - 30, yPosF, 15, 10);
}
//duplicate fish
void dupliFish() {
	glPushMatrix();
	glTranslated(-30, 20, 0);
	fish();
	glTranslated(-45, 30, 0);
	fish();
	glTranslated(-45, -40, 0);
	fish();
	glTranslated(45, -20, 0);
	fish();
	glPopMatrix();
}
//draw ship             
float xPosSh = 200;     
float yPosSh = 270;     
void line() {
	glColor3d(0, 0, 0);
	glBegin(GL_LINES);
	//draw the vertical line of handle
	glVertex2d(xPosSh - 140, yPosSh + 125);
	glVertex2d(xPosSh - 140, yPosSh + 100);
	glVertex2d(xPosSh - 80, yPosSh + 125);
	glVertex2d(xPosSh - 80, yPosSh + 100);
	//draw the horizontal line of handle
	glVertex2d(xPosSh - 140, yPosSh + 110);
	glVertex2d(xPosSh - 80, yPosSh + 110);
	glVertex2d(xPosSh - 140, yPosSh + 125);
	glVertex2d(xPosSh - 80, yPosSh + 125);
	glEnd();
}
void ship() {
	glColor3d(0.38039215686274509803921568627451, 0.36862745098039215686274509803922, 0.36862745098039215686274509803922);
	glBegin(GL_QUADS);
	glVertex2d(xPosSh, yPosSh);
	glVertex2d(xPosSh + 100, yPosSh + 100);
	glVertex2d(xPosSh - 180, yPosSh + 100);
	glVertex2d(xPosSh - 150, yPosSh);
	glEnd();
	glColor3d(0.5490196078431372549019607841373, 0.53725490196078431372549019607843, 0.5333333333333333333333333333333333);
	glRectd(xPosSh - 150, yPosSh + 100, xPosSh - 70, yPosSh + 150);
	glRectd(xPosSh - 140, yPosSh + 150, xPosSh - 80, yPosSh + 180);
	//draw the windows
	glColor4d(0.862745098, 0.9019607843, 0.9607843137, 0.5);
	glRectd(xPosSh - 135, yPosSh + 155, xPosSh - 125, yPosSh + 175);
	glPushMatrix();
	glTranslated(20, 0, 0);
	glRectd(xPosSh - 135, yPosSh + 155, xPosSh - 125, yPosSh + 175);
	glTranslated(20, 0, 0);
	glRectd(xPosSh - 135, yPosSh + 155, xPosSh - 125, yPosSh + 175);
	glPopMatrix();
	glColor3d(0, 0, 0);
	glBegin(GL_LINES);
	//draw the ropes
	glVertex2d(xPosSh + 97, yPosSh + 100);
	glVertex2d(xPosSh + 79, yPosSh + 195);
	glVertex2d(xPosSh + 51, yPosSh + 231);
	glVertex2d(xPosSh - 30, yPosSh + 100);
	glVertex2d(xPosSh + 69, yPosSh + 195);
	glVertex2d(xPosSh + 65, yPosSh + 230);
	glVertex2d(xPosSh - 130, yPosSh + 280);
	glVertex2d(xPosSh - 105, yPosSh + 240);
	glVertex2d(xPosSh - 85, yPosSh + 280);
	glVertex2d(xPosSh - 110, yPosSh + 240);
	glVertex2d(xPosSh - 130, yPosSh + 280);
	glVertex2d(xPosSh - 175, yPosSh + 100);
	glVertex2d(xPosSh - 102, yPosSh + 228);
	glVertex2d(xPosSh, yPosSh + 100);
	glVertex2d(xPosSh - 113, yPosSh + 228);
	glVertex2d(xPosSh - 130, yPosSh + 180);
	glVertex2d(xPosSh - 85, yPosSh + 283);
	glVertex2d(xPosSh - 72, yPosSh + 150);
	//draw above handle (side)
	glVertex2d(xPosSh - 147, yPosSh + 160);
	glVertex2d(xPosSh - 147, yPosSh + 150);
	glVertex2d(xPosSh - 75, yPosSh + 160);
	glVertex2d(xPosSh - 75, yPosSh + 150);
	glColor3d(0, 0, 0);
	//draw above handle (horizental)
	glVertex2d(xPosSh - 147, yPosSh + 160);
	glVertex2d(xPosSh - 75, yPosSh + 160);
	glEnd();
	//draw the rods
	glColor3d(0.8117, 0.796, 0.7921);
	glRectd(xPosSh + 50, yPosSh + 100, xPosSh + 65, yPosSh + 230);
	glRectd(xPosSh + 69, yPosSh + 100, xPosSh + 79, yPosSh + 198);
	glRectd(xPosSh - 105, yPosSh + 180, xPosSh - 110, yPosSh + 280);
	glRectd(xPosSh - 130, yPosSh + 280, xPosSh - 85, yPosSh + 285);
	glColor3b(1, 0, 0);
	glRectd(xPosSh - 102, yPosSh + 227, xPosSh - 113, yPosSh + 230);
	//draw the handle
	line();
	glPushMatrix();
	glTranslatef(80, 0, 0);
	line();
	glTranslatef(80, 0, 0);
	line();
	glPopMatrix();
	glColor3b(1, 0, 0);
	std::string text;
	text = "Georgios G";
	WriteText(text.data(), text.size(), xPosSh - 75, yPosSh + 40);
}
//jordan flag
void flag() {
	glPushMatrix();
	glTranslated(310, 20, 0);
	glColor3d(0, 0, 0);
	glRectd(120, 580, 160, 565);
	glColor3d(1, 1, 1);
	glRectd(120, 565, 160, 550);
	glColor3d(0, 0.5, 0);
	glRectd(120, 550, 160, 535);
	glBegin(GL_TRIANGLES);
	glColor3d(1, 0, 0);
	glVertex2d(120, 580);
	glVertex2d(120, 535);
	glVertex2d(135, 560);
	glEnd();
	glColor3d(1, 1, 1);
	circle(128, 560, 3, 3);
	glPushMatrix();
	glTranslated(128, 560, 0);
	for (int i = 0;i < 8;i++) {
		glRotatef(360 / 8, 0, 0, 1);
		glBegin(GL_LINES);
		glVertex2d(0, 0);
		glVertex2d(5, 0);
		glEnd();
	}
	glPopMatrix();
	glPopMatrix();
}
//draw tourist destination symbol
void symbol() {
	glPushMatrix();
	glTranslated(352, 5, 0);
	glColor3d(0.7, 0, 0);
	circle(100, 600, 15, 23);
	glBegin(GL_TRIANGLES);
	glVertex2d(85, 600);
	glVertex2d(115, 600);
	glVertex2d(100, 560);
	glColor3d(1, 1, 1);
	glVertex2d(101, 600);
	glVertex2d(112, 600);
	glVertex2d(101, 617);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2d(100, 599);
	glVertex2d(92, 599);
	glVertex2d(100, 618);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2d(89, 595);
	glVertex2d(115, 595);
	glVertex2d(113, 597);
	glVertex2d(87, 597);
	glVertex2d(89, 593);
	glVertex2d(113, 593);
	glVertex2d(110, 589);
	glVertex2d(92, 589);
	glEnd();
	glPopMatrix();
}
//Write the story of the scene
float counter = 0;
void text() {
	glColor3b(1, 0, 0);
	std::string text = "Before 42 years,";
	std::string text1 = "Georgios G vessel was travelling to Jordan";
		if (counter < 7000){
			WriteText(text.data(), text.size(), 50, 600);
			WriteText(text1.data(), text1.size(), 50, 570);
			flag();
		}

		text = "Then for unknown reasons, ";
		text1 = "the vessel stuck on the coral reefs on saudi coast!";
		if (counter < 57000 && counter > 50000) {
			WriteText(text.data(), text.size(), 50, 600);
			WriteText(text1.data(), text1.size(), 50, 570);
		}

		text = "While trying to restart the engines,";
		text1 = "cought fire and burend. Also, half of the vessel sank.";
		if (counter < 85000 && counter > 57000) {
			WriteText(text.data(), text.size(), 50, 600);
			WriteText(text1.data(), text1.size(), 50, 570);
		}

		text = "Eventually, the vessel remained ever since,  ";
		text1 = "and became a beautiful tourist destination.";
		if (counter < 150000 && counter > 108000) {
			WriteText(text.data(), text.size(), 50, 600);
			WriteText(text1.data(), text1.size(), 50, 570);
			symbol();
		}
}
//animation
int state = 1;
int ystate = 1;
int a = 1;
void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
	//clouds movement
	if (xpos < 900)
		xpos += 0.25;

	else
		xpos = -1200;

	//clouds-2 movement
	if (xPosCl < 1200)
		xPosCl += 0.3;
	else
		xPosCl = -1200;

	//birds movement
	if (xpob < 800)
		xpob += 0.45;
	else
		xpob = -2200;


	switch (ystate)
	{
	case 1: if (ypos < 5)
		ypos += 0.50;
		  else {
		ystate = -1;
		ypos = 0;
	}
		  break;
	case -1: if (ypos > -20)
		ypos -= 0.50;
		   else {
		ystate = 1;
		ypos = 0;
	}
		   break;
	}
	//animation for waves
	if (xPos0 < 800) {
		xPos0 += 0.15;
		switch (a) {
		case 1:
			if (yPos0 > 250)
				yPos0 -= 0.15;
			else a = 2; break;
		case 2:
			if (yPos0 < 270)
				yPos0 += 0.15;
			else a = 1;
			break;
		}
	}
	else
		xPos0 = 0;
	//wave 2
	if (xPos1 < 800) {
		xPos1 += 0.15;
		switch (a) {
		case 1:
			if (yPos1 < 270)
				yPos1 += 0.15;
			else a = 2; break;
		case 2:
			if (yPos1 > 250)
				yPos1 -= 0.15;
			else a = 1;
			break;
		}
	}
	else
		xPos1 = 0;
	//wave 3
	if (xPos2 < 800) {
		xPos2 += 0.15;
		switch (a) {
		case 1:
			if (yPos2 > 250)
				yPos2 -= 0.15;
			else a = 2; break;
		case 2:
			if (yPos2 < 270)
				yPos2 += 0.15;
			else a = 1;
			break;
		}
	}
	else
		xPos2 = 0;
	//wave 4
	if (xPos3 < 800) {
		xPos3 += 0.15;
		switch (a) {
		case 1:
			if (yPos3 < 270)
				yPos3 += 0.15;
			else a = 2; break;
		case 2:
			if (yPos3 > 250)
				yPos3 -= 0.15;
			else a = 1;
			break;
		}
	}
	else
		xPos3 = 0;
	//animate fish
	if (xPosF < 800)
		xPosF += 0.5;

	//animate coral reefs
	if (pointSize > 0)
		pointSize -= 0.05;
	else
		pointSize = 2;
	//animate ship    
	switch (state) {
	case 1:
		if (xPosSh < 1000)
			xPosSh += 0.6;
		else {
			xPosSh = -100;
			state = 2;
		}
		break;
	case 2:
		if (xPosSh < 600)
			xPosSh += 0.6;
		//animate smoke
		else if (yPosSh > 100)
			yposS += 0.7;
		break;

	}
	//sink ship
	if (counter < 2000000 && counter > 63000) {
		if (yPosSh > 230)
			yPosSh -= 0.05;
	}
}
void draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	//sun
	glColor3f(1.0, 0.97, 0.0);
	circle(700, 700, 60, 60);
	//call cloud
	cloud();
	duplicloud2();
	//call birds
	birds();
	//ship
	glPushMatrix();
	for (int i = 0; i < 20; i++) {
		counter++;
	}
	//ship sinking
	if (counter < 20000000 && counter > 61000) {
		glTranslated(100, -100, 0);
		glRotated(10, 0, 0, 1);
	}
	ship();
	glPopMatrix();
	//call smoke	
	dupliSoke();
	//draw the sea
	glColor4f(0.5529411765, 0.7490196078, 0.8901960784, 1);
	glRecti(0, 0, 800, 300);
	//fish
	fish();
	dupliFish();
	//calling to draw waves
	waves();
	//seabed
	seabed();
	glPushMatrix();
	for (int i = 1; i <= 11; i++) {
		if (i == 9) {
			glTranslated(0, 150, 0);
		}
		else if (i > 9) {
			glTranslated(-80, -20, 0);
		}
		else	glTranslated(100, 0, 0);
		seabed();

	}
	glPopMatrix();
	//coral reefs
	//call stars
	glColor3f(0.4117, 0.2352, 0.3445);
	star();
	glPushMatrix();
	glColor3f(1, 0.2352, 0.3445);
	glScaled(0.5, 0.5, 1);
	glTranslated(610, 120, 0);
	star();
	glPopMatrix();
	//call rocks
	glPushMatrix();
	glTranslated(0, 75, 0);
	rock();
	glTranslated(40, -170, 0);
	rock();
	glPopMatrix();
	//call coral reefs NO.1
	glPushMatrix();
	glColor3d(0.9019, 0.1333, 0.5176);
	glTranslated(0, -30, 0);
	coral1();
	duplicoral1();
	glColor3d(0.9019, 0.1333, 0);
	glTranslated(55, 100, 0);
	coral1();
	duplicoral1();
	glColor3d(0.9019, 0.1333, 0);
	glRotated(-30, 0, 0, 1);
	glTranslated(-138, 330, 0);
	coral1();
	duplicoral1();
	glPopMatrix();
	//call coralreefs NO.2
	glPushMatrix();
	glTranslated(500, 0, 0);
	coralReefs2();
	glTranslated(160, 80, 0);
	glScaled(0.8, 0.8, 1);
	coralReefs2();
	glPopMatrix();
	//tranparent plan for improvements
	glColor4f(0.5529411765, 0.7490196078, 0.8901960784, 0.5);
	glRecti(-800, 0, 800, 300);
	text();
	glutSwapBuffers();
}
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 500);
	glutCreateWindow("GEORGIOS G vessel");
	init();
	glutDisplayFunc(draw);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
	return 0;
}