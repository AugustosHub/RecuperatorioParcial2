#include <stdio.h>
#include <stdlib.h>
#include<wchar.h>
#include<locale.h>
#include<time.h>
#include<unistd.h>
#include<string.h>
#include<conio.h>

struct Empleados{
    int DNI;
    char apellido[20];
    float sueldo;

    struct Empleados *sig;
};

struct Empleados *InicioEmp1 = NULL;
struct Empleados *InicioEmp2 = NULL;

void Menu(){
    puts("Recuperatorio Augusto\n\n");
    puts("1. Agregar Empleado");
    puts("2. Despedir empleado");
    puts("3. Modificar empleado");
    puts("4. Buscar empleado");
    puts("5. Mostrar empleados");
    puts("6. Salir");
    printf("?");
}

int existeDNI(int doc,struct Empleados *actual) {

    while (actual != NULL) {
        if (actual->DNI == doc) {
            return 1;  //Exise el DNI
        }
        actual = actual->sig;
    }

    return 0;
}

int cantidadEmpleados(struct Empleados *actual){
    int cant = 1;
    while(actual!=NULL){
        cant = cant + 1;

        actual = actual->sig;
    }

    return cant;
}

void agregarEmpleado(){
    struct Empleados *nuevo1;
    struct Empleados *nuevo2;
    struct Empleados *actual;
    struct Empleados *anterior;

    int op;
    int doc;
    char nom[20];
    float sueldo;

    puts("Qu� empresa lo va a contratar?");
    puts("1. Empresa 1");
    puts("2. Empresa 2");
    printf("?");
    scanf("%d",&op);


    switch(op){
        case 1:
            if(cantidadEmpleados(InicioEmp1)<=5){
                    fflush(stdin);
            puts("Ingrese el apellido del empleado: ");
            gets(nom);
            puts("Ingrese el documento del empleado: ");
            scanf("%d",&doc);
            puts("Ingrese el sueldo neto del empleado: ");
            scanf("%f",&sueldo);

            nuevo1 = malloc(sizeof(struct Empleados));
            strcpy(nuevo1->apellido,nom);
            nuevo1->DNI = doc;
            nuevo1->sueldo = sueldo;

            actual = InicioEmp1;
            anterior = NULL;

            while (actual != NULL && strcmp(nuevo1->apellido,actual->apellido) > 0) {
                anterior = actual;
                actual = actual->sig;
            }

            if (anterior == NULL) {
                nuevo1->sig = InicioEmp1;
                InicioEmp1 = nuevo1;
            } else {
                nuevo1->sig = actual;
                anterior->sig = nuevo1;
            }

            puts("Cliente agregado con �xito a la empresa 1");
            system("pause");
            }else{
                puts("Se super� la cantidad m�xima de empleados (5)");
                puts("-----------------------------------------");
                system("pause");
            }
            break;
        case 2:
            if(cantidadEmpleados(InicioEmp2)<=5){
                fflush(stdin);
                puts("Ingrese el nombre del empleado: ");
                gets(nom);
                puts("Ingrese el documento del empleado: ");
                scanf("%d",&doc);
                puts("Ingrese el sueldo neto del empleado: ");
                scanf("%f",&sueldo);

                nuevo2 = malloc(sizeof(struct Empleados));
                strcpy(nuevo2->apellido,nom);
                nuevo2->DNI = doc;
                nuevo2->sueldo = sueldo;

                actual = InicioEmp2;
                anterior = NULL;

                while (actual != NULL && strcmp(nuevo2->apellido, actual->apellido) > 0) {
                    anterior = actual;
                    actual = actual->sig;
                }

                if (anterior == NULL) {
                    nuevo2->sig = InicioEmp2;
                    InicioEmp2 = nuevo2;
                } else {
                    nuevo2->sig = actual;
                    anterior->sig = nuevo2;
                }

                puts("Empleado agregado con exito a la empresa 2");
                system("pause");
            }else{
                puts("Se super� la cantidad m�xima de empleados (5)");
                puts("-----------------------------------------");
                system("pause");
            }
            break;
    }


}

