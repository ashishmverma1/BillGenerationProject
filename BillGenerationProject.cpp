//////////////P R O J E C T   B I L L   G E N E R A T I O N/////////


//////////////////////H E A D E R   F I L E S///////////////////


#include<fstream.h>
//for all stream operations

#include<conio.h>
//for clrscr, getch, etc.

#include<dos.h>
//for delay

#include<string.h>
//for strcpy, strcmp, etc.

#include<process.h>
//for exit

#include<stdio.h>
//for gets, getc, etc.

#include<stdlib.h>
//for randomize

////////////////////////A L L   S T R E A M S/////////////////////////

fstream fitem, fbill, fcount;

/////////////////////////////////////////////////////////////////////


int item_count, bill_count;

//////////////////////////A L L   C L A S S E S///////////////////////


class item    //for inputing/displaying item information
{
	public:
	char item_name[30], item_brand[30];
	int item_code;
	float item_price;
}item1;



class bill   //for inputing/displaying bill information
{
	public:
	int bill_no;
	int dd, mm, yy, hr, min;
	float bill_price;
}bill1;



struct date d;  //for getting sys date
struct time t;  //for getting sys time



class count   //for storing bill/item count
{
	public:
	int itemcount, billcount;
}count1;


///////////////////////A L L   F U N C T I O N S/////////////////////


void loading();     //to display the loading screen
void password();    //to add the feature of password protection
void about();       //to display the 'about' page
void main_menu();   //to display main menu and input user's selection
void exit_prog();   //to exit the program/SAVE all information
void welcome();     //to display welcome screen
void del_data();    //to master reset
void printer();	    //to print bill
void item_input();  //to enter new items
void item_output(); //to output item details from file
void item_view();   //to manipulate items
void bill_input();  //to input/print billing data
void bill_output(); //to output bill info from file
void bill_view();   //to view/delete bills


//////////////////////////////////////////////////////////////////////





void main()
{
	clrscr();
	password();
	cout<<"\n\n\n\n\n\n\t\tPlease wait while "
	<<"the software is being loaded . . .";

	fcount.open("count.dat", ios::in);
	fcount.read((char*) &count1, sizeof(count1));
	item_count=count1.itemcount;
	bill_count=count1.billcount;
	fcount.close();

	loading();
	welcome();
	main_menu();

	getch();
}









//////////////////F U N C T I O N   D E F I N I T I O N S/////////////////


//////////////////////////////L O A D I N G///////////////////////////////

void loading()
{
	int i,j;
	gotoxy(20,40);
	cout<<"----------------------------------------";
	gotoxy(20,41);
	cout<<"[                                      ]";
	gotoxy(20,42);
	cout<<"----------------------------------------";

	for(i=0; i<38; i++)
	{
		gotoxy((21+i),41);    	cout<<"*";
		j=i*100;		j=(j/38) + 3;
		gotoxy(37,44);		cout<<j<<" %";
		delay(60);
		if(i==30) delay(350);

	}
	delay(500);
}











///////////////////////P A S S W O R D//////////////////////////////

void password()
{
	char pass[6], in[100];	int c=0;
	strcpy(pass, "ashish");
	cout<<"\n\t\t\tEnter The Password : ";
	for(int i=0; in[i-1]!=13; i++)
	{
		in[i]=getch();
		if(in[i]!=13) cout<<"*";
	}

	for(i=0; i<6 ; i++)
	if(pass[i]!=in[i] || in[6]!=13)c=1;

	if(c==1)
	{
		cout<<"\n\n\t\t\tPassword incorrect !!!"
		<<"\n\n\t\t   Software is now shutting down . . .";
		loading();
		exit(0);
	}
	if(c==0) cout<<"\n\n\t\t\tPassword Correct !!";
	delay(500);
}













/////////////////////////////A B O U T///////////////////////////

