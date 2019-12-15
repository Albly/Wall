byte dataPin = 11;
byte clockPin = 12;
byte latchPin = 13;
byte ledState[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //состояния светодиодов
void setup()
{

}

void loop()
{
  ledControll(2, false); //данные, передаваемые функции
}

void ledControll(byte number, bool state)  //непосредственно функция
{
  byte x[7] = {0, 0, 0, 0, 0, 0, 0};
  byte y[7] = {0, 0, 0, 0, 0, 0, 0};
  byte z[6] = {0, 0, 0, 0, 0, 0};
  byte a = 0, b = 0, c = 0;
  ledState[number] = state;
  for (int i = 0; i <= 20; i++)
  {
    if (i <= 6)
      x[i] = ledState[i] << i;
    a = x[0] | x[1] | x[2] | x[3] | x[4] | x[5] | x[6] | x[7];
    if (i <= 13 & i >= 7)
      y[i] = ledState[i] << (i - 7);
    b = y[0] | y[1] | y[2] | y[3] | y[4] | y[5] | y[6] | y[7];
    if (i >= 14)
      z[i] = ledState[i] << (i - 13);
    c = z[0] | z[1] | z[2] | z[3] | z[4] | z[5] | z[6];
  }
  digitalWrite(latchPin, LOW); //начало загрузки данных в сдвиговый регистр
  shiftOut(dataPin, clockPin, LSBFIRST, c);
  shiftOut(dataPin, clockPin, LSBFIRST, b);
  shiftOut(dataPin, clockPin, LSBFIRST, a);
  digitalWrite(latchPin, HIGH);
}
