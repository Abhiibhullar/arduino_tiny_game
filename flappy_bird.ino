#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <SPI.h>

// TFT_Pinout
#define TFT_CS 10
#define TFT_RST 9
#define TFT_DC 8

// Buttons pins
int button_pin = 2;

// Bird(circle)
int bY = 110;
int bX = 50;
int radius = 10;
// Pillar(rect)
int pX = 240;
int pY = 100;
int pillarDistance = 60;
// Global Game State
int movingRate = 3;
int score = 0;
int gameStarted = false;
int lastSpeedUpScore = 0;
int fallRateInt = 0;
float fallRate = 0;

// Display Initialization
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

// function Init
void initiateGame();

void setup(){
    Serial.begin(9600);
    pinMode(button_pin, INPUT);
    tft.init(240, 240);
    tft.setRotation(2);
    tft.fillScreen(ST77XX_CYAN);
    initiateGame();
}

void loop(){
    pX = pX - movingRate;
    drawPillar(pX, pY);
    bY+=fallRateInt;
    fallRate=fallRate+0.2;
    fallRateInt=int(fallRate);
    // UP and Down
    if(bY >= 210 - radius + 3|| bY <= radius + 1){
        gameOver();
    } 
    // upper piller
    if(pX <= 50 && pX >= 5 && bY <= pY){
        gameOver();
    }
    if(pX <= 50 && pX >= 5 && bY >= pY + pillarDistance){
        gameOver();
    }
    if(digitalRead(button_pin) == HIGH){
        fallRate = -4;
    }
    if(pX <= -40){
        pX = 240;
        pY = random(20, 120);
        score++;
        tft.setFont(&FreeMonoBold12pt7b);
        tft.fillRect(110, 210, 50, 50, ST77XX_ORANGE);
        tft.setTextColor(ST77XX_YELLOW);
        tft.setCursor(110, 230);
        tft.print(score);
    }
    drawBird(bY);
    if((score - lastSpeedUpScore) == 5){
        lastSpeedUpScore = score;
        movingRate++;
    }
}

// Function for Init game.
void initiateGame(){
    tft.fillScreen(ST77XX_CYAN);
    // UI
    tft.fillRect(0, 210, 240, 30, ST77XX_ORANGE);
    tft.setFont(&FreeMonoBold12pt7b);
    tft.setCursor(12, 230);
    tft.setTextColor(ST77XX_YELLOW);
    tft.print("Score: ");
    tft.print(score);
    tft.setFont(&FreeMonoBold9pt7b);
    drawBird(bY);
    tft.setCursor(40,126);
    tft.setTextColor(ST77XX_BLACK);
    tft.print("PRESS TO START");
    while(!gameStarted){
        if(digitalRead(button_pin) == HIGH){
            tft.fillRect(35, 100, 170, 50, ST77XX_CYAN);
            gameStarted = true;
        }
    }
}

// Drawing Circle(Bird) to the screen.
void drawBird(int y){
    if(y + radius >= 210 - (radius * 2)){
        tft.fillRect(bX - radius, y - radius - (radius * 2), (radius * 2) + 1, radius * 2, ST77XX_CYAN);
    }
    else if(pX <= 50 && pX >= 5 && bY - pY <= radius * 2){
        tft.fillRect(bX - radius, y + radius , (radius * 2) + 1 , radius * 2, ST77XX_CYAN);
    }
    else{
        tft.fillRect(bX - radius, y - radius - (radius * 2), (radius * 2) + 1, radius * 2, ST77XX_CYAN);
        tft.fillRect(bX - radius, y + radius , (radius * 2) + 1 , radius * 2, ST77XX_CYAN);
    }
    tft.fillCircle(bX, y, radius, ST77XX_YELLOW);
}

void drawPillar(int x, int y){
    // Upper Pillar
    tft.fillRect(x + 30 + movingRate, 0, movingRate, y, ST77XX_CYAN);
    tft.fillRect(x, 0, 30, y, ST77XX_GREEN);

    // Bottom Pillar
    tft.fillRect(x + 30 + movingRate, y + pillarDistance, movingRate, 210 - (y + pillarDistance), ST77XX_CYAN);
    tft.fillRect(x, y + pillarDistance, 30, 210 - (y + pillarDistance), ST77XX_GREEN);
}

void gameOver(){
    delay(1500);
    tft.fillScreen(ST77XX_BLACK);
    tft.setCursor(30, 100);
    tft.setTextColor(ST77XX_WHITE);
    tft.println("GAME OVER!");
    tft.setCursor(30, 120);
    tft.print("Score: ");
    tft.println(score);
    tft.setCursor(30, 140);
    tft.println("Restarting...");
    delay(2000);
    gameStarted = false;
    score = 0;
    bX = 50;
    pX = 240;
    bY = 80;
    movingRate = 3;
    lastSpeedUpScore = 0;
    fallRate = 0;
    initiateGame();
}