void about()
{
	clrscr();
	cout<<"\n\n\n\t\t\t\t  A B O U T"
	<<"\n\t\t\t\t  --------- "
	<<"\n\n\n\n\t\t  This Bill Generation software was originally developed"
	<<"\n\n\t\tas  a   project   for  the  academic  session  2010-2011,"
	<<"\n\n\t\ton the language C++."
	<<"\n\n\n\n\t\t  The key features include : "
	<<"\n\n\t\t* Password Protection"
	<<"\n\n\t\t* Menu Item Management"
	<<"\n\n\t\t* Bill Calculation/Geneation/Printing"
	<<"\n\n\n\n\n\n\t\t\t\tDEVELOPED BY :"
	<<"\n\t\t\t\t------------"
	<<"\n\n\t\tAshish Mohan Verma"
	<<"\n\n\t\tClass XII"
	<<"\n\n\t\tSomerville School, Gr. Noida"
	<<"\n\n\t\t2010 - 2011"
	<<"\n\n\n\n\n\t\tPress any key to return to main menu.";
	getch();
	main_menu();
}















///////////////////////M A I N   M E N U//////////////////////////////

void main_menu()
{
	clrscr();
	int ch;
	cout<<"\n\t\tW H A T   W O U L D   Y O U   L I K E   T O   D O  ?"
	<<"\n\t\t----------------------------------------------------"
	<<"\n\n\n\n\t\t(1). Enter New Items In The Menu"
	<<"\n\n\t\t(2). View/Manipulate Information For Existing Menu"
	<<"\n\n\t\t(3). Enter Billing Information And Print Bill"
	<<"\n\n\t\t(4). View/Delete Existing Purchases' Bill"
	<<"\n\n\t\t(5). Delete All Data"
	<<"\n\n\t\t(6). About"
	<<"\n\n\t\t(7). Exit"
	<<"\n\n\n\n\n\t\tE N T E R   Y O U R   C H O I C E  :  ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			item_input();
			break;

		case 2:
			item_view();
			break;

		case 3:
			bill_input();
			break;

		case 4:
			bill_view();
			break;

		case 5:
			del_data();
			break;

		case 6:
			about();
			break;

		case 7:
			exit_prog();
			break;

		default:
			cout<<"\n\n\n\t\tYou entered an INVALID choice!";
			getch();
			main_menu();
			break;
	     }

}
















/////////////////////////E X I T   P R O G R A M/////////////////////

void exit_prog()
{
	clrscr();
	char ans;
	cout<<"\n\n\n\t\t  Are you sure you want to EXIT (y/n) : ";
	cin>>ans;
	if(ans=='n' || ans=='N') main_menu();
	cout<<"\n\n\n\n\n\t\tSoftware is now saving and"
	<<" shutting down . . ."
	<<"\n\n\n\n\t\t   Thankyou For Using The Software!";
	loading();
	fcount.open("count.dat", ios::out | ios::trunc);
	count1.itemcount=item_count;
	count1.billcount=bill_count;
	fcount.write((char*) &count1, sizeof(count1));
	fcount.close();
	exit(0);
}














///////////////////////////W E L C O M E///////////////////////////////

void welcome()
{
	clrscr();
	char w1[27], w2[47];
	strcpy(w1,"W e l c o m e   T o   T h e");
	gotoxy(25,15);
	for(int i=0;i<27;i++)
	{
		cout<<w1[i];
		delay(50);
	}
	strcpy(w2,"B i l l   G e n e r a t i o n   S o f t w a r e");
	gotoxy(15,20);
	for(i=0;i<47;i++)
	{
		cout<<w2[i];
		delay(50);
	}
	delay(800);
}

















////////////////////////D E L E T E   D A T A//////////////////////

