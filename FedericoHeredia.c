#include <stdio.h>
#include <time.h>

void ingresar_alfajores(int array[6][3], int operario_actual) {
  int i;
  for ( i = 0; i < 3; i++) {
    int temp = array[operario_actual][i];
    if(i == 0) printf("ingrese cantidad de alfajores producidos de chocolates en total:");
    if(i == 1) printf("ingrese cantidad de alfajores producidos de dulce de leche en total:");
    if(i == 2) printf("ingrese cantidad de alfajores producidos de furta en total:");
    scanf("%d", &array[operario_actual][i] );
    printf("\n");
    array[operario_actual][i] += temp;
  }
}

void limpiar_array(int array[6][3]) {
  int i, j;
  for ( i = 0; i < 6; i++) {
    for ( j = 0; j < 3; j++) {
      array[i][j] = 0;
    }
  }
}

int encontrar_entregas_con_ERROR(int array[6][3]) {
  int errorcount = 0, i, j;
  for (i = 0; i < 6; i++) {
    for ( j = 0; j < 3; j++) {
      if(array[i][j] % 6 != 0) errorcount++;
    }
  }
  return errorcount;
}

void calcular_cajas(int array[6][3], int array_precio[4], int res[3]) {
  int Cantidad_de_cajas[3] = {0,0,0}, i,j ;
  int Resto[3] = {0,0,0};
  for (i = 0; i < 6; i++) {
    for ( j = 0; j < 3; j++) {
      Cantidad_de_cajas[j] += array[i][j] / 6;
      if(array[i][j] % 6  != 0) {
        Resto[j] += array[i][j] % 6;
      }
    }
  }
  for ( i = 0; i < 3; i++) {
    printf("Cantidad de cajas producidas %d: %d\n",i, Cantidad_de_cajas[i]);
    printf("\n");
    printf("Ganancias anachei: $%d\n", Cantidad_de_cajas[i] * array_precio[i]);
    printf("\n");
  }
}


int main(void) {
  srand(time(NULL));
  char tipos_alfajores[3][10] = {"Chocolate", "Dulce de leche", "Fruta"};
  int precio_caja_alfajor[4] = {5000, 5500, 4750, 6200};
  int cantidad_de_alfajores_producidos[6][3];
  limpiar_array(cantidad_de_alfajores_producidos);
  int i, j;
  int operario_actual;
  int Resto[3] = {0,0,0};

  while(1) {
    printf("operario_actual: ");
    scanf("%d", &operario_actual);
    if(operario_actual == 0) break;
    if(operario_actual < 0 || operario_actual > 6) {
      printf("Elija un operario del 1 al 6.\n");
    } else {
      ingresar_alfajores(cantidad_de_alfajores_producidos, operario_actual - 1);
    }
  }
  printf("Cantidad de entregas con ERROR: %d\n", encontrar_entregas_con_ERROR(cantidad_de_alfajores_producidos));
  for ( i = 0; i < 6; i++) {
    for ( j = 0; j < 3; j++) {
      printf("%d ", cantidad_de_alfajores_producidos[i][j]);
    }
    printf("\n");
  }
  calcular_cajas(cantidad_de_alfajores_producidos, precio_caja_alfajor, Resto);

  return 0;
}
