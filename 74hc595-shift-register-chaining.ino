int digit[] = {32, 19, 18, 17};
const int SER = 21;
const int SRCLK = 23;
const int RCLK = 22;

int nums[10] = {
  0b11111100,  // 0
  0b01100000,  // 1
  0b11011010,  // 2
  0b11110010,  // 3
  0b01100110,  // 4
  0b10110110,  // 5
  0b00111110,  // 6
  0b11100000,  // 7
  0b11111110,  // 8
  0b11100110   // 9
};

int numberDigits[4] = {0, 0, 0, 0};

int number = 0;
int count = 0;
int byte1, byte2;
int timer = millis();

void pulse(int pin) {
  digitalWrite(pin, HIGH);
  digitalWrite(pin, LOW);
}

void send(int data) {
  for (int i = 0; i < 16; i++) {
    digitalWrite(SER, (data >> i) % 2);
    pulse(SRCLK);
  }
  pulse(RCLK);
}

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(digit[i], OUTPUT);
    digitalWrite(digit[i], HIGH);
  }

  pinMode(SER, OUTPUT);
  digitalWrite(SER, LOW);

  pinMode(SRCLK, OUTPUT);
  digitalWrite(SRCLK, LOW);

  pinMode(RCLK, OUTPUT);
  digitalWrite(RCLK, LOW);
}

void loop() {

  byte1 = (count % 4 == 0) ? nums[numberDigits[1]] : 0b00000000;
  byte2 = nums[numberDigits[count % 4]];

  send(byte2 << 8 | byte1);
  digitalWrite(digit[count % 4], LOW);  
  delay(1);                     
  digitalWrite(digit[count % 4], HIGH);
  count++;

  if (millis() - timer > 250) {
    number++;
    numberDigits[0] = number % 10;
    numberDigits[1] = (number / 10) % 10;
    numberDigits[2] = (number / 100) % 10;
    numberDigits[3] = (number / 1000) % 10;
    timer = millis();
  }
}
