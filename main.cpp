#include "citizen.h"
using namespace std;

int main() 
{
    OutingDetails outingDetails;

    do {
        cout << "Enter the number of senior citizens interested in the outing (between 10 and " << MaxPeople << "): ";
        cin >> outingDetails.numSeniorCitizens;

        if (outingDetails.numSeniorCitizens < 10 || outingDetails.numSeniorCitizens > MaxPeople) 
        {
            cout << "Error: Number of senior citizens must be between 10 and " << MaxPeople << ". Please try again." << endl;
        }
    } while (outingDetails.numSeniorCitizens < 10 || outingDetails.numSeniorCitizens > MaxPeople);

    do {
        cout << "\nEnter the number of additional people to add to the outing (up to " << MaxPeople - outingDetails.numSeniorCitizens - MinCarers << " available seats): ";
        cin >> outingDetails.numExtraPeople;

        if (outingDetails.numExtraPeople < 0 || outingDetails.numSeniorCitizens + outingDetails.numExtraPeople + MinCarers > MaxPeople) {
            cout << "Error: Invalid number of additional people. Please try again." << endl;
        }
    } while (outingDetails.numExtraPeople < 0 || outingDetails.numSeniorCitizens + outingDetails.numExtraPeople + MinCarers > MaxPeople);

    outingDetails.numCarers = MinCarers;
    if (outingDetails.numSeniorCitizens + outingDetails.numExtraPeople > MoreCarersThreshold) 
    {
        outingDetails.numCarers++;
    }

    calculateCost(outingDetails);
    displayUpdatedCosts(outingDetails);
    recordParticipants(outingDetails);
    displayList(outingDetails);
    calculateProfitOrLoss(outingDetails);

    return 0;
}