void del_data()
{
	clrscr();
	char ch;
	cout<<"\n\n\n\t\t\tPress 'i' to delete whole MENU,"
	<<"\n\n\t\t\t'b' to delete all BILLING DATA,"
	<<"\n\n\t\t\t'm' to MASTER RESET, or"
	<<"\n\n\t\t\t'c' to CANCEL : ";
	ch=getche();
	if(ch=='i')
	{
		cout<<"\n\n\n\t\tAre you sure you want to delete whole MENU ? (y/n) : ";
		cin>>ch;
		if(ch=='y')
		{
			remove("itemdata.dat");
			cout<<"\n\n\n\t\t\tWhole Menu Deleted!"
			<<"\n\n\t\t\tPress any key to return to main menu.";
			getch();
			item_count=0;
			main_menu();
		}
		else del_data();
	}
	else if(ch=='b')
	{
		cout<<"\n\n\n\tAre you sure you want to delete all BILLING INFORMATION ? (y/n) : ";
		cin>>ch;
		if(ch=='y')
		{
			remove("billdata.dat");
			cout<<"\n\n\n\t\t\tAll Billing information Deleted!"
			<<"\n\n\t\t\tPress any key to return to main menu.";
			getch();
			bill_count=0;
			main_menu();
		}
		else del_data();
	}
	else if(ch=='m')
	{
		cout<<"\n\n\n\t\tAre you sure you want to MASTER RESET ? (y/n) : ";
		cin>>ch;
		if(ch=='y')
		{
			remove("billdata.dat");
			remove("itemdata.dat");
			remove("count.dat");
			cout<<"\n\n\n\t\t\tMaster Reset Successful!"
			<<"\n\n\t\t\tPress any key to return to main menu.";
			getch();
			item_count=0;
			bill_count=0;
			main_menu();
		}
		else del_data();
	}
	else if(ch=='c') main_menu();
	else
	{
		cout<<"\n\n\n\t\t\t\tInvalid Choice!!";
		getch();
		del_data();
	}
}


//////////////////////////P R I N T E R///////////////////////////////

void printer()
{

}


















///////////////////I N P U T   I T E M S//////////////////////////

void item_input()
{
	clrscr();
	fitem.open("itemdata.dat", ios::app);

	gotoxy(15,2);
	cout<<"To stop entering, enter '0' as the item code !";
	cout<<"\n\n";
	cout<<" Item Code  |             Name              |         Brand         |     Price";
	cout<<"\n";
	cout<<" ---------                ----                        -----               -----";

	for(int i=0;i<15;i++)
	{

		gotoxy(5,7+i*2);
		cin>>item1.item_code;
		if(item1.item_code==0) goto end1;
		gotoxy(24,7+i*2);
		gets(item1.item_name);
		gotoxy(54,7+i*2);
		gets(item1.item_brand);
		gotoxy(75,7+i*2);
		cin>>item1.item_price;
		if(item1.item_code!=0)
		fitem.write((char*) &item1, sizeof(item1));
	}
	end1:
	item_count+=i;
	fitem.close();
	item_output();

	cout<<"\n\n\t\t\tMenu Update Successfull !!";
	getch();
	main_menu();

}



















////////////////////////O U T P U T  I T E M S//////////////////////////

void item_output()
{
	clrscr();
	fitem.open("itemdata.dat", ios::in);
	fitem.seekg(0);

	cout<<"\n";
	cout<<" Item Code  |             Name              |         Brand         |     Price";
	cout<<"\n";
	cout<<" ---------                ----                        -----               -----";

	for(int i=0;i<item_count;i++)
	{
		fitem.read((char*) &item1, sizeof(item1));
		gotoxy(5,5+i*2);
		cout<<item1.item_code;
		gotoxy(24,5+i*2);
		cout<<item1.item_name;
		gotoxy(54,5+i*2);
		cout<<item1.item_brand;
		gotoxy(75,5+i*2);
		cout<<item1.item_price;
	}
	fitem.close();

}















//////////////////////M A N I P U L A T E   M E N U//////////////////

