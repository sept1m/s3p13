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
        cout << "Питание: " << (power ? "Включено" : "Выключено") << endl;
    }

    void toggleBacklight() {
        if (power) {
            backlight = !backlight;
            cout << "Подсветка: " << (backlight ? "Включена" : "Выключена") << endl;
        } else {
            cout << "Невозможно переключить подсветку. Клавиатура выключена" << endl;
        }
    }

    void changeInputMode(const string& mode) {
        if (power) {
            if (mode == "EN" || mode == "RU") {
                input_mode = mode;
                cout << "Режим ввода изменен на" << input_mode << endl;
            } else {
                cout << "Неверный режим ввода!" << endl;
            }
        } else {
            cout << "Невозможно изменить режим ввода. Клавиатура выключена" << endl;
        }
    }

    void connectDevice() {
        if (power && connected_devices < 3) {
            connected_devices++;
            cout << "Подключенные устройства: " << connected_devices << endl;
        } else {
            cout << "Невозможно подключить устройство. Достигнут предел или клавиатура выключена." << endl;
        }
    }

    void disconnectDevice() {
        if (power && connected_devices > 0) {
            connected_devices--;
            cout << "Подключенные устройства: " << connected_devices << endl;
        } else {
            cout << "Невозможно отключить устройство. Никакие устройства не подключены или клавиатура выключена." << endl;
        }
    }

    void displayStatus() const {
        cout << "Питание: " << (power ? "On" : "Off") << endl;
        cout << "Подсветка: " << (backlight ? "On" : "Off") << endl;
        cout << "Режим ввода: " << input_mode << endl;
        cout << "Подключенные устройства: " << connected_devices << endl;
    }
};

void showMenu() {
    cout << "\nМеню:\n";
    cout << "1. Включить/выключить питание\n";
    cout << "2. Включить/выключить подсветку\n";
    cout << "3. Изменить режим ввода\n";
    cout << "4. Подключить устройство\n";
    cout << "5. Отключить устройство\n";
    cout << "6. Показать состояние клавиатуры\n";
    cout << "0. Выход\n";
    cout << "Выберите действие: ";
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
            cout << "Введите режим ввода (EN/RU): ";
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
            cout << "Выход...\n";
            break;
        default:
            cout << "Неверный ввод. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
