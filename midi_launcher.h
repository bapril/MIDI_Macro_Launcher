#define RED {255,0,0}
#define ORANGE {255,0x80,0}
#define YELLOW {255,255,0}
#define GREEN {0,0x80,0}
#define AQUA {0,255,255}
#define TEAL {0,0x80,0x80}
#define BLUE {0,0,255}
#define PURPLE {0x80, 0, 0x80}


typedef struct {
  byte r;    // red value 0 to 4095
  byte g;   // green value
  byte b;   // blue value
} rgbcolor;

int channel = 0;
int first_note = 0;
int mode = MACRO;

rgbcolor colors[8][128];
rgbcolor banksel[8];

int banksize = 8;

void init_banksel(){
  banksel[0] = RED;
  banksel[1] = ORANGE;
  banksel[2] = YELLOW;
  banksel[3] = GREEN;
  banksel[4] = TEAL;
  banksel[5] = AQUA;
  banksel[6] = BLUE;
  banksel[7] = PURPLE;
}

void init_page_0(){ //Main
  colors[0][0] = {25,25,25}; //Desktop 1
  colors[0][1] = {50,50,50}; //Desktop 2
  colors[0][2] = {75,75,75}; //Desktop 3
  colors[0][3] = {100,100,100}; //Desktop 4
  colors[0][4] = {125,125,125}; //Desktop 5
  colors[0][5] = {0,0,0};
  colors[0][6] = {0,0,0};
  colors[0][7] = {0,0,0};

  colors[0][8] = {50,25,25}; //Desktop 1
  colors[0][9] = {75,50,50}; //Desktop 2
  colors[0][10] = {100,75,75}; //Desktop 3
  colors[0][11] = {125,100,100}; //Desktop 4
  colors[0][12] = {150,125,125}; //Desktop 5
  colors[0][13] = {0,0,0};
  colors[0][14] = {0,0,0};
  colors[0][15] = {50,50,25}; //github.com

  colors[0][16] = {0,5,50}; //MS word Focus
  colors[0][17] = {0,0,0};
  colors[0][18] = {0,0,0};
  colors[0][19] = {0,0,0};
  colors[0][20] = {0,0,0};
  colors[0][21] = {0,0,0};
  colors[0][22] = {50,25,50}; //Exp
  colors[0][23] = {25,50,25}; //bill

  colors[0][24] = {25,25,25}; //Lock Screen
  colors[0][25] = {25,50,25}; //Eject
  colors[0][26] = {0,0,0};
  colors[0][27] = {0,0,0};
  colors[0][28] = {0,0,0};
  colors[0][29] = {0,0,0};
  colors[0][30] = {0,0,0};
}

void init_page_1(){
  colors[1][0] = {0,0,0};
  colors[1][1] = {0,0,0};
  colors[1][2] = {0,0,0};
  colors[1][3] = {0,0,0};
  colors[1][4] = {0,0,0};
  colors[1][5] = {0,0,0};
  colors[1][6] = {0,0,0};
  colors[1][7] = {0,0,0};

  colors[1][8] = {0,0,0};
  colors[1][9] = {0,0,0};
  colors[1][10] = {0,0,0};
  colors[1][11] = {0,0,0};
  colors[1][12] = {0,0,0};
  colors[1][13] = {0,0,0};
  colors[1][14] = {0,0,0};
  colors[1][15] = {0,0,0};

  colors[1][16] = {0,0,0};
  colors[1][17] = {0,0,0};
  colors[1][18] = {0,0,0};
  colors[1][19] = {0,0,0};
  colors[1][20] = {0,0,0};
  colors[1][21] = {0,0,0};
  colors[1][22] = {0,0,0};
  colors[1][23] = {0,0,0};

  colors[1][24] = {0,0,0};
  colors[1][25] = {0,0,0};
  colors[1][26] = {0,0,0};
  colors[1][27] = {0,0,0};
  colors[1][28] = {0,0,0};
  colors[1][29] = {0,0,0};
  colors[1][30] = {0,0,0};
}

