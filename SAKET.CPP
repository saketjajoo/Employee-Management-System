#include<iomanip.h>
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<dos.h>
#include<string.h>
#include<stdlib.h>
#include<fstream.h>

void main();

class employee
{
	int empno;
	int age,experience,dd, mm, yy;
	char grade[2],name[30],quali[15],desig[12];
	double salary;
	int deptno;
	int ddb, mmb, yyb;
	int ddj,mmj,yyj;

	public:

	int getno()
	{
		return empno;
	}

	int record_no();
	void new_employee();
	void modify();
	void display();
	void display_month_sal();
	void display_list();
	void delete_record();
}e;

int employee::record_no()
{
	clrscr();
	fstream file;
	file.open("employeedata.txt",ios::in);
	file.seekg(0,ios::beg);
	int count=0;
	while(!file.eof())
	{
		file.read((char *)&e,sizeof(employee));
		if(empno!=0)
		count++;
		else
		{
			count=1;
			return count;
			break;
		}
	}
	file.close();
	return count;
}

void employee::new_employee()
{
	clrscr();
	empno = record_no();
	int d1, m1, y1;
	struct date d;
	getdate(&d);
	d1 = d.da_day;
	m1 = d.da_mon;
	y1 = d.da_year;
	gotoxy(1,2);
	cout<<"Date :    /     /";
	gotoxy(8,2);cout<<d1;
	gotoxy(14,2);cout<<m1;
	gotoxy(19,2);cout<<y1;
	gotoxy(20,6);
	cout<<" N e w     E m p l o y e e     S c r e e n";
	gotoxy(1,9);
	cout<<"Employee Number   : "<<empno;
	cout<<"\n\nName              : ";
	cout<<"\nDesignation       : ";
	cout<<"\nQualification     : ";
	cout<<"\nGrade             : ";
	cout<<"\nExperience        : ";
	cout<<"\nAge               : ";
	cout<<"\nSalary            : ";
	cout<<"\nDate of Birth     :    /    / ";
	cout<<"\nDate of Joining   :    /    / ";
	cout<<"\nDepartment Number : ";
	gotoxy(21,11);gets(name);
	gotoxy(21,12);gets(desig);
	gotoxy(21,13);gets(quali);
	gotoxy(21,14);gets(grade);
	gotoxy(21,15);cin>>experience;
	gotoxy(21,16);cin>>age;
	gotoxy(21,17);cin>>salary;
	gotoxy(22,18);cin>>ddb;gotoxy(26,18);cin>>mmb;gotoxy(30,18);cin>>yyb;
	gotoxy(22,19);cin>>ddj;gotoxy(26,19);cin>>mmj;gotoxy(30,19);cin>>yyj;
	gotoxy(21,20);cin>>deptno;
	delay(2000);
	closegraph();
}

void employee::modify()
{
	clrscr();
	char t_name[30],t_grade[2],t_quali[20],t_desig[20];
	int t_experience,t_salary,t_deptno,t_ddb,t_mmb,t_yyb;
	int t_ddj,t_mmj,t_yyj;
	cout<<"\n\n Employee Number : "<<empno;
	cout<<"\nEnter the Name : ";gets(t_name);
	cout<<"\n Enter the Grade : ";gets(t_grade);
	cout<<"\n Enter the Qualification : ";gets(t_quali);
	cout<<"\n Enter the Experience : ";cin>>t_experience;
	cout<<"\n Enter the Designation : ";gets(t_desig);
	cout<<"\n Enter the Salary : ";cin>>t_salary;
	cout<<"\n Enter the Dept No : ";cin>>t_deptno;
	cout<<"\n Enter the Date of Birth   :  /    / ";
	gotoxy(29,18);cin>>t_ddb;gotoxy(31,18);cin>>t_mmb;gotoxy(34,18);cin>>t_yyb;
	cout<<"\n\n Enter the Date of Joining :  /   / ";
	gotoxy(29,20);cin>>t_ddj;gotoxy(31,20);cin>>t_mmj;gotoxy(34,20);cin>>t_yyj;

	strcpy(name,t_name);
	strcpy(grade,t_grade);
	strcpy(quali,t_quali);
	strcpy(desig,t_desig);
	experience=t_experience;  salary=t_salary;  deptno=t_deptno;
	ddb=t_ddb;  mmb=t_mmb;  yyb=t_yyb;
	ddj=t_ddj;  mmj=t_mmj;  yyj=t_yyj;
	cout<<"\n\n Record is being modified...";
	cout<<"\n Please Wait...";
	delay(2000);
}

