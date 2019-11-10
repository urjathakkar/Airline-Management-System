#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<cstdlib>

int rand();

using namespace std;

class payment
{
    double card;
    int cvv;
    char user[50];
public:
    void enter(char *);
    int retcvv(){return cvv;}
    char * retu(){return user;}
}P;

void payment::enter(char *q)
{
    strcpy(user,q);
    cout<<"\n Enter the card no : ";
    cin>>card;
    cout<<"\n Enter the cvv : ";
    cin>>cvv;
}

class admin
{
    char a_name[50];
    char a_password[50];
public:
    char* ret_au()
    {
        return a_name;
    }
    char* ret_p()
    {
        return a_password;
    }
    void add_admin();
    void display_admin();

}AD;

void admin::add_admin()
{
    char ad[50];
    cout<<"Enter admin name: "<<endl;
    cin>>ad;

    ifstream au;
    au.open("admin.dat",ios::binary);
    while(au.read((char *)&AD,sizeof(AD)))
    {
        if(!strcmp(ad,AD.ret_au()))
        {
            cout<<"\nEnter another admin user: ";
            cin>>ad;
            au.seekg(0,ios::beg);
        }
    }
    au.close();
    strcpy(a_name,ad);
    cout<<"\nEnter password: ";
    cin>>a_password;
}

class tno
{
    int no;
public:
    tno(int x=1){no=x;}
    int ret()
    {
        return no;
    }
    void up()
    {
        ++no;
    }
}N;

class user
{
    char user_id[50];
    //char* user_id;
    char password[16];
    char email[20];
    double phoneNo;
    int age;
    char sex;
public:
    void add_user();
    void delete_user();
    void display();
    char* retuser_id();
    char* retpass();

}U;


void user::display()
{
    cout<<endl;
    cout<<"\nUser_id is  : "<<user_id;
    cout<<"\nEmail is    : "<<email;
    cout<<"\nPhone no is : "<<phoneNo;
    cout<<"\nAge is      : "<<age;
    cout<<"\nSex is      : "<<sex;
    cout<<endl;

}

char* user :: retpass()
{
    return password;
}

char* user :: retuser_id()
{
    return user_id;
}

void user :: add_user()
{
    char us[50];
    //char *u;
    int length;
    cout<<"\nEnter the user_id : ";
    cin>>us;
    //length=strlen(us);
    //us=new char[length+1];
    //cout<<"len: "<<sizeof(us);
    ifstream fp;
    fp.open("user.dat",ios::binary);
    while(fp.read((char*)&U,sizeof(U)))
    {
        if(!strcmp(us,U.retuser_id()))
        {
            cout<<"\nEnter another id : ";
            cin>>us;
            //length=strlen(us);
            //us=new char[length+1];
            fp.seekg(0,ios::beg); //to start checking from begining again
        }
    }
    fp.close();

    ofstream f;
    f.open("payment.dat",ios::binary|ios::app);
    P.enter(us);
    f.write((char*)&P,sizeof(P));
    f.close();

    strcpy(user_id, us);
    cout<<"\nEnter the password : ";
    cin>>password;
    cout<<"\nEnter email id : ";
    cin>>email;
    cout<<"\nEnter phone no : ";
    cin>>phoneNo;
    cout<<"\nEnter age : ";
    cin>>age;
    cout<<"\nEnter sex : ";
    cin>>sex;

}


void user :: delete_user()
{
    char u[50];
    char p[16];
    cout<<"\nEnter the user id to delete : ";
    cin>>u;
    ofstream fuw;
    fuw.open("temp.dat",ios::app|ios::binary);
    ifstream fu;
    fu.open("user.dat",ios::binary);
    while(fu.read((char*)&U,sizeof(U)))
        if(!strcmp(u,U.retuser_id()))
        {
            /*for(int i=0;i<5;i++)
             {
             cout<<"\nAttempts remaining : "<<i;
             cout<<"\nEnter password : ";
             cin>>p;
             if(!strcmp(p,U.retpass()))
             break;
             }*/

            cout<<"\n User deleted : ";


        }
        else
            fuw.write((char*)&U,sizeof(U));

    fuw.close();
    fu.close();
    remove("user.dat");
    rename("temp.dat","user.dat");

}

