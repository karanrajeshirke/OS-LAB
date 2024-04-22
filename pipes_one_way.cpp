#include <iostream>
#include <unistd.h>
using namespace std;

struct Data {
    int number;
    string str;
};

int main() {
    int fd[2];

    if (pipe(fd) == -1) {
        cout << "Error while creating a pipe" << endl;
        return 1;
    }

    int id = fork();

    if (id == -1) {
        cout << "Fork failed" << endl;
        return 2;
    }

    if (id == 0) {
        Data data;
        cout << "Child: Enter a number: ";
        cin >> data.number;
        cout << "Child: Enter a string: ";
        cin >> data.str;

        close(fd[0]);

        if (write(fd[1], &data, sizeof(Data)) == -1) {
            cout << "Error while writing into the pipe" << endl;
            return 3;
        }

        close(fd[1]);
    } else {
        close(fd[1]);

        Data received_data;

        if (read(fd[0], &received_data, sizeof(Data)) == -1) {
            cout << "Error while reading from the pipe" << endl;
            return 4;
        }

        cout << "Parent: Received from child: Number = " << received_data.number << ", String = " << received_data.str << endl;

        close(fd[0]);
    }

    return 0;
}
