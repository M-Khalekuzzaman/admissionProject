#include<stdio.h>
#include<conio.h>
struct StudentInfo
{

    char name[25];
    char nickName[15];
    char fname[25];
    char mName[25];
    int className,dateOfBirth,phoneNumber,id,cls,no;
    char userName[10];
};

registation()
{
    FILE *file;
    file = fopen("student-Information.txt","w");
    if(file == NULL)
    {
        printf("Student-information file does not created\n");
    }
    else
    {
        printf("Student-information file create successfully\n");
        int num;
        printf("\nHow many student details store in your file : ");
        scanf("%d",&num);
        struct StudentInfo student[num];
        for(int i = 0 ; i<num ; i++)
        {

            printf("Please !!!!!!!!.......Enter student class name choose : ");
            scanf("%d",&student[i].cls);
            printf("Enter student full name : ");
            fflush(stdin);
            gets(student[i].name);
            printf("Enter student father name : ");
            gets(student[i].fname);
            printf("Enter student mother name : ");
            gets(student[i].mName);
            printf("Enter student nick name : ");
            gets(student[i].nickName);
            printf("Enter student Date of Birth : ");
            scanf("%d",&student[i].dateOfBirth);
            printf("Enter parents personal phone number : ");
            scanf("%d",&student[i].phoneNumber);
            printf("Enter student user name : ");
            fflush(stdin);
            gets(student[i].userName);
            printf("Enter student ID number is : ");
            scanf("%d",&student[i].id);
            printf("\n Enter press option 1 for Male....\n press option 2 for Female....\n press option 3 for others.....\n");
            scanf("%d",&student[i].no);

            fwrite(&student[i],sizeof(student[i]),1,file);

        }
        fclose(file);
        printf("\n\nYour nickname is your User-name\n");
        printf("Now,Login with User-name and ID\n");
        printf("\nPress any key to continue......................\n");
        getch();
        system("CLS");
        login();

    }
}
login()
{
    FILE *file;
    file = fopen("student-Information.txt","r");
    if(file == NULL)
    {
        printf("Student-information file does not created\n");
    }
    else
    {
        char user_name[10];
        int Id;
        struct StudentInfo student;
        printf("User-name : ");
        fflush(stdin);
        gets(user_name);
        printf("Student ID : ");
        scanf("%d",&Id);
        while(fread(&student,sizeof(student),1,file))
        {
            if(strcmp(user_name,student.userName) == 0 && Id == student.id)
            {
                printf("\nSuccessfully Login\n");
                printf("Student name is : %s\n",student.name);
                printf("Student Class is : %d\n",student.cls);
                break;
            }
            else
            {
                printf("Please !!!!!.......... Enter your correct User-name and ID ");
                break;
            }
        }
        fclose(file);
    }
}
int main()
{
    int cho;
    printf("Press '1' for Register........... \nPress '2' for Login.........\n");
    scanf("%d",&cho);
    if(cho == 1)
    {
        system("CLS");
        registation();
    }
    else if(cho == 2)
    {
        system("CLS");
        login();
    }
    else
        printf("Incorrect option !!!!!!!!!!!.......Please correct option selected");


    return 0;
}
