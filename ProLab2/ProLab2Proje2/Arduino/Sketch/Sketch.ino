#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const unsigned char charS [] PROGMEM = {
0x4C, 0x92, 0x92, 0x92, 0x64, 0x00, 0x00, 0x00, 
};

const unsigned char charT [] PROGMEM = {
0x06, 0x02, 0xFE, 0x02, 0x06, 0x00, 0x00, 0x00, 
};

const unsigned char charA [] PROGMEM = {
0xF8, 0x24, 0x22, 0x24, 0xF8, 0x00, 0x00, 0x00, 
};

const unsigned char charR [] PROGMEM = {
0xFE, 0x12, 0x32, 0x52, 0x8C, 0x00, 0x00, 0x00, 
};

const unsigned char charH [] PROGMEM = {
0xFE, 0x10, 0x10, 0x10, 0xFE, 0x00, 0x00, 0x00, 
};

const unsigned char charL [] PROGMEM = {
0xFE, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 
};

const unsigned char charE [] PROGMEM = {
0xFE, 0x92, 0x92, 0x92, 0x82, 0x00, 0x00, 0x00, 
};

const unsigned char charN [] PROGMEM = {
0xFE, 0x08, 0x10, 0x20, 0xFE, 0x00, 0x00, 0x00, 
};

const unsigned char charO [] PROGMEM = {
0x7C, 0x82, 0x82, 0x82, 0x7C, 0x00, 0x00, 0x00, 
};

const unsigned char charM [] PROGMEM = {
0xFE, 0x04, 0x18, 0x04, 0xFE, 0x00, 0x00, 0x00, 
};

const unsigned char charD [] PROGMEM = {
0xFE, 0x82, 0x82, 0x82, 0x7C, 0x00, 0x00, 0x00, 
};

