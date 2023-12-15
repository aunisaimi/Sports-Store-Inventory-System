#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <mysql.h> //for sql
#include<chrono> //for time and date
#include <fstream>

CONSOLE_FONT_INFOEX cfi; //global declaration

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
//taskkill /F /IM SportStore.exe

using namespace std;


void Login();
void Register();
void AdminMenu();
void UserAuthentication();


void ViewItem();
void InsertItem();
void OrderItem();
void DeleteItem();
void UpdateItem();
void OrderList();
void ViewOrderList();
void SearchItem();
void ViewOrderItem();
void OrderMenu();

void report();

void Inventory();
void ViewInventory();
void InventoryMenu();
void UpdateInventory();
void DeleteInventory();
void SearchInventory();



void SupplierMenu();
void RegisterSupplier();
void LoginSupplier();
void SuppOrderMenu();
void SuppViewOrder();
void SuppViewOrderList();
void SuppViewItem();

int qstate;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;


string UserID;
string UserNAME;
string SuppID;
string ItemID;
string InventoryID;
string OrderID;   
string OrderItemID; 

int sbyear, sbmonth, sbday;
string dyear, dmonth, dday, date;

class db_response {
public:
	static void ConnectionFunction() {
		conn = mysql_init(0);
		if (conn)
			cout << "Database Connected" << endl; 
		else
			cout << "Database failed to connect" << endl;
		conn = mysql_real_connect(conn, "localhost", "root", "", "sport_inventory", 3306, NULL, 0);

		if (conn)
			cout << "Database connected to MYSQL" << endl; 
		else
			cout << "Database failed to connect to MYSQL" << endl;
	}
};

int main() {
	system("cls");
	db_response::ConnectionFunction();


	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   
	cfi.dwFontSize.Y = 17;                  
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas"); 
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);


	


	int userchoice;


	cout << "\n\t\t\t\t\t\t\t\t" <<__DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" <<__TIME__ << endl;

	SetConsoleTextAttribute(h, 11);

	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tONI SPORTS STORE CENTER \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tWELCOME TO OUR STORE" << endl;

	cout << "\n\t\t\t\t\t\t\t\tPlease select Admin or Supplier --->\n" << endl;
	cout << "\t\t\t\t\t\t\t\t[1]. Admin" << endl;
	cout << "\t\t\t\t\t\t\t\t[2]. Supplier" << endl;
	cout << "\t\t\t\t\t\t\t\t[3]. Exit" << endl;

	cout << endl;

	cout << "\n\t\t\t\t\t\t\t\t Choose: ";
	cin >> userchoice;

	system("cls");

	if (userchoice == 1)
	{
		UserAuthentication();
	}

	else if (userchoice == 2)
	{
		LoginSupplier();
	}

	else
	{ 
		
		cout << "\t\t\t\t\t\t\t Exiting the programm . . . ";
		exit(0);
	}
	
	
}


void UserAuthentication()
{
	system("cls");
	db_response::ConnectionFunction();

	int menu;
	
	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;

	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tONI'S SPORTS STORE CENTER \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [1]. LOGIN \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [2]. REGISTER \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [3]. EXIT \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;



	cout << endl;
	cout << "\t\t\t\t\t\tChoose: ";
	cin >> menu;

	switch (menu) {

	case 1:
		Login();
		break;
	case 2:
		Register();
		break;

	case 3:
		cout << "\t\t\t\t\tExiting the menu..." << endl;
		main();

	default:
		cout << "\t\t\t\t\t Wrong input!" << endl;
		cout << "\t\t\t\t\t Please choose between 1 to 3. Press any key to continue . . ." << endl;
		char x;
		cin >> x;

		_getch();
		system("cls");
		UserAuthentication();
		break;
	}

}


void Register()
{

	system("cls");
	string name, phone, age, username, password;

	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;

	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tONI'S SPORTS CENTER \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t    ADMIN REGISTRATION" << endl;

	cout << "\n\t\t\t\t\t\t\t\t Enter name: ";
	cin.ignore(1, '\n');
	getline(cin, name);
	cout << "\t\t\t\t\t\t\t\t Enter phone number: ";
	getline(cin, phone);
	cout << "\t\t\t\t\t\t\t\t Enter your age: ";
	getline(cin, age);
	cout << "\t\t\t\t\t\t\t\t Enter username you want to use: ";
	getline(cin, username);
	cout << "\t\t\t\t\t\t\t\t Enter password: ";
	getline(cin, password);


	if (password.length() != 5)
	{
		cout << "\n";
		cout << "\n\t\t\t\t\t\t\t\t Invalid length of password (Enter Only 5 character)" << endl;
		cout << "\t\t\t\t\t\t\t\t Press Enter to Try Again...";
		_getch();
		Register();

	}


	string checkUser_query = "select * from staff where username = '" + username + "'";
	const char* cu = checkUser_query.c_str();
	qstate = mysql_query(conn, cu);

	if (!qstate)
	{
		res = mysql_store_result(conn);
		if (res->row_count == 1)
		{
			cout << "\n\t\t\t\t\t\t\t\t Username already exist. Please Try Again." << endl;
			_getch();
			Register();

		}
		else
		{
			string insertCustomer_query = "insert into staff (name,contact_no,age,username,password)values ('" + name + "','" + phone + "','" + age + "','" + username + "','" + password + "')";
			const char* q = insertCustomer_query.c_str();
			qstate = mysql_query(conn, q);

			if (!qstate)
			{
				cout << endl << "\t\t\t\t\t You have been registered as admin! Press ENTER to proceed . . .";
				_getch();
				main();
			}
			else
			{
				cout << "\t\t\t\t\t\t\t\t Query Execution Detected!" << mysql_errno(conn) << endl;
			}
		}
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t Query Execution Detected!" << mysql_errno(conn) << endl;
	}

	cout << "\t\t\t\t\t\t\t\t Press ENTER to return . . . " << endl;
	_getch();
	main();
}

void Login() {

	char ch;
	string username, password;

	system("cls");

	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;

	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tONI'S SPORTS CENTER \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t    ADMIN LOGIN " << endl;

	cout << "\n\t\t\t\t\t\t\tWelcome back, User " << UserID << endl;


	cout << "\n\t\t\t\t\t\t\t Please Enter Username And Password: " << endl;
	cout << "\n\t\t\t\t\t\t\tUSERNAME : ";
	cin >> username;
	cout << "\n\t\t\t\t\t\t\tPASSWORD : ";
	getline(cin, password);

	while ((ch = _getch()) != 13) {
		password += ch;
		cout << "*";
	}



	string checkUser_query = "select staff_id from Staff where username = '" + username + "' and password ='" + password + "'";
	const char* cu = checkUser_query.c_str();
	qstate = mysql_query(conn, cu);

	if (!qstate)
	{
		res = mysql_store_result(conn);
		if (res->row_count == 1) {
			while (row = mysql_fetch_row(res))
				UserID = row[0];
			AdminMenu();
		}
		else
		{
			char c;
			cout << "\n\t\t\t\t\t\t\t\tInvalid Username or Password.. Try Again? (y/n): ";
			cin >> c;
			if (c == 'y' || c == 'Y')
				Login();
			else
				main();
		}
	}
	else
		cout << endl << "\t\t\t\t\t\t\t\t Query Execution Detected!" << mysql_errno(conn) << endl;
}

void AdminMenu() {

	int menu;

	system("cls");

	SetConsoleTextAttribute(h, 14);

	cout << "WELCOME \t \n ";
	cout << UserID;
	cout << UserNAME;
	cout << endl;

	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;

	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tONI'S SPORTS CENTER  \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t ------ ADMIN MENU ------ \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [1] VIEW ITEM \t " << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [2] INSERT ITEM \t " << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [3] SEARCH ITEM \t " << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [4] ORDER MENU \t " << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [5] DELETE ITEM \t " << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [6] REGISTER SUPPLIER \t " << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [7] UPDATE ITEM \t " << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [8] INVENTORY MENU \t " << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [9] REPORT INVENTORY \t " << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [10] LOGOUT \t " << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;


	cout << endl;
	cout << "\t\t\t\t\t\t\t\t Enter your desired option : ";
	cin >> menu;


	switch (menu)
	{
	case 1:
		ViewItem();
		break;
	case 2:
		InsertItem();
		break;
	case 3:
		SearchItem();
		break;
	case 4:
		OrderMenu();
		break;
	case 5:
		DeleteItem();
		break;
	case 6:
		RegisterSupplier();
		break;
	case 7:
		UpdateItem();
		break;
	case 8:
		InventoryMenu();
		break;
	case 9:
		report();
		break;
	case 10:
		main();
		break;
	default:
		cout << "\t\t\t\t\t\t\t\t Please choose from [1] to [10]. press ENTER to Return to ADMIN MENU . . . ";
		_getch();
		system("cls");
		AdminMenu();
		break;
	}
}

