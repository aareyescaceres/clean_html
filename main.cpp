#include "lecture.h"

int main() {
    Counter C("","y10k.html");

    cout << C("think") << endl; // Result: 5
    cout << C("bug") << endl; // Result: 7
    cout << C("bugs") << endl; // Result: 1

    vector<string> rank = C.ranking();

    cout << rank[0] << endl; // ilsa (with 30 repetitions)
    cout << rank[1] << endl; // time (with 20 repetitions)
    cout << rank[2] << endl; // said (with 18 repetitions)
    cout << rank[3] << endl; // russell (with 16 repetitions)
    cout << rank[4] << endl; // still (with 10 repetitions)

    cout << C("<p>") << endl; // Result: 0
    cout << C("<html>") << endl; // Result: 0
    cout << C("http") << endl; // Result: 0
    cout << C("/") << endl; // Result: 0

    return 0;
}