const unsigned char exclamationMark [] PROGMEM = {
0xBE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const unsigned char arrowSign [] PROGMEM = {
0x20, 0x20, 0xF8, 0x70, 0x20, 0x00, 0x00, 0x00, 
};

const unsigned char rocketLogo [] PROGMEM = {
0x3F, 0xF0, 0x00, 0x00, 0x3F, 0xF0, 0x00, 0x00, 0x0F, 0xC0, 0x00, 0x00, 0x0F, 0xC0, 0x00, 0x00,
0x0F, 0xC0, 0x00, 0x00, 0x0F, 0xC0, 0x00, 0x00, 0x3F, 0xFF, 0xC0, 0x00, 0x3F, 0xFF, 0xC0, 0x00,
0x0F, 0xFF, 0x00, 0x00, 0x0F, 0xFF, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0x00, 0x03, 0xFF, 0xFF, 0x00,
0xFC, 0xFF, 0xFF, 0xF0, 0xFC, 0xFF, 0xFF, 0xF0, 0x3F, 0xFF, 0x03, 0xFF, 0x3F, 0xFF, 0x03, 0xFF,
0x3F, 0xFF, 0x03, 0xFF, 0x3F, 0xFF, 0x03, 0xFF, 0xFC, 0xFF, 0xFF, 0xF0, 0xFC, 0xFF, 0xFF, 0xF0,
0x03, 0xFF, 0xFF, 0x00, 0x03, 0xFF, 0xFF, 0x00, 0x0F, 0xFF, 0x00, 0x00, 0x0F, 0xFF, 0x00, 0x00,
0x3F, 0xFF, 0xC0, 0x00, 0x3F, 0xFF, 0xC0, 0x00, 0x0F, 0xC0, 0x00, 0x00, 0x0F, 0xC0, 0x00, 0x00,
0x0F, 0xC0, 0x00, 0x00, 0x0F, 0xC0, 0x00, 0x00, 0x3F, 0xF0, 0x00, 0x00, 0x3F, 0xF0, 0x00, 0x00
};

const unsigned char spaceIcon [] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

/*const unsigned char spaceTrashIcon [] PROGMEM = {
0x00, 0x00, 0x1C, 0x38, 0x30, 0x10, 0x00, 0x00, 
};*/
const unsigned char spaceTrashIcon [] PROGMEM= {
0x1C, 0x1C, 0x08, 0x3E, 0x3E, 0x08, 0x1C, 0x1C, 
};


const unsigned char damagedMeteorIcon [] PROGMEM = {
0x00, 0x08, 0x14, 0x7A, 0x5C, 0x34, 0x18, 0x00, 
};

/*const unsigned char meteorIcon [] PROGMEM = {
0x00, 0x18, 0x3C, 0x7E, 0x7E, 0x3C, 0x18, 0x00, 
};*/
/*const unsigned char meteorIcon [] PROGMEM = {
0x01, 0x0A, 0x1C, 0x3E, 0x7F, 0x3E, 0x1C, 0x08, 
};*/
/*const unsigned char meteorIcon [] PROGMEM = {
0x10, 0x38, 0x7C, 0xFF, 0xFF, 0x7C, 0x38, 0x10, 
};*/
const unsigned char meteorIcon [] PROGMEM= {
0x00, 0x08, 0x1C, 0x3F, 0x1C, 0x08, 0x00, 0x00, 
};
/*const unsigned char meteorIcon [] PROGMEM = {
0x10, 0x38, 0x7C, 0x7F, 0x7C, 0x38, 0x10, 0x00, 
};
*/



/*const unsigned char extraHealthIcon [] PROGMEM = {
0x0C, 0x1E, 0x3E, 0x7C, 0x7C, 0x3E, 0x1E, 0x0C, 
};*/
const unsigned char extraHealthIcon [] PROGMEM = {
0x1E, 0x21, 0x41, 0x82, 0x82, 0x41, 0x21, 0x1E, 
};


/*const unsigned char extraBulletIcon [] PROGMEM = {
0x00, 0x78, 0x7C, 0x7E, 0x7E, 0x7C, 0x78, 0x00, 
};*/
const unsigned char extraBulletIcon [] PROGMEM = {
0x00, 0xF4, 0xF6, 0xF7, 0xF7, 0xF6, 0xF4, 0x00, 
};


/*const unsigned char shieldIcon [] PROGMEM = {
0x00, 0x1E, 0x3E, 0x7E, 0x7E, 0x3E, 0x1E, 0x00, 
};*/

const unsigned char shieldIcon [] PROGMEM = {
0x00, 0x1E, 0x3A, 0x7A, 0x7A, 0x3A, 0x1E, 0x00, 
};

/*const unsigned char rocketIcon [] PROGMEM = {
0xF8, 0xF8, 0x7E, 0x3F, 0x3F, 0x7E, 0xF8, 0xF8, 
};*/
/*const unsigned char rocketIcon [] PROGMEM = {
0x38, 0x30, 0xF8, 0x7E, 0x7E, 0xF8, 0x30, 0x38, 
};*/

const unsigned char rocketIcon [] PROGMEM= {
0x38, 0x70, 0xF8, 0x7E, 0x7E, 0xF8, 0x70, 0x38, 
};


const int healthLedPins[] = {4, 5, 6};
const int bulletLedPins[] = {7, 8, 9};
const int shootButtonPin = 2;
const int buzzerPin = 10;
const int scoreDisplayPins[][7] = {{22, 24, 26, 28, 30, 32, 34}, {36, 38, 40, 42, 44, 46, 48}, {50, 52, 11, 17, 16, 15, 14}};
const int upButtonPin = 3;
const int okButtonPin = 18;
const int downButtonPin = 19;
const int playerPotPin = A0;
const int ldrPin = A1;

int health;
int bullet;
int score;
int obstacleCounter;

int rocketX;

int pageIndex;
int mainMenuSelection;
int hassleMenuSelection;

int space[16][8];

bool upButtonPressedControl;
bool okButtonPressedControl;
bool downButtonPressedControl;
bool isInvisible;
bool isDarkMode;

unsigned long currentMs;
unsigned long movePrevMs;
unsigned long speedPrevMs;
unsigned long updateMs;
unsigned long invisibiltyPrevMs;

Adafruit_SSD1306 oledScreen = Adafruit_SSD1306(128, 64, &Wire);

void setup() 
{
  pageIndex = 0;
  mainMenuSelection = 0;
  hassleMenuSelection = 0;
  upButtonPressedControl = false;
  okButtonPressedControl = false;
  downButtonPressedControl = false;
  isDarkMode = true;

  oledScreen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  oledScreen.clearDisplay();
  oledScreen.drawBitmap(48, 16, rocketLogo, 32, 32, isDarkMode);
  oledScreen.display();
  delay(400);
  MainMenu();

  for (int i = 0; i < 3; i++)
  {
    pinMode(healthLedPins[i], OUTPUT);
    pinMode(bulletLedPins[i], OUTPUT);
    for (int j = 0; j < 7; j++)
    {
      pinMode(scoreDisplayPins[i][j], OUTPUT);
    }
  }
  pinMode(buzzerPin, OUTPUT);


  pinMode(shootButtonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(shootButtonPin), Shoot, FALLING);
  pinMode(upButtonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(upButtonPin), UpButtonPressed, FALLING);
  pinMode(okButtonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(okButtonPin), OkButtonPressed, FALLING);
  pinMode(downButtonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(downButtonPin), DownButtonPressed, FALLING);
  pinMode(playerPotPin, INPUT);
  pinMode(ldrPin, INPUT);
}

void loop() 
{
  if (isDarkMode && analogRead(ldrPin) < 50)
  {
    isDarkMode = false;
    switch (pageIndex)
    {
    case 0:
      MainMenu();
      break;
    case 1:
      HassleMenu();
      break;
    case 2:
      RedrawGame();
      break;
    default:
      break;
    }
  }
  else if (!isDarkMode && analogRead(ldrPin) >= 50)
  {
    isDarkMode = true;
    switch (pageIndex)
    {
    case 0:
      MainMenu();
      break;
    case 1:
      HassleMenu();
      break;
    case 2:
      RedrawGame();
      break;
    default:
      break;
    }
  }

  if (upButtonPressedControl && pageIndex != 2)
  {
    upButtonPressedControl = false;
    UpButton();
  }

  if (okButtonPressedControl && pageIndex != 2)
  {
    okButtonPressedControl = false;
    OkButton();
  }

  if (downButtonPressedControl && pageIndex != 2)
  {
    downButtonPressedControl = false;
    DownButton();
  }

  if (pageIndex == 2)
  {
    int newRocketX = analogRead(playerPotPin);
    newRocketX = map(newRocketX, 0, 1023, -1, 8);
    if (rocketX != newRocketX)
    {
      MoveRocket(newRocketX);
    }

    currentMs = millis();
    if (currentMs - movePrevMs >= updateMs)
    {
      movePrevMs = currentMs;
      MoveSpace();
    }

    if (hassleMenuSelection && currentMs - speedPrevMs >= 10000)
    {
      speedPrevMs = currentMs;
      updateMs *= 0.8;
    }

    if (isInvisible && currentMs - invisibiltyPrevMs >= 3000)
    {
      isInvisible = false;
    }
  }

  if (pageIndex == 4)
  {
    pageIndex = 0;
    MainMenu();
  }
}

void RedrawGame()
{
  oledScreen.clearDisplay();
  if (!isDarkMode)
  {
    oledScreen.fillRect(0, 0, 128, 64, WHITE);
  }
  for (int i = 0; i < 16; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      switch (space[i][j])
      {
      case 0:
        oledScreen.drawBitmap(i * 8, j * 8, spaceIcon, 8, 8, isDarkMode);
        break;
      case 1:
        oledScreen.drawBitmap(i * 8, j * 8, spaceTrashIcon, 8, 8, isDarkMode);
        break;
      case 2:
        oledScreen.drawBitmap(i * 8, j * 8, damagedMeteorIcon, 8, 8, isDarkMode);
        break;
      case 3:
        oledScreen.drawBitmap(i * 8, j * 8, meteorIcon, 8, 8, isDarkMode);
        break;
      case 4:
        oledScreen.drawBitmap(i * 8, j * 8, extraHealthIcon, 8, 8, isDarkMode);
        break;
      case 5:
        oledScreen.drawBitmap(i * 8, j * 8, extraBulletIcon, 8, 8, isDarkMode);
        break;
      case 6:
        oledScreen.drawBitmap(i * 8, j * 8, shieldIcon, 8, 8, isDarkMode);
        break;
      case 7:
        oledScreen.drawBitmap(i * 8, j * 8, rocketIcon, 8, 8, isDarkMode);
        break;
      default:
        break;
      }
    }
  }
  oledScreen.display();
}