void ViewItem()
{
	system("cls");

	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;

	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tONI'S SPORTS STORE CENTER \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t ITEM INFORMATION" << endl;
	cout << " \n";

	cout << "\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout  << "\t| ITEM ID  " << setw(10) << " |     ITEM NAME     | " << setw(15) << "    TYPE       | " << setw(10) << "       BRAND | " << setw(10) << "       PricePerItem(RM) | " << setw(15) << "    ITEM DESCRIPTION | " << setw(15) << "       SUPPLIER  | " << setw(10) << " CURRENT QUANTITY | " << setw(10) << "    QTY TO REORDER     | " << endl;
	cout << "\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;


	qstate = mysql_query(conn, "select item_id,item_name,type,brand,price_per_item,item_description,supplier,current_quantity, quantitytoreorder from item");

	if (!qstate)
	{


		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{

			cout << "\t" << "|    " << row[0] << setw(25) << row[1] << setw(18) << row[2] << setw(13) << row[3] << setw(19) << row[4] << setw(25) << row[5] << setw(21) << row[6] << setw(21) << row[7] << setw(21) << row[8] << "       |" << endl;
			cout << "\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		}
	}
	else {
		cout << "\t\t\t\t\t\t\t\tuery Execution Problem Detected!" << mysql_errno(conn) << endl;
	}

	cout << "\n\n\t\t\t\t\t\t Please press ENTER to Return To ADMIN MENU..";
	_getch();
	AdminMenu();
}

void InsertItem()
{

	system("cls");

	string item_registration, item_name, type, brand, item_description, current_quantity, price, quantity_to_reorder;
	string supplier;
	char pick;

	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;

	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t INSERT ITEM  \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t ENSURE THAT NO FAKE ITEMS ENTERED!" << endl;
	cout << " ";

	cin.ignore(1, '\n');

	cout << "\n\t\t\t\t\t\t\t\t Item Name: ";
	getline(cin, item_name);
	cout << "\t\t\t\t\t\t\t\t Item Type: ";
	getline(cin, type);
	cout << "\t\t\t\t\t\t\t\t Item Brand: ";
	getline(cin, brand);
	cout << "\t\t\t\t\t\t\t\t Price per Item(RM): ";
	getline(cin, price);
	cout << "\t\t\t\t\t\t\t\t Briefly describe item: ";
	getline(cin, item_description);
	cout << "\t\t\t\t\t\t\t\t Who is the supplier: ";
	getline(cin, supplier);
	cout << "\t\t\t\t\t\t\t\t Current Quantity Item: ";
	getline(cin, current_quantity);
	cout << "\t\t\t\t\t\t\t\t Quantity to Reorder: ";
	getline(cin, quantity_to_reorder);


	string checkUser_query = "SELECT * FROM item WHERE item_name = '" + item_name + "' limit 1";
	const char* cu = checkUser_query.c_str();
	qstate = mysql_query(conn, cu);

	if (!qstate)
	{
		res = mysql_store_result(conn);
		if (res->row_count == 1)
		{

			cout << "\n\n\t\t\t\t\t\t\t ITEM ALREADY EXISTED!";
			system("pause");
			InsertItem();
		}

		else
		{
			string insert_query = "insert into item(staff_id, item_name, type, brand, price_per_item, item_description, supplier, current_quantity, quantitytoreorder)values('" + UserID + "','" + item_name + "','" + type + "','" + brand + "','" + price + "','" + item_description + "','" + supplier + "','" + current_quantity + "','" + quantity_to_reorder + "')";
			const char* q = insert_query.c_str(); //convert
			qstate = mysql_query(conn, q); //execute

			if (!qstate)
			{
				cout << endl << "\n\t\t\t\t\t\t\t\ttItem has been successfully added in database!" << endl;
				
			}
			else
			{
				cout << endl << "\n\t\t\t\t\t\t\t\t Query Execution Detected!" << mysql_errno(conn) << endl;
			}

		}
		do
		{
			cout << " \t\t\t\t\t\t\t\t Do you want to add another Item? (y/n): " << endl;
			cout << " \n\t\t\t\t\t\t\t\t | (y) for yes | (n) for no |";

			cin >> pick;


			if (pick == 'y' || pick == 'Y')
			{
				InsertItem();
			}

			else if (pick == 'N' || pick == 'n')
			{
				ViewItem();

			}

		} while (pick == 'y' || pick == 'Y' || pick == 'n' || pick == 'N');
	}

	else
	{
		cout << "\t\t\t\t\t\t\t\t QUERY EXECUTION PROBLEM " << mysql_errno(conn) << endl;
	}






}






void SearchItem()
{
	system("cls");
	char choose;
	string type;

	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;

	cin.ignore(1, '\n');
	cout << "\n\t\t\t\t\t\t\t\tEnter the TYPE of item: ";
	getline(cin, type);


	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t LIST OF ITEM SEARCHED INFORMATION \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << " ";



	string search_query = "select item_id, item_name, type, brand, price_per_item, item_description, supplier, current_quantity, quantitytoreorder from item where type like '%" + type + "%'";
	const char* q = search_query.c_str();
	qstate = mysql_query(conn, q);

	if (!qstate)
	{
		cout << "\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\t| ITEM ID  " << setw(10) << " |     ITEM NAME     | " << setw(15) << "    TYPE       | " << setw(10) << "       BRAND | " << setw(10) << "       PricePerItem(RM) | " << setw(15) << "    ITEM DESCRIPTION | " << setw(15) << "       SUPPLIER  | " << setw(10) << " CURRENT QUANTITY | " << setw(10) << "    QTY TO REORDER     | " << endl;
		cout << "\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;



		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			cout << "\t" << "|    " << row[0] << setw(25) << row[1] << setw(18) << row[2] << setw(13) << row[3] << setw(19) << row[4] << setw(25) << row[5] << setw(21) << row[6] << setw(21) << row[7] << setw(21) << row[8] << "       |" << endl;
			cout << "\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		}

		cout << endl << "\t\t\t\t\t\t\t\t Do you want to search other type? (y/n): " << endl;
		cout << " \n\t\t\t\t\t\t\t\t | (y) for yes | (n) for no |";

		cin >> choose;

		if (choose == 'y' || choose == 'Y')
			SearchItem();
		else if (choose == 'n' || choose == 'N')
			AdminMenu();
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t Query Execution Problem!" << mysql_errno(conn) << endl;
	}
}

void DeleteItem() {

	system("cls");
	char choose;

	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;

	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t DELETE ITEM  \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << " ";


	string checkUser_query = "select item_id, item_name, type, brand, price_per_item, item_description, supplier, current_quantity, quantitytoreorder from item";
	const char* cu = checkUser_query.c_str();
	qstate = mysql_query(conn, cu);

	if (!qstate)
	{
		cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| ITEM ID  " << setw(10) << " |     ITEM NAME     | " << setw(15) << "    TYPE       | " << setw(10) << "       BRAND | " << setw(10) << "       PricePerItem(RM) | " << setw(15) << "    ITEM DESCRIPTION | " << setw(15) << "       SUPPLIER  | " << setw(10) << " CURRENT QUANTITY | " << setw(10) << "    QTY TO REORDER     | " << endl;
		cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;



		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			cout << setw(2) << "|    " << row[0] << setw(25) << row[1] << setw(18) << row[2] << setw(13) << row[3] << setw(19) << row[4] << setw(25) << row[5] << setw(21) << row[6] << setw(21) << row[7] << setw(21) << row[8] << "       |" << endl;
			cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

			cout << endl;
			0;
		}


		cout << endl;
		cout << "\t\t\t\t\t\t\t\t Choose ItemID:";
		cin >> ItemID;

		cout << "\t\t\t\t\t\t\t\t Are you sure to delete? " << endl;
		cout << " \n\t\t\t\t\t\t\t\t | (y) for yes | (n) for no |";
		cin >> choose;

		if (choose == 'y' || choose == 'Y')
		{
			string delete_query = "delete from item where item_id = '" + ItemID + "'";
			const char* q = delete_query.c_str();
			qstate = mysql_query(conn, q);
		}

		else
		{
			cout << "\n\t\t\t\t\t\t\t\t Press ENTER to return to ADMIN MENU . . . ";
			_getch();
			AdminMenu();
		}

		cout << "\n\t\t\t\t\t\t\t\t Item has been deleted." << endl;
		cout << "\n\t\t\t\t\t\t\t\t Do you want to delete other item? (y/n):  " << endl;
		cout << " \n\t\t\t\t\t\t\t\t | (y) for yes | (n) for no |";

		cin >> choose;

		if (choose == 'y' || choose == 'Y')
			DeleteItem();
		else
			ViewItem();

	}

}

