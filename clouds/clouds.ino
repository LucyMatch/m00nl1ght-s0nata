/**
This arduino sketch used the parallax LCD screen to create a window scenary animation
along with moonlight sonata as a soundtrack.
Created by Alex Tosti, Joselyn Neon McDonald and Lucy Matchett
*//

#include <SoftwareSerial.h>

byte zero = 0;
int x = 0;
int y = 128;
int cloudSpeed = 200;

int A = 220;
int As = 221;
int B = 222;
int C = 223;
int Cs = 224;
int D = 225;
int Ds = 226;
int E = 227;
int F = 228;
int Fs = 229;
int G = 230;
int Gs = 231;

int sev = 219;
int six = 218;
int fth = 217;
int frt = 216;
int trd = 215;

SoftwareSerial LCDtop(12,13);  //Top LCD using pin 13
SoftwareSerial LCDmid(10,11);  //Middle LCD using pin 11
SoftwareSerial LCDbot(8,9);    //Bottom LCD using pin 9


void setup(){
  
    LCDtop.begin(9600);
    LCDtop.write(0x0C);
    
    LCDmid.begin(9600);
    LCDmid.write(0x0C);
    
    LCDbot.begin(9600);
    LCDbot.write(0x0C);
    
    delay(500);
    delay(5000);
    
    //Turn backlight on (17) write name, and then clear (12)//
    
    LCDtop.write(17);
    LCDtop.print("m00nl1ght S0nata");
    
  
    
    
    LCDmid.write(17);
    LCDmid.print("sc0re by:        B1nary Beth0ven");
  
    
    
    LCDbot.write(17);
    LCDbot.print("Lucy, Joselyn     &  Alex");
   
    
    
   
    
    delay(5000);
    LCDtop.write(12);
    LCDmid.write(12);
    LCDbot.write(12);
    
    build_me_a_forest();
    moon_me();
}


void loop(){
  
  beautiful_flowing_grass();
  let_the_music_play();
  
 
//  for(int i=0; i < 16; i++){
//    cloudFive_top(128+i);
//  cloudfrt_top(129+i);
//    
//  cloudZero_top(131+i);
//  cloudOne_top(132+i);
//  cloudTwo_top(133+i);
//  
//  cloudThree_top(135+i);
//  cloudFour_top(136+i);
//  
//    cloudZero_top(139+i);
//  cloudOne_top(140+i);
//  cloudTwo_top(141+i);
//  delay(cloudSpeed);
//  LCDtop.write(12);
//  
//    if(i>4){
//    LCDtop.write(13);
//    }
//  }  

   cloud_one(131);
  
  
  
}

void cloud_one(int x) {
  
  int remainderTop = 143 - x;
  int remainderBottom = 163 - x;
  int location2 = x+5;
  
    for(int i =0; i < remainderTop; i++){
      
        cloudZero_top(x+i);
        cloudOne_top(x+i+1);
        cloudTwo_top(x+i+2);
        
        cloudZero_top(location2+i);
        cloudOne_top(location2+i+1);
        cloudTwo_top(location2+i+2);
        
      if((2+location2+i) > 142){
        location2 = 128;
        i = 0; 
      }
      if((2+x+i) > 142){
        x = 128;
        i = 0; 
      }
      delay(cloudSpeed);
      LCDtop.write(12);
    }

}


//// FUNCTION FOR FOREST BUILDING
void build_me_a_forest() {
  for(int i=0; i< 12; i++){
    //DRAW TREE in middle screen//
    treeZero_mid(142-i);
    treeOne_mid(143-i);
    treeTwo_mid(161-i);
    treeThree_mid(162-i);
    treeFour_mid(163-i);
    //DRAW TREE in bottom screen//
    treeZero_bot(141-i);
    treeOne_bot(142-i);
    treeTwo_bot(143-i);
    treeThree_bot(162-i);
    treeFour_bot(163-i);
    
    i = i+2; // add an extra 2 so i is moving in incriments of three
  }

}

