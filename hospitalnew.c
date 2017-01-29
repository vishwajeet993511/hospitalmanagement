#include<stdio.h>
#include<stdlib.h>                            //including headers
#include<string.h>

typedef struct Address{
         int hnumber;
         char street[30];                      //structure for address
         char city[20];
         char state[20];
         char country[10];

} address;


typedef struct Hospital{
         char name[30];
         address addhos;
         char branch[20];
         char department[30];
         char facilities[50];


}hospital;

typedef struct Payment{
         int charge;
         int tax;
         int totalcharge;
         int paid;
         int due;

}payment;

typedef struct Patient{
         char name[30];
         char uniqueid[10];
         char bloodgroup[20];
         int age;
         char gender[10];
         char disease[50];
         address addpat;
         char history[100];
         char docname[30];
         char medicine[50];
         char contactno[10];
         payment paypat;

} patient;

typedef struct Employee{
         char name[30];
         int age;
         char bloodgroup[20];
         char gender[10];
         address addemp;
         char uniqueid[10];
         char contactno[10];
         double salary;
         char job[50];
}employee;

typedef struct Doctor{
        char name[30];
        char uniqueid[10];
        int age;
        char gender[10];
        address adddoc;
        char contactno[10];
        char specialization[30];
        char degree[30];


} doctor;



void fdoctor();
void fpatient();
void femployee();
void patientrecord();

int main()
{
         int options;

         printf("     HOSPITAL MANAGEMENT SYSTEM   \n");
         //printf("\nmade by vishwajeet shukla \n");
         printf("\npick the right option among 1 ,2 and 3\n");
         printf(" 1 .  patient\n");
         printf(" 2 .  employee\n");
         printf(" 3 .  doctor\n");

         scanf("%d",&options);

        switch(options)
        {
            case 1: fpatient();
                    break;

            case 2: femployee();
                    break;

            case 3: fdoctor();
                    break;

            default:  printf("invalid choice\n");

        }

		return 0;
}


