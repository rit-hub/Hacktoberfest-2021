//mini project.
//account based toll plaza management system.
//17/06/2021


/* BY GROUP

deepak s. patil
gaurav s. patil
sahil s. patil
sanket k. patil
*/

/*
for running in android cpp compiler replace bits/stdc++.h with iostream.h,conio.h,string.h,ctime.
for linux replace system("CLS") with system("clear");
for linux replace system("PAUSE") with char c; c=cin.get();
*/

#include<bits/stdc++.h>
#include<windows.h>
//uncomment below file if you are using unix or linux
//#include<unistd.h> 
using namespace std;

void mainmenu();
void help();
int loginmenu(int i);
int adminmenu();
int usermenu();
int userlog();
int adminlog();
int newacc();
int infouser();
int userreq();
int approve();
int tollsys();
int accpay(int i);
int transhistory(int i);

int main()
{
	int ch;
	
	do{
		//main screen menu 
		system("CLS");
		cout<<"\n\n\n\n\n\n";
		cout<<"\t\t\t\tWELCOME TO TOLL PLAZA MANAGEMENT SYSTEM"<<endl;
		cout<<"\t\t\t\t***************************************\n\t\t\t\t1.MAIN MENU\n\t\t\t\t*******************\n\t\t\t\t2.HELP\n\t\t\t\t*******************\n\t\t\t\t3.EXIT\n\t\t\t\t*******************\n\t\t\t\t";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				system("CLS");
				mainmenu();
				break;
			case 2:
				system("CLS");
				help();
				break;
			case 3:
				system("CLS");
				cout<<"THANKS FOR USING THE SERVICE"<<endl;
				return 0;
			default:
				system("CLS");
				cout<<"NO SUCH OPTION\n";
				system("PAUSE");
		}
		
	}while(ch!=3);
	
	return 0;
}

void mainmenu()
{
	int chm;
	
	do{
		//main menu of program.
		cout<<"\n\n\n\n\n\n";
		cout<<"\t\t\t\tYOU ARE IN MAIN MENU"<<endl;
		cout<<"\t\t\t\t********************\n\t\t\t\t1.USER LOGIN\n\t\t\t\t********************\n\t\t\t\t2.ADMIN LOGIN\n\t\t\t\t********************\n\t\t\t\t3.RETURN TO MAIN SCREEN\n\t\t\t\t********************\n\t\t\t\t";
		cin>>chm;
		switch(chm)
		{
			case 1:
				system("CLS");
				loginmenu(1);
				break;
			case 2:
				system("CLS");
				loginmenu(2);
				break;
			case 3:
				system("CLS");
				return;
			default:
				system("CLS");
				cout<<"PLEASE SELECT A VALID OPTION"<<endl<<flush;
				system("PAUSE");
				system("CLS");
		}
	}while(chm!=3);
	return;
}

