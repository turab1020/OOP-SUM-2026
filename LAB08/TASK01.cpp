#include <iostream>
#include <cstring>

using namespace std;

class Engine {
private:
    int engineID;
    char* model;
    bool running;

public:
    Engine() {
        engineID = 0;
        model = nullptr;
        running = false;
    }

    Engine(int id, const char* m, bool run) {
        engineID = id;
        running = run;
        if (m != nullptr) {
            int size = strlen(m) + 1;
            model = new char[size];
            strcpy_s(model, size, m);
        }

        else {
            model = nullptr;
        }
    }

    Engine(const Engine& other) {
        engineID = other.engineID;
        running = other.running;
        if (other.model != nullptr) {
            int size = strlen(other.model) + 1;
            model = new char[size];
            strcpy_s(model, size, other.model);
        }

        else {
            model = nullptr;
        }
    }

    Engine& operator=(const Engine& other) {
        if (this == &other) {
            return *this;
        }

        engineID = other.engineID;
        running = other.running;

        delete[] model;

        if (other.model != nullptr) {
            int size = strlen(other.model) + 1;
            model = new char[size];
            strcpy_s(model, size, other.model);
        }

        else {
            model = nullptr;
        }

        return *this;
    }

    Engine& setID(int id) {
        this->engineID = id;
        return *this;
    }

    Engine& setModel(const char* m) {
        delete[] this->model;

        if (m != nullptr) {
            int size = strlen(m) + 1;
            this->model = new char[size];
            strcpy_s(this->model, size, m);
        }

        else {
            this->model = nullptr;
        }

        return *this;
    }

    Engine& setRunning(bool status) {
        this->running = status;
        return *this;
    }

    int getID() {
        return engineID;
    }

    const char* getModel() {
        return model;
    }

    bool getRunning() {
        return running;
    }

    void display() {
        cout << "Engine ID: " << engineID << "\n";
        cout << "Model: " << (model != nullptr ? model : "N/A") << "\n";
        cout << "Running: " << (running ? "Yes" : "No") << "\n";
    }

    ~Engine() {
        cout << "\nID: " << engineID << ". Engine Destroyed\n";
        delete[] model;
    }
};

class Car {
private:
    char* name;
    Engine engine;

public:
    Car() {
        name = nullptr;
    }

    Car(const char* carName) {
        if (carName != nullptr) {
            int size = strlen(carName) + 1;
            name = new char[size];
            strcpy_s(name, size, carName);
        }

        else {
            name = nullptr;
        }
    }

    Car(const Car& other) {
        engine = other.engine;  // now safe because Engine has proper operator=
        if (other.name != nullptr) {
            int size = strlen(other.name) + 1;
            name = new char[size];
            strcpy_s(name, size, other.name);
        }

        else {
            name = nullptr;
        }
    }

    Car& operator=(const Car& other) {
        if (this == &other) {
            return *this;
        }

        delete[] name;

        if (other.name != nullptr) {
            int size = strlen(other.name) + 1;
            name = new char[size];
            strcpy_s(name, size, other.name);
        }

        else {
            name = nullptr;
        }

        engine = other.engine;
        return *this;
    }

    Car& setName(const char* carName) {
        delete[] this->name;

        if (carName != nullptr) {
            int size = strlen(carName) + 1;
            this->name = new char[size];
            strcpy_s(this->name, size, carName);
        }

        else {
            this->name = nullptr;
        }

        return *this;
    }

    Car& setEngine(int id, const char* model, bool running) {
        this->engine.setID(id).setModel(model).setRunning(running);
        return *this;
    }

    const char* getName() {
        return name;
    }

    Engine getEngine() {
        return engine;
    }

    void display() {
        cout << "\n--- Car Details ---";
        cout << "\nCar Name: " << (name != nullptr ? name : "N/A") << "\n";
        cout << "\n--- Engine Details ---\n";
        engine.display();
    }

    ~Car() {
        cout << "\nCar Name: " << (name != nullptr ? name : "N/A") << ". Car Destroyed\n";
        delete[] name;
    }
};

