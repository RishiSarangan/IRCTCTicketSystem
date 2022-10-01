
//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<string.h>

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************


class train
{
	int a[16],pno;
	char name[50],from[50],to[50];
	float price,qty,tax,dis;

	public:

	void show_train()   // Function to display Train Details
	{
		cout<<"\nThe Train No. of The Train : "<<pno;
		cout<<"\nThe Name of The Train : ";
		puts(name);
		cout<<"\nThe Name of The Starting station : ";
		puts(from);
		cout<<"\nThe Name of The Destination : ";
		puts(to);
		cout<<"\nThe Price of The Train : "<<price;
		cout<<"\nDiscount : "<<dis;
	}

	int  retpno()
	{return pno;}

	float retprice()
	{return price;}

	char* retname()
	{return name;}

	char* retfrom()
	{return from;}

	char* retto()
	{return to;}

	int retdis()
	{return dis;}

	void display_sp(int n);
	void write_train();
	void display_all();
	void modify_train();
	void admin_menu();
	void place_order();
	void menu();
	void delete_train();
	int Select();
	void create_train();
	void Enter_Modify(int);

};         //CLASS ENDS HERE

//***************************************************************
//    	global declaration for stream object, object
//****************************************************************

fstream fp;
train pr,pr1;

//***************************************************************
//    	function to create train
//****************************************************************

void train::create_train()
{
	train t;
	fp.open("Train.txt",ios::in|ios::binary);
	cout<<"\nPlease Enter The Train No. of The Train :  ";
	r:cin>>pno;
	while(fp.read((char*)&t,sizeof(train)))
	{

		if(t.retpno()==pno)
		{
			cout<<"Train no. already exists\n";
			cout<<"Please enter another no.";
			goto r;
		}
	}
	fp.close();

	cout<<"\n\nPlease Enter The Name of The Train :  ";
	gets(name);
	cout<<"\n\nPlease Enter The Name of The Starting station :  ";
	gets(from);
	cout<<"\n\nPlease Enter The Name of The Destination :  ";
	gets(to);
	cout<<"\nPlease Enter The Price of The Train :  ";
	cin>>price;
	cout<<"\nPlease Enter The Discount (%) :  ";
	cin>>dis;
	cout<<"\n Please Enter The Seats of the train :  ";

	for(int l = 0; l<16;l++)
	{
		la:cout<<" \n Seat "<<l+1<<" : ";
		cin>>a[l];
		for(int k=0;k<l;k++)
		{
			if(a[k]==a[l])
			{
				cout<<"Please enter different number";
				goto la;
			}
		}
	}
}

//***************************************************************
//    	function to write train in file
//****************************************************************

void train::write_train()
{
	pr.create_train();
	fp.open("Train.txt",ios::out|ios::app|ios::binary);
	fp.write((char*)&pr,sizeof(pr));
	fp.close();
	cout<<"\n\nThe Train Has Been Created ";
	getch();
}

//***************************************************************
//    	function to read all records from file
//****************************************************************

