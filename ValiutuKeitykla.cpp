// ValiutuuKeitykla.cpp: Allows the user to compare, purchase or sell currency.
// Author: Rokas Karosas
// Date: 2023 September

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Function that allows the user to select a currency to exchange.
int CurrencySelectionTable() {
	cout << "Iveskite valiutos, kuria norite pasirinkti, skaiciu:" << endl;
	cout << "1. EUR" << endl;
	cout << "2. GBP" << endl;
	cout << "3. USD" << endl;
	cout << "4. INR" << endl;

	int temp_number;
	cin >> temp_number;
	return temp_number;
}

// Function that compares how much currency you will receive.
double Comparision(double amount, double Currency2) {
	double rate;
	rate = amount * Currency2;
	return rate;
}

int main() {
	string CurrencyNames[5] = { ".", "EUR", "GBP", "USD", "INR" };

	double General[5];
	double Purchase[5];
	double Sell[5];

	General[1] = 1.0000; // EUR
	General[2] = 0.8593; // GBP
	General[3] = 1.0713; // USD
	General[4] = 88.8260; // INR

	Purchase[1] = 1.000; // EUR
	Purchase[2] = 0.8450; // GBP
	Purchase[3] = 1.0547; // USD
	Purchase[4] = 85.2614; // INR

	Sell[1] = 1.0000; // EUR
	Sell[2] = 0.9060; // GBP
	Sell[3] = 1.1309; // USD
	Sell[4] = 92.8334; // INR

	cout << "Pasirinkite ka noretume daryti? Iveskite veiksmo numeri:" << endl;

	cout << "1. Palyginti valiutas" << endl;
	cout << "2. Nusipirkti valiutos" << endl;
	cout << "3. Parduoti valiuta" << endl;

	int action;
	cin >> action;

	// Comparing currency
	if (action == 1) {
		cout << "Iveskite kiek euru turite" << endl;
		double amount;
		cin >> amount;

		cout << "Pasirinkite valiuta, su kuria norite palyginti eurus" << endl;
		int comparision_currency = CurrencySelectionTable();

		double rate = Comparision(amount, General[comparision_currency]);

		cout << "Jusu " << amount << " EUR yra verti " << fixed << setprecision(2) << rate;
		cout << " " << CurrencyNames[comparision_currency] << endl;
	}

	// Buying currency
	else if (action == 2) {
		cout << "Pasirinkite valiuta, kuria pirksite" << endl;
		int buying_currency = CurrencySelectionTable();

		// used to check if user doesn't enter more than he can purchase.
		// double rate = Comparision(amount, Purchase[buying_currency]);

		cout << "Kiek " << CurrencyNames[buying_currency] << " norite isigyti?" << endl;
		double buying_amount;
		cin >> buying_amount;

		cout << "Norint isigyti " << buying_amount << " " << CurrencyNames[buying_currency] << endl;
		cout << "Sumokesite: " << fixed << setprecision(2) << (buying_amount / Purchase[buying_currency]) << " EUR" << endl;


	}

	// Selling currency
	else if (action == 3) {
		cout << "Iveskite, kokia valiuta norite parduoti:" << endl;
		int selling_currency = CurrencySelectionTable();

		cout << "Kiek " << CurrencyNames[selling_currency] << " norite parduoti?" << endl;
		double selling_amount;
		cin >> selling_amount;

		cout << "Norint parduoti: " << selling_amount << " " << CurrencyNames[selling_currency] << endl;
		cout << "Gausite: " << fixed << setprecision(2) << (selling_amount / Sell[selling_currency]) << CurrencyNames[1] << endl;


		//double rate = Comparision(amount, Sell[selling_currency]);
	}

	return 0;
}