void OrderMenu()
{
	system("cls");

	int choose;

	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;

	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tONI'S SPORTS STORE CENTER\t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tORDER MENU\t \n" << endl;
	cout << " ";
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [1] ORDER ITEM \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [2] VIEW ORDER ITEM \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [3]  ORDER LIST \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [4] VIEW ORDER LIST \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [5]  RETURN  \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;

	cout << " \n\t\t\t\t\t\t\t\t\tENTER BETWEEN 1-4 ONLY . . .  ";
	cin >> choose;

	switch (choose)
	{
	case 1:
		OrderItem();
		break;
	case 2:
		ViewOrderItem();
		break;
	case 3:
		OrderList();
		break;
	case 4:
		ViewOrderList();
		break;
	case 5:
		AdminMenu();
		break;
	default:
		cout << "\n\\t\t\t\t\t\t\t\t Please choose between 1 to 7. . Then Press ENTER to Proceed";
		_getch();
		system("cls");
		OrderMenu();
		break;
	}

}


void OrderItem() 
{ 
	system("cls");
	char choose;
	string date;

	string OrderId, staffid, suppid, item_name;

	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;

	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tONI'S SPORTS STORE CENTER\t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t ORDER LIST INFORMATION" << endl;
	cout << " ";

	cout << "\t\t\t\t\t\t\t\t DO YOU WANT TO MAKE AN ORDER? (Y/n): " << endl;
	cout << " \n\t\t\t\t\t\t\t\t | (y) for yes | (n) for no |";

	cin >> choose;

	if (choose == 'Y' || choose == 'y')
	{
		cin.ignore(1, '\n');
		cout << "\n\t\t\t\t\t\t\t\t\t ENTER ITEM ID: ";
		getline(cin, ItemID);


		cout << "\n" << endl;
		string search_query = "select item_id, item_name, type, brand, price_per_item, item_description, supplier, current_quantity, quantitytoreorder from item where item_id = '" + ItemID + "'";
		const char* c = search_query.c_str();
		qstate = mysql_query(conn, c);



		if (!qstate)
		{
			cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "| ITEM ID  " << setw(10) << " |     ITEM NAME     | " << setw(15) << "    TYPE       | " << setw(10) << "       BRAND | " << setw(10) << "       PricePerItem(RM) | " << setw(15) << "    ITEM DESCRIPTION | " << setw(15) << "       SUPPLIER  | " << setw(10) << " CURRENT QUANTITY | " << setw(10) << "    QTY TO REORDER     | " << endl;
			cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

			res = mysql_store_result(conn);

			if (res->row_count == 1)
				while (row = mysql_fetch_row(res))
				{
					cout << setw(2) << "|    " << row[0] << setw(25) << row[1] << setw(18) << row[2] << setw(13) << row[3] << setw(19) << row[4] << setw(25) << row[5] << setw(21) << row[6] << setw(21) << row[7] << setw(21) << row[8] << "       |" << endl;
					cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;


					cout << endl;
					0;

				}
		}

		else
		{
			cout << "\n\t\t\t\t\t\t\t\t Query Execution Problem!" << mysql_errno(conn) << endl;

		}

		cout << "\n" << endl;



		cin.ignore(1, '\n');
		cout << " \n\t\t\t\t\t\t\t\t\tENTER ORDER ID : ";
		getline(cin, OrderID);

		cout << "\n\t\t\t\t\t\t\t\t\tENTER ITEM ID: ";
		getline(cin, ItemID);


		cout << " \n\t\t\t\t\t\t\t\t\tENTER USER ID: ";
		cin >> UserID;


		cin.ignore(1, '\n');
		cout << " \n\t\t\t\t\t\t\t\t\tENTER ITEM NAME: ";
		getline(cin, item_name);


		cin.ignore(1, '\n');
		cout << " \n\t\t\t\t\t\t\t\t\tENTER SUPPLIER ID: ";
		cin >> SuppID;


		cin.ignore(1, '\n');
		cout << " \n\t\t\t\t\t\t\t\t\tENTER DATE OF ORDER (YYYY-MM-DD) :  ";
		cin >> date;

		if (1000 <= sbyear <= 3000)
		{
			if ((sbmonth == 1 || sbmonth == 3 || sbmonth == 5 || sbmonth == 7 || sbmonth == 8 || sbmonth == 10 || sbmonth == 12) && sbday > 0 && sbday <= 31)
			{
				dyear = to_string(sbyear);
				dmonth = to_string(sbmonth);
				dday = to_string(sbday);

				date.append(dyear);
				date.append("-");
				date.append(dmonth);
				date.append("-");
				date.append(dday);

				date = date;
			}
			else if (sbmonth == 4 || sbmonth == 6 || sbmonth == 9 || sbmonth == 11 && sbday > 0 && sbday <= 30)
			{
				dyear = to_string(sbyear);
				dmonth = to_string(sbmonth);
				dday = to_string(sbday);

				date.append(dyear);
				date.append(dmonth);
				date.append(dday);

				date = date;
			}
			else if (sbmonth == 2)
			{
				if ((sbyear % 400 == 0 || (sbyear % 100 != 0 && sbyear % 4 == 0)) && sbday > 0 && sbday <= 29)
				{
					dyear = to_string(sbyear);
					dmonth = to_string(sbmonth);
					dday = to_string(sbday);

					date.append(dyear);
					date.append("-");
					date.append(dmonth);
					date.append("-");
					date.append(dday);

					date = date;
				}
				else if (sbday > 0 && sbday <= 28)
				{
					dyear = to_string(sbyear);
					dmonth = to_string(sbmonth);
					dday = to_string(sbday);

					date.append(dyear);
					date.append("-");
					date.append(dmonth);
					date.append("-");
					date.append(dday);

					date = date;
				}
				else
				{
					cout << "\n\t\t\t\t\t\t\t\t Error." << endl;
					cout << "\t\t\t\t\t\t\t\t Invaiid Format. Try Again!" << endl;
					_getch();
					OrderItem();
				}
			}
		}

		cout << endl;
		string checkUser_query = "SELECT * FROM `order` WHERE order_id  = '" + OrderID + "' limit 1";
		const char* cu = checkUser_query.c_str();
		qstate = mysql_query(conn, cu);

		if (!qstate)
		{
			res = mysql_store_result(conn);
			if (res->row_count == 1)
			{

				cout << "\n\n\t\t\t\t\t\t\t ORDERID ALREADY EXISTED!";
				system("pause");
				OrderItem();
			}
			else
			{
				string insert_query = "INSERT INTO `order` (order_id, staff_id, item_name, supplier_id,  date) values ('" + OrderID + "','" + UserID + "','" + item_name + "','" + SuppID + "','" + date + "')";
				const char* q = insert_query.c_str();
				qstate = mysql_query(conn, q);

				if (!qstate)
				{
					cout << endl << "\t\t\t\t\t\t\t\t Order has been successfully added in database!" << endl;
					system("pause");
					ViewOrderItem();
				}
				else
				{
					cout << "\t\t\t\t\t\t\t\t Query Execution Problem!" << mysql_errno(conn) << endl;

				}
			}
			do
			{
				cout << endl << "\t\t\t\t\t\t\t\t Do you want tO continue add another order ? (y/n): " << endl;
				cout << " \n\t\t\t\t\t\t\t\t | (y) for yes | (n) for no |";
				cin >> choose;

				if (choose == 'y' || choose == 'Y')
					OrderItem();
				else if (choose == 'n' || choose == 'N')
					cout << "\n\t\t\t\t\t\t\t\t PRESS ANY KEY TO RETURN TO ORDER MENU" << endl;
				_getch();
				OrderMenu();
			} while (choose == 'y' || choose == 'Y' || choose == 'n' || choose == 'N');






		}
		else
		{
			cout << "\t\t\t\t\t\t\t\t Query Execution Problem!" << mysql_errno(conn) << endl;

		}



	}

}

void ViewOrderItem()
{

	system("cls");

	qstate = mysql_query(conn, "SELECT order_id, item_name, date FROM `order` ");

	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;

	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tONI'S SPORTS STORE CENTER\t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n" << endl;


	cout << "\t\t\t\t\t\t\t\t\t---------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t\t\t" << "| ORDER ID  " << setw(10) << " |     ITEM NAME     | " << setw(15) <<  "       DATE    | "  << endl;
	cout << "\t\t\t\t\t\t\t\t\t---------------------------------------------------" << endl;



	if (!qstate)
	{

		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{

			cout << "\t\t\t\t\t\t\t\t\t" << "|    " << row[0] << setw(20) << row[1] << setw(22) << row[2] << "  | " << endl;
			cout << "\t\t\t\t\t\t\t\t\t---------------------------------------------------" << endl;


		}
	}

	else
	{
		cout << "\n\t\t\t\t\t\t\t\t  Query Execution Problem!" << mysql_errno(conn) << endl;
	}

	system("pause");
	cout << "\n\t\t\t\t\t\t\t\t  Press Enter to return . . .";
	_getch();
	OrderMenu();
}

