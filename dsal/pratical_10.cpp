#include<iostream>
#include<string>
#include<queue>

using namespace std;

void print(priority_queue<pair<int, string>>& pq) {
    while (!pq.empty()) {
        pair<int, string> patient = pq.top();
        pq.pop();

        cout << "Patient's Name: " << patient.second << ", Priority: ";

        switch (patient.first) {
            case 1:
                cout << "'Checkup'" << endl;
                break;
            case 2:
                cout << "'Non-serious'" << endl;
                break;
            case 3:
                cout << "'Serious'" << endl;
                break;
            default:
                cout << "Priority not found" << endl;
        }
    }
}

int main() {
    string name;
    int opt, priority;
    priority_queue<pair<int, string>> pq;

    cout << "Enter Your Choice:" << endl;
    do {
        cout << "1 for Insert Data in Queue" << endl
             << "2 for Show Data in Queue" << endl
             << "3 for Delete Data from Queue" << endl
             << "0 for Exit" << endl;
        cin >> opt;

        switch (opt) {
            case 1:
                int n;
                cout << "Enter the number of patients: ";
                cin >> n;

                for (int i = 0; i < n; i++) {
                    cout << "Enter the name of the patient: ";
                    cin >> name;

                    cout << "Enter the priority (3: serious, 2: non-serious, 1: general checkup): ";
                    cin >> priority;

                    pq.push(make_pair(priority, name));
                }
                break;

            case 2:
                print(pq);
                break;

            case 3:
                if (!pq.empty()) {
                    pair<int, string> patient = pq.top();
                    pq.pop();
                    cout << "Deleted Element - Patient's Name: " << patient.second << ", Priority: " << patient.first << endl;
                } else {
                    cout << "Queue is Empty" << endl;
                }
                break;
        }
    } while (opt != 0);

    return 0;
}