void fpatient()
{
    printf("\nPATIENT SECTION\n");
    FILE *fpat,*ftemp;
    int choice,count1=0,count2=0;
    patient p;
    char ch;
    int size= sizeof(p);
    char id[10],pname[30],modid[10],modpname[30];

    fpat = fopen("patnew.dat","rb+");      //opening file into binary type to read and write mode
    if(fpat == NULL)
    {
        fpat = fopen("patnew.dat","wb+");
        if(fpat == NULL)
        {
        printf("sorry some error occured while opening the file\n");
        exit(1);
        }
    }
    printf("enter the choice you want to go to\n");
    printf("1.  NEW REGISTRATION\n");
    printf("2.  MODIFY ENTRY\n");
    printf("3.  DELETE ENTRY\n");
   // printf("4.  PRINT THE RECORDS\n");
    printf("4.  log in to your id\n");

    scanf("%d",&choice);

    switch(choice)
    {
        case 1:                                      //case 1 is for entering new records
                 fseek(fpat,0,SEEK_END);

                 fflush(stdin);
                 printf("enter name\n");
                 scanf("%s",&p.name);
                 //scanf("%s",&p.name);

                 fflush(stdin);
                 printf("enter unique id\n");
                 scanf("%s",&p.uniqueid);
                 //scanf("%s",&p.uniqueid);

                 fflush(stdin);
                 printf("enter the disease\n");
                 scanf("%s",&p.disease);

                 printf("enter the address\n");
                 printf("enter street\n");
                 scanf("%s",&p.addpat.street);

                 printf("enter city\n");
                 scanf("%s",&p.addpat.city);

                 printf("enter the state\n");
                 scanf("%s",&p.addpat.state);

                 printf("enter your age \n");
                 scanf("%d",&p.age);


                 printf("enter gender \n");
                 scanf("%s",&p.gender);

                 fflush(stdin);
                 printf("enter blood group\n");
                 scanf("%s",&p.bloodgroup);

                 printf("enter contact no\n");
                 scanf("%s",&p.contactno);

                 printf("enter prescribed doctor name\n");
                 scanf("%s",&p.docname);

                 printf("enter the names of the medicines you have been alloted\n");
                 scanf("%s",&p.medicine);

                 printf("enter any earlier diseases or problems\n");
                 scanf("%s",&p.history);


                 p.paypat.paid = 0;
                 p.paypat.due=0;
                 p.paypat.charge=0;
                 p.paypat.tax=0;
                 p.paypat.totalcharge=0;




                 fwrite(&p,size,1,fpat);
                 fflush(stdin);
                 /*printf("entry saved . do you want to add another entry?y/n\n");
                 scanf("%s",&ch);
                 if(ch== 'y' || ch =='Y')
                    fpatient();  */

        break;



        case 2:
            fflush(stdin);
            printf("enter the name of the patient whose entry is to be modified\n");
            scanf("%s",&modpname);
            rewind(fpat);
            while( fread(&p,size,1,fpat)==1 )
            {
                if(strcmp(p.name,modpname)==0)   //modify else
                {
                    count1 =1;
                    printf("enter unique id\n");
                    scanf("%s",&modid);
                    if(strcmp(p.uniqueid,modid)==0)
                    {
                        fflush(stdin);

                         printf("enter new name\n");
                         scanf("%s",&p.name);

                         printf("enter the new address\n");
                         printf("enter new street\n");
                         scanf("%s",&p.addpat.street);

                         printf("enter new city\n");
                         scanf("%s",&p.addpat.city);

                         printf("enter the new state\n");
                         scanf("%s",&p.addpat.state);

                         printf("enter new contact no\n");
                         scanf("%s",&p.contactno);

                         printf("enter other doctrs prescribed\n");
                         scanf("%s",&p.docname);

                        fseek(fpat,-size,SEEK_CUR);
                        fwrite(&p,size,1,fpat);
                        break;
                    }
                    else
                    {
                        printf("id entered is wrong\n");
                        break;
                    }
                }
                else
                    continue;
                 //modify
                fflush(stdin);
            }
            if(count1 ==0) printf("name does not exist in the list\n");

        break;



        case 3:
            fflush(stdin);
            printf("enter unique id of the patient to be deleted\n");
            scanf("%s",&id);
             ftemp =fopen("temp.dat","wb+");
             rewind(fpat);
             while( fread(&p,size,1,fpat)==1 )
             {

                    if(strcmp(p.uniqueid,id)!=0)
                    {

                        fwrite(&p,size,1,ftemp);

                    }
                    else
                    {
                        printf("record deleted \n");

                    }


             }
            fclose(fpat);
            fclose(ftemp);
            remove("patnew.dat");
            rename("temp.dat","patnew.dat");
            fpat=fopen("patnew.dat","rb+");


        break;



       /* case 4:

               while( fread(&p,size,1,fpat)==1 )
               {
                   printf("enter your unique id\n");
                   puts(p.uniqueid);
                   printf("\nname of the patient::");
                   puts(p.name);
                   printf("\ndisease of the person::");
                   puts(p.disease);
                   printf("\nblood group of the patient is::");
                   puts(p.bloodgroup);
                   printf("address of the patient\n"); //hnumber not scnned
                   puts(p.addpat.street);

               }

        break;   */


        case 4 :                                    //case 5 is for login into the system
                printf("enter your name\n");
                fflush(stdin);
                scanf("%s",&pname);
                rewind(fpat);
                while( fread(&p,size,1,fpat)==1 )
                {
                    if( strcmp(p.name,pname)==0 )
                    {
                        count2 =1;
                        printf("enter the unique id\n");
                        scanf("%s",&id);
                        if(strcmp(p.uniqueid,id)==0 )
                        {
                            printf("       ****welocome to hospital managemt system,mr./ms. %s ****",p.name);
                            printf("\nyour unique id %s\n",p.uniqueid);
                            printf("bloodgroup  %s   \n",p.bloodgroup);
                            printf("your age is %d\n",p.age);
                            printf("your disease is %s\n",p.disease);
                            //puts(p.disease);
                            printf("your concerned doctor is %s\n",p.docname);
                            printf("you have been prescribed following medicines\n");
                            printf("%s\n",p.medicine);

                            printf("total charge of service = %d\n",p.paypat.charge);
                            printf("total tax = %d",p.paypat.tax);

						    printf("\namount paid = %d  and due amount = %d\n",p.paypat.paid,p.paypat.due);


                            break;
                        }
                        else
                        {

                            printf("unique id given is wrong\n");
                        }

                    }
                        else {
                                continue;
                        }


                }
                  if(count2==0) printf("name does not exist in the list\n");


        break;

        default : printf("entered choice does not match given choices\n");

    }
}