void MoveSpace()
{
  for (int i = 1; i < 16; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (i == 1)
      {
        if (space[0][j] == 7)
        {
          switch (space[1][j])
          {
            case 1:
              if (!isInvisible)
              {
                DecreaseHealth();
              }
              break;
            case 2:
              if (!isInvisible)
              {
                DecreaseHealth();
              }
              break;
            case 3:
              if (!isInvisible)
              {
                DecreaseHealth();
              }
              break;
            case 4:
              IncreaseHealth();
              break;
            case 5:
              IncreaseBullet();
              break;
            case 6:
              RocketInvisible();
              break;
            default:
              break;
          }
        }
        else if (space[0][j] != space[1][j])
        {
          oledScreen.fillRect(0, j * 8, 8, 8, !isDarkMode);
          oledScreen.fillRect(8, j * 8, 8, 8, !isDarkMode);
          switch (space[i][j])
          {
          case 0:
            oledScreen.drawBitmap(0, j * 8, spaceIcon, 8, 8, isDarkMode);
            break;
          case 1:
            oledScreen.drawBitmap(0, j * 8, spaceTrashIcon, 8, 8, isDarkMode);
            break;
          case 2:
            oledScreen.drawBitmap(0, j * 8, damagedMeteorIcon, 8, 8, isDarkMode);
            break;
          case 3:
            oledScreen.drawBitmap(0, j * 8, meteorIcon, 8, 8, isDarkMode);
            break;
          case 4:
            oledScreen.drawBitmap(0, j * 8, extraHealthIcon, 8, 8, isDarkMode);
            break;
          case 5:
            oledScreen.drawBitmap(0, j * 8, extraBulletIcon, 8, 8, isDarkMode);
            break;
          case 6:
            oledScreen.drawBitmap(0, j * 8, shieldIcon, 8, 8, isDarkMode);
            break;
          default:
            break;
          }
          space[0][j] = space[1][j];
          space[1][j] = 0;
        }
      }
      else
      {
        if (space[i - 1][j] != space[i][j])
        {
          oledScreen.fillRect((i - 1) * 8, j * 8, 8, 8, !isDarkMode);
          oledScreen.fillRect(i * 8, j * 8, 8, 8, !isDarkMode);
          switch (space[i][j])
          {
          case 0:
            oledScreen.drawBitmap((i - 1) * 8, j * 8, spaceIcon, 8, 8, isDarkMode);
            break;
          case 1:
            oledScreen.drawBitmap((i - 1) * 8, j * 8, spaceTrashIcon, 8, 8, isDarkMode);
            break;
          case 2:
            oledScreen.drawBitmap((i - 1) * 8, j * 8, damagedMeteorIcon, 8, 8, isDarkMode);
            break;
          case 3:
            oledScreen.drawBitmap((i - 1) * 8, j * 8, meteorIcon, 8, 8, isDarkMode);
            break;
          case 4:
            oledScreen.drawBitmap((i - 1) * 8, j * 8, extraHealthIcon, 8, 8, isDarkMode);
            break;
          case 5:
            oledScreen.drawBitmap((i - 1) * 8, j * 8, extraBulletIcon, 8, 8, isDarkMode);
            break;
          case 6:
            oledScreen.drawBitmap((i - 1) * 8, j * 8, shieldIcon, 8, 8, isDarkMode);
            break;
          default:
            break;
          }
          space[i - 1][j] = space[i][j];
          space[i][j] = 0;
        }
      }
    }
  }

  int newSpaceArray[] = {0, 0, 0, 0, 0, 0, 0, 0};
  int arrayObstacleCount = random(0, 9);
  switch (arrayObstacleCount)
  {
  case 0:
    arrayObstacleCount = 1;
    break;
  case 1:
    arrayObstacleCount = 1;
    break;
  case 2:
    arrayObstacleCount = 1;
    break;
  case 3:
    arrayObstacleCount = 2;
    break;
  case 4:
    arrayObstacleCount = 2;
    break;
  case 5:
    arrayObstacleCount = 2;
    break;
  case 6:
    arrayObstacleCount = 3;
    break;
  case 7:
    arrayObstacleCount = 3;
    break;
  case 8:
    arrayObstacleCount = 4;
    break;
  default:
    break;
  }
  if (arrayObstacleCount < 4)
  {
    for (int i = 0; i < arrayObstacleCount; i++)
    {
      int obstacleType = random(0, 2) * 2 + 1;
      while (true)
      {
        int obstacleX = random(0, 8);
        if (newSpaceArray[obstacleX] == 0)
        {
          if (obstacleX == 0)
          {
            if (newSpaceArray[obstacleX + 1] == 0)
            {
              newSpaceArray[obstacleX] = obstacleType;
              break;
            }
          }
          else if (obstacleX == 7)
          {
            if (newSpaceArray[obstacleX - 1] == 0)
            {
              newSpaceArray[obstacleX] = obstacleType;
              break;
            }
          }
          else if (newSpaceArray[obstacleX + 1] == 0 && newSpaceArray[obstacleX - 1] == 0)
          {
              newSpaceArray[obstacleX] = obstacleType;
              break;
          }
        }
      }
    }
  }
  else
  {
    if (random(0, 2))
    {
      newSpaceArray[0] = random(1, 4);
      newSpaceArray[2] = random(1, 4);
      newSpaceArray[4] = random(1, 4);
      newSpaceArray[6] = random(1, 4);
    }
    else
    {
      newSpaceArray[1] = random(1, 4);
      newSpaceArray[3] = random(1, 4);
      newSpaceArray[5] = random(1, 4);
      newSpaceArray[7] = random(1, 4);
    }
  }
  
  obstacleCounter += arrayObstacleCount;
  if (obstacleCounter >= 7)
  {
    obstacleCounter = 0;
    int extraType = random(0, 4) + 4;
    int extraX;
    while (true)
    {
      extraX = random(0, 8);
      if (newSpaceArray[extraX] == 0)
      {
        break;
      }
    }
    newSpaceArray[extraX] = extraType;
  }

  for (int i = 0; i < 8; i++)
  {
    space[15][i] = newSpaceArray[i];
    switch (newSpaceArray[i])
    {
      case 0:
        oledScreen.drawBitmap(15 * 8, i * 8, spaceIcon, 8, 8, isDarkMode);
        break;
      case 1:
        oledScreen.drawBitmap(15 * 8, i * 8, spaceTrashIcon, 8, 8, isDarkMode);
        break;
      case 2:
        oledScreen.drawBitmap(15 * 8, i * 8, damagedMeteorIcon, 8, 8, isDarkMode);
        break;
      case 3:
        oledScreen.drawBitmap(15 * 8, i * 8, meteorIcon, 8, 8, isDarkMode);
        break;
      case 4:
        oledScreen.drawBitmap(15 * 8, i * 8, extraHealthIcon, 8, 8, isDarkMode);
        break;
      case 5:
        oledScreen.drawBitmap(15 * 8, i * 8, extraBulletIcon, 8, 8, isDarkMode);
        break;
      case 6:
        oledScreen.drawBitmap(15 * 8, i * 8, shieldIcon, 8, 8, isDarkMode);
        break;
      default:
        break;
    }
  }

  oledScreen.display();
  IncreaseScore();
}

