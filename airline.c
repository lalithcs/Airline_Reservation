#include <stdio.h>
#include <string.h>
#include<stdbool.h>
#include<ctype.h>
struct customer {
    char name[30];
    char number[11]; // Changed size to 11 to include null terminator
    char aadhar[12];
    char email[50];
    char place[20];
};

struct ticket {
    char from[25];
    char to[25];
    char priority[15];
    int base_price;
    float dis;
    int add;
    float total_price;
};

// Function to check if the phone number has exactly 10 digits
bool isValidPhoneNumber(const char* phoneNumber) {
    int len = strlen(phoneNumber);
    int i;
    if (len != 10) {
        return false;
    }
    for (i = 0; i < len; i++) {
        if (!isdigit(phoneNumber[i])) {
            return false;
        }
    }
    return true;
}

// Function to check if the email ID is valid
bool isValidEmail(const char* email) {
    // Simple email validation (check for @ and .)
    int atCount = 0;
    int dotCount = 0;
    int len = strlen(email);
    int i;
    for (i = 0; i < len; i++) {
        if (email[i] == '@') {
            atCount++;
        } else if (email[i] == '.') {
            dotCount++;
        }
    }
    return (atCount == 1 && dotCount >= 1);
}

float cou1(float base_price, struct ticket* t) {
    int c, add;
    float dis;
    printf("All coupounds are valid once per user\n");
    printf("The list of coupons are:1.Buy for 100 and get 10 discount(applicable on ticket price above 4000)\n2.Buy for 450 get 25 off(valid on ticket price aboive 4000)\n3.Buy for 1000 and get 35 off(valid for ticket price aboive 5000)");
    scanf("%d", &c);
    switch (c) {
        case 1:
        if (base_price >= 4000) {
            dis = 0.1;
            add = 100;
        } else {
            printf("Coupon option is invalid");
        }
        break;
        case 2:
        if (base_price >= 4000) {
            dis = 0.25;
            add = 450;
        } else {
            printf("Coupon option is invalid");
        }
        break;
        case 3:
        if (base_price >= 5000) {
            dis = 0.35;
            add = 1000;
        } else {
            printf("Coupon option is invalid");
        }
        break;
        default:
        printf("Coupon number is invalid");
    }

    t->dis = dis;
    t->add = add;
    return 0;
}