void OrderList()
{
	system("cls");
	string order_itemid, order_id, ReceivedDate;
	string OrderItemQty;
	string status = "AVAILABLE";
	char choose;


	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;

	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tONI'S SPORTS STORE CENTER\t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t ORDER LIST INFORMATION" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << " ";



	

	cout <<  " \n\t\t\t\t\t\t\t\t\tEnter order item id: ";
	cin >> OrderItemID;

	cout << " \n\t\t\t\t\t\t\t\t\t ENTER ORDER ID : ";
	cin >> OrderID;


	

	cout << " \n\t\t\t\t\t\t\t\t\t Enter Item ID:  ";
	cin >> ItemID;

	cout << " \n\t\t\t\t\t\t\t\t\t Enter Order Item Quantity:  ";
	cin >> OrderItemQty;

	//cout << " \n\t\t\t\t\t\t\t\t\tEnter Order Status (Available / Not):  ";
	//cin >> status;


	cout << setw(32) << " \n\t\t\t\t\t\t\t\t\t Enter the Date Item Received (YYYY-MM-DD) : ";
	cin >> ReceivedDate;

	_getch();


	if (1000 <= sbyear <= 3000)
	{
		if ((sbmonth == 1 || sbmonth == 3 || sbmonth == 5 || sbmonth == 7 || sbmonth == 8 || sbmonth == 10 || sbmonth == 12) && sbday > 0 && sbday <= 31)
		{
			dyear = to_string(sbyear);
			dmonth = to_string(sbmonth);
			dday = to_string(sbday);

			date.append(dyear);
			date.append("-");
			date.append(dmonth);
			date.append("-");
			date.append(dday);

			ReceivedDate = date;
		}
		else if (sbmonth == 4 || sbmonth == 6 || sbmonth == 9 || sbmonth == 11 && sbday > 0 && sbday <= 30)
		{
			dyear = to_string(sbyear);
			dmonth = to_string(sbmonth);
			dday = to_string(sbday);

			date.append(dyear);
			date.append(dmonth);
			date.append(dday);

			ReceivedDate = date;
		}
		else if (sbmonth == 2)
		{
			if ((sbyear % 400 == 0 || (sbyear % 100 != 0 && sbyear % 4 == 0)) && sbday > 0 && sbday <= 29)
			{
				dyear = to_string(sbyear);
				dmonth = to_string(sbmonth);
				dday = to_string(sbday);

				date.append(dyear);
				date.append("-");
				date.append(dmonth);
				date.append("-");
				date.append(dday);

				ReceivedDate = date;
			}
			else if (sbday > 0 && sbday <= 28)
			{
				dyear = to_string(sbyear);
				dmonth = to_string(sbmonth);
				dday = to_string(sbday);

				date.append(dyear);
				date.append("-");
				date.append(dmonth);
				date.append("-");
				date.append(dday);

				ReceivedDate = date;
			}
			else
			{
				cout << "\n\t\t\t\t\t\t\t\t  Error." << endl;
				cout << "\t\t\t\t\t\t\t\t  Invaiid Format. Try Again!" << endl;
				_getch();
				OrderList();
			}
		}
	}



	string insert_query = "insert into `order_list`(order_itemid, order_id,item_id ,OrderItemQty, status, ReceivedDate ) values ('" + OrderItemID + "','" + OrderID + "','" + ItemID + "','" + OrderItemQty + "','" + status + "','" + ReceivedDate + "')";
	const char* is = insert_query.c_str();
	qstate = mysql_query(conn, is);

	mysql_free_result(res);


	if (!qstate)
	{
		cout << endl << "\t\t\t\t\t\t\t\t Your order successfully added in database!" << endl;
	}
	else {
		cout << "\t\t\t\t\t\t\t\t  Query Execution Problem!" << mysql_errno(conn) << endl;
	}

	do {
		cout << "\t\t\t\t\t\t\t\t  Is there anything else you want to order?? (y/n)" << endl;
		cout << " \n\t\t\t\t\t\t\t\t | (y) for yes | (n) for no |" << endl;

		cin >> choose;
		if (choose == 'y' || choose == 'Y') {
			OrderList();
		}
		else if (choose == 'n' || choose == 'N') {
			OrderMenu();
		}
	} while (choose == 'y' || choose == 'Y' || choose == 'n' || choose == 'N');

}

void ViewOrderList()
{
	system("cls");

	char choose;

	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;

	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t LIST OF ORDER\t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;

	cout <<"\t\t\t\t------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout <<"\t\t\t\t" << "|   ORDER ITEMID    " << setw(10) << " |     ORDER ID     | " << setw(15) << "    ITEM ID       | " << setw(10) << "       ORDER ITEM QTY  | " << setw(10) << "       STATUS    | " << setw(15) << "    RECEIVED DATE | " << endl;
	cout << "\t\t\t\t------------------------------------------------------------------------------------------------------------------------------" << endl;


	qstate = mysql_query(conn, "select order_itemid,order_id,item_id,OrderItemQty,status,ReceivedDate from order_list");


	if (!qstate)
	{

		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{



			cout << "\t\t\t\t" << "|    " << row[0] << setw(25) << row[1] << setw(18) << row[2] << setw(20) << row[3] << setw(24) << row[4] << setw(25) << row[5] << "       |" << endl;
			cout << "\t\t\t\t------------------------------------------------------------------------------------------------------------------------------" << endl;


		}
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t  Query Execution Problem!" << mysql_errno(conn) << endl;

	}

	cout << "\n\t\t\t\t\t\t\t\t Press Enter To Return to Order Menu";
	_getch();
	OrderMenu();
}

void RegisterSupplier()
{
	system("cls");
	string name, phone, company, username, password, email, address;


	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;

	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t SUPPLIER REGISTER \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << " ";

	cout << "\t\t\t\t\t\t\t\t Enter name: ";
	cin.ignore(1, '\n');
	getline(cin, name);
	cout << "\t\t\t\t\t\t\t\t Enter phone number: ";
	getline(cin, phone);
	cout << "\t\t\t\t\t\t\t\t Enter company's name: ";
	getline(cin, company);
	cout << "\t\t\t\t\t\t\t\t Enter email:  ";
	getline(cin, email);
	cout << "\t\t\t\t\t\t\t\t Enter address: ";
	getline(cin, address);
	cout << "\t\t\t\t\t\t\t\t Enter username:  ";
	getline(cin, username);
	cout << "\t\t\t\t\t\t\t\t Enter Password: ";
	getline(cin, password);


	string checkSup_query = " select * from supplier where Username = '" + username + "'";
	const char* su = checkSup_query.c_str();
	qstate = mysql_query(conn, su);

	if (!qstate)
	{
		res = mysql_store_result(conn);
		if (res->row_count == 1) {
			cout << "\t\t\t\t\t\t\t\t Username has already exist. Press Enter to try again . . .";
			_getch();
			RegisterSupplier();
		}
		else
		{

			string insertSupplier_query = "insert into supplier (name,phone,company,username,password,email,address)values('" + name + "','" + phone + "','" + company + "','" + username + "','" + password + "','" + email + "','" + address + "')";
			const char* q = insertSupplier_query.c_str();
			qstate = mysql_query(conn, q);

			if (!qstate)
			{
				cout << endl << "\t\t\t\t\t\t\t\t Supplier have been registered. Press Enter to proceed . . .";
				_getch();
				main();
			}
			else {
				cout << "\t\t\t\t\t\t\t\t Query Execution Problem!" << mysql_errno(conn) << endl;
			}
		}
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t  Query Execution Problem!" << mysql_errno(conn) << endl;
	}
}

