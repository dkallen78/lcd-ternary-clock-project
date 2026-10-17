int segments[] = {18, 19, 33, 25, 26, 17, 16, 32};
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
int count = 0;

void display(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segments[i], nums[num][i]);
  }
}

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(segments[i], OUTPUT);
  }
}

void loop() {
  display(count % 10);
  delay(200);
  count++;
}