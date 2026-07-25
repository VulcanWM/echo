int button1 = D0;
int button2 = D1;
int button3 = D2;

int led1 = D3;
int led2 = D4;
int led3 = D5;

int buzzer1 = D6;

bool gameStarted = false;
int round = 0;

int sequence[100]; // win at 100
int inputIndex = 0;

void newRound(){
  int newColour = random(3);
  sequence[round-1] = newColour;
  for (int i = 0; i < round; i++){
    int currentColour = sequence[i];
    int frequency = (currentColour+1) * 300;
    tone(buzzer1, frequency, 1000);
    delay(1000);
    if (i != (round-1)){
      delay(500);
    }
  }
}

void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(buzzer1, OUTPUT);

  Serial.begin(9600);

  randomSeed(analogRead(0));
}

void loop() {
  if (gameStarted == false) {
    if (digitalRead(button1) == LOW || digitalRead(button2) == LOW || digitalRead(button3) == LOW){
      round = 1;
      gameStarted = true;
      newRound();
      inputIndex = 0;
    }
  } else {
    bool buttonPressed = false;
    int pressedButton = 0;
    if (digitalRead(button1) == LOW){
      buttonPressed = true;
      pressedButton = 0;
    } else if (digitalRead(button2) == LOW){
      buttonPressed = true;
      pressedButton = 1;
    } else if (digitalRead(button3) == LOW){
      buttonPressed = true;
      pressedButton = 2;
    }

    if (buttonPressed == true){
      int frequency = (pressedButton+1)*300;
      if (sequence[inputIndex] == pressedButton){
        inputIndex += 1;
        tone(buzzer1, frequency, 500);
        delay(500);
        if (inputIndex == round){
          if (round == 100){
            // victory tune
            tone(buzzer1, 500, 500);
            delay(500);
            tone(buzzer1, 600, 500);
            delay(500);
            tone(buzzer1, 700, 500);
            delay(500);
            tone(buzzer1, 800, 500);
            delay(500);
            tone(buzzer1, 900, 500);
            delay(500);
            tone(buzzer1, 900, 500);
            delay(500);
            tone(buzzer1, 900, 500);
            delay(500);
            gameStarted = false;
            return;
          }
          round += 1;
          inputIndex = 0;
          newRound();
        }
      } else {
        for (int i = 0; i < round; i++){
          int currentColour = sequence[i];
          int frequency = (currentColour+1) * 300;
          tone(buzzer1, frequency, 500);
          delay(500);
          if (i != (round-1)){
            delay(250);
          }
        }
        // lose tune
        tone(buzzer1, 900, 500);
        delay(500);
        tone(buzzer1, 800, 500);
        delay(500);
        tone(buzzer1, 700, 500);
        delay(500);
        tone(buzzer1, 600, 500);
        delay(500);
        tone(buzzer1, 500, 1000);
        delay(1000);
        gameStarted = false;
      }
    }
  }
}
