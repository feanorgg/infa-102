#include <string>
using std::string;
using std::cout;
using std::endl;

namespace MySpace
{
    string sin(double x=0) {
        return "This is sin() from MySpace namespace";
    }

    template <typename T>
    class MyClass {
        private:
            T payload;
        public:
            T get_payload() {
                return payload;
            }

            void set_payload(T value) {
                payload = value;
                return;
            }

            void show() {
                cout << "[*] Class MyClass" << endl;
                cout << " - payload: " << payload << endl << endl;
            }
    };
}
