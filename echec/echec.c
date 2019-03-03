#include<stdio.h>
#include"echec.h"

int libre (int i){ // Si la case est vide, retourne vrai
  if (plateau [i] == '.'){
    return 1;
  }
  return 0;
}

void initialise_chiffre (){ // Pour m'aider a placer les pieces
  int i;
  for (i = 1; i <= 64; i = i + 1){
    tab [i] = i;
  }
}

void affiche_chiffre (){ // Affiche le plateau de nombre
  int i;
  for (i = 1; i <= 64; i = i + 1){
    printf("%3d", tab [i]);
    if (i%8 == 0){
      printf("\n");
    }
  }
}


void initialise (){ // Initialise le tableau de 1 a 64 par des points
  int i;
  for (i = 1; i <= 64; i = i + 1){
    plateau [i] = '.';
  }
}

void remplir (piece_pc pc, int i){ // Rempli une case d'une piece, pc est de type piece_pc
  if (libre (i) == 1){ // Si la case a la position i, contient un '.'
    plateau [i] = pc;
  }
}

void affiche (){ // Affiche le plateau
  int i;
  for (i = 1; i <= 64; i = i + 1){
    printf("%3c", plateau [i]);
    if (i%8 == 0){
      printf("\n");
    }
  }
}

void probleme (){ // Selectionne un probleme
  int n;
  printf("Choisissez le probleme (entre 0 et 4): \n");
  scanf("%d",&n);
  switch (n){
  case 0:
    printf("Majuscule joue et fait mat en 1 coup \n");
    remplir('T', 10);
    remplir('T', 17);
    remplir('R', 60);
    remplir('r', 7);
    affiche();
    return;
  case 1:
    printf("Majuscule joue et fait mat en 1 coup \n");
    remplir('F', 9);
    remplir('F', 49);
    remplir('P', 16);
    remplir('R', 55);
    remplir('r', 8);
    affiche();
    return;
  case 2:
    printf("Majuscule joue et fait mat en 1 coup \n");
    remplir('D', 9);
    remplir('R', 20);
    remplir('r', 5);
    affiche();
    return;
  case 3:
    printf("Majuscule joue et fait mat en 1 coup \n");
    remplir('T', 2);
    remplir('F', 44);
    remplir('P', 23);
    remplir('R', 20);
    remplir('r', 8);
    affiche();
    return;
  case 4:
    printf("Majuscule joue et fait mat en 1 coup \n");
    remplir('C', 29);
    remplir('t', 7);
    remplir('p', 15);
    remplir('p', 16);
    remplir('F', 23);
    remplir('R', 20);
    remplir('r', 8);
    affiche();
    return;
  }
}

int verifie_roi_tour(int i){ // Verifie si apres deplacement, le roi est mit en echec par une tour
  int p = i; // Position initiale
  while (i > 8){ // Verifie vers le haut
    i = i - 8;
    // Pour le roi, dans le cas d'un deplacement, verifie vers le haut si il y a une tour qui met le roi en echec
    if (libre (i) == 0){ // Si la case n'est pas vide
      if (plateau [i] == 'T' || plateau [i] == 'D'){ // Si cette case contient une tour ou une reine
	return 1;
      } 
    }
  }
  i = p; // i reprend sa position initiale
  
  while (i < 57){ // Verifie vers le bas
    i = i + 8;
    // Pour le roi, dans le cas d'un deplacement, verifie vers le bas si il y a une tour qui met le roi en echec
    if (libre (i) == 0){
      if (plateau [i] == 'T' || plateau [i] == 'D'){
	return 1;
      }
    }
  }
  i = p;
  
  while (i%8 != 0){ // Verifie vers la droite
    i = i + 1;
    // Pour le roi, dans le cas d'un deplacement, verifie vers la droite
    if (libre (i) == 0){
      if (plateau [i] == 'T' || plateau [i] == 'D'){
	return 1;
      }
    }
  }
  i = p;
  
  while (i%8 != 1){ // Verifie vers la gauche
    i = i - 1;
    // Pour le roi, dans le cas d'un deplacement, verifie vers la gauche
    if (libre (i) == 0){
      if (plateau [i] == 'T' || plateau [i] == 'D'){
	return 1;
      }
    }
  }
  i = p;
  return 0;
}