void LoginSupplier()
{
	system("cls");
	string username, password;

	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;

	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tONI'S SPORTS CENTER \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t    SUPPLIER LOGIN " << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;

	cout << "\n\t\t\t\t\t\t\t\t  Username:  ";
	cin >> username;
	cout << "\t\t\t\t\t\t\t\t Password:  ";
	getline(cin, password);

	char ps;

	while ((ps = _getch()) != 13) {
		password += ps;
		cout << "*";
	}

	string checkSup_query = "select supplier_id from supplier where username = '" + username + "'and password ='" + password + "'";
	const char* su = checkSup_query.c_str();
	qstate = mysql_query(conn, su);

	if (!qstate) {
		res = mysql_store_result(conn);
		if (res->row_count == 1) {
			while (row = mysql_fetch_row(res))
				SuppID = row[0];
			SupplierMenu();
		}
		else
		{
			char p;
			cout << "\n\t\t\t\t\t\t\t\t Invalid Username or Password. Try Again? (y/n): ";
			cin >> p;
			if (p == 'y' || p == 'Y')
				LoginSupplier();
			else
				main();
		}
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t  Query Execution Problem!" << mysql_errno(conn) << endl;
	}
}

void SupplierMenu()
{

	system("cls");


	int menu;
	system("cls");

	cout << "\t\t\t\t\t\t\t\t WELCOME " << SuppID << "!" << endl;
	cout << endl;

	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;


	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t SUPPLIER MENU \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [1] ORDER MENU \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [2] VIEW ITEM \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [3] SEARCH ITEM \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [4] LOGOUT  \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;

	cout << endl;
	cout << "\n\t\t\t\t\t\t\t\t Choose one of the option : ";
	cin >> menu;

	switch (menu)
	{
	case 1:
		SuppOrderMenu();
		break;
	case 2:
		SuppViewItem();
		break;
	case 3:
		SearchItem();
		break;
	case 4:
		cout << "\n\t\t\t\t\t\t\t\t Logging out from SUPPLIER . . . " << endl;
		UserAuthentication();
	default:
		cout << "\n\t\t\t\t\t\t\t\t Please choose between 1 - 2. Press SpaceBar to Return to main. . .";
		_getch();
		system("cls");
		UserAuthentication();
	}

}

void SuppViewItem()
{
	system("cls");

	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;

	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tONI'S SPORTS STORE CENTER \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t ITEM INFORMATION" << endl;
	cout << " \n";

	cout << "\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t| ITEM ID  " << setw(10) << " |     ITEM NAME     | " << setw(15) << "    TYPE       | " << setw(10) << "       BRAND | " << setw(10) << "       PricePerItem(RM) | " << setw(15) << "    ITEM DESCRIPTION | " << setw(15) << "       SUPPLIER  | " << setw(10) << " CURRENT QUANTITY | " << setw(10) << "    QTY TO REORDER     | " << endl;
	cout << "\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;


	qstate = mysql_query(conn, "select item_id,item_name,type,brand,price_per_item,item_description,supplier,current_quantity, quantitytoreorder from item");

	if (!qstate)
	{


		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{

			cout << "\t" << "|    " << row[0] << setw(25) << row[1] << setw(18) << row[2] << setw(13) << row[3] << setw(19) << row[4] << setw(25) << row[5] << setw(21) << row[6] << setw(21) << row[7] << setw(21) << row[8] << "       |" << endl;
			cout << "\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		}
	}
	else {
		cout << "\t\t\t\t\t\t\t\tuery Execution Problem Detected!" << mysql_errno(conn) << endl;
	}

	cout << "\n\n\t\t\t\t\t\t Please press ENTER to Return To ADMIN MENU..";
	_getch();
	SupplierMenu();
}



void SuppViewOrder() 
{


	system("cls");

	qstate = mysql_query(conn, "SELECT order_id, item_name, date FROM `order` ");

	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;

	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tONI'S SPORTS STORE CENTER\t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n" << endl;


	cout << "\t\t\t\t\t\t\t\t\t---------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t\t\t\t" << "| ORDER ID  " << setw(10) << " |     ITEM NAME     | " << setw(15) << "       DATE    | " << endl;
	cout << "\t\t\t\t\t\t\t\t\t---------------------------------------------------" << endl;


	cout << qstate;

	if (!qstate)
	{

		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{

			cout << "\t\t\t\t\t\t\t\t\t" << "|    " << row[0] << setw(20) << row[1] << setw(22) << row[2] << "  | " << endl;
			cout << "\t\t\t\t\t\t\t\t\t---------------------------------------------------" << endl;



		}
	}

	else
	{
		cout << "\n\t\t\t\t\t\t\t\t  Query Execution Problem!" << mysql_errno(conn) << endl;
	}

	cout << "\n\t\t\t\t\t\t\t\t  Press Enter to return . . .";
	_getch();
	SuppOrderMenu();
}

void SuppViewOrderList()
{
	system("cls");

	char choose;

	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;

	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t LIST OF ORDER\t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;



	cout << "\t\t\t\t-----------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t" << "|   ORDER ITEMID    " << setw(10) << " |     ORDER ID     | " << setw(15) << "    ITEM ID       | " << setw(10) << "       ORDER ITEM QTY  | " << setw(10) << "       STATUS    | " << setw(15) << "    RECEIVED DATE | " << endl;
	cout << "\t\t\t\t-----------------------------------------------------------------------------------------------------------------------------------" << endl;


	qstate = mysql_query(conn, "select order_itemid,order_id,OrderItemQty,status,ReceivedDate from order_list");


	if (!qstate)
	{

		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			cout << "\t\t\t\t" << "|    " << row[0] << setw(25) << row[1] << setw(18) << row[2] << setw(20) << row[3] << setw(24) << row[4] << setw(25) << row[5] << "       |" << endl;
			cout << "\t\t\t\t-----------------------------------------------------------------------------------------------------------------------------------" << endl;


		}
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t  Query Execution Problem!" << mysql_errno(conn) << endl;

	}

	cout << "\t\t\t\t\t\t\t\t  Press Enter To Return to Order Menu";
	_getch();
	SuppOrderMenu();
}

void UpdateItem()
{
	system("cls");

	char pick;
	int choose = 0;
	int BalanceQuantity = 0;
	double InQuantity, OutQuantity, NewQuantity{};
	int current_quantity = 0;
	string item_name, newname, NewItemDescription, price_per_item, newprice;


	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;


	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t UPDATE ITEM \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;


	cout << "\n\t\t\t\t\t\t\t\t  Do you want to update? (y/n): " << endl;
	cout << " \n\t\t\t\t\t\t\t\t | (y) for yes | (n) for no |";
	cin >> pick;

	system("cls");


	if (pick == 'Y' || pick == 'y')
	{
		system("cls");
		cout << "\t\t\t\t\t\t\t\t  Update Item" << endl;

		cout << "\t\t\t\t\t\t\t\t  Enter item ID: ";
		cin >> ItemID;

		do
		{
			string search_query = "select item_id,item_name,type,brand,item_description,current_quantity,price_per_item,quantitytoreorder from item where item_id = '" + ItemID + "'";
			const char* q = search_query.c_str();
			qstate = mysql_query(conn, q);
			res = mysql_store_result(conn);

			if (res->row_count == 1)
			{
				while (row = mysql_fetch_row(res)) 
				{
					system("cls");

					cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
					cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;


					cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t CURRENT DETAILS OF ITEM \t \n" << endl;
					cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t ITEM ID: " << row[0] << "\t(Uneditable)" << "\t \n" << endl;
					cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t [1] ITEM NAME: " << row[1] << "\t \n" << endl;
					cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t [2] ITEM TYPE: " << row[2] << "\t(Uneditable)" << "\t \n" << endl;
					cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t [3] ITEM BRAND: " << row[3] << "\t(Uneditable)" << "\t \n" << endl;
					cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t [4] ITEM DESCRIPTION: " << row[4] << "\t \n" << endl;
					cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t [5] CURRENT QUANTITY:  " << row[5] << "\t \n" << endl;
					cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t [6] PRICE PER ITEM (RM): " << row[6] << "\t \n" << endl;
					cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t [7] SUPPLIER: " << row[7] << "\t(Uneditable)" << "\t \n" << endl;
					cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t [8] QUANTITY TO REORDER: " << row[8] << "\t(Uneditable)" << "\t \n" << endl;
					cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t [9] SAVE CHANGES: \t \n" << endl;
					cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;

					cout << endl;

					current_quantity = stoi(row[5]);
					price_per_item = stoi(row[6]);



				}
				cout << "\n" << endl;
				cout << "\n\t\t\t\t\t\t\t\t\tChoose one from the update: ";
				cin >> choose;
				cin.ignore(1, '\n');

				if (choose == 1)
				{
					cout << "\t\t\t\t\t\t\t\t  Insert name: ";
					getline(cin, newname);

					string update_item = "update item SET item_name = '" + newname + "' where item_id = '" + ItemID + "'";
					const char* q = update_item.c_str();
					qstate = mysql_query(conn, q);

				}

				else if (choose == 2)
				{
					cout << "\t\t\t\t\t\t\t\t  This Part is uneditable :( " << endl;
					cout << "\t\t\t\t\t\t\t\t  Press ENTER to try again";
					_getch();
					UpdateItem();
				}

				else if (choose == 3)
				{
					cout << "\t\t\t\t\t\t\t\t  This Part is uneditable :( " << endl;
					cout << "\t\t\t\t\t\t\t\t  Press ENTER to try again";
					_getch();
					UpdateItem();
				}

				else if (choose == 4)
				{
					cout << "\t\t\t\t\t\t\t\t  Insert Item Description: ";
					getline(cin, NewItemDescription);

					string update_item = "update item SET item_description = '" + NewItemDescription + "' where item_id = '" + ItemID + "'";
					const char* q = update_item.c_str();
					qstate = mysql_query(conn, q);

				}

				else if (choose == 5)
				{

					cout << "\n\t\t\t\t\t\t\t\t\t New amount for current_quantity:  " << endl;
					cin >> NewQuantity;

					string update_item = "update item SET current_quantity = '" + to_string(NewQuantity) + "' where item_id = '" + ItemID + "'";
					const char* i = update_item.c_str();
					qstate = mysql_query(conn, i);

					system("pause");
					cout << "\n\t\t\t\t\t\t\t\t  New Amount for Item: " << NewQuantity << endl;

				}

				else if (choose == 6)
				{
					cout << "\t\t\t\t\t\t\t\t Enter latest price: ";
					getline(cin, newprice);


					string update_item = "update item SET price_per_item = '" + newprice + "' where item_id = '" + ItemID + "'";
					const char* q = update_item.c_str();
					qstate = mysql_query(conn, q);


				}
				else if (choose == 7)
				{
					cout << "\t\t\t\t\t\t\t\t This Part is uneditable :( " << endl;
					cout << "\t\t\t\t\t\t\t\t  Press ENTER to try again";
					_getch();
					UpdateItem();
				}
				else if (choose == 8)
				{
					cout << "\t\t\t\t\t\t\t\t This Part is uneditable :( " << endl;
					cout << "\t\t\t\t\t\t\t\t  Press ENTER to try again";
					_getch();
					UpdateItem();
				}

				else
				{
					system("cls");
					cout << "\t\t\t\t\t\t\t\t  All Has been Updated." << endl;
					cout << "\t\t\t\t\t\t\t\t  Saving changes . . . ";
					ViewItem();
				}
			}
			else
			{
				cout << "\n\t\t\t\t\t\t\t\t Please Enter Correct ID" << endl;
				UpdateItem();
			}

		} while (true);

	}
	else
	{
		SupplierMenu();
	}

}