class Mechanic {
private:
    char* name;
    Car* assignedCar;

public:
    Mechanic() {
        name = nullptr;
        assignedCar = nullptr;
    }

    Mechanic(const char* mechanicName, Car* car) {
        assignedCar = car;

        if (mechanicName != nullptr) {
            int size = strlen(mechanicName) + 1;
            name = new char[size];
            strcpy_s(name, size, mechanicName);
        }

        else {
            name = nullptr;
        }
    }

    Mechanic(const Mechanic& other) {
        assignedCar = other.assignedCar;

        if (other.name != nullptr) {
            int size = strlen(other.name) + 1;
            name = new char[size];
            strcpy_s(name, size, other.name);
        }

        else {
            name = nullptr;
        }
    }

    Mechanic& operator=(const Mechanic& other) {
        if (this == &other) {
            return *this;
        }

        delete[] name;

        if (other.name != nullptr) {
            int size = strlen(other.name) + 1;
            name = new char[size];
            strcpy_s(name, size, other.name);
        }

        else {
            name = nullptr;
        }

        assignedCar = other.assignedCar;
        return *this;
    }

    Mechanic& setName(const char* mechanicName) {
        delete[] this->name;

        if (mechanicName != nullptr) {
            int size = strlen(mechanicName) + 1;
            this->name = new char[size];
            strcpy_s(this->name, size, mechanicName);
        }

        else {
            this->name = nullptr;
        }

        return *this;
    }

    Mechanic& assignCar(Car* car) {
        this->assignedCar = car;
        return *this;
    }

    const char* getName() const {
        return name;
    }

    Car& getCar() {
        return *assignedCar;
    }

    void display() const {
        cout << "\n--- Mechanic Details ---";
        cout << "\nMechanic Name: " << (name != nullptr ? name : "N/A") << "\n";

        if (assignedCar != nullptr) {
            assignedCar->display();
        }

        else {
            cout << "Assigned Car: None\n";
        }
    }

    ~Mechanic() {
        cout << "\nMechanic Name: " << (name != nullptr ? name : "N/A") << ". Mechanic Destroyed\n";
        delete[] name;
    }
};

class Room {
private:
    int roomID;
    char* roomName;
    bool occupied;

public:
    Room() {
        roomID = 0;
        roomName = nullptr;
        occupied = false;
    }

    Room(int id, const char* name, bool occupied) {
        roomID = id;
        this->occupied = occupied;

        if (name != nullptr) {
            int size = strlen(name) + 1;
            roomName = new char[size];
            strcpy_s(roomName, size, name);
        }

        else {
            roomName = nullptr;
        }
    }
    Room(const Room& other) {
        roomID = other.roomID;
        occupied = other.occupied;

        if (other.roomName != nullptr) {
            int size = strlen(other.roomName) + 1;
            roomName = new char[size];
            strcpy_s(roomName, size, other.roomName);
        }

        else {
            roomName = nullptr;
        }
    }

    Room& operator=(const Room& other) {
        if (this == &other) {
            return *this;
        }
        roomID = other.roomID;
        occupied = other.occupied;

        delete[] roomName;

        if (other.roomName != nullptr) {
            int size = strlen(other.roomName) + 1;
            roomName = new char[size];
            strcpy_s(roomName, size, other.roomName);
        }

        else {
            roomName = nullptr;
        }

        return *this;
    }

    Room& setID(int id) {
        this->roomID = id;
        return *this;
    }

    Room& setName(const char* name) {
        delete[] this->roomName;

        if (name != nullptr) {
            int size = strlen(name) + 1;
            this->roomName = new char[size];
            strcpy_s(this->roomName, size, name);
        }

        else {
            this->roomName = nullptr;
        }

        return *this;
    }

    Room& setOccupied(bool status) {
        this->occupied = status;
        return *this;
    }

    int getID() {
        return roomID;
    }

    const char* getName() {
        return roomName;
    }

    bool getOccupied() {
        return occupied;
    }

