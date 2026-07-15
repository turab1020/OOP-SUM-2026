#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class TeamMember {
private:
    char* memberName;
    char* role;
    bool reciter;

    static int totalMembers;
    static bool paraCompleted[30];

public:
    TeamMember() {
        memberName = nullptr;
        role = nullptr;
        reciter = false;
        totalMembers++;
    }

    TeamMember(const char* memName, const char* r) {
        if (memName != nullptr) {
            memberName = new char[strlen(memName) + 1];
            strcpy(memberName, memName);
        }

        else {
            memberName = nullptr;
        }

        role = nullptr;
        setRole(r);
        totalMembers++;
    }

    TeamMember(const TeamMember& other) {
        if (other.memberName != nullptr) {
            memberName = new char[strlen(other.memberName) + 1];
            strcpy(memberName, other.memberName);
        }

        else {
            memberName = nullptr;
        }

        if (other.role != nullptr) {
            role = new char[strlen(other.role) + 1];
            strcpy(role, other.role);
        }

        else {
            role = nullptr;
        }

        reciter = other.reciter;
        totalMembers++;
    }

    ~TeamMember() {
        delete[] memberName;
        delete[] role;
        totalMembers--;
    }

    TeamMember& setMemberName(const char* memName) {
        delete[] this->memberName;

        if (memName != nullptr) {
            this->memberName = new char[strlen(memName) + 1];
            strcpy(this->memberName, memName);
        }

        else {
            this->memberName = nullptr;
        }

        return *this;
    }

    TeamMember& setRole(const char* inputRole) {
        if (strcmp(inputRole, "founder") == 0 ||
            strcmp(inputRole, "co founder") == 0 ||
            strcmp(inputRole, "co founder and reciter") == 0 ||
            strcmp(inputRole, "reciter") == 0 ||
            strcmp(inputRole, "content writer") == 0 ||
            strcmp(inputRole, "editor") == 0 ||
            strcmp(inputRole, "manager") == 0) {

            delete[] role;
            role = new char[strlen(inputRole) + 1];
            strcpy(role, inputRole);

            if (strcmp(inputRole, "reciter") == 0 ||
                strcmp(inputRole, "co founder and reciter") == 0) {
                reciter = true;
            }

            else {
                reciter = false;
            }
        }

        else {
            cout << "Error: Invalid role entered!" << endl;
            cout << "Setting default role to Manager!" << endl;

            if (role == nullptr) {
                role = new char[strlen("manager") + 1];
                strcpy(role, "manager");
                reciter = false;
            }
        }

        return *this;
    }

    void markParaCompleted(int paraNumber) {
        if (paraNumber > 0 && paraNumber <= 30) {
            if (paraCompleted[paraNumber - 1]) {
                cout << "Para Already completed!" << endl;
            }

            else {
                paraCompleted[paraNumber - 1] = true;
            }
        }

        else {
            cout << "Invalid Para Number!" << endl;
        }
    }

    static void printParaProg() {
        cout << "Paras Completed: ";
        bool firstCompleted = true;
        for (int i = 0; i < 30; i++) {
            if (paraCompleted[i]) {
                if (!firstCompleted) {
                    cout << ", ";
                }
                cout << i + 1;
                firstCompleted = false;
            }
        }
        if (firstCompleted) cout << "None";
        cout << endl;

        cout << "Paras in Progress: ";
        bool firstProgress = true;
        for (int i = 0; i < 30; i++) {
            if (!paraCompleted[i]) {
                if (!firstProgress) {
                    cout << ", ";
                }
                cout << i + 1;
                firstProgress = false;
            }
        }
        if (firstProgress) cout << "None";
        cout << endl;
    }

    void displayProgress() const {
        cout << "Name: " << (memberName ? memberName : "N/A") << endl;
        cout << "Role: " << (role ? role : "N/A") << endl;
        cout << "Reciter: " << (reciter ? "Yes" : "No") << endl;
    }

    static int getTotalMembers() {
        return totalMembers;
    }

    static void displayTeamStats() {
        printParaProg();
        cout << "Total Members in AJ Islamic Team: " << getTotalMembers() << endl;
    }
};

int TeamMember::totalMembers = 0;
bool TeamMember::paraCompleted[30] = { false };

int main() {
    TeamMember mem1;
    mem1.setMemberName("Ahmad Jawad").setRole("founder");

    TeamMember mem2("Hafiz Arham", "co founder and reciter");

    TeamMember mem3;
    mem3.setMemberName("Tahir").setRole("content writer");

    TeamMember mem4(mem3);
    mem4.setMemberName("Waleed");

    TeamMember mem5("Hafiz Abdulrehman", "reciter");

    TeamMember mem6(mem5);
    mem6.setMemberName("H M Aly Khan");

    mem1.markParaCompleted(9);
    mem1.markParaCompleted(28);
    mem1.markParaCompleted(29);
    mem1.markParaCompleted(30);

    cout << "--- Individual Members ---" << endl;
    mem1.displayProgress(); cout << endl;
    mem2.displayProgress(); cout << endl;
    mem3.displayProgress(); cout << endl;
    mem4.displayProgress(); cout << endl;
    mem5.displayProgress(); cout << endl;
    mem6.displayProgress(); cout << endl;

    cout << "--- Overall Team Stats ---" << endl;
    TeamMember::displayTeamStats();

    return 0;
}