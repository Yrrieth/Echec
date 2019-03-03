#include<stdio.h>

#include<stdio.h>
#include"echec.h"

int main (){
  int i;
  initialise_chiffre();
  affiche_chiffre();
  printf("\n");
  
  initialise();
  probleme();
  printf("\n");

  selection();

}
