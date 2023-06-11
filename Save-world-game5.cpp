
#include <iostream>
#include <conio.h> //👈 for keyboard input
#include <thread>// for clear screen and stop for 1s 
#ifdef _WIN32
#else

#define ClearScreen() std::cout << "\033[2J\033[1;1H"
#endif

// colors 👇👇
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

using namespace std;

const int sizex = 35 ; // 🚫 Don't make it bigger than 45
const int sizey = 15; //if game is big so much or big so much on screen change it

 int xh = sizex/8  ;
 int yh = 1  ;

 int xa = sizex / 2  ;
 int ya = sizey / 4 ;
 
 int xb =  sizex/2  ;
 int yb = sizey-3 ;

 int x1 =sizex -1  ;
 int y1 = sizey - sizey*0.35  ;

 int x2 = sizex - sizex/8 ;
 int y2 = sizey - sizey * 0.15;

 int x3 = sizex - sizex* 0.275;
 int y3= sizey - sizey * 0.15;

 int n ;
 int r1 ;
 int r3 = 1   ;

 bool gameover = false ;

   void Tracking(int &x , int &y, int xh , int yh );
   void rolls (int &x , int &y , int &xh , int &xy);
   void setup ();
   void Input();
   void Citizens(int &x , int &y  , int &r3);
   void Wallout(int &x , int &y  );


//Function that makes animes🐍🐍 Attacks you
void Tracking(int &x , int &y, int xh , int yh ) {

    if (x == xh) {
        x = xh;
    }
    if (x > xh) {
        x--;
    }
    if (x < xh) {
        x++;
    }

    if (y == yh) {
        y = yh;
    }
    if (y > yh) {
        y--;
    }
    if (y < yh) {
        y++;
    }
    
}

//THIS ROLSE OF KILLING ☠

 void rolls(int &x , int &y , int &xh , int &xy){
  
       void Input();
// 👇   this mean animes(#)die of restart 
 if(x <= xh  ){
   if( xh == x && yh == y && r1 ==2){ x-=5 ; y -=5 ; }  
} 

  if(x >= xh  ){
    if( xh == x && yh == y && r1 ==1) {x-=5 ; y -=5 ;}
}   

   if(y <= yh  ){
      if( xh == x && yh == y && r1 == 3) {x-=5 ; y -=5 ;}
}      

    if(y >= yh  ){
      if( xh == x && yh == y && r1 == 4) {x-=5 ; y -=5 ;}
}       

    // 👇   this mean you(X)die of restart 

 if(x <= xh  ){
    if( xh == x && yh == y && r1 !=2){ xh =  sizex * 0.55; yh =sizey/4 ; }   
}   

 if(x >= xh  ){
     if( xh == x && yh == y && r1 !=1) {xh= sizex * 0.55 ; yh=sizey/4 ;}
}    

  if(y <= yh  ){
      if( xh == x && yh == y && r1 != 3){ xh= sizex * 0.55 ; yh=sizey/4 ;}
}     

   if(y >= yh  ){
       if( xh == x && yh == y && r1 != 4) {xh= sizex * 0.55 ; yh=sizey/4 ;}
}     


} 



// Seting up boundaries of animes 🐍🐍
 void setup (int &x , int &y ){
  if( y == sizey/2 && x <= sizex*0.6){ x+=2 ; y-- ;}

if( y <= 4 && x == sizex*0.8 || y == 4 && x >= sizex*0.8 ){
   if(x == xa && y == ya){  xa = sizex/2 ; ya = sizey/4 ; }
    if(x == xb && y == yb){xb =  sizex/2  ; yb = sizey*0.85 ;}

}   

     
  
}
    
//THIS ⌨input function 
void Input() {
    if (_kbhit()) {
        char key = _getch();
        switch (key) {
            case 'd':                //   LIFT 👉
                xh+=2;  r1 = 1 ;  
                      break;
            case 'a':                //   RIGHT👈
                xh-=2;  r1 = 2 ;
                      break;
            case 'w':                //   UP☝️
               yh-=2;   r1 = 3 ;
                      break;
            case 'z' :                //  DOWN👇
                yh+=2 ; r1 = 4 ;
                      break;
            case 'x':                //   EXIT🛑
                gameover = true;
                      break;
        }
    }
}

