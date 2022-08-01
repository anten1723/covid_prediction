#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

                                     //COVID-19 SURVEY!!

// Initialising strings globally
char str_male[] = "male";
char str_female[] = "female";
char audio_yes[] = "yes";
char audio_no[] = "no";
char repeat_yes[] = "yes";
char repeat_no[] = "no";

// Using structure to declare variables of 5 parameters, age and gender!
struct record{

    int age, temp, oxy, resp, hr;
    char g[10], audio[10];
};

// High function is declared and defined to indicate the person is having high probabiltiy of illness.
int high(){

    printf("\nYou have a 'high-probability' of being infected with covid 19!");
    printf("\n\n\t\t\tTips :\nStay quarantined for 15 days and take proper care of your health!\nTake a covid test after 15 days!");
    return 1;
}

// Medium function is declared and defined to indicate the person is having medium probabiltiy of illness.
int medium(){

    printf("\nYou have a 'medium-probability' of being infected with covid 19!");
    printf("\n\n\t\t\tTips :\nTake proper precautions and maintain social distancing \nTake a covid test after 15 days! \nUse sanitizer and mask!");
    return 1;
}

// Low function is declared and defined to indicate the person is having low probabiltiy of illness.
void low(int age){

    printf("\nYou have a 'low-probability' of being infected with covid 19!");
    printf("\n\n\t\t\tTips :\nTake proper precautions and maintain social distancing \nUse sanitizer and mask!");
    if (age>=18)
    {
        printf("\nGet vaccinated soon if you haven't!");
    }

}

// Severity function is declared and defined to find out the variation in the number of Covid-19 cases each day.
int severity(int count[], FILE *fp){

    int j, n;

    for (j = 0; j <= 5; j++){
        if (count[j] < count[j + 1]){
            printf("The number of people who are ill is 'increased' by '%d' from day '%d' to day '%d'\n", count[j + 1] - count[j], j + 1, j + 2);
            fprintf(fp,"The number of people who are ill is 'increased' by '%d' from day '%d' to day '%d'\n", count[j + 1] - count[j], j + 1, j + 2);
        }
        else if (count[j] == count[j + 1]){
            printf("The number of people who are ill is 'neither increased nor decreased' from day '%d' to day '%d'\n", j + 1, j + 2);
            fprintf(fp,"The number of people who are ill is 'neither increased nor decreased' from day '%d' to day '%d'\n", j + 1, j + 2);
        }
        else{
            printf("The number of people who are ill is 'decreased' by '%d' from day '%d' to day '%d'\n", count[j] - count[j + 1], j + 1, j + 2);
            fprintf(fp,"The number of people who are ill is 'decreased' by '%d' from day '%d' to day '%d'\n", count[j] - count[j + 1], j + 1, j + 2);
        }
    }

}

// Child function is declared and defined to record the health details of a child.
int child(struct record *ptr, int a, int per){
       
        int b=0,c=0,d=0,e=0;
        printf("-->Enter your oxygen level: ");
        scanf("%d",&ptr->oxy);

        if(ptr->oxy<75||ptr->oxy>100){
            b=b+1;
        }
        printf("-->Enter the air intake rate: ");
        scanf("%d",&ptr->resp);

        if(ptr->resp<18||ptr->resp>30){
            c=c+1;
        }
        printf("-->Enter your heart rate: ");
        scanf("%d",&ptr->hr);

        if(ptr->hr<60||ptr->hr>130){
            d=d+1;
        }
        
        do{
            printf("-->Enter yes for severe cough, no for light/no cough: ");
            scanf("%s", &ptr->audio);
            if (strcmp(ptr->audio, audio_yes) == 0)
                e = e + 1;
            else if (strcmp(ptr->audio, audio_no) == 0)
                e = 0;
            else if (strcmp(ptr->audio, audio_yes) != 0 && strcmp(ptr->audio, audio_no) != 0)
                printf("Please RE-ENTER with a 'yes' or a 'no'.\n");
            
        }while (strcmp(ptr->audio, audio_yes) != 0 && strcmp(ptr->audio, audio_no) != 0);

        return a + b + c + d + e;

}
    