void femployee()                                   //FUNCTION FOR HANDLING EMPLOYEES
{
    printf("     EMPLOYEE SECTION \n");
    FILE *femp,*ftempemp;
    int choice,count1=0,count2=0,count=0;
    employee e;
    char ch;
    int a,b,c,d;
    int size= sizeof(e);
    char id[10],ename[30],modid[10],modename[30],modid2[10],modpname[30];

    femp = fopen("emp.dat","rb+");      //opening file into binary type to read and write mode
    if(femp == NULL)
    {
        femp = fopen("emp.dat","wb+");
        if(femp == NULL)
        {
        printf("sorry some error occured while opening the file\n");
        exit(1);
        }
    }
    printf("enter the choice you want to go to\n");
    printf("1.  NEW REGISTRATION\n");
    printf("2.  MODIFY ENTRY\n");
    printf("3.  DELETE ENTRY\n");
    printf("4.  log in to your id\n");
    printf("5.  strictly related to finance section\n");

    scanf("%d",&choice);

    switch(choice)
    {
        case 1:                                      //case 1 is for entering new records
                 fseek(femp,0,SEEK_END);
                 fflush(stdin);

                 printf("enter name\n");
                 scanf("%s",&e.name);

                 printf("enter unique id\n");
                 scanf("%s",&e.uniqueid);

                 fflush(stdin);
                 printf("enter the address\n");
                 printf("enter street\n");
                 scanf("%s",&e.addemp.street);

                 printf("enter city\n");
                 scanf("%s",&e.addemp.city);

                 printf("enter the state\n");
                 scanf("%s",&e.addemp.state);

                 fflush(stdin);
                 printf("enter your age \n");
                 scanf("%d",&e.age);

                 fflush(stdin);
                 printf("enter gender \n");
                 scanf("%s",&e.gender);

                 fflush(stdin);
                 printf("enter blood group  \n");
                 scanf("%s",&e.bloodgroup);

                 printf("enter contact no\n");
                 scanf("%s",&e.contactno);

                 printf("enter your job eg:- nurse,financial,staff etc.\n");
                 scanf("%s",&e.job);

                 fflush(stdin);
                 printf("enter your salary\n");
                 scanf("%f",&e.salary);

                 fflush(stdin);
                 fwrite(&e,size,1,femp);
                 fflush(stdin);
                 /*printf("entry saved . do you want to add another entry?y/n\n");
                 scanf("%s",&ch);
                 if(ch== 'y' || ch =='Y')
                    fpatient();  */

        break;



        case 2:
            fflush(stdin);
            printf("enter the name of the employee whose entry is to be modified\n");
            scanf("%s",&modename);
            rewind(femp);
            while( fread(&e,size,1,femp)==1 )
            {
                if(strcmp(e.name,modename)==0)   //modify else
                {
                    count1 =1;
                    printf("enter unique id\n");
                    scanf("%s",&modid);
                    if(strcmp(e.uniqueid,modid)==0)
                    {
                        fflush(stdin);
                        printf("enter the new name of the employee\n");
                        scanf("%s",&e.name);
                        printf("enter the new blood group of the employee \n");
                        scanf("%s",&e.bloodgroup);

                        fseek(femp,-size,SEEK_CUR);
                        fwrite(&e,size,1,femp);
                        break;
                    }
                    else
                    {
                        printf("id entered is wrong\n");
                        break;
                    }
                }
                else
                    continue;
                 //modify
                fflush(stdin);
            }
            if(count1 ==0) printf("name does not exist in the list\n");

        break;



        case 3:
            fflush(stdin);
            printf("enter unique id of the patient to be deleted\n");
            scanf("%s",&id);
             ftempemp =fopen("temp.dat","wb+");
             rewind(femp);
             while( fread(&e,size,1,femp)==1 )
             {

                    if(strcmp(e.uniqueid,id)!=0)
                    {

                        fwrite(&e,size,1,ftempemp);

                    }
                    else
                    {
                        printf("record deleted \n");

                    }


             }
            fclose(femp);
            fclose(ftempemp);
            remove("emp.dat");
            rename("temp.dat","emp.dat");
            femp=fopen("emp.dat","rb+");


        break;


        case 4 :                                    //case 5 is for login into the system
                printf("enter your name\n");
                fflush(stdin);
                scanf("%s",&ename);
                rewind(femp);
                while( fread(&e,size,1,femp)==1 )
                {
                    if( strcmp(e.name,ename)==0 )
                    {
                        count2 =1;
                        printf("enter the unique id\n");
                        scanf("%s",&id);
                        if(strcmp(e.uniqueid,id)==0 )
                        {
                            printf("welcome to hospital management system mr./ms. %s\n",e.name);
                            printf("your job specification is %s\n",e.job);
                            printf("your age is %d  ",e.age);
                            printf("\nyour blood group is %s ",e.bloodgroup);
                            break;
                        }
                        else
                        {

                            printf("unique id given is wrong\n");
                        }

                    }
                        else {
                                continue;
                        }


                }
                  if(count2==0) printf("name does not exist in the list\n");


        break;


          case 5:     printf("this section is only authorised to finance department\n");
                      printf("login to continue\n");
                        FILE *fpat;
                        patient p;
                        int size2 = sizeof(p);
						 fpat = fopen("patnew.dat","rb+");      //opening file into binary type to read and write mode
								   if(fpat == NULL)
									{
										fpat = fopen("patnew.dat","wb+");
										if(fpat == NULL)
										{
										printf("sorry some error occured while opening the file\n");
										exit(1);
										}
									}


                       printf("enterlogin details to continue login\n");
				      scanf("%s",&modename);
				      rewind(femp);
				      while( fread(&e,size,1,femp)==1 )
				        {
				            printf("%s",modename);
				            printf("%s",e.name);

				        if(strcmp(e.name,modename)==0)   //modify else
				        {
				            count =1;
				            printf("enter employee unique id\n");
				            scanf("%s",&modid);
				            if(strcmp(e.uniqueid,modid)==0)
				            {
					        printf("enter the name of the patient whose entry is to be modified\n");
							   scanf("%s",&modpname);
							   rewind(fpat);
							   while( fread(&p,size2,1,fpat)==1 )
							     {
								  if(strcmp(p.name,modpname)==0)   //modify else
								     {
								    count1 =1;
								    printf("enter unique id of patient \n");
								    scanf("%s",&modid2);
								     if(strcmp(p.uniqueid,modid2)==0)
								       {
								        fflush(stdin);

								         printf("enter the new payment records\n");
								         printf(" enter total charge \n");
								         scanf("%d",&p.paypat.charge);
								         printf("enter service tax\n");
								         scanf("%d",&p.paypat.tax);
								         p.paypat.totalcharge = p.paypat.charge  + p.paypat.tax;
								         printf("enter the final amount paid and final due\n");
								         scanf("%d %d",&p.paypat.paid,&p.paypat.due);


								        fseek(fpat,-size2,SEEK_CUR);
								        fwrite(&p,size2,1,fpat);
								        break;
								    }
								    else
								    {
								        printf("id entered is wrong\n");
								        break;
								    }
								}
								else
								    continue;
								 //modify
								fflush(stdin);
							}
							if(count1 ==0) printf("name does not exist in the list\n");



												break;
											}
											else
											{
												printf("id entered is wrong\n");
												break;
											}
										}
										else
											continue;
										 //modify
										fflush(stdin);
									}
									if(count ==0) printf("name does not exist in the list\n");

				      break;
        	default : printf("entered choice does not match given choices\n");

    }

}

