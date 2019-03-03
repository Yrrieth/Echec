#include<stdio.h>

typedef char piece_pc; // piece_pc est un type contenant une variable char

piece_pc plateau [64]; // Variable globale qui est un tableau de type piece_pc

typedef int tb;

tb tab [64]; // Tableau supplementaire pour m'aider a placer les pieces

int libre (int i);

void initialise_chiffre ();

void affiche_chiffre ();

void initialise ();

void remplir (piece_pc pc, int i);

void affiche ();

void probleme ();

int verifie_roi_tour(int i);

int verifie_roi_fou (int i);

int verifie_roi_pion (int i);

int verifie_roi_cavalier (int i);

int verifie_roi( int i);

void deplacement_roi (piece_pc pc, int i);

int verifie_tour(int i);

void deplacement_tour (piece_pc pc,int i);

int verifie_fou (int i);

void deplacement_fou(piece_pc pc, int i);

void deplacement_reine (piece_pc pc, int i);

int verifie_cavalier (int i);

void deplacement_cavalier (piece_pc pc, int i);

int verifie_pion (int i);

void deplacement_pion (piece_pc pc, int i);

void selection ();