int verifie_roi_fou (int i){
  int p = i;
  // Dans le cas d'un deplacement depuis le haut/gauche vers bas/droite,
  // verifie depuis le haut/droite vers bas/gauche si il y a un roi
  while (i > 8 && i%8 != 0){  // Verifie en direction de la diagonale haut/droite
    i = i - 7;
    if (libre (i) == 0){ // Si la case n'est pas vide
      if (plateau [i] == 'F' || plateau [i] == 'D'){ // Si cette case contient un fou ou une reine
	return 1;
      } 
    }
  }
  i = p;
  
  while (i < 57 && i%8 != 1) { // Verifie en direction de la diagonale bas/gauche
    i = i + 7;
    if (libre (i) == 0){
      if (plateau [i] == 'F' || plateau [i] == 'D'){
	return 1;
      } 
    }
  }
  i = p;
  
  // Dans le cas d'un deplacement depuis le haut/droite vers bas/gauche,
  // verifie depuis le haut/gauche vers bas/droite si il y a un roi
  while (i%8 != 1 && i > 8){ // Verifie en direction de la diagonale gauche/haut
    i = i - 9;
    if (libre (i) == 0){
      if (plateau [i] == 'F' || plateau [i] == 'D'){
	return 1;
      } 
    }
  }
  i = p;
  
  while (i%8 != 0 && i < 57){ // Verifie en direction de la diagonale droite/bas
    i = i + 9;
    if (libre (i) == 0){
      if (plateau [i] == 'F' || plateau [i] == 'D'){
	return 1;
      } 
    }
  }
  i = p;
  return 0;
}

int verifie_roi_pion (int i){
  int p = i;
  if (i > 8 && i%8 != 0){
     i = i - 7;
    if (libre (i) == 0){
      if (plateau [i] == 'P'){
	return 1;
      } 
    }
  }
  i = p;

  if (i > 8 && i%8 != 1){
     i = i - 9;
    if (libre (i) == 0){
      if (plateau [i] == 'P'){
	return 1;
      } 
    }
  }
  i = p;
  return 0;
}

int verifie_roi_cavalier (int i){
  int p = i;
  while (i > 16 && i%8 != 0){ // Deplace 2 vers le haut, puis 1 a droite
    i = i - 15;
    if (libre (i) == 0){
      if (plateau [i] == 'C'){
	return 1;
      } 
    }
  }
  i = p;
  
  while (i > 8 && i%8 != 0 && i%8 !=7){ // Deplace 2 a droite, puis 1 vers le haut
    i = i - 6;
    if (libre (i) == 0){
      if (plateau [i] == 'C'){
	return 1;
      } 
    }
  }
  i = p;
  
  while (i%8 != 0 && i < 57 && i%8 != 7){ // Deplace 2 a droite, puis 1 vers le bas
    i = i + 10;
    if (libre (i) == 0){
      if (plateau [i] == 'C'){
	return 1;
      } 
    }
  }
  i = p;
  
  while (i%8 != 0 && i < 49){ // Deplace 2 vers le bas puis 1 a droite
    i = i + 17;
    if (libre (i) == 0){
      if (plateau [i] == 'C'){
	return 1;
      } 
    }
  }
  i = p;
  
  while (i%8 != 1 && i < 49){ // Deplace 2 vers le bas puis a gauche
    i = i + 15;
    if (libre (i) == 0){
      if (plateau [i] == 'C'){
	return 1;
      } 
    }
  }
  i = p;
  
  while (i%8 != 1 && i%8 != 2 && i < 57){ // Deplace 2 a gauche puis 1 vers le bas
    i = i + 6;
    if (libre (i) == 0){
      if (plateau [i] == 'C'){
	return 1;
      } 
    }
  }
  i = p;
  
  while (i%8 != 1 && i%8 != 2 && i > 8){ // Deplace 2 a gauche puis 1 vers le haut
    i = i - 10;
    if (libre (i) == 0){
      if (plateau [i] == 'C'){
	return 1;
      } 
    }
  }
  i = p;
    
  while (i%8 != 1 && i > 16){ // Deplace 2 vers le haut puis 1 a gauche
    i = i - 17;
    if (libre (i) == 0){
      if (plateau [i] == 'C'){
	return 1;
      } 
    }
  }
  i = p;
  return 0;
}