void moon_me() {
  moonOne_mid(128);
  moonTwo_mid(148);
  moonThree_mid(149);
}

//MAKE SOME GRASSSSSSSS
void beautiful_flowing_grass() {
  
//      grassOne_bot(148);
//      grassTwo_bot(149);
//      grassThree_bot(150);
//      grassTwo_bot(151);
  
  
  for (int i=0; i< 2; i++){
      grassOne_bot(148 + i);
      grassTwo_bot(149 + i);
      grassThree_bot(150 + i);
      grassTwo_bot(151 + i);
        if(i > 1){
          grassThree_bot(152 - 4);
          i = 0;
        }else{
          grassThree_bot(152);
      }
      delay(200);
  }
  
  for(int i=0; i< 6; i++){
    grassOne_bot(161 - (2*i));
    grassTwo_bot(158 + i );
    grassThree_bot(155 + i );
    i = i+2;
      if(i > 5){
        i = 0;
      }
    delay(200);
  }
  
}


/////////////////////////////8 custom characters for top screen - CLOUDS//////////////////////////
void cloudZero_top(int x){

    LCDtop.write(0xF8); //take in custom char
    
    LCDtop.write(B00000001); 
    LCDtop.write(B00000010);
    LCDtop.write(B00001100);
    LCDtop.write(B00010010);
    LCDtop.write(B00010000);
    LCDtop.write(B00010000);
    LCDtop.write(B00001111);
    LCDtop.write(zero);
    LCDtop.write(x);
    LCDtop.write(zero);

}

void cloudOne_top(int x){

    LCDtop.write(0xF9); //take in custom char
    
    LCDtop.write(B00011000); 
    LCDtop.write(B00000101);
    LCDtop.write(B00000010);
    LCDtop.write(B00000001);
    LCDtop.write(zero);
    LCDtop.write(zero);
    LCDtop.write(B00011111);
    LCDtop.write(zero);
    
    LCDtop.write(x);
    LCDtop.write(1);

}

void cloudTwo_top(int x){

    LCDtop.write(0xFA); //take in custom char
    
    LCDtop.write(zero); 
    LCDtop.write(B00010000);
    LCDtop.write(B00001000);
    LCDtop.write(B00000100);
    LCDtop.write(B00000010);
    LCDtop.write(B00000010);
    LCDtop.write(B00011110);
    LCDtop.write(zero);
    
    LCDtop.write(x);
    LCDtop.write(2);

}

void cloudThree_top(int x){

    LCDtop.write(0xFB); //take in custom char
    
    LCDtop.write(zero); 
    LCDtop.write(zero);
    LCDtop.write(B00001101);
    LCDtop.write(B00010010);
    LCDtop.write(B00010010);
    LCDtop.write(B00010000);
    LCDtop.write(B00001111);
    LCDtop.write(zero);
    
    
    LCDtop.write(x);
    LCDtop.write(3);

}


void cloudFour_top(int x){

    LCDtop.write(0xFC); //take in custom char
    
    LCDtop.write(zero); 
    LCDtop.write(zero);
    LCDtop.write(B00010000);
    LCDtop.write(B00001000);
    LCDtop.write(B00000100);
    LCDtop.write(B00000010);
    LCDtop.write(B00011110);
    LCDtop.write(zero);
    
    
    LCDtop.write(x);
    LCDtop.write(4);

}

void cloudFive_top(int x){

    LCDtop.write(0xFD); //take in custom char
    
    LCDtop.write(zero); 
    LCDtop.write(B00000011);
    LCDtop.write(B00000100);
    LCDtop.write(B00001010);
    LCDtop.write(B00010000);
    LCDtop.write(B00001000);
    LCDtop.write(B00000111);
    LCDtop.write(zero);
    
    LCDtop.write(x);
    LCDtop.write(5);

}

