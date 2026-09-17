#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n], at[n], bt[n];
    int ct[n], tat[n], wt[n];
    int completed[n] = {0};

    cout << "Enter Arrival Time and Burst Time:\n";

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "P" << pid[i] << ": ";
        cin >> at[i] >> bt[i];
    }

    int time = 0;
    int count = 0;

    while (count < n) {

        int index = -1;

        for (int i = 0; i < n; i++) {
            if (completed[i] == 0 && at[i] <= time) {

                if (index == -1 || bt[i] < bt[index]) {
                    index = i;
                }
            }
        }

        if (index == -1) {
            time++;
        }
        else {
            time = time + bt[index];

            ct[index] = time;
            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];

            completed[index] = 1;
            count++;
        }
    }

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << endl;
    }

    return 0;
}
