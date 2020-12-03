#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



//STUDENT NAME STRUCTURE
struct studentname {

    char firstname[40];
    char middlename[40];
    char lastname[40];
};

//STUDENT REGISTRATION NUMBER STRUCTURE
struct studentREG {

    int year;
    int term;
    char regnum[30];
};

struct marks {

    float _7th;
    float _12th;
    float _final;
    float sum;
    float yearWork;
    char grade[3];


};

struct courseinfo_1 {

    char coursename[40];
    char coursecode[40];
    float courseCH;
    struct studentname CourseLecturer;
    struct studentname CourseGTA;
    struct studentname CourselabGTA;
    struct marks sub_marks;
    float QP;


};

struct credithours {

    float max;
    float finished;
    float current;
    float remain;
};

struct GPA {

    float totalcurrent;
    float totalfinished;
    float total;
    float gpa;

};

struct courseinfo {

    int numcourses;
    float totalCH;
    int current;
    int finished;

    struct GPA G;
    struct credithours C;
    struct courseinfo_1 current_C[8];
    struct courseinfo_1 finished_C[100];




};

struct contacts {

    char email[40];
    char homeno[40];
    char mobno[40];

};

typedef struct {

    int day;
    int month;
    int year;



}Date;

//STUDENT ID STRUCTURE
struct studentID{

    char typeID[50];
    char IDnum[50];
    Date v;
};

//STUDENT HOME ADDRESS STRUCTURE
struct studentHomeAddress {

    char flatnum[40];
    char housenum[40];
    char strtname[40];
    char areaname[40];
    char cityname[40];
    char govername[40];
    char country[40];
    char postalcode[40];


};

//STUDENT MAILING ADDRESS STRUCTURE
struct studentMailingAddresss {


    char flatnum[40];
    char housenum[40];
    char strtname[40];
    char areaname[40];
    char cityname[40];
    char govername[40];
    char country[40];
    char postalcode[40];


};

//STUDENT AGE STRUCTURE
struct studentAge {

    int dayOfBirth;
    int monthOfBirth;
    int yearOfBirth;
    int age;

};

typedef struct {

    int amountpaid;
    char tranNum[50];
    char bankTran[50];
    Date d;

}payDetail;

struct payment {

    char typeoffund[50];
    int numpayment;
    int totalpaid;
    payDetail *p;


};


//A STRUCTURE THAT COMBINES THE PREVIOUS STRUCTURES
typedef struct {

    struct studentname s;
    struct studentREG s1;
    char nationality[50];
    struct studentID s2;
    struct studentHomeAddress s3;
    struct studentMailingAddresss s4;
    char gender;
    struct studentAge s5;
    struct payment s6;
    struct courseinfo s7;
    struct contacts s8;
    char department[30];

} studentdetail;

void Capfirst (char *ch)
{
    if((*ch>='a')&&(*ch<='z'))
    {
        *ch-=32;
    }


}



void get_QP (char grade[], float *qp)
{

    if(strcmp(grade, "A+")==0) {
        *qp = 4.0;
    }
    else if(strcmp(grade, "A")==0) {
        *qp = 4.0;
    }
    else if(strcmp(grade, "A-")==0) {

        *qp = 3.7;
    }
    else if(strcmp(grade, "B+")==0) {

        *qp = 3.3;
    }
    else if(strcmp(grade, "B")==0) {

        *qp = 3.0;
    }
    else if(strcmp(grade, "B-")==0) {

        *qp = 2.7;

    }
    else if(strcmp(grade, "C+")==0) {

        *qp = 2.3;
    }
    else if(strcmp(grade, "C")==0) {

        *qp = 2.0;
    }
    else if(strcmp(grade, "C-")==0) {

        *qp = 1.7;
    }
    else if(strcmp(grade, "D")==0) {

        *qp = 1.3;
    }
    else {

        *qp = 0.0;
    }




}

void grade_sub(char grade[], float marks)
{
    if((marks >= 95)&&(marks <=  100))
    {
        strcpy(grade,"A+");
    }
    else if ((marks >= 90)&&(marks < 95))
    {
        strcpy(grade, "A");
    }
    else if((marks >= 85)&&(marks < 90))
    {
        strcpy(grade, "A-");
    }
    else if((marks >= 80)&&(marks < 85))
    {

        strcpy(grade, "B+");
    }
    else if((marks >= 75)&&(marks < 80))
    {

        strcpy(grade, "B");
    }
    else if((marks >= 70)&&(marks < 75))
    {

        strcpy(grade, "B-");
    }
    else if((marks >= 65)&&(marks < 70))
    {
        strcpy(grade, "C+");

    }
    else if((marks >= 60)&&(marks < 65))
    {

        strcpy(grade, "C");
    }
    else if((marks >= 55)&&(marks < 60))
    {

        strcpy(grade, "C-");
    }
    else if((marks >= 50)&&(marks < 55))
    {
        strcpy(grade, "D");
    }
    else
    {

        strcpy(grade, "F");
    }

}


void get_gpa(float *total, float *totalCH, float *GPA)
{

    *GPA = *total / *totalCH;


}

void viewregno(char regnum[], char firstname[], char middlename[])
{
    Capfirst(&firstname[0]);
    Capfirst(&middlename[0]);

    printf("\t\t\t%s\t\t\t\t%s %s\n", regnum, firstname, middlename);

}


//FUNCTION THAT GENERATES REGISTRATION NUMBER BASED ON YEAR/TERM/STUDENT NUMBER
void registerno(char regnum[], int year , int term, int stdnum)
{

    char regno[30];


    if(stdnum < 10 && stdnum >= 1)
    {
        sprintf(regno , "0000%d", stdnum);
    }
    else if(stdnum < 100 && stdnum >= 10) {

        sprintf(regno, "000%d", stdnum);
    }
    else if(stdnum < 1000 && stdnum >=100) {

        sprintf(regno, "00%d", stdnum);
    }
    else if(stdnum < 10000 && stdnum >= 1000) {

        sprintf(regno, "0%d", stdnum);
    }
    else if(stdnum < 100000 && stdnum >= 10000) {

        sprintf(regno, "%d", stdnum);
    }
    else {

        printf("\n\t\t\t\t\tEXCEEDED THE LIMIT");
        exit(0);
    }


    if(year>=2010){

        sprintf(regnum,"%d%d%s",year-2000, term, regno);
    }
    else if( year >=2000 && year < 2010) {

        sprintf(regnum, "0%d%d%s", year-2000, term, regno);
    }
    else if( year >=1980 && year <2000)
    {

        sprintf(regnum, "%d%d%s", year - 1900, term, regno);
    }
    else{

        printf("\n\t\t\t\t\tPLEASE CHOOSE A YEAR BETWEEN 1980 and 2019");
        exit(0);
    }


}

//A FUNCTION THAT CALCULATES AGE USING CURRENT DATE AND BIRTH DATE
int StudentAGE (int dayofbirth, int monthofbirth, int yearofbirth)
{
    time_t t=time(NULL);
    struct tm *ct = localtime(&t);

    ct->tm_mon+=1;
    ct->tm_year+=1900;

    if(dayofbirth > ct->tm_mday)
    {
        ct->tm_mon-=1;
        ct->tm_mday+=30;
    }
    if(monthofbirth > ct->tm_mon)
    {
        ct->tm_year-=1;
        ct->tm_mon+=12;
    }
    if(yearofbirth > ct->tm_year)
    {
        printf("\n\t\t\t\tYOUR YEAR OF BIRTH CAN'T BE GREATER THAN THE CURRENT YEAR\n");
        printf("\n\t\t\t\t\t   PRESS ENTER KEY TO EXIT");

        fflush(stdin);

        getchar();

        exit(0);
    }

    return ct->tm_year-yearofbirth;

}