    void display() {
        cout << "\n--- Room Details ---";
        cout << "\nRoom ID: " << roomID << "\n";
        cout << "Room Name: " << (roomName != nullptr ? roomName : "N/A") << "\n";
        cout << "Occupied: " << (occupied ? "Yes" : "No") << "\n";
    }

    ~Room() {
        if (roomID != 0) {
            cout << "\nRoom ID: " << roomID << ". Room Destroyed\n";
        }

        delete[] roomName;
    }
};

class CarHouse {
private:
    char* houseName;
    Room rooms[5];
    Car* cars[5];
    int roomCount;
    int carCount;

public:
    CarHouse() {
        houseName = nullptr;
        roomCount = 0;
        carCount = 0;

        for (int i = 0; i < 5; i++) {
            cars[i] = nullptr;
        }
    }

    CarHouse(const char* name) {
        roomCount = 0;
        carCount = 0;

        for (int i = 0; i < 5; i++) {
            cars[i] = nullptr;
        }

        if (name != nullptr) {
            int size = strlen(name) + 1;
            houseName = new char[size];
            strcpy_s(houseName, size, name);
        }

        else {
            houseName = nullptr;
        }
    }

    CarHouse(const CarHouse& other) {
        roomCount = other.roomCount;
        carCount = other.carCount;

        for (int i = 0; i < 5; i++) {
            rooms[i] = other.rooms[i];
            cars[i] = other.cars[i];
        }

        if (other.houseName != nullptr) {
            int size = strlen(other.houseName) + 1;
            houseName = new char[size];
            strcpy_s(houseName, size, other.houseName);
        }

        else {
            houseName = nullptr;
        }
    }

    CarHouse& operator=(const CarHouse& other) {
        if (this == &other) {
            return *this;
        }

        delete[] houseName;

        if (other.houseName != nullptr) {
            int size = strlen(other.houseName) + 1;
            houseName = new char[size];
            strcpy_s(houseName, size, other.houseName);
        }

        else {
            houseName = nullptr;
        }

        roomCount = other.roomCount;
        carCount = other.carCount;

        for (int i = 0; i < 5; i++) {
            rooms[i] = other.rooms[i];
            cars[i] = other.cars[i];
        }

        return *this;
    }

    CarHouse& setName(const char* name) {
        delete[] this->houseName;

        if (name != nullptr) {
            int size = strlen(name) + 1;
            this->houseName = new char[size];
            strcpy_s(this->houseName, size, name);
        }

        else {
            this->houseName = nullptr;
        }

        return *this;
    }

    CarHouse& addRoom(int id, const char* roomName, bool occupied) {
        if (roomCount < 5) {
            rooms[roomCount].setID(id).setName(roomName).setOccupied(occupied);
            roomCount++;
        }

        else {
            cout << "\nError: Car House rooms array is full!\n";
        }

        return *this;
    }

    CarHouse& addCar(Car* car) {
        if (carCount < 5) {
            cars[carCount] = car;
            carCount++;
        }

        else {
            cout << "\nError: Car House cars array is full!\n";
        }

        return *this;
    }

    void display() {
        cout << "\n--- Car House Details ---";
        cout << "\nHouse Name: " << (houseName != nullptr ? houseName : "N/A") << "\n";
        cout << "\n--------------- ROOMS -----------------";

        for (int i = 0; i < roomCount; i++) {
            rooms[i].display();
        }

        cout << "\n--------------- CARS ------------------";
        for (int i = 0; i < carCount; i++) {
            cout << "\n" << i + 1 << ". ";
            if (cars[i] != nullptr) {
                cars[i]->display();
            }
        }
    }

    ~CarHouse() {
        cout << "\nHouse Name: " << (houseName != nullptr ? houseName : "N/A") << ". CarHouse Destroyed\n";
        delete[] houseName;
    }
};

class LuxuryCarHouse {
private:
    char* name;
    Room* rooms;
    Car** cars;
    int totalRooms;
    int totalCars;

public:
    LuxuryCarHouse() {
        name = nullptr;
        rooms = nullptr;
        cars = nullptr;
        totalRooms = 0;
        totalCars = 0;
    }

