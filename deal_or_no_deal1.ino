//Adam Brennan
//Due December 10th 2020
//Final Project, Deal or No Deal using lcd screen, rgbled, buttons
#include <LiquidCrystal.h>
//Initialise the Serial LCD.
LiquidCrystal lcd( 12,11,5,4,3,2); //These pin numbers are hard coded in on the serial backpack board.
int button3Pin = 13;
int button2Pin = 6;
int button1Pin = 7;
int RGBRedPin = 8; //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 9; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 10; //The blue RGB LED is connected pin 11 of the Arduino.
int check = 25;
int randNum = 0;
int cnt = 1;
int caseCnt = 6;
int openedCases = 0;
double finalAmount = 0;
char *howtoOne[] = {"Here's How To", "Blue Light =", "Red Light =", "Green Light =", "Now we will"};
char *howtoTwo[] = {"Play.", "User make choice", "Bad choice made", "Good choice made", "start the game."};
int lightColour[] = {RGBBluePin, RGBRedPin, RGBGreenPin};
double moneyValues[] = {0.01, 1, 5, 10, 25, 50, 75, 100, 200, 300, 400, 500, 750, 1000, 5000, 10000, 25000, 50000, 75000, 100000, 200000, 300000, 400000, 500000, 750000, 1000000};
double caseValues[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int caseNumber[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
double userCaseValue = 0;
int userCaseNum = 0;
void setup()
{
Serial.begin(9600);
pinMode(button1Pin, INPUT); //Setup button1 pin as an input pin.
pinMode(button2Pin, INPUT); //Setup button2 pin as an input pin.
pinMode(button3Pin, INPUT); //Setup button3 pin as an input pin.
pinMode(RGBRedPin, OUTPUT); //Setup red RGB LED pin as an output pin.
pinMode(RGBGreenPin, OUTPUT); //Setup green RGB LED pin as an output pin.
pinMode(RGBBluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.
lcd.begin (16,2); //Initialize the LCD.
}
void loop(){
lcd.clear();
lcd.setCursor(0,0); //goto first column and first line (x,0)
lcd.print("Welcome to"); //Print at cursor Location
lcd.setCursor(0,1); //goto first column and first line (x,0)
lcd.print("Deal or No Deal!"); //Print at cursor Location
//digitalWrite(RGBRedPin, HIGH);
    delay(3000);
 howToPlay();
 settingUpGame();
 userCase();
 mainGame();
}
void howToPlay()
{
for (int i = 0; i < 5; i++) {
lcd.clear();
lcd.setCursor(0,0); //goto first column and first line (x,0)
lcd.print(howtoOne[i]); //Print at cursor Location
lcd.setCursor(0,1); //goto Second column and first line (x,0)
lcd.print(howtoTwo[i]); //Print at cursor Location
digitalWrite(lightColour[i-1], HIGH);
  delay(3000);
digitalWrite(lightColour[i-1], LOW);
}

}
void settingUpGame()
{
  for (int x = 0; x < 26; x++)
  {
  randNum = random(check);
  caseValues[x] = moneyValues[randNum];
  Serial.println(randNum);
  Serial.println(caseValues[x]);
  moneyValues[randNum] = moneyValues[check];
  check--;
  }
  check = 0;
}
int userCase()
{
  lcd.clear();
  lcd.setCursor(0,0); //goto first column and first line (x,0)
  lcd.print("Time to pick"); //Print at cursor Location
  lcd.setCursor(0,1); //goto first column and first line (x,0)
  lcd.print("your case"); //Print at cursor Location
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0); //goto first column and first line (x,0)
  lcd.print("Case");
  lcd.setCursor(5,0); //goto first column and first line (x,0)
  lcd.print(check+1);
  digitalWrite(lightColour[0], HIGH);
  for (int v = 0; v < 1; v*0)
  { 
    if (digitalRead(button2Pin) == HIGH) 
  	{
    	check++;
        if (check+1 >= 27)
        {
          check = 0;
        }
        lcd.clear();
        lcd.setCursor(0,0); //goto first column and first line (x,0)
  		lcd.print("Case");
  		lcd.setCursor(5,0); //goto first column and first line (x,0)
  		lcd.print(check+1);
        delay(500);
        
    }
    if (digitalRead(button1Pin) == HIGH) 
  	{
    	check--;
        if (check+1 <= 0)
        {
          check = 25;
        }
        lcd.clear();
        lcd.setCursor(0,0); //goto first column and first line (x,0)
  		lcd.print("Case");
  		lcd.setCursor(5,0); //goto first column and first line (x,0)
  		lcd.print(check+1);
        delay(500);
    }
    if (digitalRead(button3Pin) == HIGH) 
  	{
      userCaseValue = caseValues[check];
      userCaseNum = check + 1;
      caseValues[check] = 0;
      caseNumber[check] = 0;
      //Serial.print(userCaseValue);
      
      delay(500);
      digitalWrite(lightColour[0], LOW);
      return 0;
    }
  }
}
void mainGame()
{
  for(int m = 0; m < 1; m*0)
  {
  lcd.clear();
  lcd.setCursor(0,0); //goto first column and first line (x,0)
  lcd.print("Round"); //Print at cursor Location
  lcd.setCursor(6,0); //goto first column and first line (x,0)
  lcd.print(cnt); //Print at cursor Location
  lcd.setCursor(0,1); //goto first column and first line (x,0)
  lcd.print("Open "); //Print at cursor Location
  lcd.setCursor(5,1); //goto first column and first line (x,0)
  lcd.print(caseCnt); //Print at cursor Location
  lcd.setCursor(7,1); //goto first column and first line (x,0)
  lcd.print("Cases"); //Print at cursor Location
  delay(3000);
  Serial.print(userCaseValue);
    for (int n = 0; n < 7-(cnt); n++)
    {
      Serial.print("hi");
      lcd.clear();
      buttonControls();
      openedCases++;
      lcd.clear();
      if (caseCnt-1 == 0 && cnt < 6)
      {
        caseCnt = 7-cnt;
      }
      if (caseCnt == 1 && cnt >= 6)
      {
        caseCnt = 1;
      }
      else
      {
 	  lcd.setCursor(0,0); //goto first column and first line (x,0)
  	  lcd.print("Open"); //Print at cursor Location
      lcd.setCursor(5,0); //goto first column and first line (x,0)
  	  lcd.print(caseCnt-1); //Print at cursor Location
      lcd.setCursor(7,0); //goto first column and first line (x,0)
  	  lcd.print("More"); //Print at cursor Location
      lcd.setCursor(0,1); //goto first column and first line (x,0)
  	  lcd.print("Cases"); //Print at cursor Location
      delay(3000);
      caseCnt--;
      }
    }
    banker();
    if (cnt <= 6)
    {
      caseCnt = 1;
    }
    cnt++;
    caseCnt = 7-cnt;
    if(cnt == 11)
    {
      swapOrNo();
    }
  }
}
double banker()
{ // runs bank code
  // Ran to decide bankers offer
  // https://www.ultraboardgames.com/deal-or-no-deal/game-rules.php
  finalAmount = 0; 
  finalAmount = finalAmount + userCaseValue;
  for (int vv = 0; vv < 26; vv++) // Loops adds values
  {
    finalAmount = finalAmount + caseValues[vv];
  }
  finalAmount = finalAmount / (26-openedCases); // divides all values by cases still on the board
  lcd.clear();
  lcd.setCursor(0,0); //goto first column and first line (x,0)
  lcd.print("Bank Calling");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(finalAmount); //Print at cursor Location
  lcd.setCursor(0,1);
  lcd.print("Deal Or No Deal?");
  for (int y = 0; y < 1; y*0)
  {
    if (digitalRead(button2Pin) == HIGH) // Returns if user takes no deal
    {
      if (26-openedCases == 2)
      {
        swapOrNo();
      }
      return 0;
      
    }
    if (digitalRead(button1Pin) == HIGH) // goes to deal method if user takes deal
    {
      deal();
    }
  }
}
int buttonControls() 
{// controls when user is using menu to pick cases
  check = 0;
  for (int v = 0; v < 1; v*0)
      	{
      		if (caseValues[check] == 0.00) // skips already picked cases
        	{
          		check++;
        	}
       		else
       		{
         	v = 1;
       		}
      	}
  lcd.setCursor(0,0); //goto first column and first line (x,0)
  lcd.print("Case"); //Print at cursor Location
  lcd.setCursor(5,0); //goto first column and first line (x,0)
  lcd.print(check+1); //Print at cursor Location
  for (int o = 0; o < 1; 0*0) // inf loop waits for user input
    {
    	if (digitalRead(button2Pin) == HIGH) // shifts up values 
  		{
    	check++;
        for (int v = 0; v < 1; v*0)
      	{
      		if (caseValues[check] == 0.00)
        	{
          		check++;
        	}
       		else
       		{
         	v = 1;
       		}
      	}
        if (check+1 >= 27) // case 1 to 26
        {
          check = 0;
          for (int v = 0; v < 1; v*0)
      	{
      		if (caseValues[check] == 0.00)
        	{
          		check++;
        	}
       		else
       		{
         	v = 1;
       		}
      	}
        }
        lcd.clear();
        lcd.setCursor(0,0); //goto first column and first line (x,0)
  		lcd.print("Case");
  		lcd.setCursor(5,0); //goto first column and first line (x,0)
  		lcd.print(check+1);
        delay(500);
        
    }
    if (digitalRead(button1Pin) == HIGH) //shifts down values
  	{
    	check--;
      for (int v = 0; v < 1; v*0)
      {
      if (caseValues[check] == 0.00)
        {
          check--;
        }
       else
       {
         v = 1;
       }
      }
        if (check+1 <= 0)
        {
          check = 25;
          for (int v = 0; v < 1; v*0)
      {
      if (caseValues[check] == 0.00)
        {
          check--;
        }
       else
       {
         v = 1;
       }
      }
        }
        lcd.clear();
        lcd.setCursor(0,0); //goto first column and first line (x,0)
  		lcd.print("Case");
  		lcd.setCursor(5,0); //goto first column and first line (x,0)
  		lcd.print(check+1);
        delay(500);
    }
    if (digitalRead(button3Pin) == HIGH) 
  	{
      digitalWrite(lightColour[0], LOW);
      lcd.clear();
      lcd.setCursor(0,0); //goto first column and first line (x,0)
  	  lcd.print("Case");
      lcd.setCursor(5,0); //goto first column and first line (x,0)
  	  lcd.print(check+1);
      lcd.setCursor(7,0); //goto first column and first line (x,0)
  	  lcd.print("Has.");
      delay(500);
      lcd.print("Has..");
      delay(500);
      lcd.print("Has...");
      delay(500);
      Serial.print(caseValues[check]);
      if (caseValues[check] <= 750)
      {
        lcd.clear();
        lcd.setCursor(0,0); //goto first column and first line (x,0)
  	  	lcd.print(caseValues[check]);
      	lcd.setCursor(0,1); //goto first column and first line (x,0) 
        lcd.print("That's Good!");
        digitalWrite(lightColour[2], HIGH);
        delay(2000);
        digitalWrite(lightColour[2], LOW);
      }
      else
      {
        lcd.clear();
        lcd.setCursor(0,0); //goto first column and first line (x,0)
  	  	lcd.print(caseValues[check]);
      	lcd.setCursor(0,1); //goto first column and first line (x,0) 
        lcd.print("Oh No!");
        digitalWrite(lightColour[1], HIGH);
        delay(2000);
        digitalWrite(lightColour[1], LOW);
      }
      caseValues[check] = 0;
      //Serial.print(userCaseValue);
      digitalWrite(lightColour[0], HIGH);
      return 0;
    }
   }
}
void deal() 
{ // if user decides deal during the game
  digitalWrite(lightColour[0], LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("You Took The");
  lcd.setCursor(0,1);
  lcd.print("Deal");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Was it a good");
  lcd.setCursor(0,1);
  lcd.print("Deal?");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("The case you");
  lcd.setCursor(0,1);
  lcd.print("chose was");
  lcd.setCursor(10,1);
  lcd.print(userCaseNum);
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Your Case Held");
  delay(2000);
  lcd.setCursor(0,1);
  lcd.print(userCaseValue);
  delay(3000);
  if (userCaseValue < finalAmount) // if users deal higher than case
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("You Made A Good");
    lcd.setCursor(0,1);
    lcd.print("Deal! Game Over.");
    digitalWrite(lightColour[2], HIGH);
    delay(20000);
  }
  else // if users deal lower than case
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("You Made A Bad");
    lcd.setCursor(0,1);
    lcd.print("Deal! Game Over.");
    digitalWrite(lightColour[1], HIGH);
    delay(20000);
  }
}
void swapOrNo()
{ // used at end of game if user swaps case or not
  check = 0;
  lcd.clear();
  for (int v = 0; v < 1; v*0)
      	{
      		if (caseValues[check] == 0.00) // finds last case
        	{
          		check++;
        	}
       		else
       		{
         	v = 1;
       		}
  }
  lcd.setCursor(0,0);
  lcd.print("Swap or No Swap?");
  for (int v = 0; v < 1; v*0)
  {
    if (digitalRead(button2Pin) == HIGH) // user swaps case
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("You swapped");
      lcd.setCursor(0,1);
      lcd.print("New case has");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(caseValues[check]);
      delay(2000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Original Case");
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print(userCaseValue);
      delay(3000);
      if (userCaseValue < caseValues[check]) // good choice
      {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("good Swap");
        delay(20000);
      }
      else // bad choice
      {
         lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("bad swap");
        delay(20000);
      }
    }
    if (digitalRead(button1Pin) == HIGH) // if user keeps case
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("You kept");
      lcd.setCursor(0,1);
      lcd.print("your case");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(userCaseValue);
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("Was inside");
      delay(2000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Original Case");
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print(userCaseValue);
    }
    if (userCaseValue < caseValues[check]) // bad choice
      {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("bad keep");
      lcd.setCursor(0,1);
      lcd.print("Game Over");
        delay(20000);
      }
      else // good choice
      {
         lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("good keep");
        lcd.setCursor(0,1);
      lcd.print("Game Over");
        delay(20000);
      }
  }
  delay(5000);
}