void contactinfo (studentdetail *students)
{

    printf("\n\t\t\t\t................................................\n");
    printf("\n\t\t\t\t\t  CREATING/EDITING STUDENT CONTACTS\n\n");

    printf("\n\t\t\t\t\t   STUDENT NAME: %s %s %s\n", students->s.firstname, students->s.middlename, students->s.lastname);
    printf("\t\t\t\t\t   REGISTRATION NUMBER: %s\n", students->s1.regnum);

    printf("\n\t\t\t\t................................................\n");

    printf("\t\t\t\t\tENTER STUDENT EMIAL: ");
    scanf("%39s", students->s8.email);

    printf("\t\t\t\t\tENTER STUDENT HOME NUMBER: ");
    scanf("%39s", students->s8.homeno);

    printf("\t\t\t\t\tENTER STUDENT MOBILE NUMBER: ");
    scanf("%39s", students->s8.mobno);

    printf("\n\n\t\t\t\t\tINFO SUCCESSFULLY SAVED/EDITED\n");
    printf("\n\t\t\t\t\tPRESS ENTER TO EXIT TO MENU");

    fflush(stdin);

    getchar();

    system("cls");

}


//FUNCTION THAT CREATES A STUDENT RECORD
void createStudent(studentdetail *students, int stdnum)
{
    char choice;


    students->s7.totalCH=0;
    students->s7.numcourses=0;
    students->s7.current=0;
    students->s7.finished=0;
    students->s7.C.current=0;
    students->s7.C.finished=0;

    strcpy(students->s8.email, "NOT ADDED");
    strcpy(students->s8.homeno, "NOT ADDED");
    strcpy(students->s8.mobno, "NOT ADDED");

    printf("\n\t\t\t\t  ....................................\n");
    printf("\n\t\t\t\t\tCREATING STUDENT %d RECORD\n\n", stdnum);
    printf("\t\t\t\t  ....................................\n\n");

    printf("\t\t\t\t\tENTER STUDENT FIRSTNAME: ");
    scanf("%39s", students->s.firstname);

    printf("\t\t\t\t\tENTER STUDENT MIDDLENAME: ");
    scanf("%39s", students->s.middlename);

    fflush(stdin);

    printf("\t\t\t\t\tENTER STUDENT LASTNAME: ");
    scanf("%39[^\n]", students->s.lastname);

    printf("\t\t\t\t\tENTER STUDENT NATIONALITY: ");
    scanf("%49s", students->nationality);

    fflush(stdin);

    printf("\t\t\t\t\tENTER STUDENT GENDER(M/F): ");
    scanf("%c", &students->gender);

    fflush(stdin);

    printf("\t\t\t\t\tENTER TYPE OF ID: ");
    scanf("%49[^\n]", students->s2.typeID);

    printf("\t\t\t\t\tENTER ID NUMBER: ");
    scanf("%49s", students->s2.IDnum);

    printf("\t\t\t\t\tENTER ID VALIDITY(MM/DD/YYYY): ");
    scanf("%d/%d/%d", &students->s2.v.month, &students->s2.v.day, &students->s2.v.year);

    printf("\t\t\t\t\tENTER DATE OF BIRTH (MM/DD/YYYY): ");
    scanf("%d/%d/%d", &students->s5.monthOfBirth, &students->s5.dayOfBirth, &students->s5.yearOfBirth);

    if((students->s5.monthOfBirth > 12)||(students->s5.monthOfBirth < 1)) {

        printf("\n\t\t\t\t\tPLEASE ENTER A CORRECT MONTH NUMBER\n");
        printf("\n\t\t\t\t\t    PRESS THE ENTER KEY TO EXIT");

        fflush(stdin);

        getchar();

        exit(0);
    }



    if((students->s5.dayOfBirth > 31)||(students->s5.dayOfBirth < 1)) {

        printf("\n\t\t\t\t\tPLEASE ENTER A CORRECT DAY NUMBER\n");
        printf("\n\t\t\t\t\t    PRESS THE ENTER KEY TO EXIT");

        fflush(stdin);

        getchar();

        exit(0);
    }

    students->s5.age = StudentAGE(students->s5.dayOfBirth, students->s5.monthOfBirth, students->s5.yearOfBirth);

    fflush(stdin);

    printf("\n\t\t\t\t\t\t\tENTERING HOME ADDRESS\n");
    printf("\t\t\t\t\t---------------------------------------------------\n");

    printf("\n\t\t\t\t\tENTER FLAT NUMBER: ");
    scanf("%39s", students->s3.flatnum);

    printf("\t\t\t\t\tENTER HOUSE NUMBER: ");
    scanf("%39s", students->s3.housenum);

    fflush(stdin);

    printf("\t\t\t\t\tENTER STREET NAME: ");
    scanf("%39[^\n]", students->s3.strtname);

    fflush(stdin);

    printf("\t\t\t\t\tENTER AREA/DISTRICT NAME: ");
    scanf("%39[^\n]", students->s3.areaname);

    fflush(stdin);

    printf("\t\t\t\t\tENTER CITY NAME: ");
    scanf("%39[^\n]", students->s3.cityname);

    fflush(stdin);

    printf("\t\t\t\t\tENTER GOVERNORATE NAME: ");
    scanf("%39[^\n]", students->s3.govername);

    fflush(stdin);

    printf("\t\t\t\t\tENTER COUNTRY NAME: ");
    scanf("%39[^\n]", students->s3.country);

    printf("\t\t\t\t\tENTER POSTAL CODE: ");
    scanf("%39s", students->s3.postalcode);

    fflush(stdin);

    printf("\n\n\t\t\t\t\tDOES THE MAILING ADDRESS DIFFER FROM THE HOME ADDRESS(Y/N)?: ");
    scanf("%c", &choice);

    if(choice == 'Y') {

        printf("\n\t\t\t\t\t\t\tENTERING MAILING ADDRESS\n");
        printf("\t\t\t\t\t---------------------------------------------------\n");

        fflush(stdin);

        printf("\n\t\t\t\t\tENTER FLAT NUMBER: ");
        scanf("%39s", students->s4.flatnum);

        printf("\t\t\t\t\tENTER HOUSE NUMBER: ");
        scanf("%39s", students->s4.housenum);

        printf("\t\t\t\t\tENTER STREET NAME: ");
        scanf("%39s", students->s4.strtname);

        fflush(stdin);

        printf("\t\t\t\t\tENTER AREA/DISTRICT NAME: ");
        scanf("%39s", students->s4.areaname);

        fflush(stdin);

        printf("\t\t\t\t\tENTER CITY NAME: ");
        scanf("%39s", students->s4.cityname);

        printf("\t\t\t\t\tENTER GOVERNORATE NAME: ");
        scanf("%39s", students->s4.govername);

        fflush(stdin);

        printf("\t\t\t\t\tENTER COUNTRY NAME: ");
        scanf("%39s", students->s4.country);

        printf("\t\t\t\t\tENTER POSTAL CODE: ");
        scanf("%39s", students->s4.postalcode);


    }
    else {

        strcpy(students->s4.flatnum, students->s3.flatnum);
        strcpy(students->s4.housenum, students->s3.housenum);
        strcpy(students->s4.strtname, students->s3.strtname);
        strcpy(students->s4.areaname, students->s3.areaname);
        strcpy(students->s4.cityname, students->s3.cityname);
        strcpy(students->s4.govername, students->s3.govername);
        strcpy(students->s4.country, students->s3.country);
        strcpy(students->s4.postalcode, students->s3.postalcode);

    }


    fflush(stdin);

    printf("\n\t\t\t\t\tENTER TYPE OF FUNDING: ");
    scanf("%49[^\n]", students->s6.typeoffund);

    students->s6.totalpaid=0;

    students->s6.numpayment=0;


    fflush(stdin);

    printf("\t\t\t\t\tENTER DEPARTMENT OF ENROLMENT: ");
    scanf("%39[^\n]", students->department);

    printf("\t\t\t\t\tENTER MAXIMUM CREDIT HOURS FOR DEGREE: ");
    scanf("%f", &students->s7.C.max);


    fflush(stdin);


    printf("\n\t\t\t\t\tWOULD YOU LIKE TO CREATE THE REGISTRATION NUMBER (Y/N): ");
    scanf("%c", &choice);

    if(choice == 'Y'){

        printf("\n\t\t\t\t\tTYPE REGISTRATION NUMBER OF CHOICE: ");
        scanf("%29s", students->s1.regnum);


    }
    else {

        printf("\n\t\t\t\t\tENTER YEAR OF REGISTRATION: ");
        scanf("%d", &students->s1.year);

        printf("\t\t\t\t\tENTER TERM OF REGISTRATION: ");
        scanf("%d", &students->s1.term);

        registerno((*students).s1.regnum, (*students).s1.year, (*students).s1.term, stdnum);

        printf("\t\t\t\t\tSTUDENT REGISTERATION NUMBER IS: %s\n", (*students).s1.regnum);

    }

    printf("\n\t\t\t\t\tRECORD SUCCESSFULLY CREATED\n");
    printf("\n\t\t\t\t\tPRESS ENTER TO CONTINUE/EXIT TO MENU");

}
//A FUCNTION THAT SEACRHES FOR THE APPROPRIATE REGISTERATION NUMBER IF FOUND RETURNS THE INDEX IF NOT FOUND RETURN -1
int searchStudent(char search[], studentdetail students[], int size)
{
    int result;
    int i;

    for(i=0; i<size; i++)
    {
        result=strcmp(search, students[i].s1.regnum);

        if(result==0) {

            return i;
        }

    }

    return -1;

}