void train::display_all()
{
	train t;
	clrscr();
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	fp.open("Train.txt",ios::in|ios::binary);
	while(fp.read((char*)&pr,sizeof(pr)))
	{
		pr.show_train();
		cout<<"\n\n====================================\n";
		getch();
	}
	fp.close();
	getch();
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void train::display_sp(int n)
{
	int flag=0;
	fp.open("Train.txt",ios::in|ios::binary);
	while(fp.read((char*)&pr,sizeof(pr)))
	{
		if(pr.retpno()==n)
		{
			clrscr();
			pr.show_train();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
	cout<<"\n\nrecord not exist";
	getch();
}

//***************************************************************
//    	function to modify record of file
//****************************************************************

void train::modify_train()
{

	int found=0,no;
	clrscr();
	cout<<"\n\n\tTo Modify ";
	cout<<"\n\n\tPlease Enter The Train No. of The Train";
	cin>>no;
	fp.open("Train.txt",ios::in|ios::out|ios::binary);
	while(!fp.eof())
	{
		fp.read((char*)&pr,sizeof(train));
		if(pr.retpno()==no)
		{
			pr.show_train();
			cout<<"\nPlease Enter The New Details of Train"<<endl;
			pr1.Enter_Modify(no);
			int pos=-1*sizeof(pr);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&pr1,sizeof(train));
			cout<<"\n\n\t Record Updated";
			found=1;
			break;
		}
	}
	fp.close();
	if(found==0)
	cout<<"\n\n Record Not Found ";
	getch();

}

void train::Enter_Modify(int p)
{
	pno=p;
	cout<<"\n\nPlease Enter The Name of The Train :  ";
	gets(name);
	cout<<"\n\nPlease Enter The Name of The Starting station :  ";
	gets(from);
	cout<<"\n\nPlease Enter The Name of The Destination :  ";
	gets(to);
	cout<<"\nPlease Enter The Price of The Train :  ";
	cin>>price;
			cout<<"\nPlease Enter The Discount (%) :  ";
			cin>>dis;
			cout<<"\n Please Enter The Seats of the train :  ";

			for(int l = 0; l<16;l++)
			{
				la1:cout<<" \n Seat "<<l+1<<" : ";
				cin>>a[l];
				for(int k=0;k<l;k++)
				{
					if(a[k]==a[l])
					{
						cout<<"Please enter different number";
						goto la1;
					}
				}
			}
}
//***************************************************************
//    	function for seat booking
//****************************************************************

int train::Select()
{
	clrscr();
	int seatno,flag=0;
	char ch;
	seat_select:
	clrscr();
	cout<<"\n" ;
	cout<<"------------------------------\t \t ------------------------------\n";
	cout<<"|           RESTROOM          |\t \t |           RESTROOM	      |\n";
	cout<<"------------------------------\t \t ------------------------------\n";
	cout<<"|ENTRY / EXIT                                             ENTRY / EXIT|\n";
	cout<<"------------------------------\t \t ------------------------------\n \n ";
	for(int i=0;i<16;i++)
	{
		if(i%4 == 0 && i != 0)
		cout<<"\n \n ";

		if(a[i]== 'B')
		{
			textcolor(6);
			cprintf("        [ B ]   ");
		}
		else
		{
			textcolor(3);
			cout<<"\t [ "<<a[i]<<"] \t";
		}

	}
	cout<<"\n \n";
	cout<<"------------------------------\t \t ------------------------------\n";
	cout<<"|ENTRY / EXIT                 \t \t                  \ENTRY / EXIT|\n";
	cout<<"------------------------------\t \t ------------------------------\n";
	cout<<"|           RESTROOM          |\t \t|           RESTROOM	      |\n";
	cout<<"------------------------------\t \t ------------------------------\n";
	do
	{

		textcolor(7);
		cout<<"\t Enter the desired Seat number to be booked :  ";
		cin>>seatno;
		clrscr();
		for(int k = 0;k<16;k++)
		{
			if(a[k] == seatno)
			{
				flag = k;
				break;
			}
			else
			flag = -1;
		}
		if(flag == -1)
		{
			cout<<"\n \t INVALID SEAT, \n \t Please choose VALID seat \n";
			getch();
			goto seat_select;
		}

		cout<<"\n" ;
		cout<<"------------------------------\t \t ------------------------------\n";
		cout<<"|           RESTROOM          |\t \t |           RESTROOM	      |\n";
		cout<<"------------------------------\t \t ------------------------------\n";
		cout<<"|ENTRY / EXIT                                             ENTRY / EXIT|\n";
		cout<<"------------------------------\t \t ------------------------------\n \n ";
		for(int p=0;p<16;p++)
		{

			if(p%4 == 0 && p!=0)
			{
				cout<<"\n \n ";
			}

			if(a[p]== 'B')
			{
				textcolor(6);
				cprintf("        [ B ]   ");
			}

			else if(p==flag)
			{
				textcolor(-6);
				cprintf("        [ # ]       ");
			}

			else
			{
				cout<<"\t [ "<<a[p]<<"] \t";
			}

		}
		cout<<"\n \n";
		cout<<"------------------------------\t \t ------------------------------\n";
		cout<<"|ENTRY / EXIT                 \t \t                  \ENTRY / EXIT|\n";
		cout<<"------------------------------\t \t ------------------------------\n";
		cout<<"|           RESTROOM          |\t \t|           RESTROOM	      |\n";
		cout<<"------------------------------\t \t ------------------------------\n";
		cout<<" \n \t Please Enter (C) if you want to CHANGE seat :";
		cin>>ch;
	}while(ch == 'C');
	textcolor(7);
	return seatno;
}

//***************************************************************
//    	function to delete record of file
//****************************************************************

void train::delete_train()
{
	int no,f=1;
	clrscr();
	cout<<"\n\n\n\tDelete Record";
	cout<<"\n\nPlease Enter The train no. of The Train You Want To Delete";
	cin>>no;
	fp.open("Train.txt",ios::in|ios::out|ios::binary);
	fstream fp2;
	fp2.open("Temp.txt",ios::out|ios::binary);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&pr,sizeof(train)))
	{
		if(pr.retpno()!=no)
		{
			fp2.write((char*)&pr,sizeof(train));
			f=0;
		}
	}
	fp2.close();
	fp.close();
	remove("Train.txt");
	rename("Temp.txt","Train.txt");
	if(f==0)
	cout<<"Train does not exists";
	else
	cout<<"\n\n\tRecord Deleted ..";
	getch();
}

