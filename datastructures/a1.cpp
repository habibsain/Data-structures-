#include <iostream>
using namespace std;

class IntCell {
    private:
        int value;
    public:
        IntCell(int initialValue = 0) {
            value = initialValue;
        }
        int get() {
            return value;
        }
        void set(int x) {
            value = x;
        }
};

int main() {
    IntCell cell(5);
    cout << cell.get() << endl;
    return 0;
}