//FUNTION THAT PRINTSS EXISTING STUDENT RECORDS ON SCREEN IF THE APPROPRIATE REGISTRATION NUMBER IS FOUND
void printStudent (studentdetail *students)
{

        int i;

        Capfirst(&students->s.firstname[0]);
        Capfirst(&students->s.middlename[0]);
        Capfirst(&students->s.lastname[0]);

        printf("\n\t\t\t\t\t................................................\n");

        printf("\n\t\t\t\t\t   STUDENT NAME: %s %s %s\n", students->s.firstname, students->s.middlename, students->s.lastname);
        printf("\t\t\t\t\t   REGISTRATION NUMBER: %s\n", students->s1.regnum);

        printf("\n\t\t\t\t\t................................................\n");

        Capfirst(&students->nationality[0]);

        printf("\t\t\t\t\tSTUDENT NATIONALITY : %s\n", students->nationality);

        printf("\t\t\t\t\tSTUDENT GENDER : %c\n", students->gender);

        printf("\t\t\t\t\tSTUDENT ID TYPE : %s\n", students->s2.typeID);

        printf("\t\t\t\t\tSTUDENT ID NUMBER : %s\n", students->s2.IDnum);

        printf("\t\t\t\t\tSTUDENT ID VALID UNTIL: %d/%d/%d\n", students->s2.v.month, students->s2.v.day, students->s2.v.year);

        printf("\t\t\t\t\tAGE OF THE STUDENT : %d\n", students->s5.age);

        printf("\t\t\t\t\tSTUDENT BIRTHDATE : %d/%d/%d\n", students->s5.monthOfBirth, students->s5.dayOfBirth, students->s5.yearOfBirth);

        printf("\t\t\t\t\tSTUDENT FUNDING TYPE : %s\n", students->s6.typeoffund);

        printf("\t\t\t\t\tSTUDENT DEPARTMENT OF ENROLMENT : %s\n", students->department);


        Capfirst(&students->s3.areaname[0]);
        Capfirst(&students->s3.govername[0]);
        Capfirst(&students->s3.country[0]);
        Capfirst(&students->s3.strtname[0]);

        printf("\n\t\t\t\t\t\t\tSTUDENT HOME ADDRESS\n");
        printf("\t\t\t\t\t---------------------------------------------------\n");
        printf("\t\t\t\t\tFLAT NUMBER: %s\n", students->s3.flatnum);
        printf("\t\t\t\t\tHOUSE NUMBER: %s\n", students->s3.housenum);
        printf("\t\t\t\t\tSTREET NAME: %s\n", students->s3.strtname);
        printf("\t\t\t\t\tDISTRICT/AREA NAME: %s\n", students->s3.areaname);
        printf("\t\t\t\t\tGOVERNRATE: %s\n", students->s3.govername);
        printf("\t\t\t\t\tCOUNTRY: %s\n", students->s3.country);
        printf("\t\t\t\t\tCITY: %s\n", students->s3.cityname);
        printf("\t\t\t\t\tPOSTAL CODE: %s\n", students->s3.postalcode);

        Capfirst(&students->s4.areaname[0]);
        Capfirst(&students->s4.govername[0]);
        Capfirst(&students->s4.country[0]);
        Capfirst(&students->s4.strtname[0]);


        printf("\n\t\t\t\t\t\t\tSTUDENT MAILING ADDRESS\n");
        printf("\t\t\t\t\t---------------------------------------------------\n");
        printf("\t\t\t\t\tFLAT NUMBER: %s\n", students->s4.flatnum);
        printf("\t\t\t\t\tHOUSE NUMBER: %s\n", students->s4.housenum);
        printf("\t\t\t\t\tSTREET NAME: %s\n", students->s4.strtname);
        printf("\t\t\t\t\tDISTRICT/AREA NAME: %s\n", students->s4.areaname);
        printf("\t\t\t\t\tGOVERNRATE: %s\n", students->s4.govername);
        printf("\t\t\t\t\tCOUNTRY: %s\n", students->s4.country);
        printf("\t\t\t\t\tCITY: %s\n", students->s4.cityname);
        printf("\t\t\t\t\tPOSTAL CODE: %s\n", students->s4.postalcode);

        printf("\n\t\t\t\t\t\t\tSTUDENT CONTACT INFO\n");
        printf("\t\t\t\t\t---------------------------------------------------\n");
        printf("\t\t\t\t\tSTUDENT EMAIL: %s\n", students->s8.email);
        printf("\t\t\t\t\tSTUDENT HOME NUMBER: %s\n", students->s8.homeno);
        printf("\t\t\t\t\tSTUDENT MOBILE NUMBER: %s\n", students->s8.mobno);

        //system("color 0A");
        printf("\n\t\t\t\t\t\t\tSTUDENT PAYMENT\n");
        printf("\t\t\t\t\t---------------------------------------------------\n");



        printf("\t\t\t\t\tSTUDENT NUMBER OF PAYMENTS: %d\n\n", students->s6.numpayment);

        if(students->s6.numpayment != 0) {

            for(i=0; i<students->s6.numpayment; i++) {

                printf("\t\t\t\t\tSTUDENT PAYMENT %d : %d$\n", i+1, students->s6.p[i].amountpaid);
                printf("\t\t\t\t\tSTUDENT TRANSACTION NUMBER OF PAYMENT %d : %s\n", i+1, students->s6.p[i].tranNum);
                printf("\t\t\t\t\tTHE TRANSACTION DATE OF PAYMENT %d : %d/%d/%d\n", i+1, students->s6.p[i].d.month, students->s6.p[i].d.day, students->s6.p[i].d.year);
                printf("\n");
            }


        }

        printf("\t\t\t\t\tSTUDENT TOTAL PAYMENT : %d$\n", students->s6.totalpaid);

        if(students->s7.numcourses <=0) {

            printf("\n\t\t\t\t\t\t\t   STUDENT COURSES\n");
            printf("\t\t\t\t\t-----------------------------------------------\n");

            printf("\n\t\t\t\t\tNO COURSES ENTERED\n");

        }
        else {

            if(students->s7.current > 0) {

                for(i=0; i<students->s7.current; i++) {
                    printf("\n\t\t\t\t\t\t\tSTUDENT CURRENT COURSES %d\n", i+1);
                    printf("\t\t\t\t\t-----------------------------------------------\n");
                    printf("\n\t\t\t\t\tCOURSE NAME: %s\n", students->s7.current_C[i].coursename);
                    printf("\t\t\t\t\tCOURSE CODE: %s\n", students->s7.current_C[i].coursecode);
                    printf("\t\t\t\t\tCOURSE CREDIT HOURS: %.2f\n", students->s7.current_C[i].courseCH);
                    printf("\t\t\t\t\tCOURSE LECTURER NAME: %s %s %s\n", students->s7.current_C[i].CourseLecturer.firstname, students->s7.current_C[i].CourseLecturer.middlename, students->s7.current_C[i].CourseLecturer.lastname);
                    printf("\t\t\t\t\tCOURSE GTA NAME: %s %s %s\n", students->s7.current_C[i].CourseGTA.firstname, students->s7.current_C[i].CourseGTA.middlename, students->s7.current_C[i].CourseGTA.lastname);
                    printf("\t\t\t\t\tCOURSE LAB GTA NAME: %s %s %s\n", students->s7.current_C[i].CourselabGTA.firstname, students->s7.current_C[i].CourselabGTA.middlename, students->s7.current_C[i].CourselabGTA.lastname);
                    printf("\t\t\t\t\tCOURSE 7TH MARKS: %.2f / 30\n", students->s7.current_C[i].sub_marks._7th);
                    printf("\t\t\t\t\tCOURSE 12TH MARKS: %.2f / 20\n", students->s7.current_C[i].sub_marks._12th);
                    printf("\t\t\t\t\tCOURSE YEAK WORK MARKS: %.2f / 10\n", students->s7.current_C[i].sub_marks.yearWork);
                    printf("\t\t\t\t\tCOURSE FINAL MARKS: %.2f / 40\n", students->s7.current_C[i].sub_marks._final);
                    printf("\t\t\t\t\tCOURSE TOTAL MARKS: %.2f / 100\n\t\t\t\t\tSCORING: %s\n", students->s7.current_C[i].sub_marks.sum, students->s7.current_C[i].sub_marks.grade);
                    printf("\t\t\t\t\tCOURSE QUALITY POINT: %.2f\n", students->s7.current_C[i].QP);
                }

            }

            if(students->s7.finished > 0) {

                for(i=0; i<students->s7.finished; i++){
                    printf("\n\t\t\t\t\t\t\tSTUDENT FINISHED COURSES %d\n", i+1);
                    printf("\t\t\t\t\t-----------------------------------------------\n");
                    printf("\n\t\t\t\t\tCOURSE NAME: %s\n", students->s7.finished_C[i].coursename);
                    printf("\t\t\t\t\tCOURSE CODE: %s\n", students->s7.finished_C[i].coursecode);
                    printf("\t\t\t\t\tCOURSE CREDIT HOURS: %.2f\n", students->s7.finished_C[i].courseCH);
                    printf("\t\t\t\t\tCOURSE LECTURER NAME: %s %s %s\n", students->s7.finished_C[i].CourseLecturer.firstname, students->s7.current_C[i].CourseLecturer.middlename, students->s7.current_C[i].CourseLecturer.lastname);
                    printf("\t\t\t\t\tCOURSE GTA NAME: %s %s %s\n", students->s7.finished_C[i].CourseGTA.firstname, students->s7.finished_C[i].CourseGTA.middlename, students->s7.finished_C[i].CourseGTA.lastname);
                    printf("\t\t\t\t\tCOURSE LAB GTA NAME: %s %s %s\n", students->s7.finished_C[i].CourselabGTA.firstname, students->s7.finished_C[i].CourselabGTA.middlename, students->s7.finished_C[i].CourselabGTA.lastname);
                    printf("\t\t\t\t\tCOURSE 7TH MARKS: %.2f / 30\n", students->s7.finished_C[i].sub_marks._7th);
                    printf("\t\t\t\t\tCOURSE 12TH MARKS: %.2f / 20\n", students->s7.finished_C[i].sub_marks._12th);
                    printf("\t\t\t\t\tCOURSE YEAK WORK MARKS: %.2f / 10\n", students->s7.finished_C[i].sub_marks.yearWork);
                    printf("\t\t\t\t\tCOURSE FINAL MARKS: %.2f / 40\n", students->s7.finished_C[i].sub_marks._final);
                    printf("\t\t\t\t\tCOURSE TOTAL MARKS: %.2f / 100\n\t\t\t\t\tSCORING: %s\n", students->s7.finished_C[i].sub_marks.sum, students->s7.finished_C[i].sub_marks.grade);
                    printf("\t\t\t\t\tCOURSE QUALITY POINT: %.2f\n", students->s7.finished_C[i].QP);


                }
            }
            /*
            if(students->s7.finished==0){

                printf("\n\t\t\t\t\tTOTAL NUMBER OF COURSES: %d\n", students->s7.current);
            }
            else if(students->s7.current==0) {

                printf("\n\t\t\t\t\tTOTAL NUMBER OF COURSES: %d\n", students->s7.finished);

            }
            else {*/

                printf("\n\t\t\t\t\tTOTAL NUMBER OF COURSES: %d\n", students->s7.numcourses);

            //}
            /*
            if(students->s7.current==0) {

                printf("\n\t\t\t\t\tCOURSES TOTAL CREDIT HOURS: %f\n", students->s7.C.finished); //out of maximum credit hours entered by the operator

            }
            else if(students->s7.finished==0) {


                printf("\n\t\t\t\t\tCOURSES TOTAL CREDIT HOURS: %f\n", students->s7.C.current);

            }
            else {*/


                printf("\n\t\t\t\t\tCOURSES TOTAL CREDIT HOURS: %.2f out of %.2f\n", students->s7.totalCH, students->s7.C.max);



                printf("\t\t\t\t\tCOURSES REMAINING CREDIT HOURS: %.2f\n", students->s7.C.remain = students->s7.C.max - students->s7.C.finished - students->s7.C.current);

                printf("\t\t\t\t\tSTUDENT OVERALL GPA: %.2f\n", students->s7.G.gpa);
            //}


        }


        printf("\n\t\t\t\t\tPRESS ENTER TO RETURN TO THE MENU");

        fflush(stdin);

        getchar();

        system("cls");


}