void eliminarEmpleado(){
    struct Empleados *actualEmp1 = InicioEmp1;
    struct Empleados *anteriorEmp1 = NULL;

    struct Empleados *actualEmp2 = InicioEmp2;
    struct Empleados *anteriorEmp2 = NULL;

    int op,doc;
    char nom[20];
    float sueldo;

    puts("�De que empresa quiere despedir un empleado?");
    puts("1. Empresa 1");
    puts("2. Empresa 2");
    printf("?");
    scanf("%d",&op);

    switch(op){
        case 1:
            puts("Ingrese el documento del empleado a despedir: ");
            scanf("%d",&doc);
            if(existeDNI(doc, InicioEmp1)){
                while (actualEmp1 != NULL && actualEmp1->DNI != doc) {
                    anteriorEmp1 = actualEmp1;
                    actualEmp1 = actualEmp1->sig;
                }

                if (anteriorEmp1 == NULL) {
                    InicioEmp1 = actualEmp1->sig;
                } else {
                    anteriorEmp1->sig = actualEmp1->sig;
                }
                free(actualEmp1);
                puts("Empleado eliminado!");
                system("pause");
            }else{
                puts("No se encontr� el empleado, puede ser: dni incorrecto, empresa incorrecta");
                system("pause");
            }
            break;
        case 2:
            puts("Ingrese el documento del empleado a eliminar: ");
            scanf("%d",&doc);
            if(existeDNI(doc, InicioEmp2)){
                while (actualEmp2 != NULL && actualEmp2->DNI != doc) {
                    anteriorEmp2 = actualEmp2;
                    actualEmp2 = actualEmp2->sig;
                }

                if (anteriorEmp2 == NULL) {
                    InicioEmp2 = actualEmp2->sig;
                } else {
                    anteriorEmp2->sig = actualEmp2->sig;
                }
                free(actualEmp2);
                puts("Empleado eliminado!");
                system("pause");
            }else{
                puts("No se encontr� el empleado, puede ser: dni incorrecto, empresa incorrecta");
                system("pause");
            }
            break;
    }
}