// Teen function is declared and defined to record the health details of a teen.
int teen(struct record persons[], int a, int per){
       
        int b=0,c=0,d=0,e=0;
        printf("-->Enter your oxygen level: ");
        scanf("%d",&persons[per].oxy);

        if(persons[per].oxy<75||persons[per].oxy>100){
            b=b+1;
        }
        printf("-->Enter the air intake rate");
        scanf("%d",&persons[per].resp);

        if(persons[per].resp<18||persons[per].resp>30){
            c=c+1;
        }
        printf("-->Enter your heart rate: ");
        scanf("%d",&persons[per].hr);

        if(persons[per].hr<60||persons[per].hr>100){
            d=d+1;
        }
        do{
            printf("-->Enter yes for severe cough, no for light/no cough: ");
            scanf("%s", &persons[per].audio);
            if (strcmp(persons[per].audio, audio_yes) == 0)
                e = e + 1;
            else if (strcmp(persons[per].audio, audio_no) == 0)
                e = 0;
            else if (strcmp(persons[per].audio, audio_yes) != 0 && strcmp(persons[per].audio, audio_no) != 0)
                printf("Please RE-ENTER with a 'yes' or a 'no'.\n");
            
        }while (strcmp(persons[per].audio, audio_yes) != 0 && strcmp(persons[per].audio, audio_no) != 0);

    return a + b + c + d + e;

}

// Adult function is declared and defined to record the health details of a male or a female adult.
int adult(struct record persons[], int a, int per){
            int  b, c, d, e;
            do{
                int b=0,c=0,d=0,e=0;

                printf("Enter your gender: ");
                scanf("%s", &persons[per].g);
                if (strcmp(persons[per].g, str_male) == 0){
                    printf("-->Enter your oxygen level: : ");
                    scanf("%d",&persons[per].oxy);
                    if (persons[per].oxy < 75 || persons[per].oxy > 100)
                        b = b + 1;
                   
                    printf("-->Enter your air intake rate: ");
                    scanf("%d",&persons[per].resp);
                    if (persons[per].resp < 14 || persons[per].resp > 18)
                        c = c + 1;
                    
                    printf("-->Enter your heart rate: ");
                    scanf("%d",&persons[per].hr);
                    if (persons[per].hr < 70 || persons[per].hr > 75)
                        d = d + 1;
                    
                    do{
                        printf("-->Enter yes for severe cough, no for light/no cough: ");
                        scanf("%s", &persons[per].audio);
                        if (strcmp(persons[per].audio, audio_yes) == 0)
                            e = e + 1;
                        else if (strcmp(persons[per].audio, audio_no) == 0)
                            e = 0;
                        else if (strcmp(persons[per].audio, audio_yes) != 0 && strcmp(persons[per].audio, audio_no) != 0)
                            printf("Please RE-ENTER with a 'yes' or a 'no'.\n");
                        
                    }while (strcmp(persons[per].audio, audio_yes) != 0 && strcmp(persons[per].audio, audio_no) != 0);
                }

                else if (strcmp(persons[per].g, str_female) == 0){
                    printf("-->Enter your oxygen level: ");
                    scanf("%d",&persons[per].oxy);
                    if (persons[per].oxy < 75 || persons[per].oxy > 100)
                        b = b + 1;
                    
                    printf("-->Enter your air intake rate: ");
                    scanf("%d",&persons[per].resp);
                    if (persons[per].resp < 16 || persons[per].resp > 20)
                        c = c + 1;
                
                    printf("-->Enter your heart rate: ");
                    scanf("%d",&persons[per].hr);
                    if (persons[per].hr < 78 || persons[per].hr > 82)
                        d = d + 1;
                    
                    do{
                        printf("-->Enter yes for severe cough, no for light/no cough: ");
                        scanf("%s", &persons[per].audio);
                        if (strcmp(persons[per].audio, audio_yes) == 0)
                            e = e + 1;
                        else if (strcmp(persons[per].audio, audio_no) == 0)
                            e = 0;
                        else if (strcmp(persons[per].audio, audio_yes) != 0 && strcmp(persons[per].audio, audio_no) != 0)
                            printf("Please RE-ENTER with a 'yes' or a 'no'.\n");
                        
                    }while (strcmp(persons[per].audio, audio_yes) != 0 && strcmp(persons[per].audio, audio_no) != 0);
                }

                else
                    printf("Kindly RE-ENTER your gender.\n");

            } while (strcmp(persons[per].g, str_male) != 0 && strcmp(persons[per].g, str_female) != 0);
            return a + b + c + d + e;
        
}