void help()
{
	//help for the program.
	cout<<"\t\t\t\t"<<endl;
	cout<<"*****************THIS IS HELP******************"<<endl;
	cout<<"1.SELECT __MAIN MENU__ TO GET MAIN MENU\n2.IN MAIN MENU YOU HAVE 2 OPTIONS\n3.IF YOU ARE USER SELECT __USER LOGIN__\n4.IF YOU ARE ADMIN OR TOLL PLAZA MANAGER SELECT __ADMIN LOGIN__ OPTION\n\n"<<endl;
	cout<<"USER LOGIN\n1.IF YOU HAVE YOUR ACCOUNT SELECT __LOGIN__ TO LOGIN TO SYSTEM\n2.IF YOU DON'T HAVE USER ACCOUNT SELECT __NEW ACCOUNT CREATION__ TO CREATE A NEW ACCOUNT\n3.AFTER CREATING ACCOUNT YOUR ACCOUNT SHOULD BE VERIFIED BY ADMIN.\n4.AFTER WHICH YOU CAN LOGIN TO SYSTEM\n\n\n\nUSER OPTIONS\nAFTER LOGIN YOU HAVE 3 USER OPTIONS\n1.TO VIEW YOUR INFORMATION SELECT __USER INFORMATION__\n2.TO PAY TOLL VIA YOUR USER ACCOUNT SELECT __PAY TOLL VIA ACCOUNT__\n3.TO VIEW YOUR TRANSACTION HISTORY SELECT __TRANSACTION HISTORY__\n";
	cout<<"\n\nADMIN MENU\nAFTER ADMIN LOGIN YOU WILL HAVE 4 OPTIONS IN ADMIN MENU\n1.TO VIEW USER ACCOUNT REQUESTS SELECT __USER REQUESTS__\n2.TO VIEW USER INFORMATION SELECT __USER INFORMATION__\n3.TO APPROVE A USER ACCOUNT SELECT __ APPROVE USER__\n4.TO GET TOLL PLAZA MANAGEMENT OPTIONS SELECT __TOLL SYSTEM__"<<endl;
	cout<<"\n\nTOLL SYSTEM\nIN TOLL SYSTEM YOU WILL GET 4 OPTIONS\n1.TO PAY TOLL VIA USER ACCOUNT SELECT __PAY TOLL VIA ACCOUNT__ OPTION\n2.TO PAY TOLL VIA CASH SELECT __CASH PAYMENT__\n3.TO ADD MONEY TO USER ACCOUNT SELECT __ADD MONEY TO WALLET__\n4.TO VIEW TOLL PAYMENT HISTORY SELECT __TRANSACTION HISTORY__\n";
	cout<<"\n\nNOTE**ENTER EVERY INPUT WITHOUT SPACE**"<<endl;
	cout<<"NOTE**ENTER SPECIFIC INPUT TO USE PROGRAM CORRECTLY**\n\n"<<endl;
	cout<<"*******************************************************"<<endl;
	cout<<"PRESS ANY KEY TO RETURN TO MAIN SCREEN"<<endl<<flush;
	system("PAUSE");
	system("CLS");
	return;
}

int loginmenu(int i)
{
	int logc;
	//login menu for user and admin.
	if(i==1)
	{	
		do{
			cout<<"\n\n\n\n\n\n";
			cout<<"\t\t\t\tWELCOME USER"<<endl;
			cout<<"\t\t\t\t********************\n\t\t\t\t1.LOGIN\n\t\t\t\t********************\n\t\t\t\t2.APPLY FOR NEW ACCOUNT\n\t\t\t\t********************\n\t\t\t\t3.BACK\n\t\t\t\t********************\n\t\t\t\t";
			cin>>logc;
			
			switch(logc)
			{
				case 1:
					system("CLS");
					userlog();
					break;
				case 2:
					system("CLS");
					newacc();
					break;
				case 3:
					system("CLS");
					return 0;
				default:
					system("CLS");
					cout<<"PLEASE SELECT A VALID OPTION"<<endl<<flush;
					system("PAUSE");
					system("CLS");
			}
		}while(logc!=3);
	}
	else if(i==2)
	{
		cout<<"\n\n\n\n\n\n";
		cout<<"\t\t\t\t********************\n\t\t\t\t";
		cout<<"WELCOME ADMINISTRATOR"<<endl;
		string uname,passwd,userid,password;
		fstream file;
		file.open("adminlogin/admin.txt");
		
		if(file.is_open())
		{
			getline(file,userid);
			getline(file,password);
			file.close();
			
			int i;
			
			for(i=0;i<3;i++)
			{
				cout<<"\t\t\t\t****************"<<endl;
				cout<<"\t\t\t\tENTER USERNAME :"<<endl;
				cout<<"\t\t\t\t----------------\n\t\t\t\t";
				cin>>uname;
				cout<<"\t\t\t\t****************"<<endl;
				cout<<"\t\t\t\tENTER PASSWORD :"<<endl;
				cout<<"\t\t\t\t----------------\n\t\t\t\t";
				cin>>passwd;				
			
				if(i<3 && uname==userid && passwd==password)
				{
					system("CLS");
					adminmenu();
					return 0;
				}
				else
				{
					cout<<"INVALID USERNAME OR PASSWORD"<<endl;
					cout<<"TRY AGAIN"<<endl<<flush;
					system("PAUSE");
					system("CLS");
				}
			}
			cout<<"YOU HAVE REACHED THE MAXIMUM ATTEMPTS"<<endl;
			cout<<"PLEASE RETURN TO LOGIN MENU"<<endl<<flush;
			system("PAUSE");
			system("CLS");
		}
		else
		{
			cout<<"SORRY THERE IS A PROBLEM IN SYSTEM"<<endl;
			cout<<"TRY AGAIN LATER"<<endl;
			system("PAUSE");
			system("CLS");
		}
		
	}
	return 0;
}

