/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *  
 *  
 */

#include <iostream>
#include <cmath>
using namespace std;

class Point 
{
private:
    double x, y, z;

public:
    // Default Constructor
    Point() : x(0.0), y(0.0), z(0.0) 
    {

    }

    // Constructor with 3 values
    Point(double xVal, double yVal, double zVal) :
     x(xVal), y(yVal), z(zVal) 
     {

     }

    // Copy Constructor
    Point(const Point& copy) :
     x(copy.x), y(copy.y), z(copy.z) 
     {

     }

    // Accessor functions
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    // Modifier functions
    void setX(double xVal) { x = xVal; }
    void setY(double yVal) { y = yVal; }
    void setZ(double zVal) { z = zVal; }

    // Function to calculate the distance between two points
    double distanceBetweenPoints(const Point& copy) const 
    {
        double dx = copy.x - x;
        double dy = copy.y - y;
        double dz = copy.z - z;
        return sqrt(dx * dx + dy * dy + dz * dz);
    }

    // Function to calculate the distance between a point and the origin
    double distanceToOrigin() const
    {
        return sqrt(x * x + y * y + z * z);
    }

    // Overload the + operator to add two points
    Point operator+(const Point& copy) 
    const 
    {
        return Point(x + copy.x, y + copy.y, z + copy.z);
    }

    // Overload the - operator to subtract two points
    Point operator-(const Point& copy) const 
    {
        return Point(x - copy.x, y - copy.y, z - copy.z);
    }
};

int main() 
{
    
    // Create Point objects using different constructors

    Point a;                // Default constructor
    Point b(1.0, 2.0, 3.0); // Constructor with 3 values
    Point c = b;            // Copy constructor

    // Access and modify point coordinates
    a.setX(2.0);
    a.setY(4.0);
    a.setZ(6.0);

    // Calculate and display distances
    double distanceBetweenAAndB = a.distanceBetweenPoints(b);
    double distanceToOriginC = c.distanceToOrigin();

    cout << "Distance between a and b: " << distanceBetweenAAndB << endl;
    cout << "Distance from c to the origin: " << distanceToOriginC << endl;

    // Add and subtract points
    Point sum = a + b;
    Point difference = a - b;

    cout << "Sum of a and b: (" << sum.getX() << ", " << sum.getY() << ", " << sum.getZ() << ")" << endl;
    cout << "Difference between a and b: (" << difference.getX() << ", " << difference.getY() << ", " << difference.getZ() << ")" << endl;

    return 0;
}