    LuxuryCarHouse(const char* houseName) {
        rooms = nullptr;
        cars = nullptr;
        totalRooms = 0;
        totalCars = 0;

        if (houseName != nullptr) {
            int size = strlen(houseName) + 1;
            name = new char[size];
            strcpy_s(name, size, houseName);
        }

        else {
            name = nullptr;
        }
    }

    LuxuryCarHouse(const LuxuryCarHouse& other) {
        totalRooms = other.totalRooms;
        totalCars = other.totalCars;

        if (other.name != nullptr) {
            int size = strlen(other.name) + 1;
            name = new char[size];
            strcpy_s(name, size, other.name);
        }

        else {
            name = nullptr;
        }

        if (totalRooms > 0 && other.rooms != nullptr) {
            rooms = new Room[totalRooms];

            for (int i = 0; i < totalRooms; i++) {
                rooms[i] = other.rooms[i];  // now safe
            }
        }

        else {
            rooms = nullptr;
        }

        if (totalCars > 0 && other.cars != nullptr) {
            cars = new Car * [totalCars];

            for (int i = 0; i < totalCars; i++) {
                cars[i] = other.cars[i];
            }
        }

        else {
            cars = nullptr;
        }
    }

    LuxuryCarHouse& operator=(const LuxuryCarHouse& other) {
        if (this == &other) {
            return *this;
        }

        delete[] name;
        delete[] rooms;
        delete[] cars;

        totalRooms = other.totalRooms;
        totalCars = other.totalCars;

        if (other.name != nullptr) {
            int size = strlen(other.name) + 1;
            name = new char[size];
            strcpy_s(name, size, other.name);
        }

        else {
            name = nullptr;
        }

        if (totalRooms > 0 && other.rooms != nullptr) {
            rooms = new Room[totalRooms];

            for (int i = 0; i < totalRooms; i++) {
                rooms[i] = other.rooms[i];
            }
        }

        else {
            rooms = nullptr;
        }

        if (totalCars > 0 && other.cars != nullptr) {
            cars = new Car * [totalCars];

            for (int i = 0; i < totalCars; i++) {
                cars[i] = other.cars[i];
            }
        }

        else {
            cars = nullptr;
        }

        return *this;
    }

    LuxuryCarHouse& setName(const char* houseName) {
        delete[] this->name;

        if (houseName != nullptr) {
            int size = strlen(houseName) + 1;
            this->name = new char[size];
            strcpy_s(this->name, size, houseName);
        }

        else {
            this->name = nullptr;
        }

        return *this;
    }

    LuxuryCarHouse& addRoom(int id, const char* roomName, bool occupied) {
        Room* newRooms = new Room[totalRooms + 1];
        for (int i = 0; i < totalRooms; i++) {
            newRooms[i] = rooms[i];
        }
        newRooms[totalRooms].setID(id).setName(roomName).setOccupied(occupied);

        delete[] rooms;
        rooms = newRooms;
        totalRooms++;

        return *this;
    }

    LuxuryCarHouse& removeLastRoom() {
        if (totalRooms <= 0) {
            cout << "\nError: No rooms available to remove!\n";
            return *this;
        }

        if (totalRooms == 1) {
            delete[] rooms;
            rooms = nullptr;
            totalRooms = 0;
            return *this;
        }

        Room* newRooms = new Room[totalRooms - 1];

        for (int i = 0; i < totalRooms - 1; i++) {
            newRooms[i] = rooms[i];
        }

        delete[] rooms;
        rooms = newRooms;
        totalRooms--;
        return *this;
    }
    
    LuxuryCarHouse& addCar(Car* car) {
        Car** newCars = new Car * [totalCars + 1];

        for (int i = 0; i < totalCars; i++) {
            newCars[i] = cars[i];
        }

        newCars[totalCars] = car;
        delete[] cars;
        cars = newCars;
        totalCars++;
        return *this;
    }

