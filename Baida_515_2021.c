/**
 * @file Baida_515_2021.c
 * @author Байда В.Р., гр. 515
 * @date 23 июня 2021
 * @brief практика
*/

#include <locale.h>
#include <string.h>
#include <time.h>

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief перемещивание символов в каждом слове строки
 * @param str строка
*/
void mix_text(char* str) {
	unsigned start = 0, end;

	for (unsigned i = 0; i < strlen(str); i++) {
		//нахождение позиций первого и последнего символа слова
		while (str[start] == ' ') start++;
		end = start;
		while (str[end + 1] != ' ' && str[end + 1] != '\0') end++;
		//перемешивание текста
		for (int j = start; j <= end; j++) {
			int swap = (end - start) != 0 ? (rand() % (end - start)) + start : start;
			char buff = str[j];
			str[j] = str[swap];
			str[swap] = buff;
		}
		//перемещение индекса на край слова
		i = start = end + 1;
	}
}

int main() {
	srand(time(0));
	
	char str[128] = { 0 };

	printf("Enter string:\t");
	fgets(str, 128, stdin);
	str[strlen(str) - 1] = '\0';

	mix_text(str);
	printf("Mixed string:\t%s\n\n", str);

	return 0;
}