int userlog()
{
	//user login authentication function.
	string userid,passcode,authentication,uname,passwd;
	fstream file;
	
	cout<<"\n\n\n\n\n\n";
	cout<<"\t\t\t\t****************"<<endl;
	cout<<"\t\t\t\tENTER USERNAME :"<<endl;
	cout<<"\t\t\t\t----------------\n\t\t\t\t";
	cin>>uname;				
	
	string filenamelog="userlogin/"+uname+"log.txt";
	file.open(filenamelog.c_str());
	
	if(file.is_open())
	{
		getline(file, userid);
		getline(file, passcode);
		getline(file, authentication);
		
		file.close();
		
		if(authentication=="AUTHORIZED")
		{
			int i;
			for(i=0;i<3;i++)
			{
				cout<<"\t\t\t\t****************"<<endl;
				cout<<"\t\t\t\tENTER PASSWORD :"<<endl;
				cout<<"\t\t\t\t----------------\n\t\t\t\t";
				cin>>passwd;
				system("CLS");
				if(i<3 && uname==userid && passwd==passcode)
				{
					system("CLS");
					usermenu();
					return 0;
				}
				else
				{	
					cout<<"INVALID PASSWORD"<<endl;
					cout<<"TRY AGAIN"<<endl;
				}
			}
			cout<<"YOU HAVE REACHED MAXIMUM NUMBER OF ATTEMPTS"<<endl;
			cout<<"PRESS ANY KEY TO RETURN TO LOGIN MENU"<<endl<<flush;
			system("PAUSE");
			system("CLS");	
		}
		else
		{
			cout<<"LOOKS LIKE YOUR ACCOUNT HASN'T VERIFIED BY ADMIN"<<endl;
			cout<<"TRY AGAIN LATER"<<endl<<flush;
			system("PAUSE");
			system("CLS");
		}	
	}
	else
	{
		cout<<"YOUR ACCOUNT DOESN'T EXIST PLEASE TRY CREATING A NEW ACCOUNT"<<endl<<flush;
		system("PAUSE");
		system("CLS");
	}
	return 0;
}

