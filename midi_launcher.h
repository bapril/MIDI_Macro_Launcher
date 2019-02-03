#define C_RED {255,0,0}
#define C_ORANGE {255,0x80,0}
#define C_YELLOW {255,255,0}
#define C_GREEN {0,0x80,0}
#define C_AQUA {0,255,255}
#define C_TEAL {0,0x60,0x80}
#define C_BLUE {0,0,255}
#define C_PURPLE {0x80, 0, 0x80}
#define C_LT_RED {0x80,0,0}
#define C_LT_ORANGE {0x80,0x40,0}
#define C_LT_YELLOW {0x80,0x80,0}
#define C_LT_GREEN {0,0x40,0}
#define C_LT_AQUA {0,0x80,0x80}
#define C_LT_TEAL {0,0x30,0x40}
#define C_LT_BLUE {0,0,0x80}
#define C_LT_PURPLE {0x40, 0, 0x40}
#define C_OFF {0,0,0}

typedef struct {
  byte r;    // red value 0 to 255
  byte g;   // green value
  byte b;   // blue value
} str_rgbcolor;

typedef struct {
  bool   active;
  byte   channel;
  byte   note;
  str_rgbcolor color;
} str_btn;

str_btn button_set[31][31];
str_rgbcolor banksel[31];

void init_banksel(){
  banksel[0] = C_RED;
  banksel[1] = C_ORANGE;
  banksel[2] = C_YELLOW;
  banksel[3] = C_GREEN;
  banksel[4] = C_TEAL;
  banksel[5] = C_AQUA;
  banksel[6] = C_BLUE;
  banksel[7] = C_PURPLE;
  banksel[8] = C_LT_RED;
  banksel[9] = C_LT_ORANGE;
  banksel[10] = C_LT_YELLOW;
  banksel[11] = C_LT_GREEN;
  banksel[12] = C_LT_TEAL;
  banksel[13] = C_LT_AQUA;
  banksel[14] = C_LT_BLUE;
  banksel[15] = C_LT_PURPLE;
}

void init_page_main(byte page){ //Main
  byte channel = page;
  button_set[page][0] = {true,channel,0,{25,25,25}}; //Desktop 1
  button_set[page][1] = {true,channel,1,{50,50,50}}; //Desktop 2
  button_set[page][2] = {true,channel,2,{75,75,75}}; //Desktop 3
  button_set[page][3] = {true,channel,3,{100,100,100}}; //Desktop 4
  button_set[page][4] = {true,channel,4,{125,125,125}}; //Desktop 5
  button_set[page][5] = {false,channel,5,C_OFF};
  button_set[page][6] = {false,channel,6,C_OFF};
  button_set[page][7] = {false,channel,7,C_OFF};

  button_set[page][8] = {true,channel,8,{50,25,25}}; //Desktop 1
  button_set[page][9] = {true,channel,9,{75,50,50}}; //Desktop 2
  button_set[page][10] = {true,channel,10,{100,75,75}}; //Desktop 3
  button_set[page][11] = {true,channel,11,{125,100,100}}; //Desktop 4
  button_set[page][12] = {true,channel,12,{150,125,125}}; //Desktop 5
  button_set[page][13] = {false,channel,13,C_OFF};
  button_set[page][14] = {false,channel,14,C_OFF};
  button_set[page][15] = {true,channel,15,{50,50,25}}; //github.com

  button_set[page][16] = {true,channel,16,{0,5,50}}; //MS word Focus
  button_set[page][17] = {false,channel,17,C_OFF};
  button_set[page][18] = {false,channel,18,C_OFF};
  button_set[page][19] = {false,channel,19,C_OFF};
  button_set[page][20] = {false,channel,20,C_OFF};
  button_set[page][21] = {false,channel,21,C_OFF};
  button_set[page][22] = {true,channel,22,{50,25,50}}; //Exp
  button_set[page][23] = {true,channel,23,{25,50,25}}; //bill

  button_set[page][24] = {true,channel,24,{25,25,25}}; //Lock Screen
  button_set[page][25] = {true,channel,25,{25,50,25}}; //Eject
  button_set[page][26] = {false,channel,26,C_OFF};
  button_set[page][27] = {false,channel,27,C_OFF};
  button_set[page][28] = {false,channel,28,C_OFF};
  button_set[page][29] = {false,channel,29,C_OFF};
  button_set[page][30] = {true,channel,30,{10,10,10}}; // Programming Button.
}

//populate a page with no lights or midi commands.
void init_page_empty(byte page){
  for (byte i = 0; i < 31; i++){
    button_set[page][i] = {false,0,0,C_OFF};
  }
}

