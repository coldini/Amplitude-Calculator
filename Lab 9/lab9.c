
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


const char COLOR_CODES [10] [7] = { "black", "brown", "red", "orange",
"yellow", "green", "blue", "violet",
"grey", "white" };


char *input_color_codes (char *prompt);
int calculate_resistance( char band1[ ], char band2[ ], char band3[ ]);
void display_colors(const char a[10][7]);
char *ohms_maker(char band3[]);
double tolerance_maker(char band4[], int resistance);
char *percent_maker(char band4[]);
void calculate_tolerances( int resistance, double tolerance,
double *low, double *high );
void print_all( char band1[], char band2[], char band3[], char band4[], int resitance,char *ohms, double tolerance, double *high, double *low);




/*
* Programmer Name:Colden Jeanmnonod
*Lab Name: resist
* Date: NOV 15 2023
* DUE DATE NOV 22 2023
* Assingment: lab 9
* Class and Semester: CIS:1057 section: 004
* Description: This program is a reistance calculator
* that should accurately calculate the resistance of a
*resistor
*/

void main(){
  display_colors(COLOR_CODES);
  char *band1 = input_color_codes( "Band 1");
  char *band2 = input_color_codes("Band 2");
  char *band3 = input_color_codes("Band 3 not grey or white");
  char *band4 = input_color_codes("Band 4 you may also enter blank");
  double low = 0.0;
  double high = 0.0;
  int resistance = calculate_resistance(band1,band2,band3);
  char *ohm = ohms_maker(band3);
  double tolerance =	tolerance_maker(band4, resistance);
calculate_tolerances( resistance,  tolerance, &low, &high);
print_all(band1, band2, band3, band4, resistance,ohm,  tolerance, &low, &high);


}
void display_colors( const char a[10][7]){
  /*
  *Function Name: display_colors
  *Description: displays the colors available in a neat list
  *preconditions: a[][]
  *postcondition: none
  *Global: none
  *Returns: none
  */

  printf("Your list of available colors are:\n");
  for(int i = 0 ; i < 10; i++){
    for(int j = 0; j < 7; j++){
      printf("%c", a[i][j]);
    }
    printf("\n");
  }
  
}

char *input_color_codes ( char *prompt){
  /*
  *Function Name: *input_color_codes
  *Description: takes the user input for a color and then returns that color to the correct band, while also checking to see if it is the correct color
  *preconditions: *prompt
  *postcondition: none
  *Global: None
  *returns band
  */

  int input = 0;

  char color[7];


  while(input == 0){
     printf("Please input the color of %s \n", prompt);
                 fgets(color, 7, stdin);
    for(int i = 0; i < 7; i++){
      color[i] = tolower(color[i]);
    }
    for(int j = 0; j < 7; j++){
      if(color[j] == '\n'){

        color[j] = '\0';
      }
    }
    if( (strncmp(color, "green", 7) == 0) || (strncmp(color, "blue", 7) == 0) || (strncmp(color, "violet", 7) == 0) || (strncmp(color, "yellow", 7) == 0) || (strncmp(color, "orange", 7) == 0) || (strncmp(color, "red", 7) == 0) || (strncmp(color, "brown", 7) == 0) || (strncmp(color, "black", 7) == 0) || (strncmp(color, "white", 7) == 0) || (strncmp(color, "grey", 7) == 0) || (strncmp(color, "blank", 7) )  ){
      input = 1;

    }

    if(input == 0){
      printf("Please put in a valid color.");
    }
  }

  char *band = (char*)malloc(7* sizeof(char));
    strcpy(band, color);
    return band;


}