int newacc()
{
	//new account creation function.
	string filenamelog,userid,passwd,fname,lname,phone,email,vmanufacturer,vtype,lnumber,pnumber,dob;
	bool exist=0;
	 
	cout<<"WELCOME USER\nCREATE NEW ACCOUNT HERE: "<<endl;
	while(exist!=1)
	{
		cout<<"ENTER A USERNAME(do not use any spaces in userid) :"<<endl;
		cin>>userid;
		filenamelog="userlogin/"+userid+"log.txt";
		ifstream myfile(filenamelog.c_str());
		if(!myfile)
		{
			exist=1;
		}	
		else
		{
			exist=0;
			system("CLS");
			cout<<"USERNAME ALREADY EXIST.Try different username"<<endl;
		}
	}
	
	cout<<"ENTER A PASSWORD(use a strong password) :"<<endl;
	cin>>passwd;
	fstream myfile;
	myfile.open(filenamelog.c_str(),fstream::out);
	myfile<<userid<<"\n";
	myfile<<passwd<<"\n";
	myfile<<"UNAUTHORIZED"<<"\n";
	
	myfile.close();
	
	system("CLS");
	cout<<"ENTER YOUR FIRST NAME :\n";
	cin>>fname;
	cout<<"ENTER YOUR LAST NAME :\n";
	cin>>lname;
	cout<<"ENTER YOUR DATE OF BIRTH(dd/mm/yyyy)(include / in your input):\n";
	cin>>dob;
	cout<<"ENTER YOUR EMAIL :"<<endl;
	cin>>email;
	do
	{
		cout<<"ENTER YOUR PHONE NUMBER(must be 10 numbers long) :"<<endl;
		cin>>phone;
		if((phone.size())!=10)
		{
			cout<<"ENTER VALID PHONE NUMBER"<<endl;
		}
	}while((phone.size())!=10);
	cout<<"ENTER YOUR VEHICLE MANUFACTURER :"<<endl;
	cin>>vmanufacturer;
	cout<<"ENTER YOUR DRIVING LICENSE NUMBER(without spaces) :"<<endl;
	cin>>lnumber;
	cout<<"ENTER YOUR NUMBER PLATE NUMBER(without spaces):"<<endl;
	cin>>pnumber;
	cout<<"ENTER YOUR VEHICLE TYPE :"<<endl;
	cin>>vtype;
	
	system("CLS");
	
	cout<<"ENTERED DATA IS :"<<endl;
	cout<<"FULL NAME : "<<fname<<" "<<lname<<endl;
	cout<<"DATE OF BIRTH : "<<dob<<endl;
	cout<<"EMAIL ID : "<<email<<endl;
	cout<<"PHONE NUMBER : "<<phone<<endl;
	cout<<"VEHICLE MANUFACTURER : "<<vmanufacturer<<endl;
	cout<<"DRIVING LICENSE NUMBER : "<<lnumber<<endl;
	cout<<"NUMBER PLATE NUMBER : "<<pnumber<<endl<<flush;
	cout<<"VEHICLE TYPE : "<<vtype<<endl;
	
	system("PAUSE");
	system("CLS");
	
	string filenameinfo="userinfo/"+userid+"info.txt";
	myfile.open(filenameinfo.c_str(),fstream::out);
	myfile<<fname<<" "<<lname<<"\n";
	myfile<<dob<<"\n";
	myfile<<email<<"\n";
	myfile<<phone<<"\n";
	myfile<<vmanufacturer<<"\n";
	myfile<<lnumber<<"\n";
	myfile<<pnumber<<"\n";
	myfile<<vtype<<"\n";
	myfile.close();
	
	myfile.open("adminlogin/adminfiles/userreq.txt",ios_base::app);
	myfile<<userid<<"\n";
	myfile.close();
	
	
	cout<<"YOUR REQUEST FOR NEW ACCOUNT HAS BEEN SENT TO ADMIN FOR APPROVAL"<<endl;
	cout<<"THANK YOU FOR CREATING ACCOUNT"<<endl;
	cout<<"PRESS ANY KEY TO RETURN"<<endl;
	system("PAUSE");
	system("CLS");
}

int usermenu()
{
	int ch;
	do{
		//user options from user menu.
		cout<<"\n\n\n\n\n\n";
		cout<<"\t\t\t\tUSER MENU"<<endl;
		cout<<"\t\t\t\t********************\n\t\t\t\t1.VIEW USER INFORMATION\n\t\t\t\t********************\n\t\t\t\t2.PAY TOLL VIA ACCOUNT\n\t\t\t\t********************\n\t\t\t\t3.TRANSACTION HISTORY\n\t\t\t\t********************\n\t\t\t\t4.BACK\n\t\t\t\t********************\n\t\t\t\t";
		cin>>ch;
		switch(ch)
		{
			case 1:
				system("CLS");
				infouser();
				break;
			case 2:
				system("CLS");
				accpay(1);
				break;
			case 3:
				system("CLS");
				transhistory(2);
				break;
			case 4:
				system("CLS");
				return 0;
			default:
				system("CLS");
				return 0;
		}
	}while(ch!=4);
	
}