class airline
{
    char flno[10];
    char airline_name[15];
    int capacity;
    char origin[20];
    char dest[20];
    char date[10];
    char time[10];
    int fare;
public:
    void add_airline();
    void airline_output();
    char* retflno()
    {
        return flno;
    }
    int retCapacity()
    {
        return capacity;
    }
    char* retOrigin()
    {
        return origin;
    }
    char* retDestination()
    {
        return dest;
    }
    int retfare()
    {

        return fare;
    }
    void updateCapacity(int);
    void update();
    void modify();
    friend void book();
}A;

void airline :: updateCapacity(int x)
{
    capacity = capacity - x;
}

void airline :: update()
{
    ++capacity;
}

void airline::add_airline()
{

    cout<<"\nEnter flight ID : ";
    cin>>flno;
    cout<<"\nEnter airline name : ";
    cin>>airline_name;
    cout<<"\nEnter capacity : ";
    cin>>capacity;
    cout<<"\nEnter origin : ";
    cin>>origin;
    cout<<"\nEnter destination : ";
    cin>>dest;
    cout<<"\nEnter date : ";
    cin>>date;
    cout<<"\nEnter time : ";
    cin>>time;
    cout<<"\nEnter fare : ";
    cin>>fare;
}

void airline::airline_output()
{
    cout<<"\n"<<airline_name;
    cout<<"\nFlightid    : "<<flno;
    cout<<"\nOrigin      : "<<origin;
    cout<<"\nDestination : "<<dest;
    cout<<"\nDate        : "<<date;
    cout<<"\nTime        : "<<time;
    cout<<"\nSeats left  : "<<capacity;
    cout<<"\nFare        : "<<fare;
}

void airline::modify()
{
    cout<<"\n\t\t\t1.To change the origin ";
    cout<<"\n\t\t\t2.To change the destination ";
    cout<<"\n\t\t\t3.To change the date ";
    cout<<"\n\t\t\t4.To change the time ";
    cout<<"\n\t\t\t5.To change the fare ";
    int n;
    cout<<"\n\t\t\tEnter your choice : ";
    cin>>n;
    char temp[20];
    int temp1;
    switch(n)
    {
        case 1: cout<<"\n\t\t\tEnter the orgin : ";
            cin>>origin;
            strcpy(origin,temp);
            break;

        case 2: cout<<"\n\t\t\tEnter the destination : ";
            cin>>temp;
            strcpy(dest,temp);
            break;

        case 3: cout<<"\n\t\t\tEnter the date : ";
            cin>>temp;
            strcpy(date,temp);
            break;

        case 4: cout<<"\n\t\t\tEnter the time : ";
            cin>>temp;
            strcpy(time,temp);
            break;
        case 5: cout<<"\n\t\t\tEnter the fare : ";
            cin>>temp1;
            fare=temp1;
    }

}

void modifyflights()
{
    cout<<"\n\t\t\t Enter the flight no to be modified : ";
    char fl[10];
    cin>>fl;
    ifstream file;
    file.open("airline.dat",ios::binary);
    ofstream fout;
    fout.open("temp.dat",ios::binary|ios::app);
    while(file.read((char*)&A,sizeof(A)))
        if(!strcmp(A.retflno(),fl))
        {
            A.modify();
            fout.write((char*)&A,sizeof(A));
            cout<<"\n\t\t\tSuccessfully modified the flight : "<<fl;
        }
        else
            fout.write((char*)&A,sizeof(A));

    file.close();
    fout.close();
    remove("airline.dat");
    rename("temp.dat","airline.dat");

}

class ticket
{
    int count;
    int TNo;
    char FlNo[10];
    char origin[20];
    char destination[20];
    char name[50];
    char user[50];
    int age;
    char sex[1];
public:

    ticket()
    {
        count=1;
    }

    void booking(char *,int);
    void ticket_display();

    char* retFlNo()
    {
        return FlNo;
    }

    void ticket_display(char *);

    char* retuser()
    {
        return user;
    }

    int retno()
    {
        return TNo;
    }

    //void ticket :: ticket_displaybyuser(char *);
    friend void book();
}T;

