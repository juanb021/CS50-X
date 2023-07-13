#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validate_card(const char *number)
{
    // Convert the number into a list of individual digits.
    int digits[16];
    int length = strlen(number);
    for (int i = 0; i < length; i++)
    {
        if (number[i] < '0' || number[i] > '9')
        {
            return 0; // Not a valid integer
        }
        digits[i] = number[i] - '0';
    }

    // Go through every second digit.
    int sum = 0;
    for (int i = length - 2; i >= 0; i -= 2)
    {
        int value = digits[i] * 2;
        if (value > 9)
        {
            value -= 9;
        }
        sum += value;
    }

    // Sum the remaining digits
    for (int i = length - 1; i >= 0; i -= 2)
    {
        sum += digits[i];
    }

    // If the number can be divided by 10 is valid
    return sum % 10 == 0;
}

const char *validate_brand(const char *number)
{
    int brand_check = (number[0] - '0') * 10 + (number[1] - '0');

    if (number[0] == '4' && (strlen(number) == 13 || strlen(number) == 16))
    {
        return "Visa";
    }
    else if (brand_check >= 51 && brand_check <= 55 && strlen(number) == 16)
    {
        return "MasterCard";
    }
    else if ((strcmp(number, "34") == 0 || strcmp(number, "37") == 0) && strlen(number) == 15)
    {
        return "Amex";
    }
    else
    {
        exit(EXIT_FAILURE);
    }
}

int main()
{
    char number[20];
    printf("Credit card number: ");
    scanf("%19s", number);

    const char *brand = validate_brand(number);
    if (validate_card(number))
    {
        printf("%s\n", brand);
    }
    else
    {
        printf("Invalid\n");
    }

    return 0;
}