int calculate_resistance( char band1[ ], char band2[ ], char band3[ ]){
  /*
  *Function Name: calculate_resistance
  *Description: Calculates the number that the resistance should be.
  *preconditions: band1[], band2[], band3[]
  *postcondition: none
  *Global: None
  *returns resistance
  */

  
  int resistance = 0;
  if( strncmp(band1, "black", 7)==0 ){
    resistance += 0;
  }else if(  strncmp(band1, "brown", 7)==0   ){
    resistance +=10;
  }else if(   strncmp(band1, "red", 7)==0  ){
    resistance +=20;
  }else if(  strncmp(band1, "orange", 7)==0 ){
    resistance += 30;
  }else if(  strncmp(band1, "yellow", 7)==0 ){
    resistance += 40;
  }else if(   strncmp(band1, "green", 7)==0 ){
    resistance += 50;
  }else if(   strncmp(band1, "blue", 7)==0 ){
    resistance += 60;

  }else if(  strncmp(band1, "violet", 7) ==0 ){
    resistance += 70;
  }else if(  strncmp(band1, "grey", 7)==0  ){
    resistance+= 80;
  }else if(  strncmp(band1, "white", 7) ==0 ){
    resistance += 90;
  }


  if( strncmp(band2, "black", 7) ==0 ){
    resistance += 0;

  }else if(  strncmp(band2, "brown", 7)==0 ){
    resistance += 1;
  }else if(   strncmp(band2, "red", 7) == 0 ){
    resistance +=2;

  }else if(   strncmp(band2, "orange", 7) ==0){
    resistance += 3;
  }else if(   strncmp(band2, "yellow", 7)==0 ){
    resistance += 4;
  }else if(  strncmp(band2, "green", 7) ==0 ){
    resistance += 5;
  }else if(   strncmp(band2, "blue", 7)==0 ){
    resistance +=6;
  }else if(  strncmp(band2, "violet", 7) ==0 ){
    resistance +=7;
  }else if(  strncmp(band2, "grey", 7) ==0){
    resistance += 8;
  }else if(   strncmp(band2, "white", 7) ==0){
    resistance += 9;
  }

  if( strncmp(band3, "black", 7) ==0){
    resistance *= 1;	
  }else if(   strncmp(band3, "brown", 7)==0 ){
    resistance *= 10;
  }else if(   strncmp(band3, "red", 7)==0 ){
    resistance *= 100;
  }else if(   strncmp(band3, "orange", 7)==0 ){
    resistance *= 1;
  }else if(  strncmp(band3, "yellow", 7) ==0){ 
    resistance *= 10;
  }else if(  strncmp(band3, "green", 7)==0 ){
    resistance *= 100;
  }else if(  strncmp(band3, "blue", 7)==0 ){
    resistance *= 1;
  }else if(  strncmp(band3, "violet", 7)==0 ){
    resistance *= 10;

  }

  return resistance;
}


char *ohms_maker(char band3[]){
  /*
  *Function Name: *ohms_maker
  *Description: returns the correct terminology of ohms depending on what color band3 is
  *preconditions: band3[]
  *postcondition: none
  *Global: None
  *returns ohms
  */

  
  char *ohms = "none";

  if(strncmp(band3, "black", 7) == 0 || strncmp(band3, "brown", 7) == 0 || strncmp(band3, "red", 7) == 0){
       ohms = "ohms";
  }else if(strncmp(band3, "orange", 7)==0 || strncmp(band3, "yellow", 7)== 0|| strncmp(band3, "green", 7)== 0){
    ohms = "kilo-ohms";
  }else if(strncmp(band3, "blue", 7)==0 || strncmp(band3, "violet", 7) ==0){
    ohms = "milo-ohms";
  }
  return ohms;


}


double tolerance_maker(char band4[], int resistance){
  /*
  *Function Name: tolerance_maker
  *Description: returns the tolerance of the resistor based on the color of band4
  *preconditions: band4[], resistance
  *postcondition: none
  *Global: None
  *returns tolerance
  */

  double tolerance = 0;
  if( strncmp(band4, "black", 7) ==0 || strncmp(band4, "orange", 7) == 0 || strncmp(band4, "yellow", 7) == 0 || strncmp(band4, "white", 7) == 0 || strncmp( band4, "blank", 7 ) == 0){
    tolerance = 20;
  }else if(  strncmp(band4, "brown", 7)==0 ){
    tolerance = 1;
  }else if( strncmp(band4, "red", 7) == 0 ){
    tolerance  = 2;
  }else if( strncmp(band4, "green", 7) == 0 ){
                tolerance =0.5;
        }else if( strncmp(band4, "violet", 7) == 0 ){
                tolerance =0.1;
        }else if( strncmp(band4, "blue", 7) == 0 ){
                tolerance =0.25;
        }else if( strncmp(band4, "grey", 7) == 0 ){
                tolerance =0.05;
        }
  return tolerance;
}


void calculate_tolerances( int resistance, double tolerance,
double *low, double *high ){
  /*
  *Function Name: calculate tolerance
  *Description: Will calculate the high and low of the resistances based off of the tolerance
  *preconditions: resistance, tolerance
  *postcondition: *low, *high
  *Global: None
  *returns low, high
  */

  *low = resistance - (resistance * (tolerance/100));
  *high = resistance + (resistance * (tolerance/100));  
}

void print_all( char band1[], char band2[], char band3[], char band4[], int resitance, char *ohms, double tolerance, double *high, double *low){
  /*
  *Function Name: print_all
  *Description: Prints out the results of the various calculations
  *preconditions: band1[], band2[], band3[], band4[]
  *preconditions: reistance, *ohms, tolerance, *high, *low
  *postcondition: none
  *Global: None
  *returns: none
  */

  printf("Band 1: %s\n", band1);
  printf("Band 2: %s\n", band2);
  printf("Band 3: %s\n", band3);
  printf("Band 4: %s\n", band4);
  printf("Resistance: %d%s\n", resitance, ohms);
  printf("The percentage of tolerance is %lf %c\n", tolerance, '%');
  printf("The low value and high value of the tolerance are, low %lf, high %lf \n", *low, *high);


  
}
