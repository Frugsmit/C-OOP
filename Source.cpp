#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;
/*Создайте систему управления персональными финансами.
Система должна иметь следующие возможности:
■ Наличие разных кошельков и карт (дебетовых/кредитных);
■ Пополнение кошельков и карт;
■ Внесение затрат. Каждая затрата относится к определенной категории;
■ Формирование отчетов по затратам и категориям:
• день;
• неделя;
• месяц.
■ Формирование рейтингов по максимальным суммам:
• ТОП-3 затрат:
ӽ неделя;
ӽ месяц.
• ТОП-3 категорий:
ӽ неделя;
ӽ месяц.
■ Сохранение отчетов и рейтингов в файл.*/
class Finance {
	double costs; //Витрати
	double cash = 0; //При зміненні картки з дебетової крадитну або навпаки треба буде зняти або перекинути всі гроші на другу карту або на руки щоб не втратити їx
	double wage;

	class Card { 
	public:
		int i = 0;
		double numbercard;
		string PIB;
		string encryption = "***********";
		string namecard;
		string typecard;
		double balance = 0;
		string password;
		//Category -->>
		string category;
		double spend_money;
		string date;
		//--------------
		Card() {
			cout << "Card Constructor" << endl;
		}
		void CreateCard(double numbercard, string namecard, string typecard, string PIB, string password, double balance) {
			this->PIB = PIB;
			this->password = password;
			this->namecard = namecard;
			this->balance = balance;
			this->numbercard = numbercard;
			this->typecard = typecard;
		}
		void CreateCategory(string category, double spend_money, string date) {
			this->category = category;
			this->spend_money = spend_money;
			this->date = date;
		}
		void GetNumberCard() {
			cout << "\nN: " << numbercard << "  NameCard: " << namecard << "\tTypeCard: " << typecard << endl;
		}
		void GetInfoCard() {
			cout << "\nN: "<< numbercard << "\nNameCard: " << namecard << "\nTypeCard: "<< typecard  << "\nPIB: " << PIB << "\nPassword: " << encryption << "\nBalance: " << balance  << endl;
		}
		void GetInfoCategory() {
			cout << "\nCategory:  " << category << "\nSpend Money: " << spend_money << "\nDate: " << date << endl;
		}
		//<------>
		void SetPIB(string PIB) {
			this->PIB = PIB;
		}
		void SetPassword(string password) {
			this->password = password;
		}
		void GetPassword() {
			
		}
		void SetNameCard(string namecard) {
			this->namecard = namecard;
		}
		void SetBalance(double balance) {
			this->balance = balance;
		}
		~Card() {
			cout << "Destrucotr" << endl;
		}
	};
public:
	int i = 0;
	double numbercard;
	string PIB;
	string encryption = "***********";
	string namecard;
	string typecard;
	double balance = 0;
	string password;
	double spend_money;
	double max = 0;
	int Random(int min, int max)
	{
		return min + rand() % (max - min);
	}
	int GetCountSize() {
		return this->size;
	}
	void CreateCards() {
		cout << "Enter count Card (min - 2): ";
		cin >> this->size;
		this->cards = new Card[this->size];
		FillCards();
		Menu();
	}
	void CreateCategories() {
		cards[i].category;
		if (!category) {
		cout << "Enter the count categories\n>>> ";
		cin >> size_c;
		this->category = new Card[this-> size_c];
		FillCategory();
		}
		return ShowPrivateInfoCard();
	}
	// // //
	void ShowCategory() {
		if (!category) { cout << "Did not find the category" << endl; }
		for (int j = 0; j < size_c; j++) {
			category[j].GetInfoCategory();
		}
		system("pause"); return ShowPrivateInfoCard();
	}
	void ShowCard() {
		if (!cards) { cout << "Did not find the card" << endl; system("pause"); system("cls");  return Menu(); }
		system("cls");
		for (int i = 0; i < size; i++) {
			cards[i].GetNumberCard(); //GetInfoCard();

		}
	}
	void TheBiggestCost() {
		if (!category) { cout << "Did not find the category" << endl; system("pause"); }
		cout << "The biggest cost" << endl;
		for (int j = 0; j < size_c; j++) {
			if (spend_money < category[j].spend_money)
				spend_money = category[j].spend_money;
		}
		for (int j = 0; j < size_c; j++) {
			if (category[j].spend_money == spend_money) {
				category[j].GetInfoCategory(); system("pause");
		    }
		}
		return ShowPrivateInfoCard();
	}
	void Mining() {
		int tmp = 0;
		while (tmp < 5000) {
			tmp++;
			cout << "Enter any value (0 - Menu)" << endl;
			cin >> tmp;
			if (tmp == 0) { return ShowPrivateInfoCard(); }
				cards[i].balance += 10;
				cout << "+ 10$" << endl;
			}
	}
	void ShowPrivateInfoCard() {
		system("cls");
		cards[i].GetInfoCard();
		cout << "\n\n";
		cout << "1. Take money in credit" << endl;
		cout << "2. Transfer money to another card" << endl;
		cout << "3. Spend money" << endl;     //■ Внесение затрат. Каждая затрата относится к определенной категории; Буде 3 категорії: Їжа | Одяг | Інше. В яких ми вводимо гроші які хочемо потратити. 
		cout << "4. Report" << endl;          //■ Формирование отчетов по затратам и категориям: | день | неделя | месяц |.  Надо будет сделать масив по категориям де ми створюємо категорію і надаємо данні скільки грошей ми хочемо потратити.
		cout << "5. Raiting" << endl;         // ■ Формирование рейтингов по максимальным суммам:
		cout << "6. Menu" << endl;
		cout << "7. $ Mining $" << endl;
		cout << "8. Exit" << endl;

		int a;
		cin >> a;
		switch (a) {
		case 1: system("cls"); return TakeCredit();
			break;
		case 2: system("cls"); return TransferMoney();
			break;
		case 3:  system("cls"); return CreateCategories();
			break;
		case 4: system("cls"); ShowCategory();
			break;
		case 5: system("cls"); TheBiggestCost();
			break;
		case 6: system("cls");  return Menu();
			break;
		case 7: system("cls"); Mining();
			break;
		case 8: exit(0);
			break;
		default:
			cout << "Incorrect count!" << endl; system("pause"); system("cls"); return ShowPrivateInfoCard();
		}
	}
	//1.
	void TakeCredit() {
		if (cards[i].typecard != "Credit") {
			cout << "You must log in with a credit card" << endl; system("pause"); system("cls"); return ShowPrivateInfoCard();
		}
		cout << "How much money do you want to take?\n>>> ";
		int money;
		cin >> money;
		cards[i].balance += money;
		system("cls");
		cout << "You borrowed to " << money << endl;
		system("pause"); system("cls"); return ShowPrivateInfoCard();
	}
	//2.
	void TransferMoney() {
		int money = 0;
		cout << "Balance: " << cards[i].balance << "   ";
		cout << "How much money do you want to transfer (0 - back)" << endl;
		cin >> money;
		if (cards[i].balance < money) { money = 0; cout << "You have not money" << endl; system("pause"); system("cls"); return TransferMoney(); }
		cout << "Enter the account that will receive the money" << endl;
		cards[i].balance -= money;
		ShowCard();
		cin >> i;
		i--;
		cards[i].balance += money;
		cards[i].GetInfoCard(); system("pause"); system("cls");
		return ShowCardInfo();
	}
	void ShowCardInfo() {
		ShowCard();
		string tmpPass;
		cout << "Enter the Card: ";
		cin >> i;
		i--;
		cout << cards[i].password;
		cout << "Enter the password" << endl;
		cin >> tmpPass;
		if (cards[i].password != tmpPass) {
			cout << "\nIncorrect password!" << endl;
			system("pause"); system("cls"); return ShowCardInfo();
		}
		system("cls");
		return ShowPrivateInfoCard();

		system("cls");
		//return Menu();
	}
	Card* cards;
	Card* category;
	int size;
	int size_c; //size_category
	void FillCategory() {
		string category;
		string date;
		double spend_money;
		//
		string path = "MyFile.txt";
		ofstream f;
		f.open(path, ofstream::app);
		if (!f.is_open()) {
			cout << "Error open file!" << endl;
		}
		else
		{
			cout << "File is opened!" << endl;
			system("pause"); system("cls");
			//
			for (int j = 0; j < this->size_c; j++) {
				cout << "Enter the name category\n>>> ";
				cin >> category;
				cout << "Enter the amount you want to spend (0 - Back)\n>>> ";
				cin >> spend_money;
				if (spend_money == 0) { return ShowPrivateInfoCard(); }
				if (spend_money > cards[i].balance) {
					cout << "You do not have enough funds on the balance" << endl; system("pause"); system("cls"); return ShowPrivateInfoCard();
				}
				cout << "Enter the date\n>>> ";
				cin >> date;
				cards[i].balance -= spend_money;
				this->category[j].CreateCategory(category, spend_money, date);
				cout << "\n\nThis category was add!" << endl;
				system("pause");
				system("cls");
			//<------------------------------------File-------------------------------------------->
				f << category << " - Category " << endl;
				f << spend_money << " - Spend Money " << endl;
				f << date << " - Date " << "\n\n";
			}
		}
		f.close();
	}
	void FillCards() {
		double numbercard;
		string namecard;
		string PIB;
		string password;
		string typecard;
		double balance = 0;
		for (int i = 0; i < this->size; i++) {
			numbercard = Random(1, 20000000);
			string temp;
			cout << "Enter the TypeCard (Credit/Debit) \n >>> ";
			cin >> typecard;
			cout << "Enter the NameCard: ";
			cin >> namecard;
			cout << "PIB: ";
			cin >> PIB;
			cout << "Enter the password: ";
			cin >> password;
			int a = 0;
			while (password != temp) {
				a++;
				cout << "Confirm password: " << endl;
				cin >> temp;
				if (password != temp) {
					cout << "Incorrect password!" << a << " / 3" << endl;
						if (a == 3) { cout << "Your  3 / 3 " << endl; system("pause"); system("cls"); return FillCards(); }
				}
			}
			this->cards[i].CreateCard(numbercard, namecard, typecard, PIB, password, balance);
			cout << "\n\nThis Card was add!\n" << endl;
			system("pause");
			system("cls");
		}
	}
	~Finance() {
		delete[] category;
		delete[] cards;
	}
	void Menu() {
		cout << "1. Create Card" << endl;
		cout << "2. Show all Cards" << endl;
		cout << "3. Exit" << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: CreateCards();
			break;
		case 2: ShowCardInfo();
			break;
		case 3: exit(0);
			break;
		default: cout << "Incorrect count!" << endl; system("pause"); system("cls"); return Menu();
		}
	}
};

int main() {
	setlocale(LC_ALL, " ");
	srand(unsigned(time(NULL)));
	Finance h;
	h.Menu();


    return 0;
}