    LuxuryCarHouse& removeLastCar() {
        if (totalCars <= 0) {
            cout << "\nError: No cars attached to remove!\n";
            return *this;
        }

        if (totalCars == 1) {
            delete[] cars;
            cars = nullptr;
            totalCars = 0;
            return *this;
        }

        Car** newCars = new Car * [totalCars - 1];

        for (int i = 0; i < totalCars - 1; i++) {
            newCars[i] = cars[i];
        }

        delete[] cars;
        cars = newCars;
        totalCars--;
        return *this;
    }

    void display() const {
        cout << "\n--- Luxury Car House Details ---";
        cout << "\nHouse Name: " << (name != nullptr ? name : "N/A") << "\n";

        cout << "\n--------------- ROOMS -----------------";
        for (int i = 0; i < totalRooms; i++) {
            rooms[i].display();
        }

        cout << "\n--------------- CARS ------------------";
        for (int i = 0; i < totalCars; i++) {
            cout << "\n" << i + 1 << ". ";

            if (cars[i] != nullptr) {
                cars[i]->display();
            }
        }
    }

    ~LuxuryCarHouse() {
        cout << "\nHouse Name: " << (name != nullptr ? name : "N/A") << ". LuxuryCarHouse Destroyed\n";
        delete[] name;
        delete[] rooms;
        delete[] cars;
    }
};

int main() {
    int ID1 = 192;
    const char* model1 = "Turbo V8";
    bool running = true;
    int ID2 = 193;
    const char* model2 = "Twin Turbo V12";
    const char* name1 = "Lightning McQueen";
    int ID3 = 194;
    const char* model3 = "Super Charged V6";
    const char* name2 = "Jackson Storm";

    cout << "-------------- Engine TEST --------------" << endl;
    {
        Engine engineObj;
        engineObj.setID(ID1).setModel(model1).setRunning(running);
        engineObj.display();
    }
    cout << "-----------------------------------------\n" << endl;

    cout << "---------------- Car TEST ---------------";
    {
        Car carObj1;
        carObj1.setName(name1).setEngine(ID2, model2, running);
        carObj1.display();
    }
    cout << "-----------------------------------------\n" << endl;

    Car carObj;
    carObj.setName(name1).setEngine(ID2, model2, running);
    Car carObj1;
    carObj1.setName(name2).setEngine(ID3, model3, running);

    cout << "------------- Mechanic TEST ------------";
    {
        Mechanic mechObj;
        mechObj.setName("Doc Hudson").assignCar(&carObj);
        mechObj.display();
    }
    cout << "-----------------------------------------\n" << endl;

    cout << "------------- Room TEST -----------------";
    {
        Room roomObj;
        roomObj.setID(501).setName("Main Garage Bay").setOccupied(true);
        roomObj.display();
    }
    cout << "-----------------------------------------\n" << endl;

    cout << "----------- CarHouse TEST ---------------";
    {
        CarHouse houseObj("Radiator Springs HQ");
        houseObj.addRoom(1, "Main Garage Bay", true);
        houseObj.addRoom(2, "Paint Shop Room", false);
        houseObj.addCar(&carObj);
        houseObj.addCar(&carObj1);
        houseObj.display();
    }
    cout << "-----------------------------------------\n" << endl;

    cout << "--------- Luxury House TEST -------------";
    {
        LuxuryCarHouse luxuryHouse("Piston Cup Elite Mansion");
        cout << "\n--- Adding Rooms and Cars Dynamically ---" << endl;
        luxuryHouse.addRoom(101, "V.I.P Lounge Room", true);
        luxuryHouse.addRoom(102, "Dyno Tuning Room", false);
        luxuryHouse.addRoom(103, "Showroom Room", true);
        luxuryHouse.addCar(&carObj);
        luxuryHouse.addCar(&carObj1);
        cout << "\nDisplaying LuxuryCarHouse after growth:\n";
        luxuryHouse.display();
        cout << "\n----------------------------------------" << endl;
        cout << "\n--- Removing Last Room and Car Dynamically ---" << endl;
        luxuryHouse.removeLastRoom();
        luxuryHouse.removeLastCar();
        cout << "\nDisplaying LuxuryCarHouse after shrinking:\n";
        luxuryHouse.display();
    }
    cout << "-----------------------------------------\n" << endl;
}