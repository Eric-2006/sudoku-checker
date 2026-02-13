//Autor: Eric Buenavida Crespo

#include <stdio.h>

#define MIDA_S 16 //mida del sudoku
#define MIDA_R 4 //mida d'una regió
//NOTA: per verificar sudokus amb altres mides quadrades només cal canviar la mida del sudoku i de la regió.

int Llegir_Sudoku (int sudoku[MIDA_S][MIDA_S]);
void Imprimir_Sudoku (int sudoku[MIDA_S][MIDA_S]);
int Verificar_Sudoku (int sudoku[MIDA_S][MIDA_S]);

int main ()
{
  int sudoku[MIDA_S][MIDA_S], s;
  
  printf("Llegint sudoku...\n");
  s = Llegir_Sudoku (sudoku);
  if (s == -1)
  {
    return -1;
  }
  else
  {
    printf("Sudoku llegit.\n");
    Imprimir_Sudoku (sudoku);
    s = Verificar_Sudoku (sudoku);
    if (s == -1)
    {
      printf("La solució al Sudoku és incorrecta.\n");
      return -1;
    }
    else
    {
      printf("\nLa solució al Sudoku és correcta.\n");
    }
  }
}

int Llegir_Sudoku (int sudoku[MIDA_S][MIDA_S])
{
  int f, c; //files i columnes
  
  for (f = 0; f < MIDA_S; f++)
  {
    for (c = 0; c < MIDA_S; c++)
    {
      if (scanf("%d", &sudoku[f][c]) != 1)
      {
        fprintf(stderr, "Error de lectura en la casella %d, %d\n", f + 1, c + 1);
        return -1;
      }
      if (sudoku[f][c] < 1 || sudoku[f][c] > MIDA_S)
      {
        fprintf(stderr, "Error de lectura en la casella %d, %d\n", f + 1, c + 1);
        return -1;
      }
    }
  }
  return 0;
}

void Imprimir_Sudoku (int sudoku[MIDA_S][MIDA_S])
{
  int f, c; //files i columnes

  printf("\n");
  for (f = 0; f < MIDA_S; f++)
  {
    for (c = 0; c < MIDA_S; c++)
    {
      for (c = 0; c < MIDA_S; c++)
      {
        if (f % MIDA_R == 0)
        {
          printf("#===");
        }
        else
        {
          if (c % MIDA_R == 0)
          {
            printf("#---");
          }
          else
          {
            printf("+---");
          }
        }
      }
      printf("#");
      printf("\n");
      
      for (c = 0; c < MIDA_S; c++)
      {
        if (c % MIDA_R == 0)
        {
          printf("[");
          if (sudoku[f][c] - 10 <= -1)
          {
            printf(" %d ", sudoku[f][c]);
          }
          else
          {
            printf("%d ", sudoku[f][c]);
          }
        }
        else
        {
          printf("|");
          if (sudoku[f][c] - 10 <= -1)
          {
            printf(" %d ", sudoku[f][c]);
          }
          else
          {
            printf("%d ", sudoku[f][c]);
          }
        }
      }
      printf("[");
      printf("\n");
    }
  }
  for (c = 0; c < MIDA_S; c++)
  {
    printf("#===");
  }
  printf("#");
  printf("\n");
}

int Verificar_Sudoku (int sudoku[MIDA_S][MIDA_S])
{
  int f, c; //files i columnes
  int tmp;
  int rf, rc; //indiquen la regió
  int element_actual;
  
  //Verifiquem les files
  for (f = 0; f < MIDA_S; f++)
  {
    for (c = 0; c < MIDA_S; c++)
    {
      element_actual = sudoku[f][c];
      tmp = c; 
      /*Cal fer servir una variable temporal perquè sinó, 
      en acabar de comprovar el primer nombre d'una fila, 
      passaria a comprovar el primer nombre de la següent fila sense comprovar els altres nombres de la fila anterior, 
      ja que el bucle while faria acabar el bucle for perquè tindrien la mateixa condició de sortida (c < MIDA_S).*/
      
      /*El rang d'aquest bucle while és fins MIDA_S - 1 perquè, al finalitzar el bucle, 
      se suma tmp una vegada més i, si el rang fos fins MIDA_S, 
      estaria comparant l'element actual amb el primer element de la següent fila.*/
      while (tmp < MIDA_S - 1)
      {
        tmp++;
        if (sudoku[f][tmp] == element_actual)
        {
          fprintf(stderr, "\nEl Sudoku té un error a la fila %d.\n", f + 1);
          return -1;
        }
      }
    }
  }
  //Verifiquem les columnes
  for (c = 0; c < MIDA_S; c++)
  {
    for (f = 0; f < MIDA_S; f++)
    {
      element_actual = sudoku[f][c];
      tmp = f;
      while (tmp < MIDA_S - 1)
      {
        tmp++;
        if (sudoku[tmp][c] == element_actual)
        {
          fprintf(stderr, "\nEl Sudoku té un error a la columna %d.\n", c + 1);
          return -1;
        }
      }
    }
  }
  //Verifiquem les regions
  for (rf = 0; rf < MIDA_R; rf++)
  {
    for (rc = 0; rc < MIDA_R; rc++)
    {
      bool numeros_trobats[MIDA_S] = {false};
      
      for (f = rf * MIDA_R; f < MIDA_R + rf * MIDA_R; f++)
      {
        for (c = rc * MIDA_R; c < MIDA_R + rc * MIDA_R; c++)
        {
          element_actual = sudoku[f][c];
          if (numeros_trobats[element_actual - 1])
          {
            fprintf(stderr, "\nEl Sudoku té un error a la regió %d, %d.\n", rf + 1, rc + 1);
            return -1;
          }
          numeros_trobats[element_actual - 1] = true;
        }
      }
    }
  }
  return 0;
}