/******************
Name:
ID:
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	int menuOption = 0;
	while (menuOption != 7) {
		printf("Choose an option:\n\t1. Happy Face\n\t2. Balanced Number\n\t3. Generous Number\n\t4. Circle Of Joy\n\t5. Happy Numbers\n\t6. Festival of Laughter\n\t7. Exit\n");
		scanf(" %d", &menuOption);
		switch (menuOption) {
			// Case 1 : Draw a happy face with given characters for eyes, nose and mouth and a given size
			case 1 :
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
				break;
			// Case 2 : Determine if the sum of all digits to the left of the middle digit(s) and the sum of all digits to the right of the middle digit(s) are equal 
			case 2 :
				int digitNum = 0, digitSumL = 0, digitSumR = 0, digitCount = 0, digitTempnum = 0, digitPosition = 1;
				printf("Enter a number:\n");
				scanf("%d", &digitNum);
				// Check if the number is positive, if not, ask the user to enter a new number
				while (digitNum < 1) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &digitNum);
				}
				// Calculate the number of digits
				digitTempnum = digitNum;
				while (digitTempnum != 0) {
					digitTempnum /= 10;
					digitCount++;
				}
				// Calculate the sum of the digits to the left and right of the middle digit(s)
				digitTempnum = digitNum;
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
				break;
			// Case 3 : determine whether the sum of the proper divisors of a number is greater than the itself
			case 3 :
				int abundantNum = 0, abundantSum = 0;
				printf("Enter a number:\n");
				scanf("%d", &abundantNum);
				// Check if the number is positive, if not, ask the user to enter a new number
				while (abundantNum < 1) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &abundantNum);
				}
				// Calculate the sum of the proper divisors
				for (int i = 1; i < abundantNum; i++) {
					if (abundantNum % i == 0) {
						abundantSum += i;
					}
				}
				if (abundantSum > abundantNum) {
					printf("This number is generous!\n");
				} else {
					printf("This number does not share.\n");
				}
				break;
			// Case 4 : determine whether a number and it's reversed version are prime numbers
			case 4 :
			int primeNum = 0;
			printf("Enter a number:\n");
			scanf("%d", &primeNum);
			while (primeNum < 1) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &primeNum);
				}
			
			break;
			// Case 5 : Happy numbers: Print all the happy numbers between 1 to the given number.
			// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
			/* Examples:
			Happy :) : 7, 10
			Not Happy :( : 5, 9
			Please notice: the number has to be bigger than 0.
			*/
			case 5 :
			break;
			// Case 6 : Festival of Laughter - Prints all the numbers between 1 the given number:
			// and replace with "Smile!" every number that divided by the given smile number
			// and replace with "Cheer!" every number that divided by the given cheer number
			// and replace with "Festival!" every number that divided by both of them
			/* Example:
			6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
			*/
			case 6 :
			break;
			// Case 7 : Exit the program
			case 7 :
				printf("Thank you for your journey through Numeria!\n");
				break;
			// Menu option input validation
			default :
				printf("This option is not available, please try again.\n");
				break;
		}
	}
	return 0;
}