void init_page_2(){
  colors[2][0] = {0,0,0};
  colors[2][1] = {0,0,0};
  colors[2][2] = {0,0,0};
  colors[2][3] = {0,0,0};
  colors[2][4] = {0,0,0};
  colors[2][5] = {0,0,0};
  colors[2][6] = {0,0,0};
  colors[2][7] = {0,0,0};

  colors[2][8] = {0,0,0};
  colors[2][9] = {0,0,0};
  colors[2][10] = {0,0,0};
  colors[2][11] = {0,0,0};
  colors[2][12] = {0,0,0};
  colors[2][13] = {0,0,0};
  colors[2][14] = {0,0,0};
  colors[2][15] = {0,0,0};

  colors[2][16] = {0,0,0};
  colors[2][17] = {0,0,0};
  colors[2][18] = {0,0,0};
  colors[2][19] = {0,0,0};
  colors[2][20] = {0,0,0};
  colors[2][21] = {0,0,0};
  colors[2][22] = {0,0,0};
  colors[2][23] = {0,0,0};

  colors[2][24] = {0,0,0};
  colors[2][25] = {0,0,0};
  colors[2][26] = {0,0,0};
  colors[2][27] = {0,0,0};
  colors[2][28] = {0,0,0};
  colors[2][29] = {0,0,0};
  colors[2][30] = {0,0,0};
}

void init_page_3(){
  colors[3][0] = {0,0,0};
  colors[3][1] = {0,0,0};
  colors[3][2] = {0,0,0};
  colors[3][3] = {0,0,0};
  colors[3][4] = {0,0,0};
  colors[3][5] = {0,0,0};
  colors[3][6] = {0,0,0};
  colors[3][7] = {0,0,0};

  colors[3][8] = {0,0,0};
  colors[3][9] = {0,0,0};
  colors[3][10] = {0,0,0};
  colors[3][11] = {0,0,0};
  colors[3][12] = {0,0,0};
  colors[3][13] = {0,0,0};
  colors[3][14] = {0,0,0};
  colors[3][15] = {0,0,0};

  colors[3][16] = {0,0,0};
  colors[3][17] = {0,0,0};
  colors[3][18] = {0,0,0};
  colors[3][19] = {0,0,0};
  colors[3][20] = {0,0,0};
  colors[3][21] = {0,0,0};
  colors[3][22] = {0,0,0};
  colors[3][23] = {0,0,0};

  colors[3][24] = {0,0,0};
  colors[3][25] = {0,0,0};
  colors[3][26] = {0,0,0};
  colors[3][27] = {0,0,0};
  colors[3][28] = {0,0,0};
  colors[3][29] = {0,0,0};
  colors[3][30] = {0,0,0};
}


void init_page_4(){ //Email
  colors[4][0] = RED; // Red Tag
  colors[4][1] = ORANGE; // Orange Tag
  colors[4][2] = PURPLE; // Set Purple
  colors[4][3] = {0,0,2}; // Clear tag
  colors[4][4] = {0,0,0};
  colors[4][5] = {255,0,0}; //Delete
  colors[4][6] = {0,0,0};
  colors[4][7] = {25,0,255}; // Dark/Light

  colors[4][8] = RED; // Red Tag
  colors[4][9] = ORANGE; // Orange Tag
  colors[4][10] = PURPLE; // Set Purple
  colors[4][11] = {0,0,0};
  colors[4][12] = {0,0,0};
  colors[4][13] = {0,0,0};
  colors[4][14] = {0,0,0};
  colors[4][15] = {0,0,0};

  colors[4][16] = {0,15,0x80}; //Mark message read
  colors[4][17] = {0,0,0};
  colors[4][18] = {0,0,0};
  colors[4][19] = {0,0,0};
  colors[4][20] = {0,0,0};
  colors[4][21] = {0,0,0};
  colors[4][22] = {0,0,0};
  colors[4][23] = {0,0,0};

  colors[4][24] = {0,25,255}; // Unread All
  colors[4][25] = {0,0,0};
  colors[4][26] = {0,0,0};
  colors[4][27] = {0,0,0};
  colors[4][28] = {0,0,0};
  colors[4][29] = {0,0,0};
  colors[4][30] = {0,0,0};

}

 void init_page_5(){
  colors[5][0] = {0,0,0};
  colors[5][1] = {0,0,0};
  colors[5][2] = {0,0,0};
  colors[5][3] = {0,0,0};
  colors[5][4] = {0,0,0};
  colors[5][5] = {0,0,0};
  colors[5][6] = {0,0,0};
  colors[5][7] = {0,0,0};

  colors[5][8] = {0,0,0};
  colors[5][9] = {0,0,0};
  colors[5][10] = {0,0,0};
  colors[5][11] = {0,0,0};
  colors[5][12] = {0,0,0};
  colors[5][13] = {0,0,0};
  colors[5][14] = {0,0,0};
  colors[5][15] = {0,0,0};

  colors[5][16] = {0,0,0};
  colors[5][17] = {0,0,0};
  colors[5][18] = {0,0,0};
  colors[5][19] = {0,0,0};
  colors[5][20] = {0,0,0};
  colors[5][21] = {0,0,0};
  colors[5][22] = {0,0,0};
  colors[5][23] = {0,0,0};

  colors[5][24] = {0,0,0};
  colors[5][25] = {0,0,0};
  colors[5][26] = {0,0,0};
  colors[5][27] = {0,0,0};
  colors[5][28] = {0,0,0};
  colors[5][29] = {0,0,0};
  colors[5][30] = {0,0,0};
 }