void deleteAirline()
{
    cout<<"\n\t\t\t Enter the flight no to be deleted : ";
    char fl[10];
    cin>>fl;
    ifstream file;
    file.open("airline.dat",ios::binary);
    ofstream fout;
    fout.open("temp.dat",ios::binary|ios::app);
    while(file.read((char*)&A,sizeof(A)))
        if(!strcmp(A.retflno(),fl))
        {
            cout<<"\n\t\t\tSuccessfully deleted the flight - "<<fl;
        }
        else
            fout.write((char*)&A,sizeof(A));

    int count=0;

    ifstream ti;
    ti.open("ticket.dat",ios::binary);

    ofstream it;
    it.open("temp2.dat",ios::binary|ios::app);
    while(ti.read((char*)&T,sizeof(T)))
        if(!strcmp(fl,T.retFlNo()))
        {
            count++;
        }
        else
            it.write((char*)&T,sizeof(T));

    if(count!=0)
        cout<<"\n\t\t\t Tickets deleted "<<count;

    ti.close();
    it.close();

    remove("ticket.dat");
    rename("temp2.dat","ticket.dat");


    file.close();
    fout.close();
    remove("airline.dat");
    rename("temp.dat","airline.dat");

}




void ticket::booking(char* x,int y)
{

    strcpy(FlNo,x);
    cout<<"\nName : ";
    cin>>name;
    cout<<"\nAge  : ";
    cin>>age;
    cout<<"\nSex  : ";
    cin>>sex;
    strcpy(destination,A.retDestination());
    strcpy(origin,A.retOrigin());
    strcpy(user,U.retuser_id());
    TNo=y;

}

void ticket :: ticket_display()
{
    cout<<endl;
    cout<<"\nFlight Number  : "<<FlNo;
    cout<<"\nOrigin         : "<<origin;
    cout<<"\nDestination    : "<<destination;
    cout<<"\nName           : "<<name;
    cout<<"\nAge            : "<<age;
    cout<<"\nSex            : "<<sex;
    cout<<"\nTno is         : "<<TNo;
    cout<<"\nBooked by      : "<<user;
    cout<<endl;

}

void ticket :: ticket_display(char *x)
{
    ifstream fa;
    fa.open("ticket.dat",ios::binary);
    while(fa.read((char*)&T,sizeof(T)))
        if(!strcmp(T.retFlNo(),x))
        {
            T.ticket_display();
        }
}

void ticket_displaybyuser()
{
    ifstream fp;
    fp.open("ticket.dat",ios::binary);
    //cout<<"check1";
    while(fp.read((char*)&T,sizeof(T)))
    {
        //cout<<"check inside while"<<endl;
        if(strcmp(T.retuser(),U.retuser_id())==0)
        {
            T.ticket_display();
            //cout<<"check";
        }
    }

    fp.close();

}

int pay(int x,int fare)
{
    ifstream f;
    f.open("payment.dat",ios::binary);
    while(f.read((char*)&P,sizeof(P)))
        if(!strcmp(U.retuser_id(),P.retu()))
        {
            cout<<"\n\t\t\t The total Fare is : "<<x*fare;
            cout<<"\n\t\t\t Enter the CVV : ";
            int x;
            cin>>x;
            if(x==P.retcvv())
            {
                int y=rand()%10000;
                cout<<"\n Enter the otp you see : "<<y<<" :- ";
                int z;
                cin>>z;
                if(y==z)
                    return 1;
                else
                    return 0;
            }
            else
            {
                cout<<"\nCVV not valid."<<endl;
                return 0;
            }
        }
    f.close();
    return 1;
}


void book()
{
    char FlNo[50];
    int n;
    fstream ft;
    ft.open("ticket.dat",ios::app|ios::binary);

    ifstream fa;
    fa.open("airline.dat",ios::binary);
    ofstream fa2;
    fa2.open("temp.dat",ios::binary);

    cout<<"\nEnter the flight number : ";
    cin>>FlNo;
    while(fa.read((char*)&A,sizeof(A)))
        if(!strcmp(FlNo,A.retflno())) //checking if airline exists
        {
            cout<<"\nEnter number of seats to be booked : ";
            cin>>n;
            if(n<=A.retCapacity())
            {

                for(int i=1;i<=n;i++)
                {
                    ofstream o;
                    o.open("tno.dat",ios::binary|ios::app);
                    for(int k=0;k<n;k++)
                    {
                        N.up();
                        o.write((char*)&N,sizeof(N));
                    }
                    o.close();

                    ifstream f;
                    f.open("tno.dat",ios::binary);
                    while(f.read((char*)&N,sizeof(N)))
                        N.up();

                    int x=N.ret();

                    f.close();

                    cout<<"\nEnter Details of passeneger "<<i<<" : ";
                    T.booking(FlNo,x);
                    ft.write((char*)&T,sizeof(T));
                }
                A.updateCapacity(n);
                fa2.write((char*)&A,sizeof(A));
                int y=pay(n,A.retfare());
                if(y==1)
                {
                    cout<<"\n Successfully paid";
                }

            }

            else
                cout<<"\n Tickets remaining : "<<A.retCapacity();
                 fa2.write((char*)&A,sizeof(A));
        }
        else
            fa2.write((char*)&A,sizeof(A));

    fa2.close();
    ft.close();
    fa.close();
    remove("airline.dat");
    rename("temp.dat","airline.dat");

}

