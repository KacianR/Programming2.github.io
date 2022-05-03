/*feb 1, 2022
switch structures
switch(<option>){ 
    case 'a':<code>
    break;}*/
#include <stdio.h>
#include <math.h>

int main()
{
    int num;
    printf("Enter 1 to 5 from a message[zero to exit] ");
    scanf("%d", &num);
    while (num != 0)
    {
        switch (num)
        {
        case 1:
            printf("\n Hello have a nice day.");
            break;
        case 2:
            printf("\n C programming is fun");
            break;
        case 3:
            printf("\n Reading a little a day makes a big difference.");
            break;
        case 4:
            printf("\n Ask questions if you are unsure.");
            break;
        case 5:
            printf("\n Smile and the world smiles back ");
            break;
        default:
            printf("\n Error no such code. Please follow instructions.");
            break;
        } //end of switch
        printf("Enter 1 to 5 from a message[zero to exit] ");
        scanf("%d", &num);
    }
    printf("\n Good bye.");
    return 0;
}

/*Write a simple calculator (add, subtract, multiply and divide)
program using the C programing language. The program
should operate like a regular calculator that will allow the user
to perform the basic arithmetic operations. The user should be
allowed to type the problem as follows:
         15 + 10 + 4 = 29 or 5*7 = 35
and receive the appropriate answer.
(Hint: use a switch statement to evaluate the operator the
user inputs. Use getchar() to read the character)
NB: Your calculator should allow the user to calculate a series of numbers,
not just 2 numbers.*/

#include <stdio.h>

int main()
{
    int num, num2, ans;
    char op;
    printf("Enter operator[-,*,/,+]: ");
    scanf("%c", &op);
    printf("Enter number: ");
    scanf("%d", &num);
    ans = num;
    while (num2 != 0)
    {
        printf("Enter another number (0 to end): ");
        scanf("%d", &num2);
        if (num2 != 0)
        {
            switch (op)
            {
            case '+':
                ans += num2;
                break;
            case '-':
                ans -= num2;
                break;
            case '*':
                ans *= num2;
                break;
            case '/':
                ans /= num2;
                break;
            default:
                printf("Error! operator is not correct\n");
                break;
            }
        }
    }
    printf("The answer is %d", ans);
    return 0;
}

#include <stdio.h>
int main()
{
    int num, num2, ans;
    char op;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter operator[-,*,/,+]: ");
    scanf(" %c", &op);
    getchar();
    //printf(" %c", op);
    ans = num;
    while (op != '=')
    {
        printf("Enter another number: ");
        scanf("%d", &num2);
        while (op != '=')
        {
            switch (op)
            {
            case '+':
                ans += num2;
                printf("The answer is %d", ans);
                break;
            case '-':
                ans -= num2;
                printf("The answer is %d", ans);
                break;
            case '*':
                ans *= num2;
                printf("The answer is %d", ans);
                break;
            case '/':
                ans /= num2;
                printf("The answer is %d", ans);
                break;
            default:
                printf("The answer is %d\n", ans);
                break;
            }
            printf("\nEnter operator[-,*,/,+]: ");
            scanf(" %c", &op);
            getchar();
            printf("Enter another number (0 to end): ");
            scanf("%d", &num2);
        }
    }
    printf("The final answer is %d", ans);
    return 0;
}