//FUNCTION THAT EDITS/MODIFY THE EXISITNG STUDENT RECORDS USING THE REGISTRATIO NUMBER
void editStudent (studentdetail *students)
{
        char choice;

        Capfirst(&students->s.firstname[0]);
        Capfirst(&students->s.middlename[0]);
        Capfirst(&students->s.lastname[0]);

        printf("\n\t\t\t\t\t................................................\n");
        printf("\t\t\t\t\t       EDITING STUDENT RECORD:\n");
        printf("\n\t\t\t\t\t       STUDENT NAME: %s %s %s\n", students->s.firstname, students->s.middlename, students->s.lastname);
        printf("\t\t\t\t\t       REGISTRATION NUMBER: %s\n", students->s1.regnum);

        printf("\n\t\t\t\t\t................................................\n");


        printf("\t\t\t\t\tENTER STUDENT FIRSTNAME: ");
        scanf("%39s", students->s.firstname);

        printf("\t\t\t\t\tENTER STUDENT MIDDLENAME: ");
        scanf("%39s", students->s.middlename);

        fflush(stdin);

        printf("\t\t\t\t\tENTER STUDENT LASTNAME: ");
        scanf("%39[^\n]", students->s.lastname);

        Capfirst(&students->nationality[0]);

        printf("\t\t\t\t\tENTER STUDENT NATIONALITY: ");
        scanf("%49s", students->nationality);

        fflush(stdin);

        printf("\t\t\t\t\tENTER STUDENT GENDER(M/F): ");
        scanf("%c", &students->gender);

        fflush(stdin);

        printf("\t\t\t\t\tENTER TYPE OF ID: ");
        scanf("%49[^\n]", students->s2.typeID);

        printf("\t\t\t\t\tENTER ID NUMBER: ");
        scanf("%49s", students->s2.IDnum);

        printf("\t\t\t\t\tENTER ID VALIDITY (MM/DD/YYYY): ");
        scanf("%d/%d/%d", &students->s2.v.month, &students->s2.v.day, &students->s2.v.year);

        printf("\t\t\t\t\tENTER DATE OF BIRTH (MM/DD/YYY): ");
        scanf("%d/%d/%d", &students->s5.monthOfBirth, &students->s5.dayOfBirth, &students->s5.yearOfBirth);

        if((students->s5.monthOfBirth > 12)||(students->s5.monthOfBirth < 1)) {

            printf("\t\t\t\t\tPLEASE ENTER A CORRECT MONTH NUMBER\n");
            printf("\n\t\t\t\t\tPRESS THE ENTER KEY TO EXIT");

            fflush(stdin);

            getchar();

            exit(0);
        }


        if((students->s5.dayOfBirth > 31)||(students->s5.dayOfBirth < 1)) {

            printf("\t\t\t\t\tPLEASE ENTER A CORRECT DAY NUMBER\n");
            printf("\n\t\t\t\t\tPRESS THE ENTER KEY TO EXIT");

            fflush(stdin);

            getchar();

            exit(0);
        }

        students->s5.age = StudentAGE(students->s5.dayOfBirth, students->s5.monthOfBirth, students->s5.yearOfBirth);

        fflush(stdin);

        printf("\n\t\t\t\t\t\t\tENTERING HOME ADDRESS\n");
        printf("\t\t\t\t\t---------------------------------------------------\n");

        printf("\n\t\t\t\t\tENTER FLAT NUMBER: ");
        scanf("%39s", students->s3.flatnum);

        printf("\t\t\t\t\tENTER HOUSE NUMBER: ");
        scanf("%39s", students->s3.housenum);

        fflush(stdin);

        printf("\t\t\t\t\tENTER STREET NAME: ");
        scanf("%39[^\n]", students->s3.strtname);

        fflush(stdin);

        printf("\t\t\t\t\tENTER AREA/DISTRICT NAME: ");
        scanf("%39[^\n]", students->s3.areaname);

        fflush(stdin);

        printf("\t\t\t\t\tENTER CITY NAME: ");
        scanf("%39[^\n]", students->s3.cityname);

        fflush(stdin);

        printf("\t\t\t\t\tENTER GOVERNORATE NAME: ");
        scanf("%39[^\n]", students->s3.govername);

        fflush(stdin);

        printf("\t\t\t\t\tENTER COUNTRY NAME: ");
        scanf("%39[^\n]", students->s3.country);

        printf("\t\t\t\t\tENTER POSTAL CODE: ");
        scanf("%39s", students->s3.postalcode);

        fflush(stdin);

        printf("\n\n\t\t\t\t\tDOES THE MAILING ADDRESS DIFFER FROM THE HOME ADDRESS(Y/N)?: ");
        scanf("%c", &choice);

        if(choice == 'Y') {

            printf("\n\t\t\t\t\t\t\tENTERING MAILING ADDRESS\n");
            printf("\t\t\t\t\t---------------------------------------------------\n");

            fflush(stdin);

            printf("\n\t\t\t\t\tENTER FLAT NUMBER: ");
            scanf("%39s", students->s4.flatnum);

            printf("\t\t\t\t\tENTER HOUSE NUMBER: ");
            scanf("%39s", students->s4.housenum);

            printf("\t\t\t\t\tENTER STREET NAME: ");
            scanf("%39s", students->s4.strtname);

            fflush(stdin);

            printf("\t\t\t\t\tENTER AREA/DISTRICT NAME: ");
            scanf("%39s", students->s4.areaname);

            fflush(stdin);

            printf("\t\t\t\t\tENTER CITY NAME: ");
            scanf("%39s", students->s4.cityname);

            printf("\t\t\t\t\tENTER GOVERNORATE NAME: ");
            scanf("%39s", students->s4.govername);

            fflush(stdin);

            printf("\t\t\t\t\tENTER COUNTRY NAME: ");
            scanf("%39s", students->s4.country);

            printf("\t\t\t\t\tENTER POSTAL CODE: ");
            scanf("%39s", students->s4.postalcode);


        }
        else {

            strcpy(students->s4.flatnum, students->s3.flatnum);
            strcpy(students->s4.housenum, students->s3.housenum);
            strcpy(students->s4.strtname, students->s3.strtname);
            strcpy(students->s4.areaname, students->s3.areaname);
            strcpy(students->s4.cityname, students->s3.cityname);
            strcpy(students->s4.govername, students->s3.govername);
            strcpy(students->s4.country, students->s3.country);
            strcpy(students->s4.postalcode, students->s3.postalcode);

        }

        fflush(stdin);

        printf("\t\t\t\t\tENTER STUDENT FUNDING TYPE: ");
        scanf("%49[^\n]", students->s6.typeoffund);

        fflush(stdin);

        printf("\t\t\t\t\tENTER DEPARTMENT OF ENROLLMENT: ");
        scanf("%39s", students->department);


        fflush(stdin);

        printf("\t\t\t\t\tENTER MAXIMUM CREDIT HOURS FOR DEGREE: ");
        scanf("%f", &students->s7.C.max);


        printf("\n\n\t\t\t\t\tRECORD SUCCESSFULLY EDITED\n");
        printf("\n\t\t\t\t\tPRESS ENTER TO RETURN TO THE MENU");

        fflush(stdin);

        getchar();

        system("cls");

}