void SuppOrderMenu()
{
	system("cls");

	int choose;

	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;


	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tONI'S SPORTS STORE CENTER\t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tORDER MENU\t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [1] VIEW ORDER ITEM \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [2]. VIEW ORDER LIST \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [3]. RETURN \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << " ";
	cout << " \n\t\t\t\t\t\t\t\t\t ENTER BETWEEN [1] - [3] ONLY . . .  ";
	cin >> choose;


	switch (choose)
	{
	case 1:
		SuppViewOrder();
		break;
	case 2:
		SuppViewOrderList();
		break;

	case 3:
		cout << "\n\t\t\t\t\t\t\t\t  Returning to Supplier Menu . . .";
		system("pause");
		_getch();
		SupplierMenu();
	default:
		cout << "\n\t\t\t\t\t\t\t\t  Please enter the correct option" << endl;
		cout << "\t\t\t\t\t\t\t\t  Press ENTER to return to Supplier Menu . . . " << endl;
		system("pause");
		_getch();
		SupplierMenu();
	}
}

void Inventory()
{

	system("cls");


	char choose;
	string in_quantity, out_quantity, current_quantity, chekc_date;
	string inventory_id;
	
	string staff_id;

	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;


	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tONI'S SPORTS STORE CENTER\t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << " " << endl;



	cout << "\n\t\t\t\t\t\t\t\t  DO you want to add inventory? (y/n) : " << endl;
	cout << " \n\t\t\t\t\t\t\t\t | (y) for yes | (n) for no |";

	cin >> choose;

	if (choose == 'y' || choose == 'Y')
	{
		cin.ignore(1, '\n');
		cout << "\t\t\t\t\t\t\t\t ITEM ID: ";
		getline(cin, ItemID);


		cout << "\n" << endl;
		string search_query = "select item_id,item_name,type,brand,item_description,current_quantity,price_per_item,quantitytoreorder from item where item_id = '" + ItemID + "'";
		const char* c = search_query.c_str();
		qstate = mysql_query(conn, c);

		if (!qstate)
		{

			cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "| ITEM ID  " << setw(10) << " |     ITEM NAME     | " << setw(15) << "    TYPE       | " << setw(10) << "       BRAND | " << setw(10) << "       PricePerItem(RM) | " << setw(15) << "    ITEM DESCRIPTION | " << setw(15) << "       SUPPLIER  | " << setw(10) << " CURRENT QUANTITY | " << setw(10) << "    QTY TO REORDER     | " << endl;
			cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;




			res = mysql_store_result(conn);

			if (res->row_count == 1)
				while (row = mysql_fetch_row(res))
				{
					cout << setw(2) << "|    " << row[0] << setw(25) << row[1] << setw(18) << row[2] << setw(13) << row[3] << setw(19) << row[4] << setw(25) << row[5] << setw(21) << row[6] << setw(21) << row[7] << setw(21) << row[8] << "       |" << endl;
					cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

					cout << endl;
					0;

				}

		}

		else
		{
			cout << "\t\t\t\t\t\t\t\t  Query Execution Problem!" << mysql_errno(conn) << endl;

		}

		cout << "\n" << endl;




		cout << "\t\t\t\t\t\t\t\t  STAFF ID:  ";
		getline(cin, staff_id);


		cout << "\t\t\t\t\t\t\t\t  BALANCE QUANTITY:  ";
		getline(cin, current_quantity);
		cout << "\t\t\t\t\t\t\t\t ITEM IN QUANTITY:  ";
		getline(cin, in_quantity);
		cout << "\t\t\t\t\t\t\t\t  ITEM OUT QUANTITY:  ";
		getline(cin, out_quantity);

		cout << "\t\t\t\t\t\t\t\t THE DATE ITEM CAME IN (YYYY-MM-DD): ";
		getline(cin, chekc_date);

		if (1000 <= sbyear <= 3000)
		{
			if ((sbmonth == 1 || sbmonth == 3 || sbmonth == 5 || sbmonth == 7 || sbmonth == 8 || sbmonth == 10 || sbmonth == 12) && sbday > 0 && sbday <= 31)
			{
				dyear = to_string(sbyear);
				dmonth = to_string(sbmonth);
				dday = to_string(sbday);

				date.append(dyear);
				date.append("-");
				date.append(dmonth);
				date.append("-");
				date.append(dday);

				chekc_date = date;
			}
			else if (sbmonth == 4 || sbmonth == 6 || sbmonth == 9 || sbmonth == 11 && sbday > 0 && sbday <= 30)
			{
				dyear = to_string(sbyear);
				dmonth = to_string(sbmonth);
				dday = to_string(sbday);

				date.append(dyear);
				date.append(dmonth);
				date.append(dday);

				chekc_date = date;
			}
			else if (sbmonth == 2)
			{
				if ((sbyear % 400 == 0 || (sbyear % 100 != 0 && sbyear % 4 == 0)) && sbday > 0 && sbday <= 29)
				{
					dyear = to_string(sbyear);
					dmonth = to_string(sbmonth);
					dday = to_string(sbday);

					date.append(dyear);
					date.append("-");
					date.append(dmonth);
					date.append("-");
					date.append(dday);

					chekc_date = date;
				}
				else if (sbday > 0 && sbday <= 28)
				{
					dyear = to_string(sbyear);
					dmonth = to_string(sbmonth);
					dday = to_string(sbday);

					date.append(dyear);
					date.append("-");
					date.append(dmonth);
					date.append("-");
					date.append(dday);

					chekc_date = date;
				}
				else
				{
					cout << "\n\t\t\t Error." << endl;
					cout << "\t\t\t Invaiid Format. Try Again!" << endl;
					_getch();
					Inventory();
				}
			}
		}

		cout << endl;

		string insert_query = "insert into inventory (item_id, staff_id, in_quantity, out_quantity, current_quantity, CheckDate) values ('" + ItemID + "','" + staff_id + "','" + in_quantity + "','" + out_quantity + "','" + current_quantity + "','" + chekc_date + "')";
		const char* i = insert_query.c_str();
		qstate = mysql_query(conn, i);

		if (!qstate)
		{
			cout << endl << "\n\t\t\t\t\t\t\t\t  Inventory is successfully added" << endl;

		}

		else
		{
			cout << "\t\t\t\t\t\t\t\t  QUERY EXECUTION  PROBLEM" << mysql_errno(conn) << endl;
		}

			cout << "\n\t\t\t\t\t\t\t\t DO YOU WANT TO ADD ANOTHER INVENTORY?" << endl;
			cout << " \n\t\t\t\t\t\t\t\t | (y) for yes | (n) for no |";
			cin >> choose;

			if (choose == 'Y' || choose == 'y')
			{
				Inventory();
			}
			else
			{
				ViewInventory();
			}


	}
	else
	{
		cout << "\n\t\t\t\t\t\t\t\t  PRESS ANY KEY TO RETURN TO ORDER MENU" << endl;
		_getch();
		InventoryMenu();
	}


}