void MoveRocket(int newX)
{
  oledScreen.fillRect(0, rocketX * 8, 8, 8, !isDarkMode);
  oledScreen.drawBitmap(0, newX * 8, rocketIcon, 8, 8, isDarkMode);
  oledScreen.display();
  if (space[0][newX] == 1 || space[0][newX] == 2 ||space[0][newX] == 3)
  {
    if (!isInvisible)
    {
      DecreaseHealth();
    }
  }
  else if (space[0][newX] == 4)
  {
    IncreaseHealth();
  }
  else if (space[0][newX] == 5)
  {
    IncreaseBullet();
  }
  else if (space[0][newX] == 6)
  {
    RocketInvisible();
  }
  space[0][rocketX] = 0;
  space[0][newX] = 7;
  rocketX = newX;
}

void MainMenu()
{
  oledScreen.clearDisplay();
  if (!isDarkMode)
  {
    oledScreen.fillRect(0, 0, 128, 64, WHITE);
  }
  oledScreen.drawBitmap(66, 16, rocketLogo, 32, 32, isDarkMode);
  oledScreen.drawBitmap(43, 5, arrowSign, 8, 8, isDarkMode);
  oledScreen.drawBitmap(42, 12, charS, 8, 8, isDarkMode);
  oledScreen.drawBitmap(42, 19, charT, 8, 8, isDarkMode);
  oledScreen.drawBitmap(42, 26, charA, 8, 8, isDarkMode);
  oledScreen.drawBitmap(42, 33, charR, 8, 8, isDarkMode);
  oledScreen.drawBitmap(42, 40, charT, 8, 8, isDarkMode);
  oledScreen.drawBitmap(42, 47, exclamationMark, 8, 8, isDarkMode);
  oledScreen.drawBitmap(30, 12, charH, 8, 8, isDarkMode);
  oledScreen.drawBitmap(30, 19, charA, 8, 8, isDarkMode);
  oledScreen.drawBitmap(30, 26, charS, 8, 8, isDarkMode);
  oledScreen.drawBitmap(30, 33, charS, 8, 8, isDarkMode);
  oledScreen.drawBitmap(30, 40, charL, 8, 8, isDarkMode);
  oledScreen.drawBitmap(30, 47, charE, 8, 8, isDarkMode);
  oledScreen.display();
}