void item_view()
{
	item_output();
	char ch, found='f';
	int code;
	long pos;
	cout<<"\n\n\n\n\t\t\tPress 'd' to DELETE a record, "
	<<"\n\n\t\t\t'm' to MANIPULATE a record or"
	<<"\n\n\t\t\t'c' to CANCEL : ";
	ch=getche();
	item_output();

	if(ch=='c') main_menu();

	else if(ch=='d')
	{
		cout<<"\n\n\n\n\tEnter 'Item Code' of record to be deleted : ";
		cin>>code;
		fitem.open("itemdata.dat", ios::in);
		ofstream temp("temp.dat", ios::out);
		for(int i=0;i<item_count;i++)
		{
			fitem.read((char*) &item1, sizeof(item1));
			if(item1.item_code==code) found='t';
			else temp.write((char*) &item1, sizeof(item1));
		}
		if(found=='f')
		{
			cout<<"\n\n\t\tItem NOT found!!";
			item_view();
		}
		else --item_count;
		fitem.close();
		temp.close();
		remove("itemdata.dat");
		rename("temp.dat", "itemdata.dat");

		item_output();
		cout<<"\n\n\n\n\t\t\tMenu Update Successfull !!";
		cout<<"\n\n\n\n\t\t\t Above is the NEW menu.";
		getch();
		item_view();
	}

	else if(ch=='m')
	{
		cout<<"\n\n\n\n\tEnter 'Item Code' of record to be manipulated : ";
		cin>>code;
		fitem.open("itemdata.dat", ios::in | ios::out);
		for(int i=0;i<item_count;i++)
		{
			pos=fitem.tellg();
			fitem.read((char*) &item1, sizeof(item1));
			if(item1.item_code==code)
			{
				gotoxy(5,5+i*2);
				cout<<"                                                                                ";
				gotoxy(5,5+i*2);
				cin>>item1.item_code;
				gotoxy(24,5+i*2);
				gets(item1.item_name);
				gotoxy(54,5+i*2);
				gets(item1.item_brand);
				gotoxy(75,5+i*2);
				cin>>item1.item_price;
				fitem.seekg(pos);
				fitem.write((char*) &item1, sizeof(item1));
				found='t';
				break;
			}
		}
		fitem.close();

		item_output();
		cout<<"\n\n\n\n\t\t\tMenu Update Successfull !!";
		cout<<"\n\n\n\n\t\t\t Above is the NEW menu.";
		getch();
		item_view();
	}

	else
	{
		cout<<"\n\n\n\t\t\t\tInvalid Choice!";
		getch();
		item_view();
	}
}















//////////////////////I N P U T   B I L L//////////////////////////

void bill_input()
{
	clrscr();
	fbill.open("billdata.dat", ios::app);
	char prnt;
	char item_name[30], item_brand[30];
	int item_code , item_qty;
	float item_price;

	gotoxy(5,3);
	randomize();	bill1.bill_no=random(9999);
	cout<<"Bill Number : "<<bill1.bill_no;

	gotoxy(33,3);
	getdate(&d);
	bill1.dd=d.da_day;
	bill1.mm=d.da_mon;
	bill1.yy=d.da_year;
	cout<<"Date : "<<bill1.dd<<"/"<<bill1.mm
	<<"/"<<bill1.yy;

	gotoxy(60,3);
	gettime(&t);
	bill1.hr=t.ti_hour;
	bill1.min=t.ti_min;
	cout<<"Time : "<<bill1.hr<<":"<<bill1.min;

	gotoxy(5,5);
	cout<<"Enter Item Information Below : ";


	gotoxy(5,7);
	cout<<"To stop entering, enter '0' as the item code !";
	cout<<"\n\n\n\n";
	cout<<" Item Code  |       Name         |       Brand       |    Quantity    |   Price";
	cout<<"\n";
	cout<<" ---------          ----                 -----            --------        -----";


	bill1.bill_price=0;

	for(int i=0;i<15;i++)
	{

		gotoxy(5,17+i*2);
		cin>>item_code;
		if(item_code==0)
		{
			gotoxy(5,17+i*2);
			cout<<"       ";
			goto end2;
		}

		fitem.open("itemdata.dat", ios::in);
		for(int j=0;j<item_count;j++)
		{
			fitem.read((char*) &item1, sizeof(item1));
			if(item1.item_code==item_code)
			{
				gotoxy(19,17+i*2);
				cout<<item1.item_name;
				gotoxy(40,17+i*2);
				cout<<item1.item_brand;
				gotoxy(61,17+i*2);
				cin>>item_qty;
				gotoxy(76,17+i*2);
				item_price=item_qty*item1.item_price;
				cout<<item_price;
				bill1.bill_price+=item_price;
				goto end3;
			}
		}

		gotoxy(19,17+i*2);
		gets(item_name);
		gotoxy(40,17+i*2);
		gets(item_brand);
		gotoxy(61,17+i*2);
		cin>>item_qty;
		gotoxy(76,17+i*2);
		cin>>item_price;
		bill1.bill_price+=item_price;
		end3:
		fitem.close();

	}
	end2:
	bill_count++;
	gotoxy(30,21+i*2);
	cout<<"Total Bill Cost : "<<bill1.bill_price;
	fbill.write((char*) &bill1, sizeof(bill1));
	fbill.close();

	cout<<"\n\n\n\t\t\tBill Data Update Successfull !!";
	cout<<"\n\n\n\n\t\t\tPress 'p' now to print current bill, "
	<<"\n\n\t\t\tor any other key to return to main menu : ";
	prnt=getche();
	if(prnt=='p')
	{
		printer();
		cout<<"\n\n\n\n\t\t\t\tPrint Data sent!";
		getch();
	}
	main_menu();
}














