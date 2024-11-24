/******************
Name:
ID:
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	int menuOption = 0;
	while (1) {
		printf("Choose an option:\n\t1. Happy Face\n\t2. Balanced Number\n\t3. Generous Number\n\t4. Circle Of Joy\n\t5. Happy Numbers\n\t6. Festival of Laughter\n\t7. Exit\n");
		scanf("%d", &menuOption);
		// Case 1: Draw a happy face with given characters for eyes, nose and mouth and a given size
		if (menuOption == 1) {
			char faceEyes, faceNose, faceMouth;
			int faceSize = 0;
			printf("Enter symbols for the eyes, nose, and mouth:\n");
			scanf(" %c %c %c", &faceEyes, &faceNose, &faceMouth);
			printf("Enter face size:\n");
			scanf("%d", &faceSize);
			// Check if the face size is an odd and positive number, if not, ask the user to enter a new number
			while (faceSize <= 0 || faceSize % 2 == 0) {
				printf("The face's size must be an odd and positive number, please try again:\n");
				scanf("%d", &faceSize);
			}
			// Print the eyes
			printf("%c", faceEyes);
			for (int i = 0; i < faceSize; i++) {
				printf(" ");
			}
			printf("%c\n", faceEyes);
			// Print the nose
			for (int i = 0; i < (faceSize / 2) + 1; i++) {
				printf(" ");
			}
			printf("%c", faceNose);
			for (int i = 0; i < (faceSize / 2) + 1; i++) {
				printf(" ");
			}
			// Print the mouth
			printf("\n\\");
			for (int i = 0; i < faceSize; i++) {
				printf("%c", faceMouth);
			}
			printf("/\n");
		continue;
		}
		// Case 2: Determine if the sum of all digits to the left of the middle digit(s) and the sum of all digits to the right of the middle digit(s) are equal 
		else if (menuOption == 2) {
			int digitNumber = 0, digitSumL = 0, digitSumR = 0, digitCount = 0, digitTempnum = 0, digitPosition = 1;
			printf("Enter a number:\n");
			// Check if the number is positive, if not, ask the user to enter a new number
			while (digitNumber < 1) {
				printf("Only positive number is allowed, please try again:\n");
				scanf("%d", &digitNumber);
			}
			// Calculate the number of digits
			digitTempnum = digitNumber;
			while (digitTempnum != 0) {
				digitTempnum /= 10;
				digitCount++;
			}
			// Calculate the sum of the digits to the left and right of the middle digit(s)
			digitTempnum = digitNumber;
			while (digitTempnum != 0) {
				int digitCurrent = digitTempnum % 10;
				digitTempnum /= 10;
				if (digitPosition <= digitCount / 2) {
					digitSumL += digitCurrent;
				}
				else if (digitPosition > (digitCount + 1) / 2)  {
					digitSumR += digitCurrent;
				}
				digitPosition++;
			}
			if (digitSumL == digitSumR) {
				printf("Balanced\n");
			}
			else {
				printf("Not Balanced\n");
			}
		continue;
		}
		// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
		/* Examples:
		Abudant: 12, 20, 24
		Not Abudant: 3, 7, 10
		Please notice: the number has to be bigger than 0. */
		else if (menuOption == 3) {
		}
		// Case 4: determine whether a number is a prime.
		/* Examples:
		This one brings joy: 3, 5, 11
		This one does not bring joy: 15, 8, 99
		Please notice: the number has to be bigger than 0. */
		else if (menuOption == 4) {
		}
		// Happy numbers: Print all the happy numbers between 1 to the given number.
		// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
		/* Examples:
		Happy :) : 7, 10
		Not Happy :( : 5, 9
		Please notice: the number has to be bigger than 0.
		*/
		else if (menuOption == 5) {
		}
		// Case 6: Festival of Laughter - Prints all the numbers between 1 the given number:
		// and replace with "Smile!" every number that divided by the given smile number
		// and replace with "Cheer!" every number that divided by the given cheer number
		// and replace with "Festival!" every number that divided by both of them
		/* Example:
		6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
		*/
		else if (menuOption == 6) {
		}
		// Case 7: Exit the program
		else if (menuOption == 7) {
			printf("Thank you for your journey through Numeria!\n");
			break;
		}
		// Menu option input validation
		else {
			printf("This option is not available, please try again.\n");
			continue;
		}
	return 0;
	}
}