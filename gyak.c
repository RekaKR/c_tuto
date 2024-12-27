#include <stdio.h>

int main() {
  // -------- forditás, futtatás --------
  /*
  gcc -Wall -Wextra fő.c mellék.c
  ./a.exe (win)
  ./a.out
  */


  // -------- modularizálás --------
  /*
  fő.c
  --------
  #include "mellék.h"

  mellék.c
  --------
  #include "mellék.h"

  void függvény1(void){
    ...
  }

  int függvény2(void){
    ...
  }

  mellék.h
  --------
  #ifndef MELLÉK_H
  #define MELLÉK_H

  enum Vlmi {..}
  void fuggveny(void);
  int függvény2(void);

  #endif
  */


  // -------- tipusok, makrók --------
  // egész szám
  int szam1 = 3;

  // tört szám
  double tort_szam1 = 9.62;

  // karakter
  char karakter1 = 'a';

  // string
  char string1[] = "alma";
  char string2[] = {'a', 'l', 'm', 'a', '\0'};
  char string3[5];
  string3[0] = 'a';
  string3[1] = 'l';
  string3[2] = 'm';
  string3[3] = 'a';
  string3[4] = '\0';

  /*
  // typedef
  struct Pont {
    double x, y;
  };
  typedef struct Pont Pont;
 
  Pont p;
  
  //rövidebben
  typedef struct Pont1 {
    double x, y;
  } Pont1;
 
  Pont1 p;

  //még rövidebben:
  typedef struct {
    double x, y;
  } Pont3;
  */

  // makró
  #define NEV "\0IdeJönMindenFéleKarakter"

  // enum - felsoroló tipus
  /*ezek int-ek alapvetően*/
  enum NevEnum {
    ALMA, // ez 0
    KORTE, // ez 1
    KIWI = 9, // ez 9
    BANAN // ez 10
  };

  // struct - stuktúra tipus
  struct NevStruct {
    int valami;
    char masik_valami;
  };
  /*struct változó létrehozás*/
  struct NevStruct NevStruct;


  // -------- terminálról beolvasás, input --------
  // int input
  printf("adj meg egy szamot: ");
  int szam;
  scanf("%d", &szam);
  printf("ezt adtad meg: %d\n", szam);

  // double input
  printf("adj meg egy tort szamot: ");
  double tort_szam;
  scanf("%lf", &tort_szam);
  printf("ezt adtad meg: %f\n", tort_szam);

  // char input
  printf("adj meg egy karaktert: ");
  char karakter;
  scanf("%c", &karakter);
  printf("ezt adtad meg: %c\n", karakter);

  // string input
  printf("adj meg max 49 karakter hosszu szoveget: ");
  char string[50];
  scanf("%s", string);
  printf("ezt adtad meg: %s\n", string);

  // int tömb input
  int a[2];

  for (int i = 0; i < 2; i++) {
    printf("adj hozza egy szamot az a tombhoz: ");
    scanf("%i", &a[i]);
  }


  // -------- file-ból beolvasás --------
  /*
  r - megnyitás, olvasás
  w - készités, (felül)irás
  a - hozzáirás
  r+ - megnyitás, olvasás/(felül)irja az 0. karaktertől annyit, amennyit irunk bele
  w+ - készitése, olvasás/felülirja az egész file-t
  a+ - olvasás/hozzáirás
  */
  // megnyitás, elmentés
  FILE* file = fopen("file_neve.txt", "r");

  // hiba kezelés
  if (file == NULL) {
    perror("Error uzike1");
    return 1;
  }

  // első sor beolvasása - int
  int row;
  fscanf(file, "%d", &row);
  /* hibakezeléssel
  if (fscanf(file, "%d", &row) != 1) {
      fprintf(stderr, "Error uzike\n");
      fclose(file);
  }
  */

  // első két sor beolvasása - int
  int row1, row2;
  fscanf(file, "%d", &row1);
  fscanf(file, "%d", &row2);
  /* hibakezeléssel
  if (fscanf(file, "%d", &row1) != 1 || fscanf(file, "%d", &row2) != 1) {
      fprintf(stderr, "Error uzike\n");
      fclose(file);
  }
  */

  // mtx^10x10 számok beolvasása - intxint
  int mtx[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      fscanf(file, "%d", &mtx[i][j]);
      /* hibakezeléssel
      if (fscanf(file, "%d", &mtx[i][j]) != 1) {
        fprintf(stderr, "Error uzike\n");
        fclose(file);
        return 1;
      }
      */
    }
  }

  // mtx^3x3 karakterek beolvasása - charxchar
  char mtx1[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      do {
          fscanf(file, "%c", &mtx1[i][j]);
      } while (mtx1[i][j] == '\n' || mtx1[i][j] == ' ');
    }
  }

  // bezárás
  fclose(file);


  // -------- kiiratás, print --------
  // printelés
  /*szám, törtszám, karakter, string*/
  printf("%d, %f, %c, %s\n", szam1, tort_szam1, karakter1, string1);
  printf("%s, %s\n", string2, string3);

  // hiba printelése
  fprintf(stderr, "Ez egy szandekos hibauzenet.\n");
  
  // mtx^10x10 számok
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%d", mtx[i][j]);
    }
    
    printf("\n");
  }
  
  // mtx^3x3 karakterek printelés
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%c ", mtx1[i][j]);
    }
    
    printf("\n");
  }



  // -------- konvertálás tipusok között --------
  // int => float
  int i = 5;
  float f = i;

  // float => int (lecsapja a tört részt)
  float d = 5.75;
  int g = (int)d;

  // char => int
  char c = 'A';
  int c1 = c;

  // int => char
  int i3 = 65;
  char c3 = (char)i3; // int -> char

  return 0;
}
