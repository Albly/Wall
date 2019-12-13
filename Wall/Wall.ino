//количество кнопок и диодов
const int BTN_COUNT = 20;

//массив с кнопками
int btn[BTN_COUNT]; // Присвоить номера пинов!!!!
//массив с диодами
int led[BTN_COUNT]; // Присвоить номера пинов!!!!
//массив с масками (какие должы быть состояния кнопок во время игры)
boolean mask[BTN_COUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

//счётчик
unsigned long currentTime = 0;


void setup() {
  //выбираем режим работы для пинов диодов и кнопок
  for (int i = 0; i < BTN_COUNT; i++) {
    pinMode(btn[i], INPUT_PULLUP);
    pinMode(led[i], OUTPUT);
  }
  //последоательный порт для отладки
  Serial.begin(9600);

}

void loop() {


}