void modificarEmpleado(){
    struct Empleados *actualEmp1 = InicioEmp1;
    struct Empleados *actualEmp2 = InicioEmp2;

    char nombreNuevo[20];
    int op,op1,doc,docNuevo;
    float sueldoNuevo;

    printf("Ingrese el DNI del empleado que desea modificar: ");
    scanf("%d",&doc);
    if(existeDNI(doc, InicioEmp1)){
        while (actualEmp1->DNI != doc && actualEmp1 != NULL) {
                actualEmp1 = actualEmp1->sig;
            }

            system("cls");
            puts("Empleado encontrado: \n");
            printf("Apellido: %s\n", actualEmp1->apellido);
            printf("DNI: %d\n", actualEmp1->DNI);
            printf("Sueldo: %.1f\n", actualEmp1->sueldo);
            printf("---------------------------\n\n");

            puts("�Qu� desea modificar?\n1. Apellido\n2. DNI\n3. Sueldo");
            puts("------------------------------------");
            printf("Elegir opci�n: ");
            scanf("%d",&op);
            while(op>3 || op<1){
                puts("�Opci�n no valida, intente de nuevo!");
                printf("Elegir opci�n: ");
                scanf("%d",&op);
            }
            switch(op){
                case 1:
                    fflush(stdin);
                    printf("Ingrese el nuevo apellido del empleado: ");
                    gets(nombreNuevo);

                    strcpy(actualEmp1->apellido,nombreNuevo);
                    puts("�Apellido del empleado cambiado con exito!");
                    puts("------------------------------------------");
                    system("pause");
                    break;
                case 2:
                    fflush(stdin);
                    printf("Ingrese el nuevo DNI del empleado: ");
                    scanf("%d",&docNuevo);

                    actualEmp1->DNI = doc;
                    puts("�DNI del empleado actualizado con �xito!");
                    puts("-------------------------------------------");
                    system("pause");
                    break;
                case 3:
                    printf("Ingrese su nuevo sueldo neto: ");
                    scanf("%f",&sueldoNuevo);

                    actualEmp1->sueldo = sueldoNuevo;
                    puts("�Sueldo actualizado!");
                    puts("-------------------");
                    system("pause");
                    break;
            }
    }else if(existeDNI(doc, InicioEmp2)){
        while (actualEmp2->DNI != doc && actualEmp2 != NULL) {
                actualEmp2 = actualEmp2->sig;
            }

            system("cls");
            puts("Empleado encontrado: \n");
            printf("Apellido: %s\n", actualEmp2->apellido);
            printf("DNI: %d\n", actualEmp2->DNI);
            printf("Sueldo: %.1f\n", actualEmp2->sueldo);
            printf("---------------------------\n\n");

            puts("�Qu� desea modificar?\n1. Apellido\n2. DNI\n3. Sueldo");
            puts("------------------------------------");
            printf("Elegir opci�n: ");
            scanf("%d",&op);
            while(op>3 || op<1){
                puts("�Opci�n no valida, intente de nuevo!");
                printf("Elegir opci�n: ");
                scanf("%d",&op);
            }
            switch(op){
                case 1:
                    fflush(stdin);
                    printf("Ingrese el nuevo apellido del empleado: ");
                    gets(nombreNuevo);

                    strcpy(actualEmp2->apellido,nombreNuevo);
                    puts("�Apellido del empleado cambiado con exito!");
                    puts("------------------------------------------");
                    system("pause");
                    break;
                case 2:
                    fflush(stdin);
                    printf("Ingrese el nuevo DNI del empleado: ");
                    scanf("%d",&docNuevo);

                    actualEmp2->DNI = doc;
                    puts("�DNI del empleado actualizado con �xito!");
                    puts("-------------------------------------------");
                    system("pause");
                    break;
                case 3:
                    printf("Ingrese su nuevo sueldo neto: ");
                    scanf("%f",&sueldoNuevo);

                    actualEmp2->sueldo = sueldoNuevo;
                    puts("�Sueldo actualizado!");
                    puts("-------------------");
                    system("pause");
                    break;
            }
    }else{
        puts("No se encontr� un empleado con ese DNI");
        puts("--------------------------------------");
        system("pause");
    }
    //COMENTE ESTAS LINEAS PORQUE ERA DE LA PRIMERA VERSION QUE HICE DONDE
    //HABIA QUE SELECCIONAR LA EMPRESA Y LUEGO BUCAR POR DNI DENTRO DE ESA EMPRESA
    //AHORA HAY QUE PONER SOLO EL DNI Y LAS BUSCA EN LAS DOS EMPRESAS AUTOMATICAMENTE
    //EN EL CASO QUE NO SIRVA EL ANTERIOR COMENTARLO Y USAR ESTE
    /*puts("�De que empresa quiere modificar un empleado?");
    puts("1. Empresa 1");
    puts("2. Empresa 2");
    printf("?");
    scanf("%d",&op1);

    switch(op1){
    case 1:
        printf("Ingrese el DNI del empleado que desea modificar: ");
        scanf("%d",&doc);
        if(existeDNI(doc, InicioEmp1)){
            while (actualEmp1->DNI != doc && actualEmp1 != NULL) {
                actualEmp1 = actualEmp1->sig;
            }

            system("cls");
            puts("Empleado encontrado: \n");
            printf("Apellido: %s\n", actualEmp1->apellido);
            printf("DNI: %d\n", actualEmp1->DNI);
            printf("Sueldo: %f\n", actualEmp1->sueldo);
            printf("---------------------------\n\n");

            puts("�Qu� desea modificar?\n1. Apellido\n2. DNI\n3. Sueldo");
            puts("------------------------------------");
            printf("Elegir opci�n: ");
            scanf("%d",&op);
            while(op>3 || op<1){
                puts("�Opci�n no valida, intente de nuevo!");
                printf("Elegir opci�n: ");
                scanf("%d",&op);
            }
            switch(op){
                case 1:
                    fflush(stdin);
                    printf("Ingrese el nuevo apellido del empleado: ");
                    gets(nombreNuevo);

                    strcpy(actualEmp1->apellido,nombreNuevo);
                    puts("�Apellido del empleado cambiado con exito!");
                    puts("------------------------------------------");
                    system("pause");
                    break;
                case 2:
                    fflush(stdin);
                    printf("Ingrese el nuevo DNI del empleado: ");
                    scanf("%d",&docNuevo);

                    actualEmp1->DNI = doc;
                    puts("�DNI del empleado actualizado con �xito!");
                    puts("-------------------------------------------");
                    system("pause");
                    break;
                case 3:
                    printf("Ingrese su nuevo sueldo neto: ");
                    scanf("%f",&sueldoNuevo);

                    actualEmp1->sueldo = sueldoNuevo;
                    puts("�Sueldo actualizado!");
                    puts("-------------------");
                    system("pause");
                    break;
            }
        break;
    case 2:
        printf("Ingrese el DNI del empleado que desea modificar: ");
        scanf("%d",&doc);
        if(existeDNI(doc, InicioEmp2)){
            while (actualEmp2->DNI != doc && actualEmp2 != NULL) {
                actualEmp2 = actualEmp2->sig;
            }

            system("cls");
            puts("Empleado encontrado: \n");
            printf("Apellido: %s\n", actualEmp2->apellido);
            printf("DNI: %d\n", actualEmp2->DNI);
            printf("Sueldo: %f\n", actualEmp2->sueldo);
            printf("---------------------------\n\n");

            puts("�Qu� desea modificar?\n1. Apellido\n2. DNI\n3. Sueldo");
            puts("------------------------------------");
            printf("Elegir opci�n: ");
            scanf("%d",&op);
            while(op>3 || op<1){
                puts("�Opci�n no valida, intente de nuevo!");
                printf("Elegir opci�n: ");
                scanf("%d",&op);
            }
            switch(op){
                case 1:
                    fflush(stdin);
                    printf("Ingrese el nuevo apellido del empleado: ");
                    gets(nombreNuevo);

                    strcpy(actualEmp2->apellido,nombreNuevo);
                    puts("�Apellido del empleado cambiado con exito!");
                    puts("------------------------------------------");
                    system("pause");
                    break;
                case 2:
                    fflush(stdin);
                    printf("Ingrese el nuevo DNI del empleado: ");
                    scanf("%d",&docNuevo);

                    actualEmp2->DNI = doc;
                    puts("�DNI del empleado actualizado con �xito!");
                    puts("-------------------------------------------");
                    system("pause");
                    break;
                case 3:
                    printf("Ingrese su nuevo sueldo neto: ");
                    scanf("%f",&sueldoNuevo);

                    actualEmp2->sueldo = sueldoNuevo;
                    puts("�Sueldo actualizado!");
                    puts("-------------------");
                    system("pause");
                    break;
            }
        break;
    }
}
}*/
}

