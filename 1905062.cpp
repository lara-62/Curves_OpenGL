# include "iGraphics.h"
#include<math.h>

int x = 0,dx=10,lara=1,t,curve=1,curve1,curve2,curve3,curve_sum;
int c=0,A=50,speed=1,X=1,Y=1;
double f=0.7;
int m=0,shaw=0;
int tracer_hide=0;
float num[100];
int color[100];



/*
	function iDraw() is called again and again by the system.
*/
double strx[7505],stry[100][7505],strcy[7505],str2y[7505];
void sinfunction2()
{       int i;double m=0,n,q;
    for(i=0;i<7505;i++)
    {  n=(m*3.1416)/180;
        strx[i]=m;
        q=A*sin(1.5*f*n);
        str2y[i]=q;
      m=m+0.2;
    }
}
void sinfunction(int a,int j)
{       int i;double m=0,n,q;
num[0]=0;
    for(i=0;i<7505;i++)
    {  n=(m*3.1416)/180;
        strx[i]=m;
        q=(A+a*X)*sin((f+num[j]*Y)*n);
        stry[j][i]=q;
      m=m+0.2;
    }
}
void cosfunction()
{       int i;double m=0,n,q;
    for(i=0;i<7505;i++)
    {  n=(m*3.1416)/180;
        q=A*cos(f*n);
        strcy[i]=q;
      m=m+0.2;
    }
}
double sum_curve(int i)
{
 int j;double sum=0;
 for(j=0;j<curve;j++)
 {
   sum=sum+stry[j][i];
 }
 return sum+strcy[i]+str2y[i];
}

