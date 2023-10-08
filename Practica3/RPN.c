#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MPI 3.14159265358979323846

struct node {
    double data;
    struct node *next;
};

struct node *head = NULL;

void push(double val) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

double pop() {
    double data = 0;
    if (head != NULL) {
        struct node *tmp = head;
        data = head->data;
        head = head->next;
        free(tmp); 
    }
    return data;
}

void print() {
    struct node *tmp = head;
    while (tmp != NULL) {  
        printf("%.3lf\n", tmp->data);
        tmp = tmp->next;
    }
}

void printReverse() {
    struct node *tmp = head;
    struct node *stack = NULL; 

    while (tmp != NULL) {
        struct node *newNode = malloc(sizeof(struct node));
        newNode->data = tmp->data;
        newNode->next = stack;
        stack = newNode;
        tmp = tmp->next;
    }

    while (stack != NULL) {
        printf("%.3lf\n", stack->data);
        struct node *temp = stack;
        stack = stack->next;
        free(temp); 
    }
}


void menu() {
    printf("\n╔═══════════════════════════════╗\n"
           "║        CALCULADORA RPN        ║\n"
           "╚═══════════════════════════════╝\n");
    printReverse();
    printf("\n╔═══════╦═══════╦═══════╦═══════╗\n"
            "║   +   ║   -   ║   *   ║   /   ║\n"
            "╠═══════╩═╦═════╩═══╦═══╩═══════╣\n"
            "║  sin(s) ║  cos(c) ║   tan(t)  ║\n"
            "╠═════════╩════╦════╩═══════════╣\n"
            "║    raiz(r)   ║   potencia(p)  ║\n"
            "╚══════════════╩════════════════╝\n"
            "─────────────────────────────────\n"
            "  1. Ingresar número\n"
            "  2. Ingresar operador\n"
            "  0. SALIR\n"
            "─────────────────────────────────\n");
}

int main() {
    int option = 0;
    double number, num1=0, num2=0;
    char character;
    menu();
    do {
        scanf("%d", &option); 

        if(option==1){
            printf("Número: ");
            scanf("%lf", &number);
            push(number);

        }else if(option==2){
            printf("Operador: ");
            scanf(" %c", &character);

            switch (character)
            {
                case '+':
                    num1 = pop();
                    num2 = pop();
                    push(num1+num2);
                    break;

                case '-':
                    num1 = pop();
                    num2 = pop();
                    push(num2-num1);
                    break;
                
                case '*':
                    num1 = pop();
                    num2 = pop();
                    push(num1*num2);
                    break;
                
                case '/':
                    num1 = pop();
                    num2 = pop();
                    if(num1 != 0){
                        push(num2/num1);
                    }else{
                        print("ERROR! No se puede dividir por 0");
                    }
                    break;
                
                case 's':
                    num1 = pop();
                    push(sin(num1*MPI/180));
                    break;

                case 'c':
                    num1 = pop();
                    push(cos(num1*MPI/180));
                    break;

                case 't':
                    num1 = pop();
                    if(num1!=90 && num1!=180 && num1!=270){
                        push(tan(num1*MPI/180));
                    }
                    else{
                        print("ERROR! No se puede realizar la operación matemática");
                    }
                    break;
                    
                case 'r':
                    num1 = pop();
                    if(num1>=0){
                        push(sqrt(num1));
                    }
                    else{
                        print("ERROR! No se puede realizar la operación matemática");
                    }
                    break;
                
                case 'p':
                    num1 = pop();
                    num2 = pop();
                    push(pow(num1,num2));
                    break;

                default:
                    printf("Opción inválida\n");
                    break;  
            } 
        }

        system("clear");
        menu();

    } while (option != 0);

    return 0;
}