void employee::display()
{
	clrscr();
	cout<<"\n\nEmployee Number   : "<<empno;
	cout<<"\n\nName              : "<<name;
	cout<<"\nDesignation       : "<<desig;
	cout<<"\nQualification     : "<<quali;
	cout<<"\nGrade             : "<<grade;
	cout<<"\nExperience        : "<<experience;
	cout<<"\nAge               : "<<age;
	cout<<"\nSalary            : "<<salary;
	cout<<"\nDate of Birth     : "<<ddb<<" / "<<mmb<<" / "<<yyb;
	cout<<"\nDate of Joining   : "<<ddj<<" / "<<mmj<<" / "<<yyj;
	cout<<"\nDepartment Number : "<<deptno;
	getch();
}

void employee::display_list()
{
	cout<<"  "<<empno<<"\t\t\t\t\t\t\t   "<<name<<"\n";
}

void employee::display_month_sal()
{
	clrscr();
	char t_acc[10];
	char *cmonth;
	int j;
	int t, t_emp_id;
	gotoxy(71, 1);
	cout << "<0>=Exit";
	gotoxy(30, 3);
	cout << "Salary Slip";
	gotoxy(30, 4);
	cout << "===========";
	int d1, m1, y1;
	struct date d;
	getdate(&d);
	d1 = d.da_day;
	m1 = d.da_mon;
	y1 = d.da_year;
	gotoxy(10, 5);
	cout << "Employee No : "<<empno;
	switch (m1)
	{
		case 1  : strcpy( cmonth, "January"  );break;
		case 2  : strcpy( cmonth, "February" ); break;
		case 3  : strcpy( cmonth, "March"    ); break;
		case 4  : strcpy( cmonth, "April"    ); break;
		case 5  : strcpy( cmonth, "May"      ); break;
		case 6  : strcpy( cmonth, "June"     ); break;
		case 7  : strcpy( cmonth, "July"     ); break;
		case 8  : strcpy( cmonth, "August"   ); break;
		case 9  : strcpy( cmonth, "September"); break;
		case 10 : strcpy( cmonth, "October"  ); break;
		case 11 : strcpy( cmonth, "November"); break;
		case 12 : strcpy( cmonth, "December" ); break;
	}
	gotoxy(45,5);
	cout<<cmonth;
	gotoxy(8,6);
	for (int i=0;i<=64;i++)
	cout << "=";
	gotoxy(30, 7);
	cout << "Date of Joining : " << ddj << "/" << mmj << "/" << yyj;
	gotoxy(30, 8);
	cout << "Designation : " <<desig;
	gotoxy(30, 9);
	cout << "Qualification : " <<quali;
	gotoxy(30,10);
	cout << "Department No. : " <<deptno;
	gotoxy(30, 11);
	cout << "Grade : " <<grade;
	delay(2);
	gotoxy(8,12);
	for (i = 0; i <= 64; i++)
	cout << "-";
	gotoxy(10,13);
	cout << "Salary";
	gotoxy(35,13);
	cout<<"Earnings";
	gotoxy(62,13);
	cout << "Deduction";
	gotoxy(8,14);
	for (i = 0; i <= 64; i++)
	cout << "-";
	float EPF = 0.0;
	float DA = 0.0;
	float ESI = 0.0;
	float HRA = 0.0;
	float CANTEEN = 0.0;
	float CONV = 0.0;
	float ANN_GROSS = 0.0;
	float ITAX = 0.0;
	float NET_INCOME = 0.0;
	float TOTAL_EARN = 0.0;
	float TOTAL_DEDU = 0.0;
	float PFTAX = 0.0;
	float TAXABLE = 0.0;
	if (salary >= 2500 && salary <= 3000)
	{
		DA = salary * 0.9;
		HRA = salary * 0.2;
		CONV = salary * 0.1;
	}
	else if (salary >= 3001 && salary <= 4000)
	{
		DA = salary * 0.12;
		HRA = salary * 0.3;
		CONV = salary * 0.15;
	}
	else if (salary >= 4001 && salary <= 5000)
	{
		DA = salary * 0.14;
		HRA = salary * 0.35;
		CONV = salary * 0.2;
	}
	else if (salary >= 5001)
	{
		DA = salary * 0.16;
		HRA = salary * 0.4;
		CONV = salary * 0.25;
	}
	TOTAL_EARN = salary + DA + HRA + CONV;
	ANN_GROSS = TOTAL_EARN * 12;
	EPF = (salary+DA) * 0.12;
	ESI = salary * 0.07;
	CANTEEN = 350;
	PFTAX = ((salary + DA) * 0.2) * 12;
	ANN_GROSS = ANN_GROSS + PFTAX;
	if (ANN_GROSS <= 60000)
	ANN_GROSS = 40000 - 20000;
	else
	ANN_GROSS = ANN_GROSS - 20000;
	if (ANN_GROSS > 40000)
	TAXABLE = ANN_GROSS - 40000;
	else
	TAXABLE = 0;
	if (TAXABLE <= 20000)
	ITAX = TAXABLE * 0.1;
	else if (TAXABLE > 20000 && TAXABLE <= 110000)
	ITAX = 2000 + ((TAXABLE-20000) * 0.2);
	else if (TAXABLE > 110000)
	ITAX = 20000 + ((TAXABLE-110000) * 0.3);
	ITAX = ITAX / 12;
	TOTAL_DEDU = EPF + ESI + CANTEEN + ITAX;
	NET_INCOME = TOTAL_EARN - TOTAL_DEDU;
	gotoxy(11, 15);
	cout << "Basic:" ;
	gotoxy(22, 15);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< salary;
	gotoxy(35, 15);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< salary;
	gotoxy(50, 15);
	cout << "E.P.F.:" ;
	gotoxy(63, 15);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< EPF ;
	gotoxy(11, 16);
	cout << "D.A.:" ;
	gotoxy(22, 16);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< DA;
	gotoxy(35, 16);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< DA;
	gotoxy(50, 16);
	cout << "E.S.I.:";
	gotoxy(63, 16);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< ESI;
	gotoxy(11, 17);
	cout << "H.R.A.:" ;
	gotoxy(22, 17);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< HRA;
	gotoxy(35, 17);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< HRA;
	gotoxy(50, 17);
	cout << "CANTEEN:" ;
	gotoxy(63, 17);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< CANTEEN ;
	gotoxy(11, 18);
	cout << "CONV.:" ;
	gotoxy(22, 18);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< CONV;
	gotoxy(35, 18);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< CONV;
	gotoxy(50, 18);
	cout << "INCOME TAX:" ;
	gotoxy(63, 18);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< ITAX ;
	gotoxy(8, 19);
	for (i = 0; i <= 64; i++)
	cout << "-";
	gotoxy(11, 20);
	cout << "Total Earnings: ";
	gotoxy(34, 20);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< TOTAL_EARN;
	gotoxy(48, 20);
	cout << "Total Deduct: ";
	gotoxy(63, 20);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< TOTAL_DEDU;
	gotoxy(8, 21);
	for (i = 0; i <= 64; i++)
	cout << "=";
	gotoxy(11, 22);
	cout << "Net Pay: ";
	gotoxy(34, 22);
	cout << setw(15)<< setprecision(2)<< setiosflags(ios::left)<< setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< NET_INCOME;
	gotoxy(10, 24);
	cout << "Press any key to Continue ...";
	getch();
}


