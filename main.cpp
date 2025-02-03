#include <iostream>
#include <string>
using namespace std;

// Step 1: Define the Robot class
class Robot {
private:
    string name;
    string model;
    int batteryLife;

public:
    // Constructor
    Robot(string n, string m, int b) {
        name = n;
        model = m;
        batteryLife = b;
    }

    // Getter Methods
    string getName() {
        return name;
    }

    string getModel() {
        return model;
    }

    int getBatteryLife() {
        return batteryLife;
    }

    // Setter Methods
    void setName(string n) {
        name = n;
    }

    void setModel(string m) {
        model = m;
    }

    void setBatteryLife(int b) {
        batteryLife = b;
    }

    // Display function
    void displayRobot() {
        cout << "Robot: " << name << " | Model: " << model << " | Battery Life: " << batteryLife << "%\n";
    }
};

// Step 2: Function to modify robot (pass by value)
void modifyRobotValue(Robot r) {
    r.setModel("007 Agent");
    r.displayRobot();
}

// Step 3: Function to modify robot (pass by reference)
void ModifyRobotReference(Robot& r) {
    r.setModel("008 Agent");
    r.displayRobot();
}

// Step 4: Template class for a Fleet that stores multiple robots
template <typename T>
class Fleet {
private:
    T* robots;
    int capacity;
    int count;

public:
    // Constructor: Allocates space for 'capacity' robots
    Fleet(int cap) {
        capacity = cap;
        count = 0;
        robots = new T[capacity];
    }

    // Add robot to fleet
    void addRobot(T robot) {
        if (count < capacity) {
            robots[count] = robot;
            count++;
        } else {
            cout << "Fleet is full!\n";
        }
    }

    // Display all robots
    void showFleet() {
        cout << "Fleet contains:\n";
        for (int i = 0; i < count; i++) {
            cout << "- " << robots[i] << "\n";
        }
    }

    // Destructor: Free allocated memory
    ~Fleet() {
        delete[] robots;
    }
};

int main() {
    // Step 5: Create a Robot object
    Robot SamsRobot("LayUp 00Agent", "007", 100);

    // Step 6: Use pointers to access Robot object
    Robot* robotPtr = &SamsRobot;
    cout << "Updated Battery Life (using pointer): " << robotPtr->getBatteryLife() << "%\n";

    // Step 7: Pass by value (no change outside function)
    modifyRobotValue(SamsRobot);

    cout << "After modifyRobotByValue, Battery Life: " << SamsRobot.getBatteryLife() << "%\n";

    // Step 8: Pass by reference (changes persist)
    ModifyRobotReference(SamsRobot);

    cout << "After modifyRobotByReference, Battery Life: " << SamsRobot.getBatteryLife() << "%\n";

    // Step 9: Use the Fleet template class
    Fleet<string> myFleet(3);
    myFleet.addRobot("Autobot-X");
    myFleet.addRobot("Cybertron-7");
    myFleet.addRobot("NanoDroid-3");

    myFleet.showFleet();

    return 0;
}