void buscarEmpleado(){
    struct Empleados *actualEmp1 = InicioEmp1;
    struct Empleados *actualEmp2 = InicioEmp2;

    int doc;

    printf("Ingrese el DNI del empleado que desea modificar: ");
    scanf("%d",&doc);
    if(existeDNI(doc, InicioEmp1)){
        while (actualEmp1->DNI != doc && actualEmp1 != NULL) {
                actualEmp1 = actualEmp1->sig;
            }

            system("cls");
            puts("Empleado encontrado: \n");
            printf("Apellido: %s\n", actualEmp1->apellido);
            printf("DNI: %d\n", actualEmp1->DNI);
            printf("Sueldo: %.1f\n", actualEmp1->sueldo);
            printf("Empresa: Empresa 1\n");
            puts("---------------------------");
            system("pause");
    }else if(existeDNI(doc, InicioEmp2)){
        while (actualEmp2->DNI != doc && actualEmp2 != NULL) {
                actualEmp2 = actualEmp2->sig;
            }

            system("cls");
            puts("Empleado encontrado: \n");
            printf("Apellido: %s\n", actualEmp2->apellido);
            printf("DNI: %d\n", actualEmp2->DNI);
            printf("Sueldo: %.1f\n", actualEmp2->sueldo);
            printf("Empresa: Empresa 2\n");
            puts("---------------------------");
            system("pause");
    }else{
        puts("No se encontr� un empleado con ese DNI");
        puts("--------------------------------------");
        system("pause");
    }
}

