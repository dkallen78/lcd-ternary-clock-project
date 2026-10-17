int segment[] = {18, 23, 25, 27, 13, 19, 33, 26};
int digit[] = {32, 22, 21, 17};

int nums[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},  // 0
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {0, 0, 1, 1, 1, 1, 1},  // 6
  {1, 1, 1, 0, 0, 0, 0},  // 7
  {1, 1, 1, 1, 1, 1, 1},  // 8
  {1, 1, 1, 0, 0, 1, 1}   // 9
};

int number = 0;
int timer = millis();

void display(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segment[i], nums[num][i]);
  }
}

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(segment[i], OUTPUT);
    digitalWrite(segment[i], LOW);
    if (i < 4) {
      pinMode(digit[i], OUTPUT);
      digitalWrite(digit[i], HIGH);
    }
  }
}

void loop() {
  int numberDigits[4] = {
    number % 10,                              //ones
    (number % 100 - number % 10) / 10,        //tens
    (number % 1000 - number % 100) / 100,     //hundreds
    (number % 10000 - number % 1000) / 1000   //thousands
  };

  for (int i = 0; i < 4; i++) {
    digitalWrite(digit[i], LOW);  //Set the cathode pin to ground
    display(numberDigits[i]);     //Display the digit
    delay(1);                     //Show it for 1 ms
    digitalWrite(digit[i], HIGH); //Pull the cathode pin to HIGH
  }

   if (millis() - timer > 250) {
    number++;
    timer = millis();
  }
}