int verifie_roi( int i){
  verifie_roi_tour (i);
  verifie_roi_fou (i);
  verifie_roi_pion (i);
  verifie_roi_cavalier (i);
  if (verifie_roi_tour (i) == 1){
    return 1;
  }
  if (verifie_roi_fou (i) == 1){
    return 1;
  }
  if (verifie_roi_pion (i) == 1){
    return 1;
    }
  if (verifie_roi_cavalier (i) == 1){
    return 1;
  }
  return 0;
}

void deplacement_roi (piece_pc pc, int i){ // Deplacement possible d'un roi
  int p = i;
  int dplcmt_max = 8;        // Le nombre de deplacement maximum théorique, possible
  int dplcmt_echec = 0;      // Le nombre de cas d'echec, apres deplacement
  if (i > 8){                // Pour deplacer vers le haut
    plateau [i] = '.';       // Enleve la lettre 
    i = i - 8;               // Deplace vers le haut
    if (libre (i) == 1){     // Si la case est libre
      plateau [i] = pc;      // Pose la lettre sur la nouvelle case, ici 'r' sur  i - 8
      verifie_roi(i);        // Appelle la fonction verifie_roi
      if (verifie_roi (i) == 1){ // Si la fonction verifie_roi renvoie 1, ie que le roi est en echec meme apres un deplacement
	dplcmt_echec = dplcmt_echec + 1; // Alors, on incremente la variable dplcmt_echec
      }
      plateau [i] = '.';
    } else {                  // Sinon la case est deja occupe
      dplcmt_max = dplcmt_max - 1;  // Alors decremente le maximum de deplacement possible
    }
  } else {                   // Sinon, le roi se trouve sur le bord du plateau
    dplcmt_max = dplcmt_max - 1;    // Alors decremente le maximum de deplacement possible
  }
  i = p;
  
  if (i > 8 && i%8 != 0){ // Deplace vers le haut et a droite
    plateau [i] = '.';
    i = i - 7;
    if (libre (i) == 1){
      plateau [i] = pc;
      verifie_roi(i);
      if (verifie_roi (i) == 1){
	dplcmt_echec = dplcmt_echec + 1;
      }
      plateau [i] = '.';
    } else {
      dplcmt_max = dplcmt_max - 1;
    }
  } else {
    dplcmt_max = dplcmt_max - 1;
  }
  i = p;
  
  if (i%8 != 0){ // Deplace vers la droite
    plateau [i] = '.';
    i = i + 1;
    if (libre (i) == 1){
      plateau [i] = pc;
      verifie_roi(i);
      if (verifie_roi (i) == 1){
	dplcmt_echec = dplcmt_echec + 1;
      }
      plateau [i] = '.';
    } else {
      dplcmt_max = dplcmt_max - 1;
    }
  } else {
    dplcmt_max = dplcmt_max - 1;
  }
  i = p;
  
  if (i%8 != 0 && i < 57){ // Deplace vers la droite et en bas
    plateau [i] = '.';
    i = i + 9;
    if (libre (i) == 1){
      plateau [i] = pc;
      verifie_roi(i);
      if (verifie_roi (i) == 1){
	dplcmt_echec = dplcmt_echec + 1;
      }
      plateau [i] = '.';
    } else {
      dplcmt_max = dplcmt_max - 1;
    }
  } else {
    dplcmt_max = dplcmt_max - 1;
  }
  i = p;
  
  if (i < 57){ // Deplace vers le bas
    plateau [i] = '.';
    i = i + 8;
    if (libre (i) == 1){
      plateau [i] = pc;
      verifie_roi(i);
      if (verifie_roi (i) == 1){
	dplcmt_echec = dplcmt_echec + 1;
      }
      plateau [i] = '.';
    } else {
      dplcmt_max = dplcmt_max - 1;
    }
  } else {
    dplcmt_max = dplcmt_max - 1;
  }
  i = p;
  
  if (i < 57 && i%8 != 1){ // Deplace vers le bas et a gauche
    plateau [i] = '.';
    i = i + 7;
    if (libre (i) == 1){
      plateau [i] = pc;
      verifie_roi(i);
      if (verifie_roi (i) == 1){
	dplcmt_echec = dplcmt_echec + 1;
      }
      plateau [i] = '.';
    } else {
      dplcmt_max = dplcmt_max - 1;
    }
  } else {
    dplcmt_max = dplcmt_max - 1;
  }
  i = p;
  
  if (i%8 != 1) { // Deplace vers la gauche
    plateau [i] = '.';
    i = i - 1;
    if (libre (i) == 1){
      plateau [i] = pc;
      verifie_roi(i);
      if (verifie_roi (i) == 1){
	dplcmt_echec = dplcmt_echec + 1;
      }
      plateau [i] = '.';
    } else {
      dplcmt_max = dplcmt_max - 1;
    }
  } else {
    dplcmt_max = dplcmt_max - 1;
  }
  i = p;
  
  if (i%8 != 1 && i > 8) { // Deplace vers la gauche et en haut
    plateau [i] = '.';
    i = i - 9;
    if (libre (i) == 1){
      plateau [i] = pc;
      verifie_roi(i);
      if (verifie_roi (i) == 1){
	dplcmt_echec = dplcmt_echec + 1;
      }
      plateau [i] = '.';
    } else {
      dplcmt_max = dplcmt_max - 1;
    }
  } else {
    dplcmt_max = dplcmt_max - 1;
  }
  i = p;
  plateau [i] = pc;
  if (dplcmt_max == dplcmt_echec){ // Si le deplacement max theorique est egal au nombre de cas d'echec apres deplacement
    printf("Echec et mat ! \n");
    affiche();
  }
}