void HassleMenu()
{
  oledScreen.clearDisplay();
  if (!isDarkMode)
  {
    oledScreen.fillRect(0, 0, 128, 64, WHITE);
  }
  oledScreen.drawBitmap(66, 16, rocketLogo, 32, 32, isDarkMode);
  oledScreen.drawBitmap(43, 5, arrowSign, 8, 8, isDarkMode);
  oledScreen.drawBitmap(42, 12, charN, 8, 8, isDarkMode);
  oledScreen.drawBitmap(42, 19, charO, 8, 8, isDarkMode);
  oledScreen.drawBitmap(42, 26, charR, 8, 8, isDarkMode);
  oledScreen.drawBitmap(42, 33, charM, 8, 8, isDarkMode);
  oledScreen.drawBitmap(42, 40, charA, 8, 8, isDarkMode);
  oledScreen.drawBitmap(42, 47, charL, 8, 8, isDarkMode);
  oledScreen.drawBitmap(30, 19, charH, 8, 8, isDarkMode);
  oledScreen.drawBitmap(30, 26, charA, 8, 8, isDarkMode);
  oledScreen.drawBitmap(30, 33, charR, 8, 8, isDarkMode);
  oledScreen.drawBitmap(30, 40, charD, 8, 8, isDarkMode);
  oledScreen.display();
}

