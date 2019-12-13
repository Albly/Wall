void wallie() {
  /*Игра Wallie*/
  chooseTheButton();
  waitForPressed();
  waitWhilePressed();
}

/*===========================================================================================================*/
/*Выбор случайной кнопки
   Использует аналоговый пин А5 для снятия наводок
   Выбирает случайное число от 0 до BTN_COUNT
   Изменяет выбранную ячейку маски с 0 на 1
   Включает диод на пине под выбранным номером
   Выводит выбранное число в Порт

*/
void chooseTheButton() {
  Serial.println("choosing random button");
  while (true) {
    randomSeed(analogRead(A5));
    int a = random(0, BTN_COUNT);
    if (mask[a] == false) {
      mask[a] = true;
      changeLedState(a,HIGH);
      Serial.print("I've chosen: ");
      Serial.println(a);
      break;
    }
  }
}
/*===========================================================================================================*/
/* Ожидает 5 секунд нажатия всех кнопок маски
   Если кнопка маски нажата, то выключает её диод
   Если нажата неверная кнопка вызывает лоха
*/
void waitForPressed() {
  Serial.println("Waiting for pressing");
  for (currentTime = millis(); millis() - currentTime < 5000;) {
    if (isAllPressed()) {
      Serial.println("All btns had been pressed");
      for (int i = 0; i < BTN_COUNT; i++) {
        if (mask[i] == true) {
          changeLedState(i,LOW);
          //digitalWrite(led[i], LOW);
          Serial.print("Switched off the led number: ");
          Serial.println(i);
        }
      }
      return;
    }
  }
  Serial.println("Btns hadn't been pressed");
  loser();
}
/*===========================================================================================================*/
/* Проверяет все ли кнопки из маски были нажаты
    Возвращает true если все кнопки нажаты
    Возвращает false если не все кнопки были нажаты

*/
boolean isAllPressed() {
  for (int i = 0 ; i < BTN_COUNT ; i++ ) {
    if (mask[i] == true) {
      if (digitalRead(btn[i]) == true) {
        delay(200);
        if (digitalRead(btn[i]) == true) {
          Serial.println(i);
          return false;
        }
      }
    }
  }
  return true;
}

/*===========================================================================================================*/
/* 3 секунды проверяет нажаты ли кнопки.
    Если не нажаты, то вызывает функцию лоха
*/
void waitWhilePressed() {
  Serial.println("Searching for unpressing");
  for (currentTime = millis(); millis() - currentTime < 3000;) {
    if (!isAllPressed()) {
      Serial.println("Unpressing detected");
      loser();
      return;
    }
  }
}
