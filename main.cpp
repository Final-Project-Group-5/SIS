#include "./src/ObjectModels/Course.cpp"

using namespace std;

int main()
{
    cout << "working"
         << "\n\n\n\n\n\n\n";
    Course c = Course("ABC", 4, 'A', "Omar");
    c.printReport();
    return 1;
}