//***************************************************************
//    	function to display all trains price list
//****************************************************************

void train::menu()
{
	clrscr();
	fp.open("Train.txt",ios::in|ios::binary);
	if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
		cout<<"\n\n\n Program is closing ....";
		getch();
		exit(0);
	}

	cout<<"\n\n\t\tTrain MENU\n\n";
	cout<<"================================================================================\n";
	cout<<"T.NO    NAME\t\tFROM\t\tTO\t\t\PRICE\n";
	cout<<"================================================================================\n";

	while(fp.read((char*)&pr,sizeof(train)))
	{
	   cout<<pr.retpno()<<"    "<<pr.retname()<<"\t \t"<<pr.retfrom()<<"\t        "<<pr.retto()<<"\t"<<pr.retprice()<<endl;
	}

	fp.close();

}

//***************************************************************
//    	function to book tickets and generating bill for Trains
//****************************************************************

void train::place_order()
{

    int  order,seat,f=0;
    float amt,damt,total=0;
    menu();
    cout<<"\n============================";
    cout<<"\n    PLACE YOUR ORDER";
    cout<<"\n============================\n";

    cout<<"\n\nEnter The Train No. Of The Train : ";
    cin>>order;
    fp.open("Train.txt",ios::in|ios::binary);
    while(fp.read((char*)&pr,sizeof(train)))
    {
	if(pr.retpno()==order)
	{
		f=1;
		break;
	}
    }
    fp.close();
    if(f==1)
    {
	cout<<"\n Proceeding to Seat selection... \n";
	cout<<" \n NOTE : \n [B] = Booked Seats \n";
	cout<<" [number] = Available seats \n";
	getch();
	seat = Select();
	int l=0;
	fp.open("Train.txt",ios::in|ios::out|ios::binary);
	while(fp.read((char*)&pr,sizeof(train)))
	{
		if(pr.retpno()==order)
		{
			for(int p=0;p<16;p++)
			{
				if(a[p] == seat)
				{
					a[p] = -1;
					fp.seekp((l*sizeof(train))+(p*2),ios::beg);
					fp.write("B",1);
					break;
				}
			}

		}
		l++;
	}

	fp.close();
	clrscr();
	cout<<"\n\n \n \t Thank You For Booking the Tickets";getch();clrscr();
	cout<<"\n\n********************************TICKETS**********************************\n";
	cout<<"\nTrain No.    Train Name      Price     Price after discount \n";
	fp.open("Train.txt",ios::in|ios::binary);
	while(fp.read((char*)&pr,sizeof(train)))
	{
		if(pr.retpno()==order)
		{
		amt=pr.retprice();
		damt=amt-(amt*pr.retdis()/100);
		cout<<"\n"<<order<<"\t       "<<pr.retname()<<"\t      "<<pr.retprice()<<"\t     "<<damt<<"\n \n \n \t \t \t";
		cout<<"SEAT "<<" : "<<seat<<"\n \t \t \t";
		total+=damt;
		}
	}
	fp.close();
	cout<<"\n\n\n\n\n\t\t\t\t\tTOTAL AMOUNT  = "<<total;
	getch();
    }

    else
    {
	cout<<"The Train does not exists";
    }

}