void studentpayments (studentdetail *students)
{
    int i;

    Capfirst(&students->s.firstname[0]);
    Capfirst(&students->s.middlename[0]);
    Capfirst(&students->s.lastname[0]);

    printf("\n\t\t\t\t\t................................................\n");
    printf("\n\t\t\t\t\t      ADDING/EDITING STUDENT PAYMENT\n");
    printf("\n\t\t\t\t\t      STUDENT NAME: %s %s %s\n", students->s.firstname, students->s.middlename, students->s.lastname);
    printf("\t\t\t\t\t      REGISTRATION NUMBER: %s\n", students->s1.regnum);
    printf("\n\t\t\t\t\t................................................\n");

    printf("\n\t\t\t\t\tENTER NUMBER OF PAYMENTS: ");
    scanf("%d", &students->s6.numpayment);

    students->s6.p = (payDetail *)malloc((students->s6.numpayment)*sizeof(payDetail));

    students->s6.totalpaid = 0;

    for(i=0; i < students->s6.numpayment; i++) {

        printf("\n\t\t\t\t\t\t\tPAYMENT %d\n", i+1);
        printf("\t\t\t\t\t----------------------------------------------\n");
        printf("\t\t\t\t\tENTER AMOUNT PAID: ");
        scanf("%d", &students->s6.p[i].amountpaid);

        fflush(stdin);

        printf("\t\t\t\t\tENTER TRANSACTION NUMBER OF PAYMENT: ");
        scanf("%49[^\n]", students->s6.p[i].tranNum);

        fflush(stdin);

        printf("\t\t\t\t\tENTER BANK OF TRANSACTION OF PAYMENT: ");
        scanf("%49[^\n]", students->s6.p[i].bankTran);

        printf("\t\t\t\t\tENTER DATE OF PAYMENT (MM/DD/YYYY): ");
        scanf("%d/%d/%d", &students->s6.p[i].d.month, &students->s6.p[i].d.day, &students->s6.p[i].d.year);

        students->s6.totalpaid += students->s6.p[i].amountpaid;

    }

    printf("\n\n\t\t\t\t\tPAYMENT SUCCESSFULLY ADDED/EDITED\n");
    printf("\n\t\t\t\t\tPRESS THE ENTER KEY TO RETURN TO THE MENU");

    fflush(stdin);

    getchar();

    system("cls");
}