int verifie_tour(int i){
  int p = i;
  // Dans le cas d'un deplacement horizontal d'une tour, verifie verticalement si il y a un roi
  while (i > 8){ // Verifie vers le haut
    i = i - 8;
    if (libre (i) == 0){ // Si la case n'est pas vide
      if (plateau [i] == 'r'){ // Si cette case contient un roi
	deplacement_roi('r', i);
	return 1;
      } else { // Sinon, il s'agit d'une autre piece qui bloque
	break;
      }
    }
  }
  i = p;
  while (i < 57){ // Verifie vers le bas
    i = i + 8;
    if (libre (i) == 0){
      if (plateau [i] == 'r'){
	deplacement_roi('r', i);
	return 1;
      } else {
	break;
      }
    }
  }
  i = p;
  //  Dans le cas d'un deplacement vertical, verifie horizontalement si il y a un roi
  while (i%8 != 0){ // Verifie vers la droite
    i = i + 1;
    if (libre (i) == 0){
      if (plateau [i] == 'r'){
	deplacement_roi('r', i);
	return 1;
      } else {
	break;
      }
    }
  }
  i = p;
  while (i%8 != 1){ // Verifie vers la gauche
    i = i - 1;
    if (libre (i) == 0){
      if (plateau [i] == 'r'){
	deplacement_roi('r', i);
	return 1;
      } else {
	break;
      }
    }
  }
  i = p;
  return 0;
}