//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{

	clrscr();
	cout<< "\n \n \n \n";
	cout<<"	___________   _______________________________________^__       \n";
	cout<<"	 ___   ___ |||  ___   ___   ___    ___ ___  |   __  ,----\     \n";
	cout<<"	|   | |   |||| |   | |   | |   |  |   |   | |  |  | |_____\    \n";
	cout<<"	|___| |___|||| |___| |___| |___|  | O | O | |  |  |        \   \n";
	cout<<"	           |||                    |___|___| |  |__|         )  \n";
	cout<<"	___________|||______________________________|______________/   \n";
	cout<<"	           |||                                        /--------\n";
	cout<<"	-----------'''---------------------------------------'         \n";
	getch();
	clrscr();
	gotoxy(31,11);
	cout<<"INDIAN RAILWAYS ";
	gotoxy(35,14);
	cout<<"e-BOOKING";
	gotoxy(35,17);
	cout<<"PROJECT";
	cout<<"\n\nMADE BY : Rishikesh Sarangan";
	getch();

}

//***************************************************************
//    	ADMINSTRATOR MENU FUNCTION
//***************************************************************

void train::admin_menu()
{
	clrscr();
	char ch2;
	cout<<"\n\n\n\tADMIN MENU";
	cout<<"\n\n\t1.CREATE ENTRY";
	cout<<"\n\n\t2.DISPLAY ALL TRAINS";
	cout<<"\n\n\t3.QUERY ";
	cout<<"\n\n\t4.MODIFY TRAINS";
	cout<<"\n\n\t5.DELETE TRAINS";
	cout<<"\n\n\t6.VIEW TRAIN MENU";
	cout<<"\n\n\t7.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-7) ";

	ch2=getche();

	switch(ch2)
	{
		case '1': 	clrscr();
				write_train();
				break;

		case '2': 	display_all();
				break;

		case '3':	int num;
				clrscr();
				cout<<"\n\n\tPlease Enter The Train No. ";
				cin>>num;
				display_sp(num);
				break;

		case '4': 	modify_train();
				break;

		case '5': 	delete_train();
				break;

		case '6': 	menu();
				getch();
				break;

		case '7': 	break;

		default:cout<<"\a";admin_menu();
	}

}


//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************


void main()
{
	char ch;
	intro();
	do
	{
		clrscr();
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. TICKET BOOKING";
		cout<<"\n\n\t02. ADMINISTRATOR";
		cout<<"\n\n\t03. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-3) ";
		ch=getche();
		switch(ch)
		{
			case '1': 	clrscr();
					pr.place_order();
					getch();
					break;

			case '2': 	pr.admin_menu();
					break;

			case '3':	exit(0);

			default :	cout<<"\a";

		}

    }while(ch!='3');

}

//***************************************************************
//    			END OF PROJECT
//***************************************************************