void cloudfrt_top(int x){

    LCDtop.write(0xFE); //take in custom char
    
    LCDtop.write(zero); 
    LCDtop.write(zero);
    LCDtop.write(B00010100);
    LCDtop.write(B00001010);
    LCDtop.write(B00000001);
    LCDtop.write(B00001001);
    LCDtop.write(B00010010);
    LCDtop.write(B00011000);
    
    LCDtop.write(x);
    LCDtop.write(6);

}


void cloudSeven_top(int x){

    LCDtop.write(0xFF); //take in custom char
    
    LCDtop.write(zero); 
    LCDtop.write(zero);
    LCDtop.write(zero);
    LCDtop.write(zero);
    LCDtop.write(zero);
    LCDtop.write(zero);
    LCDtop.write(zero);
    LCDtop.write(zero);
    
    LCDtop.write(x);
    LCDtop.write(7);

}



////////////  8 custom charcters for Middle screen - TREEE TOP////////////////


void treeZero_mid(int x){

    LCDmid.write(0xF8); //take in custom char
    
    LCDmid.write(zero); 
    LCDmid.write(zero);
    LCDmid.write(zero);
    LCDmid.write(B00000001);
    LCDmid.write(B00000001);
    LCDmid.write(B00000001);
    LCDmid.write(B00000011);
    LCDmid.write(B00000010);
    
    
    LCDmid.write(x);
    LCDmid.write(zero);

}

void treeOne_mid(int x){

    LCDmid.write(0xF9); //take in custom char
    
    LCDmid.write(zero); 
    LCDmid.write(zero);
    LCDmid.write(B00010000);
    LCDmid.write(B00010000);
    LCDmid.write(B00010000);
    LCDmid.write(B00011000);
    LCDmid.write(B00011000);
    LCDmid.write(B00011000);
    LCDmid.write(x);
    LCDmid.write(1);

}

void treeTwo_mid(int x){

LCDmid.write(0xFA); //take in custom char

LCDmid.write(zero); 
LCDmid.write(zero);
LCDmid.write(zero); 
LCDmid.write(zero);
LCDmid.write(zero); 
LCDmid.write(zero);
LCDmid.write(B00000001);
LCDmid.write(B00000001);
LCDmid.write(x);
LCDmid.write(2);

}

void treeThree_mid(int x){

LCDmid.write(0xFB); //take in custom char

LCDmid.write(B00000010); 
LCDmid.write(B00000110);
LCDmid.write(B00001100);
LCDmid.write(B00011000);
LCDmid.write(B00010000);
LCDmid.write(B00010000);
LCDmid.write(B00000001);
LCDmid.write(B00000001);
LCDmid.write(x);
LCDmid.write(3);

}

void treeFour_mid(int x){

LCDmid.write(0xFC); //take in custom char

LCDmid.write(B00011100); 
LCDmid.write(B00000100);
LCDmid.write(B00000100);
LCDmid.write(B00000110);
LCDmid.write(B00000010);
LCDmid.write(B00000110);
LCDmid.write(B00000010);
LCDmid.write(B00000011);
LCDmid.write(x);
LCDmid.write(4);

}

void moonOne_mid(int x){

  LCDmid.write(0xFD); //take in custom char
  
  LCDmid.write(zero); 
  LCDmid.write(B00000011);
  LCDmid.write(B00000110);
  LCDmid.write(B00001100);
  LCDmid.write(B00001100);
  LCDmid.write(B00011100);
  LCDmid.write(B00011100);
  LCDmid.write(B00011100);
  LCDmid.write(x);
  LCDmid.write(5);

}

void moonTwo_mid(int x){

    LCDmid.write(0xFE); //take in custom char
    
    LCDmid.write(B00001100);
    LCDmid.write(B00000110);
    LCDmid.write(B00010011);
    LCDmid.write(B00011001);
    LCDmid.write(B00001111);
    LCDmid.write(B00000001);
    LCDmid.write(zero);
    LCDmid.write(zero);
    LCDmid.write(x);
    LCDmid.write(6);

}

