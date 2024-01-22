#include <stdio.h>

int main() {
    double loan_amount, yearly_interest_rate, m_payment,m_interest_rate;
    double after_first,after_second,after_third;    

    // Get user input
    printf("Enter amount of loan: Rs. ");
    scanf("%lf", &loan_amount);

    printf("Enter yearly interest rate: ");
    scanf("%lf", &yearly_interest_rate);

    printf("Enter monthly payment: Rs. ");
    scanf("%lf", &m_payment);

    // Convert yearly interest rate to monthly interest rate
     m_interest_rate = (yearly_interest_rate / 100.0) / 12.0;

    //  remaining after each monthly payment
     after_first = loan_amount - m_payment + (loan_amount * m_interest_rate);
     after_second = after_first- m_payment + (after_first * m_interest_rate);
     after_third= after_second - m_payment + (after_second* m_interest_rate);

    
    printf("Balance remaining after first payment: Rs. %.2f\n", after_first);
    printf("Balance remaining after second payment: Rs. %.2f\n", after_second);
    printf("Balance remaining after third payment: Rs. %.2f\n", after_third);

    return 0;
}
