// Q1. The Electricity Bill Calculator is an application-based micro project 
// that calculates the month’s electricity bill based on the appliances or 
// loads and units consumed. People who do not have a technical understanding of
// calculating power bills can use this program to forecast/calculate their 
// electricity bills. The application should have the following features:
//
// -> To display the Meter Number
// -> To display the previous meter reading
// -> Facility to enter present meter-reading
// -> To display the no. of units consumed
// -> To display the complete Tariff Structure (Domestic, Non-Domestic, Industrial)
// -> Provision to input the no. of units consumed per month
// -> To display the bill-amount payable as per the tariff structure
// -> To display the due date of the payment
//
// Note: Assumptions can be made wherever necessary and list them. You must 
// execute the program and submit the program logic, sample input and output 
// along with the necessary documentation for this question.

#include <stdio.h>

int main() {
    int meter_number, input_type, previous_reading, present_reading, units_consumed, tariff_type;
    float tariff_rate, bill_amount, surcharge;
    const char tariff_structure[][20] = {"Domestic", "Non-industrial", "Industrial"};

    printf("Enter the meter number: ");
    scanf("%d", &meter_number);

    printf("Choose input type (1 = unit per month or 2 = previous and present reading): ");
    scanf("%d", &input_type);

    switch (input_type) {
        case 1:
            printf("Enter units consumed per month: ");
            scanf("%d", &units_consumed);
            break;
        case 2:
            printf("Enter the previous meter reading: ");
            scanf("%d", &previous_reading);
            printf("Enter the present meter reading: ");
            scanf("%d", &present_reading);
            units_consumed = present_reading - previous_reading;
            break;
        default:
            printf("Invalid input type. Please choose 1 or 2.\n");
            return 0;
    }

    printf("The units consumed are: %d\n", units_consumed);
    printf("Choose the tariff type (1. Domestic, 2. Non-Industrial, 3. Industrial): ");
    scanf("%d", &tariff_type);

    switch (tariff_type) {
        case 1:
            if (units_consumed <= 200) {
                tariff_rate = 1.2;
            } else if (units_consumed <= 400) {
                tariff_rate = 1.5;
            } else {
                tariff_rate = 2.0;
            }
            printf("The chosen tariff structure is: Domestic\n");
            printf("Less than 200 units: 1.2. 200-400 units: 1.5. More than 600 units: 2.0\n");
            break;
        case 2:
            if (units_consumed <= 200) {
                tariff_rate = 1.5;
            } else if (units_consumed <= 400) {
                tariff_rate = 1.9;
            } else {
                tariff_rate = 2.5;
            }
            printf("The chosen tariff structure is: Non-Industrial\n");
            printf("Less than 200 units: 1.5. 200-400 units: 1.9. More than 600 units: 2.5\n");
            break;
        case 3:
            if (units_consumed <= 500) {
                tariff_rate = 2.0;
            } else if (units_consumed <= 700) {
                tariff_rate = 2.5;
            } else {
                tariff_rate = 3.0;
            }
            printf("The chosen tariff structure is: Industrial\n");
            printf("Less than 500 units: 2.0. 500-700 units: 2.5. More than 700 units: 3.0\n");
            break;
        default:
            printf("Invalid tariff type. Please choose 1, 2, or 3.\n");
            return 0;
    }

    bill_amount = units_consumed * tariff_rate;
    surcharge = bill_amount * 0.15;

    printf("\nElectricity bill details:\n");
    printf("Meter number: %d\n", meter_number);
    if (input_type == 1) {
        printf("Previous meter reading: %d\n", previous_reading);
        printf("Current meter reading: %d\n", present_reading);
    }
    printf("Units consumed: %d\n", units_consumed);
    printf("Tariff structure: %s\n", tariff_structure[tariff_type - 1]);
    printf("Amount charged at Rs. %.2f per unit: %.2f\n", tariff_rate, bill_amount);
    printf("Surcharge amount at 15%%: %.2f\n", surcharge);
    printf("Bill amount payable: %.2f\n", bill_amount + surcharge);
    printf("Due date of payment: 7th of next month\n");
    return 0;
}