int main() {
    struct customer c;
    struct ticket t;
    int base_price, base;
    printf("Enter the name of the customer:");
    scanf("%s", c.name);
    // Phone number validation loop
    while (true) {
        printf("Enter the mobile number of the customer (10 digits): ");
        scanf("%s", c.number);

        if (isValidPhoneNumber(c.number)) {
            break;
        } else {
            printf("Invalid phone number. Please enter a 10-digit number.\n");
        }
    }

    printf("Enter the aadhar number of the customer:");
    scanf("%s", c.aadhar);

    // Email validation loop
    while (true) {
        printf("Enter the email of the customer: ");
        scanf("%s", c.email);

        if (isValidEmail(c.email)) {
            break;
        } else {
            printf("Invalid email ID. Please enter a valid email address.\n");
        }
    }

    printf("Enter the address of the customer:\n");
    scanf("%s", c.place);

    int i;
    //Boarding DETAILS
        for(i=0;;)
        {
        printf("Enter the boarding location:\n");
        printf("KEY:Hyderabad(or)Delhi(or)Vizag\n");
        scanf("%s",t.from);
        printf("%s",t.from);
        printf("Enter the destination:");
        printf("KEY:Hyderabad(or)Delhi(or)Vizag\n");
        scanf("%s",t.to);
        printf("%s",t.to);
        if(strcmp(t.from,t.to))
        {
            break;
        }
        else
        {
            printf("Please Enter different Boarding and Destination location\n");
            continue;  
        }
        
        }
    printf("Please enter your priority of class:\n");
    printf("KEY:business(or)firstclass(or)economy\n");
    scanf("%s",t.priority);
    char airline[]="Indigo";
    if(!strcmp(t.from,"Hyderabad") && !strcmp(t.to,"Bangalore") && !strcmp(t.priority,"business")){
        base_price= 3250;
        }
        else if(!strcmp(t.from,"Hyderabad") && !strcmp(t.to,"Bangalore") && !strcmp(t.priority,"firstclass")){
        base_price = 2850;
        }
        else if(!strcmp(t.from,"Hyderabad") && !strcmp(t.to,"Bangalore") && !strcmp(t.priority,"economy")){
        base_price = 2500;
        }
        else if(!strcmp(t.from,"Hyderabad") && !strcmp(t.to,"Vizag") && !strcmp(t.priority,"business")){
        base_price = 5000;
        }
        else if(!strcmp(t.from,"Hyderabad")&& !strcmp(t.to,"Vizag")&& !strcmp(t.priority,"firstclass")){
        
        base_price = 4650;
        }
        else if(!strcmp(t.from,"Hyderabad") && !strcmp(t.to,"Vizag") && !strcmp(t.priority,"economy")){
        base_price = 4150;
        }
        else if(!strcmp(t.from,"Hyderabad")&& !strcmp(t.to,"Delhi") && !strcmp(t.priority,"business")){
        base_price = 8000;
        }
        else if(!strcmp(t.from,"Hyderabad") && !strcmp(t.to,"Delhi") && !strcmp(t.priority,"firstclass")){
        base_price = 7450;
        }
        else if(!strcmp(t.from,"Hyderabad") && !strcmp(t.to,"Delhi") && !strcmp(t.priority,"economy")){
        base_price = 6850;
        }
        else{
        printf("ticket not available");
        }
    char timing[]="00:00PM";
    int l;
    printf("Please select you timings:\n1.7:00AM\n2.9:00AM\n3.11:00AM\n4.1:00PM\n5.6:00PM\n6.8:00PM\n7.10:00PM(please enter the serial number of the timing)\nEnter Your Timing:");
    scanf("%d", &t.base_price);
    switch (t.base_price) {
        case 1:
        strcpy(timing,"07:00AM");
        l=strlen(timing);
        base = 450;
        break;
        case 2:
        strcpy(timing,"09:00AM");
        l=strlen(timing);
        base = 700;
        break;
        case 3:
        strcpy(timing,"11:00AM");
        l=strlen(timing);
        base= 1000;
        break;
        case 4:
        strcpy(timing,"01:00PM");
        l=strlen(timing);
        base= 1150;
        break;
        case 5:
        strcpy(timing,"06:00PM");
        l=strlen(timing);
        base= 650;
        break;
        case 6:
        strcpy(timing,"08:00PM");
        l=strlen(timing);
        base= 550;
        break;
        case 7:
        strcpy(timing,"10:00PM");
        l=strlen(timing);
        base= 400;
        break;
        default:
        printf("Please select a valid timing");
    }
    base_price=base_price+base;
    t.base_price=base_price;
    int coup;
    printf("Do you want to buy any coupons?(Y=1/N=0)");
    scanf("%d", &coup);
    if (coup == 1) {
        cou1(t.base_price, &t);
    } else {
        t.dis = 0;
        t.add = 0;
    }
    float total_price = t.base_price - (t.base_price * t.dis) + t.add;
    printf("YOUR TICKET DETAILS\n");
    printf("Name:\n%s\n", c.name);
    printf("Number:\n%s\n", c.number);
    printf("Aadhar Number:\n");
    printf("%s\n", c.aadhar);
    printf("Email:\n%s\n", c.email);
    printf("Address:\n%s\n", c.place);
    printf("Timing:\n");
    for(i=0;i<l;i++)
    {
        printf("%c",timing[i]);
    }
    printf("\n");
    printf("Discount:\n%f\n", t.dis);
    printf("Total Price:\n%f\n", total_price);
    return 0;
}