void moonThree_mid(int x){

    LCDmid.write(0xFF); //take in custom char
    
    LCDmid.write(zero);
    LCDmid.write(zero);
    LCDmid.write(zero);
    LCDmid.write(B00010011);
    LCDmid.write(B00011110);
    LCDmid.write(B00011100);
    LCDmid.write(B00011000);
    LCDmid.write(zero);
    LCDmid.write(x);
    LCDmid.write(7);

}


///////////////// 8 custom characters for bottom screen - GRASS & TREES///////


void treeZero_bot(int x){

LCDbot.write(0xF8); //take in custom char

    LCDbot.write(B00000001); 
    LCDbot.write(B00000011);
    LCDbot.write(B00000110); 
    LCDbot.write(B00001100);
    LCDbot.write(B00011000); 
    LCDbot.write(B00011111);
    LCDbot.write(B00001100); 
    LCDbot.write(zero);
    
    LCDbot.write(x);
    LCDbot.write(zero);

}

void treeOne_bot(int x){

    LCDbot.write(0xF9); //take in custom char
    
    LCDbot.write(zero); 
    LCDbot.write(B00000110);
    LCDbot.write(B00001100); 
    LCDbot.write(B00001000);
    LCDbot.write(zero); 
    LCDbot.write(zero);
    LCDbot.write(B00011111); 
    LCDbot.write(B00000011);
    
    LCDbot.write(x);
    LCDbot.write(1);

}

void treeTwo_bot(int x){

    LCDbot.write(0xFA); //take in custom char
    
    LCDbot.write(zero); 
    LCDbot.write(zero);
    LCDbot.write(B00000100); 
    LCDbot.write(B00001100);
    LCDbot.write(B00001000); 
    LCDbot.write(zero);
    LCDbot.write(B00011111); 
    LCDbot.write(B00010000);
    LCDbot.write(x);
    LCDbot.write(2);

}

void treeThree_bot(int x){

    LCDbot.write(0xFB); //take in custom char
    
    LCDbot.write(B00000011); 
    LCDbot.write(B00000011);
    LCDbot.write(B00000011); 
    LCDbot.write(B00000011);
    LCDbot.write(B00000011); 
    LCDbot.write(B00010011);
    LCDbot.write(B00010111); 
    LCDbot.write(B00011111);
    
    LCDbot.write(x);
    LCDbot.write(3);

}


void treeFour_bot(int x){

    LCDbot.write(0xFC); //take in custom char
    
    LCDbot.write(B00010000); 
    LCDbot.write(B00010000);
    LCDbot.write(B00010000); 
    LCDbot.write(B00010000);
    LCDbot.write(B00010000); 
    LCDbot.write(B00010010);
    LCDbot.write(B00011110); 
    LCDbot.write(B00011111);
    
    LCDbot.write(x);
    LCDbot.write(4);

}


void grassOne_bot(int x){

    LCDbot.write(0xFD); //take in custom char
    
    LCDbot.write(zero); 
    LCDbot.write(zero);
    LCDbot.write(zero); 
    LCDbot.write(B00010000);
    LCDbot.write(B00010000); 
    LCDbot.write(B00010100);
    LCDbot.write(B00011101); 
    LCDbot.write(B00011111);
    LCDbot.write(x);
    LCDbot.write(5);

}

void grassTwo_bot(int x){

    LCDbot.write(0xFE); //take in custom char
    
    LCDbot.write(zero); 
    LCDbot.write(zero);
    LCDbot.write(zero); 
    LCDbot.write(B00000100);
    LCDbot.write(B00000100); 
    LCDbot.write(B00001110);
    LCDbot.write(B00001111); 
    LCDbot.write(B00011111);
    LCDbot.write(x);
    LCDbot.write(6);

}

