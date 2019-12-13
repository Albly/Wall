#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>


//количество кнопок и диодов
const int BTN_COUNT = 20;
//пины кнопок
int btn[BTN_COUNT]; // Присвоить номера пинов!!!!
//массив с состояниями диодов
int ledState[BTN_COUNT]; // Присвоить номера!!!!
//массив с масками (какие должы быть состояния кнопок во время игры)
boolean mask[BTN_COUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//счёт первого и второго игрока
int score1 = 0;
int score2 = 0;

byte gameMode = 0;


const int pinCS = 10; // ПИН CS для матрицы
const int numberOfHorizontalDisplays = 4; //количество горизонтальных матриц
const int numberOfVerticalDisplays = 1; //количество вертикальных матриц
Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays); // объект матрица


//счётчик
unsigned long currentTime = 0;

/*===========================================================================================================*/
void setup() {
  //выбираем режим работы для пинов диодов и кнопок
  for (int i = 0; i < BTN_COUNT; i++) {
    pinMode(btn[i], INPUT_PULLUP);
    //pinMode(led[i], OUTPUT);
  }
  //последоательный порт для отладки
  Serial.begin(9600);
  //выбор яркости матрицы
  matrix.setIntensity(2);

}

/*===========================================================================================================*/
void loop() {
  switch (gameMode) {
    case 1: {
        wallie();
      }
  }

}

/*===========================================================================================================*/
/* Функция лоха
*/
void loser() {

}
/*===========================================================================================================*/
/*
   Функция изменения состояния светодиода
   number - номер светодиода
   state - состояние HIGH или LOW
   Функция должна изменять массив состояний светодиодов и загружать этот массив в регистр
*/
void changeLedState(byte number, boolean state) {


}