void ViewInventory()
{
	system("cls");
	char choose;

	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;


	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tONI'S SPORTS STORE CENTER\t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << " " << endl;

	qstate = mysql_query(conn, "select inventory_id, item_id, staff_id, in_quantity, out_quantity, current_quantity, CheckDate from inventory");

	if (!qstate)
	{
		
			cout << "\t\t\t\t" << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "\t\t\t\t" << "| INVENTORY ID  " << setw(10) << " |     ITEM ID     | " << setw(15) << "    STAFF ID       | " << setw(10) << "       IN QUANTITY   | " << setw(10) << "       OUT QUANTITY | " << setw(15) << "    BALANCE  | " << setw(15) << "       CHECK DATE     | " << endl;
			cout << "\t\t\t\t" << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;



		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			cout << "\t\t\t\t" << "|    " << row[0] << setw(25) << row[1] << setw(18) << row[2] << setw(22) << row[3] << setw(20) << row[4] << setw(22) << row[5] << setw(22) << row[6] << "     |" << endl;
			cout << "\t\t\t\t" << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;


		}
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t  QUERY EXECUTION  PROBLEM" << mysql_errno(conn) << endl;
	}

	cout << "\n\t\t\t\t\t\t\t\t  Press Enter To Go Back To Main Menu.." << endl;
	_getch();
	AdminMenu();
}

void UpdateInventory()
{
	system("cls");
	char choose;
	int chooseUpdate = 0;
	string inventory_id, item_id, staff_id, CheckDate;
	double in_quantity, out_quantity, current_quantity;
	double newIn_qty{}, newOut_qty{}, newBalance{};


	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;



	cout << "\n\t\t\t\t\t\t\t\t Do you want to update your inventory? (y/n):  " << endl;
	cout << " \n\t\t\t\t\t\t\t\t | (y) for yes | (n) for no |";
	cin >> choose;
	



		if (choose == 'Y' || choose == 'y')
		{
			system("cls");
			cout << "\n\t\t\t\t\t\t\t\t  Update Inventory" << endl;

			cout << "\n\t\t\t\t\t\t\t\t  Enter Inventory ID: ";
			cin >> InventoryID;

			do
			{
				string search_query = "select inventory_id,staff_id,in_quantity,out_quantity,current_quantity,CheckDate from inventory where inventory_id = '" + InventoryID + "'";
				const char* i = search_query.c_str();
				qstate = mysql_query(conn, i);
				res = mysql_store_result(conn);

				if (res->row_count == 1)
				{
					while (row = mysql_fetch_row(res))
					{
						system("cls");

						cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
						cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;

						cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t CURRENT DETAILS OF INVENTORY \t \n" << endl;
						cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t INVENTORY ID: " << row[0] << "\t(Uneditable)" << "\t \n" << endl;
						cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t [1] STAFF ID: " << row[1] << "\t(Uneditable)" << "\t \n" << endl;
						cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t [2] ITEM IN QUANTITY: " << row[2] << "\t \n" << endl;
						cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t [3] ITEM OUT QUANTITY: " << row[3] << "\t \n" << endl;
						cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t [4] BALANCE QUANTITY: " << row[4] << "\t \n" << endl;
						cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t [5] RECEIVED DATE (YYYY-MM-DD):  " << row[5] << "\t(Uneditable)" << "\t \n" << endl;
						cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t [6] SAVE CHANGES: \t \n" << endl;
						cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;

						cout << endl;

						in_quantity = stoi(row[2]);
						out_quantity = stoi(row[3]);
						current_quantity = stoi(row[4]);
					}

					cout << "\n" << endl;
					cout << "\n\t\t\t\t\t\t\t\t  Choose One To Update: ";
					cin >> chooseUpdate;
					cin.ignore(1, '\n');

					if (chooseUpdate == 1)
					{
						cout << "\t\t\t\t\t\t\t\t  This Part is uneditable :( " << endl;
						cout << "\t\t\t\t\t\t\t\t  Press ENTER to try again";
						_getch();
						UpdateInventory();
					}
					else if (chooseUpdate == 2)
					{

						cout << "\n" << endl;
						cout << "\t\t\t\t\t\t\t\t Enter new IN Quantity: ";
						cin >> newIn_qty;


						string update_inventory = "update inventory SET in_quantity ='" + to_string(newIn_qty) + "' where inventory_id='" + InventoryID + "'";
						const char* q = update_inventory.c_str();
						qstate = mysql_query(conn, q);

						system("pause");
						cout << "\t\t\t\t\t\t\t\t Done Updated" << endl;
						ViewInventory();

					}
					else if (chooseUpdate == 3)
					{
						system("cls");

						cout << "\t\t\t\t\t\t\t\t Enter new OUT Quantity: ";
						cin >> newOut_qty;

						string update_inventory = "update inventory SET out_quantity ='" + to_string(newOut_qty) + "' where inventory_id='" + InventoryID + "'";
						const char* q = update_inventory.c_str();
						qstate = mysql_query(conn, q);

						cout << "\n\t\t\t\t\t\t\t\t Done Updated" << endl;
						cout << "\n\t\t\t\t\t\t\t\t Press ENTER to Continue" << endl;
						_getch();
						ViewInventory();

					}
					else if (chooseUpdate == 4)
					{



						string checkinventory_query = "select current_quantity, in_quantity, out_quantity from inventory where inventory_id = '" + InventoryID + "'";
						const char* q = checkinventory_query.c_str();
						qstate = mysql_query(conn, q);

						if (!qstate)
						{
							res = mysql_store_result(conn);
							while (row = mysql_fetch_row(res))
							{

								newBalance = stod(row[0]) - (stod(row[1]) + stod(row[2]));
							}
						}

						string update_inventory = "update inventory SET current_quantity ='" + to_string(newBalance) + "'  where inventory_id='" + InventoryID + "'";
						const char* i = update_inventory.c_str();
						qstate = mysql_query(conn, i);


						cout << "\n\t\t\t\t\t\t\t\t Done Updated" << endl;
						cout << "\n\t\t\t\t\t\t\t\t Press ENTER to Continue" << endl;
						_getch();
						ViewInventory();

					}
					else if (choose ==5)
					{
						cout << "\t\t\t\t\t\t\t\t  This Part is uneditable :( " << endl;
						cout << "\t\t\t\t\t\t\t\t  Press ENTER to try again";
						_getch();
						UpdateInventory();
					}
					else
					{
					cout << "\t\t\t\t\t\t\t\t Save CHanges";
					_getch();
					InventoryMenu();
					}
				}
				else
				{
					cout << "\n\t\t\t\t\t\t\t\t Please Enter the Correct Inventory ID " << endl;
					UpdateInventory();
				}

			} while (true);
		}
		else
		{
			InventoryMenu();
		}
}

void InventoryMenu()
{
	system("cls");

	int choose;

	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;

	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t INVENTORY MENU \t \n" << endl;
	cout << " " << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [1] INVENTORY \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [2] VIEW INVENTORY \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [3] UPDATE INVENTORY \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [4] DELETE INVENTORY \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [5] SEARCH INVENTORY \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t [6] EXIT TO MAIN MENU \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;

	cout << " " << endl;
	cout << "\t\t\t\t\t\t\t\t INSERT ONLY OPTION FROM [1] TO [6] >>>> \t";
	cin >> choose;

	switch (choose)
	{
	case 1:
		Inventory();
		break;
	case 2:
		ViewInventory();
		break;
	case 3:
		UpdateInventory();
		break;
	case 4:
		DeleteInventory();
		break;
	case 5:
		SearchInventory();
		break;
	case 6:
		cout << "\t\t\t\t\t\t\t\t Exiting inventory . . ." << endl;
		AdminMenu();
		break;
	default:
		cout << "\n\t\t\t\t\t\t\t\t  Please enter the correct number. Press SPACEBAR to return to admin menu" << endl;
		_getch();
		InventoryMenu();
	}


}

