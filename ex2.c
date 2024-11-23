/******************
Name:
ID:
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	int menuOption, faceSize = 0, digitNumber, digitSumL = 0, digitSumR = 0, digitCount = 0, digitTempnum;
	char faceEyes, faceNose, faceMouth;
	while (menuOption != 7) {
		printf("Choose an option:\n\t1. Happy Face\n\t2. Balanced Number\n\t3. Generous Number\n\t4. Circle Of Joy\n\t5. Happy Numbers\n\t6. Festival of Laughter\n\t7. Exit\n");
		scanf("%d", &menuOption);
		if (menuOption == 7) {
			printf("Thank you for your journey through Numeria!\n");
				break;
		}
		if ((menuOption > 7) || (menuOption < 1)) {
			printf("This option is not available, please try again.\n");
			continue;
		}
		// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse and size
		if (menuOption == 1) {
			printf("Enter symbols for the eyes, nose, and mouth:\n");
			scanf("%c %c %c", &faceEyes, &faceNose, &faceMouth);
			printf("Enter face size:\n");
			scanf("%d", &faceSize);
			while ((faceSize < 0) || (faceSize % 2 == 0)) {
				printf("The face's size must be an odd and positive number, please try again:\n");
				scanf("%d", &faceSize);
			}
			printf("\n%c", faceEyes);
			for (int i = 0; i < faceSize; i++) {
			printf(" ");
			}
			printf("%c\n", faceEyes);
			for (int i = 0; i < faceSize / 2; i++) {
				printf(" ");
			}
			printf("%c", faceNose);
			for (int i = 0; i < faceSize / 2; i++) {
				printf(" \n");
			}
			printf("\\");
			for (int i = 0; i < faceSize; i++) {
				printf("%c", faceMouth);
			}
			printf("/\n");
		}
		// Case 2: determine whether the sum of all digits to the left of the middle digit(s) and the sum of all digits to the right of the middle digit(s) are equal
		if (menuOption == 2) {
			printf("Enter a number:\n");
			do{
				scanf("%d", &digitNumber);
				if (digitNumber < 1) {
					printf("Only positive number is allowed, please try again:\n");
				}
			} while (digitNumber < 1);
			digitTempnum = digitNumber;
			while (digitTempnum != 0) {
				digitTempnum /= 10;
				digitCount++;
			}
			digitTempnum = digitNumber;
			for (int i = 0; i < digitCount / 2; i++) {
				digitSumL += digitTempnum % 10;
				digitTempnum /= 10;
			}
			digitTempnum /= 10;
			for (int i = 0; i < digitCount / 2; i++) {
				digitSumR += digitTempnum % 10;
				digitTempnum /= 10;
			}
			if (digitSumL == digitSumR) {
				printf("Balanced\n");
			}
			else {
				printf("Not Balanced\n");
			}
		}
	// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
	/* Examples:
	Abudant: 12, 20, 24
	Not Abudant: 3, 7, 10
	Please notice: the number has to be bigger than 0.
	*/

	// Case 4: determine wether a number is a prime.
	/* Examples:
	This one brings joy: 3, 5, 11
	This one does not bring joy: 15, 8, 99
	Please notice: the number has to be bigger than 0.
	*/
    

	// Happy numbers: Print all the happy numbers between 1 to the given number.
	// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
	/* Examples:
	Happy :) : 7, 10
	Not Happy :( : 5, 9
	Please notice: the number has to be bigger than 0.
	*/

	// Festival of Laughter: Prints all the numbers between 1 the given number:
	// and replace with "Smile!" every number that divided by the given smile number
	// and replace with "Cheer!" every number that divided by the given cheer number
	// and replace with "Festival!" every number that divided by both of them
	/* Example:
	6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
	*/
	return 0;
	}
}