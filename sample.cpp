#include <GL/glut.h> #include<iostream> #include<cmath> #include<vector> #include<string> using namespace std;

float cmouse_click_n0=0,mouse_click_n0=0,angle=0;int tc=0; int jpoints=0;
float x[2]={20,40},y[2]={20,40},cx[2]={35,10},cy[2]={45,25};
int len=700,wid=500;
int len_half=350,wid_half=250; vector<int> points;
GLfloat red=1; GLfloat green=0; GLfloat blue=0;
void LINE_CLIPPING(){
float p[5]={0},q[5]={0},u1=0,u2=1; p[1] = cx[0]-cx[1];
p[2] = -p[1];
p[3] = cy[0]-cy[1];

