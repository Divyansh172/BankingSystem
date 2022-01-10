#include <stdio.h>
typedef struct Employee{
    int EmpID;
    char name[20];
    int sal;
    }Employee;


void create(){
    Employee *s;
    FILE *fp;
    int n,i,j;
    printf("Number of Employee : ");
    scanf("%d",&n);

    s = (Employee*)calloc(n, sizeof(Employee));
    fp = fopen("GitHub.txt","w");

    for(i=0;i<n;i++)
    {

        printf("Enter Employee ID : ");
        scanf("%d",&s[i]);
        fflush(stdin);
        printf("Enter Employee Name : ");
        scanf("%s",s[i].name);
        for(j=0;j<1;j++)
        {
            printf("Enter Salary : ",j+1);
            scanf("%d",&s[i].sal);

        }

        fwrite(&s[i],sizeof(Employee),1,fp);
    }
    fclose(fp);
    }
void display(){
    int j;
    Employee s1;
    FILE *fp;
    fp = fopen("GitHub.txt","r");
    while(fread(&s1,sizeof(Employee),1,fp))
    {
        printf("\n%-5d%-20s",s1.EmpID,s1.name);
        for(j=0;j<1;j++)
        {
            printf("%4d",s1.sal);
        }

    }
    fclose(fp);

    }
void append(){
 Employee *s;
    FILE *fp;
    int n,i,j;
    printf("Number of Employee : ");
    scanf("%d",&n);

    s = (Employee*)calloc(n, sizeof(Employee));
    fp = fopen("GitHub.txt","a");

    for(i=0;i<n;i++)
    {

        printf("Enter Employee ID : ");
        scanf("%d",&s[i]);
        fflush(stdin);
        printf("Enter Employee Name : ");
        scanf("%s",s[i].name);
        for(j=0;j<1;j++)
        {
            printf("Enter Salary : ",j+1);
            scanf("%d",&s[i].sal);

        }

        fwrite(&s[i],sizeof(Employee),1,fp);
    }
    fclose(fp);
    }
int main(){
    int ch;
    do{
        printf("\n1.CREATE");
        printf("\n2.DISPLAY");
        printf("\n3.APPEND");
        printf("\n4.EXIT");

        printf("\nEnter Your Choice :");
        scanf("%d",&ch);

        switch(ch){
          case 1:
            create();
          break;
          case 2:
            display();
          break;
          case 3:
            append();
          break;
          }
    }while(ch!=0);

return 0;}

