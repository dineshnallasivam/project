#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ashwithac 2468017
#define arunac 135678
#define ashwithpi 9876
#define arunpi 6543

struct information{
    char person[15];
    long long mobile;
    char district[10];
    short pin;
    int balance;
}str[50]={{"ARUNKARTHI", 9345606392, "TIRUPPUR", 2354, 30000}, {"ASHWINTH", 9715064031, "TENKASI", 1234, 10000}};

struct billing{
    char item_name[20];
    int item_price;
    int item_num;
}things[20];

void balance(struct information s){
    printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    printf("\nNAME : %s \tDISTRICT : %s\t MOBILE NO. %lld\nBALANCE : %d\n", s.person, s.district, s.mobile, s.balance);
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
}

void deposit(struct information s){
    int choice, account, pin, amount;
    printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("\n\tAVAILABLE BANK ");
    printf("\n1.KVB BANK\n2.State bank\n3.None of these");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    switch(choice){
        case 1:{
            printf("\nEnter your account number : ");
            scanf("%d", &account);
            printf("\nEnter your pin : ");
            scanf("%d", &pin);
            if(account==ashwithac || account==arunac){
                if(pin==ashwithpi || pin==arunpi){
                    printf("\nEnter the amount : ");
                    scanf("%d", &amount);
                    s.balance=s.balance+amount;
                    printf("\nNow your balance is %d", s.balance); 
                }
            }
            else{
                printf("\nyou have enter wrong pin or accoint number."); 
            }
        }
        break;
        case 2:{
            printf("\nEnter your account number : ");
            scanf("%d", &account);
            printf("\nEnter your pin : ");
            scanf("%d", &pin);
            if(account==ashwithac || account==arunac){
                if(pin==ashwithpi || pin==arunpi){
                    printf("\nEnter the amount : ");
                    scanf("%d", &amount);
                    s.balance = s.balance + amount;
                    printf("\nNow your balance is %d", s.balance); 
                }
            }
            else{
                printf("\nyou have enter wrong pin or accoint number."); 
            }
        }
        break;
        case 3: 
        break;
        default: printf("\nYou have entered wrong option.");
    }
}
void newitem(struct information s){
    FILE *fp;
    char select[5];
    char item[20];
    int num, price, items, sum=0;
    for(int i=0; i<50; i++){
        if(strcmp(s.person,"ARUNKARTHI")==0){
            printf("\nEnter the number of item : ");
            scanf("%d", &num);
            for(int j=0;j<num;j++){
                printf("\nEnter the item name : ");
                scanf("%s", item);
                printf("\nHow many pair : ");
                scanf("%d",&items);
                printf("\nEnter the price : ");
                scanf("%d", &price);
                if(price*items<=(s.balance-1000)){
                    fp=fopen("arunkarthi.text", "a");
                    fprintf(fp,"\n%s \t\t%d\t%d", item, items, price);
                    fclose(fp);
                    sum=sum+(price*items);
                    s.balance=s.balance-(price*items);
                    strcpy(things[j].item_name,item);
                    things[j].item_num=items;
                    things[j].item_price=price;
                }
                else{
                    printf("\nYou don't have enough money to buy the thing.");
                    printf("\nDo you want to deposit the amount and continue?\nif you want enter yes, if not enter no");
                    scanf("%s", &select); 
                    if(select=="yes"){
                        deposit(s);
                        printf("\nEnter the item name : ");
                        scanf("%s", &item);
                        printf("\nHow many pair : ");
                        scanf("%d",&items);
                        printf("\nEnter the price : ");
                        scanf("%d", &price);
                        if(price*items<=(s.balance-1000)){
                            fp=fopen("arunkarthi.text", "a");
                            fprintf(fp,"\n%s \t\t%d\t%d", item, items, price);
                            fclose(fp);
                            sum=sum+(price*items);
                            s.balance=s.balance-(price*items);
                            strcpy(things[j].item_name,item);
                            things[j].item_num=items;
                            things[j].item_price=price;
                        }    
                    }                   
                } 
            }
            printf("\n=========================================================================");
            printf("\n\tJ S MALL BILL RECEIPT");
            printf("\nITEM NAME \tPAIRS\tPRICE");
            printf("\n-------------------------------------------------------------------------------------------");
            for(int k=0;k<20;k++){
                if(things[k].item_price!=0){
                    printf("\n%s \t%d\t%d", things[k].item_name, things[k].item_num, things[k].item_price);              
                }
            }
            printf("\n--------------------------------------------------------------------------------------------");
            printf("\n\t\t\t\t\t\t\tTOTAL = %d", sum);
            break;
        }
        if(strcmp(s.person,"ASHWINTH")==0){
            printf("\nEnter the number of item : ");
            scanf("%d", &num);
            for(int j=0;j<num;j++){
                printf("\nEnter the item name : ");
                scanf("%s", item);
                printf("\nHow many pair : ");
                scanf("%d",&items);
                printf("\nEnter the price : ");
                scanf("%d", &price);
                if(price*items<=(s.balance-1000)){
                    fp=fopen("ashwinth.text", "a");
                    fprintf(fp,"\n%s \t\t%d\t%d", item, items, price);
                    fclose(fp);
                    sum=sum+(price*items);
                    s.balance=s.balance-(price*items);
                    strcpy(things[j].item_name,item);
                    things[j].item_num=items;
                    things[j].item_price=price;
                }
                else{
                    printf("\nYou don't have enough money to buy the thing.");
                    printf("\nDo you want to deposit the amount and continue?\nif you want enter yes, if not enter no");
                    scanf("%s", &select); 
                    if(select=="yes"){
                        deposit(s);
                        printf("\nEnter the item name : ");
                        scanf("%s", &item);
                        printf("\nHow many pair : ");
                        scanf("%d",&items);
                        printf("\nEnter the price : ");
                        scanf("%d", &price);
                        if(price*items<=(s.balance-1000)){
                            fp=fopen("ashwinth.text", "a");
                            fprintf(fp,"\n%s \t\t%d\t%d", item, items, price);
                            fclose(fp);
                            sum=sum+(price*items);
                            s.balance=s.balance-(price*items);
                            strcpy(things[j].item_name,item);
                            things[j].item_num=items;
                            things[j].item_price=price;
                        }    
                    }                   
                } 
            }
            printf("\n=========================================================================");
            printf("\n\tJ S MALL BILL RECEIPT");
            printf("\nITEM NAME \tPAIRS\tPRICE");
            printf("\n-------------------------------------------------------------------------------------------");
            for(int k=0;k<20;k++){
                if(things[k].item_price!=0){
                    printf("\n%s \t%d\t%d", things[k].item_name, things[k].item_num, things[k].item_price);              
                }
            }
            printf("\n--------------------------------------------------------------------------------------------");
            printf("\n\t\t\t\t\t\t\tTOTAL = %d", sum);
            break;
        }
    }   
}