void cancel_ticket()
{
    system("CLS");
    int o;
    cout<<"\n\t\tEnter the tno to be deleted : ";
    cin>>o;
    ofstream fin;
    fin.open("temp.dat",ios::app|ios::binary);
    ifstream fout;
    fout.open("ticket.dat",ios::binary);

    while(fout.read((char*)&T,sizeof(T)))
        if(T.retno()==o)
        {
            cout<<"\n\t\tTicket successfully deleted!";
            ifstream op;
            op.open("airline.dat",ios::binary);
            ofstream p;
            p.open("temp2.dat",ios::binary|ios::app);
            while(op.read((char*)&A,sizeof(A)))
                if(!strcmp(T.retFlNo(),A.retflno()))
                {
                    A.update();
                    p.write((char*)&A,sizeof(A));

                }
                else
                    p.write((char*)&A,sizeof(A));

            op.close();
            p.close();

            remove("airline.dat");
            rename("temp2.dat","airline.dat");

        }
        else
            fin.write((char*)&T,sizeof(T));

    fin.close();
    fout.close();
    //p.close();
    remove("ticket.dat");
    rename("temp.dat","ticket.dat");


}


void main22()
{
    int p;
    system("CLS");
    ifstream f;
    f.open("airline.dat",ios::binary);
    while(f.read((char*)&A,sizeof(A)))
        A.airline_output();

    f.close();
    cout<<endl;
    cout<<endl;
    do
    {
        cout<<"\n\t\t\t1.To book tickets";
        cout<<"\n\t\t\t2.To cancel tickets";
        cout<<"\n\t\t\t3.To view the ticket(s) booked";
        cout<<"\n\t\t\t4.To delete account";
        cout<<"\n\t\t\t0.To exit";
        cout<<"\n\t\t\tEnter choice : ";
        cin>>p;
        switch(p)
        {
            case 1:book();
                break;

            case 2: ticket_displaybyuser();
                cancel_ticket();
                break;

            case 3:ticket_displaybyuser();
                break;

            case 4:U.delete_user();
                break;
        }

    }while(p!=0&&p!=4);
}

void main2()
{
    system("clear");
    char us[50];
    char pa[16];
    cout<<"\n\t\t\tPlease fill the details to sign in : ";
    cout<<endl;
    cout<<endl;
    cout<<"\n\t\t\tEnter the user id : ";
    cin>>us;
    ifstream fu;
    fu.open("user.dat",ios::binary);
    while(fu.read((char*)&U,sizeof(U)))
        if(!strcmp(us,U.retuser_id()))
        {
            cout<<"\n\t\t\tEnter the password : ";
            cin>>pa;
            if(!strcmp(pa,U.retpass()))
                main22();
            else
                for(int i=0;i<5;i++)
                {
                    cout<<"\nAttempts remaining : "<<i;
                    cout<<"\nEnter password : ";
                    cin>>pa;
                    if(!strcmp(pa,U.retpass()))
                        main22();
                }
        }
    //else
    //  cout<<"\n\t\t\tNo user found, please sign up!";

    fu.close();

}

void main3()//adding users
{
    ofstream fuw;
    fuw.open("user.dat",ios::app|ios::binary);


    U.add_user();
    fuw.write((char*)&U,sizeof(U));

    fuw.close();
}

void enterflights()
{
    cout<<"\nEnter the no of flights to be entered : ";
    int n;
    cin>>n;
    fstream file;
    file.open("airline.dat",ios::app|ios::binary);
    for(int i=0;i<n;i++)
    {
        cout<<"\n\t\t\tEnter details for flight "<<i+1<<" : ";
        A.add_airline();
        file.write((char*)&A,sizeof(A));
    }
    file.close();

}

void  viewallpass()
{
    ifstream f;
    f.open("ticket.dat",ios::binary);
    f.seekg(0,ios::beg);
    while(f.read((char*)&T,sizeof(T)))
        T.ticket_display();

    f.close();
}