//////////////////////B I L L    O U T P U T//////////////////////////

void bill_output()
{
	clrscr();
	fbill.open("billdata.dat", ios::in);
	fbill.seekg(0);

	cout<<"\n";
	cout<<"    Bill No.     |         Date           |        Time         |      Price    ";
	cout<<"\n";
	cout<<"    --------               ----                    ----                -----";

	for(int i=0;i<bill_count;i++)
	{
		fbill.read((char*) &bill1, sizeof(bill1));
		gotoxy(7,7+i*2);
		cout<<bill1.bill_no;
		gotoxy(24,7+i*2);
		cout<<bill1.dd<<"/"<<bill1.mm<<"/"<<bill1.yy;
		gotoxy(52,7+i*2);
		cout<<bill1.hr<<":"<<bill1.min;
		gotoxy(73,7+i*2);
		cout<<bill1.bill_price;
	}
	fbill.close();

}















/////////////////M A N I P U L A T E   B I L L S////////////////////

void bill_view()
{
	bill_output();
	char ch, found='f';
	int code;
	cout<<"\n\n\n\n\t\t\tPress 'd' to DELETE a record or "
	<<"\n\n\t\t\t'c' to CANCEL : ";
	ch=getche();
	bill_output();

	if(ch=='c') main_menu();

	else if(ch=='d')
	{
		cout<<"\n\n\n\n\tEnter 'Bill No.' of the bill to be deleted : ";
		cin>>code;
		fbill.open("billdata.dat", ios::in);
		ofstream temp1("temp1.dat", ios::out);
		for(int i=0;i<bill_count;i++)
		{
			fbill.read((char*) &bill1, sizeof(bill1));
			if(bill1.bill_no==code) found='t';
			else temp1.write((char*) &bill1, sizeof(bill1));
		}
		if(found=='f')
		{
			cout<<"\n\n\t\tItem NOT found!!";
			bill_view();
		}
		else --bill_count;
		fbill.close();
		temp1.close();
		remove("billdata.dat");
		rename("temp1.dat", "billdata.dat");

		bill_output();
		cout<<"\n\n\n\n\t\t\tBill Data Update Successfull !!";
		cout<<"\n\n\n\n\t\t\t Above is the NEW Bill Data.";
		getch();
		bill_view();
	}

	else
	{
		cout<<"\n\n\n\t\t\t\tInvalid Choice!";
		getch();
		bill_view();
	}
}






/////////////////E N D   O F   T H E    P R O G R A M//////////////////