void fdoctor()
{
    printf("    DOCTOR SECTION\n");

    FILE *fdoc,*ftempdoc,*fpat;
    int choice,count1=0,count2=0;
    doctor d;
    patient p;
    char ch;
    int size= sizeof(d);
    char id[10],dname[30],modid[10],moddname[30];

    fdoc = fopen("doc.dat","rb+");      //opening file into binary type to read and write mode
    if(fdoc == NULL)
    {
        fdoc = fopen("doc.dat","wb+");
        if(fdoc == NULL)
        {
        printf("sorry some error occured while opening the file\n");
        exit(1);
        }
    }
    printf("enter the choice you want to go to\n");
    printf("1.  NEW REGISTRATION\n");
    printf("2.  MODIFY ENTRY\n");
    printf("3.  DELETE ENTRY\n");
    printf("4.  log in to your id\n");

    scanf("%d",&choice);

    switch(choice)
    {
        case 1:                                      //case 1 is for entering new records
                 fseek(fdoc,0,SEEK_END);
                 fflush(stdin);

                 printf("enter name\n");
                 scanf("%s",&d.name);

                 printf("enter unique id\n");
                 scanf("%s",&d.uniqueid);

                 printf("enter the address\n");
                 printf("enter street\n");
                 scanf("%s",&d.adddoc.street);

                 printf("enter city\n");
                 scanf("%s",&d.adddoc.city);

                 printf("enter the state\n");
                 scanf("%s",&d.adddoc.state);

                 printf("enter your age \n");
                 scanf("%d",&d.age);

                 fflush(stdin);
                 printf("enter gender \n");
                 scanf("%s",&d.gender);

                 fflush(stdin);
                 printf("enter contact no\n");
                 scanf("%s",&d.contactno);

                 printf("enter specialisation\n");
                 scanf("%s",&d.specialization);

                 printf("enter degree\n");
                 scanf("%s",&d.degree);

                 fwrite(&d,size,1,fdoc);
                 fflush(stdin);
                 /*printf("entry saved . do you want to add another entry?y/n\n");
                 scanf("%s",&ch);
                 if(ch== 'y' || ch =='Y')
                    fpatient();  */

        break;



        case 2:
            fflush(stdin);
            printf("enter the name of the doctor whose entry is to be modified\n");
            scanf("%s",&moddname);
            rewind(fdoc);
            while( fread(&d,size,1,fdoc)==1 )
            {
                if(strcmp(d.name,moddname)==0)   //modify else
                {
                    count1 =1;
                    printf("enter unique id\n");
                    scanf("%s",&modid);
                    if(strcmp(d.uniqueid,modid)==0)
                    {
                        fflush(stdin);
                        printf("enter the new name of the patient\n");
                        scanf("%s",&d.name);

                        fseek(fdoc,-size,SEEK_CUR);
                        fwrite(&d,size,1,fdoc);
                        break;
                    }
                    else
                    {
                        printf("id entered is wrong\n");
                        break;
                    }
                }
                else
                    continue;
                 //modify
                fflush(stdin);
            }
            if(count1 ==0) printf("name does not exist in the list\n");

        break;



        case 3:
            fflush(stdin);
            printf("enter unique id of the doctor to be deleted\n");
            scanf("%s",&id);
             ftempdoc =fopen("temp.dat","wb+");
             rewind(fdoc);
             while( fread(&d,size,1,fdoc)==1 )
             {

                    if(strcmp(d.uniqueid,id)!=0)
                    {

                        fwrite(&d,size,1,ftempdoc);

                    }
                    else
                    {
                        printf("record deleted \n");

                    }


             }
            fclose(fdoc);
            fclose(ftempdoc);
            remove("doc.dat");
            rename("temp.dat","doc.dat");
            fdoc=fopen("doc.dat","rb+");


        break;


        case 4 :                                    //case 5 is for login into the system
                printf("enter your name\n");
                fflush(stdin);
                scanf("%s",&dname);
                rewind(fdoc);
                while( fread(&d,size,1,fdoc)==1 )
                {
                    if( strcmp(d.name,dname)==0 )
                    {
                        count2 =1;
                        printf("enter the unique id\n");
                        scanf("%s",&id);
                        if(strcmp(d.uniqueid,id)==0 )
                        {
                            printf("welcome to hospital management system dr. %s\n",d.name);
                            printf("\nyour specialisation is %s\n",d.specialization);
                            printf("your age is %d\n",d.age);
                            printf("your degree is %s\n",d.degree);

                            printf("\n\ndo you want to print the patients information..(y/n)\n");
                            scanf("%s",&ch);
                            if(ch=='y' || ch=='Y')
                                patientrecord();
                            break;
                        }
                        else
                        {

                            printf("unique id given is wrong\n");
                        }

                    }
                        else {
                                continue;
                        }


                }
                  if(count2==0) printf("name does not exist in the list\n");


        break;

        default : printf("entered choice does not match given choices\n");

    }
}


void patientrecord()
{
     FILE *fpat;
     patient p;
     int size = sizeof(p);
     fpat = fopen("patnew.dat","rb+");      //opening file into binary type to read and write mode
               if(fpat == NULL)
                {
                    fpat = fopen("patnew.dat","wb+");
                    if(fpat == NULL)
                    {
                    printf("sorry some error occured while opening the file\n");
                    exit(1);
                    }
                }
               while( fread(&p,size,1,fpat)==1 )
               {
                   printf("unique id\n");
                   puts(p.uniqueid);
                   printf("\nname of the patient::");
                   puts(p.name);
                   printf("\ndisease of the person::");
                   puts(p.disease);
                   printf("\nblood group of the patient is::");
                   puts(p.bloodgroup);
                   printf("medical history of the patient\n"); //hnumber not scnned
                   puts(p.history);

               }
}