int main(){
    char select[5], item[20], name[10];
    short password, new_pin;
    int choice, option, i, j, num, price, items, sum=0;
    FILE *fp;
    printf("\tCUSTOMER MANAGEMENT\n");
    printf("\tJ.S MALL");
    printf("\n1. Already have account.");
    printf("\n2. Create acoount.");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    if(choice==1){
        field :
        printf("\nEnetr your id name : ");
        scanf("%s", &name);
        printf("\nEnter the pasword : ");
        scanf("%hd", &password);
        for(i=0;i<50;i++){
            if(strcmp(name,str[i].person)==0 && password==str[i].pin){
                printf("\n1. BALANCE\n2. DEPOSIT\n3. ADDITION OF NEW ITEM");
                printf("\nEnter your option : ");
                scanf("%d", &option);
                switch(option){
                    case 1:balance(str[i]);
                    break;
                    case 2:deposit(str[i]);
                    break;
                    case 3:newitem(str[i]);
                    break;
                    default: printf("\nYou have entered wrong option.\nPlease try again,");
                    break;
                }         
            }
        }
        if(str[i].person!=0){
        } 
        else{
            printf("\nyou have entered the wrong id or password.");
        }
    }
    else{
        printf("\nEnter your name :(like : ASHWINTH)");
        scanf("%s", &str[2].person);
        printf("\nEnter your mobile number : ");
        scanf("%lld", &str[2].mobile);
        printf("\nEnter your district name : (like : tenkasi)");
        scanf("%s", &str[2].district);
        retry:
        printf("\nEnter the pin number :");
        scanf("%hd", &new_pin);
        for(i=0;i<50;i++){
            if(new_pin==str[i].pin){
                printf("\npin is already exist.");
                goto retry;
            }
        }
        printf("\nFor continue you should deposit the amount first");
        deposit(str[2]);
        if(str[2].balance!=0){
            fp=fopen("new_registration.text", "w");
            fprintf(fp, "\n\t\t\t\t\t\t\tJ S MALL\n\nNAME : %s\tDISTRICT : %s\tMOBILE NO.:%lld", str[2].person, str[2].district, str[2].mobile);
            fprintf(fp, "\n-----------------------------------------------------------------------------------");
            fprintf(fp, "\n\nITEM NAME \t\tPAIRS\tPRICE");
            fprintf(fp, "\n==============================================================================================");
            fclose(fp);
            printf("\nEnter the number of item : ");
            scanf("%d", &num);
            for(int j=0;j<num;j++){
                printf("\nEnter the item name : ");
                scanf("%s", &item);
                printf("\nHow many pair : ");
                scanf("%d",&items);
                printf("\nEnter the price : ");
                scanf("%d", &price);
                if(price*items<=(str[2].balance-1000)){
                    fp=fopen("new_registration.text", "a");
                    fprintf(fp,"\n%s \t\t%d\t%d", item, items, price);
                    fclose(fp);
                    sum=sum+(price*items);
                    str[2].balance=str[2].balance-(price*items);
                    strcpy(things[j].item_name,item);
                    things[j].item_num=items;
                    things[j].item_price=price;
                }
                else{
                    printf("\nYou don't have enough money to buy the thing.");
                    printf("\nDo you want to deposit the amount and continue?\nif you want enter yes, if not enter no");
                    scanf("%s", &select); 
                    if(select=="yes"){
                        deposit(str[2]);
                        printf("\nEnter the item name : ");
                        scanf("%s", &item);
                        printf("\nHow many pair : ");
                        scanf("%d",&items);
                        printf("\nEnter the price : ");
                        scanf("%d", &price);
                        if(price*items<=(str[2].balance-1000)){
                            fp=fopen("new_registration.text", "a");
                            fprintf(fp, "\n%s \t\t%d\t%d", item, items, price);
                            fclose(fp);
                            sum=sum+(price*items);
                            str[2].balance=str[2].balance-(price*items);
                            strcpy(things[j].item_name,item);
                            things[j].item_num=items;
                            things[j].item_price=price;
                        }            
                    }                   
                } 
            }
            printf("\n=========================================================================");
            printf("\n\tJ S MALL BILL RECEIPT");
            printf("\nITEM NAME \tPAIRS\tPRICE");
            printf("\n-------------------------------------------------------------------------------------------");
            for(int k=0;k<20;k++){
                if(things[k].item_price!=0){
                    printf("\n%s \t%d\t%d", things[k].item_name, things[k].item_num, things[k].item_price);              
                }
            printf("\n--------------------------------------------------------------------------------------------");
            printf("\n\t\t\t\t\t\t\tTOTAL = %d", sum);
            }
        }
    }   
}
