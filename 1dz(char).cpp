#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;

bool checkPalindrome(char* buff)
{
	size_t len = strlen(buff);
	for (size_t i = 0; i < len / 2; i++)
	{
		if (buff[i] != buff[len - i - 1])
			return false;
	}
	return true;
}

int calculateValue(char* buff)
{
	int result = 0;
	char* token;
	char* context;
	token = strtok_s(buff, "+", &context);
	while (token)
	{
		result += std::atoi(token); 
		token = strtok_s(NULL, "+", &context);
	}
	return result;
}

char* getInitials(char* buff)
{
	char* context = NULL;
	char* F = strtok_s(buff, " ", &context);
	char* I = strtok_s(NULL, " ", &context);
	char* O = strtok_s(NULL, " ", &context);
	size_t len = strlen(F) + 6;
	char* result = new char[len];
	strncpy_s(result, len, I, 1);
	strcat_s(result, len, ".");
	strncat_s(result, len, O, 1);
	strcat_s(result, len, ". ");
	strcat_s(result, len, F);
	return result;
}

char* getBakName(char* fileName, char* ext)
{
	size_t len = strlen(fileName);
	
	size_t lenExt = strlen(ext);
	size_t lenName = len;
	for (int i = len - 1; i >= 0; i--)
		if (fileName[i] == '.')
		{
			lenName = i;
			break;
		}
	size_t newLen = lenName + lenExt + 2;
	char* result = new char[newLen];
	strncpy_s(result, newLen, fileName, lenName);
	strcat_s(result, newLen, ".");
	strcat_s(result, newLen, ext);

	return result;
}

int countWord(char* str, char* word)
{
	size_t strLen = strlen(str);
	size_t strWord = strlen(word);
	if (strWord > strLen)
		return 0;
	int cnt = 0;
	for (size_t i = 0; i < strLen - strWord + 1; i++)
	{
		bool found = true;
		for (size_t j = 0; j < strWord; j++)
			if (str[i + j] != word[j])
			{
				found = false;
				break;
			}
		if (found)
			cnt++;
	}
	return cnt;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const size_t BUFFER_SIZE = 255;
	char buff[BUFFER_SIZE];
	char buff2[BUFFER_SIZE];

	// 1
	cout << "Введите палиндром: ";
	cin.get(buff, BUFFER_SIZE);
	cin.get();
	cout << (checkPalindrome(buff) ? "Введен палиндром" : "Введен не палиндром") << endl;
	
	// 2
	cout << "Введите арифметическое выражение: ";
	cin.get(buff, BUFFER_SIZE);
	cin.get();
	cout << "Результат выражения: " << calculateValue(buff) << endl;

	// 3
	cout << "Введите ФИО: ";
	cin.get(buff, BUFFER_SIZE);
	cin.get();
	char* fio = getInitials(buff);
	cout << fio << endl;
	delete[] fio;
	
	// 4
	cout << "Введите имя файла: ";
	cin.get(buff, BUFFER_SIZE);
	cin.get();
	char ext[] = "bak";
	char* fName = getBakName(buff, ext);
	cout << fName << endl;
	delete[] fName;

	// 5
	cout << "Введите символьную строку: ";
	cin.get(buff, BUFFER_SIZE);
	cin.get();
	cout << "Введите искомое слово: ";
	cin.get(buff2, BUFFER_SIZE);
	cin.get();
	cout << "Колличество вхождений: " << countWord(buff, buff2) << endl;
}