void add_employee()
{
	clrscr();
	employee e;
	fstream fout;
	fout.open("employeedata.txt",ios::app);
	e.new_employee();
	fout.write((char *)&e,sizeof(employee));
	cout<<"\n\n Record successfully added !!!";
	getch();
	fout.close();
}

void display_employee(int no)
{
	clrscr();
	employee e;
	int flag=0;
	fstream fin;
	fin.open("employeedata.txt",ios::in);
	while(!fin.eof())
	{
		fin.read((char *)&e,sizeof(employee));
		if(no==e.getno())
		{
			flag=1;
			e.display();
		}
	}
	if(flag==0)
	{
		cout<<"\n\n Employee not found";
		getch();
	}
}

void month_salary_e(int no)
{
	int flag=0;
	employee e;
	fstream fin("employeedata.txt",ios::in);
	while(!fin.eof())
	{
		fin.read((char *)&e,sizeof(employee));
		if(no==e.getno())
		{
			clrscr();
			cout<<"Record is found.\n\n";
			e.display_month_sal();
			flag=1;
			main();
		}
	}
	if(flag==0)
	{
		cout<<"\n\n Employee not found";
		getch();
	}
	fin.close();
}

void emp_display()
{
	clrscr();
	employee e;
	cout<<"\nEmployee Number\t\t\t\t\t\tEmployee Name\n";
	fstream fin;
	fin.open("employeedata.txt",ios::in);
	while(!fin.eof())
	{
		fin.read((char *)&e,sizeof(employee));
		e.display_list();
	}
	fin.close();
	getch();
}