void UpButtonPressed()
{
  upButtonPressedControl = true;
}

void OkButtonPressed()
{
  okButtonPressedControl = true;
}

void DownButtonPressed()
{
  downButtonPressedControl = true;
}

void UpButton()
{
  if (pageIndex == 0)
  {
    mainMenuSelection = !mainMenuSelection;
    
    if (mainMenuSelection)
    {
      ArrowDown();
    }
    else
    {
      ArrowUp();
    }
  }
  else if (pageIndex == 1)
  {
    hassleMenuSelection = !hassleMenuSelection;
    
    if (hassleMenuSelection)
    {
      ArrowDown();
    }
    else
    {
      ArrowUp();
    }
  }
}

void OkButton()
{
  if (pageIndex == 0)
  {
    if (!mainMenuSelection)
    {
      pageIndex = 2;
      InitializeGame();
    }
    else
    {
      pageIndex = 1;
      HassleMenu();
      if (hassleMenuSelection)
      {
        ArrowDown();
      }
    }
  }
  else if (pageIndex == 1)
  {
    pageIndex = 0;
    MainMenu();
    if (mainMenuSelection)
    {
      ArrowDown();
    }
  }
}

void DownButton()
{
  if (pageIndex == 0)
  {
    mainMenuSelection = !mainMenuSelection;
    
    if (mainMenuSelection)
    {
      ArrowDown();
    }
    else
    {
      ArrowUp();
    }
  }
  else if (pageIndex == 1)
  {
    hassleMenuSelection = !hassleMenuSelection;
    
    if (hassleMenuSelection)
    {
      ArrowDown();
    }
    else
    {
      ArrowUp();
    }
  }
}