//populate a page with no lights, but 31 MIDI keys.
void init_page_blank(byte page, byte channel, byte first_note){
  for (byte i = 0; i < 31; i++){
    button_set[page][i] = {true,channel,(byte)((int)first_note + (int)i),C_OFF};
  }
}

void init_page_email(byte page){ //Email
  byte channel = page;
  button_set[page][0] = {true,channel,0,C_RED}; // Red Tag
  button_set[page][1] = {true,channel,1,C_ORANGE}; // Orange Tag
  button_set[page][2] = {true,channel,2,C_PURPLE}; // Set Purple
  button_set[page][3] = {true,channel,3,{0,0,5}}; // Clear tag
  button_set[page][4] = {false,channel,4,C_OFF};
  button_set[page][5] = {true,channel,5,{255,0,0}}; //Delete
  button_set[page][6] = {false,channel,5,C_OFF};
  button_set[page][7] = {true,channel,7,{25,0,255}}; // Dark/Light

  button_set[page][8] = {true,channel,8,C_RED}; // Red Tag
  button_set[page][9] = {true,channel,9,C_ORANGE}; // Orange Tag
  button_set[page][10] = {true,channel,10,C_PURPLE}; // Set Purple
  button_set[page][11] = {false,0,11,C_OFF};
  button_set[page][12] = {false,0,12,C_OFF};
  button_set[page][13] = {false,0,13,C_OFF};
  button_set[page][14] = {false,0,14,C_OFF};
  button_set[page][15] = {false,0,15,C_OFF};

  button_set[page][16] = {true,channel,16,{0,15,0x80}}; //Mark message read
  button_set[page][17] = {false,0,17,C_OFF};
  button_set[page][18] = {false,0,18,C_OFF};
  button_set[page][19] = {false,0,19,C_OFF};
  button_set[page][20] = {false,0,20,C_OFF};
  button_set[page][21] = {false,0,21,C_OFF};
  button_set[page][22] = {false,0,22,C_OFF};
  button_set[page][23] = {false,0,23,C_OFF};

  button_set[page][24] = {true,channel,24,{0,25,255}}; // Unread All
  button_set[page][25] = {false,0,25,C_OFF};
  button_set[page][26] = {false,0,26,C_OFF};
  button_set[page][27] = {false,0,27,C_OFF};
  button_set[page][28] = {false,0,28,C_OFF};
  button_set[page][29] = {false,0,29,C_OFF};
  button_set[page][30] = {false,0,30,C_OFF};
}

//Template: copy/rename this function and build your own pages.
void init_page_template(byte page,byte channel){
  button_set[page][0] = {true,channel,0,C_OFF};
  button_set[page][1] = {true,channel,1,C_OFF};
  button_set[page][2] = {true,channel,2,C_OFF};
  button_set[page][3] = {true,channel,3,C_OFF};
  button_set[page][4] = {true,channel,4,C_OFF};
  button_set[page][5] = {true,channel,5,C_OFF};
  button_set[page][6] = {true,channel,5,C_OFF};
  button_set[page][7] = {true,channel,7,C_OFF};

  button_set[page][8] = {true,channel,8,C_OFF};
  button_set[page][9] = {true,channel,9,C_OFF};
  button_set[page][10] = {true,channel,10,C_OFF};
  button_set[page][11] = {true,channel,11,C_OFF};
  button_set[page][12] = {true,channel,12,C_OFF};
  button_set[page][13] = {true,channel,13,C_OFF};
  button_set[page][14] = {true,channel,14,C_OFF};
  button_set[page][15] = {true,channel,15,C_OFF};

  button_set[page][16] = {true,channel,16,C_OFF};
  button_set[page][17] = {true,channel,17,C_OFF};
  button_set[page][18] = {true,channel,18,C_OFF};
  button_set[page][19] = {true,channel,19,C_OFF};
  button_set[page][20] = {true,channel,20,C_OFF};
  button_set[page][21] = {true,channel,21,C_OFF};
  button_set[page][22] = {true,channel,22,C_OFF};
  button_set[page][23] = {true,channel,23,C_OFF};

  button_set[page][24] = {true,channel,24,C_OFF};
  button_set[page][25] = {true,channel,25,C_OFF};
  button_set[page][26] = {true,channel,26,C_OFF};
  button_set[page][27] = {true,channel,27,C_OFF};
  button_set[page][28] = {true,channel,28,C_OFF};
  button_set[page][29] = {true,channel,29,C_OFF};
  button_set[page][30] = {true,channel,30,C_OFF};
}

void init_pages(){
  init_page_main(0);
  init_page_blank(1,1,0);
  init_page_template(2,2);
  init_page_empty(3);
  init_page_email(4);
  for(int i = 5; i < 16; i++){
    init_page_empty(i);
  }
}