void deplacement_tour (piece_pc pc,int i){ // Deplacement possible d'une tour
  int p = i; // Stocke la position initiale de i
  verifie_tour(i); // Verifie si en i, la tour met echec le roi,
  if (verifie_tour(i) == 0){ // Si c'est faux, continue
    while (i%8 != 0){ // Deplace vers la droite
      plateau [i] = '.';
      i = i + 1;
      if (libre (i) == 1){ // Si la case suivante est libre
	plateau [i] = pc;
	verifie_tour(i);
	plateau [i] = '.';
      } else {
	break; // Sors de la boucle while si il y a une piece dans la case adjacente
      }
    }
    i = p; // i reprend sa valeur initiale
    
    while (i%8 != 1) { // Deplace vers la gauche
      plateau [i] = '.';
      i = i - 1;
      if (libre (i) == 1){
	plateau [i] = pc;
	verifie_tour(i);
	plateau [i] = '.';
      } else {
	break;
      }
    }
    i = p;
    
    while (i > 8){ // Deplace vers le haut
      plateau [i] = '.';
      i = i - 8;
      if (libre (i) == 1){
	plateau [i] = pc;
	verifie_tour(i);
	plateau [i] = '.';
      } else {
	break;
      }
    }
    i = p;
    
    while (i < 57){ // Deplace vers le bas
      plateau [i] = '.';
      i = i + 8;
      if (libre (i) == 1){
	plateau [i] = pc;
	verifie_tour(i);
	plateau [i] = '.';
      } else {
	break;
      }
    }
    i = p;
  }
  plateau [i] = pc;
}

int verifie_fou (int i){
  int p = i;
  // Dans le cas d'un deplacement depuis le haut/gauche vers bas/droite,
  // verifie depuis le haut/droite vers bas/gauche si il y a un roi
  while (i > 8 && i%8 != 0){  // Verifie en direction de la diagonale haut/droite
    i = i - 7;
    if (libre (i) == 0){ // Si la case suivante n'est pas libre
      if (plateau [i] == 'r'){
	deplacement_roi('r', i);
	return 1;
      } else {
	break; // Sors de la boucle while si il y a une autre piece dans la case adjacente
      }
    }
  }
  i = p;
  while (i < 57 && i%8 != 1) { // Verifie en direction de la diagonale bas/gauche
    i = i + 7;
    if (libre (i) == 0){
      if (plateau [i] == 'r'){
	deplacement_roi('r', i);
	return 1;
      } else {
	break;
      }
    }
  }
  i = p;
  // Dans le cas d'un deplacement depuis le haut/droite vers bas/gauche,
  // verifie depuis le haut/gauche vers bas/droite si il y a un roi
  while (i%8 != 1 && i > 8){ // Verifie en direction de la diagonale gauche/haut
    i = i - 9;
    if (libre (i) == 0){
      if (plateau [i] == 'r'){
	deplacement_roi('r', i);
	return 1;
      } else {
	break;
      }
    }
  }
  i = p;
  while (i%8 != 0 && i < 57){ // Verifie en direction de la diagonale droite/bas
    i = i + 9;
    if (libre (i) == 0){
      if (plateau [i] == 'r'){
	deplacement_roi('r', i);
	return 1;
      } else {
	break;
      }
    }
  }
  i = p;
  return 0;
}

void deplacement_fou(piece_pc pc, int i){ // Deplacement possible d'un fou
  int p = i; // Stocke la position initiale de i
  verifie_fou(i);
  if (verifie_fou(i) == 0){
    while (i > 8 && i%8 != 0){ // Deplace vers la diagonale haut/droite
      plateau [i] = '.';
      i = i - 7;
      if (libre (i) == 1){ // Si la case suivante est libre
	plateau [i] = pc;
	verifie_fou(i);
	plateau [i] = '.';
      } else {
	break; // Sors de la boucle while si il y a une piece dans la case adjacente
      }
    }
    i = p; // i reprend sa valeur initiale
    
    while (i%8 != 0 && i < 57){ // Deplace vers la diagonale droite/bas
      plateau [i] = '.';
      i = i + 9;
      if (libre (i) == 1){
	plateau [i] = pc;
	verifie_fou (i);
	plateau [i] = '.';
      } else {
	break;
      }
    }
    i = p;
    
    while (i < 57 && i%8 != 1) { // Deplace vers la diagonale bas/gauche
      plateau [i] = '.';
      i = i + 7;
      if (libre (i) == 1){
	plateau [i] = pc;
	verifie_fou(i);
	plateau [i] = '.';
      } else {
	break;
      }
    }
    i = p;
    
    while (i%8 != 1 && i > 8){ // Deplace vers la diagonale gauche/haut
      plateau [i] = '.';
      i = i - 9;
      if (libre (i) == 1){
	plateau [i] = pc;
	verifie_fou (i);
	plateau [i] = '.';
      } else {
	break;
      }
    }
    i = p;
  }
  plateau [i] = pc;
}