void grassThree_bot(int x){

    LCDbot.write(0xFF); //take in custom char
    
    LCDbot.write(zero); 
    LCDbot.write(zero);
    LCDbot.write(zero); 
    LCDbot.write(B00000010);
    LCDbot.write(B00001010); 
    LCDbot.write(B00011011);
    LCDbot.write(B00011111); 
    LCDbot.write(B00011111);
    LCDbot.write(x);
    LCDbot.write(7);

}
///////////////////////MUUUUUUUUSSSSSSSSSIIIIIIIICCCCCCCC
void let_the_music_play() {
      //MUSIC STARTS//
     
    LCDtop.write(211);
    
     
    ////Bar one**********************
    //LCDtop.write(trd);
    //LCDtop.write(G);
    //LCDtop.write(frt);
    //LCDtop.write(C);
    //LCDtop.write(Ds);
    //LCDtop.write(232);
    //
    ////LCDmid.write(214);
    ////LCDmid.write(frt);
    ////LCDmid.write(C);
    ////LCDbot.write(214);
    ////LCDbot.write(trd);
    ////LCDbot.write(C);
    //
    //LCDtop.write(trd);
    //LCDtop.write(G);
    //LCDtop.write(frt);
    //LCDtop.write(C);
    //LCDtop.write(Ds);
    //LCDtop.write(232);
    //
    ////LCDmid.write(214);
    ////LCDmid.write(C);
    ////LCDbot.write(214);
    ////LCDbot.write(C);
    //
    //
    //LCDtop.write(trd);
    //LCDtop.write(G);
    //LCDtop.write(frt);
    //LCDtop.write(C);
    //LCDtop.write(Ds);
    //LCDtop.write(232);
    //
    ////LCDmid.write(214);
    ////LCDmid.write(C);
    ////LCDbot.write(214);
    ////LCDbot.write(C);
    //
    //LCDtop.write(trd);
    //LCDtop.write(G);
    //LCDtop.write(frt);
    //LCDtop.write(C);
    //LCDtop.write(Ds);
    //LCDtop.write(232);
    //
    ////LCDmid.write(214);
    ////LCDmid.write(C);
    ////LCDbot.write(214);
    ////LCDbot.write(C);
    
    //////Bar Two **************
    
    //LCDtop.write(trd);
    //LCDtop.write(G);
    //LCDtop.write(frt);
    //LCDtop.write(C);
    //LCDtop.write(Ds);
    //LCDtop.write(232);
    //
    //LCDtop.write(trd);
    //LCDtop.write(G);
    //LCDtop.write(frt);
    //LCDtop.write(C);
    //LCDtop.write(Ds);
    //LCDtop.write(232);
    
    //LCDtop.write(trd);
    //LCDtop.write(G);
    //LCDtop.write(frt);
    //LCDtop.write(C);
    //LCDtop.write(Ds);
    //LCDtop.write(232);
    //
    //LCDtop.write(trd);
    //LCDtop.write(G);
    //LCDtop.write(frt);
    //LCDtop.write(C);
    //LCDtop.write(Ds);
    //LCDtop.write(232);
    
    //BAR threeeeee ***************
    
    LCDtop.write(trd);
    LCDtop.write(Gs);
    LCDtop.write(frt);
    LCDtop.write(C);
    LCDtop.write(Ds);
    LCDtop.write(232);
    
    LCDtop.write(trd);
    LCDtop.write(Gs);
    LCDtop.write(frt);
    LCDtop.write(C);
    LCDtop.write(Ds);
    LCDtop.write(232);
    
    LCDtop.write(trd);
    LCDtop.write(Gs);
    LCDtop.write(frt);
    LCDtop.write(Cs);
    LCDtop.write(F);
    LCDtop.write(232);
    
    LCDtop.write(trd);
    LCDtop.write(Gs);
    LCDtop.write(frt);
    LCDtop.write(Cs);
    LCDtop.write(F);
    LCDtop.write(232);
    
    //BAR FOUR *****************
    
    LCDtop.write(trd);
    LCDtop.write(G);
    LCDtop.write(frt);
    LCDtop.write(B);
    LCDtop.write(F);
    LCDtop.write(232);
    
    LCDtop.write(trd);
    LCDtop.write(G);
    LCDtop.write(frt);
    LCDtop.write(B);
    LCDtop.write(Ds);
    LCDtop.write(232);
    
    LCDtop.write(trd);
    LCDtop.write(G);
    LCDtop.write(frt);
    LCDtop.write(B);
    LCDtop.write(D);
    LCDtop.write(232);
    
    //LCDtop.write(trd);
    //LCDtop.write(F);
    //LCDtop.write(frt);
    //LCDtop.write(B);
    //LCDtop.write(D);
    //LCDtop.write(232);
    
    //BAR FIVE ***************
    
    LCDtop.write(trd);
    LCDtop.write(G);
    LCDtop.write(frt);
    LCDtop.write(C);
    LCDtop.write(Ds);
    LCDtop.write(232);
    
    LCDtop.write(trd);
    LCDtop.write(G);
    LCDtop.write(frt);
    LCDtop.write(C);
    LCDtop.write(Ds);
    LCDtop.write(232);
    
    LCDtop.write(trd);
    LCDtop.write(G);
    LCDtop.write(frt);
    LCDtop.write(C);
    LCDtop.write(Ds);
    LCDtop.write(232);
    
    LCDtop.write(212);
    LCDtop.write(frt);
    LCDtop.write(G);
    
    LCDtop.write(211);
    LCDtop.write(G);
    //MAY NEED TO PUT REST HERE!!!!
    
    //BAR frt ***********
    LCDtop.write(frt);
    LCDtop.write(G);
    LCDtop.write(B);
    LCDtop.write(D);
    LCDtop.write(232);
    
    LCDtop.write(trd);
    LCDtop.write(G);
    LCDtop.write(frt);
    LCDtop.write(B);
    LCDtop.write(D);
    LCDtop.write(232);
    
    LCDtop.write(trd);
    LCDtop.write(G);
    LCDtop.write(frt);
    LCDtop.write(B);
    LCDtop.write(D);
    LCDtop.write(232);
    
    LCDtop.write(212);
    LCDtop.write(frt);
    LCDtop.write(G);
    
    LCDtop.write(211);
    LCDtop.write(G);
    //MAY NEED TO PUT REST HERE!!!!
    
    //BAR SEVEN *****************
    LCDtop.write(frt);
    LCDtop.write(G);
    LCDtop.write(C);
    LCDtop.write(Ds);
    LCDtop.write(232);
    
    LCDtop.write(trd);
    LCDtop.write(G);
    LCDtop.write(frt);
    LCDtop.write(C);
    LCDtop.write(Ds);
    LCDtop.write(232);
    
    LCDtop.write(trd);
    LCDtop.write(Gs);
    LCDtop.write(frt);
    LCDtop.write(C);
    LCDtop.write(F);
    LCDtop.write(232);
    
    LCDtop.write(trd);
    LCDtop.write(Gs);
    LCDtop.write(frt);
    LCDtop.write(C);
    LCDtop.write(F);
    LCDtop.write(232);
    
    //BAR EIGHT *****************
    LCDtop.write(trd);
    LCDtop.write(G);
    LCDtop.write(frt);
    LCDtop.write(As);
    LCDtop.write(Ds);
    LCDtop.write(232);
    
    LCDtop.write(trd);
    LCDtop.write(G);
    LCDtop.write(frt);
    LCDtop.write(As);
    LCDtop.write(Ds);
    LCDtop.write(232);
    
    LCDtop.write(trd);
    LCDtop.write(Gs);
    LCDtop.write(frt);
    LCDtop.write(As);
    LCDtop.write(D);
    LCDtop.write(232);
    
    LCDtop.write(trd);
    LCDtop.write(Gs);
    LCDtop.write(frt);
    LCDtop.write(As);
    LCDtop.write(D);
    LCDtop.write(232);
    
    ///BAR NINE IE THE MO FO END
    LCDtop.write(214);
    //LCDmid.write(214);
    //LCDbot.write(214);
    LCDtop.write(trd);
    LCDtop.write(Ds);
    //LCDmid.write(frt);
    //LCDmid.write(As);
    //LCDbot.write(trd);
    //LCDbot.write(G);

}



