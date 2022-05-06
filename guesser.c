#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*finds number between 0 and max<=difficulty*(RAND_MAX-500)/10+500*/
int ranNumFinder(int difficulty){
  srand((int)time(0));
  int userNum=-1;
  int max=rand()%(difficulty*((RAND_MAX-500)/10)+500);
  while(!(max>=userNum && userNum>=0)){
    printf("Pick a number between 0 and %d (inclusive)",max);
    scanf("%d",&userNum);
    }
  int count=1;
  int firstGuess=rand()%(max+1);
  int secondGuess;
  char responseOne;
  if (firstGuess==userNum){
    printf("Is your number %d?(y/n)",firstGuess);
    scanf("%c",&responseOne);
    if(responseOne != 'y' || responseOne !='Y'){
      printf("Yes it is. Your number is %d",firstGuess);
      return firstGuess;
    }
    else{
    printf("The number is %d. First Try! Hooray!",firstGuess);
    return firstGuess;
    }
  }
    //iteratatively find the number by narrowing on it's position
  else{
    int ceiling=max;
    int floor=0;
    int currentGuess=firstGuess;
    int lastGuess=0;
    int gap=currentGuess-lastGuess;
    char highLowNow;


    
    while(currentGuess!=userNum){
      count++;//keep track of number of guesses
      while((highLowNow!='h' || highLowNow=='l') && (highLowNow=='h' || highLowNow!='l')){
        printf("\nIs your number %d?\nWas I Too high or too low?(h/l)", currentGuess);
        scanf("%c",&highLowNow);
      }
      
      while(highLowNow=='h'){
        //move down
        ceiling=currentGuess;
        
        currentGuess=(currentGuess+floor)/2+((currentGuess+floor)%2);
        if (floor==currentGuess){
          floor=0;
        }
        highLowNow='t';
      }
      while(highLowNow=='l'){
        floor=currentGuess;
        currentGuess=(currentGuess+ceiling)/2+((ceiling+currentGuess)%2);
        if(ceiling==currentGuess){
          ceiling=max;
        }
        highLowNow='t';
        
      }
      if(ceiling-floor<2){
        ceiling=max;
        floor=0;
        currentGuess=max/2+(max%2);
      }
      if(count>30){
        printf("Terrible");
      }
      if(count>50){
        printf("What is wrong with you");
      }
    }
        
          
    
      
    printf("your number is %d,and was found with %d guesses\n",currentGuess,count);
    return currentGuess;
  }
  }
  /*plays the game*/
  int main(){
    int play=1;
    while(play==1){
      int dif=20;
      while(!(10>=dif && dif>=0)){
        printf("Choose your difficulty level.(0-10)");
        scanf("%d",&dif);
      }
      int game = ranNumFinder(dif);
      char playAgain;
      while((playAgain!='y'||playAgain=='n')&&(playAgain=='y'||playAgain!='n')){
        printf("play again?(y/n)");
        scanf("%c",&playAgain);
        }
      if(playAgain=='n'){
        play=0;
      }
      } 
    return 0;}