//this the style 🎨 and UX of game   
void Draw(){
  cout<<"         SAVE THE WORLD       "<<endl   ;
//cout<<BLUE<<"*****************************************\n";

for(int I = 0 ; I <= sizex ; I++){cout<<BLUE<<"*";}//top wall
 cout<<endl ;
            
for(int I =0 ; I < sizey ; I ++){

    n = 1 ;
   
 cout<<BLUE <<"*"<<RESET; // left wall   
      for(int J =0 ; J < sizex ; J ++) {    
 
if( I == y1 && J == x1||I == y2 && J == x2||I == y3 && J == x3 ||I == yb && J == xb||I == ya && J == xa|| I == yh && J == xh ||I == sizey/2 && J < 0.7 * sizex ||I < 4 && J == sizex* 0.8 ||I == 4 && J >= sizex*0.8){

if(I == sizey/2 && J < 0.7 * sizex){
  cout <<"=";
}   
if(I < 4 && J == sizex* 0.8){    
  cout << "&";
}   
if(I == 4 && J >= sizex* 0.8){
  cout << "&";
}   
  
 if(I == yh && J == xh){
   cout<<CYAN<<"X"<<RESET ;
      n++;} 
 
     if(I == ya && J == xa){
        cout<<YELLOW<<"#"<<RESET     ;
            n++;}

       if(I == yb && J == xb){
          cout<<MAGENTA<<"#"<<RESET     ;
           n++;}  

       if(I == y1 && J == x1){cout<<GREEN<<"×"<<RESET    ; 
       n++;}

   if(I == y2 && J == x2){cout<<GREEN<<"×"<<RESET    ; 
    n++;} 

 if(I == y3 && J == x3){cout<<GREEN<<"×"<<RESET    ;  
 n++;}


} 
         else{n++ ; cout<<" "; } 
                
     }                                      
     if( n > 1 && I >= sizey){
    for(int A ; A <= n ;A++){  
    cout <<" ";
    } 
    cout <<BLUE<<"*"<< endl;      // right  wall 
       }
               
     else { cout<<BLUE << "*" <<endl;
  
                     } 
        
  }          
for(int I = 0 ; I <= sizex ; I++){cout<<BLUE<<"*";} //botton wall
 cout<<endl ;       
cout<<GREEN<<"you have score : "<<RESET<< r3 -1  <<endl;

}



//Function for get through walls ↔️
void Wallout(int &x , int &y  ){

    if (y <= 0) { y = sizey;}
          
    if (y > sizey) {y = 1 ;}
     
    if (x <= 0) { x = sizex;}
        
    if (x > sizex){ x = 1;}
    

}


//Function  of 🌍 citizens(×) and  save citizens 
void Citizens(int &x , int &y   , int &r3  ){

if( y < 4  && x >= sizex*0.8  ){
       y = y ;
       x = x ;  
      r3++;
}               
 else if(xh == x && yh == y-2|| xh == x && yh == y+2 || xh == x+2 && yh == y ||xh == x-2 && yh == y || xh == x && yh == y  || xh == x && yh == y-1|| xh == x && yh == y+1 || xh == x+1 && yh ==y||xh == x-1 && yh == y ){ 
    x = xh ; y = yh ;
  }   
      
                }



int main(){
  
while (!gameover){
r1 = 0 ;

   Wallout(xh , yh);    
    Input();     
      Draw ();
  
   if( yh > sizey/2 ){ Tracking(xb , yb , xh , yh  );  }
       else { Tracking(xa , ya , xh , yh  ); }   
      
   rolls (xa , ya , xh , yh );
    rolls (xb , yb , xh , yh );             
      setup (xb , yb);
       setup (xa , ya); 
         
       
 if( r3 == 1){ Citizens( x1 , y1  , r3) ;  Wallout(x1 , y1); }  
            
 if( r3 == 2 ){  Citizens( x2 , y2 , r3 ); Wallout(x2 , y2);} 
      
 if( r3 == 3){   Citizens( x3 , y3 , r3 ); Wallout(x3 , y3);} 
            
       ClearScreen();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  
    
 if( r3==3 &&y3 < 4 && x3 >=sizex*0.8){ break;}     
      
}    

 if(!gameover)cout<<"\n"<<"\n"<<YELLOW <<"  YOU WIN   " << RESET <<endl<< endl; 
        
            
    return 0;
}