void viewflightdetails()
{
    ifstream fout;
    fout.open("airline.dat",ios::binary);
    while(fout.read((char*)&A,sizeof(A)))
        A.airline_output();

    fout.close();
}

void viewuserdetails()
{
    ifstream fo;
    fo.open("user.dat",ios::binary);
    while(fo.read((char*)&U,sizeof(U)))
        U.display();

    fo.close();
}

void viewallpassbyflight(char a[10])
{
    ifstream fa;
    fa.open("ticket.dat",ios::binary);
    fa.seekg(0);
    while(fa.read((char*)&T,sizeof(T)))
    {
        if(strcmp(T.retFlNo(),a)==0)
            T.ticket_display();
    }
    fa.close();
}

void main4()
{
    int c;
    char x[10];
    do
    {
        cout<<endl;
        cout<<endl;
        cout<<"\n\t\t\t1.Add more flights ";
        cout<<"\n\t\t\t2.Modify flight details ";
        cout<<"\n\t\t\t3.Delete a flight ";
        cout<<"\n\t\t\t4.View all passengers";
        cout<<"\n\t\t\t5.View all passengers by flight";
        cout<<"\n\t\t\t6.View flight Details";
        cout<<"\n\t\t\t7.View all users";
        cout<<"\n\t\t\t0.To exit";
        cout<<"\n\t\t\tEnter your choice : ";
        cin>>c;
        switch(c)
        {
            case 1: enterflights();
                break;

            case 2: modifyflights();
                break;

            case 3: deleteAirline();
                break;

            case 4: viewallpass();
                break;

            case 5: cout<<"\n\t\t\tEnter flight id : ";
                cin>>x;
                viewallpassbyflight(x);
                break;

            case 6: viewflightdetails();
                break;

            case 7: viewuserdetails();
                break;
        }

    }while(c!=0);

}

void main5()
{
    /*ofstream adm;
     adm.open("admin.dat",ios::app|ios::binary);


     AD.add_admin();
     adm.write((char*)&AD,sizeof(AD));

     adm.close();*/

    system("clear");
    char us[50];
    char pa[16];
    //cout<<"\n\t\t\tPlease fill the details to sign in : ";
    //cout<<endl;
    cout<<endl;
    cout<<"\n\t\t\tEnter the admin id : ";
    cin>>us;
    ifstream ai;
    ai.open("admin.dat",ios::binary);
    while(ai.read((char*)&AD,sizeof(AD)))
        if(!strcmp(us,AD.ret_au()))
        {
            cout<<"\n\t\t\tEnter the password : ";
            cin>>pa;
            // if(strcmp(pa,AD.ret_p())!=0)
            //{
            //  throw 1;
            //}
            try
            {
                int y;
                y=strcmp(pa,AD.ret_p());
                if(y==0)
                    main4();
                else throw y;
            }
            catch(int y)
            {
                cout<<"ERROR"<<endl;
            }
            /*else
             for(int i=0;i<5;i++)
             {
             cout<<"\nAttempts remaining : "<<i;
             cout<<"\nEnter password : ";
             cin>>pa;
             if(!strcmp(pa,U.retpass()))
             main22();
             }*/
        }
    //else
    //  cout<<"\n\t\t\tNo user found, please sign up!";

    ai.close();

}
void main6()
{
    char code[14];
    cout<<"\nEnter code: ";
    cin>>code;
    if(!strcmp("@aussieROX@",code))
    {
        main5();
    }

}
int main(int argc, const char * argv[])
{
    //remove("admin.dat");
    remove("user.dat");
    remove("ticket.dat");
    remove("airline.dat");

    int x;

    do
    {
        int l;
        ifstream file;
        file.open("ticket.dat",ios::binary);
        while(file.read((char*)&T,sizeof(T)))
            cout<<endl;

        l=T.retno();
        cout<<l;
        file.close();


        cout<<"\n\t\t\tWELCOME TO AIRLINE TICKET RESERVATION";
        cout<<"\n\t\t\t******* ** ******* ****** ***********";
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"\n\t\t\t1.To log in ";
        cout<<"\n\t\t\t2.To sign up ";
        cout<<"\n\t\t\t3.Admin sign in";
        cout<<"\n\t\t\t4.To exit";
        cout<<"\n\t\t\tEnter your choice : ";
        cin>>x;
        switch(x)
        {
            case 1:main2();
                break;
            case 2:main3();
                break;
            case 3:main6();
                break;
        }
    }while(x<4);

    return 0;

}