// Main function
int main(){

    FILE *fp;       // File pointer is declared.
    int sum = 0;

    int a=0, total_a=0;

    char repeat[10];

    printf("\n\t\t\t\t\t\t\t********************************************\n\n");
    printf("\t\t\t\t\t\t\t\t\tCOVID-19 SURVEY\n\n");
    printf("\t\t\t\t\t\t\t********************************************\n\n");

    // Do-While loop declared to collect the day-wise information of the desired number of people for a week, and then the number of people having high temperature each day.
    do{
        int n;
        printf("\nENTER THE NUMBER OF PEOPLE IN YOUR LOCALITY: ");
        scanf("%d", &n);
        struct record persons[n];
        int count[7];

        // For loop declared to collect people's date for analysis
        for (int j = 0; j <= 6; j++){

                printf("\n\t\tSURVEY FOR DAY %d ", j + 1);
                printf("\n\t\t------------------");

                int a=0, med_prob = 0, high_prob = 0;    

                for (int i = 1; i <= n; i++){
                    
                    int per=i-1;
                    printf("\n\nREPORT OF PERSON: %d\n\n", i);

                    printf("Enter your age: ");
                    scanf("%d", &persons[per].age);

                    printf("-->Enter your body tmperature: ");
                    scanf("%d", &persons[per].temp);

                    if (persons[per].temp > 97){
                        total_a += 1;
                        a = a + 1;
                    }

                    else if (persons[per].temp < 95);
                        a = a + 1;

                    if (persons[per].age > 0 && persons[per].age <= 12)
                        sum = child(persons,a,per);

                    else if(persons[per].age >= 13 && persons[per].age < 18)
                        sum = teen(persons,a,per);

                    else
                        sum = adult(persons,a,per);

                    if (sum >= 4)
                        high_prob += high();
                    

                    else if (sum > 2 && sum < 4)
                        med_prob += medium();
                        
                    else
                    {
                        low(persons[per].age);
                    }

                }

            printf("\n\nThe number of people having high temperature in day %d is %d. \n", j + 1, total_a);

            total_a = 0;

            count[j] = med_prob + high_prob; // Represents the number of sick individuals.

        }
        fp = fopen("Data.txt","a");     // Creates a text file called "Data.txt".
        fprintf(fp,"\n\t\t\t\t\t\t\t********************************************\n\n");
        fprintf(fp,"\t\t\t\t\t\t\t\tCOVID-19 SURVEY - COLLECTED DATA\n\n");
        fprintf(fp,"\t\t\t\t\t\t\t********************************************\n\n");

        printf("\n\n\t\t\tTHE DAY WISE REPORT OF NUMBER OF PEOPLE WHO ARE ILL IS AS FOLLOWS");
        printf("\n\t\t\t-----------------------------------------------------------------\n");
        
        fprintf(fp,"\nTHE DAY WISE REPORT OF NUMBER OF PEOPLE WHO ARE ILL IS AS FOLLOWS:-\n");
        

        int j = 0;

        // While loop declared to display the day-wise report of the number of ill people.
        while(j <= 6){

            printf("\t\t\t\t\t\tDAY %d : %d\n", j + 1, count[j]);
            fprintf(fp,"\t\t\t\t\t\tDAY %d : %d\n", j + 1, count[j],"a");
            j++;
        }
        
        printf("\n\n\t\t\tTHE VARIATION OF ILLNESS FOR A WEEK IS AS FOLLOWS\n");
        printf("\t\t\t---------------------------------------------------\n\n");
        fprintf(fp,"\nTHE VARIATION OF ILLNESS FOR A WEEK IS AS FOLLOWS:-\n");
        
        severity(count,fp);     // Severity function called to display the variation of COVID-19 for a week.

        printf("\nEnter yes if you wanna survey for another locality and no if you wanna exit: ");
        scanf("%s",repeat);
        
        fclose(fp);     // Closes the file.

    }while (strcmp(repeat,repeat_yes) == 0);

        return 0;

}