void modify_employee(int no)
{
	clrscr();
	employee e;
	int flag=0;
	char ch;
	fstream fin;
	fin.open("employeedata.txt",ios::in | ios::out);
	while(!fin.eof())
	{
		int pos=fin.tellg();
		fin.read((char *)&e,sizeof(employee));
		if(no==e.getno())
		{
			flag=1;
			display_employee(no);
			cout<<"\n\n\n\n";
			cout<<"Do you want to modify this record ? (y/n) : ";
			cin>>ch;
			if(ch=='y' || ch=='Y')
			{
				e.modify();
				fin.seekg(pos,ios::beg);
				fin.write((char *)&e,sizeof(employee));
				cout<<"\n\n Record Modified Successfully !!!";
				getch();
				//main();
			}
			else
			{
				main();
			}
		}
	}
	if(flag==0)
	{
		cout<<"\n\n Employee not found.";
		getch();
	}
	fin.close();
	getch();
}

void delete_employee(int no)
{
	clrscr();
	employee e;
	fstream fin;
	fstream fout;
	fin.open("employeedata.txt",ios::in);
	fout.open("temp.txt",ios::app);
	int flag=0;
	while(!fin.eof())
	{
		fin.read((char *)&e,sizeof(employee));
		if(no==e.getno())
		flag=1;
		else
		fout.write((char *)&e,sizeof(employee));
	}
	fout.close();
	fin.close();
	if(flag==1)
	{
		remove("employeedata.txt");
		rename("temp.txt","employeedata.txt");
		cout<<"\n\n Employee deleted successfully !!!";
	}
	else
	{
		cout<<"\n\n Employee not found.";
		getch();
	}
}

void main()
{
	employee e;
	int choice,no;
	clrscr();
	gotoxy(10,5);cout<<"1. New Employee.";
	gotoxy(10,7);cout<<"2. Modify Employee's Record.";
	gotoxy(10,9);cout<<"3. Delete Employee's Record.";
	gotoxy(10,11);cout<<"4. Display Employee's Record.";
	gotoxy(10,13);cout<<"5. Display Employee's Monthly Salary.";
	gotoxy(10,15);cout<<"6. Display Employee List.";
	gotoxy(10,17);cout<<"7. EXIT";
	gotoxy(10,21);cout<<"Enter your choice : ";
	gotoxy(32,21);cin>>choice;
	switch(choice)
	{
		case 1:
		add_employee();
		main();
		break;

		case 2:
		clrscr();
		cout<<"\n\nEnter the employee number : ";
		cin>>no;
		modify_employee(no);
		main();
		break;

		case 3:
		clrscr();
		cout<<"\n\nEnter the employee number : ";
		cin>>no;
		delete_employee(no);
		main();
		break;

		case 4:
		clrscr();
		cout<<"\n\nEnter the employee number for display : ";
		cin>>no;
		display_employee(no);
		main();
		break;

		case 5:
		clrscr();
		cout<<"\n\nEnter the employee number : ";
		cin>>no;
		month_salary_e(no);
		main();
		break;

		case 6:
		emp_display();
		main();
		break;

		case 7:
		exit(0);

		default:
		cout<<"\n\n You have entered the incorrect choice.";
		main();
	}
}