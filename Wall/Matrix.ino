void displayScore(int left, int right) {
  // выводит счет на матрицу
  //drawChar. drawChar( x, y, символ, цвет, фон, размер );
  if (left > 9) {
    matrix.drawChar(0, 0, (left / 10), HIGH, LOW, 1);
    matrix.drawChar(8, 0, (left % 10), HIGH, LOW, 1);
  }
  else {
    matrix.drawChar(0, 0, left, HIGH, LOW, 1);
  }
  if (right > 9) {
    matrix.drawChar(16, 0, (right / 10), HIGH, LOW, 1);
    matrix.drawChar(24, 0, (right % 10), HIGH, LOW, 1);
  }
  else {
    matrix.drawChar(16, 0, right, HIGH, LOW, 1);
  }
}
