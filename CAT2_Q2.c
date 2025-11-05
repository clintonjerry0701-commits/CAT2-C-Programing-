/*
Name:Clinton Jerry 
Reg:CT100/G/26286/25
Description:C program that requests the user to enter hours worked in a week and the hourly wage and then calculate the taxes and the net pay
*/
#include <stdio.h>

int main() {
    float hours_worked, hourly_wage;
    float gross_pay, taxes, net_pay;
    float overtime_hours, regular_hours;
    
    // Get input from user
    printf("Enter hours worked in a week: ");
    scanf("%f", &hours_worked);
    
    printf("Enter hourly wage: $");
    scanf("%f", &hourly_wage);
    
    // Calculate gross pay with overtime
    if (hours_worked > 40) {
        regular_hours = 40;
        overtime_hours = hours_worked - 40;
        gross_pay = (regular_hours * hourly_wage) + (overtime_hours * hourly_wage * 1.5);
    } else {
        regular_hours = hours_worked;
        overtime_hours = 0;
        gross_pay = hours_worked * hourly_wage;
    }
    
    // Calculate taxes
    if (gross_pay <= 600) {
        taxes = gross_pay * 0.15;  // 15% tax
    } else {
        taxes = (600 * 0.15) + ((gross_pay - 600) * 0.20);  // 15% on first $600, 20% on rest
    }
    
    // Calculate net pay
    net_pay = gross_pay - taxes;
    
    // Display results
    printf("\n--- PAYROLL CALCULATION ---\n");
    printf("Hours worked: %.2f hours\n", hours_worked);
    printf("Hourly wage: $%.2f\n", hourly_wage);
    
    if (overtime_hours > 0) {
        printf("Regular hours: %.2f hours\n", regular_hours);
        printf("Overtime hours: %.2f hours\n", overtime_hours);
    }
    
    printf("Gross pay: $%.2f\n", gross_pay);
    printf("Taxes: $%.2f\n", taxes);
    printf("Net pay: $%.2f\n", net_pay);
    
    return 0;
}