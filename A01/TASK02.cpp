#include <iostream>
using namespace std;

class Playlist {
private:
    char** songs;
    int capacity;
    int count;

public:
    Playlist(int capacity) {
        if (capacity < 0) {
            this->capacity = 0;
            songs = nullptr;
        }

        else {
            this->capacity = capacity;

            if (this->capacity > 0) {
                songs = new char* [this->capacity];

                for (int i = 0; i < this->capacity; i++) {
                    *(songs + i) = nullptr;
                }
            }

            else {
                songs = nullptr;
            }
        }

        count = 0;
    }

    Playlist(const Playlist& other) {
        capacity = other.capacity;
        count = other.count;

        if (capacity > 0) {
            songs = new char* [capacity];

            for (int i = 0; i < capacity; i++) {
                *(songs + i) = nullptr;
            }

            for (int i = 0; i < count; i++) {
                const char* source = *(other.songs + i);
                int size = 0;

                while (*(source + size) != '\0') {
                    size++;
                }

                *(songs + i) = new char[size + 1];

                for (int j = 0; j <= size; j++) {
                    *(*(songs + i) + j) = *(source + j);
                }
            }
        }

        else {
            songs = nullptr;
        }
    }

    void addSong(const char* title) {
        if (count >= capacity) {
            cout << "\nError: Playlist is full!\n";
            return;
        }

        if (title == nullptr) {
            return;
        }

        int size = 0;

        while (*(title + size) != '\0') {
            size++;
        }

        *(songs + count) = new char[size + 1];

        for (int i = 0; i <= size; i++) {
            *(*(songs + count) + i) = *(title + i);
        }

        count++;
    }

    const char* operator[](int index) const {
        if (index < 0 || index >= count) {
            return "Invalid Index";
        }

        return *(songs + index);
    }

    friend Playlist operator+(const Playlist& first, const Playlist& second) {
        Playlist merged(first.count + second.count);

        for (int i = 0; i < first.count; i++) {
            merged.addSong(*(first.songs + i));
        }

        for (int i = 0; i < second.count; i++) {
            merged.addSong(*(second.songs + i));
        }

        return merged;
    }

    ~Playlist() {
        if (songs != nullptr) {
            for (int i = 0; i < count; i++) {
                delete[] *(songs + i);
            }

            delete[] songs;
        }
    }
};

int main() {
    Playlist first(3);
    Playlist second(2);

    first.addSong("Song A");
    first.addSong("Song B");
    second.addSong("Song C");
    second.addSong("Song D");

    Playlist merged = first + second;

    cout << "Merged Playlist Songs:\n";

    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". " << merged[i] << "\n";
    }

    return 0;
}