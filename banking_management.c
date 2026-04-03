#include<stdio.h>
#include<string.h>

int open_amount, account=0, deposit_amount, withdraw_amount;
char account_number[20], user_name[20];

int menu()
{
    int option;
    printf("\n\n********** Banking Management Menu **********\n\n");

    printf("1. Create Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. View Balance\n");
    printf("5. View Account Info\n");
    printf("6. Exit\n\n");

    printf("What Do You Want, Enter The Number From Menu = ");
    scanf("%d",&option);

    return option;
}
int create_account()
{
    for(int i=0; i<20; i++)
    {  
        printf("Enter Your Name : ");
        scanf("%s",&user_name);

        int d=strlen(user_name), flag=0, u;

        for(u=0; user_name[u]!=NULL; u++)
        {
            if(user_name[u]>='a' && user_name[u]<='z' || user_name[u]>='A' && user_name[u]<='Z')
                flag++;
            else
                break;
        }
        if(flag==d)
        {
            printf("\nyour name is successfully submit\n");
            break;
        }
        else
            printf("Try Again! \n");
    }

    for(int i=0; i<10; i++)
    {
        printf("Enter Account Number : ");
        scanf("%s",&account_number);

        int count=0;

        for(int j=0; account_number[j]!=NULL; j++)
        {
            if(account_number[j]>='0' && account_number[j]<='9')
                count++;
            
            else
            {
                printf("Please Enter Only Numbers!\n");
                break;
            }
        }
        if(count==11)
        {
            printf("\n    ***********     Account Created Successfully     ***********     \n");
            break;
        }
        else
            printf("Enter Correct Account No.\n");

    }
    for(int i=0; i<10; i++)
    {
        printf("Enter Opening amount : ");
        scanf("%d",&open_amount);

        if(open_amount>=500)
        {
            printf("\n**********     Your Amount is Successfully Deposited     **********\n");
            break;
        }
        else
            printf("        *****       Enter Amount Above 500      *****       \n");
    }
    //account submit confirmation
    account=1;
}
int deposit()
{
    if(account==1)
    {
        for(int i=0; i<10; i++)
        {
            printf("Enter Your Deposit Amount = ");
            scanf("%d",&deposit_amount);

            if(deposit_amount>=100)
            {
                open_amount+=deposit_amount;
                printf("\n\n********** Your Amount Is Successfully Deposited **********\n\n");
                break;
            }
            else
                printf("Please Enter Deposit Amount Above 100\n\n");
        }
    }
    else
        printf("Please Create Your Account First!\n");
}
int withdraw()
{
    if(account==1)
    {
        for(int i=0; i<10; i++)
        {
            printf("Enter Your Withdraw Amount = ");
            scanf("%d",&withdraw_amount);

            if(open_amount>=withdraw_amount)
            {
                open_amount-=withdraw_amount;
                break;
            }
            else
                printf("You Have Not This Balance\n");
        }
    }
    else
        printf("Please Create Your Account First!");
}
int view_balance()
{
    if(account==1)
        printf("\nbalance = %d\n",open_amount);
    else
        printf("Please Create Your Account First!");
}

int view_account_info()
{
    if(account==1)
    {
        printf("\nyour name = %s\n",user_name);
        printf("account no. = %s\n",account_number);
        printf("balance = %d\n\n",open_amount);
    }
    else
        printf("Please Create Your Account First!");
}

int main()
{
    int op;

    for(int i=0; i<10; i++)
    {
        op=menu();

        if(op==1)
            create_account();
        else if(op==2)
            deposit();
        else if(op==3)
            withdraw();
        else if(op==4)
            view_balance();
        else if(op==5)
            view_account_info();
        else if(op==6)
            break;
        else
            printf("Enter Valid Option\n");

    }
    
    return 0;
}