void ArrowUp()
{
  oledScreen.fillRect(31, 5, 5, 5, !isDarkMode);
  oledScreen.drawBitmap(43, 5, arrowSign, 8, 8, isDarkMode);
  oledScreen.display();
}

void ArrowDown()
{
  oledScreen.fillRect(43, 5, 5, 5, !isDarkMode);
  oledScreen.drawBitmap(31, 5, arrowSign, 8, 8, isDarkMode);
  oledScreen.display();
}

void InitializeGame()
{
  isInvisible  = false;
  updateMs = 1000;
  movePrevMs = millis();
  speedPrevMs = millis();
  obstacleCounter = 0;

  for (int i = 0; i < 16; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      space[i][j] = 0;
    }
  }
  space[0][0] = 7;

  oledScreen.clearDisplay();
  if (!isDarkMode)
  {
    oledScreen.fillRect(0, 0, 128, 64, WHITE);
  }
  for (int i = 0; i < 16; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      switch (space[i][j])
      {
        case 0:
          oledScreen.drawBitmap(i * 8, j * 8, spaceIcon, 8, 8, isDarkMode);
          break;
        case 7:
          oledScreen.drawBitmap(i * 8, j * 8, rocketIcon, 8, 8, isDarkMode);
          break;
        default:
          oledScreen.drawBitmap(i * 8, j * 8, spaceIcon, 8, 8, isDarkMode);
          break;
      }
    }
  }
  oledScreen.display();

  rocketX = 0;
  health = 3;
  bullet = 3;
  score = 0;

  for (int i = 0; i < 3; i++)
  {
    digitalWrite(healthLedPins[i], HIGH);
    digitalWrite(bulletLedPins[i], HIGH);
  }

  UpdateDisplay(0, 0);
  UpdateDisplay(1, 0);
  UpdateDisplay(2, 0);
}

void IncreaseHealth()
{
  if (health < 3)
  {
    digitalWrite(healthLedPins[health], HIGH);
    health++;
  }
}

void DecreaseHealth()
{
  RocketInvisible();

  health--;
  digitalWrite(healthLedPins[health], LOW);

  digitalWrite(buzzerPin, HIGH);
  delay(50);
  digitalWrite(buzzerPin, LOW);

  if (health <= 0)
  {
    GameOver();
  }
}

void IncreaseBullet()
{
  if (bullet < 3)
  {
    digitalWrite(bulletLedPins[bullet], HIGH);
    bullet++;
  }
}