void init_page_6(){
  colors[6][0] = {0,0,0};
  colors[6][1] = {0,0,0};
  colors[6][2] = {0,0,0};
  colors[6][3] = {0,0,0};
  colors[6][4] = {0,0,0};
  colors[6][5] = {0,0,0};
  colors[6][6] = {0,0,0};
  colors[6][7] = {0,0,0};

  colors[6][8] = {0,0,0};
  colors[6][9] = {0,0,0};
  colors[6][10] = {0,0,0};
  colors[6][11] = {0,0,0};
  colors[6][12] = {0,0,0};
  colors[6][13] = {0,0,0};
  colors[6][14] = {0,0,0};
  colors[6][15] = {0,0,0};

  colors[6][16] = {0,0,0};
  colors[6][17] = {0,0,0};
  colors[6][18] = {0,0,0};
  colors[6][19] = {0,0,0};
  colors[6][20] = {0,0,0};
  colors[6][21] = {0,0,0};
  colors[6][22] = {0,0,0};
  colors[6][23] = {0,0,0};

  colors[6][24] = {0,0,0};
  colors[6][25] = {0,0,0};
  colors[6][26] = {0,0,0};
  colors[6][27] = {0,0,0};
  colors[6][28] = {0,0,0};
  colors[6][29] = {0,0,0};
  colors[6][30] = {0,0,0};
}

void init_page_7(){
  colors[7][0] = {0,0,0};
  colors[7][1] = {0,0,0};
  colors[7][2] = {0,0,0};
  colors[7][3] = {0,0,0};
  colors[7][4] = {0,0,0};
  colors[7][5] = {0,0,0};
  colors[7][6] = {0,0,0};
  colors[7][7] = {0,0,0};

  colors[7][8] = {0,0,0};
  colors[7][9] = {0,0,0};
  colors[7][10] = {0,0,0};
  colors[7][11] = {0,0,0};
  colors[7][12] = {0,0,0};
  colors[7][13] = {0,0,0};
  colors[7][14] = {0,0,0};
  colors[7][15] = {0,0,0};

  colors[7][16] = {0,0,0};
  colors[7][17] = {0,0,0};
  colors[7][18] = {0,0,0};
  colors[7][19] = {0,0,0};
  colors[7][20] = {0,0,0};
  colors[7][21] = {0,0,0};
  colors[7][22] = {0,0,0};
  colors[7][23] = {0,0,0};

  colors[7][24] = {0,0,0};
  colors[7][25] = {0,0,0};
  colors[7][26] = {0,0,0};
  colors[7][27] = {0,0,0};
  colors[7][28] = {0,0,0};
  colors[7][29] = {0,0,0};
  colors[7][30] = {0,0,0};
}

void init_pages(){
  init_page_0();
  init_page_1();
  init_page_2();
  init_page_3();
  init_page_4();
  init_page_5();
  init_page_6();
  init_page_7();
}
