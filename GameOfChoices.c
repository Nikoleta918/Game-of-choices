#include <stdio.h>
#include <stdlib.h>
#include <time.h>   
#include <windows.h>

//variables
char characterLetter;
int enemyPower;
int fullPower;
const char *enemyName;

//struct that stores the players inputs
struct Player{
    char weaponLetter;
    char armorLetter;
    char companionLetter;
};

//structs that stores the players powerups
struct Powerups{
    int weaponPower;
    int armorPower;
    int companionPower;
};

char chooseWeapon(struct Player p);
char chooseArmor(struct Player p);
char chooseCompanion(struct Player p);

//function that prompts the player to choose weapon
char chooseWeapon(struct Player p){
    printf("Choose a weapon:\n");
    printf("________________\n");
    printf("|   a)Excalibur |\n");
    printf("|   b)Vijaya    |\n");
    printf("|   c)Murasame  |\n");
    printf("|   d)Dainsleif |\n");
    printf("________________\n");
    scanf(" %c",&p.weaponLetter);
    return p.weaponLetter;
}

//function that prompts the player to choose armor
char chooseArmor(struct Player p){
    printf("Choose armor:\n");
    printf("_________________________\n");
    printf("|   a)Armor of Achilles  |\n");
    printf("|   b)Srivatsa           |\n");
    printf("|   c)Megingjoaroa       |\n");
    printf("|   d)Seven-league boots |\n");
    printf("_________________________\n");
    scanf(" %c",&p.armorLetter);
    return p.armorLetter;
}

//function that prompts the player to choose companion
char chooseCompanion(struct Player p){
    printf("Choose companion:\n");
    printf("__________________\n");
    printf("|   a)Cerberus    |\n");
    printf("|   b)Pegasus     |\n");
    printf("|   c)Wood Sprite |\n");
    printf("|   d)Selkie      |\n");
    printf("__________________\n");
    scanf("  %c",&p.companionLetter);
    return p.companionLetter;
}

//code to keep the programm running after finishing the game
void myflush ( FILE *in )
{
  int ch;

  do
    ch = fgetc ( in ); //Taking input single character
  while ( ch != EOF && ch != '\n' ); //while the input is not the end of file or change of line

  clearerr ( in );  //clears the end-of-file and error indicators for the given stream.
}

void mypause ( void ) 
{ 
  printf ( "Press [Enter] to continue . . ." );
  fflush ( stdout );   //fflush clears the output buffer and moves buffered data to console
  getchar();
} 


//function that checks the user input and chooses the right power points for the weapon
int weaponChoice(struct Player p,struct Powerups power){
    switch(p.weaponLetter){
    case 'a':
        printf("The sword King Arthur got from the lady of the lake\n");
        power.weaponPower=90;
        break;
    case 'b':
        printf("The bow of Karna, one of the greatest hero of the Hindu epic Mahabharata\n");
        power.weaponPower=90;
        break; 
    case 'c':
        printf("A magical katana, it said the blade can moist itself to wash off the blood stain for keeping it sharp\n");
        power.weaponPower=50;
        break;
    case 'd':
        printf("King Högni's sword that gave wounds that never healed and could not be unsheathed without killing a man\n");
        power.weaponPower=70;
        break;  
    default:
          printf("Invalid weapon\n");
          power.weaponPower=0;
          break;
    }
        return power.weaponPower;
}

//function that checks the user input and chooses the right power points for the armor
int armorChoice(struct Player p,struct Powerups power){
    switch(p.armorLetter){
    case 'a':
        printf("created by Hephaestus and said to be impenetrable\n");
        power.armorPower=100;
        break;
    case 'b':
        printf("the shield of Vishnu, said to be manifested in the god's chest\n");
        power.armorPower=80;
        break;
    case 'c':
        printf(" a magic belt worn by the god Thor\n");
        power.armorPower=60;
        break;
    case 'd':
        printf("a pair of boots said to allow the wearer to make strides of seven leagues in length\n");
        power.armorPower=20;
    default:
        printf("Invalid armor\n");
        power.armorPower=0;
        break;
    }
    return power.armorPower;
}

