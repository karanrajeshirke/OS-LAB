#include<iostream>
#include<unistd.h>
#include<cstring>
#include<sys/wait.h>
using namespace std;

int main() {
    int toChild[2];
    int fromChild[2];

    if (pipe(toChild) == -1 || pipe(fromChild) == -1) {
        cout << "failed while making a pipe" << endl;
        return 1;
    }

    int id = fork();

    if (id == -1) {
        cout << "fork failed" << endl;
        return 2;
    }

    if (id == 0) {
        close(toChild[1]);
        close(fromChild[0]);

        char d1[100], d2[100]; // Use char arrays instead of struct

        if (read(toChild[0], d1, sizeof(d1)) == -1) {
            cout << "read failed";
            return 3;
        }

        cout << "(CHILD) --> received string from parent: " << d1 << endl;

        cout << "(CHILD) --> enter the string to be concatenated: ";
        cin >> d2;

        strcat(d1, " "); // Concatenate strings using strcat
        strcat(d1, d2);

        if (write(fromChild[1], d1, sizeof(d1)) == -1) {
            cout << "write failed";
            return 4;
        }

        cout << "(CHILD) --> string sent back to parent: " << d1 << endl;

        close(toChild[0]);
        close(fromChild[1]);
    } else {
        close(toChild[0]);
        close(fromChild[1]);

        char d1[100];

        cout << "(PARENT) --> enter the string you want to send to child: ";
        cin >> d1;

        if (write(toChild[1], d1, sizeof(d1)) == -1) {
            cout << "write failed" << endl;
            return 5;
        }

        cout << "(PARENT) --> string sent to child: " << d1 << endl;

        if (read(fromChild[0], d1, sizeof(d1)) == -1) {
            cout << "Read failed" << endl;
            return 6;
        }

        cout << "(PARENT) --> received from child: " << d1 << endl;

        close(toChild[1]);
        close(fromChild[0]);

        wait(NULL); // Wait for the child process to finish
    }
    return 0;
}