void DeleteInventory()
{
	system("cls");
	char choose;

	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;


	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t DELETE INVENTORY \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << " ";


	string checkinventory_query = "select inventory_id, item_id, staff_id, in_quantity, out_quantity, current_quantity, CheckDate from inventory";
	const char* in = checkinventory_query.c_str();
	qstate = mysql_query(conn, in);

	if (!qstate)
	{

		cout << "\t\t\t\t" << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\t\t\t\t" << "| INVENTORY ID  " << setw(10) << " |     ITEM ID     | " << setw(15) << "    STAFF ID       | " << setw(10) << "       IN QUANTITY   | " << setw(10) << "       OUT QUANTITY | " << setw(15) << "    BALANCE  | " << setw(15) << "       CHECK DATE     | " << endl;
		cout << "\t\t\t\t" << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;


		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			cout << "\t\t\t\t" << "|    " << row[0] << setw(25) << row[1] << setw(18) << row[2] << setw(22) << row[3] << setw(20) << row[4] << setw(22) << row[5] << setw(22) << row[6] << "     |" << endl;
			cout << "\t\t\t\t" << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;


		}


		cout << endl;
		cout << "\t\t\t\t\t\t\t\t Choose InventoryID:";
		cin >> InventoryID;

		cout << "\t\t\t\t\t\t\t\t  Are you sure to delete? " << endl;
		cout << "\t\t\t\t\t\t\t\t  (Y) for yes, (N) for no! ";
		cin >> choose;

		if (choose == 'y' || choose == 'Y')
		{
			string delete_query = "delete from inventory where inventory_id = '" + InventoryID + "'";
			const char* q = delete_query.c_str();
			qstate = mysql_query(conn, q);
		}

		else
		{
			cout << "\t\t\t\t\t\t\t\t  Press ENTER to return to ADMIN MENU . . . ";
			_getch();
			InventoryMenu();
		}

		cout << "\t\t\t\t\t\t\t\t Item has been deleted. \n" << endl;
		cout << "\t\t\t\t\t\t\t\t Do you want to delete other item? (y/n):  " << endl;
		cout << " \n\t\t\t\t\t\t\t\t | (y) for yes | (n) for no |";
		cin >> choose;

		if (choose == 'y' || choose == 'Y')
			DeleteInventory();
		else
			ViewInventory();

	}


}

void SearchInventory()
{
	system("cls");

	char choose;

	string CheckDate;;

	cin.ignore(1, '\n');

	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;


	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t SEARCH INVENTORY \t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << " ";


	cout << "\t\t\t\t\t\t Search Inventory by Received Date (yyyy-mm-dd) : ";
	cin >> CheckDate;

	string search_query = "SELECT inventory_id, staff_id, item_id, in_quantity, out_quantity,current_quantity, CheckDate FROM inventory WHERE CheckDate like '%" + CheckDate + "%'";
	const char* q = search_query.c_str();
	qstate = mysql_query(conn, q);

	if (!qstate)
	{



		cout << "\t\t\t\t" << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\t\t\t\t" << "| INVENTORY ID  " << setw(10) << " |     ITEM ID     | " << setw(15) << "    STAFF ID       | " << setw(10) << "       IN QUANTITY   | " << setw(10) << "       OUT QUANTITY | " << setw(15) << "    BALANCE  | " << setw(15) << "       CHECK DATE     | " << endl;
		cout << "\t\t\t\t" << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;



		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{

			cout << "\t\t\t\t" << "|    " << row[0] << setw(25) << row[1] << setw(18) << row[2] << setw(22) << row[3] << setw(20) << row[4] << setw(22) << row[5] << setw(22) << row[6] << "     |" << endl;
			cout << "\t\t\t\t" << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;

			cout << endl;
			0;
		}

		cout << "\t\t\t\t\t\t\t\t Do you want to search another date? ";
		cin >> choose;

		if (choose == 'Y' || choose == 'y')
		{
			SearchInventory();
		}
		else if (choose == 'n' || choose == 'N')
		{
			InventoryMenu();
		}

	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t Query Execution Problem!" << mysql_errno(conn) << endl;
	}
}


void report()
{
	system("cls");
	char choose;
	cout << "\n\t\t\t\t\t\t\t\t" << __DATE__ << endl;
	cout << "\n\t\t\t\t\t\t\t\t" << __TIME__ << endl;


	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tONI'S SPORTS STORE CENTER\t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tREPORT INVENTORY\t \n" << endl;
	cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------------------" << endl;


	string Month;



	cout << "\n\t\t\t\t\t\t\t\t Monthly Remaining Quantity Item in Inventory " << endl;
	cout << "\t\t\t\t\t\t\t\t Below Will Show How Many Remaining Items have Left in the Inventory : " << endl;
	cout << "" << endl;
	cout << "\t\t\t\t\t\t\t\t Enter Month [1-12] : ";
	cin >> Month;

	string searchM_query = "SELECT inventory_id, item_id, staff_id, current_quantity, CheckDate FROM inventory WHERE month(CheckDate) like '%" + Month + "%'";

	const char* m = searchM_query.c_str();
	qstate = mysql_query(conn, m);

	cout << "\n\t\t\t\t\t\t\t\t  List of Searched Item for Report In Inventory Based on Remaining Item in Month : " << Month << "\n" << endl;

	if (!qstate)
	{

		cout << "\t\t\t\t\t\t" << "--------------------------------------------------------------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t" << "| INVENTORY ID  " << setw(10) << " |     ITEM ID     | " << setw(15) << "    STAFF ID       | "  << setw(15) << "    BALANCE    | " << setw(15) << "       CHECK DATE     | " << endl;
		cout << "\t\t\t\t\t\t" << "--------------------------------------------------------------------------------------------------" << endl;


		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{


			cout << "\t\t\t\t\t\t" << "|    " << row[0] << setw(25) << row[1] << setw(18) << row[2]  << setw(22) << row[3] << setw(22) << row[4] << "     |" << endl;
			cout << "\t\t\t\t\t\t" << "--------------------------------------------------------------------------------------------------" << endl;



		}

	}

	else
	{
		cout << "\t\t\t\t\t\t\t\t  QUERY EXECUTION PROBLEN " << mysql_errno(conn) << endl;
	}

	string search_SumQuery = "SELECT SUM(current_quantity) from inventory WHERE month(CheckDate) like '%" + Month + "%'";
	const char* smm = search_SumQuery.c_str();
	qstate = mysql_query(conn, smm);

	if (!qstate)
	{
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			float total = stof(row[0]);  //string to float
			cout << "\n\t\t\t\t\t\t\t\t " << "Total Remaining Quantity for The Month " << Month << " " << " is : " << total << endl;
			cout << "\t\t\t--------------------------------------------------------------------------------------------------------------------------------------" << endl;

		}
	}

	string search_AVGQuery="SELECT AVG(current_quantity) from inventory WHERE month(CheckDate) like '%" + Month + "%'";
	const char* av = search_AVGQuery.c_str();
	qstate = mysql_query(conn, av);

	if (!qstate)
	{
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			float avg = stof(row[0]);
			cout << "\n\t\t\t\t\t\t\t\t " << "AVERAGE for Remaining Quantity for The Month " << Month << " " << " is : " << avg << endl;
			cout << "\t\t\t--------------------------------------------------------------------------------------------------------------------------------------" << endl;

		}
	}

	//string search_CountQuery= "SELECT COUNT(current_quantity) from inventory WHERE month(CheckDate) like '%" + Month + "'";
	//const char* cnt = search_CountQuery.c_str();
	//qstate = mysql_query(conn, cnt);

	//if (!qstate)
	//{
	//	res = mysql_store_result(conn);
	//	while (row = mysql_fetch_row(res))
	//	{
	//		cout << "\n\t\t\t\t\t\t\t\t " << "Amount for Remaining Item in Inventory for The Month " << Month << " " << " is : " << row[0] << endl;
	//		cout << "\t\t\t--------------------------------------------------------------------------------------------------------------------------------------" << endl;

	//	}
	//}

	cout << "\n\t\t\t\t\t\t\t\tDo you want to do another report?" << endl;
	cout << " \n\t\t\t\t\t\t\t\t | (y) for yes | (n) for no |" << "\n";
	cin >> choose;

	if (choose == 'y' || choose == 'Y')
	{
		_getch();
		report();
	}
	else
	{
		cout << "\n\t\t\t\t\t\t\t\t  Press ENTER to return to ADMIN MENU . . . . ";
		_getch();
		AdminMenu();
	}

	cout << "\n\t\t\t\t\t\t\t\t  Press ENTER to return to ADMIN MENU . . . . ";
	_getch();
	AdminMenu();


	


}