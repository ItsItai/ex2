/******************
Name: 
ID: 
Assignment: ex2
*******************/

#include <stdio.h>
#define DECIMAL_BASE 10
#define FESTIVAL_CORRECT_FORMAT 2

int main() {
	int menuOption = 0;
	while (menuOption != 7) {
		printf("Choose an option:\n\t1. Happy Face\n\t2. Balanced Number\n\t3. Generous Number\n\t4. Circle Of Joy\n\t5. Happy Numbers\n\t6. Festival Of Laughter\n\t7. Exit\n");
		scanf(" %d", &menuOption);
		switch (menuOption) {
			// Case 1 : Draw a happy face with given characters for eyes, nose and mouth and a given size
			case 1 : 
				char faceEyes = 0, faceNose = 0, faceMouth = 0;
				int faceSize = 0;
				printf("Enter symbols for the eyes, nose, and mouth:\n");
				scanf(" %c %c %c", &faceEyes, &faceNose, &faceMouth);
				printf("Enter face size:\n");
				scanf("%d", &faceSize);
				// Check if the face size is above the minimum size and is an odd number, if not, ask the user to enter a new size
				while (faceSize < 1 || faceSize % 2 == 0) {
					printf("The face's size must be an odd and positive number, please try again:\n");
					scanf("%d", &faceSize);
				}
				// Print the eyes and the space between them
				printf("%c", faceEyes);
				for (int i = 0; i < faceSize; i++) {
					printf(" ");
				}
				printf("%c\n", faceEyes);
				// Print the space before the nose
				for (int i = 0; i <= faceSize / 2; i++) {
					printf(" ");
				}
				// Print the nose
				printf("%c", faceNose);
				// Print the space after the nose
				for (int i = 0; i <= faceSize / 2; i++) {
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
					digitTempnum /= DECIMAL_BASE;
					digitCount++;
				}
				// Calculate the sum of the digits to the left and right of the middle digit(s)
				digitTempnum = digitNum;
				while (digitTempnum != 0) {
					// Get the current digit
					int digitCurrent = digitTempnum % DECIMAL_BASE;
					digitTempnum /= DECIMAL_BASE;
					// Check if the digit is in the left or right side of the middle digit(s) and add it to the appropriate sum
					if (digitPosition <= digitCount / 2) {
						digitSumL += digitCurrent;
					}
					else if (digitPosition > (digitCount + 1) / 2)  {
						digitSumR += digitCurrent;
					}
					digitPosition++;
				}
				if (digitSumL == digitSumR) {
					printf("This number is balanced and brings harmony!\n");
				}
				else {
					printf("This number isn't balanced and destroys harmony.\n");
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
				// Find the sum of the proper divisors of the number and sum them
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
				int primeNum = 0, primeFlag = 1, primeFlagreversed = 1, primeReversed = 0;
				printf("Enter a number:\n");
				scanf("%d", &primeNum);
				// Check if the number is positive, if not, ask the user to enter a new number
				while (primeNum < 1) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &primeNum);
				}
				// Flag the number as not prime if it's 1
				if (primeNum == 1) {
					primeFlag = 0;
				// Check if the number is prime by checking if it's divisible by any number other than 1 and itself
				} else {
					for (int i = 2; i < primeNum; i++) {
						if (primeNum % i == 0) {
							primeFlag = 0;
							break;
						}
					}
				}
				if (primeFlag == 1) {
					// Reverse the number
					while (primeNum != 0) {
						int digit = primeNum % DECIMAL_BASE;
						primeReversed = primeReversed * DECIMAL_BASE + digit;
						primeNum /= DECIMAL_BASE;
					}
					// Check if the number is prime by checking if it's divisible by any number other than 1 and itself
					for (int i = 2; i < primeReversed; i++) {
						if (primeReversed % i == 0) {
							primeFlagreversed = 0;
							break;
						}
					}
					if (primeFlagreversed == 1) {
					printf("This number completes the circle of joy!\n");
					} else {
						printf("The circle remains incomplete.\n");
					}
				} else {
					printf("The circle remains incomplete.\n");
				}
				break;
			// Case 5 : Print all the happy numbers between 1 to the given number.
			case 5 :
				int happyNum = 0;
				printf("Enter a number:\n");
				scanf("%d", &happyNum);
				// Check if the number is positive, if not, ask the user to enter a new number
				while (happyNum < 1) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &happyNum);
				}
				printf("Between 1 and %d only these numbers bring happiness: ", happyNum);
				// Go through all the numbers between 1 and the given number (including 1 and the given number)
				for (int i = 1; i <= happyNum; i++) {
					int num = i;
					/* Avoid infinite loops by checking the sum
					 If it is 1 then the number is happy
					 If it is one of the numbers 4, 16, 37, 58, 89, 145, 42, 20 then the number is not happy since all numbers that are not happy eventually enter this infinite cycle of sums
					 (And I just to clarify, I would have used an array for the not happy cycle if it was allowed)*/
					while (num != 1 && num != 4 && num != 16 && num != 37 && num != 58 && num != 89 && num != 145 && num != 42 && num != 20) {
						int sum = 0;
						// Calculate the sum of the squares of the digits
						while (num > 0) {
							int digit = num % DECIMAL_BASE;
							sum += digit * digit;
							num /= DECIMAL_BASE;
						}
						num = sum;
					}
					// Print the number if it's a happy number
					if (num == 1) {
						printf("%d ", i);
					}
				}
				printf("\n");
				break;
			/* Case 6 : Festival of Laughter - Prints all the numbers between 1 and the given number.
				If a number is divisible by the smile number, it prints "Smile!".
				If a number is divisible by the cheer number, it prints "Cheer!".
				If a number is divisible by both, it prints "Festival!".
				Otherwise, it prints the number itself.*/
			case 6 :
				int festivalSmile = 0, festivalCheer = 0, festivalMax = 0, festivalFormat = 0;
				printf("Enter a smile and cheer number:\n");
				festivalFormat = scanf(" smile: %d , cheer: %d", &festivalSmile, &festivalCheer);
				// Clear the buffer
				scanf("%*[^\n]%*c");
				// Validate the input format and check if the numbers are positive and different, if not, ask the user to enter new numbers
				while (festivalFormat != FESTIVAL_CORRECT_FORMAT || festivalSmile == festivalCheer || festivalSmile < 1 || festivalCheer < 1 ) {
					printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
					festivalFormat = scanf(" smile: %d , cheer: %d", &festivalSmile, &festivalCheer);
					// Clear the buffer
					scanf("%*[^\n]%*c");
				}
				printf("Enter maximum number for the festival:\n");
				scanf("%d", &festivalMax);
				// Check if the number is positive, if not, ask the user to enter a new number
				while (festivalMax < 1) {
					printf("Only positive maximum number is allowed, please try again:\n");
					scanf("%d", &festivalMax);
				}
				// Print the numbers based on the festival rules
				for (int i = 1; i <= festivalMax; i++) {
					if (i % festivalSmile == 0 && i % festivalCheer == 0) {
						printf("Festival!\n");
					} else if (i % festivalSmile == 0) {
						printf("Smile!\n");
					} else if (i % festivalCheer == 0) {
						printf("Cheer!\n");
					} else {
						printf("%d\n", i);
					}
				}
				break;
			// Case 7 : Exit the program
			case 7 :
				printf("Thank you for your journey through Numeria!\n");
				break;
			// Default : Print an error message and ask the user to enter a new option (menu option input validation)
			default :
				printf("This option is not available, please try again.\n");
				break;
		}
	}
	return 0;
}