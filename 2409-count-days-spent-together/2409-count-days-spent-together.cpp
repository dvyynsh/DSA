// convert "dates,moths" into numbers

class Solution {
public:

    // conversion function from strinf of dates into in
    int dayOfYear(string date){
    vector<int> monthDays = {31,28,31,30,31,30,31,31,30,31,30,31};

    int month = stoi(date.substr(0,2));
    int day = stoi(date.substr(3,2));

    int total = 0;

    for(int i=0;i<month-1;i++){
        total += monthDays[i];
    }

    total += day;

    return total;
    }

    // now the code
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aliceArrive = dayOfYear(arriveAlice);
        int aliceLeave = dayOfYear(leaveAlice);

        int bobArrive = dayOfYear(arriveBob);
        int bobLeave = dayOfYear(leaveBob);

        // main logic
        int start = max(aliceArrive, bobArrive);
        int end = min(aliceLeave, bobLeave);

        if (start > end)
            return 0;

        return end - start + 1;
    }
};