#include <iostream>
#include <string>
using namespace std;

const int MaxPeople = 36;
const int MinCarers = 2;
const int MoreCarersThreshold = 24;

struct OutingDetails {
    int numSeniorCitizens;
    int numExtraPeople;
    int numCarers;
    float totalCost;
    float costPerPerson;
    string names[MaxPeople + MinCarers];
    float amountsPaid[MaxPeople + MinCarers];
};

float calculateBaseCost(int numSeniorCitizens) 
{
    if (numSeniorCitizens >= 10 && numSeniorCitizens <= 16) {
        return 150;
    } else if (numSeniorCitizens >= 17 && numSeniorCitizens <= 26) {
        return 190;
    } else {
        return 225;
    }
}

void calculateCost(OutingDetails& details) 
{
    details.totalCost = calculateBaseCost(details.numSeniorCitizens) + (details.numSeniorCitizens + details.numCarers) * (14.00 + 21.00);

    details.totalCost += details.numExtraPeople * (14.00 + 21.00);

    details.costPerPerson = details.totalCost / (details.numSeniorCitizens + details.numExtraPeople);
}

void displayUpdatedCosts(const OutingDetails& details) 
{
    cout << "\nUpdated Outing Details:" << endl;
    cout << "Number of Senior Citizens: " << details.numSeniorCitizens << endl;
    cout << "Number of Carers: " << details.numCarers << endl;
    cout << "Total Cost: $" << details.totalCost << endl;
    cout << "Cost per Person: $" << details.costPerPerson << endl;
}

void recordParticipants(OutingDetails& details) 
{
    for (int i = 0; i < details.numSeniorCitizens + details.numExtraPeople; ++i) {
        cout << "\nEnter the name of participant " << i + 1 << ": ";
        cin >> details.names[i];

        cout << "Enter the amount paid by " << details.names[i] << ": $";
        cin >> details.amountsPaid[i];
    }
}

void displayList(const OutingDetails& details) 
{
    cout << "\nList of People on the Outing:" << endl;
    for (int i = 0; i < details.numSeniorCitizens+ details.numExtraPeople; ++i) 
    {
        cout << details.names[i] << ": $" << details.amountsPaid[i] << endl;
    }
    for (int i = 0; i < details.numCarers; ++i)
    cout<<"Carers: 0$"<<endl;
}

void calculateProfitOrLoss(const OutingDetails& details) 
{
    float totalAmountCollected = 0.0;
    for (int i = 0; i < details.numSeniorCitizens + details.numCarers + details.numExtraPeople; ++i) 
    {
        totalAmountCollected += details.amountsPaid[i];
    }
    float profitOrLoss = totalAmountCollected - details.totalCost;

    cout << "\nTotal Amount Collected: $" << totalAmountCollected << endl;
    cout << "\nProfit or Loss: $" << profitOrLoss << endl;

    if (profitOrLoss > 0) 
    {
        cout << "The outing has made a profit." << endl;
    }
    else if (profitOrLoss = 0) 
    {
        cout << "All bills are payed. No profit/loss." << endl;
    }
    else 
    {
        cout << "The outing has incurred a loss." << endl;
    }
}