void deplacement_reine (piece_pc pc, int i){ // Le deplacement d'une reine est celui d'une tour et d'un fou
  deplacement_tour(pc, i);
  deplacement_fou(pc, i);
}

int verifie_cavalier (int i){
  int p = i;
  while (i > 16 && i%8 != 0){ // Deplace 2 vers le haut, puis 1 a droite
    i = i - 15;
    if (libre (i) == 0){
      if (plateau [i] == 'r'){
	deplacement_roi('r', i);
	return 1;
      } else {
	break;
      }
    }
  }
  i = p;
  
  while (i > 8 && i%8 != 0 && i%8 !=7){ // Deplace 2 a droite, puis 1 vers le haut
    i = i - 6;
    if (libre (i) == 0){
      if (plateau [i] == 'r'){
	deplacement_roi('r', i);
	return 1;
      } else {
	break;
      }
    }
  }
  i = p;
  
  while (i%8 != 0 && i < 57 && i%8 != 7){ // Deplace 2 a droite, puis 1 vers le bas
    i = i + 10;
    if (libre (i) == 0){
      if (plateau [i] == 'r'){
	deplacement_roi('r', i);
	return 1;
      } else {
	break;
      }
    }
  }
  i = p;
  
  while (i%8 != 0 && i < 49){ // Deplace 2 vers le bas puis 1 a droite
    i = i + 17;
    if (libre (i) == 0){
      if (plateau [i] == 'r'){
	deplacement_roi('r', i);
	return 1;
      } else {
	break;
      }
    }
  }
  i = p;
  
  while (i%8 != 1 && i < 49){ // Deplace 2 vers le bas puis a gauche
    i = i + 15;
    if (libre (i) == 0){
      if (plateau [i] == 'r'){
	deplacement_roi('r', i);
	return 1;
      } else {
	break;
      }
    }
  }
  i = p;
  
  while (i%8 != 1 && i%8 != 2 && i < 57){ // Deplace 2 a gauche puis 1 vers le bas
    i = i + 6;
    if (libre (i) == 0){
      if (plateau [i] == 'r'){
	deplacement_roi('r', i);
	return 1;
      } else {
	break;
      }
    }
  }
  i = p;
  
  while (i%8 != 1 && i%8 != 2 && i > 8){ // Deplace 2 a gauche puis 1 vers le haut
    i = i - 10;
    if (libre (i) == 0){
      if (plateau [i] == 'r'){
	deplacement_roi('r', i);
	return 1;
      } else {
	break;
      }
    }
  }
  i = p;
    
  while (i%8 != 1 && i > 16){ // Deplace 2 vers le haut puis 1 a gauche
    i = i - 17;
    if (libre (i) == 0){
      if (plateau [i] == 'r'){
	deplacement_roi('r', i);
	return 1;
      } else {
	break;
      }
    }
  }
  i = p;
  return 0;
}

