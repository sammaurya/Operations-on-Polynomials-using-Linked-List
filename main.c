#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};
struct node *first1,*first2,*first;

void create(struct node **);
void print(struct node **);
void Sort(struct node **);
void addpolynomial(struct node **,struct node **,struct node **);

int main()
{
    int choice;
    START:
    system("cls");
    printf("\n\t\tRepresentation of Polynomial Using Link List");
    printf("\n\t  ---------------------------------------------------------");
    printf("\n\n\t1.Equation 1\n\t2.Equation 2\n\t3.Operations\n\t4.Exit");
    do
    {
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\n1.Insert Equation\n2.Print Equation\n3.Main Menu");
            do
            {
                printf("\nEnter Choice : ");
                scanf("%d",&choice);
                switch(choice)
                {
                case 1:
                    create(&first1);
                    break;
                case 2:
                    print(&first1);
                    break;
                case 3:
                    goto START;
                    break;
                default:
                    printf("\nWrong Choice!!!");
                }
            }while(choice!=3);
            break;
        case 2:
            printf("\n\n1.Insert Equation\n2.Print Equation\n3.Main Menu");
            do
            {
                printf("\nEnter Choice : ");
                scanf("%d",&choice);
                switch(choice)
                {
                case 1:
                    create(&first2);
                    break;
                case 2:
                    print(&first2);
                    break;
                case 3:
                    goto START;
                    break;
                default:
                    printf("\nWrong Choice!!!");
                }
            }while(choice!=3);
            break;
        case 3:
            printf("\n1.Addition\n2.Main Menu");
            do
            {
                printf("\nEnter Choice : ");
                scanf("%d",&choice);
                switch(choice)
                {
                case 1:
                    addpolynomial(&first1,&first2,&first);
                    break;
                case 2:
                    goto START;
                    break;
                default:
                    printf("\nWrong Choice!!!");
                }
            }while(choice!=2);
            break;
        case 4:
            printf("\nExiting...");
            break;
        default:
            printf("\nWrong Choice!!!");
        }
    }while(choice!=4);
    return 0;
}
void create(struct node **newfirst)
{
    char ch;
    struct node *ptr,*cpt;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter Coeff and Exponent of First Term : ");
    scanf("%d%d",&ptr->coeff,&ptr->exp);
    *newfirst=ptr;
    do
    {
        cpt=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter Coeff and Exponent of Next Term : ");
        scanf("%d%d",&cpt->coeff,&cpt->exp);
        ptr->next=cpt;
        ptr=cpt;
        printf("\nEnter more (Y/N) : ");
        scanf(" %c",&ch);
    }while(ch=='Y'||ch=='y');
    ptr->next=NULL;
}
void print(struct node **newfirst)
{
    struct node *ptr;
    ptr=(*newfirst);
    if(ptr==NULL)
    {
        printf("Link List is Empty");
    }
    else
    {
        printf("\n");
        do
        {
            printf(" %dX^%d",ptr->coeff,ptr->exp);
            if(ptr->next!=NULL)
            {
                printf("+");
            }
            ptr=ptr->next;
        }while(ptr!=NULL);
        printf("\n");
    }
}
void addpolynomial(struct node **newfirst1,struct node **newfirst2,struct node **newfirst)
{
    if(*newfirst1==NULL&&*newfirst2==NULL)
    {
        printf("\nEquation A and B is Empty");
    }
    else if(*newfirst1==NULL)
    {
        printf("\nEquation A is Empty");
    }
    else if(*newfirst2==NULL)
    {
        printf("\nEquation B is Empty");
    }
    else
    {
        struct node *ptr1,*ptr2,*ptr,*cpt;
        ptr=(struct node *)malloc(sizeof(struct node));
        *newfirst=ptr;
        Sort(newfirst1);
        Sort(newfirst2);
        ptr1=*newfirst1;
        ptr2=*newfirst2;
        if(ptr1->exp > ptr2->exp)
        {
            ptr->coeff=ptr1->coeff;
            ptr->exp=ptr1->exp;
            ptr1=ptr1->next;
        }
        else if(ptr1->exp < ptr2->exp)
        {
            ptr->coeff=ptr2->coeff;
            ptr->exp=ptr2->exp;
            ptr2=ptr2->next;
        }
        else
        {
            ptr->coeff=ptr1->coeff +ptr2->coeff;
            ptr->exp=ptr1->exp;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        while(ptr1!=NULL && ptr2!=NULL)
        {
            cpt=(struct node *)malloc(sizeof(struct node));
            if(ptr1->exp > ptr2->exp)
            {
                cpt->coeff=ptr1->coeff;
                cpt->exp=ptr1->exp;
                ptr1=ptr1->next;
            }
            else if(ptr1->exp < ptr2->exp)
            {
                cpt->coeff=ptr2->coeff;
                cpt->exp=ptr2->exp;
                ptr2=ptr2->next;
            }
            else
            {
                cpt->coeff=ptr1->coeff +ptr2->coeff;
                cpt->exp=ptr1->exp;
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            ptr->next=cpt;
            ptr=cpt;
        }
        while(ptr1!=NULL)
        {
            cpt=(struct node *)malloc(sizeof(struct node));
            cpt->coeff=ptr1->coeff;
            cpt->exp=ptr1->exp;
            ptr1=ptr1->next;
            ptr->next=cpt;
            ptr=cpt;
        }
        while(ptr2!=NULL)
        {
            cpt=(struct node *)malloc(sizeof(struct node));
            cpt->coeff=ptr2->coeff;
            cpt->exp=ptr2->exp;
            ptr2=ptr2->next;
            ptr->next=cpt;
            ptr=cpt;
        }
        ptr->next=NULL;
        printf("\nTwo Equations are Added\n");
        print(newfirst);
    }
}
void Sort(struct node **newfirst)
{
    struct node *ptr,*cpt,*tpt;
    ptr=*newfirst;
    while(ptr!=NULL)
    {
        cpt=ptr->next;
        while(cpt!=NULL)
        {
            tpt=(struct node *)malloc(sizeof(struct node));
            if(ptr->exp <= cpt->exp)
            {
                tpt->exp = ptr->exp;
                tpt->coeff = ptr->coeff;
                ptr->exp = cpt->exp;
                ptr->coeff = cpt->coeff;
                cpt->exp = tpt->exp;
                cpt->coeff = tpt->coeff;
            }
            cpt=cpt->next;
        }
        ptr=ptr->next;
    }
}
