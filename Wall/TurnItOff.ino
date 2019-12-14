void turnItOff() {
  turnAll();
  isOffExist();
}

void turnAll() {
  for (int i; i < BTN_COUNT; i++) {
    changeLedState(i, HIGH);
    mask[i] = 1;
  }
}

void isOffExist() {
  for (int i, i < BTN_COUNT; i++) {
    if (mask[i] == 0) {
      if (isAllOff()) {
        winRound();
      }
      else{
        
        }
    }
  }
}

boolean isAllOff() {
  for (int i, i < BTN_COUNT; i++) {
    if (mask[i] == 1) {
      return false;
    }
  }
  return true;
}
