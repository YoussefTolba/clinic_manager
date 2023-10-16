/******************************************************************************************************
 * @file: main.c
 * @author: Youssef Tolba
 * @brief: This code is used to manage a database for a small clinic
 *******************************************************************************************************
 */
/* ********************** Includes Section Start ********************** */
#include <stdio.h>
/* ********************** Includes Section End ********************** */
/* ********************** Global Variables Section Start ************** */
struct patient_data {
    int id;
    char name_first[25];
    char name_second[25];
    int gender;
    int age;
    double reservation;
}patient[100];
int bool_reserve[] = {0,0,0,0,0};
int num;
int ID;
/* ********************** Global Variables Section End ************** */
/* ********************** Sub-Program Declerations Section Start ******* */
int input_password(); // lets admin input password
void new_patient();  //allows admin to input a new patient
void print_data(ID);  //prints the data of the patient using ID number
void edit_data();  //allows admin to edit the data of any patient using their ID
void reserve();  //allows admin to make a reservation and access the available time slots
void user_view(); //allows the user to view the data of any patient
void user_ReserveView();  //allows the user to view the booked and available slots without changing them
void cancel_res();  //allows admin to cancel their reservation
/* ********************** Sub-Program Declerations Section End ******* */

int main(){
   while(1) {
       printf("please choose a user\n1)admin\n2)user\n");
       int user_type = 0;
       scanf("%d", &user_type);
       switch (user_type) {
           case 1:
                   int result = input_password();
                while (1) {
                   if (result == 1) {
                       printf("To add a new patient press 1\nTo edit the data of an already registered patient press 2\nTo reserve a slot with a doctor press 3\nTo cancel a reservation press 4\nTo view a patients record press 5\n");
                       int opp;
                       scanf("%d", &opp);
                       switch (opp) {
                           case 1:
                               new_patient();
                               break;
                           case 2:
                               edit_data();
                               break;
                           case 3:
                               reserve();
                               break;
                           case 4:
                               cancel_res();
                               break;
                           case 5:
                               printf("please enter the ID of the patient you want to view");
                               scanf("%d", &ID);
                               print_data(ID);
                               break;
                           default:
                               printf("wrong choice\n");
                               break;
                       }
                       //break;
                   }
                   printf("to go to main menu press 0, to continue press 1\n");
                   int breaker = 0;
                   scanf("%d", &breaker);
                   if(breaker == 0){
                       break;
                   }else{}
               }
           case 2:
               user_view();
               break;
           default:
               printf("wrong input\n");
               break;
       }

   }
    return 0;
}

/* ********************** Sub-Program Section Start ************* */
int input_password(){
    int password = 0;
    printf("please enter the password, you have 3 tries left\n");

    for(int i = 3; i > 0; i--){
        scanf("%d", &password);
        if(password == 1234){
            printf("correct password\n");
            return 1;
        }else if(i > 1){
            printf("incorrect password, you have %d tries left\n", i-1);

        }else{
            printf("incorrect password, you have 0 tries left\n");
            return 0;
        }
    }
}

void new_patient(){
    printf("please enter the id of the patient\n");
    scanf("%d", &num);
    patient[num].id = num;
    printf("please enter the first name of the patient\n");
    scanf("%s", patient[num].name_first);
    printf("please enter the second name of the patient\n");
    scanf("%s", patient[num].name_second);
    printf("please enter the gender of the user\n1)Male\n2)Female\n");
    scanf("%d", &patient[num].gender);
    printf("please enter the age of the user\n");
    scanf("%d", &patient[num].age);
    print_data(num);


}

void print_data(int ID){
    printf("ID:%d\n", patient[ID].id);
    printf("Name:%s %s\n", patient[ID].name_first, patient[ID].name_second);
    switch (patient[ID].gender){
        case 1:
            printf("Gender:Male\n");
            break;
        case 2:
            printf("Gender:Female\n");
            break;
        default:
            printf("wrong input\n");
            break;
    }
    printf("Age:%d\n", patient[ID].age);
}