int adminmenu()
{
	int ch;
	
	do{
		//admin options from admin menu
		cout<<"\n\n\n\n\n\n";
		cout<<"\t\t\t\tADMIN MENU"<<endl;
		cout<<"\t\t\t\t********************\n\t\t\t\t1.USER INFORMATION\n\t\t\t\t********************\n\t\t\t\t2.USER REQUESTS\n\t\t\t\t********************\n\t\t\t\t3.APPROVE REQUESTS\n\t\t\t\t********************\n\t\t\t\t4.TOLL PLAZA SYSTEM\n\t\t\t\t********************\n\t\t\t\t5.BACK\n\t\t\t\t";
		cin>>ch;
		switch(ch)
		{
			case 1:
				system("CLS");
				infouser();
				break;
			case 2:
				system("CLS");
				userreq();
				break;
			case 3:
				system("CLS");
				approve();
				break;
			case 4:
				system("CLS");
				tollsys();
				break;
			case 5:
				system("CLS");
				return 0;
			default:
				system("CLS");
				return 0;
		}
	}while(ch!=5);
}

int infouser()
{
	//function for displaying user information.
	string userid;
	
	cout<<"ENTER USERID"<<endl;
	cin>>userid;
	
	fstream file;
	string line;
	string filename="userinfo/"+userid+"info.txt";
	file.open(filename.c_str(),fstream::in);
	
	if(file.is_open())
	{
		system("CLS");
		cout<<"DATA FOR USERID "<<userid<<" IS :"<<endl;
		getline(file,line);
		cout<<"FULL NAME : "<<line<<endl;
		getline(file,line);
		cout<<"DATE OF BIRTH : "<<line<<endl;
		getline(file,line);
		cout<<"EMAIL ID : "<<line<<endl;
		getline(file,line);
		cout<<"PHONE NUMBER : "<<line<<endl;
		getline(file,line);
		cout<<"VEHICLE MANUFACTURER : "<<line<<endl;
		getline(file,line);
		cout<<"DRIVING LICENSE NUMBER : "<<line<<endl;
		getline(file,line);
		cout<<"NUMBER PLATE NUMBER : "<<line<<endl;
		getline(file,line);
		cout<<"VEHICLE TYPE : "<<line<<endl;
		file.close();
	}
	else
	{
		cout<<"DATA NOT FOUND"<<endl;
	}
	system("PAUSE");
	system("CLS");
}

int userreq()
{
	//function for displaying user requests.
	cout<<"USER REQUESTS FOR NEW ACCOUNT"<<endl;
	int i;
	
	fstream file;
	
	file.open("adminlogin/adminfiles/userreq.txt",fstream::in);
	
	if(file.is_open())
	{
		string line;
		while(!file.eof())
		{
			getline(file,line);
			cout<<line<<endl;
		}
	}
	system("PAUSE");
	system("CLS");
	return 0;
}

int approve()
{
	system("CLS");
	string userid;
	fstream file1;
	cout<<"ENTER USERID YOU WANT TO VERIFY :"<<endl;
	cin>>userid;
	string filename="userlogin/"+userid+"log.txt";
	file1.open(filename.c_str());
	if(file1.is_open())
	{
		char ch;
		cout<<"ARE YOU SURE YOU WANT TO VERIFY :(y/n)"<<userid<<endl;
		cin>>ch;
		if(ch=='y' || ch=='Y')
		{
			int i=0;
			fstream file2,file3,file4;
			string copy;
			file2.open("userlogin/temp.txt",fstream::out);
			while(getline(file1,copy) && !file1.eof() && i<3)
			{
				if(i==2)
				{
					copy.replace(0,2,"");
				}
				file2<<copy<<endl;
				i++;
			}
			file1.close();
			file2.close();
			remove(filename.c_str());
			rename("userlogin/temp.txt",filename.c_str());
			cout<<"USER VERIFIED SUCCESSFULLY"<<endl;
			
			file3.open("adminlogin/adminfiles/userreq.txt");
			file2.open("adminlogin/adminfiles/temp.txt",fstream::out);
			i=0;
			string del=userid;
			while(getline(file3,copy) && !file3.eof() && i<3)
			{
				if(copy==userid)
				{
					continue;
				}
				file2<<copy<<endl;
				i++;
			}
			file3.close();
			file2.close();
			remove("adminlogin/adminfiles/userreq.txt");
			rename("adminlogin/adminfiles/temp.txt","adminlogin/adminfiles/userreq.txt");
			
			filename="useraccinfo/"+userid+"acc.txt";
			file4.open(filename.c_str(),fstream::out);
			file4<<"0"<<"\n";
			file4.close();
		}
		else
		{
			cout<<"THANK YOU"<<endl;	
		}	
	}
	else
	{
		cout<<"USER NOT FOUND"<<endl;
	}
	system("PAUSE");
	system("CLS");
}