void studentCourses (studentdetail *students)
{

    int choice;
    int i;

    Capfirst(&students->s.firstname[0]);
    Capfirst(&students->s.middlename[0]);
    Capfirst(&students->s.lastname[0]);


    while (choice !=3) {

        printf("\n\t\t\t\t  ................................................\n");
        printf("\n\t\t\t\t\t   ADDING/EDITING STUDENT COURSES:\n");

        printf("\n\t\t\t\t\t   STUDENT NAME: %s %s %s\n", students->s.firstname, students->s.middlename, students->s.lastname);
        printf("\t\t\t\t\t   REGISTRATION NUMBER: %s\n", students->s1.regnum);

        printf("\n\t\t\t\t  ................................................\n");

        printf("\n\t\t\t\t\t1. TO ENTER CURRENT COUSES\n");
        printf("\t\t\t\t\t2. TO ENTER FINISHED COURSES\n");
        printf("\t\t\t\t\t3. TO RETURN TO MAIN MENU\n");
        printf("\t\t\t\t\tENTER YOUR OPTION: ");
        scanf("%d", &choice);

        system("cls");


        switch(choice)
        {

            case 1:

                students->s7.C.current=0;
                students->s7.G.totalcurrent=0;

                printf("\n\n\n\n\n\t\t\t\t\tENTER NUMBER OF CURRENT COURSES (8 MAX): ");
                scanf("%d", &students->s7.current);

                system("cls");

                for(i=0; i<students->s7.current; i++) {

                    fflush(stdin);

                    printf("\n\t\t\t\t\t\t\t   COURSE %d\n", i+1);
                    printf("\t\t\t\t\t-----------------------------------------------\n");

                    printf("\t\t\t\t\tENTER COURSE NAME: ");
                    scanf("%39[^\n]", students->s7.current_C[i].coursename);

                    fflush(stdin);

                    printf("\t\t\t\t\tENTER COURSE CODE: ");
                    scanf("%39[^\n]", students->s7.current_C[i].coursecode);

                    printf("\t\t\t\t\tENTER COURSE CREDIT HOURS: ");
                    scanf("%f", &students->s7.current_C[i].courseCH);

                    students->s7.C.current += students->s7.current_C[i].courseCH;

                    fflush(stdin);

                    printf("\t\t\t\t\tENTER COURSE LECTURER FIRST NAME: ");
                    scanf("%39[^\n]", students->s7.current_C[i].CourseLecturer.firstname);

                    fflush(stdin);

                    printf("\t\t\t\t\tENTER COURSE LECTURER MIDDLE NAME: ");
                    scanf("%39[^\n]", students->s7.current_C[i].CourseLecturer.middlename);

                    fflush(stdin);

                    printf("\t\t\t\t\tENTER COURSE LECTURER LAST NAME: ");
                    scanf("%39[^\n]", students->s7.current_C[i].CourseLecturer.lastname);

                    fflush(stdin);

                    printf("\t\t\t\t\tENTER COURSE GTA FIRST NAME: ");
                    scanf("%39[^\n]", students->s7.current_C[i].CourseGTA.firstname);

                    fflush(stdin);

                    printf("\t\t\t\t\tENTER COURSE GTA MIDDLE NAME: ");
                    scanf("%39[^\n]", students->s7.current_C[i].CourseGTA.middlename);

                    fflush(stdin);

                    printf("\t\t\t\t\tENTER COURSE GTA LAST NAME: ");
                    scanf("%39[^\n]", students->s7.current_C[i].CourseGTA.lastname);

                    fflush(stdin);

                    printf("\t\t\t\t\tENTER COURSE LAB GTA FIRST NAME: ");
                    scanf("%39[^\n]", students->s7.current_C[i].CourselabGTA.firstname);

                    fflush(stdin);

                    printf("\t\t\t\t\tENTER COURSE LAB GTA MIDDLE NAME: ");
                    scanf("%39[^\n]", students->s7.current_C[i].CourselabGTA.middlename);

                    fflush(stdin);

                    printf("\t\t\t\t\tENTER COURSE LAB GTA LAST NAME: ");
                    scanf("%39[^\n]", students->s7.current_C[i].CourselabGTA.lastname);

                    printf("\t\t\t\t\tENTER COURSE 7TH MARK (OUT OF 30): ");
                    scanf("%f", &students->s7.current_C[i].sub_marks._7th);

                    printf("\t\t\t\t\tENTER COURSE 12TH MARK (OUT OF 20): ");
                    scanf("%f", &students->s7.current_C[i].sub_marks._12th);

                    printf("\t\t\t\t\tENTER COURE YEAR WORK (OUT OF 10): ");
                    scanf("%f", &students->s7.current_C[i].sub_marks.yearWork);

                    printf("\t\t\t\t\tENTER FINAL EXAM MARK (OUT OF 40): ");
                    scanf("%f", &students->s7.current_C[i].sub_marks._final);

                    students->s7.current_C[i].sub_marks.sum=0;

                    students->s7.current_C[i].sub_marks.sum += students->s7.current_C[i].sub_marks._final + students->s7.current_C[i].sub_marks.yearWork + students->s7.current_C[i].sub_marks._12th + students->s7.current_C[i].sub_marks._7th;

                    grade_sub(students->s7.current_C[i].sub_marks.grade, students->s7.current_C[i].sub_marks.sum);

                    get_QP(students->s7.current_C[i].sub_marks.grade, &students->s7.current_C[i].QP);

                    students->s7.G.totalcurrent += students->s7.current_C[i].QP * students->s7.current_C[i].courseCH;
                }






                if(students->s7.current==0) {

                    students->s7.totalCH -= students->s7.C.current;

                }

                students->s7.totalCH =  students->s7.C.finished + students->s7.C.current;

                if(students->s7.current==0){

                    students->s7.numcourses -= students->s7.current;
                }
                students->s7.numcourses = students->s7.current + students->s7.finished;

                students->s7.G.total = students->s7.G.totalcurrent + students->s7.G.totalfinished;

                get_gpa(&students->s7.G.total, &students->s7.totalCH, &students->s7.G.gpa);

                printf("\n\n\t\t\t\t\tCOURSES SUCCESSFULLY ADDED/EDITED\n");
                printf("\n\t\t\t\t\tPRESS ENTER TO RETURN TO MENU");

                fflush(stdin);

                getchar();

                system("cls");


            break;

            case 2:

                students->s7.C.finished=0;
                students->s7.G.totalfinished=0;

                printf("\n\n\n\n\n\t\t\t\t\tENTER NUMBER OF FINISHED COURSES: ");
                scanf("%d", &students->s7.finished);

                system("cls");

                for(i=0; i<students->s7.finished; i++) {

                    fflush(stdin);

                    printf("\n\t\t\t\t\t\t\t   COURSE %d\n", i+1);
                    printf("\t\t\t\t\t-----------------------------------------------\n");

                    printf("\t\t\t\t\tENTER COURSE NAME: ");
                    scanf("%39[^\n]", students->s7.finished_C[i].coursename);

                    fflush(stdin);

                    printf("\t\t\t\t\tENTER COURSE CODE: ");
                    scanf("%39[^\n]", students->s7.finished_C[i].coursecode);

                    printf("\t\t\t\t\tENTER COURSE CREDIT HOURS: ");
                    scanf("%f", &students->s7.finished_C[i].courseCH);

                    students->s7.C.finished += students->s7.finished_C[i].courseCH;

                    fflush(stdin);

                    printf("\t\t\t\t\tENTER COURSE LECTURER FIRST NAME: ");
                    scanf("%39[^\n]", students->s7.finished_C[i].CourseLecturer.firstname);

                    fflush(stdin);

                    printf("\t\t\t\t\tENTER COURSE LECTURER MIDDLE NAME: ");
                    scanf("%39[^\n]", students->s7.finished_C[i].CourseLecturer.middlename);

                    fflush(stdin);

                    printf("\t\t\t\t\tENTER COURSE LECTURER LAST NAME: ");
                    scanf("%39[^\n]", students->s7.finished_C[i].CourseLecturer.lastname);

                    fflush(stdin);

                    printf("\t\t\t\t\tENTER COURSE GTA FIRST NAME: ");
                    scanf("%39[^\n]", students->s7.finished_C[i].CourseGTA.firstname);

                    fflush(stdin);

                    printf("\t\t\t\t\tENTER COURSE GTA MIDDLE NAME: ");
                    scanf("%39[^\n]", students->s7.finished_C[i].CourseGTA.middlename);

                    fflush(stdin);

                    printf("\t\t\t\t\tENTER COURSE GTA LAST NAME: ");
                    scanf("%39[^\n]", students->s7.finished_C[i].CourseGTA.lastname);

                    fflush(stdin);

                    printf("\t\t\t\t\tENTER COURSE LAB GTA FIRST NAME: ");
                    scanf("%39[^\n]", students->s7.finished_C[i].CourselabGTA.firstname);

                    fflush(stdin);

                    printf("\t\t\t\t\tENTER COURSE LAB GTA MIDDLE NAME: ");
                    scanf("%39[^\n]", students->s7.finished_C[i].CourselabGTA.middlename);

                    fflush(stdin);

                    printf("\t\t\t\t\tENTER COURSE LAB GTA LAST NAME: ");
                    scanf("%39[^\n]", students->s7.finished_C[i].CourselabGTA.lastname);

                    printf("\t\t\t\t\tENTER COURSE 7TH MARK (OUT OF 30): ");
                    scanf("%f", &students->s7.finished_C[i].sub_marks._7th);

                    printf("\t\t\t\t\tENTER COURSE 12TH MARK (OUT OF 20): ");
                    scanf("%f", &students->s7.finished_C[i].sub_marks._12th);

                    printf("\t\t\t\t\tENTER COURE YEAR WORK (OUT OF 10): ");
                    scanf("%f", &students->s7.finished_C[i].sub_marks.yearWork);

                    printf("\t\t\t\t\tENTER FINAL EXAM MARK (OUT OF 40): ");
                    scanf("%f", &students->s7.finished_C[i].sub_marks._final);

                    students->s7.finished_C[i].sub_marks.sum=0;

                    students->s7.finished_C[i].sub_marks.sum += students->s7.finished_C[i].sub_marks._final + students->s7.finished_C[i].sub_marks.yearWork + students->s7.finished_C[i].sub_marks._12th + students->s7.finished_C[i].sub_marks._7th;

                    grade_sub(students->s7.finished_C[i].sub_marks.grade, students->s7.finished_C[i].sub_marks.sum);

                    get_QP(students->s7.finished_C[i].sub_marks.grade, &students->s7.finished_C[i].QP);

                    students->s7.G.totalfinished += students->s7.finished_C[i].QP * students->s7.finished_C[i].courseCH;
                }

                //
                if(students->s7.finished==0){

                    students->s7.totalCH -= students->s7.C.finished;
                }



                students->s7.totalCH =  students->s7.C.finished + students->s7.C.current;


                //

                if(students->s7.finished==0) {

                    students->s7.numcourses -= students->s7.finished;
                }

                students->s7.numcourses = students->s7.current + students->s7.finished;

                students->s7.G.total = students->s7.G.totalcurrent + students->s7.G.totalfinished;

                get_gpa(&students->s7.G.total, &students->s7.totalCH, &students->s7.G.gpa);

                printf("\n\n\t\t\t\t\tCOURSES SUCCESSFULLY ADDED/EDITED\n");
                printf("\n\t\t\t\t\tPRESS ENTER TO RETURN TO MENU");

                fflush(stdin);

                getchar();

                system("cls");

            break;

            case 3:

            break;

            default:

                printf("\n\n\n\n\n\t\t\t\tPLEASE ENTER A CORRECT NUMBER FORM THE MENU\n");
                printf("\n\t\t\t\t\tPRESS ENTER TO CONTINUE");

                fflush(stdin);
                getchar();
                system("cls");


            break;

        }
    }




}