void edit_data(){
    printf("choose how many fields you want to edit:\nmax is 3\n");
    int x = 0;
    scanf("%d", &x);
    printf("Please enter the id of the patient you want to edit:\n");
    scanf("%d", &ID);
    print_data(ID);
    for(int i = 0; i < x;i++){
        printf("Please enter number of the field you want to edit:\nFor name press 1\nFor age press 2\nFor gender press 3\n");
        int field_num;
        scanf("%d", &field_num);
        printf("please enter the new data you want below\n");
        switch (field_num){
            case 1:
                scanf("%s %s", patient[ID].name_first, patient[ID].name_second);
                break;
            case 2:
                scanf("%d", &patient[ID].age);
                break;
            case 3:
                if(patient[ID].gender == 1){
                    patient[ID].gender = 2;
                }else{
                    patient[ID].gender = 1;
                }
                break;
        }
    }
    print_data(ID);
}

void reserve(){
    printf("please enter the id of the patient doing the reservation\n");
    scanf("%d", &ID);
    print_data(ID);
    double schedule[] = {2.00, 2.30, 3.00, 4.00, 4.30 };
    printf("please choose a reservation time:\n");
    for(int i = 0; i < 5; i++){
        printf("%d)%.2f\n", i+1, schedule[i]);
    }
    int x = 0;
    scanf("%d", &x);
    switch (x){
        case 1:
            bool_reserve[0] = 1;
            patient[ID].reservation = 2.00;
            break;
        case 2:
            bool_reserve[1] = 1;
            patient[ID].reservation = 2.30;
            break;
        case 3:
            bool_reserve[2] = 1;
            patient[ID].reservation = 3.00;
            break;
        case 4:
            bool_reserve[3] = 1;
            patient[ID].reservation = 4.00;
            break;
        case 5:
            bool_reserve[4] = 1;
            patient[ID].reservation = 4.30;
            break;
        default:
            printf("wrong input");
            break;

    }
    printf("You have successfully booked the time slot: %.2f\n", patient[ID].reservation);

}

void user_view(){
    printf("to view patient record press 1\nto view reservations press 2\n");
    int x = 0;
    scanf("%d", &x);
    switch (x){
        case 1:
            printf("please enter the id of the patient you want to view\n");
            scanf("%d", &ID);
            print_data(ID);
            break;
        case 2:
            user_ReserveView();
            break;
    }
}

void user_ReserveView(){
    printf("slots available:\n1)2.00\n2)2.30\n3)3.00\n4)4.00\n5)4.30\n");
    for(int i = 0; i < 5; i++){
        if(bool_reserve[i] == 1) {
            printf("slot number %d is booked\n", i + 1);
        }else{
            printf("slot number %d is open\n", i+1);
        }
    }
}

void cancel_res(){

    printf("please enter the ID of the patient to cancel their reservation\n");
    scanf("%d", &ID);
    printf("Are you sure you want to cancel the reservation of %s %s ID number (%d)?\nPress 1 to cancel\nPress 2 to stop\n", patient[ID].name_first, patient[ID].name_first, ID);
    int cancel = 0;
    scanf("%d", &cancel);
    if(cancel == 1){

        if(patient[ID].reservation == 2.00){
            bool_reserve[0] = 0;
        }else if(patient[ID].reservation == 2.30) {
            bool_reserve[1] = 0;
        }else if(patient[ID].reservation == 3.00) {
            bool_reserve[2] = 0;
        }else if(patient[ID].reservation == 4.00) {
            bool_reserve[3] = 0;
        }else if(patient[ID].reservation == 4.30) {
            bool_reserve[4] = 0;
        }else{
            printf("wrong input");
        }
    }else{}

}
/* ********************** Sub-Program Section End ************* */