void mostrarEmpleados(){
    struct Empleados *actualEmp1 = InicioEmp1;
    struct Empleados *anteriorEmp1 = NULL;
    struct Empleados *actualEmp2 = InicioEmp2;
    struct Empleados *anteriorEmp2 = NULL;

    int op;
    float mayor = 0;
    char aux[20];

    puts("�De que empresa quiere mostrar sus empleados?");
    puts("1. Empresa 1");
    puts("2. Empresa 2");
    printf("?");
    scanf("%d",&op);
    switch(op){
        case 1:
            system("cls");
            puts("Empleados de la empresa 1: \n");
            while(actualEmp1!=NULL){
                if(actualEmp1->sueldo>mayor){
                    mayor = actualEmp1->sueldo;

                    strcpy(aux,actualEmp1->apellido);
                }
                actualEmp1 = actualEmp1->sig;
            }

            actualEmp1 = InicioEmp1;
            while(actualEmp1!=NULL){
                    printf("Apellido: %s\n", actualEmp1->apellido);
                    printf("DNI: %d\n", actualEmp1->DNI);
                    printf("Sueldo: %.1f\n", actualEmp1->sueldo);
                    puts("---------------------------");
                    actualEmp1 = actualEmp1->sig;
                }
            puts("----------------------------------------------");
            printf("SUELDO MAS ALTO DE LA EMPRESA 1 es el de: %s\n",aux);
            printf("MONTO: %.1f\n",mayor);
            puts("----------------------------------------------");
                system("pause");
            break;
        case 2:
            system("cls");
            puts("Empleados de la empresa 2: \n");

            while(actualEmp2!=NULL){
                if(actualEmp2->sueldo>mayor){
                    mayor = actualEmp2->sueldo;

                    strcpy(aux,actualEmp2->apellido);
                }
                actualEmp2 = actualEmp2->sig;
            }

            actualEmp2 = InicioEmp2;

            while(actualEmp2!=NULL){
                    printf("Apellido: %s\n", actualEmp2->apellido);
                    printf("DNI: %d\n", actualEmp2->DNI);
                    printf("Sueldo: %.1f\n", actualEmp2->sueldo);
                    puts("---------------------------");
                    actualEmp2 = actualEmp2->sig;
                }

            puts("----------------------------------------------");
            printf("SUELDO MAS ALTO DE LA EMPRESA 2 es el de: %s\n",aux);
            printf("MONTO: %.1f\n",mayor);
            puts("----------------------------------------------");

            system("pause");
            break;
    }
}

int main()
{
    int op;

    setlocale(LC_ALL, "");
    srand(time(NULL));

    do{
        system("cls");
        Menu();
        scanf("%d",&op);

        switch(op){
        case 1:
            agregarEmpleado();
            break;
        case 2:
            eliminarEmpleado();
            break;
        case 3:
            modificarEmpleado();
            break;
        case 4:
            buscarEmpleado();
            break;
        case 5:
            mostrarEmpleados();
            break;
        case 6:
            puts("Adios");
            break;
        }
    }while(op!=6);
    return 0;
}