int main()
{
    int stdnum=0;
    int size=0;
    int i;
    int choice;
    char search[50];
    int index;

    studentdetail *students;


    while(choice!=8) {

        printf("\n\t\t\t\t................................................\n");
        printf("\n\t\t\t\t\tAAST REGISTRATION SYSTEM PROJECT\n\n");
        printf("\t\t\t\t................................................\n\n");
        printf("\t\t\t\t\t1. CREATE STUDENT RECORD\n");
        printf("\t\t\t\t\t2. SEARCH TO VIEW STUDENT RECORD\n");
        printf("\t\t\t\t\t3. SEARCH TO EDIT STUDENT RECORD\n");
        printf("\t\t\t\t\t4. SEARCH TO ADD/EDIT STUDENT PAYMENT\n");
        printf("\t\t\t\t\t5. VIEW STORED REGISTERATION NUMBERS\n");
        printf("\t\t\t\t\t6. SEACH TO ADD/EDIT STUDENT COURSES\n");
        printf("\t\t\t\t\t7. SEARCH TO ADD/EDIT STUDENT CONTACT INFO\n");
        printf("\t\t\t\t\t8. EXIT\n");
        printf("\t\t\t\t\tENTER YOUR OPTION: ");

        scanf("%d", &choice);

        system("cls");

        switch(choice)
        {
            case 1://CREATE/OVERWRITE A STUDENT

                printf("\n\n\n\n\n\t\t\t\tENTER HOW MANY STUDENTS YOU WOULD LIKE TO ADD: ");
                scanf("%d", &size);

                students = (studentdetail*)malloc(size*sizeof(studentdetail));

                //creates a dynamic array based on the number of students

                system("cls");

                for(i=0; i<size; i++)
                {
                    stdnum=i+1;

                    createStudent(&students[i], stdnum);

                    //this function creates a student record

                    fflush(stdin);

                    getchar();

                    system("cls");

                }

            break;


            case 2:

                if(size==0) {

                    printf("\n\n\n\n\n\t\t\t\tYOU NEED TO CREATE A STUDENT RECORD\n");
                    printf("\n\t\t\t\tPRESS ENTER TO RETURN TO THE MENU");

                    //if no student record is created in the first place a waring message is displayed

                    fflush(stdin);

                    getchar();

                    system("cls");

                    break;
                }

                //if a student record is indeed created the user is asked to input the registration number to search for the particular student


                printf("\n\n\n\n\n\t\t\t\tENTER REGISTRATION NUMBER: ");
                scanf("%49s", search);

                system("cls");

                index = searchStudent(search, students, size);

                //this function returns the index if the student is found else it returns -1

                if(index==-1) {

                    printf("\n\n\n\n\n\t\t\t\tRECORD NOT FOUND\n");
                    printf("\n\t\t\t\tPRESS THE ENTER KEY TO EXIT TO THE MENU");

                    fflush(stdin);

                    getchar();

                    system("cls");

                    break;
                }

                printStudent(&students[index]);

                //this function is responsible for printing all of the student info


            break;

            case 3:

                if(size==0) {

                    printf("\n\n\n\n\n\t\t\t\tYOU NEED TO CREATE A STUDENT RECORD\n");
                    printf("\n\t\t\t\tPRESS ENTER TO RETURN TO THE MENU");

                    fflush(stdin);

                    getchar();

                    system("cls");

                    break;
                }


                printf("\n\n\n\n\n\t\t\t\tENTER REGISTRATION NUMBER: ");
                scanf("%49s", search);

                system("cls");


                index = searchStudent(search, students, size);

                if(index==-1) {

                    printf("\n\n\n\n\n\t\t\t\tRECORD NOT FOUND\n");
                    printf("\n\t\t\t\tPRESS THE ENTER KEY TO EXIT TO THE MENU");

                    fflush(stdin);

                    getchar();

                    system("cls");

                    break;
                }

                editStudent(&students[index]);

            break;

            case 4://payment

                if(size==0) {

                    printf("\n\n\n\n\n\t\t\t\tYOU NEED TO CREATE A STUDENT RECORD\n");
                    printf("\n\t\t\t\tPRESS ENTER TO RETURN TO THE MENU");

                    fflush(stdin);

                    getchar();

                    system("cls");

                    break;
                }


                printf("\n\n\n\n\n\t\t\t\tENTER REGISTRATION NUMBER: ");
                scanf("%49s", search);

                system("cls");


                index = searchStudent(search, students, size);

                if(index==-1) {

                    printf("\n\n\n\n\n\t\t\t\tRECORD NOT FOUND\n");
                    printf("\n\t\t\t\tPRESS THE ENTER KEY TO EXIT TO THE MENU");

                    fflush(stdin);

                    getchar();

                    system("cls");

                    break;
                }

                studentpayments(&students[index]);


            break;

            case 5://view stored registration number

                if(size==0) {

                    printf("\n\n\n\n\n\t\t\t\tYOU NEED TO CREATE A STUDENT RECORD\n");
                    printf("\n\t\t\t\tPRESS ENTER TO RETURN TO THE MENU");

                    fflush(stdin);

                    getchar();

                    system("cls");

                    break;

                }

                printf("\n\t\t\tREGISTRATION NUMBERS\t\t\tSTUDENT NAMES\n\n");
                for(i=0; i<size; i++) {

                    viewregno(students[i].s1.regnum, students[i].s.firstname, students[i].s.middlename);
                }
                fflush(stdin);

                getchar();

                system("cls");


            break;


            case 6:// ADD COURSES

                if(size==0) {

                    printf("\n\n\n\n\n\t\t\t\tYOU NEED TO CREATE A STUDENT RECORD\n");
                    printf("\n\t\t\t\tPRESS ENTER TO RETURN TO THE MENU");

                    fflush(stdin);

                    getchar();

                    system("cls");

                    break;
                }


                printf("\n\n\n\n\n\t\t\t\tENTER REGISTRATION NUMBER: ");
                scanf("%49s", search);

                system("cls");


                index = searchStudent(search, students, size);

                if(index==-1) {

                    printf("\n\n\n\n\n\t\t\t\tRECORD NOT FOUND\n");
                    printf("\n\t\t\t\tPRESS THE ENTER KEY TO EXIT TO THE MENU");

                    fflush(stdin);

                    getchar();

                    system("cls");

                    break;
                }


                studentCourses (&students[index]);


            break;

            case 7://ADD/EDIT STUDENT CONTACT INFO

                if(size==0) {

                    printf("\n\n\n\n\n\t\t\t\tYOU NEED TO CREATE A STUDENT RECORD\n");
                    printf("\n\t\t\t\tPRESS ENTER TO RETURN TO THE MENU");

                    fflush(stdin);

                    getchar();

                    system("cls");

                    break;
                }


                printf("\n\n\n\n\n\t\t\t\tENTER REGISTRATION NUMBER: ");
                scanf("%49s", search);

                system("cls");


                index = searchStudent(search, students, size);

                if(index==-1) {

                    printf("\n\n\n\n\n\t\t\t\tRECORD NOT FOUND\n");
                    printf("\n\t\t\t\tPRESS THE ENTER KEY TO EXIT TO THE MENU");

                    fflush(stdin);

                    getchar();

                    system("cls");

                    break;
                }
                contactinfo(&students[index]);

            break;

            case 8:

            break;


            default://SENDS A WARNING MESSAGE TO THE USER IF HE/SHE INPUTS A NUMBER NOT FROM THE MENU

                printf("\n\n\n\n\n\t\t\t\tPLEASE ENTER A CORRECT NUMBER FORM THE MENU\n");
                printf("\n\t\t\t\t\tPRESS ENTER TO CONTINUE");

                fflush(stdin);
                getchar();
                system("cls");

            break;
        }

    }


    return 0;
}