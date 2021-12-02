/*
				| Copyright 2021 | MaximFLUNN | Maxim Filatov Group: 3821B1PR2 |
				|      GitHub profile link: https://github.com/MaximFLUNN      |
-------------------------------------------------------------------------------------------------------
| [ENG] Task 4: To develop the program "Electronic cash register" Must be able to generate a receipt and note commands: |
| 1) "scan" the next product, 2) display a description of the scanned product |
| 3) add information about the product to the check, 4) generate a receipt for the purchase, 5) calculate the total amount to be paid |
| [RU] Task 4: Разработать программу «Электронная касса» Должна уметь формировать чек и меть комманды: |
| 1) «сканировать» очередной товар, 2) вывести описание отсканированного товара |
| 3) добавить данные о товаре в чек, 4) сформировать чек за покупку, 5) рассчитать итоговую сумму к оплате |
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 20
#define SIZEX 60

void main() {
	srand(time(NULL));

	// | [ENG] Array product | [RU] Список продуктов |
	char product[SIZE][SIZEX] = {
		{"Notebook MagicBook r7 3700U"},
		{"Notebook MagicBook r5 4500U"},
		{"Notebook MSI Pulse GL76 i5 11400H"},
		{"Notebook ASUS ROG Strix G15 r7 4800H"},
		{"Notebook Acer Nitro 5 i7 10750H"},
		{"Notebook Apple MacBook Air M1 7 core"},
		{"Notebook GIGABYTE G5 KC i5 10500H"},
		{"Ultrabook MSI Summit E13 i5 1135G7"},
		{"Ultrabook Dell XPS i5 10210U"},
		{"Ultrabook ASUS ZenBook 14 i7 1165G7"},
		{"Ultrabook LG Gram 14 i5 1135G7"},
		{"Ultrabook ASUS ZenBook Flip 13 i7 1165G7"},
		{"Ultrabook ASUS ZenBook 14 i5 1135G7"},
		{"Smartphone Xiaomi Mi 10T Pro 256 GB"},
		{"Smartphone Samsung Galaxy A72 256 GB"},
		{"Smartphone Samsung Galaxy S20 FE 128 GB"},
		{"Smartphone POCO F2 Pro 256 GB"},
		{"Smartphone Huawei P40 128 GB"},
		{"Smartphone Apple iPhone Xr 64 GB"},
		{"Smartphone ASUS Zenfone 8 128 GB"}
	};

	// | [ENG] Array price product | [RU] Список цен |
	int price[SIZE] = {
		67990,60100,100000,99000,100785,
		121765,78900,99450,88120,111900,
		46870,120890,113455,76890,89340,
		160000,80000,111990,80880,99450
	};
	// | [ENG] Variables | [RU] Переменные |
	int historylist[SIZEX];
	int discount[SIZE];
	int barkode[SIZE];
	int receipt[SIZE];
	int x, check, lastproduct, flagcontinue = 0, flagaddproduct = 0, w = 0, count = 0;
	char MenuChoose;
	float amounttopay, amounttopayfullprice, fulldiscount, totalprice;

	// | [ENG] Main cycle (endless) | [RU] Основной цикл |
	while (1) {
		if (w == 0) {


			// | [ENG] Generates random unique barkode | [RU] Генерация случайного уникального штрихкода |
			for (int i = 0; i < SIZE; i++) {
				x = rand() % 8999 + 1000;
				check = 0;
				for (int g = 0; g < i; g++) {
					if (x == barkode[g]) {
						check = 1;
					}
				}
				if (check == 0) {
					receipt[i] = 0;
					barkode[i] = x;
					i++;
				}
				i--;
			}

			// | [ENG] Generates random discount (0% - 50%) | [RU] Генерация случайной скидки (0% - 50%) |
			for (int i = 0; i < SIZE; i++) {
				discount[i] = rand() % 50;
			}
			printf("| Welcome!\n");
			w++;
			MenuChoose = '+';
		}
		// | [ENG] Menu choosing | [RU] Меню выбора |
		if (MenuChoose == '+') {
			printf("|\n| To scan an item, press '1'\n| For product information press '2'\n| To add data about the product to the receipt, press '3'\n| To outpute a purchase receipt, press '4'\n| To calculate the total amount to be paid, press '5'\n| To output the final check, press '6'\n| To remove the last added product press '7'\n| To show the product menu press '0'\n| Press + to re-display the menu\n|");
		}
		printf("\n| Input: ");
		scanf("%s", &MenuChoose);

		// | [ENG] Print all product info | [RU] Вывод информации о всей продукции |
		if (MenuChoose == '0') {
			printf("|");
			for (int i = 0; i < SIZE; i++) {
				printf("\n| Barkode: %d | Name: %s | Price: %d (Rub) | Discount: %d%% |", barkode[i], product[i], price[i], discount[i]);
			}
			printf("\n|");
		}

		// | [ENG] Scan barkode | [RU] Сканирование штрихкода |
		if (MenuChoose == '1') {
			x = 0;
			printf("|\n| Input barkode: ");
			scanf("%d", &check);
			if (check >= 1000 & check <= 9999) {
				for (int i = 0; i < SIZE; i++) {
					if (check == barkode[i]) {
						printf("|\n| Product finded :)\n|");
						lastproduct = i;
						x = i = SIZE;
						flagcontinue = 1;
					}
				}
			}
			if (x != SIZE) {
				printf("|\n| Invalid barkode :(\n|");
			}
		}
		// | [ENG] Print info last scanned item | [RU] Вывод информации о послежнем просканированном продукте | 
		if (MenuChoose == '2' & flagcontinue == 1) {
			printf("|\n| Last scanned product ->");
			printf("\n| Barkode: %d | Name : %s | Price : %d.00 (Rub) | Discount : %d%% |\n|", barkode[lastproduct], product[lastproduct], price[lastproduct], discount[lastproduct]);
		}
		// | [ENG] Add product in check | [RU] Добавление продукта в чек |
		else if (MenuChoose == '3' & flagcontinue == 1) {
			printf("|\n| Product add in recipe\n|");
			receipt[lastproduct]++;
			historylist[count] = barkode[lastproduct];
			count++;
			flagaddproduct = 1;
		}

		// | [ENG] Remove the last added product | [RU] Удаление последнего добавленного продукта |
		else if (MenuChoose == '7' & flagcontinue == 1 & historylist[0] != 0 & flagaddproduct != 0) {
			count--;
			for (int i = 0; i < SIZE; i++) {
				if (historylist[count] == barkode[i]) {
					historylist[count] = 0;
					receipt[i]--;
				}
			}
			printf("|\n| Product deleted\n|");
		}
		else if (MenuChoose == '7' & flagaddproduct == 0) {
			printf("|\n| Check is clear!\n");
		}
		if (historylist[0] == 0) {
			flagaddproduct = 0;
		}

		// | [ENG] Error if no product has been scanned | [RU] Ошибка если продукт не был просканирован |
		else if ((MenuChoose == '2' || MenuChoose == '3' || MenuChoose == '7') & flagcontinue != 1) {
			printf("|\n| Invalid opetation!\n|");
		}

		//| [ENG] Print check | [RU] Вывод чека |
		if (MenuChoose == '4' & flagaddproduct == 1) {
			printf("| List of goods:\n|");
			for (int i = 0, g = 1, fastprice; i < SIZE; i++) {
				if (receipt[i] != 0) {
					printf("\n| %d. Name : %s ", g, product[i]);
					if (receipt[i] == 1) {
						printf("\n| -> Price : %d.00 (Rub)", price[i]);
					}
					else if (receipt[i] > 1) {
						fastprice = receipt[i] * price[i];
						printf("\n| -> %d x %d.00 (Rub)", receipt[i], price[i]);
						printf("\n| -> Price : %d.00 (Rub)", fastprice);

					}
					g++;
				}
			}
		}

		// | [ENG] Void check error | [RU] Ошибка если чек пуст |
		else if ((MenuChoose == '4' || MenuChoose == '5' || MenuChoose == '6') & flagaddproduct != 1) {
			printf("|\n| No products added to the check!\n|");
		}

		// | [ENG] Full price (Amount to pay) | [RU] Расчёт полной цены к оплате|
		if ((MenuChoose == '5' || MenuChoose == '6') & flagaddproduct == 1) {
			amounttopay = amounttopayfullprice = fulldiscount = totalprice = 0;
			for (int i = 0; i < SIZE; i++) {
				if (receipt[i] != 0) {
					amounttopayfullprice += receipt[i] * price[i];
					amounttopay += receipt[i] * (price[i] * (0.01 * (100.00 - discount[i])));
				}
			}
			if (MenuChoose == '5') {
				printf("|\n| Amount to pay: %.2f (Rub)\n|", amounttopay);
			}

			// | [ENG] Full list of goods (Check) | [RU] Полный список продуктов | 
			if (MenuChoose == '6') {
				printf("|\n| Full list of goods:\n|\n");
				for (int i = 0, g = 1, fastprice; i < SIZE; i++) {
					if (receipt[i] != 0) {
						printf("| %d. Name : %s ", g, product[i]);
						if (receipt[i] == 1) {
							printf("\n| -> Price : %d.00 (Rub)", price[i]);
							printf("\n| -> Discount : %d%%", discount[i]);
							fulldiscount += price[i] - (price[i] * (0.01 * (100 - discount[i])));
							totalprice = price[i] * (0.01 * (100 - discount[i]));
							printf("\n| -> Total price product : %.2f (Rub)\n", totalprice);
						}
						else if (receipt[i] > 1) {
							fastprice = receipt[i] * price[i];
							fulldiscount += receipt[i] * price[i] - (receipt[i] * (price[i] * (0.01 * (100 - discount[i]))));
							totalprice = receipt[i] * (price[i] * (0.01 * (100 - discount[i])));
							printf("\n| -> %d x %d.00 (Rub)", receipt[i], price[i]);
							printf("\n| -> Price : %d.00 (Rub)", fastprice);
							printf("\n| -> Discount : %d%%", discount[i]);
							printf("\n| -> Total price product : %.2f (Rub)\n", totalprice);
						}
						g++;
					}
				}
				w--;
				printf("|\n================================\n|");
				printf("\n| Full price :  %.2f", amounttopayfullprice);
				printf("\n| Discount :   -%.2f", fulldiscount);
				printf("\n| Total price : %.2f\n", amounttopay);
				printf("|\n| Goodbye!\n|\n| ");
				system("pause");
				flagcontinue = flagaddproduct = amounttopay = amounttopayfullprice = fulldiscount = totalprice = 0;
				system("cls"); // | [ENG] Clear console | [RU] Чистка консоли
			}
		}
	}
}