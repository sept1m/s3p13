#include <iostream>
#include <string>
using namespace std;

class Keyboard {
private:
    bool power;
    bool backlight;
    string input_mode;
    int connected_devices;

public:
    Keyboard() : power(false), backlight(false), input_mode("EN"), connected_devices(0) {}
    Keyboard(bool p, bool b, string mode, int devices)
        : power(p), backlight(b), input_mode(mode), connected_devices(devices) {}
    void togglePower() {
        power = !power;
        cout << "�������: " << (power ? "��������" : "���������") << endl;
    }

    void toggleBacklight() {
        if (power) {
            backlight = !backlight;
            cout << "���������: " << (backlight ? "��������" : "���������") << endl;
        } else {
            cout << "���������� ����������� ���������. ���������� ���������" << endl;
        }
    }

    void changeInputMode(const string& mode) {
        if (power) {
            if (mode == "EN" || mode == "RU") {
                input_mode = mode;
                cout << "����� ����� ������� ��" << input_mode << endl;
            } else {
                cout << "�������� ����� �����!" << endl;
            }
        } else {
            cout << "���������� �������� ����� �����. ���������� ���������" << endl;
        }
    }

    void connectDevice() {
        if (power && connected_devices < 3) {
            connected_devices++;
            cout << "������������ ����������: " << connected_devices << endl;
        } else {
            cout << "���������� ���������� ����������. ��������� ������ ��� ���������� ���������." << endl;
        }
    }

    void disconnectDevice() {
        if (power && connected_devices > 0) {
            connected_devices--;
            cout << "������������ ����������: " << connected_devices << endl;
        } else {
            cout << "���������� ��������� ����������. ������� ���������� �� ���������� ��� ���������� ���������." << endl;
        }
    }

    void displayStatus() const {
        cout << "�������: " << (power ? "On" : "Off") << endl;
        cout << "���������: " << (backlight ? "On" : "Off") << endl;
        cout << "����� �����: " << input_mode << endl;
        cout << "������������ ����������: " << connected_devices << endl;
    }
};

void showMenu() {
    cout << "\n����:\n";
    cout << "1. ��������/��������� �������\n";
    cout << "2. ��������/��������� ���������\n";
    cout << "3. �������� ����� �����\n";
    cout << "4. ���������� ����������\n";
    cout << "5. ��������� ����������\n";
    cout << "6. �������� ��������� ����������\n";
    cout << "0. �����\n";
    cout << "�������� ��������: ";
}

int main() {
    system("chcp 1251>0");
    Keyboard keyboard;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            keyboard.togglePower();
            break;
        case 2:
            keyboard.toggleBacklight();
            break;
        case 3: {
            string mode;
            cout << "������� ����� ����� (EN/RU): ";
            cin >> mode;
            keyboard.changeInputMode(mode);
            break;
        }
        case 4:
            keyboard.connectDevice();
            break;
        case 5:
            keyboard.disconnectDevice();
            break;
        case 6:
            keyboard.displayStatus();
            break;
        case 0:
            cout << "�����...\n";
            break;
        default:
            cout << "�������� ����. ���������� �����.\n";
        }
    } while (choice != 0);

    return 0;
}