void Shoot()
{
  if (bullet > 0 && pageIndex == 2)
  {
    bullet--;
    digitalWrite(bulletLedPins[bullet], LOW);

    for (int i = 1; i < 16; i++)
    {
      if (space[i][rocketX] == 1 || space[i][rocketX] == 2)
      {
        oledScreen.fillRect(i * 8, rocketX * 8, 8, 8, !isDarkMode);
        oledScreen.drawBitmap(i * 8, rocketX * 8, spaceIcon, 8, 8, isDarkMode);
        space[i][rocketX] = 0;
        break;
      }
      else if (space[i][rocketX] == 3)
      {
        oledScreen.fillRect(i * 8, rocketX * 8, 8, 8, !isDarkMode);
        oledScreen.drawBitmap(i * 8, rocketX * 8, damagedMeteorIcon, 8, 8, isDarkMode);
        space[i][rocketX] = 2;
        break;
      }
    }
  }
}

void IncreaseScore()
{
  score++;
  if (score < 1000)
  {
    UpdateDisplay(2, score % 10);
    if (score % 10 == 0)
    {
      UpdateDisplay(1, (score / 10) % 10);
    }
    if (score % 10 == 0 && (score) / 10 % 10 == 0)
    {
      UpdateDisplay(0, (score / 100) % 10);
    }
  }
}

void RocketInvisible()
{
  isInvisible = true;
  invisibiltyPrevMs = millis();
}

void GameOver()
{
  pageIndex = 3;
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(healthLedPins[i], HIGH);
    digitalWrite(bulletLedPins[i], HIGH);
  }
  digitalWrite(buzzerPin, HIGH);
  delay(50);
  digitalWrite(buzzerPin, LOW);
  delay(100);
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(healthLedPins[i], LOW);
    digitalWrite(bulletLedPins[i], LOW);
  }
  delay(100);
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(healthLedPins[i], HIGH);
    digitalWrite(bulletLedPins[i], HIGH);
  }
  digitalWrite(buzzerPin, HIGH);
  delay(50);
  digitalWrite(buzzerPin, LOW);
  delay(100);
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(healthLedPins[i], LOW);
    digitalWrite(bulletLedPins[i], LOW);
  }
  delay(100);
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(healthLedPins[i], HIGH);
    digitalWrite(bulletLedPins[i], HIGH);
  }
  digitalWrite(buzzerPin, HIGH);
  delay(50);
  digitalWrite(buzzerPin, LOW);
  delay(100);
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(healthLedPins[i], LOW);
    digitalWrite(bulletLedPins[i], LOW);
  }
  pageIndex = 4;
}

void UpdateDisplay(int displayIndex, int digit)
{
  for (int i = 0; i < 7; i++)
    digitalWrite(scoreDisplayPins[displayIndex][i], LOW);

  switch (digit)
  {
    case 0:
      digitalWrite(scoreDisplayPins[displayIndex][0], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][1], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][2], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][3], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][4], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][5], HIGH);
      break;
    case 1:
      digitalWrite(scoreDisplayPins[displayIndex][1], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][2], HIGH);
      break;
    case 2:
      digitalWrite(scoreDisplayPins[displayIndex][0], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][1], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][3], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][4], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][6], HIGH);
      break;
    case 3:
      digitalWrite(scoreDisplayPins[displayIndex][0], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][1], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][2], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][3], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][6], HIGH);
      break;
    case 4:
      digitalWrite(scoreDisplayPins[displayIndex][1], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][2], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][5], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][6], HIGH);
      break;
    case 5:
      digitalWrite(scoreDisplayPins[displayIndex][0], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][2], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][3], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][5], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][6], HIGH);
      break;
    case 6:
      digitalWrite(scoreDisplayPins[displayIndex][0], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][2], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][3], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][4], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][5], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][6], HIGH);
      break;
    case 7:
      digitalWrite(scoreDisplayPins[displayIndex][0], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][1], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][2], HIGH);
      break;
    case 8:
      digitalWrite(scoreDisplayPins[displayIndex][0], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][1], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][2], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][3], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][4], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][5], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][6], HIGH);
      break;
    case 9:
      digitalWrite(scoreDisplayPins[displayIndex][0], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][1], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][2], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][3], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][5], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][6], HIGH);
      break;
    default:
      digitalWrite(scoreDisplayPins[displayIndex][0], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][1], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][2], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][3], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][4], HIGH);
      digitalWrite(scoreDisplayPins[displayIndex][5], HIGH);
      break;
  }
}