//function that checks the user input and chooses the right power points for the companion
int companionChoice(struct Player p,struct Powerups power){
    switch(p.companionLetter){
    case 'a':    
        printf("A three-headed dog and it guards the gate to hell\n");
        power.companionPower=80;
        break;
    case 'b':
        printf("a winged horse,good-natured and peace-loving\n");
        if(enemyName=="Chimera"){
            power.companionPower=300;
        }
        else{
            power.companionPower=50;
        }
        break;
    case 'c':
        printf("a small creature with knobby, woody exteriors, leafy extensions, and beady dark eyes. It lives in trees\n");
        power.companionPower=1;
        break;
    case 'd':
        printf("a creature that transforms into a human on land and a seal in water\n");
        power.companionPower=50;
        break;
    default:
        printf("Invalid companion\n");
        power.companionPower=0;
        break;
    }
    return power.companionPower;
}

//calculate randomly a number from 1 to 4 (with the rand function) and return an enemy for the player to defeat
int randomEnemy(){
    int lower=1;
    int upper=4;

    srand ( time(NULL) ); //srand is a random number generator function which will randomize the number produced by rand function
    int enemy=(rand() % (upper - lower + 1)) + lower ; //setting limits to the rand function,so chooses only from 1 to 4

    switch (enemy)
    {
    case 1:
        enemyName="Dracula";
        printf("The enemy is %s \n",enemyName);
        printf("A former prince of Wallachia that now feeds on blood\n");
        enemyPower=200;
        break;
    case 2:
        enemyName="Yeti";
        printf("The enemy is %s \n",enemyName);
        printf(" a large, bipedal ape-like creature that is covered with white hair, and it has large, sharp teeth\n");
        enemyPower=100;
        break;
    case 3:
        enemyName="Chimera";
        printf("The enemy is %s \n",enemyName);
        printf("A chimera has the body of a lion, the legs and hooves of a goat, and the tail of a snake's body\n");
        enemyPower=400;
        break;
    case 4:
        enemyName="Grandpa Peter";
        printf("The enemy is %s \n",enemyName);
        printf("Be carefull he is the wildest of them all\n");
        enemyPower=5;
        break;
    default:
        break;
    }
    return enemyPower;
}

void Battle(int enemyPower,struct Powerups power){
    struct Player p;
    int i;

    p.weaponLetter=chooseWeapon(p);  //ask player for weapon input
    int weapon=weaponChoice(p,power);  //calculate the weapon points
    p.armorLetter=chooseArmor(p);    //ask player for armor input
    int armor=armorChoice(p,power);    //calculate the armor points
    p.companionLetter=chooseCompanion(p);  //ask player for companion input
    int companion=companionChoice(p,power);    //calculate the companion points

    for(i=0;i<3;i++){     //wait for 3 seconds and print dots for a more ''realistic'' game feeling
        printf(".");
        Sleep(1000);
    }
    printf("\n");

    fullPower =weapon+armor+companion;  //adding the points

    if(enemyPower>fullPower){    //if player's power > enemy's power-->he wins,else-->he loses
        printf("You lose\n");
        printf("enemypower is: %d \n",enemyPower);
        printf("your power is: %d \n",fullPower);
    }
    else{
        printf("You win\n");
        printf("enemypower is: %d \n",enemyPower);
        printf("your power is: %d \n",fullPower);
    }

}
int main(){
    struct Player p;
    struct Powerups power;
    int i;

    printf("Welcome to the game\n");

    Sleep(1000);
    printf("\n");

    randomEnemy();

    Sleep(2000);
    printf("\n");

    Battle(enemyPower,power);

    //code used to keep the programm running until Enter is pressed
    myflush ( stdin );  //without this,mypause will read an existing character and execute,without waiting for user input
    mypause();  

    return 0;
}