void deplacement_cavalier (piece_pc pc, int i){
  int p = i;
  verifie_cavalier(i);
  if (verifie_cavalier (i) == 0){
    while (i > 16 && i%8 != 0){ // Deplace 2 vers le haut, puis 1 a droite
      plateau [i] = '.';
      i = i - 15;
      if (libre (i) == 1){
	plateau [i] = pc;
	verifie_cavalier(i);
	plateau [i] = '.';
      } else {
	break;
      }
    }
    i = p;
    
    while (i > 8 && i%8 != 0 && i%8 !=7){ // Deplace 2 a droite, puis 1 vers le haut
      plateau [i] = '.';
      i = i - 6;
      if (libre (i) == 1){
	plateau [i] = pc;
	verifie_cavalier(i);
	plateau [i] = '.';
      } else {
	break;
      }
    }
    i = p;
    
    while (i%8 != 0 && i < 57 && i%8 != 7){ // Deplace 2 a droite, puis 1 vers le bas
      plateau [i] = '.';
      i = i + 10;
      if (libre (i) == 1){
	plateau [i] = pc;
	verifie_cavalier(i);
	plateau [i] = '.';
      } else {
	break;
      }
    }
    i = p;
    
    while (i%8 != 0 && i < 49){ // Deplace 2 vers le bas puis 1 a droite
      plateau [i] = '.';
      i = i + 17;
      if (libre (i) == 1){
	plateau [i] = pc;
	verifie_cavalier(i);
	plateau [i] = '.';
      } else {
	break;
      }
    }
    i = p;
    
    while (i%8 != 1 && i < 49){ // Deplace 2 vers le bas puis a gauche
      plateau [i] = '.';
      i = i + 15;
      if (libre (i) == 1){
	plateau [i] = pc;
	verifie_cavalier(i);
	plateau [i] = '.';
      } else {
	break;
      }
    }
    i = p;
    
    while (i%8 != 1 && i%8 != 2 && i < 57){ // Deplace 2 a gauche puis 1 vers le bas
      plateau [i] = '.';
      i = i + 6;
      if (libre (i) == 1){
	plateau [i] = pc;
	verifie_cavalier(i);
	plateau [i] = '.';
      } else {
	break;
      }
    }
    i = p;
    
    while (i%8 != 1 && i%8 != 2 && i > 8){ // Deplace 2 a gauche puis 1 vers le haut
      plateau [i] = '.';
      i = i - 10;
      if (libre (i) == 1){
	plateau [i] = pc;
	verifie_cavalier(i);
	plateau [i] = '.';
      } else {
	break;
      }
    }
    i = p;
    
    while (i%8 != 1 && i > 16){ // Deplace 2 vers le haut puis 1 a gauche
      plateau [i] = '.';
      i = i - 17;
      if (libre (i) == 1){
	plateau [i] = pc;
	verifie_cavalier(i);
	plateau [i] = '.';
      } else {
	break;
      }
    }
    i = p;
  }
  plateau [i] = pc;
}


int verifie_pion (int i){
  int p = i;
  if (i > 8 && i%8 != 0){
    i = i - 7;
    if (libre (i) == 0){
      if (plateau [i] == 'r'){
	deplacement_roi('r', i);
	return 1;
      }
    }
  }
  i = p;

  if (i > 8 && i%8 != 1){
    i = i - 9;
    if (libre (i) == 0){
      if (plateau [i] == 'r'){
	deplacement_roi('r', i);
	return 1;
      }
    }
  }
  i = p;
  return 0;
}

void deplacement_pion (piece_pc pc, int i){
  int p = i;
  verifie_pion(i); // Verifie si en i, le pion met en echec le roi,
  if (verifie_pion(i) == 0){ 
    if (i > 8){
      plateau [i] = '.';
      i = i - 8;
      if (libre (i) == 1){
	plateau [i] = pc;
	verifie_pion (i);
	plateau [i] = '.';
      }
    }
    i = p;
  }
  plateau [i] = pc;
}

void selection (){ // Selectionne la piece a deplacer
  int i;
  piece_pc pc;
  for (i = 1; i < 64; i = i + 1){
     if (plateau [i] == 'T'){
      pc = 'T';
      deplacement_tour(pc, i);
    }
    if (plateau [i] == 'F'){
      pc = 'F';
      deplacement_fou(pc, i);
    }
    if (plateau [i] == 'D'){
      pc = 'D';
      deplacement_reine(pc, i);
    }
    if (plateau [i] == 'P'){
      pc = 'P';
      deplacement_pion(pc, i);
      }
    if (plateau [i] == 'C'){
      pc = 'C';
      deplacement_cavalier(pc, i);
    }
  }
}
