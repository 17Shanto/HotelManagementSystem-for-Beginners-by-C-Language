#include<stdio.h>
#include<string.h>
FILE *User;
FILE *Hotel;
typedef struct infoUser
{
    char name[20];
    char gender[20];
    char age[20];
    char Phone[30];
    char id[30];
    char user[20];
    char pass[20];
} info;

typedef struct hotelInfo
{
    int floor;
    char status[20];
    char rent[20];
    int booked;

} hInfo;



void __Book(int x)
{

    hInfo Ex[10];
    Hotel = fopen("Hotel.txt","r");
    for( int i=0; i<6; ++i)
    {
        fscanf(Hotel,"\n%d\n%s\n%s\n%d",&Ex[i].floor,&Ex[i].rent,&Ex[i].status,&Ex[i].booked);
    }
    int roomRent = 0;
    for(int i=0; i<6; ++i)
    {
        if(x==Ex[i].floor)
        {

            printf("\n\nMake Advance 1000 tk plz: \nEnter Ammount: ");
            int tk;
            scanf("%d",&tk);
            printf("\n\n**Room Successfully Booked.**\n\n");
            roomRent=1;
            Ex[i].booked=1;
            break;
        }
    }
    if(roomRent==0)
    {
        printf("Plz Try Again.");
    }
    fclose(Hotel);
    Hotel = fopen("Hotel.txt","w");
    if(User == NULL)
    {
        printf("File isn't Created.");
    }
    else
    {
        for( int i=0; i<6; ++i)
        {
            fprintf(Hotel,"\n%d\n%s\n%s\n%d",Ex[i].floor,Ex[i].rent,Ex[i].status,Ex[i].booked);
        }
    }

}
void SignUp()
{
    User = fopen("UserInfo.txt","a");
    if(User == NULL)
    {
        printf("File isn't Created.");
    }
    else
    {
        info Ex[10];
        printf("Please Provide Your Information Below\n\n");
        printf("Name: ");
        scanf("%s",&Ex[0].name);
        printf("Gender: ");
        scanf("%s",&Ex[0].gender);
        printf("Age: ");
        scanf("%s",&Ex[0].age);
        printf("Phone Number: ");
        scanf("%s",&Ex[0].Phone);
        printf("National Id no: ");
        scanf("%s",&Ex[0].id);
        printf("User Name: ");
        scanf("%s",&Ex[0].user);
        printf("Password: ");
        scanf("%s",&Ex[0].pass);
        fprintf(User,"\n%s\n%s\n%s\n%s\n%s\n%s\n%s",Ex[0].name,Ex[0].gender,Ex[0].age,Ex[0].Phone,Ex[0].id,Ex[0].user,Ex[0].pass);

    }
    printf("**Signed Up Successfully**");
}

void Display()
{
    hInfo Ex[10];
    Hotel = fopen("Hotel.txt","r");
    for( int i=0; i<6; ++i)
    {
        fscanf(Hotel,"\n%d\n%s\n%s\n%d",&Ex[i].floor,&Ex[i].rent,&Ex[i].status,&Ex[i].booked);
    }
    printf("Our Available Room:\n\n");
    for(int i=0; i<6; ++i)
    {
        if(Ex[i].booked==0)
        {
            printf("Room No. %d\n",i+1);
            printf("Floor Number: %d\n",Ex[i].floor);
            printf("Room Type: %s\n",Ex[i].status);
            printf("Rent per Night: %s\n",Ex[i].rent);
            printf("Current Status: ");
            printf("Available\n");
            printf("\n");
        }


    }
    printf("\n\n");
    printf("Do you want to Book?\n ");
    char ok [10];
    scanf("%s",&ok);
    if(strcmp(ok,"yes")==0)
    {
        printf("\nEnter a room number: ");
        int no;
        scanf("%d",&no);
        __Book(no);

    }
    else
        Display();
}




void LogIn()
{
    char UserName[25];
    char Password[20];
    info Ex[105];
    User =  fopen("UserInfo.txt","r");
    for(int i=0; i<100; ++i)
    {
        fscanf(User,"\n%s\n%s\n%s\n%s\n%s\n%s\n%s",&Ex[i].name,&Ex[i].gender,&Ex[i].age,&Ex[i].Phone,&Ex[i].id,&Ex[i].user,&Ex[i].pass);
    }
    printf("\n\nUsername: ");
    scanf("%s",&UserName);
    printf("Password: ");
    scanf("%s",&Password);

    int yes = 0;
    for(int i=0; i<100; ++i)
    {
        if(strcmp(UserName,Ex[i].user)==0 && strcmp(Password,Ex[i].pass)==0)
        {
            printf("Welcom To our Hotel\n");
            printf("===================\n\n");
            Display();


            yes = 1;
        }
    }
    if(yes==0)
        printf("Username or Password doesn't Match.\nPlz Try Again***");

    fclose(User);
}




void admin()
{
    hInfo Ex[10];
    Hotel = fopen("Hotel.txt","r");
    if(Hotel==NULL)
    {

    }
    else
    {
        for( int i=0; i<6; ++i)
        {
            fscanf(Hotel,"\n%d\n%s\n%s\n%d",&Ex[i].floor,&Ex[i].rent,&Ex[i].status,&Ex[i].booked);
        }
    }

    fclose(Hotel);
    char username[30];
    char pass[30];
    printf("**Admin Pannel**\n\n");
    printf("UserName: ");
    scanf("%s",&username);
    printf("Password: ");
    scanf("%s",&pass);

    int select = 0;

    if(strcmp(username,"Admin")==0 && strcmp(pass,"12345")==0)
    {
        printf("\n\nTo Update Room Status\n\nEnter the Room No:");
        int room;
        fflush(stdin);
        scanf("%d",&room);
        fflush(stdin);

        for(int i=0; i<6; ++i)
        {
            if(room==Ex[i].floor)
            {
                Ex[i].booked=0;
                select=1;
                break;
            }
        }

        Hotel = fopen("Hotel.txt","w");
        for( int i=0; i<6; ++i)
        {
            fprintf(Hotel,"\n%d\n%s\n%s\n%d",Ex[i].floor,Ex[i].rent,Ex[i].status,Ex[i].booked);
        }

        fclose(Hotel);


    }
    else
    {
        printf("Username or Password Doesn't match");
        admin();
    }

    if(select==1)
    {
        printf("\n\n**Update Successfully\n\n**");
        int op;
        printf("Do you want to Display Current status?\n\n1.Yes\n2.No");
        printf("\nEnter any option: ");
        scanf("%d",&op);
        if(op==1)
        {
            Display();
        }
        else
            return 0;
    }
    else
        printf("Unsuccessfull");

}
int main()
{

    printf("Welcome To Hotel 8 no. Gate\n");
    printf("======================\n\n");
    printf("Are you...\n");
    printf("1.Admin?\n2.Customer\n\nEnter an Option: ");
    int op;

    scanf("%d",&op);
    printf("\n\n");
    int select;
    switch(op)
    {
    case 1:
        admin();
        break;
    case 2:

        printf("Do you want to...\n");
        printf("1.SignUp?\n2.LogIn?\n\nEnter an Option: ");
        scanf("%d",&select);
        fflush(stdin);
        if(select==1)
            SignUp();
        else
            LogIn();
        break;
    default:
        printf("WrongOption");
        break;

    }


    return 0;
}