int accpay(int i)
{
	//function for payment of toll.
	if(i==1 || i==2)
	{
		int j=0;
		string userid,passwd;
		string us,ps,line;
		fstream file,file1,infofile;
	
		cout<<"ENTER YOUR USERID"<<endl;
		cin>>userid;
		
		string userfile="userlogin/"+userid+"log.txt";
		file.open(userfile.c_str());
		getline(file,us);
		getline(file,ps);
		file.close();
		
		string filename="userinfo/"+userid+"info.txt";
		file.open(filename.c_str(),fstream::in);
		while(!file.eof() && j<8)
		{
			getline(file,line);
			j++;
		}
		file.close();
		
		string filename1="useraccinfo/"+userid+"acc.txt";
		file1.open(filename1.c_str());
		
		if(file1.is_open())
		{
			if(i==1)
			{
				char ch;
				int toll=0;
				int a;
				
				ofstream file2,file3;
				string filename2="useraccinfo/"+userid+"history.txt";
				file2.open(filename2.c_str(),ios_base::app);
				file3.open("adminlogin/adminfiles/tolltransactions.txt",ios_base::app);
				file1>>a;
				file1.close();
				cout<<"YOUR CURRENT ACCOUNT BALANCE IS : Rs."<<a<<endl;
					if(line=="car" || line=="CAR")
					{
						toll=40;
						cout<<"TOLL AMOUNT FOR CAR : Rs.40"<<"\n";
					}
					else if(line=="lcv" || line=="LCV")
					{
						toll=65;
						cout<<"TOLL AMOUNT FOR LCV :  Rs.65"<<"\n";
					}
					else if(line=="tcv" || line=="TCV")
					{
						toll=20;
						cout<<"TOLL AMOUNT TCV : Rs.20"<<"\n";
					}
					else if(line=="truck" || line=="TRUCK" || line=="bus" || line=="BUS")
					{
						toll=90;
						cout<<"TOLL AMOUNT  : Rs.90"<<"\n";
					}
					else if(line=="truck4" || line=="TRUCK4")
					{ 
						toll=110;
						cout<<"TOLL AMOUNT : Rs.110"<<"\n";	
					}
					else if(line=="truck7" || line=="TRUCK7")
					{
						toll=130;
						cout<<"TOLL AMOUNT : Rs.130"<<"\n";	
					}
					else if(line=="HCM" || line=="hcm")
					{
						toll=270;
						cout<<"TOLL AMOUNT : Rs.270"<<"\n";	
					}
					else
					{
						cout<<"CANNOT PROCESS YOUR REQUEST"<<endl;
						return 0;
					}
				if(a>=100 && (a-100)>=toll)
				{
					cout<<"ARE YOU SURE YOU WANT TO PAY TOLL?(y/n)"<<endl;
					cin>>ch;
					cout<<"ENTER YOUR PASSWORD TO CONFIRM"<<endl;
					cin>>passwd;					
					if((ch=='y' || ch=='Y') && passwd==ps)
					{
						a=a-toll;
						file1.open(filename1.c_str(),ios::out | ios::trunc);
						file1<<a;
						time_t my_time = time(NULL);
				       	string t=ctime(&my_time);	
						file2<<t<<"\t"<<userid<<"\t"<<"-"<<toll<<"\n";
						file3<<t<<"\t"<<userid<<"\t"<<toll<<"\n";
						cout<<"TRANSACTION SUCCESSFUL"<<endl;
						cout<<"REMAINING BALANCE IS : "<<a<<endl;
					}
					else
					{
						cout<<"THANKS YOU!!"<<endl;
					}
				}
				else
				{
					cout<<"ACCOUNT BALANCE INSUFFICIENT FOR TRANSACTION"<<endl;
				}
				file1.close();
				file2.close();
				file3.close();
			}
			else if(i==2)
			{
				int a,b;
				
				fstream file1;
				ofstream file2,file3;
				string filename1="useraccinfo/"+userid+"acc.txt";
				string filename2="useraccinfo/"+userid+"history.txt";
				
				file1.open(filename1.c_str());
				file2.open(filename2.c_str(),ios_base::app);
				file1>>a;
				file1.close();
				cout<<"YOUR CURRENT ACCOUNT BALANCE IS : Rs."<<a<<endl;
				cout<<"ENTER AMOUNT YOU WANT TO ADD TO YOUR ACCOUNT"<<endl;
				cout<<"Rs.";
				cin>>b;
				a=a+b;
				file1.open(filename1.c_str(),ios::out | ios::trunc);
				file1<<a;
				time_t my_time = time(NULL);
		       	string t=ctime(&my_time);	
				file2<<t<<"\t"<<userid<<"\t"<<"+"<<b<<"\n";
				cout<<"AMOUNT ADDED SUCCESSFUL"<<endl;
				cout<<"NEW ACCOUNT BALANCE IS : Rs."<<a<<endl;
				
				file1.close();
				file2.close();
			}
		}
		else
		{	
			cout<<"USER NOT FOUND"<<endl;
		}	
	}
	else if(i==3)
	{
		string number,type;
		int toll=0;
		cout<<"OFFLINE PAYMENT GATEWAY"<<endl;
		cout<<"VEHICLE NUMBER :"<<endl;
		cin>>number;
		cout<<"VEHICLE TYPE :"<<endl;
		cin>>type;
		
		time_t my_time = time(NULL);
		string t1,t=ctime(&my_time);
		t1=t;	
		t.erase(remove(t.begin(), t.end(),'\n'), t.end());
		t.erase(remove(t.begin(), t.end(),':'), t.end());
		t.erase(remove(t.begin(), t.end(),' '), t.end());
		fstream file,file1;
		string filename="reciepts/"+number+t+"rct.txt";
		file.open(filename.c_str(),fstream::out);
		file<<"\t\t\t"<<"XYZ TOLL PLAZA"<<"\n\n";
		file<<"DATE TIME : "<<t1<<"\n";
		file<<"VEHICLE TYPE :"<<type<<"\t\t";
		file<<"VEHICLE NUMBER :"<<number<<"\n";
		
		if(type=="car" || type=="CAR")
		{
			toll=40;
			file<<"TOLL AMOUNT AT :"<<t<<"  Rs.40"<<"\n";
			file<<"CASH RECIEVED : Rs.40 ONLY"<<"\n";
			file<<"FOURTY ONLY"<<"\n";	
		}
		else if(type=="lcv" || type=="LCV")
		{
			toll=65;
			file<<"TOLL AMOUNT AT :"<<t<<"  Rs.65"<<"\n";
			file<<"CASH RECIEVED : Rs.65 ONLY"<<"\n";
			file<<"SIXTY FIVE ONLY"<<"\n";	
		}
		else if(type=="tcv" || type=="TCV")
		{
			toll=20;
			file<<"TOLL AMOUNT AT :"<<t<<"  Rs.20"<<"\n";
			file<<"CASH RECIEVED : Rs.20 ONLY"<<"\n";
			file<<"TWENTY ONLY"<<"\n";	
		}
		else if(type=="truck" || type=="TRUCK" || type=="bus" || type=="BUS")
		{
			toll=90;
			file<<"TOLL AMOUNT AT :"<<t<<"  Rs.90"<<"\n";
			file<<"CASH RECIEVED : Rs.90 ONLY"<<"\n";
			file<<"NINETY ONLY"<<"\n";	
		}
		else if(type=="truck4" || type=="TRUCK4")
		{ 
			toll=110;
			file<<"TOLL AMOUNT AT :"<<t<<"  Rs.110"<<"\n";
			file<<"CASH RECIEVED : Rs.110 ONLY"<<"\n";
			file<<"ONE HUNDRED AND TEN ONLY"<<"\n";	
		}
		else if(type=="truck7" || type=="TRUCK7")
		{
			toll=130;
			file<<"TOLL AMOUNT AT :"<<t<<"  Rs.130"<<"\n";
			file<<"CASH RECIEVED : Rs.130 ONLY"<<"\n";
			file<<"ONE HUNDRED AND THIRTY ONLY"<<"\n";	
		}
		else if(type=="HCM" || type=="hcm")
		{
			toll=270;
			file<<"TOLL AMOUNT AT :"<<t<<"  Rs.270"<<"\n";
			file<<"CASH RECIEVED : Rs.270 ONLY"<<"\n";
			file<<"TWO HUNDRED AND SEVENTY ONLY"<<"\n";	
		}
		
		file<<"\n\n\t\t\t"<<"VISIT AGAIN!!!!!"<<"\n";
		file<<"\t*****NATIONAL HIGHWAY AUTHORITY OF INDIA*****"<<"\n";
		file.close();
		file1.open("adminlogin/adminfiles/tolltransactions.txt",ios_base::app);
		file1<<"\n"<<t1<<"\t"<<number<<"\t"<<toll<<"\n";
		file1.close();
		cout<<"GENERATING RECIEPT....."<<endl;
		Sleep(3000);
		//uncomment below lines if you are using unix or linux.
		//unsigned int microsecond = 100000;
		//usleep(3 * microsecond);
		cout<<"PAYMENT SUCCESSFUL"<<endl;
	} 
	system("PAUSE");
	system("CLS");
}