void iDraw()
{
    //place your drawing codes here
    iClear();
    //iSetColor(0,255,255);
    //iLine(0,100,500,100);
    //iCircle(750,375,200);

     /*if(c==1)
    {
        iSetColor(255,255,0);
    }*/
    if (shaw==0)
    {
        iShowBMP(220,45,"help.bmp");
        iSetColor(0,0,0);
        iText(400,600,"Toggle Help/Main page  :F1",GLUT_BITMAP_8_BY_13);
        iText(400,580,"Toggle curve show/hide :s/S",GLUT_BITMAP_8_BY_13);
        iText(400,560,"Toggle tracer show/hide:t/T",GLUT_BITMAP_8_BY_13);
        iText(400,540,"press 1,2,3,4,..for hiding tracer individullay",GLUT_BITMAP_8_BY_13);
        iText(400,520,"pause animation    :p/P",GLUT_BITMAP_8_BY_13);
        iText(400,500,"resume animation   :r/R",GLUT_BITMAP_8_BY_13);
        iText(400,480,"Increase amplitude :a",GLUT_BITMAP_8_BY_13);
        iText(400,460,"Decrease amplitude :A",GLUT_BITMAP_8_BY_13);
         iText(400,440,"Increase frequency :f",GLUT_BITMAP_8_BY_13);
        iText(400,420,"Decrease frequency :F",GLUT_BITMAP_8_BY_13);
         iText(400,400,"Increase speed     :+",GLUT_BITMAP_8_BY_13);
        iText(400,380,"Decrease speed     :-",GLUT_BITMAP_8_BY_13);
        iText(400,360,"increase /decrease number of curves:c/C",GLUT_BITMAP_8_BY_13);
        iSetColor(0,0,255);
        iRectangle(400,650,400,50);
        iSetColor(255,255,255);
        iFilledRectangle(401,651,398,48);
        iSetColor(0,0,255);
        iText(520,670,"LETS START",GLUT_BITMAP_HELVETICA_18);
    }
    if (shaw==1)
{
iSetColor(255,255,255);
    iLine(0,375,1500,375);
    // iSetColor(255,0,0);

    sinfunction(0,0);
    cosfunction();
    sinfunction2();
    int i=0,k,j;
if(m==0){
    for(i=0;i<7504;i++){
            //iSetColor(255,0,0);
    iLine(strx[i],stry[0][i]+375,strx[i+1],stry[0][i+1]+375);
    }
    //iSetColor(30,150,50);
    for(i=0;i<7504;i++){
            //iSetColor(255,0,0);
    iLine(strx[i],strcy[i]+375,strx[i+1],strcy[i+1]+375);
    }
    //iSetColor(200,200,20);
    for(i=0;i<7504;i++){
            iSetColor(255,0,0);
    iLine(strx[i],sum_curve(i)+375,strx[i+1],sum_curve(i+1)+375);
    }
    //iSetColor(0,50,50);
    for(i=0;i<7504;i++){
            iSetColor(255,255,255);
    iLine(strx[i],str2y[i]+375,strx[i+1],str2y[i+1]+375);
    }int a=0;
    for(j=1;j<curve;j++)
    {   num[j]=num[j-1]+0.2;
    a=a+20;
    sinfunction(a,j);
        for(i=0;i<7504;i++){
            //iSetColor(255,0,0);
    iLine(strx[i],stry[j][i]+375,strx[i+1],stry[j][i+1]+375);
    }

    }

}   if(tracer_hide==0){
iSetColor(0,0,255);
        if(curve1==0)
        iFilledCircle(strx[x],stry[0][x]+375,5);
        iSetColor(17,103,198);
        if(curve2==0)
        iFilledCircle(strx[x],strcy[x]+375,5);
        iSetColor(255,0,128);
        if(curve_sum==0)
        iFilledCircle(strx[x],sum_curve(x)+375,7);
        iSetColor(43,85,72);
        if(curve3==0)
        iFilledCircle(strx[x],str2y[x]+375,5);
        color[0]=0;
        for(k=1;k<100;k++)
        {
            color[k]=50+color[k-1];
        }
        for(j=1;j<curve;j++)
        {
            iSetColor(0+color[j],0+color[j],50);
            iFilledCircle(strx[x],stry[j][x]+375,5);
        }


        iSetColor(255,255,255);

        iText(10,5,"press p for pause ,r for resume,END for exit",GLUT_BITMAP_8_BY_13);
        iText(700,675,"drag your mouse (down to up for increasing and vice versa)for changing amplitude and frequency",GLUT_BITMAP_8_BY_13);

}
    /*iRectangle(x,y,dx,dy);

    /*iSetColor(20,200,255);
    iFilledCircle(x,y,r);*/
}
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //printf("x = %d, y= %d\n",mx,my);
    //place your codes here



          A=my/2;
          if(my<5)
          {
              A=0;
            X=0;
          }
          else
          {
              X=1;
          }


      f=(mx/1000.0);

}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    /*if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        //printf("x = %d, y= %d\n",mx,my);
        x += 5;
        y += 5;

    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        x -= 5;
        y -= 5;
    }*/
   /* if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN&&(mx>=x&&mx<=x+dx)&&(my>=y&&my<=y+dy))
    {   iSetColor(255,255,0);
        c=1;
    }
    else if(button==GLUT_LEFT_BUTTON && state==GLUT_UP)
    {
        c=0;
    }*/
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void ballchange()
{   if(tracer_hide==0)
   {

    x=x+dx;
    if(x<1||x>7505)
    {
        dx=-dx;
    }
   }
}
void iKeyboard(unsigned char key)
{
   /* if(key == 'q')
    {
        exit(0);
    }
    //place your codes for other keys here
    */
    if(key=='a')
    {   if(A<=374)
        A++;
    }
    else if(key=='A')
    {   if(A>0)
        A--;
        if(A==0)
        {
            X=0;
        }
        else
        {
            X=1;
        }

    }
    if(key=='f')
    {


            f=f+0.1;

    }
    else if(key=='F')
    {
            f=f-0.1;

            if(f<0.0)
            {
                f=0.0;
                Y=0;

            }
            else
            {
                Y=1;
            }
            /*if(f==0.2)
            {
                Y=0;
            }*/

    }
    if(key=='+')
    {   t=x;
        if(t<x+dx)
        {dx++;}
        else
            dx--;
    }
    else if(key=='-')
    {t=x;
        if(t>x+dx)
        {dx++;}
        else
        dx--;
    }
   if(key=='p')
   {
       iPauseTimer(0);
   }
    if(key=='r')
   {
       iResumeTimer(0);
   }
    if(key=='s')
   {
       m=0;
   }
   else if(key=='S')
   {
       m=1;
   }
   if(key=='t')
   {
       tracer_hide=1;
   }
   else if(key=='T')
   {
       tracer_hide=0;
   }
   if(key=='c')
   {    if(curve<100)
       curve++;
   }
   else if(key=='C')
   {    if(curve>1)
       curve--;
   }
   if(/*key=='<'&&*/key=='1'/*&&key=='>'*/)
   {
       if(curve1==0)
       {
           curve1=1;
       }
       else
       {
           curve1=0;
       }
   }
   if(/*key=='<'&&*/key=='2'/*&&key=='>'*/)
   {
       if(curve2==0)
       {
           curve2=1;
       }
       else
       {
           curve2=0;
       }
   }
   if(/*key=='<'&&*/key=='3'/*&&key=='>'*/)
   {
       if(curve3==0)
       {
           curve3=1;
       }
       else
       {
           curve3=0;
       }
   }
   if(/*key=='<'&&*/key=='4'/*&&key=='>'*/)
   {
       if(curve_sum==0)
       {
           curve_sum=1;
       }
       else
       {
           curve_sum=0;
       }
   }
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{   if(key==GLUT_KEY_F1&&lara==1)
{
    shaw=1;
    lara=0;
}
else if(key==GLUT_KEY_F1&&lara==0)
{
    shaw=0;
    lara=1;
}


    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    //place your codes for other keys here

}


int main()
{
    //place your own initialization codes here.
iSetTimer(speed,ballchange);
    iInitialize(1500, 750, "curve");

    return 0;
}
