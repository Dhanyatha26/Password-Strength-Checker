#include <stdio.h>
 #include <string.h>
 #include <ctype.h>
 int main() {
  char password[100];
  int length, digits = 0, special = 0, upper = 0, lower = 0;
  printf("Enter a password: ");
  fgets(password, sizeof(password), stdin);
  password[strcspn(password, "\n")] = '\0';
  length = strlen(password);
  for (int i = 0; i < length; i++) {
    if (isdigit(password[i]))
      digits++;
    else if (isupper(password[i]))
      upper++;
    else if (islower(password[i]))
      lower++;
    else
      special++;
  }
  printf("\nPassword Analysis:\n");
  printf("Length: %d\n", length);
  printf("Digits: %d\n", digits);
  printf("Uppercase Letters: %d\n", upper);
  printf("Lowercase Letters: %d\n", lower);
  printf("Special Characters: %d\n", special);
  if (length >= 8 && digits > 0 && special > 0 && upper > 0 && lower > 0)
    printf("Password Strength: Strong\n");
  else if (length >= 6 && ((upper > 0 || lower > 0) && (digits > 0 || special > 0)))
    printf("Password Strength: Moderate\n");
  else
    printf("Password Strength: Weak\n");
  return 0;
 }