int transhistory(int i)
{
	//function for showing transaction history.
	if(i==1)
	{
		system("CLS");
		fstream file;
		string line;
		file.open("adminlogin/adminfiles/tolltransactions.txt");
		if(file.is_open())
		{
			cout<<"TOLL TRANSACTION HISTORY"<<endl;
			while(!file.eof())
			{
				getline(file,line);
				cout<<line<<endl;
			}
		}
		else
		{
			cout<<"WE CAN'T PROCESS YOUR REQUEST AT THIS TIME"<<endl;
			cout<<"PLEASE TRY AGAIN LATER"<<endl;
		}
		file.close();
	}
	else if(i==2)
	{
		string userid,line,filename;
		fstream file;
		cout<<"ENTER YOUR USERID TO CONFIRM"<<endl;
		cin>>userid;
		
		filename="useraccinfo/"+userid+"history.txt";
		file.open(filename.c_str());
		
		if(file.is_open())
		{
			system("CLS");
			cout<<"TOLL TRANSACTION HISTORY FOR "<<userid<<endl;
			while(!file.eof())
			{
				getline(file,line);
				cout<<line<<endl;
			}
		}
		else
		{
			cout<<"WE CAN'T PROCESS YOUR REQUEST AT THIS TIME"<<endl;
			cout<<"PLEASE TRY AGAIN LATER"<<endl;
		}
		file.close();
	}
	system("PAUSE");
	system("CLS");
	return 0;
}

int tollsys()
{
	int ch;
	do{
		//options for toll plaza
		cout<<"\n\n\n\n\n\n";
		cout<<"\t\t\t\tTOLL PLAZA SYSTEM"<<endl;
		cout<<"\t\t\t\t********************\n\t\t\t\t1.TOLL PAYMENT VIA ACCOUNT\n\t\t\t\t********************\n\t\t\t\t2.CASH PAYMENT\n\t\t\t\t********************\n\t\t\t\t3.ADD MONEY TO THE WALLET\n\t\t\t\t********************\n\t\t\t\t4.VIEW ALL PAYMENT HISTORY\n\t\t\t\t********************\n\t\t\t\t5.BACK\n\t\t\t\t";	
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				system("CLS");
				accpay(1);
				break;
			case 2:
				system("CLS");
				accpay(3);
				break;
			case 3:
				system("CLS");
				accpay(2);
				break;
			case 4:
				system("CLS");
				transhistory(1);
				break;
			case 5:
				system("CLS");
				return 0;
			default:
				return 0;
		}
	}while(ch!=5);
	return 0;
}
