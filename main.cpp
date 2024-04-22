#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <clocale>

using namespace std;

void zadanie_1() 
{
	string fio;
	cout << "������� ��� (�������� ������ �� ��������): ";
	getline(cin, fio);

	string lastName;
	string firstName;
	string middleName;

	int space1 = fio.find(' ');
	int space2 = fio.find(' ', space1 + 1);


	lastName = fio.substr(0, space1);


	if (space2 != string::npos) {
		firstName = fio.substr(space1 + 1, space2 - space1 - 1);
	}
	else {
		firstName = fio.substr(space1 + 1);
	}


	if (space2 != string::npos) {
		middleName = fio.substr(space2 + 1);
	}


	cout << "������� ���. ��������.: ";
	cout << lastName << " ";
	if (!firstName.empty()) {
		cout << firstName[0] << ".";
	}
	if (!middleName.empty()) {
		cout << middleName[0];
	}
	cout << endl;

}
void zadanie_2()
{
	int n;
	cout << "������� ����� �� 51 �� 100(�� ������������):";
	cin >> n;

	if ((n > 51) and (n < 100))
	{
		int count = 0;

		for (int ten = 0; ten <= n / 10; ten++)
		{
			for (int five = 0; five <= (n - ten * 10) / 5; five++)
			{
				for (int dub = 0; dub <= (n - ten * 10 - five * 5) / 2; dub++)
				{
					int one = n - ten * 10 - five * 5 - dub * 2;

					if (one >= 0)
					{
						count++;
					}
				}
			}
		}
		cout << "���-�� �������� ������: " << count;
	}
	
	else 
	{ 
		cout << "������� ������������ ����� n."; 
	}

}
void zadanie_6() 
{
	int result = 0;
	for (int i = 1; i <= 300; i++) 
	{
		int delitel = 0;
		
		for (int n = 1; n < i; n++) 
		{
			if (i % n == 0) 
			{ 
				delitel++; 
			}
		}
		if (delitel == 5) 
		{ 
			result++;
		}
	}
	cout << "���-�� ����� ����� � ������� 5 ���������: " << result << endl;
}
void zadanie_5() {
	vector <int> mark;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(2, 5);

	for (int i = 0; i <= 21; i++) 
	{
		mark.push_back(dis(gen));
	}

	int mark5 = 0, mark4 = 0, mark3 = 0, mark2 = 0;

	for (int n = 0; n < mark.size(); n++) 
	{
		if (mark[n] == 5) 
		{ 
			mark5++; 
		}
		if (mark[n] == 4) 
		{
			mark4++; 
		}
		if (mark[n] == 3) 
		{ 
			mark3++; 
		}
		if (mark[n] == 2) 
		{ 
			mark2++; 
		}
	}

	cout << "����� 5: " << mark5 << endl << "����� 4: " << mark4 << endl << "����� 3: " << mark3 << endl << "����� 2: " << mark2 << endl;
	
}
void zadanie_8() {
	int n;
	cout << "������� ���������� �������: " << endl;
	cin >> n;
	if ((n >= 1) and (n <= 1188)) 
	{
		int month = n % 12;
		int year = (n - month) / 12;

		cout << "���-�� ���: " << year << endl << "���-�� �������: " << month << endl;
	}

	else 
	{ 
		cout << "������� ���������� ������� �� 1 �� 1188."; 
	}

}
void zadanie_4() {
	vector<string> kards = { "6", "7", "8", "9", "10", "�����", "����", "������", "���" };

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, kards.size() - 1);

	cout << "��� ������ �����: " << kards[dis(gen)] << endl;
}
void zadanie_9() {
	string url;
	cout << "������� URL: ";
	getline(cin, url);
	string protocol, host, endpoint;
	vector<string> args;

	size_t colonPos = url.find(':');
	if (colonPos != std::string::npos) {
		protocol = url.substr(0, colonPos);
		colonPos += 3;
	}

	size_t slashPos = url.find('/', colonPos);
	if (slashPos != string::npos) {
		host = url.substr(colonPos, slashPos - colonPos);
		size_t questionPos = url.find('?', slashPos);
		if (questionPos != string::npos) {
			endpoint = url.substr(slashPos, questionPos - slashPos);
			string argsStr = url.substr(questionPos + 1);
			size_t pos = 0;
			while (pos < argsStr.size()) {
				size_t ampersandPos = argsStr.find('&', pos);
				if (ampersandPos != string::npos) {
					args.push_back(argsStr.substr(pos, ampersandPos - pos));
					pos = ampersandPos + 1;
				}
				else {
					args.push_back(argsStr.substr(pos));
					break;
				}
			}
		}
		else {
			endpoint = url.substr(slashPos);
		}
	}
	else {
		host = url.substr(colonPos);
	}

	cout << "��������: " << protocol << endl;
	cout << "����: " << host << endl;
	cout << "End point: " << endpoint << endl;
	cout << "Args:";
	for (const auto& arg : args) {
		cout << " " << arg << ";";
	}
	cout << endl;
}
void zadanie_3() 
{
	for (int x = 0; x <= 100; x++) 
	{
		for (int y = 0; y <= 100; y++) 
		{
			if (19 * x + 9 * y == 100) 
			{
				int z = 100 - x - y;
				cout << "����: " << x << endl << "������: " << y << endl << "������: " << z << endl << "������ ������� ����.";
			}
		}
	}
	
}


int main() 
{
	setlocale(LC_ALL, "Russian");
	zadanie_3();
	return 0;
}